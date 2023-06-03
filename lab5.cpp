#include <iostream>
#include <string>

using namespace std;
void wczytajDane(string& wzorzec, string& tekst) {
    cout << "Podaj wzorzec: ";
    getline(cin, wzorzec);
    cout << "Podaj tekst: ";
    getline(cin, tekst);
}
int naiwny(string tekst, string wzorzec, int dlt, int dlw){
int i=0;
while (i<= (dlt-dlw)){
    int j = 0;
    while(j<dlw && wzorzec[j]==tekst[i+j]){
        j++;
    }
    if (j==dlw){
        return i;
    }
    i++;
}
cout << "Indeks wzorca: "<< i <<endl;
}

int main() {
    string wzorzec, tekst;
    int indeks;
    wczytajDane(wzorzec, tekst);
    cout << "Wzorzec: " << wzorzec << endl;
    cout << "Tekst: " << tekst << endl;
    int m = wzorzec.length();
    int n = tekst.length();
    indeks = naiwny(tekst, wzorzec, n, m);
    cout << "indeks wzorca" << indeks<<endl;
    return 0;
}
