using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimUDuck
{
    class MallardDuck : Duck
    {
        public MallardDuck()
        {
            flyingBehavior = new FlyWithWings();
        }

        public override string ToString()
        {
            return "Mallard Duck";
        }
    }
}
