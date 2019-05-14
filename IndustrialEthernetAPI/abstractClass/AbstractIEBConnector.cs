using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IndustrialEthernetAPI
{
    abstract class AbstractIEBConnector : IConnection
    {
        public abstract event EventHandler datachanged;
        private AbstractIEBConnector Connector;

        private AbstractIEBConnector()
        {

        }

        public abstract int connect();
        public abstract int close();
        public abstract int disconnect();
    }
}
