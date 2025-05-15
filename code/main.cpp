#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include "Attendance.h"
#pragma warning(disable : 4996).
using namespace std;

void menu();
void takeAttendance();
void viewAttendance();
void printDivider();
void addClass();
void appendToFile(string filePath, string newLine);

void selectDate(string course);
void selectRoster(string c);

int main() {
    Attendance test("data/course1/allStudents.txt");
    appendToFile("data/courseNames.txt", "Test");
    menu();
    return 0;
}


void menu() {
    int selectionNum = 0;
    
    while (selectionNum != 3)
    {
        cout << "========================" << endl;
        cout << "Press the key for corresponding action, or type out 3 to quit" << endl;
        cout << "1) Take Attendance" << endl;
        cout << "2) View Attendance" << endl;
        cout << "3) Add a New Class" << endl;
        
        cout << endl;
        cout << "Enter number here: ";
        cin >> selectionNum;
        
        if(selectionNum == 1) {
            cout << endl;
            cout << "========================" << endl;
            takeAttendance();
        }  
        if (selectionNum == 2) {
            cout << endl;
            cout << "========================" << endl;
            viewAttendance();
        }
    }
}

void takeAttendance() {
    int selectionNum = 0;
    
    while (selectionNum != 5)
    {
        cout << "Choose a class" << endl;
        cout << "1) CSC 4000" << endl;
        cout << "2) CSC 3521" << endl;
        cout << "3) CSC 3521" << endl;
        
        cout << "Enter number here: ";
        cin >> selectionNum;
       
        
        if(selectionNum == 1) {
            Attendance course1("data/course1/allStudents.txt");

            course1.printStudents();
            while (selectionNum != -1) {
                cout << "Enter Student index to update attendance: (-1 to quit) ";
                cin >> selectionNum;
                cout << "Selection num is: " << selectionNum << endl;


                if (selectionNum != -1) {
                    course1.changeAttendance(course1.getStudentAt(selectionNum - 1));
                }
            }
            course1.writeFile("course1");
        }
        else if(selectionNum == 2) {
            Attendance course2("data/course2/allStudents.txt");

            course2.printStudents();
            while (selectionNum != -1) {
                cout << "Enter Student index to update attendance: (-1 to quit) ";
                cin >> selectionNum;
                cout << "Selection num is: " << selectionNum << endl;

                if (selectionNum != -1) {
                    course2.changeAttendance(course2.getStudentAt(selectionNum - 1));
                }
            }
            course2.writeFile("course2");
        }
        else if(selectionNum == 3) {
            Attendance course3("data/course3/allStudents.txt");

            course3.printStudents();
            while (selectionNum != -1) {
                cout << "Enter Student index to update attendance: (-1 to quit) ";
                cin >> selectionNum;
                
                if (selectionNum == course3.getNumStudents()) {
                    selectionNum -= 1;
                }

                if (selectionNum != -1) {
                    course3.changeAttendance(course3.getStudentAt(selectionNum - 1));
                }
            }
            course3.writeFile("course3");
        }
        
        cout << endl;
        cout << "========================" << endl;
    }
}

// View Attendance functions

void selectRoster(string c) {
    
    string numSelect;
    
    cout << c << endl;
    cout << endl;
    
    while(numSelect != "quit")
    {
        cout << "Select Roster" << endl;
        cout << "1) Alphabetical" << endl;
        cout << "2) Seat Order" << endl;
        cout << endl;
        
        cout << "Enter Number Here: " << endl;
        cin >> numSelect;
        
        if (numSelect == "1") {
            cout << "You have chosen `Alphabetical`" << endl;
        } else if (numSelect == "2") {
            cout << "You have chosen `Seat Order`" << endl;
        }
    }
    
    printDivider();
}


void viewAttendance() {
    int selectionNum = 0;

    while (selectionNum != 4) {
        cout << "========================" << endl;
        cout << "Press the key for corresponding course, or type 4 to quit" << endl;
        cout << "1) Class 1" << endl;
        cout << "2) Class 2" << endl;
        cout << "3) Class 3" << endl;
        cout << "========================" << endl;

        cout << "Enter option here: ";
        cin >> selectionNum;
        cout << endl;
        
        selectDate("course1");
    }
}

void addClass() {
    string date = "";
    cout << "Enter in course name: ";
    cin >> date;
    cout << endl;
    
}

