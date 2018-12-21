//het
#include <bits/stdc++.h>
using namespace std;

int findd(int L){
    for(int i=0;;i++){
        if(i*i>=L){
            return i*i;
        }
    }
}

int main(){
    int t=1;cin>>t;
    vector<string> answ;
    while(t--){/////////////////////////////////////////////////
        string s;cin>>s;
        int L=s.size();
        int M=findd(L);
        int K=sqrt(M);
        vector<vector<char>> v;
        for(int i=0;i<K;i++){
            vector<char> vv;
            for(int j=0;j<K;j++){
                vv.push_back('*');
            }
            v.push_back(vv);
        }
        int cnt=0;
        for(int i=0;i<K;i++){
            for(int j=0;j<K;j++){
                v[i][j]=s[cnt];
                cnt++;
                if(cnt==L)goto Li;
            }
        }
        Li:
        string sss;
        for(int i=0;i<K;i++){
            for(int j=K-1;j>=0;j--){
                if(v[j][i]!='*'){
                    sss+=v[j][i];
                }
            }
        }
        answ.push_back(sss);

    }///////////////////////////////////////////////////////////

    for(string answw:answ){
        cout<<answw<<endl;
    }
    return 0;
}
