#include <bits/stdc++.h>//TLE
using namespace std;
//https://hack.codingblocks.com/contests/c/511/1556
int main(){//;)
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int ii=0;
    for(int i=0;ii<k;i++){

        int cnt=0;
        for(int i=0;i<n-1;i++){
            if((v[i]<v[i+1])){
                break;
            }else{
                cnt++;
            }
        }
        if(cnt==n-1)break;

        auto ty=max_element(v.begin()+i+1,v.end());
        int tyindx=abs(v.begin()-ty);
        if(v[i]<v[tyindx]){ii++;
            swap(v[i],v[tyindx]);
        }
    }
    for(int i:v){
        cout<<i<<" ";
    }
}
