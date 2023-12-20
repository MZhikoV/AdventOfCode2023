#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main()
{
	string input;
	int sum = 0, sumPower=0;
	bool isok = false;
	bool addsum = true;

	while (getline(cin, input)) {
		if (input.empty()) {
			break;
		}

		isok = false;
		addsum = true;

		size_t dotsP = input.find(':');
		string game = input.substr(0, dotsP);
		input.erase(0, (dotsP + 2));

		stringstream gameST(game);

		int gameIdx = 0;
		int maxR = 0, maxG = 0, maxB = 0, power = 0;
		while (gameST >> game) {
			if (game != "Game") {
				gameIdx = stoi(game);
			}
		}



		bool stopL = false;

		while (true) {

			string nums;
			size_t semicP = input.find(';');

			if (semicP != string::npos) {
				nums = input.substr(0, semicP);
				input.erase(0, (semicP + 2));
			}
			else {
				nums = input;
				stopL = true;
			}

			stringstream inp(nums);
			string words;
			int num = 0;
			int sumR = 0, sumG = 0, sumB = 0;
			
			while (inp >> words) {
				if (isdigit(words[0])) {
					num = stoi(words);
				}
				else {
					switch (words[0]) {
					case 'r': sumR += num; break;
					case 'g': sumG += num; break;
					case 'b': sumB += num; break;
					default: break;
					}
				}
			}

			 if (maxR<sumR) {
			 maxR=sumR;
			 }
			 if (maxG<sumG) {
			 maxG=sumG;
			 }
			 if (maxB<sumB) {
			 maxB=sumB;
			 }
			 

			if (sumR <= 12 && sumG <= 13 && sumB <= 14 && addsum) {
				isok = true;
			}
			else {
				addsum = false;
			}

			if (stopL) {
				break;
			}
		}

		if (isok) {
			sum += gameIdx;
		}

		power = maxR * maxG * maxB;
		sumPower += power;
	
	}

	cout << sum << endl;
	cout << sumPower << endl;

	return 0;
}

//20231220 0600
//20231220 0733