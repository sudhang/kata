using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Bookie
{
    class Better : Observer
    {
        public float odds { get; set; }
        public string name { get; set; }

        public Better(string name)
        {
            this.name = name;
        }

        public void update(float odds)
        {
            this.odds = odds;
            Console.WriteLine(name + ": New odds: " + odds);
        }
    }
}
