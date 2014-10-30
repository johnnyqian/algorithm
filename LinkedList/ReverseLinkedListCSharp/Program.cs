using System;
using System.Collections.Generic;
using System.IO;

namespace ReverseLinkedListCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Node<int> p, tmp;
            var list = new LinkedList<int>();
            p = list.Header;

            var streamReader = new StreamReader("Input.txt");
            Console.SetIn(streamReader);

            string line;
            while((line=Console.ReadLine())!=null)
            {
                tmp = new Node<int>();
                tmp.Data = int.Parse(line);

                p.Next = tmp;
                p = p.Next;
            }

            // 1. use while loop
            list.Print();
            list.Reverse();
            list.Print();

            // reset linked list
            list.Reverse();
            Console.WriteLine();

            // 2. use recursion
            list.Print();
            list.ReverseByRecursion();
            list.Print();

            // reset linked list
            list.Reverse();
            Console.WriteLine();

            // 3. use stack
            list.Print();
            list.ReverseByStack();
            list.Print();
        }
    }

    class LinkedList<T>
    {
        public Node<T> Header { get; set; }

        public LinkedList()
        {
            Header = new Node<T>();
        }

        public void Print()
        {
            var p = Header.Next;
            while(p!=null)
            {
                Console.Write("{0}\t",p.Data);
                p = p.Next;
            }
            Console.WriteLine();
        }

        public void Reverse()
        {
            var curr = Header.Next; // 第一个数据节点
            if (curr==null || curr.Next == null)
                return;

            Node<T> pre=null, tmp;
            while(curr!=null)
            {
                tmp = curr;
                curr = curr.Next;
                tmp.Next = pre;
                pre = tmp;
            }
            Header.Next = pre;
        }

        Node<T> ReverseByRecursionInternal(Node<T> pre, Node<T> curr)
        {
            Node<T> next = curr.Next;
            curr.Next = pre;

            if (next != null)
                return ReverseByRecursionInternal(curr, next);
            else
                return curr;
        }

        public void ReverseByRecursion()
        {
            var curr = Header.Next; // 第一个数据节点
            if (curr == null || curr.Next == null)
                return;

            Header.Next = ReverseByRecursionInternal(null, curr);
        }

        public void ReverseByStack()
        {
            var curr = Header.Next; // 第一个数据节点
            if (curr == null || curr.Next == null)
                return;

            Stack<Node<T>> stack = new Stack<Node<T>>();
            while(curr!=null)
            {
                stack.Push(curr);
                curr = curr.Next;
            }

            Header.Next = curr = stack.Pop(); // 将头结点指向逆置后的第一个节点

            Node<T> tmp;
            while(stack.Count>0)
            {
                tmp = stack.Pop();

                curr.Next = tmp;
                curr = tmp;
            }
            curr.Next = null;
        }
    }

    class Node<T>
    {
        public T Data { get; set; }

        public Node<T> Next { get; set; }
    }
}