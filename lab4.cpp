#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct student{
string imie;
string nazwisko;
int punkty;
};

void wczytajStudentow(student *&tab,  int &liczbastudentow){
string sciezka, linia, pomoc;
ifstream plik;
char sredniki;
sciezka="studenci.csv";
plik.open(sciezka);
plik >> liczbastudentow;
for (int i = 0; i < 2; i++)
{
    plik >> sredniki;
}
tab = new student [liczbastudentow];
for(int i=0; i<liczbastudentow; i++){
plik>>linia;
stringstream ss(linia);
getline(ss, tab[i].imie, ';');
getline(ss, tab[i].nazwisko, ';');
getline(ss, pomoc);
tab[i].punkty=atoi(pomoc.c_str());}
plik.close();
}

void wyswietlStudentow(student *tab, int n){
    for (int i=0; i < n; i++)
    {
        cout << "Student nr " << i<<": ";
        cout <<tab[i].imie << " "<< tab[i].nazwisko<<" "<< tab[i].punkty<<endl;
    }
    cout<<endl;
}
void wyswietlStudentow2(student *tab, int n, int granica){
    int i=0;
    cout << "Ponizej " << granica << " punktow" << endl;
    while (i < n)
    {
        cout << "Student nr " << i<<": ";
        cout <<tab[i].imie << " "<< tab[i].nazwisko<<" "<< tab[i].punkty<<endl;
        i++;
        if (tab[i].punkty > granica){
            cout<<"Powyzej " << granica << " punktow " << endl;
            break;
        }
    }
    while (i<n){
      cout << "Student nr " << i<<": ";
      cout <<tab[i].imie << " "<< tab[i].nazwisko<<" "<< tab[i].punkty<<endl;
      i++;
    }
}
void wyswietlStudentow3(student *tab, int n){
    int i=0;
    cout << "Liczba punktow podzielna przez 3" << endl;
    while (i < n)
    {
        cout << "Student nr " << i<<": ";
        cout <<tab[i].imie << " "<< tab[i].nazwisko<<" "<< tab[i].punkty<<endl;
        i++;
        if ((tab[i].punkty%3)==1){
            cout<< "Liczba punktow podzielna przez 3 z reszta 1" << endl;
            break;}}
      while (i<n){
      cout << "Student nr " << i<<": ";
      cout <<tab[i].imie << " "<< tab[i].nazwisko<<" "<< tab[i].punkty<<endl;
      i++;
      if ((tab[i].punkty%3)==2){
            cout<< "Liczba punktow podzielna przez 3 z reszta 2" << endl;
            break;
      }}
      while (i<n){
      cout << "Student nr " << i<<": ";
      cout <<tab[i].imie << " "<< tab[i].nazwisko<<" "<< tab[i].punkty<<endl;
      i++;
        }
      }

void usunTabliceStudentow(student *&tab){
delete []tab;
cout << "usunieto tablice" << endl;
}
void zadanie4_1()
{
    student* tab;
    int liczbastudentow;
    wczytajStudentow(tab, liczbastudentow);
    wyswietlStudentow(tab, liczbastudentow);
}

int podzial2czesci(student* tab, int n, int granica)
{
 int i, j;
 i = 0; j = n - 1;
 while (i < j){
    while (tab[i].punkty <= granica && i<j){
        i ++;
    }
    while (tab[j].punkty > granica && i<j){
        j --;
    }
    if (i < j){
        swap(tab[i], tab[j]);
        i++;
        j --;
    }
 }
if (tab[i].punkty<= 10){
    return i+1;
}
else{
    return i;
    }
}

void podzial3czesci(student* tab, int n)
{
    int i, j, k;
    j=0; i=-1;
    k = n;
    while (j<k){
        if ((tab[j].punkty%3)==0){
            i++;
            swap(tab[i].punkty, tab[j].punkty);
            j++;
        }
        else
        {
            if((tab[j].punkty%3)==2){
            k--;
            swap(tab[k].punkty, tab[j].punkty);
            }
            else{
                j++;
            }
        }
    }
}

void zadanie4_2()
{
    student* tab;
    int liczbastudentow;
    wczytajStudentow(tab, liczbastudentow);
    wyswietlStudentow(tab, liczbastudentow);
    podzial2czesci(tab, liczbastudentow, 10);
    cout << "Po podziale "<< endl<<endl;
    wyswietlStudentow2(tab, liczbastudentow, 10);
    usunTabliceStudentow(tab);
}

void zadanie4_3(){
    student* tab;
    int liczbastudentow;
    wczytajStudentow(tab, liczbastudentow);
    wyswietlStudentow(tab, liczbastudentow);
    podzial3czesci(tab, liczbastudentow);
    cout << "Po podziale "<< endl<<endl;
    wyswietlStudentow3(tab, liczbastudentow);
    usunTabliceStudentow(tab);

}


int main()
{

    int wybor;
    wybor = 1;
    while (wybor != 0){
    cout << "Podaj numer zadania: " << endl << "1 - zadanie4_2" << endl << "2 - zadanie4_3" << endl << "0 - wyjscie z programu" << endl;
    cin >> wybor;
    if (wybor == 1)
    {
     zadanie4_2();
    }
    else if (wybor == 2)
    {
     zadanie4_3();
    }
    }
    return 0;
}
