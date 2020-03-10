using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TeacherStudent
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Inherited TA");
            TeachingAssistantInherited ta1 = new TeachingAssistantInherited();
            ta1.teach();

            //ta1.study();      // Due to the "hardcoding" caused by inheritance, we cannot make the TA "study"!

            Console.WriteLine("\n\nComposed TA");
            TeachingAssistantComposed ta2 = new TeachingAssistantComposed();
            ta2.perform();
            TeacherRole teacherRole = new TeacherRole() ;
            ta2.setRole(teacherRole);
            ta2.perform();
        }
    }
}
