#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main()
{
	string prev, curr, next;
	getline(cin, prev);
	getline(cin, curr);

	int sum = 0;

	bool adj = false, adjC = false, adjN = false ;
	bool pp = false, cc = false, aa = false;

	bool r1 = false, r2 = false, r3 = false; //bool for each row and to determine is there are two adjasent nums
	bool br = false; //to check if the conditions have break and multiply the result directly
	int brN = 0; //number to be carried out if break occurs;


	while (getline(cin, next)) {
		if (next.empty()) {
			break;
		}



		string temp{}, rev{}, tempr{}, tempC{};
		int prevN = 1, currN = 1, nextN=1;

		for (int i = 0; i < curr.length(); i++) {

			
			if (curr[i] == '*') {

				//*************************************************************************************************************
								//for previuous row
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
					while (isdigit(prev[j])) {
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
					prevN = stoi(temp);
					cc = false;
					pp = false;
					aa = false;
				}

				else if (adj && !cc && pp && !aa) {
					prevN = stoi(temp);
					pp = false;
				}

				else if (adj && !cc && pp && aa) {
					prevN = stoi(temp);
					prevN *= stoi(tempr);
					aa = false;
					pp = false;
					br = true;
					brN = prevN;
					goto res; // break if there are two numbers on that row
				}

				else if (adj && aa && !cc && !pp) {
					prevN = stoi(tempr);
					aa = false;
				}

				else if (adj && cc && pp && !aa) {
					prevN = stoi(temp);
					cc = false;
					pp = false;
				}

				else if (adj && cc && !pp && aa) {
					temp += tempr;
					prevN = stoi(temp);
					cc = false;
					aa = false;
				}

				else if (adj && cc && !pp && !aa) {
					prevN = stoi(temp);
					cc = false;
				}
				temp.clear();
				tempr.clear();
				cc = false;
				pp = false;
				aa = false;
				adj = false;
				
				if (prevN != 1) {
					r1 = true;
				}

//*************************************************************************************************************
				//for current row
				if (i > 0 && isdigit(curr[i - 1])) {
					int j = i - 1;
					while (curr[j] != '.') {
						tempC += curr[j];
						j--;
						if (j < 0) {
							break;
						}
					}
					for (int k = tempC.length() - 1; k >= 0; k--) {
						rev += tempC[k];
					}
					tempC = rev;
					adjC = true;
					pp = true;
					rev.clear();
				}

				if (isdigit(curr[i + 1])) {
					int j = i + 1;
					while (isdigit(curr[j])) {
						tempr += curr[j];
						j++;
						if (j >= curr.length()) {
							break;
						}
					}
					adjC = true;
					aa = true;
				}

				if (adjC && pp && !aa) {
					currN = stoi(tempC);
					pp = false;
				}

				else if (adjC && pp && aa) {
					currN = stoi(tempC);
					currN *= stoi(tempr);
					aa = false;
					pp = false;
					br = true;
					brN = currN;
					goto res; // break if there are two numbers on that row
				}

				else if (adjC && aa && !pp) {
					currN = stoi(tempr);
					aa = false;
				}

				tempC.clear();
				tempr.clear();
				cc = false;
				pp = false;
				aa = false;
				adjC = false;

				if (currN != 1) {
					r2 = true;
				}

//*************************************************************************************************************
				//for next row

				if (i > 0 && isdigit(next[i - 1])) {
					int j = i - 1;
					while (next[j] != '.') {
						temp += next[j];
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

				if (isdigit(next[i])) {
					temp += next[i];
					adj = true;
					cc = true;
				}

				if (isdigit(next[i + 1])) {
					int j = i + 1;
					while (isdigit(next[j])) {
						tempr += next[j];
						j++;
						if (j >= next.length()) {
							break;
						}
					}
					adj = true;
					aa = true;
				}

				if (adj && cc && pp && aa) {
					temp += tempr;
					nextN = stoi(temp);
					cc = false;
					pp = false;
					aa = false;
				}

				else if (adj && !cc && pp && !aa) {
					nextN = stoi(temp);
					pp = false;
				}

				else if (adj && !cc && pp && aa) {
					nextN = stoi(temp);
					nextN *= stoi(tempr);
					aa = false;
					pp = false;
					br = true;
					brN = nextN;
					goto res; // break if there are two numbers on that row
				}

				else if (adj && aa && !cc && !pp) {
					nextN = stoi(tempr);
					aa = false;
				}

				else if (adj && cc && pp && !aa) {
					nextN = stoi(temp);
					cc = false;
					pp = false;
				}

				else if (adj && cc && !pp && aa) {
					temp += tempr;
					nextN = stoi(temp);
					cc = false;
					aa = false;
				}

				else if (adj && cc && !pp && !aa) {
					nextN = stoi(temp);
					cc = false;
				}
				temp.clear();
				tempr.clear();
				cc = false;
				pp = false;
				aa = false;
				adj = false;

				if (nextN != 1) {
					r3 = true;
				}

			}

//*************************************************************************************************************
	res:			

			if (br) {
				sum += brN;
			}
			else if (r1 && r2) {
				sum += (prevN * currN);
			}
			else if (r1 && r3) {
				sum += (prevN * nextN);
			}
			else if (r2 && r3) {
				sum += (currN * nextN);
			}
			
			//sum +=(prevN+currN+nextN);
			//adj = false;
			temp.clear();
			tempr.clear();
			tempC.clear();
			currN = 1;
			prevN = 1;
			nextN = 1;
			brN = 0;
			r1 = false;
			r2 = false;
			r3 = false;
			cc = false;
			pp = false;
			aa = false;
			adj = false;
			adjC = false;
			br = false;


		}
		prev = curr;
		curr = next;
	}

	cout << sum << endl;

	return 0;

}

//p1
//20231220 1150
//20231220 1830

//p2
//20231221 0630
//20231221 0830





/*
Part 1

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
					while (isdigit(prev[j]) ) {
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
					currN += stoi(tempr);
					aa = false;
					pp = false;
				}

				else if (adj && aa && !cc && !pp) {
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
//20231220 1830

*/