using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ToyFactory1
{
    interface IPartsFactory          // The "abstract" factory
    {
        HeadGear createHat();
        Skirt createSkirt();
    }
}
