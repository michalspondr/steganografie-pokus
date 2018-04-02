#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <map>

using namespace std;

// substitucni tabulka
map<char,char> table;

void parsesubs(string str) {
	if (str.length() != 3) throw domain_error("Spatna zadana substituce; povoleny jsou 3 znaky");
	if (str.find("=") == string::npos) {
		throw domain_error("Spatne zadana substituce; zadejte ve formatu X=Y");
	}

	if (table.count(str[0]) > 0 && table[str[0]] != str[2]) {
		throw domain_error("Pokus o vicenasobnou substituci pro 1 znak");
	}


	table[str[0]] = str[2];	// vytvorime substituci 1. znaku za 2. znak
}

char substitute(char c) {
	if (table.count(c) > 0) return table[c];
	else return c;
}

int main(char argc, char* argv[]) {
	for (int i=0; i<argc; ++i) {
		if (i==0) continue;
		else {
			parsesubs(string(argv[i]));
		}
	}

	// nyni nacteme stdin a budeme jen prepisovat na stdout podle substituce
	char c=getchar();
	while (c != EOF && c!='\n') {
		cout << substitute(c);
		c=getchar();
	}
	cout << endl;
}
