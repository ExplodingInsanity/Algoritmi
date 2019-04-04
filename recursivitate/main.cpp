#include <iostream>

using namespace std;

/// converteste un numar din baza b in baza 10
/// in x[] sunt cele n cifre in baza b, indexate de la 1
int conversiein10(int n, int x[], int b){
if(n == 0) return 0;
return x[n] + b*conversiein10(n-1,x,b);
}

/// al n-lea termen al sirului lui fibonacci
int fibonacci(int n){
if(n <= 1) return 0;
if(n == 2) return 1;
return fibonacci(n-1) + fibonacci(n-2);
}

/// elementul de pe linia l, coloana c din triunghiul lui pascal
/// respectiv "combinari de l luate cate c"
int pascal(int l, int c){
if(l == c || c == 0) return 1;
return pascal(l-1,c-1) + pascal(l-1,c);
}

/// suma cifrelor unui numar
int sumcif(int n){
if(n < 10) return n;
return n%10+sumcif(n/10);
}

/// Numarul format din cifrele pare si cel din cifre impare
int sumcifpi(int n, int &p, int &i){
if(n < 9)
    if(n%2 == 0) { p = n; i = 0;}
    else { p = 0; i = n;}
else{
sumcifpi(n/10,p,i);
if(n%2 == 0) p = p*10+n%10;
else i = i*10+n%10;
}
}

/// valoarea unui polinom intr-un punct
/// coef[] -> coeficientii, indexati de la 0 la n, a0*x^n + a1*x^(n-1)+...+an
int poli(int n, int coef[], int x){
if(n == 0) return coef[0];
return coef[n] + x*poli(n-1,coef,x);
}

int main()
{
    for(int i = 1; i <= 10; i++) cout<<fibonacci(i)<<" ";
    cout<<endl;
    for(int i = 0; i <= 7; i++) cout<<pascal(7, i)<<" ";
    cout<<endl;
    cout<<sumcif(145345);
    cout<<endl;
    int p,i;
    sumcifpi(123456789,p,i);
    cout<<p<<endl<<i;
    cout<<endl;
    int coef[] = {3,5,-2,0,3};
    cout<<poli(4,coef,2);
}
