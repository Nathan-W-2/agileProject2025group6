#include <iostream>
using namespace std;

void menu();
void viewAttendance();

int main() {
    
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
        cout << "========================" << endl;
        
        cin >> selectionNum;
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
