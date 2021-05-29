using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Treap1; 

namespace ConsoleApp1
{
    class Program
    {
        public static Treap Build(int[] xs, int[] ys)
        {
            Console.WriteLine(xs.Length == ys.Length);
            //System.Diagnostics.Debug.Assert(xs.Length == ys.Length);

            var tree = new Treap(xs[0], ys[0]);
            var last = tree;

            for (int i = 1; i < xs.Length; ++i)
            {
                if (last.y > ys[i])
                {
                    last.Right = new Treap(xs[i], ys[i], parent: last);
                    last = last.Right;
                }
                else
                {
                    Treap cur = last;
                    while (cur.Parent != null && cur.y <= ys[i])
                        cur = cur.Parent;
                    if (cur.y <= ys[i])
                        last = new Treap(xs[i], ys[i], cur);
                    else
                    {
                        last = new Treap(xs[i], ys[i], cur.Right, null, cur);
                        cur.Right = last;
                    }
                }
            }

            while (last.Parent != null)
                last = last.Parent;
            return last;
        }

        static void Main(string[] args)
        {
            int[] xs = new int[6] { 11, 4, 29, 18, 22, 5 };
            int[] ys = new int[6] { 67, 0, 24, 58, 64, 45 };
            Treap result = Build(xs, ys);
            Console.WriteLine(result.Parent);
            Console.WriteLine(result.Left);
            Console.WriteLine(result.Right);
            Console.ReadKey();
            

        }
    }

}

