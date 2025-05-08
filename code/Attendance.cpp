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
        Student student; 
        student.firstName = element.at(0);
        student.lastName = element.at(1);
        allStudents.push_back(student);
    }

    for (auto& student: allStudents) {
        cout << student.firstName << endl; 
        cout << student.lastName << endl; 
    }
}
