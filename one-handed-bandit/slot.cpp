#include <iostream>
#include <string>
#include <stdlib.h>     
#include <time.h>
#include "slot.h"
using namespace std;


//funktio varmistaa, ettei nimess‰ ole numeroita
std:: string NimiTarkistus()
{
	string name1;
	int i = 0;
	int x = 1;
	while (x == 1)
	{
		cin >> name1;
		while (name1[i])
		{
			if (isalpha(name1[i]) || name1[i] == '-')
				i++;
			else {
				cout << "Nimi voi sis‰lt‰‰ vain kirjaimia sek‰ v‰liviiva-symbolin.\nSyˆt‰ nimi uudelleen:";
				x--;
				i = 0;    //indeksin‰ k‰ytett‰v‰ muuttuja asetetaan takaisin nollaan, jotta se aloittaa stringin lukemisen taas ensimm‰isest‰ merkist‰
				break;
			}
		}
		x++;
	}
	return(name1);
}


//funktio tarkistaa ettei asetettu panos ole saldoa suurempi.
int SaldoTarkistus(int saldo, int panos)
{
	if (panos > saldo) {
		int placeholder;
		cout << "Saldosi on panosta pienempi, joten panoksesi muutetaan saldon arvoiseksi. \nNykyinen panos: " << saldo << "\nSyˆt‰ jotain jatkaaksesi.\n";
		cin >> placeholder;
		panos = saldo;

		return(panos);
	}
	return(panos);
}
//Funktiolla annetaan k‰ytt‰j‰lle mahdollisuus valita jatkaako pelaamista vaiko lopettaako.       
int PelinJatkaminen(int balance) {
	cout << "\n\nSyˆt‰ '1' pelataksesi uudelleen\nSyˆt‰ jotain muuta lopettaaksesi." << endl;
	int x = 3;
	while (x != 1 && x != 2) {
		cin >> x;
		if (x == 1) {
			cout << "\n\n\n";
			return(1);
		}
		else
		cout << "\nKiitos pelaamisesta, tervetuloa uudelleen\nLoppusaldosi: " << balance << "\n";
		exit(0);
	}
}

//Funktio tarkasta onko syˆte numeraalinen, sek‰ k‰ytt‰j‰n t‰ysi-ik‰isyyden
int Ik‰Tarkistus() {
	char age[10];
	int age1, len;
	int x = 1;
	int i = 0;
	while (x == 1) {
		cin >> age;
		len = strlen(age);
		while (isdigit(age[i])) {
			i++;
			if (i == len) {
				x++;
			}
		}
		if (x == 1)::cout << "Voit syˆtt‰‰ vai numeroita.\n";
		i = 0;
	}
	age1 = atoi(age);
	try {
		if (age1 < 18) {
			throw(age1);
		}
	}
	catch (int age1) {
		cout << "\nVeikkaus Oy taikka elinkeinonharjoittaja tai yhteisˆ,\njoka v‰litt‰‰ rahapeleihin liittyvi‰ osallistumisilmoituksia ja -maksuja \ntai luovuttaa tilan raha-automaattien k‰ytett‰v‰n‰ pit‰miseen,\n ei saa antaa alle 18-vuotiaan pelata rahapelej‰.  \n\nSuomen arpajaislaki, kolmas luku, nelj‰stoista momentti.\n\n";
		exit(0);
	}
	return(age1);
}
//Funktiossa tarkistetaan asiakkaan nimi, ik‰ ja saldo. Funktio palauttaa saldon main-funktioon.
int AsiakkaanTarkistus() {
	struct Customer {
		string name;
		int age, deposit;
	};
	int age1, deposit1;
	string name1;

	cout << "\nTervetuloa pelaamaan! T‰yt‰th‰n tietosi ennen pelaamista." << endl;
	cout << "Etunimi: ";
	name1 = NimiTarkistus();
	cout << "Ik‰: ";
	age1 = Ik‰Tarkistus();
	cout << "Talletettava summa, jonka haluat pelata: ";
	cin >> deposit1;
	struct Customer cust = { name1, age1, deposit1 };

	return(cust.deposit);
}

//funktio toimii peliautomaattina, pit‰‰ kirjaa asiakkaan saldosta, ja palauttaa lopussa saldon. 
int Pelikone(int balance, int panos) {
	cout << "Syˆt‰ '1' aloittaaksesi pelaamisen.\nSyˆt‰ jotain muuta poistuaksesi pelaamatta.\n";

	int input;
	cin >> input;
	while (input == 1) {	 	                                        //while-loopilla pysyt‰‰n peliss‰ k‰ytt‰j‰n tahdon mukaan.
		panos = SaldoTarkistus(balance, panos);
		char first, second, third;
		char symb1[] = "WWWWWAAAAAAAAAAALLLLLLLLLLLLLLLLLLLLXXXX";         //pelikoneen symbolit arvotaan stringist‰, muuttamalla symboleiden suhteita, voidaan muuttaa pelikoneen palautusprosenttia
		srand(time(0));
		first = symb1[rand() % 37];
		second = symb1[rand() % 37];
		third = symb1[rand() % 37];

		cout << "   SLOT\n ________\n" << "| " << first << " " << second << " " << third << "  |\n" << " ---------"
			<< "\n\n";
		//if-lause voittoriveille, switch m‰‰rittelem‰‰n voiton tietyille riveille. else v‰hent‰‰ panoksen saldosta.
		if (first == second && second == third) {
			cout << "\n\n";
			switch (first) {
			case 'A':
				cout << "$$$$$$$$$$$$$$\nVoitit " << 26 * panos << " euroa!\n$$$$$$$$$$$$$$\n\n";
				balance = balance + 26 * panos - panos;
				break;
			case 'L':
				cout << "$$$$$$$$$$$$$$\nVoitit " << 8 * panos << " euroa\n$$$$$$$$$$$$$$\n\n";
				balance = balance + 8 * panos - panos;
				break;
			case 'W':
				cout << "  $$$\nSuurvoitto!!\n  $$$\n";
				balance = balance + 200 * panos - panos;
				break;
			case 'X':
				cout << "    $$$\nJackpot!!\n    $$$\n";
				balance = balance + 400 * panos - panos;
			}
		}
		else {
			balance = balance - panos;
		}
		cout << "Saldosi: " << balance << endl;
		if (balance <= 0)
		{
			cout << "Pelivarasi loppuivat, kiitos pelaamisesta! " << endl;
			return(balance);
		}
		input = PelinJatkaminen(balance);
	}
	return(balance);
}

int Logo() {
	cout << "VIEKKAUS OY\n\n";
	cout << "PELAA VASTUULLISESTI\n\n\nSaat apua peliongelmiisi osoitteesta: peluuri.fi\n\n\n";

	return(0);
}


//funktio palauttaa arvon sen mukaan, onko parametrin‰ annettu muuttuja numero. 
bool NumeroTarkistus(int luku) {
	char buffer[33];
	int i = 0;
	_itoa_s(luku, buffer, 10);
	int len = strlen(buffer);
	for (int i = 0; i < len; i++) {
		if (!(isdigit(buffer[i])));
		return(false);
	}
	return(true);
}