using System;
using System.Collections;
using System.Linq;
using System.Text;

/*
 * 
 * Version 1.0 of the Names Collection Library
 * This extends the .NET ArrayList class
 * 
 */

namespace NamesCollectionNS
{
    public class NamesCollection : ArrayList
    {
        public void display()
        {
            Console.WriteLine("Names:\t");
            foreach (object item in this)
            {
                Console.Write(item.ToString() + "\t");
            }
        }
    }
}
