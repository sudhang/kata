using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Contacts
{
    class OldClassmate : Contact
    {
        public OldClassmate(string name, string email, string phoneNumber)
            : base(name, email, phoneNumber)
        {

        }

        public override void sendMessage(string message)
        {
            Console.WriteLine("Sending email to: " + this.Name + " : " + message);
        }
    }
}
