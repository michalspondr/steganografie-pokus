#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;
static const int KLENGTH=7;	// predpokladana delka klice


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
		cout << (it->second/(double)letterscount)*100 << " % - " << it->first << endl;
	}
	
}

int main(char argc, char *argv[]) {
	int column=0, ncol=KLENGTH-1;
	string col, cipher;

	// nacteni cisla sloupce, ktery se bude zpracovavat, neni-li uveden, bere se posledni sloupec
	if (argc == 2) {
		ncol = atoi(argv[1]);
		if (ncol >= KLENGTH) exit(1);
	}

	char c=getchar();
	//overeni vstupu - pozadujeme cislo vypisovaneho sloupce
	while (c != EOF && c!= '\n') {

		if (column == ncol) {
			// uchovavame kazde ncol pismeno (= stejny sloupec)
			col+=c;
		}
		if (column == KLENGTH-1) {
			column=0;
		}
		else column++;
		cipher+=c;

		c=getchar();
	}
	frequency_analysis(col);
}
