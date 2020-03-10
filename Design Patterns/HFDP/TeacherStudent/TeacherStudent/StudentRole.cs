using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TeacherStudent
{
    class StudentRole : Role
    {
        public void perform()
        {
            Student s = new Student();
            s.study();
        }
    }
}
