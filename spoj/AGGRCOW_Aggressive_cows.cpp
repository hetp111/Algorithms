//Carefully Crafted by hetp111
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

//<3
bool canFit(const vector<int> &v, int dis, int c){
    int cnt=0;
    cnt++;//for 1st cow
    int lstpos=v[0];
    for(int i=1;i<v.size();i++){
        if(v[i]-lstpos>=dis){
            lstpos=v[i];
            cnt++;
            if(cnt>=c)return true;
        }
    }
    return false;
}

signed main(){
    FASTER;
    int t;cin>>t;
    while(t--){
        int n,c;cin>>n>>c;
        vector<int> v(n);for(int &i:v)cin>>i;
        sort(all(v));
        int l=0,r=v[n-1]-v[0],mid,Ans=-1;//0 to max-min
        while(l<=r){
            mid=(l+r)/2;
            if(canFit(v,mid,c)){
                Ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        cout<<Ans<<"\n";
    }
}
