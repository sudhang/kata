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
            Toy toy;

            toy = new BoyToy();     // Hardcoding!

            toy.play();
        }
    }
}
