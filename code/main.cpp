#include <iostream>
#include <string>
#include "Attendance.h"
using namespace std;

void menu();
void takeAttendance();
void viewAttendance();
void printDivider();

void selectDate(string course);
void selectRoster(string c);

int main() {
    Attendance test("data/course1/allStudents.txt");
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

                if (selectionNum == course1.getNumStudents()) {
                    selectionNum -= 1;
                }

                if (selectionNum != -1) {
                    course1.changeAttendance(course1.getStudentAt(selectionNum));
                }
            }
        }
        else if(selectionNum == 2) {
            Attendance course2("data/course2/allStudents.txt");

            course2.printStudents();
            while (selectionNum != -1) {
                cout << "Enter Student index to update attendance: (-1 to quit) ";
                cin >> selectionNum;
                cout << "Selection num is: " << selectionNum << endl;

                if (selectionNum == course2.getNumStudents()) {
                    selectionNum -= 1;
                }

                if (selectionNum != -1) {
                    course2.changeAttendance(course2.getStudentAt(selectionNum));
                }
            }
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
                    course3.changeAttendance(course3.getStudentAt(selectionNum));
                }
                
            }
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
