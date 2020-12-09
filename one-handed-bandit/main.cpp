#include <iostream>
#include "slot.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	Logo();

	int balance, panos, loppusaldo;
	balance = CustomerValidation();
	cout << "Aseta panos: ";
	cin >> panos;
	loppusaldo = slot(balance, panos);

	Logo();
	return (0);
}
