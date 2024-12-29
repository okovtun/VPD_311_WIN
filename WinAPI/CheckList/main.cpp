#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include"resource.h"

//Чтобы запустить окно нужна Процедура окна.
//Процедура окна - это самая обычная функция, которая неявно вызывается при запуске окна.
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_MAIN_DIALOG), NULL, DlgProc, 0);
	//Функция DialogBoxParam() запускает окно диалога, и вызывает процедуру этого окна.
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:	//Отрабатывает один раз при запуске окна
	{
		//Ошибка 'skipped by case label' решется при помощи фигурных скобок.
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, NULL, (LPARAM)hIcon);
		HWND hEditStudent = GetDlgItem(hwnd, IDC_EDIT_STUDENT);	//Функция GetDlgItem() позволяет получить элемент окна по его ResourceID
		SetFocus(hEditStudent);
	}
	break;
	case WM_COMMAND:	//Обрабатывает команды нажатия на кнопки и другие элементы окна.
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			HWND hEditStudent = GetDlgItem(hwnd, IDC_EDIT_STUDENT);
			HWND hEditDescription = GetDlgItem(hwnd, IDC_EDIT_DESCRIPTION);
			CONST INT SIZE = 1024;
			CHAR szStudent[SIZE]{};		//sz - String Zero (строка, заканчивающаяся нулем - NULL-Terminated Line)
			CHAR szDescription[SIZE]{};
			SendMessage(hEditStudent, WM_GETTEXT, SIZE, (LPARAM)szStudent);
			strcpy(szDescription, szStudent);
			SendMessage(hEditDescription, WM_SETTEXT, 0, (LPARAM)szDescription);
		}
		break;
		case IDCANCEL:EndDialog(hwnd, 0);
		}
		break;
	case WM_CLOSE:		//Обрабатывает кнопку 'Закрыть' X
		EndDialog(hwnd, 0);
		break;
	}
	return FALSE;
}