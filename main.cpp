#include <iostream>
#include <fstream>

using namespace std;

/*int pobranieDanych(int A[], int &x){
int stopien;
cout<<"Podaj stopien wielomianu"<<endl;
cin>>stopien;
for(int i=0;i<stopien;i++){
    cout<<"Wartosc wspolczynnika a" << i <<":"<<endl;
    cin>>A[i];
}
cout<<"x:"<<endl;
cin>> x;
}*/


int horner(int A[],int n, int x){
 int wynik;
 wynik = A[0];
 for(int i=1;i<=n;i++){
    wynik = wynik*x + A[i];
 }

 return wynik;
}


int main()
{
int n, x;
cout<<"Podaj stopien wielomianu"<<endl;
cin>>n;
int A[n+1];
for(int i=0;i<=n;i++){
    cout<<"Wartosc wspolczynnika a" << i <<":"<<endl;
    cin>>A[i];
}
cout<<"x:"<<endl;
cin>> x;
cout<<endl;

for(int i=0;i<=n;i++){
    cout<<"Wartosc wspolczynnika a" << i <<":"<<endl;
    cout<<A[i]<<endl;
}

cout<<"Wartosc w punkcie wynosi: ";
cout<<horner(A, n, x)<<endl;
    return 0;
}
