using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Contacts
{
    class Friend : Contact
    {
        public Friend(string name, string email, string phoneNumber) : base(name,email,phoneNumber)
        {

        }

        public override void sendMessage(string message)
        {
            Console.WriteLine("Sending sms to: " + this.Name + " : " + message);
        }
    }
}
