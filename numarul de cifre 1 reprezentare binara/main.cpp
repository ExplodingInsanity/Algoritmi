#include <iostream>

using namespace std;

int numara_impartiri(int n){
/// numara de cate ori da restul 1 pentru binar
    int c = 0;
while(n) {
        if(n%2 == 1) c++;
        n/=2;
}
return c;
}

int numara_biti1(int n){
/// numara mereu ultimul bit, apoi muta totul cu un bit in dreapta pana numarul devine 0
int c = 0;
while(n){
c+= n&1;
n = n>>1;
}
return c;
}

int numara_biti_pred(int n){
/// face in continuu & logic intre n si n-1, ca sa scoata cate un bit 1 odata
/// n-1 practic schimba cel mai din dreapta 1 in 0, si prin n&n-1 scoate bitul ala
int c = 0;
while(n){
    n&=n-1;
    c++;
}
return c;
}

int numara_biti_preproc(int n){
/// cunoscand numarul de 1 din reprezentarile de la 0000->1111 putem lua 4 cate 4 bitii
int biti[] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
int c = 0;
while(n){
c+= biti[n&15]; /// si logic intre n si 1111, practic iau ultimii 4 biti
n = n>>4; ///mutam 4 biti in dreapta
}
return c;
}

int main()
{
int n;
while(true){
    cin>>n;
    cout<<numara_impartiri(n)<<','<<numara_biti1(n)<<','<<numara_biti_pred(n)<<','<<numara_biti_preproc(n)<<endl;
}
}
