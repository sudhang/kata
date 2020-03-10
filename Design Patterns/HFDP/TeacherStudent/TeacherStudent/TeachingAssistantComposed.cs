using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TeacherStudent
{
    class TeachingAssistantComposed
    {
        Role currentRole;

        public TeachingAssistantComposed()
        {
            currentRole = new StudentRole();
        }

        public void becomeTeacher()
        {
            currentRole = new TeacherRole();
        }
        public void becomeStudent()
        {
            currentRole = new StudentRole();
        }
        public void setRole(Role r)
        {
            currentRole = r;
        }

        public void perform()
        {
            currentRole.perform();
        }

    }
}
