// Day7_CamelCards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;



#include <iostream>

int main()
{
    string input;

    //five of a kind 5
    vector<string>five;
    vector<string>fiveR;

    //four of a kind 4+1
    vector<string>four;
    vector<string>fourR;

    //full house 3+2
    vector<string>fH;
    vector<string>fHR;

    //three of a kind 3+1+1
    vector<string>three;
    vector<string>threeR;

    //double pair 2+2+1
    vector<string>dPr;
    vector<string>dPrR;

    //single pair 2+1+1+1
    vector<string>pair;
    vector<string>pairR;

    //no pairs 1+1+1+1+1
    vector<string>dist;
    vector<string>distR;





    while (getline(cin, input)) {
        if (input.empty()) {
            break;
        }

        string cards, result;
        
        stringstream inpS(input);

        inpS >> cards >> result;
        
        int temp[5] = { 1,1,1,1,1 }; //temporary array to determine the card hand type

        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (cards[i] == cards[j]) {
                    temp[i] += 1;
                }
            }
        }

        /*if (temp[0] == 5) {
            five.push_back(cards);
            fiveR.push_back(result);
            continue;
        }

        for (int i = 0; i < 5; i++) {
            if (temp[i] == 4) {
                four.push_back(cards);
                fourR.push_back(result);
            }
            else if ()
        }*/

        bool triple = false, doubleP = false, singleP = false, nomatch = true, exitLoop=false;

        for (int i = 0; i < 5; i++) {
            cout << temp[i] << endl;

            switch (temp[i]) {
            case 5:
                five.push_back(cards);
                fiveR.push_back(result);
                nomatch = false;
                exitLoop = true;
                break;
            case 4:
                four.push_back(cards);
                fourR.push_back(result);
                nomatch = false;
                exitLoop = true;
                break;
            case 3: triple = true;
                nomatch = false; 
                break;
            case 2: if (singleP) doubleP = true;
                    else singleP = true;
                nomatch = false;
                break;
            default:break;
            }
            if (exitLoop) {
                break;
            }
        }

        if (triple && singleP) {
            fH.push_back(cards);
            fHR.push_back(result);
        }
        else if (triple) {
            three.push_back(cards);
            threeR.push_back(result);
        }
        else if (doubleP) {
            dPr.push_back(cards);
            dPrR.push_back(result);
        }
        else if (singleP) {
            pair.push_back(cards);
            pairR.push_back(result);
        }
        else if (nomatch) {
            dist.push_back(cards);
            distR.push_back(result);
        }





    }

    cout << "debug" << endl;

    return 0;
}
