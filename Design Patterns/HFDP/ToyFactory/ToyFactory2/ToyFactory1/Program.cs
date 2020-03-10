using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ToyFactory1
{
    class Program
    {
        // NOT CLOSED FOR MODIFICATION!
        static Toy buyToy(string sex)
        {
            if (sex.ToUpper().Equals("BOY"))
            {
                return new BoyToy();
            }
            else
            {
                return new GirlToy();
            }
        }

        static void Main(string[] args)
        {
            Toy toy;

            toy = buyToy("GIRL");

            toy.play();
        }
    }
}
