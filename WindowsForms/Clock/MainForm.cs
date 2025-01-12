using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Clock
{
	public partial class MainForm : Form
	{
		public MainForm()
		{
			InitializeComponent();
			labelTime.BackColor = Color.AliceBlue;
			this.Location = new Point(Screen.PrimaryScreen.Bounds.Width - this.Width, 50);
			//toolStripMenuItemShowControls.Checked = false;	//Works not correctly
			toolStripMenuItemShowControls.Checked = true;
		}
		void SetVisibility(bool visible)
		{
			checkBoxShowDate.Visible = visible;
			checkBoxShowWeekday.Visible = visible;
			buttonHideControls.Visible = visible;
			this.FormBorderStyle = visible ? FormBorderStyle.FixedDialog : FormBorderStyle.None;
			this.ShowInTaskbar = visible;
			this.TransparencyKey = visible ? Color.Empty : this.BackColor;
		}

		private void timer_Tick(object sender, EventArgs e)
		{
			//Обработчик события - это самая обычная функция, которая неявно вызывается 
			//					   при возникновении определенного события.
			//У элемента интерфкйса может быть множество событий, и одно из них будет событием по умолчанию.
			labelTime.Text = DateTime.Now.ToString("hh:mm:ss tt", System.Globalization.CultureInfo.InvariantCulture);
			//labelTime.Text = DateTime.Now.ToString("HH:mm:ss");
			if (checkBoxShowDate.Checked)
				labelTime.Text += $"\n{DateTime.Now.ToString("yyyy.MM.dd")}";
			if (checkBoxShowWeekday.Checked)
				labelTime.Text += $"\n{DateTime.Now.DayOfWeek}";
			notifyIcon.Text =
				$"{DateTime.Now.ToString("hh:mm tt")}\n" +
				$"{DateTime.Now.ToString("yyyy.MM.dd")}\n" +
				$"{DateTime.Now.DayOfWeek}";
		}

		private void buttonHideControls_Click(object sender, EventArgs e)
		{
			//SetVisibility(false);
			toolStripMenuItemShowControls.Checked = false;
		}

		private void labelTime_DoubleClick(object sender, EventArgs e)
		{
			//SetVisibility(true);
			toolStripMenuItemShowControls.Checked = true;
		}

		private void toolStripMenuItemExit_Click(object sender, EventArgs e) => this.Close();

		private void toolStripMenuItemTopmost_CheckedChanged(object sender, EventArgs e) =>
			this.TopMost = toolStripMenuItemTopmost.Checked;

		private void toolStripMenuItemShowControls_CheckStateChanged(object sender, EventArgs e) =>
			SetVisibility(toolStripMenuItemShowControls.Checked);

		private void toolStripMenuItemShowDate_CheckedChanged(object sender, EventArgs e) =>
			checkBoxShowDate.Checked = toolStripMenuItemShowDate.Checked;

		private void checkBoxShowDate_CheckedChanged(object sender, EventArgs e) =>
			toolStripMenuItemShowDate.Checked = checkBoxShowDate.Checked;

		private void toolStripMenuItemShowDay_CheckedChanged(object sender, EventArgs e) =>
			checkBoxShowWeekday.Checked = toolStripMenuItemShowDay.Checked;

		private void checkBoxShowWeekday_CheckedChanged(object sender, EventArgs e) =>
			toolStripMenuItemShowDay.Checked = checkBoxShowWeekday.Checked;

		//private void toolStripMenuItemShowControls_CheckedChanged(object sender, EventArgs e)
		//{
		//	SetVisibility(toolStripMenuItemShowControls.Checked);
		//}
	}
}
