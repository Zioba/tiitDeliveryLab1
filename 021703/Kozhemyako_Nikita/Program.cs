using System;

namespace lw1_sem2_tiit
{

    class MyQueue
    {

        private class Node
        {
            public Node Next = null;
            public int Data;

            public Node(int data)
            {
                this.Data = data;
            }

        }

        private Node head;
        private int size = 0;

        public void Add(int value)
        {
            if (size == 0)
            {
                head = new Node(value);

            }
            else
            {
                Node current = head;
                while (current.Next != null)
                {
                    current = current.Next;
                }
                current.Next = new Node(value);
            }
            size++;
        }

        public int Get()
        {
            if (size == 0)
            {
                throw new NullReferenceException();
            }
            else
            {
                int retVal = head.Data;
                if (head.Next != null)
                {
                    head = head.Next;
                }

                size--;
                return retVal;
            }
        }
        public int GetSize()
        {
            return size;
        }

        public void PrintList()
        {
            int counter = size;
            if (counter == 0)
            {
                Console.WriteLine("Queue is empty!");
            }
            else
            {
                Node outer = head;
                while (counter != 0)
                {
                    Console.WriteLine(outer.Data);
                    outer = outer.Next;
                    counter--;
                }
            }
        }

        public int CheckHead()
        {
            Node HeadData = head;
            return HeadData.Data;
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            MyQueue q1 = new MyQueue();
            int c = 0;
            bool w = true;
            int switcher;
            //do
            while (c < args.Length)
            {

                Console.WriteLine("Choose required operation with queue:\n1 - Add element to the queue\n2 - Extract from the queue\n3 - Output number of elements in the queue\n4 - Output the queue\n");
                string switcherstr = args[c];
                c++;//Console.ReadLine(args);
                switcherstr = switcherstr.Trim();
                if ((switcherstr != "1") & (switcherstr != "2") & (switcherstr != "3") & (switcherstr != "4") & (switcherstr != "5"))
                {
                    Console.WriteLine("Format of input data is incorrect");
                }
                else
                {
                    switcher = Convert.ToInt32(switcherstr);
                    switch (switcher)
                    {
                        case 1:
                            {
                                try
                                {
                                    int element;
                                    string elementstr;
                                    Console.WriteLine("Enter the element");
                                    elementstr = args[c];
                                    c++;
                                    element = Convert.ToInt32(elementstr);
                                    q1.Add(element);
                                    Console.WriteLine(element);
                                    break;
                                }
                                catch (FormatException)
                                {
                                    Console.WriteLine("Format of the element is incorrect");
                                    break;
                                }
                            }
                        case 2:
                            {
                                try
                                {
                                    int HeadData = q1.CheckHead();
                                    q1.Get();
                                    Console.WriteLine($"Value of extracted element - {HeadData}");
                                    break;
                                }
                                catch (NullReferenceException)
                                {
                                    Console.WriteLine("Queue is empty, element extraction is not available");
                                    break;
                                }
                            }
                        case 3:
                            {
                                int ElementNumb = q1.GetSize();
                                Console.WriteLine($"Number of elements in the queue - {ElementNumb}");
                                break;
                            }
                        case 4:
                            {
                                Console.WriteLine("View of the queue:");
                                q1.PrintList();
                                break;
                            }
                        //case 5:
                        //    {
                        //        w = false;
                        //        break;
                        //    }

                    }
                }
            } /*while (c<args.Length);*/
        }
    }
}