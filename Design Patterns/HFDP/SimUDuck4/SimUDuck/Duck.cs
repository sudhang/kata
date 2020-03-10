using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimUDuck
{
    class Duck 
    {
        internal FlyingBehavior flyingBehavior;
        public FlyingBehavior FlyingBehavior 
        {
            get { return this.flyingBehavior; }
            set { this.flyingBehavior = value; }
        }

        public virtual void fly()
        {
            Console.Write(this.ToString());
            flyingBehavior.fly();
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
