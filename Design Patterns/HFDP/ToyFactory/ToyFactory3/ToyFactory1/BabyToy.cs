using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ToyFactory1
{
    class BabyToy : Toy
    {
        Skirt sk;

        IPartsFactory factory;

        public BabyToy(IPartsFactory factory)
        {
            this.factory = factory;
     
        }

        public override void play()
        {
            Console.WriteLine("This is a Toy for babies");
            Console.WriteLine(hat.describe());
        }
    }
}
