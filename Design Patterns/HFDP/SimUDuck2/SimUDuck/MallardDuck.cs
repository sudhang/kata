using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimUDuck
{
    class MallardDuck : Duck, Flyable
    {
        public override string ToString()
        {
            return "Mallard Duck";
        }
        public virtual void fly()
        {
            Console.WriteLine(this.ToString() + " is flying high");
        }
    }
}
