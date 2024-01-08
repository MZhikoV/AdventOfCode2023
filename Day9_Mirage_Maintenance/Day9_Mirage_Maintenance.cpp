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

    vector<int>::iterator it1, it2;

    int sum = 0;

    while (getline(cin, input)) {
        if (input.empty()) {
            break;
        }

        stringstream inpSt(input);

        int num;
        while (inpSt >> num) {
            currV.push_back(num);
        }
        ///
        

        while (true) {

            bool isnum = false;

            for (it1 = currV.begin(); it1 != (currV.end() - 1); it1++) {
                //int temp = *it1 - *(it1 + 1);
                int temp = *(it1 + 1)-*it1;
                //newV.push_back(abs(temp));
                newV.push_back(temp);
                if (temp != 0) {
                    isnum = true;
                }

            }

            

            it1 = currV.begin();
            endingsV.push_back(*it1);

            currV.clear();
            currV = newV;
            newV.clear();

            if (!isnum) {
                break;
            }
            
        }
        currV.clear();

        placeholdersV.push_back(0);
        int placeIdx = 0;

        for (it1 = (endingsV.end() - 1);; it1--) {
            placeholdersV.push_back(*it1-placeholdersV[placeIdx]);
            placeIdx++;
            if (it1 == endingsV.begin()) {
                break;
            }
        }

        it2 = (placeholdersV.end() - 1);

        sum += *it2;

        /*cout << "it2 = " << *it2 << endl << endl;

        cout << "placeholders" << endl;
        for (int n : placeholdersV) {
            cout << n << endl;
        }

        cout << endl;*/



        endingsV.clear();
        placeholdersV.clear();


    }

    cout << sum << endl;
    return 0;
}



//Day 09 - Part one

/*

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

    vector<int>::iterator it1, it2;

    int sum = 0;

    while (getline(cin, input)) {
        if (input.empty()) {
            break;
        }

        stringstream inpSt(input);

        int num;
        while (inpSt >> num) {
            currV.push_back(num);
        }
        ///


        while (true) {

            bool isnum = false;

            for (it1 = currV.begin(); it1 != (currV.end() - 1); it1++) {
                //int temp = *it1 - *(it1 + 1);
                int temp = *(it1 + 1)-*it1;
                //newV.push_back(abs(temp));
                newV.push_back(temp);
                if (temp != 0) {
                    isnum = true;
                }

            }



            it1 = (currV.end() - 1);
            endingsV.push_back(*it1);

            currV.clear();
            currV = newV;
            newV.clear();

            if (!isnum) {
                break;
            }

        }
        currV.clear();

        placeholdersV.push_back(0);
        int placeIdx = 0;

        for (it1 = (endingsV.end() - 1);; it1--) {
            placeholdersV.push_back(placeholdersV[placeIdx] + *it1);
            placeIdx++;
            if (it1 == endingsV.begin()) {
                break;
            }
        }

        it2 = (placeholdersV.end() - 1);

        sum += *it2;

endingsV.clear();
placeholdersV.clear();


    }

    cout << sum << endl;
    return 0;
}


*/