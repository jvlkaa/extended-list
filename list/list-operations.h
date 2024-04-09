#pragma once
#define SIZE 10
#define DL_KOMENDY 4
#define NR_ITERATORA 0

struct lista {
    unsigned long long int liczba;
    lista* nastepny;
    lista* poprzedni;
};

//dodaje do listy przed pozycja x, liczbe y
void dodaj_przed(lista** glowa, lista** ogon, lista* iterator[10], char* x, unsigned long long int y);
void dodaj_przed_i(lista** glowa, lista** ogon, lista** iterator, unsigned long long int y);

// dodaje do listy za pozycja x, liczbe y
void dodaj_po(lista** glowa, lista** ogon, lista* iterator[10], char* x, unsigned long long int y);
void dodaj_po_i(lista** glowa, lista** ogon, lista** iterator, unsigned long long int y);

//usuwa element x z listy - usuwa glowe (usun_BEG) gdy x=BEG, usuwa ogon (usun_END) gdy x=END
void usun(lista** glowa, lista** ogon, lista* iterator[10], char* x);
void usun_BEG(lista** glowa, lista** ogon, lista* iterator[10]);
void usun_END(lista** glowa, lista** ogon, lista* iterator[10]);

//wyswietla wszystkie elementy listy komenda [ALL], lub jeden podajac iterator
void wyswietl(lista* glowa, lista* iterator[10], char* p);

//ustawia iterator a na poczatek listy (b=BEG) / koniec listy (b=END) / lub na miejsce w liscie na ktore wskazuje iterator b=0-9
void ustaw_iterator(lista** glowa, lista** ogon, lista** iterator, char* b);
void ustaw_iterator_i(lista** iterator1, lista** iterator2);

// przesuwa iterator na nastepny element listy
void przesun_przod(lista** iterator);

//przesuwa iterator na poprzedni element listy
void przesun_tyl(lista** iterator);

//czyszczenie pamieci
void wyczysc(lista** glowa, lista** ogon, lista* iterator[10]);