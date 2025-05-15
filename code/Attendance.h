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
    int getNumStudents();
    
    void printStudents(); 
    void readFile(string filepath);
    void writeFile(string courseFolderName);
    void changeAttendance(Student* student);
    string getDate();
    //
    void getSummary(vector < string >& vec);
    void storeName(vector < Student* >& ros, vector < Student* >& students, string names);
 
private:
    vector<Student*> allStudents;
};