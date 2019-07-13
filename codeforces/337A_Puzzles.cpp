//het-
#include <bits/stdc++.h>
using namespace std;

main(){
    int n,m;cin>>n>>m;
    vector<int> f;
    for(int i=0;i<m;i++){
        int tmp;cin>>tmp;
        f.push_back(tmp);
    }
    sort(f.begin(),f.end());
    int minn=999999999;
    for(int i=0;i<m-n+1;i++){
        int mminn=f[i+n-1]-f[i];
        if(mminn<=minn){
            minn=mminn;
        }
    }
    cout<<minn;
}
