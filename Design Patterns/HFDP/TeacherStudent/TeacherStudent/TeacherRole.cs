using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TeacherStudent
{
    class TeacherRole : Role
    {
        public void perform()
        {
            Teacher t = new Teacher();

            t.teach();
        }
    }
}
