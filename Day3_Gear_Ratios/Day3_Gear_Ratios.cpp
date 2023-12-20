#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main()
{
	string prev, curr;
	getline(cin, prev);

	int sum = 0;

	bool adj = false;
	bool pp = false, cc = false, aa = false;


	while (getline(cin, curr)) {
		if (curr.empty()) {
			break;
		}

		string temp{}, rev{}, tempr{};
		int prevN = 0, currN = 0;

		for (int i = 0; i < curr.length(); i++) {

			if (isdigit(curr[i])) {

				int j = i;

				while (isdigit(curr[j]) && curr[j] != '.' && j < curr.length()) {
					temp += curr[j];
					j++;
				}

				for (int k = i; k < j; k++) {
					if (ispunct(prev[k]) && prev[k] != '.') {
						adj = true;
						break;
					}
				}
				if (!adj) {
					if ((i > 0 && ispunct(curr[i - 1]) && curr[i - 1] != '.') || (j - 1 < curr.length() - 1 && ispunct(curr[j]) && curr[j] != '.')
						|| (i > 0 && ispunct(prev[i - 1]) && prev[i - 1] != '.') || (j - 1 < prev.length() - 1 && ispunct(prev[j]) && prev[j] != '.')) {
						adj = true;
					}
				}
				i = j - 1;
				if (adj) {
					currN = stoi(temp);

				}
			}
			else if (curr[i] != '.') {

				if (i > 0 && isdigit(prev[i - 1])) {
					int j = i - 1;
					while (prev[j] != '.') {
						temp += prev[j];
						j--;
						if (j < 0) {
							break;
						}
					}
					for (int k = temp.length() - 1; k >= 0; k--) {
						rev += temp[k];
					}
					temp = rev;
					adj = true;
					pp = true;
					rev.clear();
				}

				if (isdigit(prev[i])) {
					temp += prev[i];
					adj = true;
					cc = true;
				}

				if (isdigit(prev[i + 1])) {
					int j = i + 1;
					while (isdigit(prev[j]) /*&& j < prev.length()*/) {
						tempr += prev[j];
						j++;
						if (j >= prev.length()) {
							break;
						}
					}
					adj = true;
					aa = true;
				}


				if (adj && cc && pp && aa) {
					temp += tempr;
					currN = stoi(temp);
					cc = false;
					pp = false;
					aa = false;
				}

				else if (adj && !cc && pp && !aa) {
					//temp += tempr;
					currN = stoi(temp);
					pp = false;
				}



				else if (adj && !cc && pp && aa) {
					currN = stoi(temp);
					currN+= stoi(tempr);
					aa = false;
					pp = false;
				}

				else if (adj && aa &&!cc &&!pp) {
					currN = stoi(tempr);
					aa = false;
				}

				else if (adj && cc && pp && !aa) {
					//temp += tempr;
					currN = stoi(temp);
					cc = false;
					pp = false;
				}

				else if (adj && cc && !pp && aa) {
					temp += tempr;
					currN = stoi(temp);
					cc = false;
					aa = false;
				}

				else if (adj && cc && !pp && !aa) {
					//temp += tempr;
					currN = stoi(temp);
					cc = false;
					//pp = false;
				}
				temp.clear();
				tempr.clear();

			}

			sum += currN;
			adj = false;
			temp.clear();
			tempr.clear();
			currN = 0;

		}
		prev = curr;
	}

	cout << sum << endl;

	return 0;

}


//20231220 1150














		//for (int i = 0; i < curr.length(); i++) {
		//	if (!isalnum(curr[i]) && curr[i] != '.') {
		//		if (isdigit(prev[i - 1])) {
		//			int j = i - 1;
		//			while (prev[j] != '.') {
		//				temp += prev[j];
		//				j--;
		//				if (j < 0) {
		//					break;
		//				}
		//			}
		//			for (int k = temp.length()-1; k >= 0; k--) {
		//				rev+= temp[k];
		//			}
		//			prevN = stoi(rev);
		//		}
		//		else if (isdigit(prev[i + 1])) {
		//			int j = i + 1;
		//			while (prev[j] != '.' && j < prev.length()) {
		//				temp += prev[j];
		//				j++;
		//			}
		//			prevN = stoi(temp);
		//			}
		//		}
		//	else if (isdigit(curr[i])) {
		//		int j = i;
		//		while (isdigit(curr[j]) && curr[j] != '.' && j < curr.length()) {
		//			temp += curr[j];
		//			j++;
		//		}

		//		if ((i>0 && ispunct(prev[i - 1]) && prev[i - 1] != '.') || (j<prev.length()-1 && ispunct(prev[j + 1]) && prev[j + 1] != '.')) {
		//			currN = stoi(temp);
		//			i = j;
		//		}
		//	}
		//}
