#include <iostream>

using namespace std;

/// Face reuneste multimile a si b in vectorul c, fara repetarea valorilor
/// a si b trebuie sa fie sortate crescator
void interclasare(int a[], int na, int b[], int nb, int c[], int &nc){
nc = 0;
int i = 1; /// index in primul sir
int j = 1; /// index in al doilea sir

while(i <= na && j <= nb){
if(a[i] == b[j]) i++;
else if(a[i] < b[j]) c[++nc] = a[i++];
else c[++nc] = b[j++];
}
while(i <= na) c[++nc] = a[i++];
while(j <= nb) c[++nc] = b[j++];
}

int main()
{
    int a[]= {0,1,2,4,5,7,9,15,16};
    int na = 8;
    int b[]= {0,1,2,6,8,9,15,16,17,20,21};
    int nb = 10;
    int c[101], nc;
    interclasare(a,na,b,nb,c,nc);
    for(int i = 1; i <= nc; i++) cout<<c[i]<<" ";
    return 0;
}
