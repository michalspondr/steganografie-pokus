#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// mapa retezcu a jejich vyskytu
map <string,int> mapa;

void vypis() {
	int pocet_znaku=0;

	// setridime mapu podle nejcastejsich vyskytu retezcu
	for (map<string,int>::iterator it = mapa.begin()  ; it != mapa.end(); it++) {
		// vypisujeme jen retezce s velikosti vetsi nez 2
		if ((it->first).length() > 2 && it->second >= 2) {
			cout << it->second << " " << it->first << endl;
		}
	}
	return;
}


int main() {
	string ciphertext;
	char c;
	
	// nactu sifru ze standardniho vstupu
	c=getchar();
	while (c != EOF && c!='\n') {
		ciphertext += c;
		c=getchar();
	}

	// projedu vsechny podretezce daneho sifrovaneho textu a budu scitat podobne nazvy
	
	size_t p1=0,p2=ciphertext.length();	// pomocne ukazatele do retezce kvuli pruchodu
	
	while (p1 < p2) {
		size_t p=0;	// minimalni velikost podretezce
		while (p <= (p2-p1)) {
			mapa[ciphertext.substr(p1,p)]++;
			p++;
		}
		p1++;
	}

	vypis();

	return 0;

}

