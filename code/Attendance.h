#pragma once
#include <string>
#include <vector>

using namespace std;

class Attendance
{
    struct Student{
        string name;
        int attendance = 0; 
    };
public:
    Attendance(string filepath);
    ~Attendance();

    vector<Student*> getAllStudents() const; 
    
    void readFile(string filepath);
    void writeFile();
    void changeAttendance(Student* student);
private:
    vector<Student*> allStudents;
};