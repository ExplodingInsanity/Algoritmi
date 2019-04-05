#include <iostream>

using namespace std;

/// conversie din baza b in baza 10, iterativ
/// b < 10
int dinbin10(int n, int b){
int p = 1;
int s = 0;
while(n > 0) {
    s = s+(n%10)*p;
    p*=b;
    n/=10;
}
return s;
}

/// conversie din baza b in baza 10, recursiv
/// b < 10
int dinbin10R(int n, int b, int p){
if(n == 0) return 0;
return n%10*p + dinbin10R(n/10,b,p*b);
}

/// conversie din baza 10 in baza b, iterativ
/// b < 10
int din10inb(int n, int b){
int s = 0, p = 1;
while(n > 0){
    s = s+n%b*p;
    p*=10;
    n/=b;
}
return s;
}

/// conversie din baza 10 in baza b, recursiv
/// b < 10
int din10inbR(int n, int b){
if(n == 0) return 0;
return n%b+10*din10inbR(n/b,b);
}

/// conversie din baza b in baza 10, iterativ
/// ca sir de n caractere
int _dinbin10(int n, char nr[], int b){
int s = 0;
int p = 1;
for(int i = n; i >= 1; i--){
    if(nr[i] >= 'A' && nr[i] <= 'Z') s += (nr[i]-'A'+10)*p;
    else if(nr[i] >= '0' && nr[i] <= '9') s += (nr[i]-'0')*p;
    p*=b;
}
return s;
}

/// conversie din baza b in baza 10, recursiv
/// ca sir de n caractere
int _dinbin10R(int n, char nr[], int b){
if(n == 0) return 0;
if(nr[n] >= 'A' && nr[n] <= 'Z') return nr[n]-'A'+10 + b*_dinbin10R(n-1,nr,b);
else if(nr[n] >= '0' && nr[n] <= '9') return nr[n]-'0' + b*_dinbin10R(n-1,nr,b);
}

/// conversie din baza 10 in baza b, recursiv
/// returneaza ca sir
void _din10inbR(int nr, int b, int &n, int rez[]){
if(nr == 0) n = 0;
else {
    _din10inbR(nr/b,b,n,rez);
    rez[++n] = nr%b;
}
}

int main()
{
    cout<<dinbin10(1010,2)<<endl; /// tre sa dea 10
    cout<<dinbin10R(1010,2,1)<<endl; /// tre sa dea 10
    cout<<din10inb(10,2)<<endl; /// tre sa dea 1010
    cout<<din10inbR(10,2)<<endl; /// tre sa dea 1010
    char nr[] = "_41A";
    cout<<_dinbin10R(3,nr,16)<<endl; /// tre sa dea 1050
    cout<<_dinbin10(3,nr,16)<<endl; /// tre sa dea 1050
    int n,rez[101];
    _din10inbR(10,2,n,rez); /// tre sa dea 1010
    for(int i = 1; i <= n; i++) cout<<rez[i];

    return 0;
}
