#include "Attendance.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>

Attendance::Attendance(string filepath){
    readFile(filepath);
}

Attendance::~Attendance(){
    for (Student*& student: allStudents) {
        delete student; 
    }
}

Student* Attendance::getStudentAt(int index) const
{
    cout << "Length of allStudents: " << allStudents.size() << endl;
    return allStudents.at(index);
}

int Attendance::getNumStudents() {
    return allStudents.size();
}

void Attendance::readFile(string filepath) {
    vector<vector<string>> parsedInput;

	std::ifstream file(filepath);
    if (file.is_open()) {
        std::string line;
        //get each line one at a time
        while (std::getline(file, line)) {
            Student* studentPtr = new Student;
            studentPtr->name = line;
            allStudents.push_back(studentPtr);
            // std::stringstream ss(line);
            // std::string word;
			// vector<string> v;
            // //each word is added to a vector
            // while (ss >> word) {
            //     v.push_back(word);
            // }
			// parsedInput.push_back(v);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }

    // for (const vector<string>& element: parsedInput) {
    //     // Student* studentPtr = new Student;
    //     // studentPtr->firstName = element.at(0);
    //     // studentPtr->lastName = element.at(1);
    //     // allStudents.push_back(studentPtr);
    // }

    // for (Student*& student: allStudents) {
    //     cout << student->name << endl;
    // }
}

void Attendance::writeFile()
{
    ofstream outputFile("foo.txt");
    for (Student*& student: allStudents) {
        outputFile << student->name << " " << student->attendance << endl; 
    }
}

void Attendance::printStudents() {
    
    for (int i = 0; i < allStudents.size(); i++) {
        cout << i+1 << ") " << allStudents.at(i)->name << " - ";
        if (allStudents.at(i)->attendance == 0) {
            cout << "Present"; 
        } 
        else if (allStudents.at(i)->attendance == 1) {
            cout << "Absent (Excused)"; 
        } 
        else if (allStudents.at(i)->attendance == 2) {
            cout << "Absent (Unexcused)";
        }
        else if (allStudents.at(i)->attendance == 3) {
            cout << "Late";
        }
        else {
            cout << "Error";
        }
        cout << endl; 
    }
}

void Attendance::changeAttendance(Student* student) {
    string attendanceNum;
    cout << "Enter in attendance (0 = Present, 1 = Excused Absent, 2 = Unexcused Absent, 3 = Late): "; 
    cin >> attendanceNum; 
    student->attendance = stoi(attendanceNum);
}