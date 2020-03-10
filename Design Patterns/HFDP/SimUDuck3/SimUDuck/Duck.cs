using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimUDuck
{
    class Duck 
    {
        public virtual void fly()
        {
        }

        public virtual void quack()
        {
            Console.WriteLine("QUACK QUACK");
        }
        public virtual void display()
        {
            Console.WriteLine("look at this " + this.ToString());
        }
    }
}
