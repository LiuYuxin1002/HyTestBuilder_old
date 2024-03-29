﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace testConsole
{
    class ImportClass
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
}
