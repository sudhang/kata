using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimUDuck
{
    class MallardDuck : Duck
    {
        FlyWithWings flyingMethod = new FlyWithWings();
        public override string ToString()
        {
            return "Mallard Duck";
        }
        public override void fly()
        {
            Console.Write(this.ToString());
            flyingMethod.fly();
        }
    }
}
