#include <bits/stdc++.h>
using namespace std;
//https://hack.codingblocks.com/contests/c/101/102
//PLAYING WITH BITS
//;)
int cntbitsfst(int n){
    int cnt=0;
    while(n>0){
        n=n&(n-1);
        cnt++;
    }
    return cnt;
}
int cntbitsslow(int n){
    int cnt=0;
    while(n>0){
        if(n&1)cnt++;
        n=n>>1;
    }
    return cnt;
}

main(){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        int cnt=0;
        for(int i=a;i<=b;i++){
            cnt+=cntbitsfst(i);
        }
        cout<<cnt<<"\n";
    }
}
