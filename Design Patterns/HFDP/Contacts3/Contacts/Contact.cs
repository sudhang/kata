using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Contacts
{
    class Contact
    {
        public string Name { get; set; }
        public string Email { get; set; }
        public string PhoneNumber { get; set; }

        public Contact(string name, string email, string phoneNumber)
        {
            this.Name = name;
            this.Email = email;
            this.PhoneNumber = phoneNumber;
        }

        public virtual void sendMessage(string message)
        {
        }
    }
}
