#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
    string seedsS;
    getline(cin, seedsS); //reading he input string seeds

    size_t idx = seedsS.find(':');
    seedsS.erase(0, idx + 2);

    cout << seedsS << endl;

    stringstream seedsStream(seedsS);

    vector<int> seeds;

    int num;

    while (seedsStream >> num) {
        seeds.push_back(num);
    }

    for (int nnum : seeds) {
        cout << nnum << endl;
    }
}



//20231223 1700