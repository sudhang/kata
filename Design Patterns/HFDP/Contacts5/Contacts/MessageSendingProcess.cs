using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Contacts
{
    interface MessageSendingProcess
    {
        void sendMessage(string name, string message);
    }
}
