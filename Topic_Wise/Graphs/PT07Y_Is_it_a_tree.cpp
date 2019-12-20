//Carefully Crafted by hetp111
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int cycle=0;
list<int> *lst = new list<int>[10000];
bool *boo = new bool[10000]{0};

void f(int v, int last){
    if(boo[v]){
        cycle=1;
        return;
    }
    boo[v]=1;
    for(int i:lst[v]){
        if(i!=last)f(i,v);
    }
}

signed main(){
    FASTER;
    int n,m;cin>>n>>m;
    if(n==m+1){
        for(int t=0;t<m;t++){
            int a,b;cin>>a>>b;a--;b--;
            lst[a].push_back(b);
            lst[b].push_back(a);
        }
        f(0,0);
        for(int asdd=0;asdd<n;asdd++)
            if(!boo[asdd]){
                cycle=1;break;
            }
        if(cycle){
            cout<<"NO";
        }else{
            cout<<"YES";
        }

    }else{
        cout<<"NO";
    }
}
