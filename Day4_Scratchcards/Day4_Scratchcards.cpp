#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int MAXNUM = 220;

#include <iostream>

int main()
{
    string input, win, own, temp, numS;
   // getline(cin, input);

	int sum = 0;
	int card = 0;

	int ticket[MAXNUM] = {};

	fill_n(ticket, MAXNUM, 1); //fills the array with default value

	while (getline(cin, input)) {
		if (input.empty()) {
			break;
		}

		card++;		//number of current card;

		int posT = input.find(':');

		numS = input.substr(5, posT - 1); //take the number of the card;

		int cardN = stoi(numS);
		
		input.erase(0, posT + 1);	//remove the card number

		posT = input.find('|');

		win = input.substr(0, posT - 1);	//take the left part numbers
		input.erase(0, posT + 1);

		own = input+' ';	//take the right part numbers

		stringstream winS(win);
	
		win.clear();	//empty the two strings;
	
		int wincount = 0;

		while (winS >> win) {
			string srch = ' ' + win + ' ';
			int found = 0;
				found = own.find(srch);
			if (found>=0) {
				wincount++;
			}
		}

		for (int i = (cardN + 1); i <= (cardN + wincount); i++) {
			ticket[i] += (1 * ticket[cardN]);
		}

	}

	for (int i = 1; i <= card; i++) {
		sum += ticket[i];
	}

	cout << sum << endl;

	return 0;
}

//p1
//20231221 1500
//20231221 1545

//20231221 1630
//20231221 1700



//Part one

/*

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include <iostream>

int main()
{
	string input, win, own, temp;
   // getline(cin, input);

	int sum = 0;

	while (getline(cin, input)) {
		if (input.empty()) {
			break;
		}

		int posT = input.find(':');
		input.erase(0, posT + 1);	//remove the card number

		posT = input.find('|');

		win = input.substr(0, posT - 1);	//take the left part numbers
		input.erase(0, posT + 1);

		own = input+' ';	//take the right part numbers

		stringstream winS(win);


		win.clear();	//empty the two strings;

int wincount = 0;

while (winS >> win) {
	string srch = ' ' + win + ' ';
	int found = 0;
	found = own.find(srch);
	if (found >= 0) {
		wincount++;
	}
}

int points = 1;

if (wincount > 1) {
	for (int i = 1; i < wincount; i++) {
		points *= 2;
	}
}
else if (wincount == 0) {
	points = 0;
}

sum += points;
wincount = 0;
	}
	cout << sum << endl;

	return 0;
}

*/

