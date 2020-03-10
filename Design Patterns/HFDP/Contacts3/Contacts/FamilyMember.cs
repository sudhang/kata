using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Contacts
{
    class FamilyMember : Contact
    {
        public FamilyMember(string name, string email, string phoneNumber)
            : base(name, email, phoneNumber)
        {

        }

        public override void sendMessage(string message)
        {
            Console.WriteLine("Sending email to: " + this.Name + " : " + message);
        }
    }
}