void selectDate(string course) {
    string date = "";

    //prompt user to chose which class they would like to view
    cout << "========================" << endl;
    cout << "Which date would you like to chose? (MM/DD/YYYY)" << endl;
    cout << "Enter date here: ";
    cin >> date;
    cout << endl;
    
    string filePath = "/data/" + course + "/attendanceSheets/" + date + ".txt";
    cout << filePath << endl;
    Attendance course2(filePath);
    course2.printStudents();

    //prompt user to chose how they would like the attendance to be displayed
    cout << "========================" << endl;
}

void printDivider() {
    cout << endl;
    cout << "========================" << endl;
}

void appendToFile(string filePath, string newLine){
    vector<string> allLines; 
    ifstream file(filePath);
    if (file.is_open()) {
        string line;
        //get each line one at a time
        while (std::getline(file, line)) {
            allLines.push_back(line);
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
    }
    //add new line that will be added to the file
    allLines.push_back(newLine); 
    ofstream outputFile(filePath);
    for (auto& line: allLines) {
        outputFile << line << endl; 
    }
}

// Toledo Code

void classSummary() {
    vector < string > courseList;
    vector < string > rosterList;
    vector < string > dateList;
    
    fillVector("/Users/alejandrotoledo/Downloads/agileProject2025group6/code/data/courseNames.txt", courseList);
    
    string select;
    
    while (select != "quit") {
        cout << "Course Section" << endl;
        cout << "--------------" << endl;
        
// Make function?
        for (int i = 0; i < courseList.size(); i++)
        {
            cout << i << ") " << courseList[i] << endl;
        }
        
        int select_num = 0;
        
        while (select_num >= 0 && select_num < courseList.size())
        {
            cout << "Select Course Section: ";
            cin >> select;
            
            if (select == "quit") {
                select_num = -1;
            } else {
                select_num = stoi(select);
                string courseName = courseList[select_num];
                cout << endl;
                //-----
                
                string roster = selectFile("/Users/alejandrotoledo/Downloads/agileProject2025group6/code/data/student_rosters", rosterList, "Roster");
                string date = selectFile("/Users/alejandrotoledo/Downloads/agileProject2025group6/code/data/" + courseName + "/attendanceSheets", dateList, "Date");
                
                vector < string > rosters;
                // Fills rosters with string of students
                fillVector("/Users/alejandrotoledo/Downloads/agileProject2025group6/code/data/student_rosters/"+roster, rosters);
                
                string filePath = "/Users/alejandrotoledo/Downloads/agileProject2025group6/code/data/" + courseName + "/attendanceSheets/" + date;
                Attendance course(filePath);
                
                cout << "Class Attendance: " << date << endl;
                cout << "----------------" << endl;
                course.getSummary(rosters);
                cout << endl;
                cout << "========================" << endl;
            }
        }
        
        if (select_num == -1) {
            break;
        }
    }
    
}

void fillVector(string filePath, vector < string >& vec) {
    ifstream file(filePath);
    
    if (file.is_open()) {
        string line;
        
        while(getline(file, line)) {
            vec.push_back(line);
        }
        
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
}

void listFilesInDirectory(const string& dirPath, vector < string >& vec) {
    if (filesystem::exists(dirPath) && filesystem::is_directory(dirPath)) {
        // std::cout << "Files in " << dirPath << ":\n";
        for (const auto& entry : filesystem::directory_iterator(dirPath)) {
            if (filesystem::is_regular_file(entry.status())) {
                vec.push_back(entry.path().filename());
            }
        }
    } else {
        std::cerr << "Path is not a directory or doesn't exist: " << dirPath << '\n';
    }
}

string selectFile(string filePath, vector < string >& vec, string typeSelect) {
//    string dateFilePath = "/Users/alejandrotoledo/Downloads/agileProject2025group6/code/data/" + courseName + "/attendanceSheets";
    listFilesInDirectory(filePath, vec);
    
    cout << typeSelect << " Selection" << endl;
    cout << "----------------" << endl;
    
    for (int j = 0; j < vec.size(); j++)
    {
        cout << j << ") " << vec[j] << endl;
    }
    
    string option;
    cout << "Select " << typeSelect << ": ";
    cin >> option;
    cout << endl;
    
    return vec[stoi(option)];
}