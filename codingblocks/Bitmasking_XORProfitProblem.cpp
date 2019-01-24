#include <bits/stdc++.h>
using namespace std;
//https://hack.codingblocks.com/practice/p/366/498
//;)
main(){
    int x,y;cin>>x>>y;
    int ans=-1;
    for(int i=x;i<=y;i++){
        for(int j=i;j<=y;j++){
            ans=max(ans,i^j);
        }
    }
    cout<<ans;
}
