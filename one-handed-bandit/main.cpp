#include <iostream>
#include "slot.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	Logo();

	int balance, panos, loppusaldo;
	balance = AsiakkaanTarkistus();
	cout << "Aseta panos: ";
	cin >> panos;
	loppusaldo = Pelikone(balance, panos);
	Logo();
	return (0);
}
