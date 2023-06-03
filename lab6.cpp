#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int make_hash(char s, int off,int p, int exp){
    int Hash = (((int)s) - off)*pow(p,exp);
    return Hash;
}

int update_hash(int Hash, char s_prev, char s_next, int off,int p, int exp){
    int u_hash=Hash - ((int)s_prev-off)*pow(p,exp);
    u_hash = u_hash*p;
    u_hash = u_hash +((int)s_next-off);
    return u_hash;
}

void karp_rabin(string pattern, string text, int p, int off){
    bool var= true;
    int lenP = pattern.length();
    int lenT = text.length();
    int hashP=0;
    int hashT = 0;
    for(int i=0;i<lenP;i++){
        hashP=hashP+ make_hash(pattern[i],off,p,lenP-i-1);
        hashT=hashT+ make_hash(text[i],off,p,lenP-i-1);
    }
    for(int j=0, i=lenP;i<=lenT;i++,j++){
        if(hashP==hashT){
            int k=0;
            while(k<lenP && pattern[k]==text[j+k]){
                k++;
            }
            if(k==lenP){
                cout<<j<<" ";
                var=false;
            }
        }
        if(i<lenT){
            hashT= update_hash(hashT,text[j],text[i],off,p,lenP-1);
        }
    }
    if(var)
    {
        cout<<"-1";
    }
}

int main() {
    string sciezka, linia;
    ifstream plik;
    sciezka="C:\\Users\\jakub\\Desktop\\Algorytmika\\tekst.txt";
    string pattern;
    plik.open(sciezka);
    plik >> pattern;
    int i=2;
    while (!plik.eof()){
        plik>>linia;
        cout<<"Linijka nr "<<i<<": ";
        karp_rabin(pattern,linia,2,0);
        i++;
        cout<<endl;
    }
    plik.close();
    return 0;
}
