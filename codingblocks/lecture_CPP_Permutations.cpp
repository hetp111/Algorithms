//Carefully crafted by hetp111
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define sz(v) (v).size()
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

//https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits/0

char carr[10][4]={
    {0,0,0,0},
    {0,0,0,0},
    {'A','B','C',0},
    {'D','E','F',0},
    {'G','H','I',0},
    {'J','K','L',0},
    {'M','N','O',0},
    {'P','Q','R','S'},
    {'T','U','V',0},
    {'W','X','Y','Z'}
};

int szofNum(int n){
    if(n==7 || n==9)return 4;
    else return 3;
}

string tolowr(string s){
    string ss=s;
    for(char &i:ss){
        i=tolower(i);
    }
    return ss;
}

void f(string num, string str, int i){
    if(str.size()==num.size()){
        cout<<tolowr(str)<<" ";
        return;
    }
    for(int j=0;j<szofNum(num[i]-'0');j++){
        f(num,str+carr[num[i]-'0'][j],i+1);
    }
}

signed main(){
    FASTER;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s="";
        while(n--){
            char cd;cin>>cd;
            s+=cd;
        }
        f(s,"",0);cout<<"\n";
    }

}
