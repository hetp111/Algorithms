//Carefully crafted by hetp111
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define sz(v) (v).size()
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

//https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits/0
//https://hack.codingblocks.com/contests/c/16/96

char carr[10][4]={
    {0,0,0,0},
    {'.','+','@','$'},
    {'a','b','c',0},
    {'d','e','f',0},
    {'g','h','i',0},
    {'j','k','l',0},
    {'m','n','o',0},
    {'p','q','r','s'},
    {'t','u','v',0},
    {'w','x','y','z'}
};

int szofNum(int n){
    if(n==7 || n==9 || n==1)return 4;
    else return 3;
}


void f(string num, string str, int i){
    if(str.size()==num.size()){
        cout<<(str)<<"\n";
        return;
    }
    for(int j=0;j<szofNum(num[i]-'0');j++){
        f(num,str+carr[num[i]-'0'][j],i+1);
    }
}

signed main(){
    FASTER;
    string s;cin>>s;
    f(s,"",0);

}
