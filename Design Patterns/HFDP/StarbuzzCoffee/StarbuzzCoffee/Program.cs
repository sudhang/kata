using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StarbuzzCoffee
{
    class Program
    {
        static void Main(string[] args)
        {
            Beverage beverage = new Espresso();
            Console.WriteLine(beverage.getDescription() + " $" + beverage.cost());

            Beverage beverage2 = new HouseBlend();
            beverage2 = new Mocha(beverage2);
            beverage2 = new Soy(beverage2);
            beverage2 = new Whip(beverage2);
            Console.WriteLine(beverage2.getDescription() + " $" + beverage2.cost());
        }
    }
}
