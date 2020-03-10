using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Contacts
{
    class Friend : Contact
    {
        SMSProcess smsProcess = new SMSProcess();

        public Friend(string name, string email, string phoneNumber) : base(name,email,phoneNumber)
        {
            this.msp = new SMSProcess();
        }

    }
}
