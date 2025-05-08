#include <iostream>
#include "Attendance.h"
using namespace std;

int main()
{
    Attendance test("data/course1/allStudents.txt");
    test.writeFile();
    return 0;
}
