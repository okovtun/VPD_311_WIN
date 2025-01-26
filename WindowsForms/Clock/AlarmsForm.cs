﻿using System;
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
	public partial class AlarmsForm : Form
	{
		AddAlarmDialog dialog;
		public AlarmsForm()
		{
			InitializeComponent();
			dialog = new AddAlarmDialog();
		}
		public AlarmsForm(System.Windows.Forms.Form parent) : this()
		{
			this.StartPosition = FormStartPosition.Manual;
			this.Location = new Point
				(
				parent.Location.X - this.Width,
				parent.Location.Y
				);
		}

		private void buttonAdd_Click(object sender, EventArgs e)
		{
			dialog.Location = new Point
				(
					this.Location.X + (this.Width - dialog.Width) / 2,
					this.Location.Y + (this.Height - dialog.Height) / 2
				);
			dialog.ShowDialog();
		}
	}
}
