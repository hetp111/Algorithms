#include<bits/stdc++.h>
using namespace std;

int f(int a,int b){
    if(b==1)return a;
    if(b==0)return 0;
    if(a<0 && b<0)return -(a+f(a,-b-1));
    if(a>0 && b>0)return a+f(a,b-1);
    if(a>0 && b<0)return b+f(b,a-1);
    if(a<0 && b>0)return a+f(a,b-1);
}
int main(){
    int a,b;cin>>a>>b;
    cout<<f(a,b);
}
