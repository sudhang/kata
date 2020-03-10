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
            Duck duck = new MallardDuck();
            duck.fly();
            duck = new RedheadDuck();
            duck.fly();
            duck = new RubberDuck();
            duck.fly();
        }
    }
}
