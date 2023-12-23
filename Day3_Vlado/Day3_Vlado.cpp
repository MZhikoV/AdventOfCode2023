#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool findSpecialNums(int index, string str1, string str2, string str3, bool& f, bool& back, bool& top, bool& bott, bool& tD1, bool& tD2, bool& bD1, bool& bD2, bool& t1, bool& b1);

int main()
{
    string inputOne = "empty", inputTwo = "empty", inputTree = "empty";
    int sumTotal = 0;

    while (true) {
        getline(cin, inputTree);

        for (int i = 0; i < inputTwo.size(); i++) {
            char c = inputTwo[i];

            bool frontNum = false, backNum = false, topNum = false, bottomNum = false;
            bool topD1 = false, topD2 = false, bottD1 = false, bottD2 = false;
            bool centerTop = false, centerBottom = false;

            if (c == '*') {
                if (findSpecialNums(i, inputOne, inputTwo, inputTree,
                    frontNum, backNum, topNum, bottomNum,
                    topD1, topD2, bottD1, bottD2, centerTop, centerBottom)) {
                    int num1=1, num2=1;
                    stringstream numbers;
                    //if (backNum) {
                    //    numbers << inputTwo[i + 1];
                    //    if (isdigit(inputTwo[i + 2])) {
                    //        numbers << inputTwo[i + 2];
                    //        if (isdigit(inputTwo[i + 3]))
                    //            numbers << inputTwo[i + 3];
                    //    }
                    //    numbers << " ";
                    //}
                    if (frontNum) {
                        if (isdigit(inputTwo[i - 3]) && isdigit(inputTwo[i - 2]))
                            numbers << inputTwo[i - 3] << inputTwo[i - 2];
                        else if (isdigit(inputTwo[i - 2]))
                            numbers << inputTwo[i - 2];
                        numbers << inputTwo[i - 1] << " ";
                    }
                    if (topNum) {
                        numbers << inputOne[i - 1] << inputOne[i] << inputOne[i + 1] << " ";
                    }

                    //check here
                    //if (centerTop) {
                    //    numbers << inputOne[i] << " ";
                    //}
                    if (bottomNum) {
                        numbers << inputTree[i - 1] << inputTree[i] << inputTree[i + 1] << " ";
                    }

                    //check here
                    //if (centerBottom) {
                    //    numbers << inputTree[i] << " ";
                    //}
                    if (topD1 && topD2 == false && !isdigit(inputOne[i])) {
                        if (isdigit(inputOne[i - 3]) && isdigit(inputOne[i - 2]))
                            numbers << inputOne[i - 3] << inputOne[i - 2];
                        else if (isdigit(inputOne[i - 2]))
                            numbers << inputOne[i - 2];
                        numbers << inputOne[i - 1] << " ";
                    }
                    if (topD1 && isdigit(inputOne[i])) {
                        if (isdigit(inputOne[i - 2]))
                            numbers << inputOne[i - 2];
                        numbers << inputOne[i - 1] << inputOne[i] << " ";
                    }
                    if (topD2 && topD1 == false && !isdigit(inputOne[i])) {
                        numbers << inputOne[i + 1];
                        if (isdigit(inputOne[i + 2])) {
                            numbers << inputOne[i + 2];
                            if (isdigit(inputOne[i + 3]))
                                numbers << inputOne[i + 3];
                        }
                        numbers << " ";
                    }
                    if (topD2 && isdigit(inputOne[i])) {
                        numbers << inputOne[i] << inputOne[i + 1];
                        if (isdigit(inputOne[i + 2]))
                            numbers << inputOne[i + 2];
                        numbers << " ";
                    }
                    if (bottD1 && bottD2 == false && !isdigit(inputTree[i])) {
                        if (isdigit(inputTree[i - 3]) && isdigit(inputTree[i - 2]))
                            numbers << inputTree[i - 3] << inputTree[i - 2];
                        else if (isdigit(inputTree[i - 2]))
                            numbers << inputTree[i - 2];
                        numbers << inputTree[i - 1] << " ";
                    }
                    if (bottD1 && isdigit(inputTree[i])) {
                        if (isdigit(inputTree[i - 2]))
                            numbers << inputTree[i - 2];
                        numbers << inputTree[i - 1] << inputTree[i] << " ";
                    }
                    if (bottD2 && bottD1 == false && !isdigit(inputTree[i])) {
                        numbers << inputTree[i + 1];
                        if (isdigit(inputTree[i + 2])) {
                            numbers << inputTree[i + 2];
                            if (isdigit(inputTree[i + 3]))
                                numbers << inputTree[i + 3];
                        }
                        numbers << " ";
                    }
                    if (bottD2 && isdigit(inputTree[i])) {
                        numbers << inputTree[i] << inputTree[i + 1];
                        if (isdigit(inputTree[i + 2]))
                            numbers << inputTree[i + 2];
                        numbers << " ";
                    }
                    if (topD1 && topD2) {
                        if (isdigit(inputOne[i - 3]) && isdigit(inputOne[i - 2]))
                            numbers << inputOne[i - 3] << inputOne[i - 2];
                        else if (isdigit(inputOne[i - 2]))
                            numbers << inputOne[i - 2];
                        numbers << inputOne[i - 1] << " ";

                        numbers << inputOne[i + 1];
                        if (isdigit(inputOne[i + 2])) {
                            numbers << inputOne[i + 2];
                            if (isdigit(inputOne[i + 3]))
                                numbers << inputOne[i + 3];
                        }
                        numbers << " ";
                    }
                    if (bottD1 && bottD2) {
                        if (isdigit(inputTree[i - 3]) && isdigit(inputTree[i - 2]))
                            numbers << inputTree[i - 3] << inputTree[i - 2];
                        else if (isdigit(inputTree[i - 2]))
                            numbers << inputTree[i - 2];
                        numbers << inputTree[i - 1] << " ";

                        numbers << inputTree[i + 1];
                        if (isdigit(inputTree[i + 2])) {
                            numbers << inputTree[i + 2];
                            if (isdigit(inputTree[i + 3]))
                                numbers << inputTree[i + 3];
                        }
                        numbers << " ";
                    }
                    numbers >> num1 >> num2;
                    sumTotal += num1 * num2;
                }

            }

        }
        inputOne = inputTwo;
        inputTwo = inputTree;

        if (inputTree == "end") break;
    }
    cout << endl << sumTotal << endl;
}
bool findSpecialNums(int index, string str1, string str2, string str3,
    bool& f, bool& back, bool& top, bool& bott,
    bool& tD1, bool& tD2, bool& bD1, bool& bD2, bool& t1, bool& b1) {
    int specialNum = 0;

    if (isdigit(str2[index + 1])) {
        specialNum++;
        back = true;
    }

    if (isdigit(str2[index - 1])) {
        specialNum++;
        f = true;
    }

    if (isdigit(str1[index - 1]) && isdigit(str1[index]) && isdigit(str1[index + 1])) {
        specialNum++;
        top = true;
    }
    else if (isdigit(str1[index - 1]) && isdigit(str1[index])) {
        specialNum++;
        tD1 = true;
    }
    else if (isdigit(str1[index - 1]) && !isdigit(str1[index]) && !isdigit(str1[index + 1])) {  // !
        specialNum++;
        tD1 = true;
    }
    else if (isdigit(str1[index]) && isdigit(str1[index + 1])) {
        specialNum++;
        tD2 = true;
    }
    else if (!isdigit(str1[index - 1]) && !isdigit(str1[index]) && isdigit(str1[index + 1])) {   // !
        specialNum++;
        tD2 = true;
    }
    else if (isdigit(str1[index - 1]) && isdigit(str1[index + 1])) {
        specialNum += 2;
        tD1 = true;
        tD2 = true;
    }

    if (isdigit(str3[index - 1]) && isdigit(str3[index]) && isdigit(str3[index + 1])) {
        specialNum++;
        bott = true;
    }
    else if (isdigit(str3[index - 1]) && isdigit(str3[index])) {
        specialNum++;
        bD1 = true;
    }
    else if (isdigit(str3[index - 1]) && !isdigit(str3[index]) && !isdigit(str3[index + 1])) {   // !
        specialNum++;
        bD1 = true;
    }
    else if (isdigit(str3[index]) && isdigit(str3[index + 1])) {
        specialNum++;
        bD2 = true;
    }
    else if (!isdigit(str3[index - 1]) && !isdigit(str3[index]) && isdigit(str3[index + 1])) {   // !
        specialNum++;
        bD2 = true;
    }
    else if (isdigit(str3[index - 1]) && isdigit(str3[index + 1])) {
        specialNum += 2;
        bD1 = true;
        bD2 = true;
    }

    if (specialNum == 2)
        return true;
    else
        return false;
}