using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Contacts
{
    class EmailProcess : MessageSendingProcess
    {
        // Message with signature for email
        public void sendMessage(string name, string message)
        {
            Console.WriteLine("Sending email to: " + name + " : " + message + "\n\t\tKR, Sudhang");
        }
    }
}
