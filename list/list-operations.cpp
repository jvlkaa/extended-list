#include <iostream>
#include "list-operations.h"
using namespace std;

void dodaj_przed(lista** glowa, lista** ogon, lista* iterator[10], char* x, unsigned long long int y)
{
    if (*glowa == NULL)
    {
        *glowa = new lista;
        (*glowa)->nastepny = NULL;
        (*glowa)->poprzedni = NULL;
        (*glowa)->liczba = y;
    }
    else if ((*glowa)->nastepny == NULL)
    {
        lista* pomocniczy = new lista;
        pomocniczy->liczba = y;
        pomocniczy->nastepny = *glowa;
        pomocniczy->poprzedni = NULL;
        (*glowa)->poprzedni = pomocniczy;
        *ogon = *glowa;
        *glowa = pomocniczy;
    }
    else if (strcmp("BEG", x) != 0 && strcmp("END", x) != 0) {
        int pom = x[NR_ITERATORA] - '0';
        dodaj_przed_i(glowa, ogon, &iterator[pom], y);
    }
    else
    {
        if (strcmp("BEG", x) == 0)
        {
            lista* nowy = new lista;
            nowy->liczba = y;
            nowy->nastepny = *glowa;
            nowy->poprzedni = NULL;
            (*glowa)->poprzedni = nowy;
            *glowa = nowy;
        }
        else if (strcmp("END", x) == 0)
        {
            lista* nowy = new lista;
            nowy->liczba = y;
            nowy->nastepny = *ogon;
            nowy->poprzedni = (*ogon)->poprzedni;
            (*ogon)->poprzedni->nastepny = nowy;
            (*ogon)->poprzedni = nowy;
        }
    }
}

void dodaj_przed_i(lista** glowa, lista** ogon, lista** iterator, unsigned long long int y)
{
    if ((*iterator)->nastepny == NULL)
    {
        lista* nowy = new lista;
        nowy->liczba = y;
        nowy->nastepny = *ogon;
        nowy->poprzedni = (*iterator)->poprzedni;
        (*iterator)->poprzedni->nastepny = nowy;
        (*iterator)->poprzedni = nowy;
    }
    else if ((*iterator)->poprzedni == NULL)
    {
        lista* nowy = new lista;
        nowy->liczba = y;
        nowy->nastepny = *glowa;
        nowy->poprzedni = NULL;
        (*glowa)->poprzedni = nowy;
        *glowa = nowy;
    }
    else {
        lista* nowy = new lista;
        nowy->liczba = y;
        nowy->nastepny = *iterator;
        nowy->poprzedni = (*iterator)->poprzedni;
        (*iterator)->poprzedni->nastepny = nowy;
        (*iterator)->poprzedni = nowy;
    }
}

void dodaj_po(lista** glowa, lista** ogon, lista* iterator[10], char* x, unsigned long long int y)
{
    if (*glowa == NULL)
    {
        *glowa = new lista;
        (*glowa)->nastepny = NULL;
        (*glowa)->poprzedni = NULL;
        (*glowa)->liczba = y;
    }
    else if ((*glowa)->nastepny == NULL)
    {
        *ogon = new lista;
        (*ogon)->liczba = y;
        (*ogon)->nastepny = NULL;
        (*ogon)->poprzedni = *glowa;
        (*glowa)->nastepny = *ogon;
    }
    else if (strcmp("BEG", x) != 0 && strcmp("END", x) != 0) {
        int pom = x[NR_ITERATORA] - '0';
        dodaj_po_i(glowa, ogon, &iterator[pom], y);
    }
    else
    {
        if (strcmp("BEG", x) == 0)
        {
            lista* nowy = new lista;
            nowy->liczba = y;
            nowy->nastepny = (*glowa)->nastepny;
            nowy->poprzedni = *glowa;
            (*glowa)->nastepny = nowy;
            (*glowa)->nastepny->poprzedni = nowy;
        }
        else if (strcmp("END", x) == 0)
        {
            lista* nowy = new lista;
            nowy->liczba = y;
            nowy->nastepny = NULL;
            nowy->poprzedni = *ogon;
            (*ogon)->nastepny = nowy;
            *ogon = nowy;
        }
    }
}

void dodaj_po_i(lista** glowa, lista** ogon, lista** iterator, unsigned long long int y)
{
    if ((*iterator)->nastepny == NULL)
    {
        lista* nowy = new lista;
        nowy->liczba = y;
        nowy->nastepny = NULL;
        nowy->poprzedni = (*iterator);
        (*iterator)->nastepny = nowy;
        *ogon = nowy;
    }
    else if ((*iterator)->poprzedni == NULL)
    {
        lista* nowy = new lista;
        nowy->liczba = y;
        nowy->nastepny = (*glowa)->nastepny;
        nowy->poprzedni = *glowa;
        (*glowa)->nastepny = nowy;
        (*glowa)->nastepny->poprzedni = nowy;
    }
    else {
        lista* nowy = new lista;
        nowy->liczba = y;
        nowy->nastepny = (*iterator)->nastepny;
        nowy->poprzedni = *iterator;
        (*iterator)->nastepny->poprzedni = nowy;
        (*iterator)->nastepny = nowy;
    }
}

