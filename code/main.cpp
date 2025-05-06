#include <iostream>
#include <string>
using namespace std;


void menu();
void takeAttend();

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


