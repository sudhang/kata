using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimUDuck
{
    class Program
    {
        static void Main(string[] args)
        {
            Flyable duck = new MallardDuck();
            duck.fly();
            duck = new RedheadDuck();
            duck.fly();

            Duck duck2 = new Duck();
            duck2 = new RubberDuck();
            //duck2.fly();
        }
    }
}
