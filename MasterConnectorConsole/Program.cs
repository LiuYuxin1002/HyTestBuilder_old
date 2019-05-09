using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace MasterConnectorConsole
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
    public struct Context
    {
        public List<StringBuilder> nicDesc;
        public List<StringBuilder> nicName;
        public int adapterNum;
    }

    public class InterfaceClass
    {
        //获取计算机网卡信息，接收到Context结构体
        [DllImport("DLLOutput.dll")]
        public static extern int getAdapterNum();
        [DllImport("DLLOutput.dll", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern int getContextInfo(StringBuilder str);
        //设置所选网卡，如果失败返回错误信息，成功返回当前连接的从站信息
        [DllImport("DLLOutput.dll", EntryPoint = "setNicId", CallingConvention = CallingConvention.Cdecl)]
        public static extern int setNicId(int nicId);
        //自动配置从站，成功更新结构体数组
        [DllImport("DLLOutput.dll")]
        public static extern int initConfig();
        [DllImport("DLLOutput.dll", EntryPoint = "setNicInfo", CallingConvention = CallingConvention.Cdecl)]
        public static extern void getSlaveInfo(ref SlaveInfo slaveInfo, int id);
        //设置从站某端口信息
        [DllImport("DLLOutput.dll")]
        public static extern int setIntergerValue(int slaveId, int channel, int value);
        [DllImport("DLLOutput.dll")]
        public static extern int setDoubleValue(int slaveId, int channel, double value);
    }
    class Program
    {
        static void Main(string[] args)
        {
            Context context = new Context();
            context.nicName = new List<StringBuilder>(10);

            int adapterNum = InterfaceClass.getAdapterNum();
            Console.WriteLine("您的网卡信息如下, 请选择：");
            for (int i=0; i< adapterNum; i++)
            {
                StringBuilder strb = new StringBuilder(128);
                int nicNum = InterfaceClass.getContextInfo(strb);
                context.nicName.Add(strb);
                Console.WriteLine("[" + i + "] :" + strb);
            }
            //读取选择网卡
            int selected = int.Parse(Console.ReadLine());
            int result = InterfaceClass.setNicId(selected);

            if (result <= 0)//连接失败
            {
                Console.WriteLine("当前选择网卡没有连接从站，请检查");
                return;
            }
            
            //如果连接成功，建立从站结构体数组
            SlaveInfo[] slaveinfo = new SlaveInfo[context.adapterNum];
            //显示从站信息
            Console.WriteLine("您的计算机连接的从站信息如下：");
            for (int i=0; i<context.adapterNum; i++)
            {
                InterfaceClass.getSlaveInfo(ref slaveinfo[i], i);
                Console.WriteLine(i+":"+slaveinfo[i].name);
            }

            //写入测试
            InterfaceClass.setIntergerValue(1, 1, 240);
            InterfaceClass.getSlaveInfo(ref slaveinfo[1], 1);
            Console.WriteLine("写入测试结果:" + slaveinfo[1].state);
        }
    }
}
