using System;
using System.Collections;
using System.Linq;
using System.Text;

/*
 * 
 * Version 3.0 of the Names Collection Library
 * This uses composition
 * 
 */

namespace NamesCollectionNS
{
    public class NamesCollection
    {
        Stack s;
        public NamesCollection()
        {
            s = new Stack();
        }

        public void Add(object o)
        {
            s.Push(o);
        }

        public void display()
        {
            Console.WriteLine("Names:\t");
            foreach (Object item in s)
            {
                Console.Write(item.ToString() + "\t");
            }
        }
    }
}
