#pragma once
#include <string>
#include <vector>

using namespace std;

struct Student{
    string name;
    int attendance = 0; 
};

class Attendance
{
    public:
    Attendance(string filepath);
    ~Attendance();

    Student* getStudentAt(int index) const; 
    
    void printStudents(); 
    void readFile(string filepath);
    void writeFile();
    void changeAttendance(Student* student);
private:
    vector<Student*> allStudents;
};