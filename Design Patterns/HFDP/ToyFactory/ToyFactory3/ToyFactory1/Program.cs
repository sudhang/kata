using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ToyFactory1
{
    class Program
    {

        static void Main(string[] args)
        {
            IPartsFactory pf;

            //pf = new EuropeanPartsFactory();
            pf = new IndianPartsFactory();

            Toy toy;

            toy = new BoyToy(pf);

            toy.play();

            Toy toy2;
            toy2 = new GirlToy(pf);
            toy2.play();
        }
    }
}
