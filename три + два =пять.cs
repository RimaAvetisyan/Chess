using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp27
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int x = 100; x <= 999; x++)
            {

                int xa = x / 100 % 10;
                int xb = x / 10 % 10;
                int xc = x % 10;
                if (xc == xa || xc == xb || xa == xb) continue;
                for (int y = 100; y <= 999; y++)
                {

                    int ya = y / 100 % 10;
                    int yb = y / 10 % 10;
                    int yc = y % 10;
                    if (ya == yb || ya == yc || yb == yc
            || ya == xa || ya == xb || ya == xc
            || yb == xa || yb == xb || yb == xc
            || yc == xa || yc == xb || yc == xc)
                        continue;

                    int z = x + y;

                    if (z < 1000) continue;


                    int za = z / 1000 % 10;
                    int zb = z / 100 % 10;
                    int zc = z / 10 % 10;
                    int zd = z % 10;

                    if (zc != xa
            || za == zb || za == zc || za == zd || zb == zc || zb == zd || zc == zd
            || za == xb || za == xc || za == ya || za == yb || za == yc
            || zb == xb || zb == xc || zb == ya || zb == yb || zb == yc
            || zd == xb || zd == xc || zd == ya || zd == yb || zd == yc) continue;

                    Console.WriteLine($"{x} + {y} = {z}");
                }
            }
            Console.ReadKey();
        }
    }
}
