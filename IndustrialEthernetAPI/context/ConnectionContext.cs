using IndustrialEthernetEntity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IndustrialEthernetAPI
{
    public class ConnectionContext
    {
        public IOdevice[] devices { get; set; }
        public Adapter[] adapters { get; set; }
        public bool hasAdapter { get; set; }
        public int inputDeviceNum { get; set; }
        public int outputDeviceNum { get; set; }
        public int adapterNum { get; set; }
        public ConnectionContext(bool hasAdapter)
        {
            this.hasAdapter = hasAdapter;
        }
    }
}
