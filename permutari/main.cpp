#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("permutari.in");
ofstream fout("permutari.out");

void permuta(int v[], int n, int poz){
for(int i = 1; i <= poz-2; i++) if(v[i] == v[poz-1]) return;
if(poz == n+1){
    for(int i = 1; i <= n; i++) fout<<v[i]<<" ";
    fout<<endl;
    return;
}
v[poz] = 1;
while(v[poz]<=n){
    permuta(v,n,poz+1);
    v[poz]++;
}
}

int main()
{
    int v[41000] = {1};
    int n; fin>>n;
    permuta(v,n,1);
}
