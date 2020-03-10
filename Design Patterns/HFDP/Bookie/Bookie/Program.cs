using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Bookie
{
    class Program
    {
        static void Main(string[] args)
        {
            Match m1 = new Match("Mumbai Indians", "Kolkata Knight Riders");
            Better b1 = new Better("Sudhang");
            Better b2 = new Better("Devanshu");

            m1.registerObserver(b1);
            m1.registerObserver(b2);
            m1.odds = 1.3f;

            m1.unRegisterObserver(b1);
            m1.odds = 1.7f;
        }
    }
}
