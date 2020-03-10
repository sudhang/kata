using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StarbuzzCoffee
{
    abstract class Beverage
    {
        public string description = "Unknown Beverage";

        public virtual string getDescription()
        {
            return description;
        }

        public abstract double cost();
    }
}
