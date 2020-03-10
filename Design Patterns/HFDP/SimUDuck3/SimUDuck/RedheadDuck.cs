using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimUDuck
{
    class RedheadDuck : Duck
    {
        FlyWithWings flyingMethod = new FlyWithWings();
        public override string ToString()
        {
            return "RedheadDuck";
        }
        public override void fly()
        {
            Console.Write(this.ToString());
            flyingMethod.fly();
        }
    }
}
