using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StarbuzzCoffee
{
    class Soy : CondimentDecorator
    {
        Beverage beverage;

        public Soy(Beverage beverage)
        {
            this.beverage = beverage;
        }
        public override string getDescription()
        {
            return beverage.getDescription() + ", Soy";
        }
        public override double cost()
        {
            return 0.15 + beverage.cost();
        }
    }
}
