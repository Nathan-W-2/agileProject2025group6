#include <iostream>
#include <string>
#include <ctime>
#include "Attendance.h"
#pragma warning(disable : 4996).
using namespace std;

void menu();
void takeAttendance();
void viewAttendance();
<<<<<<< Updated upstream
void printDivider();
=======
string parseDate(string dateString);
>>>>>>> Stashed changes

void selectDate(string course);
void selectRoster(string c);

<<<<<<< Updated upstream
int main() {
    Attendance test("data/course1/allStudents.txt");
    menu();
=======
int main()
{
   // Attendance test("data/course1/allStudents.txt");
    //test.printStudents();
    //test.writeFile();

    time_t currentTime = time(0);
    char* dt = ctime(&currentTime);
    string str(dt);

    cout << "The current date and time is: " << str << endl;
    string dateString = parseDate(str);
    cout << dateString << endl;
    //menu();
>>>>>>> Stashed changes
    return 0;
}

string parseDate(string dateString) {
    //Tue May 13 13:12:23 2025
    string newString = "";

    int beginSpace = 3;
    int monthLen = 1;
    int spaceCounter = 0;

    for(int i = beginSpace + 1; i < dateString.size(); i++) {
        //go until we find the second space
        if (dateString[i] == ' ') {
            if (spaceCounter == 0) {
                spaceCounter++;
            }
            else {
                break;
            }
        }
        else {
            monthLen++;
        }
    }

    newString = dateString.substr(beginSpace + 1, monthLen);
    
    beginSpace = beginSpace + monthLen + 1;
    spaceCounter = 1;
    for (int i = beginSpace + 1; i < dateString.size(); i++) {
        if (dateString[i] == ' ') {
            beginSpace += spaceCounter + 1;
            break;
        }
        spaceCounter++;
    }

    string year = dateString.substr(beginSpace, dateString.size() - 1);
    
    newString = newString + " " + year;
    
    return newString;
}


void menu() {
    int selectionNum = 0;
    
    while (selectionNum != 3)
    {
        cout << "========================" << endl;
        cout << "Press the key for corresponding action, or type out 3 to quit" << endl;
        cout << "1) Take Attendance" << endl;
        cout << "2) View Attendance" << endl;
        
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
