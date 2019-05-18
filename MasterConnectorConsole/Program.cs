using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using ServiceStack.Redis;
using EtherCATImpl.database;

namespace MasterConnectorConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            //RedisClient client = RedisManager.Client;

            //simple operation
            //client.Add("123", "kkk");
            //Console.WriteLine(client.Get<string>("123"));

            //List<string> keyStrList = client.GetAllKeys();
            //keyStrList.ForEach(delegate (string key)
            //{
            //    Console.WriteLine(key + "=>" + client.Get<string>(key));
            //});

            //client.HSet("1", Encoding.UTF8.GetBytes("123"), Encoding.UTF8.GetBytes("234"));
            //client.HSet("1", Encoding.UTF8.GetBytes("111"), Encoding.UTF8.GetBytes("2jqk"));


            //Dictionary<string, string> data = new Dictionary<string, string>();
            //data.Add("1_1", "256");
            //data.Add("1_2", "257");
            //data.Add("1_3", "258");
            //data.Add("1_4", "259");
            //data.Add("2_1", "260");
            //data.Add("2_2", "261");

            //string time = "1";

            //RedisHashHelper.AddKeyValues(client, time, data);

            //Dictionary<string, string> readData = RedisHashHelper.GetKeyValues(client, time);

            //Dataframe dataframe = DataDeserialization.deserializedDic(readData);

            //for(int i = 0; i<dataframe.count; i++)
            //{
            //    Console.WriteLine(dataframe.toString()[i]);
            //}

            BaseClass bc = new BaseClass();
            Console.ReadKey();
        }
    }
}