void usun(lista** glowa, lista** ogon, lista* iterator[10], char* x)
{
    if (strcmp("BEG", x) == 0)
        usun_BEG(glowa, ogon, iterator);
    else if (strcmp("END", x) == 0)
        usun_END(glowa, ogon, iterator);
    else
    {
        int pom = x[NR_ITERATORA] - '0';
        if (iterator[pom] != NULL)
        {
            if (iterator[pom]->nastepny == NULL)
                usun_END(glowa, ogon, iterator);
            else if (iterator[pom]->poprzedni == NULL)
                usun_BEG(glowa, ogon, iterator);
            else {
                lista* pomocniczy = iterator[pom]->nastepny;
                iterator[pom]->poprzedni->nastepny = iterator[pom]->nastepny;
                iterator[pom]->nastepny->poprzedni = iterator[pom]->poprzedni;
                for (int i = 0; i < SIZE; i++)
                {
                    if (iterator[i] == iterator[pom] && i != pom)
                        iterator[i] = pomocniczy;
                }
                delete iterator[pom];
                iterator[pom] = new lista;
                iterator[pom] = pomocniczy;
            }
        }
    }
}

void usun_BEG(lista** glowa, lista** ogon, lista* iterator[10])
{
    if (*glowa != NULL) {
        if ((*glowa)->nastepny == NULL) {
            for (int i = 0; i < SIZE; i++)
            {
                if (iterator[i] == *glowa)
                    iterator[i] = NULL;
            }
            delete* glowa;
            *glowa = NULL;
        }
        else if ((*glowa)->nastepny->nastepny == NULL)
        {
            (*glowa)->liczba = (*ogon)->liczba;
            for (int i = 0; i < SIZE; i++)
            {
                if (iterator[i] == *ogon)
                    iterator[i] = iterator[i]->poprzedni;
            }
            (*glowa)->poprzedni = NULL;
            (*glowa)->nastepny = NULL;
            delete* ogon;
            *ogon = NULL;
        }
        else {
            lista* pom = (*glowa)->nastepny;
            pom->poprzedni = NULL;
            for (int i = 0; i < SIZE; i++)
            {
                if (iterator[i] == *glowa)
                    iterator[i] = iterator[i]->nastepny;
            }
            delete* glowa;
            *glowa = pom;
        }
    }
}

void usun_END(lista** glowa, lista** ogon, lista* iterator[10])
{
    if (*ogon != NULL) {
        if ((*glowa)->nastepny == NULL) {
            for (int i = 0; i < SIZE; i++)
            {
                if (iterator[i] == *glowa)
                    iterator[i] = NULL;
            }
            delete* glowa;
            *glowa = NULL;
        }
        else if ((*glowa)->nastepny->nastepny == NULL)
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (iterator[i] == *ogon)
                    iterator[i] = *glowa;
            }
            (*glowa)->nastepny = NULL;
            delete* ogon;
            *ogon = NULL;
        }
        else {
            lista* pom = (*ogon)->poprzedni;
            pom->nastepny = NULL;
            for (int i = 0; i < SIZE; i++)
            {
                if (iterator[i] == *ogon)
                    iterator[i] = pom;
            }
            delete* ogon;
            *ogon = pom;
        }
    }
    else if (*ogon == NULL && (*glowa)->nastepny == NULL) {
        for (int i = 0; i < SIZE; i++)
        {
            if (iterator[i] == *glowa)
                iterator[i] = NULL;
        }
        delete* glowa;
        *glowa = NULL;
    }
}

void wyswietl(lista* glowa, lista* iterator[10], char* p)
{
    if (glowa != NULL)
    {
        if (strcmp("ALL", p) == 0)
        {
            lista* current = glowa;
            do {
                cout << current->liczba << "  ";
                current = current->nastepny;
            } while (current != NULL);
            cout << endl;
        }
        else
        {
            int pom = p[NR_ITERATORA] - '0';
            cout << iterator[pom]->liczba << endl;
        }
    }
}

void ustaw_iterator(lista** glowa, lista** ogon, lista** iterator, char* b)
{
    if (strcmp("BEG", b) == 0)
    {
        if (*glowa != NULL)
            (*iterator) = *glowa;
    }
    else if (strcmp("END", b) == 0)
    {
        if (*ogon != NULL)
            (*iterator) = *ogon;
        else if (*ogon == NULL && *glowa != NULL)
            (*iterator) = *glowa;
    }
}

void ustaw_iterator_i(lista** iterator1, lista** iterator2)
{
    if ((*iterator2) == NULL)
        (*iterator1) = NULL;
    else
        (*iterator1) = (*iterator2);
}

void przesun_przod(lista** iterator)
{
    if ((*iterator)->nastepny != NULL) {
        *iterator = (*iterator)->nastepny;
    }
}

void przesun_tyl(lista** iterator)
{
    if ((*iterator)->poprzedni != NULL)
        *iterator = (*iterator)->poprzedni;
}

void wyczysc(lista** glowa, lista** ogon, lista* iterator[10])
{
    if (*glowa != NULL)
    {
        if ((*ogon) != NULL)
        {
            while ((*ogon)->poprzedni != *glowa)
            {
                lista* current = (*ogon);
                (*ogon) = (*ogon)->poprzedni;
                delete current;
            }
        }
    }
    delete* ogon;
    delete* glowa;
    for (int i = 0; i < SIZE; i++)
        iterator[i] = NULL;
}