using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ToyFactory1
{
    class GirlToy : Toy
    {
        IPartsFactory factory;

        public GirlToy(IPartsFactory factory)
        {
            this.factory = factory;
        }

        public override void play()
        {
            Console.WriteLine("This is a toy for girls");
        }
    }
}
