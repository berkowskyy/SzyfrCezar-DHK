#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;


string zakodujCezar(string t, int s) {
    string result = "";

    for (int i = 0; i < t.length(); i++) {
        char c = t[i];

        // duze litery
        if (isupper(c)) {
            result += char(int(c + s - 65) % 26 + 65);
        }
        // male litery
        else if (islower(c)) {
            result += char(int(c + s - 97) % 26 + 97);
        }
        
        else {
            result += c;
        }
    }
    return result;
}

string odkodujCezar(string t, int s) {
    return zakodujCezar(t, 26 - (s % 26));
}

long long powerMod(long long b, long long e, long long m) {
    long long result = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            result = (result * b) % m;
        }
        b = (b * b) % m;
        e /= 2;
    }
    return result;
}

void cezarPrint() {
    string tekst;
    int przesuniecie;

    cin.ignore();

    cout << "Wprowadz tekst do zaszyfrowania: ";
    getline(cin, tekst);
    cout << "Wprowadz przesuniecie: ";
    cin >> przesuniecie;

    string encryptedText = zakodujCezar(tekst, przesuniecie);
    cout << "Zaszyfrowany tekst: " << encryptedText << endl;

    string decryptedText = odkodujCezar(encryptedText, przesuniecie);
    cout << "Odszyfrowany tekst: " << decryptedText << endl;
}


void DHKPrint() {

    long long p = 0;
    long long g = 0;
    cout << "Wprowadz liczbe pierwsza: \n";
    cin >> p;
    cout << "Wprowadz pierwiastek pierwotny: \n";
    cin >> g;
    if (p < g)
    {
        cout << "Liczba pierwsza musi byc wieksza od pierwiastka! Podaj ponownie liczbe pierwsza: \n";
        cin >> p;
    }

    srand(time(0));
    long long privateA = rand() % (p - 1) + 1; 
    long long privateB = rand() % (p - 1) + 1; 

    long long publicA = powerMod(g, privateA, p); // klucz publiczny Uzytkownika 1
    long long publicB = powerMod(g, privateB, p); // klucz publiczny Uzytkownika 2

    cout << "Klucz publiczny Uzytkownika 1: " << publicA << endl;
    cout << "Klucz publiczny Uzytkownika 2: " << publicB << endl;


    long long sA = powerMod(publicB, privateA, p); // tajny klucz Uzytkownika 1
    long long sB = powerMod(publicA, privateB, p); // tajny klucz Uzytkownika 2

    cout << "Wspolny tajny klucz Uzytkownika 1: " << sA << endl;
    cout << "Wspolny tajny klucz Uzytkownika 2: " << sB << endl;

    if (sA == sB) {
        cout << "Zgodnosc tajnych kluczy. Wszystko OK.\n";
    }
    else {
        cout << "Dziki blad. Sprawdz kod.\n" << endl;
    }

}

void Menu() {

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "         SZYFR CEZARA I DHK\n";
    cout << " Wybierz, ktore szyfrowanie chcesz uzyc\n";
    cout << "       1 - Szyfr Cezara | 2- DHK\n";
    cout << "         0 - wyjscie z programu\n";
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

    int wybor;
    cin >> wybor;

    do {

        switch (wybor) {
        case 1:
            cezarPrint();
            return;
            break;
        case 2:
            DHKPrint();
            return;
            break;
        case 0:
            return;
            break;
        default:
            cout << "Wybrales zla opcje, sprobuj ponownie\n";
        }
        

    } while (wybor != 0);

}


int main() {
 
    Menu();
    return 0;
}
