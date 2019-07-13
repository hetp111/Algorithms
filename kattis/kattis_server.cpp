//https://open.kattis.com/problems/server
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t=1;//cin>>t;
    vector<string> answ;
    while(t--){//////////////////////////////////////////////////////////////////////////////////////////////////
        int n,tttt;cin>>n>>tttt;
        int sum=0;int cnt=0;
        vector<int> v;
        for(int i=0;i<n;i++){
            int tmp;cin>>tmp;
            v.push_back(tmp);
            sum+=tmp;
            if(sum<=tttt){
                cnt++;
            }
        }
        answ.push_back(to_string(cnt));
    }/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    for(string answw:answ){
        cout<<answw<<endl;
    }
    return 0;
}
