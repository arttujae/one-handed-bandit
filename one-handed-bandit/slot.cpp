#include <iostream>
#include <string>
#include <stdlib.h>     
#include <time.h>
#include "slot.h"
using namespace std;


//funktio varmistaa, ettei nimess� ole numeroita
 string NimiTarkistus()
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
				cout << "Nimi voi sis�lt�� vain kirjaimia sek� v�liviiva-symbolin.\nSy�t� nimi uudelleen:";
				x--;
				i = 0;    //indeksin� k�ytett�v� muuttuja asetetaan takaisin nollaan, jotta se aloittaa stringin lukemisen taas ensimm�isest� merkist�
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
		cout << "Saldosi on panosta pienempi, joten panoksesi muutetaan saldon arvoiseksi. \nNykyinen panos: " << saldo << "\nSy�t� jotain jatkaaksesi.\n";
		cin >> placeholder;
		panos = saldo;

		return(panos);
	}
	return(panos);
}
//Funktiolla annetaan k�ytt�j�lle mahdollisuus valita jatkaako pelaamista vaiko lopettaako.       
int PelinJatkaminen(int balance) {
	cout << "\n\nSy�t� '1' pelataksesi uudelleen\nSy�t� jotain muuta lopettaaksesi." << endl;
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

//Funktio tarkastaa onko sy�te numeraalinen, sek� varmistaa k�ytt�j�n t�ysi-ik�isyyden
int Ik�Tarkistus() {
	char age_as_char[10];
	int age_int, len;
	int x = 1;
	int i = 0;
	while (x == 1) {
		cin >> age_as_char;
		age_int = atoi(age_as_char);
		len = strlen(age_as_char);
		while (isdigit(age_as_char[i])) {
			i++;
			if (i == len) {
				x++;
			}}
		if (x == 1)::cout << "Voit sy�tt�� vain numeroita.\nSy�t� ik� uudelleen: ";
		i = 0;			
	}

	try {
		if (age_int < 18) {
			throw(age_int);
		}
	}
	catch (int age1) {
		cout << "\nVeikkaus Oy taikka elinkeinonharjoittaja tai yhteis�,\njoka v�litt�� rahapeleihin liittyvi� osallistumisilmoituksia ja -maksuja \ntai luovuttaa tilan raha-automaattien k�ytett�v�n� pit�miseen,\n ei saa antaa alle 18-vuotiaan pelata rahapelej�.  \n\nSuomen arpajaislaki, kolmas luku, nelj�stoista momentti.\n\n";
		exit(0);
	}
	return(age_int);
}
//Funktiossa tarkistetaan asiakkaan nimi, ik� ja saldo. Funktio palauttaa saldon main-funktioon.
int AsiakkaanTarkistus() {
	struct Customer {
		string name;
		int age, deposit;
	};
	int age1, deposit1;
	string name1;

	cout << "\nTervetuloa pelaamaan! T�yt�th�n tietosi ennen pelaamista." << endl;
	cout << "Etunimi: ";
	name1 = NimiTarkistus();
	cout << "Ik�: ";
	age1 = Ik�Tarkistus();
	cout << "Talletettava summa, jonka haluat pelata: ";
	cin >> deposit1;
	struct Customer user = { name1, age1, deposit1 };

	return(user.deposit);
}

//funktio toimii peliautomaattina, pit�� kirjaa asiakkaan saldosta, ja palauttaa lopussa saldon. 
int Pelikone(int balance, int panos) {
	cout << "Sy�t� '1' aloittaaksesi pelaamisen.\nSy�t� jotain muuta poistuaksesi pelaamatta.\n";

	int input;
	cin >> input;
	while (input == 1) {	 	                                        //while-loopilla pysyt��n peliss� k�ytt�j�n tahdon mukaan.
		panos = SaldoTarkistus(balance, panos);
		char first, second, third;
		char symb1[] = "WWWWWAAAAAAAAAAALLLLLLLLLLLLLLLLLLLLXXXX????";         //pelikoneen symbolit arvotaan stringist�, muuttamalla symboleiden suhteita, voidaan muuttaa pelikoneen palautusprosenttia
		srand(time(0));
		first = symb1[rand() % 41];
		second = symb1[rand() % 41];
		third = symb1[rand() % 41];

		cout << "   SLOT\n ________\n" << "| " << first << " " << second << " " << third << "  |\n" << " ---------"
			<< "\n\n";
		//if-lause voittoriveille, switch m��rittelem��n voiton tietyille riveille. else v�hent�� panoksen saldosta.
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
				balance = balance + 150 * panos - panos;
				break;
			case 'X':
				cout << "    $$$\nJackpot!!\n    $$$\n";
				balance = balance + 300 * panos - panos;
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
