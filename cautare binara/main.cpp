#include <iostream>

using namespace std;

int radical(int n){
int lo = 4, hi = n;
while(lo <= hi){
    int m = (lo+hi)/2;
    if(m*m <= n && (m+1)*(m+1) > n) return m;
    if(m*m>n&&(m-1)*(m-1)<=n) return m-1;
    if(m*m < n) lo = m+1;
    else hi = m-1;
}
return -1;
}

/// cauta in vectorul x[], indexat de la 1, valoarea val, si daca o gaseste, returneaza pozitia ei
/// daca nu o gaseste, returneaza -1
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

int main()
{
    int a[] = {0,1,2,3,4,5,6,7,8,10,30,40,12};
    for(int i = 1; i <= 50; i++) cout<<i<<" : "<<cautare_vect(i,a,13)<<endl;
    //for(int i = 0; i <= 121; i++) cout<<i<<" : "<<radical(i)<<endl;
    return 0;
}
