// Day8_HauntedWasteland.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

string currentValue(char c, int index, vector<string>& L, vector<string>& R);


int main()
{
    string directions;
    getline(cin, directions);

    string input;
    getline(cin, input);

    vector<string> label;
    vector<string> left;
    vector<string>right;

    while (getline(cin, input)) {
        if (input.empty()) {
            break;
        }

        string temp;

        size_t found = input.find(" = (");
        
        temp = input.substr(0, found);

        label.push_back(temp);

        input.erase(0, found + 4);

        temp= input.substr(0, 3);

        left.push_back(temp);

        input.erase(0, 5);

        temp = input.substr(0,3);

        right.push_back(temp);

    }

    int steps = 0;

    vector<string>::iterator itStart;

    itStart = find(label.begin(), label.end(), "AAA");

    string currLabel = *itStart;

    
    while (currLabel != "ZZZ") {

        for (int i = 0; i < directions.length(); i++) {
        
            int idx = itStart - label.begin();

            currLabel = currentValue(directions[i], idx, left, right);

            steps++;

            itStart = find(label.begin(), label.end(), currLabel);

            if (currLabel == "ZZZ") {
                break;
            }
        }
    }
    
    
    
    
    /*for (int i = 0; i < directions.length(); i++) {
        if (currLabel == "ZZZ") {
            break;
        }
        
        int idx = itStart - label.begin();

        currLabel = currentValue(directions[i], idx, left, right);

        steps++;

        itStart = find(label.begin(), label.end(), currLabel);

        if (i == directions.length() - 1) {
            i = 0;
        }

    }*/

    cout << steps << endl;




    /*for (string a : label) {
        cout << a << endl;
    }

    for (string b : left) {
        cout << b << endl;
    }

    for (string c : right) {
        cout << c << endl;
    }*/




    return 0;
}

string currentValue(char c, int index, vector<string>& L, vector<string>& R) {

    int idx = 0;

    if (c == 'L') {
        return L[index];
    }
    else {
        return R[index];
    }
}