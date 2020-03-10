using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Contacts
{
    class Colleague : Contact
    {
        EmailProcess emailProcess = new EmailProcess();

        public Colleague(string name, string email, string phoneNumber)
            : base(name, email, phoneNumber)
        {
            this.msp = new EmailProcess();
        }
    }
}
