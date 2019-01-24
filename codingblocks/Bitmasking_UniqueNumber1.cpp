#include <bits/stdc++.h>
using namespace std;

main(){
    int n;cin>>n;
    int ans,tmp;cin>>tmp;
    ans=tmp;
    for(int i=1;i<n;i++){
        cin>>tmp;
        ans=ans^tmp;
    }
    cout<<ans;
}
