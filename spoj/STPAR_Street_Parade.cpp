//Carefully Crafted by hetp111
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


signed main(){
    FASTER;
    int n;cin>>n;
    while(n){
        stack<int> stkver;
        stack<int> stkhor;
        for(int i=0;i<n;i++){
            int tmp;cin>>tmp;

            if(tmp==1)stkhor.push(1);
            else{
                if(!stkhor.empty()){
                    if(tmp-1==stkhor.top())stkhor.push(tmp);
                    else stkver.push(tmp);
                }
                else stkver.push(tmp);
            }

            if(!stkhor.empty() && !stkver.empty())
            while(stkhor.top()+1==stkver.top()){
                stkhor.push(stkver.top());
                stkver.pop();
                if(stkver.empty())break;
            }
        }

        if(stkver.empty())cout<<"yes\n";
        else cout<<"no\n";

        cin>>n;
    }
}
