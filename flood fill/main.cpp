#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("input.txt");

int dl[] = {0,1,0,-1};
int dc[] = {-1,0,1,0};

void fill(int x, int y, int a[101][101], int n, int value){

if(x < 1 || y < 1 || y > n || x > n) return;
if(a[x][y] != 0) return;
a[x][y] = value;
for(int i = 0; i < 4; i++) fill(x+dl[i],y+dc[i],a,n,value);
}


int main()
{
    ///citire
    int n, a[101][101];
    fin>>n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) fin>>a[i][j];
    ///fill
    int value = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) if(a[i][j] == 0) fill(i,j,a,n,++value);
    ///afisare
for(int i = 1; i <= n; i++,cout<<endl)
    for(int j = 1; j <= n; j++,cout<<" ") {
        ///afisez peretii ca 0, nu -1, ca sa nu imi mute desenul in fata cu un caracter de la '-'
        ///atunci fac maxim
        cout<<max(a[i][j],0);
    }



    return 0;
}
