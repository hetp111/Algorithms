//Carefully Crafted by hetp111
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

//STACK 
//ref: http://gautamimp.blogspot.com/2016/02/d-maximum-xor-secondary-find-max-and.html

signed main() {
    FASTER;
    int n,ans=-1;cin>>n;
    stack<int> stk;
    for(int i=0;i<n;i++){
        int in;cin>>in;
        while(!stk.empty()){
            if(in<stk.top()){
                ans=max(ans,stk.top()^in);
                stk.push(in);
                break;
            }else{
                ans=max(ans,stk.top()^in);
                stk.pop();
            }
        }
        stk.push(in);
    }
    cout<<ans;
}
