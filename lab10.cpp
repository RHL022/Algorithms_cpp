#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

struct element{
 char character;
 element* next; };

struct queue{
 element* head;
 element* tail; };

void push(queue &q, char value){
element *el;
el=new element;
el->character=value;
el->next=nullptr;
if (q.tail!=nullptr){
    q.tail->next=el;
    }
else q.head=el;
q.tail=el;
}

void pop(queue &q){
element *temp;
temp = q.head;
q.head=q.head->next;
delete temp;
if (q.head==nullptr){
    q.tail=nullptr;
    }
}

int isEmpty(queue q){
if (q.head==nullptr) return 1;
else return 0;
}

int first(queue q){
return q.head->character;
}

int main(){
queue q;
q.head=nullptr;
q.tail=nullptr;
int wybor=9;
while(wybor!=7){
cout << endl;
cout << "Podaj numer zadania:"<< endl;
cout << "1-sprawdzenie czy kolejka jest pusta"<< endl;
cout << "2-dodanie elementu"<< endl;
cout << "3-usuniecie elementu"<< endl;
cout << "4-pobranie elementu"<< endl;
cout << "5-wyczyszczenie kolejki"<< endl;
cout << "7-wyjscie"<< endl;
cin >> wybor;
if (wybor == 1){
    int czyPusty;
    czyPusty = isEmpty(q);
    if (czyPusty==1){
        cout << "Kolejka jest pusta" << endl;
        }
    else cout << "Kolejka nie jest pusta" << endl;
    }
else if(wybor==2){
    int value;
    value = rand() % 100;
    cout<<value<<endl;
    push(q, value);
    }
else if(wybor==3){
    int czyPusty;
    czyPusty = isEmpty(q);
    if (czyPusty==1){
        cout << "Kolejka jest pusta, nie da sie usunac elementu" << endl;
        }
    else {
        pop(q);
        cout << "Usunięto" << endl;
        }
    }
else if(wybor==4){
    int ostatnia;
    ostatnia=first(q);
    cout << ostatnia << endl;
    }
else if(wybor==5){
    int Pusty;
    int ostatnia;
    Pusty=0;
    while(Pusty!=1){
        pop(q);
        cout << "Usunieto" << endl;
    }
    cout << "wyczyszczono" << endl;
    }
else if(wybor==6){
    fstream plik;
    plik.open("C:/Users/jakub/Downloads/znaki2.txt");
    while(!plik.eof()){
        int value;
        value=plik.get();
        if (value>64 && value<91){
            char znak;
            znak = char(value);
            push(q, znak);
            }
    }
    while(isEmpty(q)!=1){
        cout << (char)first(q) << endl;
        pop(q);
    }
}
}


return 0;
}
