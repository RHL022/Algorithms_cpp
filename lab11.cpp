#include <iostream>
#include <cstdlib>


using namespace std;

struct element{
    int number;
    element *next;
};

struct single_list{
    element* head;
    element* tail;
    int counter;
};

void add_tail(single_list &l, int value){
element *el;
el=new element;
el->number=value;
el->next=nullptr;
if (l.tail!=nullptr)
    {
    l.tail->next=el;
    }
else l.head=el;
l.tail=el;
l.counter++;
}

void add_head(single_list &l, int value){
element *el;
el=new element;
el->number=value;
el->next=l.head;
l.head=el;
if(l.tail==nullptr) l.tail=el;
l.counter++;
}

void add_position(single_list &l, int value, int position){
element* el;
element *temp;
el=new element;
el->number=value;
temp=l.head;
int i=1;
while(i<position-1){
    temp=temp->next;
    i++;
    }
el->next=temp->next;
temp->next=el;
l.counter++;
}

void delete_tail(single_list &l){
element* temp;
element* bef_temp;
temp=l.tail;
if (l.counter==1)
    {
    l.tail=nullptr;
    l.head=nullptr;
    }
else{
    bef_temp=l.head;
    int i=1;
    while (i<l.counter-1){
        bef_temp=bef_temp->next;
        i++;
        }
    l.tail=bef_temp;
    l.tail->next=nullptr;
    }
l.counter--;
delete temp;
}

void delete_head(single_list &l){
element* temp;
temp=l.head;
l.head=l.head->next;
if(l.counter==1){
    l.tail=nullptr;
    }
l.counter--;
delete temp;
}

void delete_position(single_list &l, int position){
element *prev, *temp;
prev=l.head;
int i=1;
while(i<position-1){
    prev=prev->next;
    i++;
    }
temp=prev->next;
prev->next=temp->next;
l.counter--;
delete temp;
}

void show(single_list &l){
int i=1;
element *temp;
temp=l.head;
while(i<=l.counter){
    cout<<temp->number<<endl;
    temp=temp->next;
    i++;
    }
}
bool isEmpty(single_list &l){
    if(l.tail == nullptr || l.tail== nullptr) return 1;
    else return 0;
}


int main(){
single_list l;
int wybor;
wybor=16;
while(wybor!=15){
cout<<"Podaj nr_zadania 1-czy jest pusty, 2-dodanie na koniec, 3-dodanie na poczatek, 4 dodanie na pozycje, 5 usuniecie z konca, 6 usuniecie z poczatku, 7 usuniecie z pozycji, 8 pobranie pierwszego 15-wyjscie"<<endl;
cin>>wybor;
cout<<endl;
if (wybor==1){
    if((isEmpty(l))==1){
        cout<<"Pusty"<<endl;
        }
    else cout<<"Niepusty"<<endl;
    }
else if(wybor==2){
    int value;
    value=rand()%50+1;
    add_tail(l, value);
    }
else if(wybor==3){
    int value;
    value=rand()%50+1;
    add_head(l, value);
    }
else if(wybor==4){
    int value, pozycja;
    value=rand()%50+1;
    cout<<"Podaj pozycje"<<endl;
    cin>>pozycja;
    add_position(l, value, pozycja);
    }
else if(wybor==5){
    delete_tail(l);
    }
else if(wybor==6){
    delete_head(l);
    }
else if(wybor==7){
    int pozycja;
    cout<<"Podaj pozycje"<<endl;
    cin>>pozycja;
    delete_position(l, pozycja);
    }
}

return 0;
}
