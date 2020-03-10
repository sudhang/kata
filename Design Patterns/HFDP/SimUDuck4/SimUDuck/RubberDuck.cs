using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimUDuck
{
    class RubberDuck : Duck
    {
        public RubberDuck()
        {
            flyingBehavior = new FlyNot();
        }
        public override string ToString()
        {
            return "Rubber Duck";
        }
    }
}
