using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Timers;

namespace MasterConnectorConsole
{
    public class BaseClass
    {
        private Timer timer;
        public BaseClass()
        {
            timer = new Timer(1000);
            //this.timer.Interval = 1000;
            this.timer.Elapsed += events;
            this.timer.Start();
        }

        public void events(Object sender, EventArgs e)
        {
            //Delegate del = sender as Delegate;
            //del.DynamicInvoke(null);
            reporter();
        }
        public void reporter()
        {
            Console.WriteLine("ohho~");
            //del.DynamicInvoke(null);
        }
    }
}
