using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Contacts
{
    class FamilyMember : Contact
    {
        SMSProcess smsProcess = new SMSProcess();
        public FamilyMember(string name, string email, string phoneNumber)
            : base(name, email, phoneNumber)
        {

        }

        public override void sendMessage(string message)
        {
            smsProcess.sendMessage(this.Name, message);
        }
    }
}
