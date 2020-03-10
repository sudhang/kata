using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimUDuck
{
    class RedheadDuck : Duck, Flyable
    {
        public override string ToString()
        {
            return "RedheadDuck";
        }
        public virtual void fly()
        {
            Console.WriteLine(this.ToString() + " is flying high");
        }
    }
}
