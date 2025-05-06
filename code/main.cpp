#include <iostream>
using namespace std;

void menu();

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
