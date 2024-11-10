#include<Windows.h>
#include"resource.h"

//#define MESSAGE_BOX

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	/*
	---------------------------
	WinMain
	hInstance - экземпляр нашего приложения в памяти (экземпляр *.exe-файла)
	hPrevInst - предыдущий запущенный экземпляр (Deprecated, использовался в Windows 98).
	LPSTR lpCmdLine:
	LPSTR - LongPointer to String (Указатель на строку наподобие const char*)
	lpCmdLine - коммандная строка запуска приложения
	nCmdShow - режим отображения окна: Свернуто в окно, Развернуто на весь экран, свернуто в пнель задач......
	*/

#ifdef MESSAGE_BOX
	MessageBox
	(
		NULL,
		"Hello WinAPI!\nЭто окно сообщения",
		"Question",
		MB_YESNOCANCEL | MB_ICONQUESTION
		| MB_HELP | MB_DEFBUTTON4
		| MB_SYSTEMMODAL
	);
#endif // MESSAGE_BOX

	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc, 0);

	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	/*
	---------------------------
	DlgProc(WndProc) - Процедура окна.
	ПРОЦЕДУРА - ЭТО ФУНКЦИЯ
	hwnd (Handler to Window) - окно. Обработчик окна - это число, через которое можно обратиться к окну.
	---------------------------
	uMsg - сообщение, отправляемое окну.
	---------------------------
	wParam, lParam - параметры сообщения.
	DWORD - Dourle Word
	HIWORD - старшее слово;
	LOWORD - младшее слово;

	Слово (WORD) - это 2 Байта
	---------------------------
	*/

	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_COPY:
		{
			//1) Создаем буфер, через который будет выполняться копирование:
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE]{};

			//2) Получаем дескрипторы тектовых полей, с которыми будем работать:
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);

			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);	//Копируем текст из поля 'Login' в буфер.
			SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);	//Загруэаем текст из тектового буфера в поле 'Password'.
		}
		break;
		case IDOK:		MessageBox(hwnd, "Была нажата кнопка OK", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL:	EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		break;
	}
	return FALSE;
}