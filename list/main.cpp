#include <iostream>
#include "list-operations.h"
using namespace std;

int main()
{
    lista* glowa = NULL;
    lista* ogon = NULL;
    lista* iterator[SIZE];
    for (int i = 0; i < SIZE; i++)
        iterator[i] = NULL;
    char polecenie, com, x1[DL_KOMENDY];
    int index;
    unsigned long long int y;
    while (cin >> polecenie)
    {
        switch (polecenie)
        {
        case 'I':
            int x;
            cin >> x;
            break;
        case '.':
            cin >> com;
            if (com == 'A') {
                cin >> x1 >> y;
                dodaj_przed(&glowa, &ogon, iterator, x1, y);
            }
            break;
        case 'A':
            cin >> com;
            if (com == '.') {
                cin >> x1 >> y;
                dodaj_po(&glowa, &ogon, iterator, x1, y);
            }
            break;
        case 'R':
            cin >> x1;
            usun(&glowa, &ogon, iterator, x1);
            break;
        case 'i':
            cin >> index >> x1;
            if (strcmp("BEG", x1) != 0 && strcmp("END", x1) != 0) {
                int l = x1[NR_ITERATORA] - '0';
                ustaw_iterator_i(&iterator[index], &iterator[l]);
            }
            else
                ustaw_iterator(&glowa, &ogon, &iterator[index], x1);
            break;
        case '+':
            cin >> index;
            przesun_przod(&iterator[index]);
            break;
        case '-':
            cin >> index;
            przesun_tyl(&iterator[index]);
            break;
        case 'P':
            cin >> x1;
            wyswietl(glowa, iterator, x1);
            break;
        default:
            break;
        }
    }
    wyczysc(&glowa, &ogon, iterator);
    return 0;
}
