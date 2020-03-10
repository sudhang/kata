using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Contacts
{
    class SMSProcess
    {
        public void sendMessage(string name, string message)
        {
            Console.WriteLine("Sending sms to: " + name + " : " + message);
        }
    }
}
