// Day9_Mirage_Maintenance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    string input;

    vector<int> currV;
    vector<int> newV;
    vector<int> endingsV;
    vector<int> placeholdersV;

    vector<int>::iterator it1;

    while (getline(cin, input)) {
        if (input.empty()) {
            break;
        }

        iostream inpSt(input);

        int num;
        while (inpSt >> num) {
            currV.push_back(num);
        }
        ///
        while (true) {

            for (it1 = currV.begin(); it1 != (currV.end() - 1); it1++) {
                newV.push_back(abs(*it1 - *(it1 + 1)));
            }
        }


    }
    return 0;
}
