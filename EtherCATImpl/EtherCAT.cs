using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using IndustrialEthernetAPI;
using IndustrialEthernetEntity;

namespace EtherCATImpl
{
    class EtherCAT : IConnection, IAdapterLoader, IDeviceLoader, IReadWrite
    {
        //public IOdevice[] devices { get; set; }
        #region region_property
        public ConnectionContext context { get; set; }
        #endregion

        #region region_const
        private const int SAFECODE = 0;
        #endregion

        #region region_event

        public event EventHandler datachanged;

        #endregion


        #region region_connection
        public int close()
        {
            throw new NotImplementedException();
        }

        public int connect()
        {
            throw new NotImplementedException();
        }

        public int disconnect()
        {
            throw new NotImplementedException();
        }
        #endregion

        #region region_deviceLoader

        public IOdevice[] getDevice()
        {
            int slaveNum = CppConnect.getSlaveNum();
            context.deviceNum = slaveNum;
            for (int i = 0; i < slaveNum; i++)
            {
                Slave tmpSlave = new Slave();
                int err = CppConnect.getSlaveInfo(ref tmpSlave, i);
                if (err == SAFECODE)
                {
                    context.devices[i] = tmpSlave;
                }
                else//有错误
                {
                    throw new Exception();
                }
            }
            return context.devices;
        }

        #endregion

        #region region_readWrite
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
            return CppConnect.setIntergerValue(deviceId, channel, value);
        }
        /// <summary>
        /// 批量写
        /// </summary>
        /// <param name="deviceList"></param>
        /// <param name="channelList"></param>
        /// <param name="values"></param>
        /// <returns></returns>
        public int WriteDigital(List<int> deviceList, List<int[]> channelList, List<bool[]> values)
        {
            throw new NotImplementedException();
        }

        public int WriteDigital(int deviceId, int channel, bool value)
        {
            return CppConnect.setDigitalValue(deviceId, channel, value);
        }
        #endregion

        #region region_adapter
        Adapter[] IAdapterLoader.getAdapter()
        {
            int adapternum = CppConnect.getAdapterNum();
            context.adapters = new Adapter[adapternum];

            StringBuilder tmpAdapterName = new StringBuilder();
            tmpAdapterName.Capacity = 128;
            for (int i = 0; i < adapternum; i++)
            {
                int err = CppConnect.getContextInfo(tmpAdapterName);
                if (err != 0)//有错误
                {

                }
                context.adapters[i].name = tmpAdapterName.ToString();
                tmpAdapterName.Clear();
            }
            return context.adapters;
        }

        ErrorCode IAdapterLoader.setAdapter(int id)
        {
            int err = CppConnect.setNicId(id);
            if (err != 0)
            {
                return ErrorCode.ADAPTER_SELECT_FAIL;
            }
            return 0;
        }
        #endregion

        #region other method

        #endregion
    }
}
