using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ToyFactory1
{
    class EuropeanPartsFactory : IPartsFactory   // concrete factory
    {

        public HeadGear createHat()
        {
            return new Cap();
        }
    }
}
