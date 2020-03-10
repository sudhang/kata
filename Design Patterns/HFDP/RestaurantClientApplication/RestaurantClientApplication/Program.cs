using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using NamesCollectionNS;

namespace RestaurantClientApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            NamesCollection names = new NamesCollection();

            names = new NamesCollection();
            names.Add("Mutton Rogan Josh");
            names.Add("Chicken Tikka");
            names.Add("Pasta Prima Vera");
            names.display();
        }
    }
}
