//-het
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t=1;//cin>>t;
    vector<string> answ;
    while(t--){//////////////////////////////////////////////////////////////////////////////////////////////////
        int n,tttt;cin>>n>>tttt;
        vector<int> v;set<int> ass;
        for(int i=0;i<tttt;i++){
            int tmp;cin>>tmp;
            v.push_back(tmp);
            ass.insert(tmp);
            ass.insert(n-tmp);
        }
        for(int a:v){
            for(int b:v){
                if(a!=b){
                    ass.insert(abs(a-b));
                }
            }
        }
        ass.insert(n);
        for(int a:ass){
            cout<<a<<" ";
        }

        //answ.push_back(to_string(cnt));
    }/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    for(string answw:answ){
        cout<<answw<<endl;
    }
    return 0;
}
