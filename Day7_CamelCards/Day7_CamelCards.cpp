// Day7_CamelCards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

void sortHands(vector<string>& hands, vector<string>& score);

int valueCard(char c);

void combineHands(vector<string>& inp, vector<string>& outp);

void combineValues(vector<string>& inp, vector<int>& outp);

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
        string cardsT = cards; //temporary string to determine the card hand type

        bool noj = false, onej = false, twoj = false, threej = false, fourj = false, fivej = false;

        int jj = 0; //counter for 'J' cards

        for (int i = 0; i < 5; i++) {
                if (cardsT[i] == 'J') {
                    jj++;
                    cardsT[i] = '0';
                }
        }

        switch (jj)
        {
        case 0: noj = true; break;
        case 1: onej = true; break;
        case 2: twoj = true; break;
        case 3: threej = true; break;
        case 4: fourj = true; break;
        case 5: fivej = true; break;
        default:
            break;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 5; j++) {
                if ((cardsT[i] == cardsT[j]) && cardsT[i]!='0') {
                    temp[i] += 1;
                    cardsT[j] = '0';
                }
            }
        }

        bool quadriple = false, triple = false, doubleP = false, singleP = false, nomatch = true, exitLoop = false;

        for (int i = 0; i < 5; i++) {
            //cout << temp[i] << endl;

            switch (temp[i]) {
            case 5:
                five.push_back(cards);
                fiveR.push_back(result);
                nomatch = false;
                exitLoop = true;
                break;
            case 4:
                quadriple = true;
                nomatch = false;
                exitLoop = true;
                break;
            case 3: 
                triple = true;
                nomatch = false;
                break;
            case 2: 
                if (singleP) doubleP = true;
                else singleP = true;
                nomatch = false;
                break;
            default:break;
            }
            if (exitLoop) {
                break;
            }
        }

        if (fivej) {
            five.push_back(cards);
            fiveR.push_back(result);
        }
        else if (quadriple) {
            if (onej) {
                five.push_back(cards);
                fiveR.push_back(result);
            }
            else {
                four.push_back(cards);
                fourR.push_back(result);
            }
        }
        else if (triple) {
            if (twoj) {
                five.push_back(cards);
                fiveR.push_back(result);
            }
            else if (onej) {
                four.push_back(cards);
                fourR.push_back(result);
            }
            else if (singleP) {
                fH.push_back(cards);
                fHR.push_back(result);
            }
            else {
                three.push_back(cards);
                threeR.push_back(result);
            }
        }
        else if (doubleP) {
            if (onej) {
                fH.push_back(cards);
                fHR.push_back(result);
            }
            else {
                dPr.push_back(cards);
                dPrR.push_back(result);
            }
        }
        else if (singleP) {
            if (threej) {
                five.push_back(cards);
                fiveR.push_back(result);
            }
            else if (twoj) {
                four.push_back(cards);
                fourR.push_back(result);
            }
            else if (onej) {
                three.push_back(cards);
                threeR.push_back(result);
            }
            else {
                pair.push_back(cards);
                pairR.push_back(result);
            }
        }
        else if (nomatch) {
            if (fourj) {
                five.push_back(cards);
                fiveR.push_back(result);
            }
            else if (threej) {
                four.push_back(cards);
                fourR.push_back(result);
            }
            else if (twoj) {
                three.push_back(cards);
                threeR.push_back(result);
            }
            else if (onej) {
                pair.push_back(cards);
                pairR.push_back(result);
            }
            else {
                dist.push_back(cards);
            distR.push_back(result);
            }

        }

    }

    if (!five.empty()) sortHands(five, fiveR);
    if (!four.empty()) sortHands(four, fourR);
    if (!fH.empty()) sortHands(fH, fHR);
    if (!three.empty()) sortHands(three, threeR);
    if (!dPr.empty()) sortHands(dPr, dPrR);
    if (!pair.empty()) sortHands(pair, pairR);
    if (!dist.empty()) sortHands(dist, distR);
 
    vector <string> sortedHands;
    vector <int> sortedValues;

    combineHands(five, sortedHands);
    combineValues(fiveR, sortedValues);
    combineHands(four, sortedHands);
    combineValues(fourR, sortedValues);
    combineHands(fH, sortedHands);
    combineValues(fHR, sortedValues);
    combineHands(three, sortedHands);
    combineValues(threeR, sortedValues);
    combineHands(dPr, sortedHands);
    combineValues(dPrR, sortedValues);
    combineHands(pair, sortedHands);
    combineValues(pairR, sortedValues);
    combineHands(dist, sortedHands);
    combineValues(distR, sortedValues);

    vector<int>::iterator it1;

    int res = 0;
    int factor=0;

    for (it1 = (sortedValues.end() - 1);;) {
        factor++;
        res += (factor * *it1);
        if (it1 == sortedValues.begin()) {
            break;
        }
        it1--;
    }

    cout << res << endl;

    return 0;
}

