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

        public int setAdapterIdToUse()
        {

        }
    }
}
