#include "Attendance.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

Attendance::Attendance(string filepath){
    readFile(filepath);
}

void Attendance::readFile(string filepath) {
    vector<vector<string>> parsedInput;

	std::ifstream file(filepath);
    if (file.is_open()) {
        std::string line;
        //get each line one at a time
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string word;
			vector<string> v;
            //each word is added to a vector
            while (ss >> word) {
                v.push_back(word);
            }
			parsedInput.push_back(v);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }

    for (const vector<string>& element: parsedInput) {
        Student* studentPtr = new Student;
        // cout << element.at(0) << element.at(1) << endl; 
        studentPtr->firstName = element.at(0);
        studentPtr->lastName = element.at(1);
        allStudents.push_back(studentPtr);
    }

    for (Student*& student: allStudents) {
        changeAttendance(student);
        cout << student->attendance << endl;
    }
}

void Attendance::changeAttendance(Student* student) {
    string attendanceNum;
    cout << student->firstName << " " << student->lastName << endl; 
    cout << "Enter in attendance (0 = Present, 1 = Excused Absent, 2 = Unexcused Absent, 3 = Late): "; 
    cin >> attendanceNum; 
    student->attendance = stoi(attendanceNum);

}