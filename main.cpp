
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <gsl/span>
#include <cppitertools/range.hpp>
#include <cppitertools/enumerate.hpp>

using namespace std;
using namespace std::literals;
using namespace iter;
using namespace gsl;

void exercice1() {
    string phrase;
    cout << "Saisissez une phrase : ";
    getline(cin, phrase);

    string motPlusCourt;
    string motPlusLong;

    // long. maximale qu'un mot peut avoir (sera utilisee pour determiner le mot le plus COURT)
    int longueurmax = phrase.length();
    // long. minimale qu'un mot peut avoir (sera utilisee pour determiner le mot le plus LONG)
    int longueurmin = 0;

    double sommeLongMots = 0;
    int nbMots = 0;

    istringstream element(phrase);
    string mot;

    while (element >> mot) {
        int longueurmot = mot.length();

        // rentre dans le if a moins que le mot soit plus LONG que le precedent
        if (longueurmot < longueurmax) {
            longueurmax = longueurmot;
            motPlusCourt = mot;
        }

        // rentre dans le if a moins que le mot soit plus COURT que le precedent
        if (longueurmot > longueurmin) {
            longueurmin = longueurmot;
            motPlusLong = mot;
        }

        sommeLongMots += longueurmot;
        nbMots++;
    }

    double moyenne = sommeLongMots / nbMots;

    cout << "Le mot le plus court est : " << motPlusCourt << endl;
    cout << "Le mot le plus long est : " << motPlusLong << endl;
    cout << "La longueur moyenne est : " << moyenne << " lettres" << endl;
}


int estUnEntier() {
    while (true) {
        try {
            string entier;
            cout << "Inserez un entier: " << endl;
            cin >> entier;

            return stoi(entier);
        }
        catch (const invalid_argument& e) {
            cerr << "Inserez un entier: ";
        }
    }
}

void exercice3() {
    int entier = estUnEntier();

    int tab[6] = { entier, 1, 3, 4, 7, 9 };

    //pour parcourir le tableau et comparer entier avec les autres deja presents
    for (auto i : range(size(tab))) {
        if (tab[i] > tab[i + 1]) {
            tab[i] = tab[i + 1];
            tab[i + 1] = tab[i];
        }
    }

    for (int i : tab) {
        cout << "{" << i << "}";
    }
}

int main()
{
    //allo
    exercice1();
    exercice3();
}
