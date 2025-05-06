#pragma once
#include <string>
#include <vector>

using namespace std;

class Attendance
{
    struct Student{
        string firstName;
        string lastName;
    };
public:
    Attendance(string filepath);
    
    void readFile(string filepath);
private:
    vector<Student> allStudents;
};