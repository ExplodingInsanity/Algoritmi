#include <iostream>

using namespace std;

/// cautare binara, clasic, recursiv, pe sir ordonat crescator, indexat de la 1
/// returneaza pozitia elementului in sir, sau -1 daca nu il gaseste
int caut(int val, int sir[], int s, int d){
if(s > d) return -1;
int mij = (s+d)/2;
if(sir[mij] == val) return mij;
else if(sir[mij] < val) return caut(val,sir,mij+1,d);
else return caut(val,sir,s,mij-1);
}

/// cautare binara iterativa in vectorul x[], indexat de la 1
/// returneaza pozitia lui val in sir, si daca o gaseste, sau -1 daca nu gaseste
int cautare_vect(int val, int x[], int n){
int lo = 1, hi = n;
while(lo <= hi){
int m = (lo+hi)/2;
if(x[m] == val) return m;
else if(x[m] < val) lo = m+1;
else hi = m-1;
}
return -1;
}

/// cautare binara, recursiva, fara parametri de stanga si dreapta
/// vector indexat de la 0
int cautare_rec(int n, int x[], int v){
if(n < 0) return -1; /// iesit afara din vector
int m = n/2; /// indexarea incepe de la 0
if(x[m] == v) return m; /// am gasit numar
if(x[m] > v) return cautare_rec(m-1,x,v); /// mutam high->m-1

int rez = cautare_rec(n-m-1,m+x+1,v); /// mutam low -> m-1
                                      /// luam sirul cu m+1 elemente mai in fata => x+m+1
                                      /// dar atunci, avem cu m+1 elemente mai putin
if(rez== -1) return rez; /// daca nu a gasit nimic, returneaza -1
                         /// daca a gasit ceva, trebuie sa adunam alea m-1 elemente pe care
                         /// le-am sters, pentru ca e index local ce imi returneaza functia
else return m+1+rez;
}

/// foloseste cautare binara in numerele de la 1 la n pentru radical
/// returneaza partea intreaga a sqrt(n)
int radical(int n){
int lo = 4, hi = n;
while(lo <= hi){
    int m = (lo+hi)/2;
    if(m*m <= n && (m+1)*(m+1) > n) return m;
    if(m*m>n&&(m-1)*(m-1)<=n) return m-1;
    if(m*m < n) lo = m+1;
    else hi = m-1;
}
return -1; /// asta ar fi daca numarul e negativ sau ceva, nu-mi dau seama cum altfel sa ajunga aici
           /// poate daca iese din int sau ceva idek.
}

int main()
{
    int a[] = {0,1,2,3,4,5,6,7,8,10,30,40,12};
    for(int i = 1; i <= 50; i++) cout<<i<<" : "<<cautare_vect(i,a,13)<<endl;
    //for(int i = 0; i <= 121; i++) cout<<i<<" : "<<radical(i)<<endl;
    return 0;
}
