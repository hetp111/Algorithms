//Carefully Crafted by hetp111
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

signed main(){
    FASTER;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);for(int &i:v)cin>>i;

        int I=-1;
        for(int i=0;i<n-1;i++){
            if(v[i]<v[i+1])I=i;
        }

        if(I!=-1){
            int J=I+1;
            for(int j=I+2;j<n;j++){
                if(v[j]>v[I])J=j;
            }

            swap(v[I],v[J]);
            reverse(v.begin()+I+1,v.end());
            for(int i:v)cout<<i;
        }else{
            cout<<-1;
        }
        cout<<"\n";
    }
}
