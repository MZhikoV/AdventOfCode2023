// Day8_HauntedWasteland.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

string currentValue(char c, int index, vector<string>& L, vector<string>& R);

bool checkSymb(string a, char reqSymb);

bool checkSeq(vector<string> seq, char reqSymb);

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

    vector<string> newLabel;
    vector<int> newLabelIdx;
    vector<string> newLeft;
    vector<string> newRight;

    vector<string> currLeft;
    vector<string> currRight;
    vector<int> currLabelIdx;
    vector<string> currLabel;

    vector<string>::iterator it1, it4;
    vector<int>::iterator it2, it3;

    for (it1 = label.begin(); it1 != label.end(); it1++) {
        if (checkSymb(*it1, 'A')) {
            currLabel.push_back(*it1);
            int idxV = it1 - label.begin();
            currLabelIdx.push_back(idxV);
            currLeft.push_back(left[idxV]);
            currRight.push_back(right[idxV]);


        }
    }

    bool isZ = true;

    int steps = 0;

    while (true) {

        for (int i = 0; i < directions.length(); i++) {
            
            steps++;
            
            int currIdx = 0;

            for (it2 = currLabelIdx.begin(); it2 != currLabelIdx.end(); it2++) {

                string temp = currentValue(directions[i], currIdx, currLeft, currRight);
  
                newLabel.push_back(temp);

                currIdx++;

                it4 = find(label.begin(), label.end(), temp);

                int found = (it4 - label.begin());

                newLeft.push_back(left[found]);
                newRight.push_back(right[found]);
                newLabelIdx.push_back(found);

            }

            currLabelIdx.clear();
            currLeft.clear();
            currRight.clear();
            currLabel.clear();

            currLabelIdx = newLabelIdx;
            currLeft = newLeft;
            currRight = newRight;
            currLabel = newLabel;

            newLabelIdx.clear();
            newLeft.clear();
            newRight.clear();
            newLabel.clear();

            isZ = checkSeq(currLabel, 'Z');

            if (isZ == true) {
                break;
            }

        }

        if (isZ == true) {
            break;
        }

    }

    cout << steps << endl;

    return 0;
}

string currentValue(char c, int index, vector<string>& L, vector<string>& R) {

    if (c == 'L') {
        return L[index];
    }
    else {
        return R[index];
    }
}

bool checkSymb(string a, char reqSymb) {
    if (a[2] == reqSymb) {
        return true;
    }
    else {
        return false;
    }
}

bool checkSeq(vector<string> seq, char reqSymb) {

    for (string check : seq) {
        if (check[2] != reqSymb) {
            return false;
        }
    }

    return true;
}



//Part one

/*

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

    cout << steps << endl;

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

*/