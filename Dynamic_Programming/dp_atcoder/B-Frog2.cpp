#include <bits/stdc++.h>
using namespace std;
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
 
int main(){
    FASTER;
    int n,k;cin>>n>>k;
    vector<int> h(n),F(n,INT_MAX);for(int &i:h)cin>>i;
 
    if(k>=n){
        k=n;
    }
 
    for(int i=0;i<k;i++)F[i]=abs(h[0]-h[i]);
 
    for(int i=k;i<n;i++){
        for(int j=i-1;j>=i-k;j--){
            F[i]=min(abs(h[i]-h[j])+F[j],F[i]);
        }
    }
    cout<<F[n-1];
}
