#include <bits/stdc++.h>
using namespace std;
//https://hack.codingblocks.com/practice/p/366/458
//;)
main(){
    int n;cin>>n;
    vector<int> bits(40,0);
    for(int i=0;i<n;i++){
        int num;cin>>num;
        int idx=0;
        while(num>0){
            if(num&1)bits[idx]++;
            num=num>>1;
            idx++;
        }
    }
    int ans=0;
    for(int i=0;i<40;i++){
        bits[i]%=3;
        ans+=(1<<i)*bits[i];
    }
    cout<<ans;
}
