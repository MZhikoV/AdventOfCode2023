#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>

using namespace std;

long long int records(long long int a, long long int b); //function for determining the total count of values that are greater than the record


int main()
{
    string time;
    string dist;

    getline(cin, time);
    getline(cin, dist);

    time.erase(0, 5);
    dist.erase(0, 9);

    stringstream timeS(time);
    stringstream distS(dist);

    string ttime, ddist;
    string sNumTime, sNumDist;

    long long int prod = 0;


    while (timeS >> ttime) {
        sNumTime += ttime;
    }

    while (distS >> ddist) {
        sNumDist += ddist;
    }
    
    long long int numTime = stoll(sNumTime);
    long long int numDist = stoll(sNumDist);


    
    prod= records(numTime, numDist);


    cout << prod << endl;

    return 0;

}


long long int records(long long int a, long long int b) {
    long long int sum = 0;

    for (long long int i = 0; i <= a; i++) {
        long long int temp = (a-i)*i;
        if (temp > b) {
            sum++;
        }
    }
    return sum;
}


//20240101 1430 - 1445 p1.
//20240101 1700 - 1730 p2.


//First part
/*
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>

using namespace std;

int records(int a, int b); //function for determining the total count of values that are greater than the record


int main()
{
    string time;
    string dist;

    getline(cin, time);
    getline(cin, dist);

    time.erase(0, 5);
    dist.erase(0, 9);

    stringstream timeS(time);
    stringstream distS(dist);

    int ttime=0, ddist=0;

    int prod = 1;
    while (timeS >> ttime && distS >> ddist) {
        prod *= records(ttime, ddist);
    }

    cout << prod << endl;

    return 0;

}


int records(int a, int b) {
    int sum = 0;

    for (int i = 0; i <= a; i++) {
        int temp = (a-i)*i;
        if (temp > b) {
            sum++;
        }
    }
    return sum;
}

*/