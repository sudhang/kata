using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimUDuck
{
    class RubberDuck : Duck
    {
        FlyNot flyingMethod = new FlyNot();
        public override void fly()
        {
            flyingMethod.fly();
        }
        public override string ToString()
        {
            return "Rubber Duck";
        }
    }
}
