using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using Treap1;
using System.Linq;
using System.Diagnostics;
using System.Collections;
using System.Collections.Generic;
//using NUnit;


namespace Test
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public static void TestBuild(int[] xs, int[] ys)
        {

            //int[] xs = new int[6] { 11, 4, 29, 18, 22, 5 };
            //int[] ys = new int[6] { 3, 0, 24, 58, 64, 45 };


            Treap result5 = Treap.Build(xs, ys);
            int m = ys.Max();
            int index_m = Array.IndexOf(ys, m);
            Treap expected = new Treap(xs[index_m], ys[index_m]);

            // Assert
            Assert.AreEqual(expected.x, result5.x);
            Assert.AreEqual(expected.y, result5.y);
            //Debug.Assert();
            if (expected.x == result5.x && expected.y == result5.y)
            {
                Console.WriteLine("Expected x of the root is ");
                Console.WriteLine(expected.x);
                Console.WriteLine("Expectd y of the root is ");
                Console.WriteLine(expected.y);
                Console.WriteLine("x of the result tree is ");
                Console.WriteLine(result5.x);
                Console.WriteLine("y of the result tree is ");
                Console.WriteLine(result5.y);
                Console.WriteLine("PASSED");
            }
            else
                Console.WriteLine("Not Passed");
            

        }

        [TestMethod]
        public static void TestMerge(int[] xs, int[] ys, int[] xs2, int[] ys2)
        {
            //int[] xs = new int[6] { 11, 4, 29, 18, 22, 5 };
            //int[] ys = new int[6] { 3, 0, 24, 58, 64, 45 };

            Treap first = Treap.Build(xs, ys);
            Treap second = Treap.Build(xs2, ys2);

            Treap res = Treap.Merge(first, second);
            //Assert.AreEqual(res, second);
            PrintTreap(res);
        }
        static Dictionary<int, int> elements = new Dictionary<int, int>();
        [TestMethod]
        public static void PrintTreap(Treap tree)
        {
            // Console.WriteLine($"{Tr.x} {";"} {Tr.y}");            
            //int k = 0;
            if (tree != null)
            {
                Console.WriteLine($"{tree.x} {";"} {tree.y}");
                elements.Add(tree.x, tree.y);
                PrintTreap(tree.Left);                
                PrintTreap(tree.Right);
            }

        }

    }
}
