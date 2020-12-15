#include <iostream>
#include "slot.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	cout << "PELAA VASTUULLISESTI\n\n\nSaat apua peliongelmiisi osoitteesta: peluuri.fi\n\n\n";

	int balance, panos, loppusaldo;
	balance = AsiakkaanTarkistus();
	cout << "Aseta panos: ";
	cin >> panos;
	loppusaldo = Pelikone(balance, panos);
	return (0);
}
