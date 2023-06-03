#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

struct student{
    string imie;
    string nazwisko;
    int punkty;
};
void quickSort(int tablica[], int lewy,int prawy, int tryb);
void quickSortDlaStruktur(student *tablica, int lewy,int prawy, int tryb);
void wczytajStudentow(student *&tab,int *liczba_studentow);
void usunTabliceStudentow(student *&tab);
void wyswietlStudentow(student*tab,int n);
int main() {
    int liczba_studentow=0, *wsk, granica,
            *koniec,*koniec1,*koniec2, kon, kon1, kon2;
    int wybor=3;
    koniec1=&kon1;
    koniec2=&kon2;
    koniec=&kon;
    wsk=&liczba_studentow;
    student *tab2=new student[20];
    wczytajStudentow(tab2, wsk);
    wyswietlStudentow(tab2,liczba_studentow);
    quickSortDlaStruktur(tab2,0,13,1);
    wyswietlStudentow(tab2,13);
    return 0;
}
void quickSort(int tablica[], int lewy,int prawy, int tryb){//Quicksort dla liczb
    int srodek=(int)(lewy+prawy)/2;
    int piwot=tablica[srodek];
    int zamiana=tablica[prawy];
    tablica[prawy]=tablica[srodek];
    tablica[srodek]=zamiana;
    int granica = lewy;
    int i=lewy;
    while(i<prawy){
        if(tryb) {
            if(tablica[i]<piwot){
                int y =tablica[granica];
                tablica[granica]=tablica[i];
                tablica[i]=y;
                granica+=1;
            }
        }
        else{
            if(tablica[i]>piwot){
                int x=tablica[granica];
                tablica[granica]=tablica[i];
                tablica[i]=x;
                granica+=1;
            }
        }
        i+=1;
    }
    zamiana=tablica[prawy];
    tablica[prawy]=tablica[granica];
    tablica[granica]=zamiana;
    if(lewy<granica-1){
        quickSort(tablica,lewy,granica-1,tryb);
    }
    if(granica+1<prawy){
        quickSort(tablica,granica+1,prawy,tryb);
    }
}
void quickSortDlaStruktur(student *tablica, int lewy,int prawy, int tryb){
    int srodek=(int)(lewy+prawy)/2;
    int piwot=tablica[srodek].punkty;
    student robocza1 = tablica[srodek];
    tablica[srodek]=tablica[prawy];
    tablica[prawy]=robocza1;
    int granica = lewy;
    int i=lewy;
    while(i<prawy){
        if(tryb) {
            if(tablica[i].punkty<piwot){
                student robocza2=tablica[granica];
                tablica[granica]=tablica[i];
                tablica[i]=robocza2;
                granica+=1;
            }
        }
        else{
            if(tablica[i].punkty>piwot){
                student robocza2=tablica[granica];
                tablica[granica]=tablica[i];
                tablica[i]=robocza2;
                granica+=1;
            }
        }
        i+=1;
    }
    student robocza3 = tablica[prawy];
    tablica[prawy]=tablica[granica];
    tablica[granica]=robocza3;
    if(lewy<granica-1){
        quickSortDlaStruktur(tablica,lewy,granica-1,tryb);
    }
    if(granica+1<prawy){
        quickSortDlaStruktur(tablica,granica+1,prawy,tryb);
    }
}
void wczytajStudentow(student *&tab, int *liczba_studetnow){
    string sciezka,linia,pomoc;
    int liczbaStudentow;
    fstream plik;
    plik.open("studenci.csv");
    char sredniki;
    plik >> liczbaStudentow;
    for(int i = 0; i < 2; i++)
        plik >> sredniki;
    for(int i=0; i<liczbaStudentow; i++){
        plik>>linia;
        stringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].punkty=atoi(pomoc.c_str());
    }
    *liczba_studetnow=liczbaStudentow;
    plik.close();
}
void usunTabliceStudentow(student *&tab){
    delete []tab;
}
void wyswietlStudentow(student*tab,int n){
    for(int i=0;i<n;i++){
        cout<<"numer:"<<i+1<<" imie:"<<tab[i].imie<<endl;
        cout<<"nazwisko:"<<tab[i].nazwisko<<endl;
        cout<<"punkty:"<<tab[i].punkty<<endl;
        cout<<endl;
    }
}
