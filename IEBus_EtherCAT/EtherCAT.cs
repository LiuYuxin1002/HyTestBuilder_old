using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using IEBus_API;

namespace IEBus_EtherCAT
{
    class EtherCAT : IConnector
    {


        public int ReadAnalog(List<int> deviceList, List<int[]> channelList, ref List<int[]> values)
        {
            throw new NotImplementedException();
        }

        public int ReadAnalog(int deviceId, int channel, ref int value)
        {
            throw new NotImplementedException();
        }

        public int ReadDigital(List<int> deviceList, List<int[]> channelList, ref List<bool[]> values)
        {
            throw new NotImplementedException();
        }

        public int ReadDigital(int deviceId, int channel, ref bool value)
        {
            throw new NotImplementedException();
        }

        public int WriteAnalog(List<int> deviceList, List<int[]> channelList, List<int[]> values)
        {
            throw new NotImplementedException();
        }

        public int WriteAnalog(int deviceId, int channel, int value)
        {
            throw new NotImplementedException();
        }

        public int WriteDigital(List<int> deviceList, List<int[]> channelList, List<bool[]> values)
        {
            throw new NotImplementedException();
        }

        public int WriteDigital(int deviceId, int channel, bool value)
        {
            throw new NotImplementedException();
        }

        public int getConnection()
        {
            throw new NotImplementedException();
        }

        public List<SlaveDevice> getInputDevices()
        {
            throw new NotImplementedException();
        }

        public List<SlaveDevice> getOutputDevices()
        {
            throw new NotImplementedException();
        }
    }
}
