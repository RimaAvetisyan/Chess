using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp21
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int x = 1;
            int y = 2;
            int z = 3;
            while (x < Math.Sqrt(n))
            {
                y = x + 1;
                while (y < Math.Sqrt(n))
                {
                    z = y + 1;
                    while (z < Math.Sqrt(n))
                    {
                        if ((x * x) + (y * y) + (z * z) == n)
                        {
                            Console.WriteLine(x+"+"+y+"+"+z+"="+n);

                        }
                        z++;
                    }
                    y++;
                }
                x++;
            }
            Console.ReadKey();
        }
    }
}
