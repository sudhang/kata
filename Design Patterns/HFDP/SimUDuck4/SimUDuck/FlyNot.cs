using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimUDuck
{
    class FlyNot : FlyingBehavior
    {
        public void fly()
        {
            Console.WriteLine("Cannot fly");
        }
    }
}
