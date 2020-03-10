using System;
using System.Collections;
using System.Linq;
using System.Text;

/*
 * 
 * Version 2.0 of the Names Collection Library
 * This extends the .NET Stack class
 * 
 */

namespace NamesCollectionNS
{
    public class NamesCollection : Stack
    {
        public void display()
        {
            Console.WriteLine("Names:\t");
            foreach (Object item in this)
            {
                Console.Write(item.ToString() + "\t");
            }
        }
    }
}
