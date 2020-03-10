using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Contacts
{
    class Program
    {
        // Application changed to include family members (who are sent sms) and oldClassmates who are sent emails
        // Suppose there are 100s of more such classes.  One day someone says that with every email message, a signature must be added?
        static void Main(string[] args)
        {
            Contact boss = new Colleague("Aayushi", "boss@work.com", "1234567");
            boss.sendMessage("WFH Today");

            Contact friend = new Friend("Kafka", "kafka@bar.com", "98765443");
            friend.sendMessage("Party Today");

            Contact mom = new FamilyMember("Mom", "mom@home.com", "9213834532");
            mom.sendMessage("Working Late Today");

            Contact oldClassmate = new OldClassmate("arjun", "arjun@college.com", "928934543");
            oldClassmate.sendMessage("Have you collected your degree yet?");

            // Change message sending strategy at runtime
            oldClassmate.msp = new SMSProcess();
            oldClassmate.sendMessage("Have you collected your degree yet?");
        }
    }
}
