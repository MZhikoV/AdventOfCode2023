#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

void readStoD(vector<long long int>& destV);

void printV(vector<long long int> destV);

int main()
{
    string seedsS;
    getline(cin, seedsS); //reading the input string seeds

    size_t idx = seedsS.find(':');
    seedsS.erase(0, idx + 2);

    cout << seedsS << endl;

    stringstream seedsStream(seedsS);

    vector<long long int> seeds;

    long long int num;

    while (seedsStream >> num) {
        seeds.push_back(num);
    }

    for (long long nnum : seeds) {
        cout << nnum << endl;
    }

    vector<long long int>::iterator it1;

    string input;

    bool endC = false;

    while (getline(cin, input)) {

        if (input == "seed-to-soil map:") {
            readStoD(seeds);
            printV(seeds);
        }

        if (input == "soil-to-fertilizer map:") {
            readStoD(seeds);
            printV(seeds);
        }

        if (input == "fertilizer-to-water map:") {
            readStoD(seeds);
            printV(seeds);
        }

        if (input == "water-to-light map:") {
            readStoD(seeds);
            printV(seeds);
        }

        if (input == "light-to-temperature map:") {
            readStoD(seeds);
            printV(seeds);
        }

        if (input == "temperature-to-humidity map:") {
            readStoD(seeds);
            printV(seeds);
        }

        if (input == "humidity-to-location map:") {
            readStoD(seeds);
            printV(seeds);
            endC = true;
        }

        if (endC) {
            break;
        }
    }


    long long int minNum = seeds[0];

    for (it1 = seeds.begin() + 1; it1 != seeds.end(); it1++) {
        if (minNum > *it1) {
            minNum = *it1;
        }
    }

    cout << minNum << endl;

}

void readStoD(vector<long long int>& destV) {

    vector<long long int>::iterator it1,it2;

    vector<long long int> temp= destV;

    string input;
    while (getline(cin, input)) {
        if (input.empty()) {
            break;
        }

        long long int src = 0, dest = 0, range = 0; //declaring the variables for reading input

        stringstream inpST(input);
        inpST >> dest >> src >> range;

        

        for (it1 = destV.begin(), it2 = temp.begin(); it1 != destV.end(); it1++, it2++) {
            if (*it1 >= src && *it1 <= (src + range - 1)) {
                *it1 = dest + (*it1 - src);
                *it2 = *it1;
                *it1 = -1;
            }
        }
    }

    for (it1 = destV.begin(), it2 = temp.begin(); it1 != destV.end(); it1++, it2++) {
        if (*it1 == - 1) {
            *it1 = *it2;
        }
    }

}

void printV(vector<long long int> destV) {
    for (long long nnum : destV) {
        cout << nnum << endl;
    }
    cout << endl;
}





//20231223 1700