using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp31
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            switch (n)
            {
                case 1:
                    Console.WriteLine("erkushabti");
                    break;
                case 2:
                    Console.WriteLine("ereqshabti");
                    break;
                case 3:
                    Console.WriteLine("choreqshabti");
                    break;
                case 4:
                    Console.WriteLine("hingshabti");
                    break;
                case 5:
                    Console.WriteLine("urbat");
                    break;
                case 6:
                    Console.WriteLine("shabat");
                    break;
                case 7:
                    Console.WriteLine("kiraki");
                    break;
                default:
                    Console.WriteLine("sxal tiv eq mutqagrel");
                    break;

            }
            Console.ReadKey();
        }
    }
}
