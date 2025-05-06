#include <iostream>
#include <string>
using namespace std;

#include "Attendance.h"

void menu();
void takeAttend();
void viewAttendance();


int main()
{
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
            takeAttend();
        }
        
        
    }
}

void takeAttend() {
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
            cout << "You have chosen class 1" << endl;
        }
        else if(selectionNum == 2) {
            cout << "You have chosen class 2" << endl;
        }
        else if(selectionNum == 3) {
            cout << "You have chosen class 3" << endl;
        }
        
        cout << endl;
        cout << "========================" << endl;
    }
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

        string date = "";

        //prompt user to chose which class they would like to view
        cout << "========================" << endl;
        cout << "Which date would you like to chose? (MM/DD/YYYY)" << endl;
        cout << "Enter date here: ";
        cin >> date;
        cout << endl;

        //prompt user to chose how they would like the attendance to be displayed
        cout << "========================" << endl;
    

        //find specific class on that given date
        if (selectionNum == 1) {

        }
        else if (selectionNum == 2) {
           
        }
        else if (selectionNum == 3) {
           
        }


    }
}
