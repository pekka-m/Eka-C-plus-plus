#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int Valikko();

struct KAUPPA {
	int id;
	char tuote[20];
	int hinta;
	int lkm;
};

struct KOKOELMA {
	int id;
	char tuote[20];
	int arvo;
	int lkm;
};