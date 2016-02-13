#include "s-header.h"

int Valikko() {
	int valinta;
	cout << "ETUSIVU\n\n"
		<< "1 - Kokoelma\n"
		<< "2 - Kauppa\n"
		<< "0 - Lopeta\n"
		<< "--> ";
	cin >> valinta;
	return valinta;
}