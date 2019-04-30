//Carefully Crafted by hetp111
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

string printRevStk(stack<char> st){
    string ss="";
    stack<char> nw;
    while(!st.empty()){
        nw.push(st.top());
        st.pop();
    }
    while(!nw.empty()){
        ss+=nw.top();
        nw.pop();
    }
    return ss;
}

int f(string s){
    int n=s.size(),ans=0,a=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='{')a++;
        else b++;
    }
    ans=a/2+b/2;
    if(a&1)ans+=2;
    return ans;
}

signed main(){
    FASTER;
    string s;cin>>s;int casee=1;
    while(s[0]!='-'){
        int n=s.size();
        stack<char> stk;
        for(int i=0;i<n;i++){
            if(s[i]=='}'){
                int flg=1;
                if(!stk.empty() && stk.top()=='{'){
                    stk.pop();flg=0;
                }
                if(flg){
                    stk.push('}');
                }
            }else{
                stk.push(s[i]);
            }
        }
        string ss=printRevStk(stk);
        cout<<casee<<". "<<f(ss)<<"\n";
        casee++;
        cin>>s;
    }
}
