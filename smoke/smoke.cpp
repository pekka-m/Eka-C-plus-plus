#include "s-header.h"
int main() {
/* osoitinkokeiluja
int luku1 = 1;
int luku2 = 2;

int *pluku1 = &luku1;
int *pluku2 = &luku2;

cout << luku1 << endl;
cout << *pluku1 << "\n\n";
cout << luku2 << endl;
cout << *pluku2 << "\n\n";


*pluku1 = *pluku2;
cout << luku1 << endl;
*/
srand(time(0)); //rand vaatii tämän

int aloitusvalinta; //valikko halutaanko säilyttää edelliset rahat vai aloittaa puhtaalta pöydältä
cout << "1 - Jatka edellisestä\n"
	<< "2 - Puhdas pöytä\n"
	<< "--> ";
cin >> aloitusvalinta;
int raha;
//char jono[2];
if (aloitusvalinta == 2) {
	//kirjoitetaan rahat.dat -tiedostoon starttiraha
	raha = 50; //starttirahaa 50
	ofstream rahat;
	rahat.open("rahat.dat", ios::in);
	rahat << raha;
	rahat.close();
}
else if (aloitusvalinta == 1) {
	//haetaan rahat.dat -tiedostosta rahamäärä
	ifstream rahatluku;
	rahatluku.open("rahat.dat");
	if (rahatluku.is_open()) {
		while (!rahatluku.eof()) {
			rahatluku >> raha;
		}
	}
	rahatluku.close();
}
//laitetaan kaupan hyllylle kolme tuotetta (ajanpuutteen vuoksi eivät kerenneet edetä tiedostoon)
KAUPPA hylly[3] = {
	{ 1, "Spurdo", 10, 10 },
	{ 2, "Dolan", 12, 10 },
	{ 3, "Shibe", 14, 10 }
};
KAUPPA kokoelma[3];

KAUPPA *okokoelma;
okokoelma = &kokoelma[0]; //koska osoitin

int tuotteita = 3;
int omat = 0; //omat tuotteet (erilaiset)

bool loppu = false;
while (loppu == false) {
	int valinta = Valikko(); //tulostetaan näytölle valikko (Valikko-aliohjelma)
	switch (valinta) {
		case 0: //lopeta
		{
			cout << "\nSe om moro!\n\n";
			loppu = true; //poistutaan while-loopista
			break;
		}
		case 1: //kokoelma
		{
			cout << "\nKOKOELMA\n\n";

			cout << "ID\t\t" << "Tuote\t\t" << "Arvo/kpl\t" << "Lukumäärä\n\n";
			for (int ind = 0; ind < omat; ind++) { //tulostetaan kokoelma
				cout << kokoelma[ind].id << "\t\t" << kokoelma[ind].tuote << "\t\t" << kokoelma[ind].hinta << "\t\t" << kokoelma[ind].lkm << endl;
			}

			//haetaan rahat.dat -tiedostosta rahamäärä
			ifstream rahatluku;
			rahatluku.open("rahat.dat");
			if (rahatluku.is_open()) {
				while (!rahatluku.eof()) {
					rahatluku >> raha;
				}
			}
			rahatluku.close();

			//valikko mitä tehdään seuraavaksi
			cout << "\n\n"
				<< "1 - Myy tuote\n"
				<< "0 - Takaisin\n"
				<< "Rahaa: " << raha << "e\n"
				<< "--> ";
			cin >> valinta;
			switch (valinta) { //ostettavan tuotteen valinta
				case 0: //takaisin
				{
							break;
				}
				case 1: //myy tuote
				{
					cout << "\nMyytävän tuotteen ID: \n-->";
					cin >> valinta;
					int ok = 0;
					if (valinta > 0) {
						for (int ind = 0; ok < 1; ind++) { //valkataan syötetty id vastaamaan oikeaa taulukon kohtaa
							if (valinta == kokoelma[ind].id) {
								if (kokoelma[ind].lkm > 0) { //josko tuotteita on enemmän kuin nolla
									valinta = ind;
									cout << "-->" << kokoelma[valinta].tuote << "\n"; //tulostetaan ID:tä vastaava tuotenimi
									kokoelma[valinta].lkm--; //vähennetään kokoelmasta 1 kpl tuotetta
									int myyntitulo = kokoelma[valinta].hinta + (rand() & 6) - 2; //tuotteen arvoon lisätään randomilla luku -2 - 4
									cout << "\nTienasit " << myyntitulo << "e\n\n";
									raha = raha + myyntitulo; //lisätään myyntitulo omiin rahoihin

									//kirjoitetaan uusi rahatilanne rahat.dat -tiedostoon
									ofstream rahat;
									rahat.open("rahat.dat", ios::in);
									rahat << raha;
									rahat.close();

									ok = 1;
								}
								else { //tuotteen lukumäärä on 0
									cout << "\n\nTuote on loppu\n\n";
									ok = 1;
								}
							}
							else if (kokoelma[ind].id > 2) { //kokoelmassa ei vastaavaa tuoteID:tä
								cout << "\n\nEt omista tuotetta kyseisellä ID:llä\n\n";
								ok = 1;
							}
						}
					}
					break;
				}
			}
			break;
		}
		case 2: //kauppa
		{
			cout << "\nKAUPPA\n\n"
				<< "ID\t\t" << "Tuote\t\t" << "Hinta\t\t" << "Lukumäärä\n\n";
			for (int ind = 0; ind < tuotteita; ind++) { //tulostetaan kaupan kaikki tuotteet
				if (hylly[ind].lkm > 0)
					cout << hylly[ind].id << "\t\t" << hylly[ind].tuote << "\t\t" << hylly[ind].hinta << "\t\t" << hylly[ind].lkm << endl;
			}

			//haetaan rahat.dat -tiedostosta rahamäärä
			ifstream rahatluku;
			rahatluku.open("rahat.dat");
			if (rahatluku.is_open()) {
				while (!rahatluku.eof()) {
					rahatluku >> raha;
				}
			}
			rahatluku.close();

			//valikko mitä tehdään seuraavaksi
			cout << "\n\n"
				<< "1 - Osta tuote\n"
				<< "0 - Takaisin\n"
				<< "Rahaa: " << raha << "e\n"
				<< "--> ";
			cin >> valinta;
			switch (valinta) { //ostettavan tuotteen valinta
				case 0: //takaisin
				{
					break;
				}
				case 1: //osta tuote
				{
					cout << "\nOstettavan tuotteen ID: \n-->";
					cin >> valinta;
					valinta--; //koska taulukko alkaa nollasta
					if (valinta <= tuotteita && valinta >= 0 && raha > hylly[valinta].hinta) { //testataan onko id oikea ja riittääkö rahat
						bool uusi = true;
						for (int ind = 0; ind <= omat; ind++) {
							if (kokoelma[ind].id == hylly[valinta].id) { //testataan onko ostajalla kyseistä tuotetta ennestään
								cout << "-->" << hylly[valinta].tuote << "\n\n"; //tulostetaan ID:tä vastaava tuotenimi
								(kokoelma[ind].lkm)++; //lisätään olemassa olevan tuotteen lukumäärää
								(hylly[valinta].lkm)--; //vähennetään kaupasta yksi kappale tuotetta
								raha = raha - hylly[valinta].hinta; //rahamassi kevenee

								//kirjoitetaan uusi rahatilanne rahat.dat -tiedostoon
								ofstream rahat;
								rahat.open("rahat.dat", ios::in);
								rahat << raha;
								rahat.close();

								uusi = false;
							}
						}
						if (uusi == true) { //tuotetta ei ole kokoelmassa ennestään
							cout << "-->" << hylly[valinta].tuote << "\n\n"; //tulostetaan ID:tä vastaava tuotenimi
							okokoelma[omat] = hylly[valinta]; //lisätään kaupan tuote omaan kokoelmaan
							kokoelma[omat].lkm = 1; //korjataan lukumäärä
							omat++; //uusi tuote kokoelmaan
							(hylly[valinta].lkm)--; //vähennetään kaupasta yksi kappale tuotetta
							raha = raha - hylly[valinta].hinta; //rahamassi kevenee

							//kirjoitetaan uusi rahatilanne rahat.dat -tiedostoon
							ofstream rahat;
							rahat.open("rahat.dat", ios::in);
							rahat << raha;
							rahat.close();

						}
					}
					else {
						cout << "\n\nVirheellinen ID tai massit finito\n\n";
					}
					break;
				}
			}
			break;
		}
	}
}
}