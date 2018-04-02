#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int position=0;	// pozice v klici

char substitute(char c, string k) {
	int p=c;
	int tmp=p-k[position];
	if (tmp >= 0) p = tmp%26;
	else p = 26+tmp;

	return (char)p+'A';
}

int main(char argc, char *argv[]) {
	string key;

	if (argc != 2) {
		cerr << "Zadejte jako parametr klic" << endl;
		return 1;
	}
	else {	// prevod na velka pismena
		char *c=argv[1];
		while (*c != '\0') {
			key += toupper(*c);
			c++;
		}
	}

	char c=getchar();
	while (c != EOF && c!='\n') {
		cout << substitute(toupper(c), key);
		if (position == key.length()-1) position=0; else position++;

		c=getchar();
	}

	cout << endl;
}
