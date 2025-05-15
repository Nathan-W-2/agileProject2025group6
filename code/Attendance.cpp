#include "Attendance.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <algorithm>
#pragma warning(disable : 4996).

Attendance::Attendance(string filepath, bool isAttendanceSheet){
    if (isAttendanceSheet) {
        readAttendanceSheet(filepath); 
    } else {
        readFile(filepath);
    }
}

Attendance::~Attendance(){
    for (Student*& student: allStudents) {
        delete student; 
    }
}

Student* Attendance::getStudentAt(int index) const
{  
    return allStudents.at(index);
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
        std::cerr << "Unable to open roster file" << std::endl;
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

void Attendance::readAttendanceSheet(string filepath) {
    vector<vector<string>> parsedInput;

    
	std::ifstream file("./data/course1/attendanceSheets/foo.txt");
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
        std::cerr << "Unable to open attendance file" << std::endl;
    }

    for (const vector<string>& element: parsedInput) {
        Student* studentPtr = new Student;
        string formattedName = element.at(0);
        //replacing underscores with spaces
        replace(formattedName.begin(), formattedName.end(), '_', ' ');
        studentPtr->name = formattedName;
        cout << formattedName << endl; 
        studentPtr->attendance = stoi(element.at(1));
        allStudents.push_back(studentPtr);
    }

    for (Student*& student: allStudents) {
        cout << student->name << endl;
        cout << student->attendance << endl; 
    }
    cout << allStudents.size();
}

void Attendance::writeFile(string courseFolderName)
{  
    string date = getDate();
    string filePath = "data/" + courseFolderName + "/attendanceSheets/" + date + ".txt";
    cout << filePath << endl; 
    ofstream outputFile(filePath);
    for (Student*& student: allStudents) {
        //replacing spaces with underscores
        string formattedName = student->name; 
        //replacing underscores with spaces
        replace(formattedName.begin(), formattedName.end(), ' ', '_');
        outputFile << formattedName << " " << student->attendance << endl; 
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
    string attendanceInput;
    cout << "Enter in attendance (0 = Present, 1 = Excused Absent, 2 = Unexcused Absent, 3 = Late): "; 
    cin >> attendanceInput; 
    int attendanceNum = stoi(attendanceInput);
    if (attendanceNum < 0 or attendanceNum > 3) {
        student->attendance = 0; 
    } else {
        student->attendance = attendanceNum;
    }
}

int Attendance::getNumStudents() {
    return allStudents.size();
}

string Attendance::getDate() {
    time_t currentTime = time(0);
    char* dt = ctime(&currentTime);
    string str(dt);
    
    //Ex: Tue May 13 13:12:23 2025
    string newString = "";

    //start after the day string ends
    int beginSpace = 3;
    int monthLen = 1;
    int spaceCounter = 0;

    for (int i = beginSpace + 1; i < str.size(); i++) {
        //go until we find the second space
        if (str[i] == ' ') {
            if (spaceCounter == 0) {
                spaceCounter++;
            }
            else {
                break;
            }
        }
        else {
            //increment the length until we reach the second space
            monthLen++;
        }
    }

    newString = str.substr(beginSpace + 1, monthLen);

    //set beginSpace the end of the new String
    beginSpace = beginSpace + monthLen + 1;
    spaceCounter = 1;
    for (int i = beginSpace + 1; i < str.size(); i++) {
        if (str[i] == ' ') {
            //when we reach the final space set begin space to where the final space is
            beginSpace += spaceCounter + 1;
            break;
        }
        //increment until we reach the final space before the year string
        spaceCounter++;
    }

    string year = str.substr(beginSpace, str.size() - 1);

    newString = newString + " " + year;

    return newString;
}
//--
void Attendance::getSummary(vector < string >& vec) {
    vector < Student* > copy;
    copy = allStudents;
    
    vector < Student* > studentRoster;
    
    for (int i = 0; i < vec.size(); i++) {
//        cout << vec[i] << endl;
        storeName(studentRoster, copy, vec[i]);
    }
    
    allStudents = studentRoster;
    
    printStudents();
    allStudents = copy;
    
//    deleteVec(copy);
//    deleteVec(studentRoster);
}

void Attendance::storeName(vector < Student* >& ros, vector < Student* >& students, string names){
    
    string stuName;
    string stuName2;
    int stuAttend;
    
    for (int i = 0; i < students.size(); i++) {
//        cout << students.at(i)->name << endl;
        
        std::istringstream ss(students.at(i)->name);
        
        ss >> stuName >> stuName2 >> stuAttend;
        
        students.at(i)->name = stuName + " " + stuName2;
        students.at(i)->attendance = stuAttend;
        
        if (students.at(i)->name == names) {
            ros.push_back(students.at(i));
            break;
        }
    }
}
