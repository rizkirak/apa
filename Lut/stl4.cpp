#include <iostream>
#include <list>
#include <string>
using namespace std;

class Student
{
public:
   // ... various functions to perform the required operations

private:
   string name, ID;
   int mark;
};
int main()
{
    list<Student> students;

    // Read from data base

    while (more_students())
    {
       Student temp;
       temp.read();
       students.push_back (temp);
    }

    // Now print the students that failed (mark < 60%) - of
    // course, the particular Student object should provide a
    // member-function (say, passed()) that will determine that

   list<Student>::iterator i;
   for (i = students.begin(); i != students.end(); ++i)
   {
      if (! i->passed())    // iterators also provide operator ->
      {
         cout << "The student " << *i << " failed." << endl;
          // provided that class Student provides the overloaded
          // stream insertion operator <<
      }
   }

   // Now remove the failed students (of course, this could have
   // been done in the previous loop)

   i = students.begin()
   while (i != students.end())
   {
      if (! i->passed())
      {
         i = students.erase (i);
      }
      else
      {
         ++i;
      }
   }

   // ...

   return 0;
}
