//Carefully Crafted by hetp111
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

signed main() {
    FASTER;
    int n;cin>>n;
    while(n){
        stack<int> pos;
        stack<int> height;
        int mx=-1;
        for(int i=0;i<n;i++){
            int h;cin>>h;
            if(height.empty() || h>=height.top()){
                pos.push(i);
                height.push(h);
            }else{
                int tmpP=-1;
                while(!height.empty() && h<height.top()){
                    tmpP=pos.top();
                    int ans=height.top()*(i-pos.top());
                    mx=max(mx,ans);
                    height.pop();
                    pos.pop();
                }
                pos.push(tmpP);
                height.push(h);
            }
        }
        while(!height.empty()){
            int ans=height.top()*(n-pos.top());
            mx=max(mx,ans);
            height.pop();
            pos.pop();
        }
        cout<<mx<<"\n";
        cin>>n;
    }
}
