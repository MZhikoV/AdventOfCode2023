#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isNum(string inp, string number, int position) {
    if (number.length() <= (inp.length() - position)) {
        string check = inp.substr(position, number.length());
        if (check == number) {
            return true;
        }
    }
    return false;
}

int main()
{
    string input;

    bool fNum=false, currNum = false;
    int first=0, last=0;

    int sum = 0;

    while (getline(cin, input)) {
        if (input.empty()) {
            break;
        }
        
       for (int i = 0; i < input.length(); i++) {

            if (isdigit(input[i])) {
                if (!fNum) {
                    first =(int) input[i]-48;
                    fNum = true;
                }
                else {
                    last= (int) input[i]-48;
                    currNum = true;
                }
            }

            else if (isalpha(input[i])) {

                string check{};

                switch (input[i]) {
                case 'o': 
                    if (isNum(input, "one", i)) {
                        if (!fNum) {
                            first = 1;
                            fNum = true;
                        }
                        else {
                            last = 1;
                            currNum = true;
                        }
                        i += 2;
                    }
                    break;

                case 't':
                    if (isNum(input, "two", i)) {
                        if (!fNum) {
                            first = 2;
                            fNum = true;
                        }
                        else {
                            last = 2;
                            currNum = true;
                        }
                        i += 2;
                    }
                    else if (isNum(input, "three", i)) {
                        if (!fNum) {
                            first = 3;
                            fNum = true;
                        }
                        else {
                            last = 3;
                            currNum = true;
                        }
                        i += 4;
                    }
                    break;

                case 'f':
                    if (isNum(input, "four", i)) {
                        if (!fNum) {
                            first = 4;
                            fNum = true;
                        }
                        else {
                            last = 4;
                            currNum = true;
                        }
                        i += 3;
                    }
                    else if (isNum(input, "five", i)) {
                        if (!fNum) {
                            first = 5;
                            fNum = true;
                        }
                        else {
                            last = 5;
                            currNum = true;
                        }
                        i += 3;
                    }
                    break;

                case 's':
                    if (isNum(input, "six", i)) {
                        if (!fNum) {
                            first = 6;
                            fNum = true;
                        }
                        else {
                            last = 6;
                            currNum = true;
                        }
                        i += 2;
                    }
                    else if (isNum(input, "seven", i)) {
                        if (!fNum) {
                            first = 7;
                            fNum = true;
                        }
                        else {
                            last = 7;
                            currNum = true;
                        }
                        i += 4;
                    }
                    break;

                case 'e':
                    if (isNum(input, "eight", i)) {
                        if (!fNum) {
                            first = 8;
                            fNum = true;
                        }
                        else {
                            last = 8;
                            currNum = true;
                        }
                        i += 4;
                    }
                    break;

                case 'n':
                    if (isNum(input, "nine", i)) {
                        if (!fNum) {
                            first = 9;
                            fNum = true;
                        }
                        else {
                            last = 9;
                            currNum = true;
                        }
                        i += 3;
                    }
                    break;

                default: break;

                }

            }

        }
        int curr=0;

        if (currNum) {
            curr = (first)*10 + (last);
        }
        else {
            curr = (first)*10 + (first);
        }

        sum += curr;
       // cout << curr << endl;
        first = 0, last = 0;
        fNum = false;
        currNum = false;

    }
    cout << sum << endl;

    return 0;
}


//20231219/1650
//20231219/1900






//for (int i = 0; i < input.length(); i++) {
//    if (isdigit(input[i])) {
//        if (!fNum) {
//            first = (int)input[i];
//            fNum = true;
//        }
//        else {
//            last = (int)input[i];
//            currNum = true;
//        }
//    }
//}
//int curr = 0;
//
//if (currNum) {
//    curr = (first - 48) * 10 + (last - 48);
//}
//else {
//    curr = (first - 48) * 10 + (first - 48);
//}
//
//sum += curr;
//cout << curr << endl;
//first = 0, last = 0;
//fNum = false;
//currNum = false;