//function for sorting values in descending order "bubble sort"
void sortHands(vector<string>& hands, vector<string>& score) {
    
    vector<string>::iterator it1, it2, it3, it4;

    int k = 0;

    for (it1 = hands.begin(), it2 = score.begin(); it1 != (hands.end() - 1), it2 != (score.end() - 1); it1++, it2++) {
        for (it3 = hands.begin(), it4 = score.begin(); it3 != hands.end() - k - 1, it4 != score.end() - k - 1; it3++, it4++) {
            string firstSt = *it3;
            string secondSt = *(it3 + 1);

            string value{};
            string temp{};

            bool second = false;

            for (int i = 0; i < 5; i++) {
                int valFirst = valueCard(firstSt[i]);
                int valSecond = valueCard(secondSt[i]);

                if (valFirst > valSecond) {
                    break;
                }
                else if (valFirst < valSecond) {
                    second = true;
                    break;
                }
            }

            if (second) {
                temp = *it3;
                *it3 = *(it3 + 1);
                *(it3 + 1) = temp;

                value = *it4;
                *it4 = *(it4 + 1);
                *(it4 + 1) = value;
            }

        }
        k++;
    }
}

//function for determining the values of each card
int valueCard(char c) {
    if (isdigit(c)) {
        return c - 48;
    }
    else {
        switch (c) {
        case 'A': return 14;
        case 'K': return 13;
        case 'Q': return 12;
        case 'J': return 1;
        case 'T': return 10;
        }
    }
}

//function for creating combined vector for all the card hands
void combineHands(vector<string>& inp, vector<string>& outp) {
    for (string str : inp) {
        outp.push_back(str);
    }
}

//function for creating combined vector for all the hands values
void combineValues(vector<string>& inp, vector<int>& outp) {
    for (string str : inp) {
        int val = stoi(str);
        outp.push_back(val);
    }
}




//Part one

/*

// Day7_CamelCards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

void sortHands(vector<string>& hands, vector<string>& score);

int valueCard(char c);

void combineHands(vector<string>& inp, vector<string>& outp);

void combineValues(vector<string>& inp, vector<int>& outp);

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
        string cardsT = cards; //temporary string to determine the card hand type

        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 5; j++) {
                if ((cardsT[i] == cardsT[j]) && cardsT[i]!='0') {
                    temp[i] += 1;
                    cardsT[j] = '0';
                }
            }
        }

        bool triple = false, doubleP = false, singleP = false, nomatch = true, exitLoop=false;

        for (int i = 0; i < 5; i++) {
            //cout << temp[i] << endl;

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

    if (!five.empty()) sortHands(five, fiveR);
    if (!four.empty()) sortHands(four, fourR);
    if (!fH.empty()) sortHands(fH, fHR);
    if (!three.empty()) sortHands(three, threeR);
    if (!dPr.empty()) sortHands(dPr, dPrR);
    if (!pair.empty()) sortHands(pair, pairR);
    if (!dist.empty()) sortHands(dist, distR);


    vector <string> sortedHands;
    vector <int> sortedValues;


    combineHands(five, sortedHands);
    combineValues(fiveR, sortedValues);
    combineHands(four, sortedHands);
    combineValues(fourR, sortedValues);
    combineHands(fH, sortedHands);
    combineValues(fHR, sortedValues);
    combineHands(three, sortedHands);
    combineValues(threeR, sortedValues);
    combineHands(dPr, sortedHands);
    combineValues(dPrR, sortedValues);
    combineHands(pair, sortedHands);
    combineValues(pairR, sortedValues);
    combineHands(dist, sortedHands);
    combineValues(distR, sortedValues);

vector<int>::iterator it1;

int res = 0;
int factor = 0;

for (it1 = (sortedValues.end() - 1);;) {
    factor++;
    res += (factor * *it1);
    if (it1 == sortedValues.begin()) {
        break;
    }
    it1--;
}

cout << res << endl;

return 0;
}

//function for sorting values in descending order "bubble sort"
void sortHands(vector<string>& hands, vector<string>& score) {

    vector<string>::iterator it1, it2, it3, it4;

    int k = 0;

    for (it1 = hands.begin(), it2 = score.begin(); it1 != (hands.end() - 1), it2 != (score.end() - 1); it1++, it2++) {
        for (it3 = hands.begin(), it4 = score.begin(); it3 != hands.end() - k - 1, it4 != score.end() - k - 1; it3++, it4++) {
            string firstSt = *it3;
            string secondSt = *(it3 + 1);

            string value{};
            string temp{};

            bool second = false;

            for (int i = 0; i < 5; i++) {
                int valFirst = valueCard(firstSt[i]);
                int valSecond = valueCard(secondSt[i]);

                if (valFirst > valSecond) {
                    break;
                }
                else if (valFirst < valSecond) {
                    second = true;
                    break;
                }
            }

            if (second) {
                temp = *it3;
                *it3 = *(it3 + 1);
                *(it3 + 1) = temp;

                value = *it4;
                *it4 = *(it4 + 1);
                *(it4 + 1) = value;
            }

        }
        k++;
    }
}

//function for determining the values of each card
int valueCard(char c) {
    if (isdigit(c)) {
        return c - 48;
    }
    else {
        switch (c) {
        case 'A': return 14;
        case 'K': return 13;
        case 'Q': return 12;
        case 'J': return 11;
        case 'T': return 10;
        }
    }
}

//function for creating combined vector for all the card hands
void combineHands(vector<string>& inp, vector<string>& outp) {
    for (string str : inp) {
        outp.push_back(str);
    }
}

//function for creating combined vector for all the hands values
void combineValues(vector<string>& inp, vector<int>& outp) {
    for (string str : inp) {
        int val = stoi(str);
        outp.push_back(val);
    }
}


*/