using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using ServiceStack.Redis;

namespace MasterConnectorConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            RedisClient client = new RedisClient("127.0.0.1", 6379);

            client.Add("123", "kkk");
            Console.WriteLine(client.Get<string>("123"));

            List<string> keyStrList = client.GetAllKeys();
            keyStrList.ForEach(delegate (string key)
            {
                Console.WriteLine(key + "=>" + client.Get<string>(key));
            });

            client.HSet("1", Encoding.UTF8.GetBytes("123"), Encoding.UTF8.GetBytes("234"));
            client.HSet("1", Encoding.UTF8.GetBytes("111"), Encoding.UTF8.GetBytes("2jqk"));
        }
    }
}
