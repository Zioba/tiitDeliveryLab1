using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Treap1;
using Test;

namespace ConsoleApp1
{
    class Program
    {
        public static int EnterNumber()
        {
            string input = Console.ReadLine();
            int parsed = Convert.ToInt32(input);
            return parsed;
        }
        

        static void Main(string[] args)
        {
            //int[] xs = new int[6] { 11, 4, 29, 18, 22, 5 };
            //int[] ys = new int[6] { 3, 0, 24, 58, 64, 45 };
            //build
            Console.WriteLine("Enter the length of the tree:");
            var length = EnterNumber();
            int[] xs = new int[length];
            int[] ys = new int[length];
            for (int i = 0; i < length; i++)
            {
                Console.WriteLine("Enter xs:");
                var xx = EnterNumber();
                xs[i] = xx;
            }

            for (int j = 0; j < length; j++)
            {
                Console.WriteLine("Enter ys:");
                var yy = EnterNumber();
                ys[j] = yy;
            }

            Console.WriteLine("Choose the operation");
            Console.WriteLine("1 - Build Cartesian Tree");
            Console.WriteLine("2 - Merge two trees");
            Console.WriteLine("3 - Split a tree by a node");
            Console.WriteLine("4 - Remove the node from a tree");
            Console.WriteLine("5 - Test build");
            Console.WriteLine("6 - Print the tree");
            //Console.WriteLine("7 - Test Merge");
            //Console.WriteLine("8 - Test Split");
            //Console.WriteLine("9 - Test Remove");
            var operation = EnterNumber();

            if (operation == 1) // build
            {

                Treap result = Treap.Build(xs, ys);
                //UnitTest1.TestBuild(xs, ys);


                Console.WriteLine("The root is:");
                Console.WriteLine($"{result.x}{"; "}{result.y}");

                Console.ReadKey();
                Test.UnitTest1.PrintTreap(result);
                return; 

            } 

            else if (operation == 2) //merge 
            {
                //merge
                Console.WriteLine("Enter the length of the second tree:");
                var length2 = EnterNumber();
                int[] xs2 = new int[length2];
                int[] ys2 = new int[length2];
                for (int i = 0; i < length2; i++)
                {
                    Console.WriteLine("Enter xs:");
                    var xx = EnterNumber();
                    xs2[i] = xx;
                }

                for (int j = 0; j < length2; j++)
                {
                    Console.WriteLine("Enter ys:");
                    var yy = EnterNumber();
                    ys2[j] = yy;
                }
                Treap first = Treap.Build(xs, ys);
                Treap second = Treap.Build(xs2, ys2);
                Treap Result_Merge = Treap.Merge(first, second);
                Test.UnitTest1.PrintTreap(Result_Merge);
                return;

            } 

            else if (operation == 3) //split 
            {
                //split               
                Treap tree_to_split = Treap.Build(xs, ys);
                Console.WriteLine("Enter the x of the node by which you want to split the tree: ");
                var xxx = EnterNumber();
                if (xs.Contains(xxx))
                {
                    Treap LL = null;
                    Treap RR = null;
                    tree_to_split.Split(xxx, out LL, out RR);

                }
                else
                {
                    Console.WriteLine("Incorrect x");
                    return;
                }
                Test.UnitTest1.PrintTreap(tree_to_split);
                return;

            } 

            else if (operation == 4) //remove
            {
                //remove
                Treap tree_to_remove = Treap.Build(xs, ys);
                Console.WriteLine("Choose the node by x");
                var xxx = EnterNumber();
                if (xs.Contains(xxx))
                {
                    tree_to_remove.Remove(xxx);
                }
                else if (!xs.Contains(xxx))
                {
                    Console.WriteLine("Incorrect x");
                    return;
                }
                Test.UnitTest1.PrintTreap(tree_to_remove);
                return;

            } 

            else if (operation == 5) //test build
            {
                //test
                
                //Treap result5 = Treap.Build(xs5, ys5);
                UnitTest1.TestBuild(xs, ys);
                return;
            } 

            else if (operation == 6) //printing the elements of tree
            {
                //print
                Treap tree_to_draw = Treap.Build(xs, ys);
                UnitTest1.PrintTreap(tree_to_draw);
                return;
            }  

            else if (operation == 7) //test merge
            {
                Console.WriteLine("Enter the length of the second tree:");
                var length2 = EnterNumber();
                int[] xs2 = new int[length2];
                int[] ys2 = new int[length2];
                for (int i = 0; i < length2; i++)
                {
                    Console.WriteLine("Enter xs:");
                    var xx = EnterNumber();
                    xs2[i] = xx;
                }
                for (int j = 0; j < length2; j++)
                {
                    Console.WriteLine("Enter ys:");
                    var yy = EnterNumber();
                    ys2[j] = yy;
                }
                UnitTest1.TestMerge(xs, ys, xs2, ys2);              
                
            }

            else if (operation == 8) //test Split
            {
                Console.WriteLine("Enter the length of the second tree:");
                var length2 = EnterNumber();
                int[] xs2 = new int[length2];
                int[] ys2 = new int[length2];
                for (int i = 0; i < length2; i++)
                {
                    Console.WriteLine("Enter xs:");
                    var xx = EnterNumber();
                    xs2[i] = xx;
                }
                for (int j = 0; j < length2; j++)
                {
                    Console.WriteLine("Enter ys:");
                    var yy = EnterNumber();
                    ys2[j] = yy;
                }
                UnitTest1.TestMerge(xs, ys, xs2, ys2);

            }

            else if (operation == 9) //test remove
            {
                Console.WriteLine("Enter the length of the second tree:");
                var length2 = EnterNumber();
                int[] xs2 = new int[length2];
                int[] ys2 = new int[length2];
                for (int i = 0; i < length2; i++)
                {
                    Console.WriteLine("Enter xs:");
                    var xx = EnterNumber();
                    xs2[i] = xx;
                }
                for (int j = 0; j < length2; j++)
                {
                    Console.WriteLine("Enter ys:");
                    var yy = EnterNumber();
                    ys2[j] = yy;
                }
                UnitTest1.TestMerge(xs, ys, xs2, ys2);

            }

            else
            {
                Console.WriteLine("incorrect input");
                return;

            }



            }
        }

    }


