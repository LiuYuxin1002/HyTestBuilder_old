using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IndustrialEthernetEntity
{
    public class IOdevice
    {
        public int id { get; set; }
        public int type { get; set; }//Di,DO,AI,AO
        public string name { get; set; }
        public int channelNum { get; set; }
        public Type[] value;
    }
}
