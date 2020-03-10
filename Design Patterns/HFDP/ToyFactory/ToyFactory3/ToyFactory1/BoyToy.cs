using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ToyFactory1
{
    class BoyToy : Toy
    {
        HeadGear hat;

        IPartsFactory factory;

        public BoyToy(IPartsFactory factory)
        {
            this.factory = factory;
            this.hat = factory.createHat();
        }

        public override void play()
        {
            Console.WriteLine("This is a Toy for Boys");
            Console.WriteLine(hat.describe());
        }

    }
}
