using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StarbuzzCoffee
{
    abstract class CondimentDecorator : Beverage
    {
        public override abstract string getDescription();
    }
}
