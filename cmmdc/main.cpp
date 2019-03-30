#include <iostream>

using namespace std;

int euclid(int a, int b){
int c;
while(b){
    c = a%b;
    a = b;
    b = c;
}
return a;
}

int euclid_recursiv(int _a, int _b){
if(_b == 0) return _a;
return euclid(_b,_a%_b);
}

int cmmdc_scaderi(int a, int b){
while(a!=0 && b!= 0) if(a>b) a-=b;
            else b-=a;
return a+b;
}

int main()
{
    int x,y;
    while(true){
    cin>>x>>y;
    cout<<"euclid: "<<euclid(x,y)<<endl;
    cout<<"euclid recursiv: "<<euclid_recursiv(x,y)<<endl;
    cout<<"scaderi: "<<cmmdc_scaderi(x,y)<<endl;
    }
}
