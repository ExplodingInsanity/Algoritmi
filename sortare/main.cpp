#include <iostream>

using namespace std;

void bubble_sort(int n, int a[]){
bool ok;
do{
    ok = true;
    for(int i = 1; i < n; i++)
    if(a[i] > a[i+1]){
        int aux = a[i];
        a[i] = a[i+1];
        a[i+1] = aux;
        ok = false;
    }
}while(!ok);
}

void interclasare(int a[], int ia, int ib, int n){
int i = ia; /// index in primul subsir
int j = ib; /// index in al doilea subsir
int c[1001], nc=0; /// auxiliar
while(i < ib && j <= n){
if(a[i] <= a[j]) c[++nc] = a[i++];
else c[++nc] = a[j++];
}
while(i <= ib) c[++nc] = a[i++];
while(j <= n) c[++nc] = a[j++];
for(int i = 1; i <= nc; i++) a[i] = c[i];
n = nc;
}

void merge_sort(int a[], int i, int f){
    if(i < f){
        int m = (i+f)/2;
        merge_sort(a,i,m);
        merge_sort(a,m+1,f);
        interclasare(a,i,m,f);
    }
}

int main()
{
    int a[] = {0,15,14,12,16,17,13,11,16,10,7,6,5,4,3,9,8,1,2};
    int n = 18;
    merge_sort(a,1,n);
    for(int i = 1; i <= n; i++) cout<<a[i]<<" ";
    return 0;
}
