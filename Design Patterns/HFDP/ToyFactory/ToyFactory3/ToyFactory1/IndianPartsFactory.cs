using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ToyFactory1
{
    class IndianPartsFactory : IPartsFactory // concrete factory
    {
        public HeadGear createHat()
        {
            return new Pagdi();
        }
        public Skirt createSkirt()
        {
        }
    }
}
