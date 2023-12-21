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
	//	stringstream ownS(own);

		win.clear();	//empty the two strings;
	//	own.clear();

		/*cout << winS.str() << endl;
		cout << ownS.str() << endl;

		return 1;*/


		int wincount = 0;

		while (winS >> win) {
			string srch = ' ' + win + ' ';
			int found = 0;
				found = own.find(srch);
			if (found>=0) {
				wincount++;
			}

			/*while (ownS >> own) {
				if (win == own) {
					wincount++;
				}
			}
			ownS(input);*/
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

