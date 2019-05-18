using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using IndustrialEthernetAPI;
using IndustrialEthernetEntity;

namespace EtherCATImpl
{
    public class EtherCAT : ConnectionContext, IConnection, IAdapterLoader, IDeviceLoader, IReadWrite
    {
        #region region_属性
        //public ConnectionContext context { get; set; }
        #endregion

        #region region_常量
        private const int SAFECODE = 0;

        public EtherCAT(bool hasAdapter) : base(hasAdapter)
        {
            //context = new ConnectionContext(hasAdapter);
        }
        #endregion

        #region region_事件

        public event EventHandler datachanged;

        #endregion

        #region region_连接管理
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

        #region region_硬件

        public IOdevice[] getDevice()
        {
            int slaveNum = CppConnect.getSlaveNum();
            deviceNum = slaveNum;
            for (int i = 0; i < slaveNum; i++)
            {
                IOdevice tmpSlave = new IOdevice();
                int err = CppConnect.getSlaveInfo(ref tmpSlave, i);
                if (err == SAFECODE)
                {
                    devices[i] = tmpSlave;
                }
                else//有错误
                {
                    throw new Exception();
                }
            }
            return devices;
        }

        #endregion

        #region region_读写
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

        #region region_网卡
        public Adapter[] getAdapter()
        {
            adapterNum = CppConnect.getAdapterNum();
            adapters = new Adapter[adapterNum];

            StringBuilder tmpAdapterName = new StringBuilder();
            tmpAdapterName.Capacity = 128;
            for (int i = 0; i < adapterNum; i++)
            {
                int err = CppConnect.getContextInfo(tmpAdapterName);
                if (err != 0)//有错误
                {

                }
                adapters[i] = new Adapter();
                adapters[i].name = tmpAdapterName.ToString();
                tmpAdapterName.Clear();
            }
            return adapters;
        }

        public ErrorCode setAdapter(int id)
        {
            int err = CppConnect.setNicId(id);
            if (err != 0)
            {
                return ErrorCode.ADAPTER_SELECT_FAIL;
            }
            return 0;
        }

        IOdevice[] IDeviceLoader.getDevice()
        {
            throw new NotImplementedException();
        }
        #endregion

        #region other method

        #endregion
    }
}
