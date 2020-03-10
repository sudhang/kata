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
            this.msp = new SMSProcess();
        }
    }
}
