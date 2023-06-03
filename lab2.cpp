#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void sortowanieBabelkowe(int* tab, int n, int tryb);
void sortowaniePrzezWybor(int* tab, int n, int tryb);
void sortowaniePrzezWstawianie(int* tab, int n, int tryb);
void wypelnijTablice(int *tab, int n, int a, int b);
void przydzielPamiec(int *&tab, int n);
void wyswietl1D(int* tab, int n);
void usunTablice1D(int *&tab);
void zadanie2_2();
void zadanie2_3();
void zadanie2_4();

int main()
{
    int wybor;
    cout << "Podaj numer zadania" << endl;
    cin >> wybor;
    if (wybor == 1)
    {
     zadanie2_2();
    }
    else if (wybor == 2)
    {
     zadanie2_3();
    }
    else if (wybor == 3)
    {
     zadanie2_4();
    }
    return 0;
}

void usunTablice1D(int *&tab){
    delete []tab;}

void wypelnijTablice(int *tab, int n, int a, int b)
{
    srand(time(NULL));
    for(int i=0; i<n; i++){
        tab[i]=rand()%(b-a+1)+a;
    }
}
void przydzielPamiec1D(int *&tab, int n){
    tab = new int[n];
}
void wyswietl1D(int* tab, int n){
    for(int i=0; i<n; i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

void sortowanieBabelkowe(int* tab, int n, int tryb)
{
    int i, j, p;
    i=n-1;
    if(tryb == 1)
    {
     while(i>0)
    {
      j=0;
      p=1;
      while(j<i)
      {
          if (tab[j]>tab[j+1])
          {
              swap(tab[j],tab[j+1]);
              p=0;
          }
      j=j+1;
      }
    if (p==1)
    {
     break;
    }
    i = i-1;
    }
    }
    else
    {
     while(i>0)
    {
      j=0;
      p=1;
      while(j<i)
      {
          if (tab[j]<tab[j+1])
          {
              swap(tab[j],tab[j+1]);
              p=0;
          }
      j=j+1;
      }
    if (p==1)
    {
     break;
    }
    i = i-1;
    }
    }

}

void sortowaniePrzezWybor(int* tab, int n, int tryb)
{
    int i, ind, j;
    i=n-1;
    if (tryb == 1)
    {
    for(;i>0;i--)
    {
        ind = 0;
        j = 1;
        for (;j<=i;j++)
        {
            if (tab[j]>tab[ind])
            {
             ind = j;
            }
        }
       swap(tab[i], tab[ind]);
    }
    }
    else if (tryb == 2)
    {
        for(;i>0;i--)
    {
        ind = 0;
        j = 1;
        for (;j<=i;j++)
        {
            if (tab[j]<tab[ind])
            {
             ind = j;
            }
        }
       swap(tab[i], tab[ind]);
    }
    }
}

void sortowaniePrzezWstawianie(int* tab, int n, int tryb)
{
    int i, j, temp;
    i=i-2;
    if (tryb == 1)
    {for(;i>=0;)
    {
        j=i;
        temp = tab[j];
        for(;temp>tab[j+1]&&j<n-1;)
        {
            tab[j]=tab[j+1];
            j++;
        }
        tab[j]=temp;
        i--;
    }
    }
    else if (tryb==2)
    {
        for(;i>=0;)
    {
        j=i;
        temp = tab[j];
        for(;temp<tab[j+1]&&j<n-1;)
        {
            tab[j]=tab[j+1];
            j++;
        }
        tab[j]=temp;
        i--;
    }
    }
}


void zadanie2_2()
{
    int n, a, b, tryb;
    int *tab;
    cout << "Podaj rozmiar tablicy ";
    cin >> n;
    cout << "Przedzial losowania: ";
    cin >> a >> b;
    cout << "Podaj tryb sortowania 1-rosn, 2-mal ";
    cin >> tryb;
    przydzielPamiec1D(tab, n);
    wypelnijTablice(tab, n, a, b);
    wyswietl1D(tab, n);
    sortowanieBabelkowe(tab, n, tryb);
    wyswietl1D(tab, n);
}

void zadanie2_3()
{
    int n, a, b, tryb;
    int *tab;
    cout << "Podaj rozmiar tablicy ";
    cin >> n;
    cout << "Przedzial losowania: ";
    cin >> a >> b;
    cout << "Podaj tryb sortowania 1-rosn, 2-mal ";
    cin >> tryb;
    przydzielPamiec1D(tab, n);
    wypelnijTablice(tab, n, a, b);
    wyswietl1D(tab, n);
    sortowaniePrzezWybor(tab, n, tryb);
    wyswietl1D(tab, n);
}

void zadanie2_4()
{
    int n, a, b, tryb;
    int *tab;
    cout << "Podaj rozmiar tablicy ";
    cin >> n;
    cout << "Przedzial losowania: ";
    cin >> a >> b;
    cout << "Podaj tryb sortowania 1-rosn, 2-mal ";
    cin >> tryb;
    przydzielPamiec1D(tab, n);
    wypelnijTablice(tab, n, a, b);
    wyswietl1D(tab, n);
    sortowaniePrzezWstawianie(tab, n, tryb);
    wyswietl1D(tab, n);
}
