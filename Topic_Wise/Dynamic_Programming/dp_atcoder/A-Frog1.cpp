#include <bits/stdc++.h>
using namespace std;
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
 
int f(vector<int> h,int n){
    if(n==0)return 0;
    else if(n==1)return abs(h[0]-h[1]);
    return min(abs(h[n]-h[n-1])+f(h,n-1),abs(h[n]-h[n-2])+f(h,n-2));
}
 
int main(){
    FASTER;
    int n;cin>>n;
    vector<int> h(n),F(n,INT_MAX);for(int &i:h)cin>>i;
    F[0]=0;
    F[1]=abs(h[1]-h[0]);
    for(int i=2;i<n;i++)F[i]=min(abs(h[i]-h[i-1])+F[i-1],abs(h[i]-h[i-2])+F[i-2]);
    cout<<F[n-1];
}
