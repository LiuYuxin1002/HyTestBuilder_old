using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace MasterConnectorConsole.Connectors
{
    //单个从站
    [StructLayout(LayoutKind.Sequential)]
    public struct SlaveInfo
    {
        public int state;
        public string name;
    }

    //试验环境上下文信息
    [StructLayout(LayoutKind.Sequential)]
    public struct Adapter
    {
        public List<StringBuilder> nicDesc;
        public List<StringBuilder> nicName;
        public int adapterNum;
    }

    public class BaseTools
    {
        public static int MAX_ADAPTER_NUM = 10;

        Adapter adapter;

        public BaseTools()
        {
            adapter = new Adapter();
            adapter.nicName = new List<StringBuilder>(MAX_ADAPTER_NUM);
        }

        /// <summary>
        /// 获取网络适配器列表
        /// </summary>
        /// <returns>一个网络适配器名称的StringBuilder列表</returns>
        public List<StringBuilder> getAdapterInfo()
        {
            //获取网卡数目并初始化
            int adapterNum = InterfaceClass.getAdapterNum();
            if (adapterNum == 0)/*没有adapter，返回空*/
            {
                return null;
            }
            else/*有adapter，返回stringbuilder*/
            {
                for (int i = 0; i < adapterNum; i++)
                {
                    StringBuilder strb = new StringBuilder(128);
                    int nicNum = InterfaceClass.getContextInfo(strb);
                    adapter.nicName.Add(strb);
                }
            }
            return adapter.nicName;
        }

        public SlaveInfo[] setAdapterIdToUse(int id)
        {
            int isConnected = InterfaceClass.setNicId(id);
            //isConnected表示连接的从站数量
            if (isConnected > 0)
            {
                //如果连接成功，建立从站结构体数组
                SlaveInfo[] slaveinfo = new SlaveInfo[isConnected+1];
                //显示从站信息
                //Console.WriteLine("您的计算机连接的从站信息如下：");
                for (int i = 0; i < isConnected + 1; i++)
                {
                    InterfaceClass.getSlaveInfo(ref slaveinfo[i], i);
                    Console.WriteLine(i + ":" + slaveinfo[i].name);
                }
                return slaveinfo;
            }
            else
            {
                return null;
            }
        }
    }
}
