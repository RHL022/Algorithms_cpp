#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct element{
    int number;
    element* next;
};

void push(element* &stack, int value){
element *el;
el=new element;
el->number=value;
el->next=stack;
stack=el;
}

void pop(element* &stack){
element *temp;
temp=stack;
stack=stack->next;
delete temp;
}

int isEmpty(element* stack){
if (stack == nullptr){
return 1;
}
else return 0;
}

int top(element* stack){
return stack->number;
}

int main(){
element* stack=nullptr;
int value;
int wybor=9;
while(wybor!=6){
cout << "Podaj numer zadania:"<< endl;
cout << "1-sprawdzenie czy jest pusty"<< endl;
cout << "2-dodanie elementu na stos"<< endl;
cout << "3-usunięcie elementu ze stosu"<< endl;
cout << "4-wyswietlenie wierzchołka stosu"<< endl;
cout << "5-wyczyszczenie stosu"<< endl;
cout << "6-wyjscie"<< endl;

cin >> wybor;
cout<< endl;
if (wybor == 1){
    int pusty;
    pusty=isEmpty(stack);
    if (pusty==1){
    cout<<"Stos pusty"<<endl;
    }
    else cout <<"Stos nie jest pusty" << endl;
}
if (wybor==2){
int losowa;
srand(time(NULL));
losowa = (rand()%10)+1;
cout << "Wylosowana liczba to: "<< losowa<<endl;
push(stack, losowa);
}
if (wybor==3){
int pusty;
pusty=isEmpty(stack);
if (pusty == 1){
cout<< "Stos jest pusty"<<endl;
}
else{
pop(stack);
cout<<"Usunięto"<<endl;
}
}
if (wybor==4){
int pusty;
pusty=isEmpty(stack);
if (pusty == 1){
cout<< "Stos jest pusty"<<endl;
}
else{
int wierzch;
wierzch=top(stack);
cout<<"Liczba na wierzchu"<<wierzch<<endl;
}
}
if(wybor==5){
int pusty;
int wierzch;
pusty = 0;
while(pusty!=1){
pusty=isEmpty(stack);
if(pusty ==0){
wierzch=top(stack);
cout<<"Liczba na wierzchu"<<wierzch<<endl;
pop(stack);
}
else break;
}
cout<<"wyczyszczony"<<endl<<endl;

}
}

return 0;
}
