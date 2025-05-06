#pragma once
#include <string>
#include <vector>

using namespace std;

class Attendance
{
    struct Student{
        string firstName;
        string lastName;
        int attendance = 0; 
    };
public:
    Attendance(string filepath);
    
    void readFile(string filepath);
    void changeAttendance(Student* student);
private:
    vector<Student*> allStudents;
};