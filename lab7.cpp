#include <iostream>
#include <fstream>

using namespace std;

void wczytaj_z_pliku(int *&tablica, int &rozmiar) {
    plik.open()
    plik >> rozmiar;
    tablica = new int[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        plik >> tablica[i];
    }

    plik.close();
}

void zwolnij_pamiec(int *&tablica) {
{
        delete[] tablica;

}
}

int main() {
    int *tablica;
    int rozmiar = 0;

    wczytaj_z_pliku(tablica, rozmiar, "dane.txt");


    for (int i = 0; i < rozmiar; i++) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    zwolnij_pamiec(tablica);

    return 0;
}
