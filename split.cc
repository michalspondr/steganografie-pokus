#include <iostream>
#include <string>
#include <map>
using namespace std;
static const int KLENGTH=7;	// predpokladana delka klice


double coincidence_index(string& s) {
	map<char,int> letters;
	int letterscount=0;
	for (string::iterator it = s.begin(); it != s.end(); ++it) {
		letters[*it]++;
		letterscount++;
	}

	double Ic=0;	// index koincidence
	for (int i=0; i<26; ++i) {
		char c='A'+i;	// = A-Z
		double freq = (double)letters.count(c);
		freq *= (freq-1);
		Ic += freq;
	}
	size_t n = s.length();
	Ic /= (double)(n*(n-1));

	return Ic;
}

void shift(string& str) {
	for (size_t i=0; i < str.length(); ++i) {
		if (str[i] == 'Z') str[i]='A';
		else str[i] = str[i]+1;
	}
}

void frequency_analysis(string& str) {
	map<char,int> letters;
	int letterscount=0;
	for (string::iterator it = str.begin(); it != str.end(); ++it) {
		letters[*it]++;
		letterscount++;
	}

	// vypis frekvenci vsech znaku v retezci
	for (map<char,int>::iterator it = letters.begin(); it != letters.end(); ++it) {
		cout << (it->second/(double)letterscount)*100 << " " << it->first << endl;
	}
	
	
	// nyni hledame index koincidence, ktery by mel byt 0.065
	double M=0;
	int shft=0;
	while (shft < 26) {
		for (map<char,int>::iterator it = letters.begin(); it != letters.end(); ++it) {
	//		cout << it->second << " " << it->first << " = " << (it->second/(double)letterscount)*100 << "%" << endl;
			M += ((it->second/(double)letterscount)/(double)str.length());
		}
//		cout << "shift " << shft << " = " << M << endl;

		shift(str);
		shft++;
	}
}

int main() {
	int column=0;
	char c=getchar();
	string col, cipher;
	while (c != EOF && c!= '\n') {
		cout << c;
		if (column == KLENGTH-1) {
			// uchovavame kazde KLENGHTH-e pismeno (= stejny sloupec)
			col+=c;
			column=0;
			cout << endl;
		} else column++;
		cipher+=c;

		c=getchar();
	}
	cout << endl;
//	cout << coincidence_index(cipher) << endl;
	frequency_analysis(col);

}
