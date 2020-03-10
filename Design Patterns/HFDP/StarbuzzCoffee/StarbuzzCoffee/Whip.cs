using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StarbuzzCoffee
{
    class Whip : CondimentDecorator
    {
        Beverage beverage;

        public Whip(Beverage beverage)
        {
            this.beverage = beverage;
        }
        public override string getDescription()
        {
            return beverage.getDescription() + ", Whip";
        }
        public override double cost()
        {
            return 0.15 + beverage.cost();
        }
    }
}
