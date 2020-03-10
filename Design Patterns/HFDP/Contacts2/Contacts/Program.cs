using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Contacts
{
    class Program
    {
        static void Main(string[] args)
        {
            Contact boss = new Colleague("Aayushi", "boss@work.com", "1234567");
            boss.sendMessage("WFH Today");

            Contact friend = new Friend("Kafka", "kafka@bar.com", "98765443");
            friend.sendMessage("Party Today");
        }
    }
}
