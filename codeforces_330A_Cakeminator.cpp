#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/330/submission/47901072
//https://codeforces.com/contest/330/problem/A
//by het-
main()
{
    int r,c;cin>>r>>c;
    int sver=0,shor=0;
    vector<vector<char>> v(r,vector<char>(c,0));
    for(int i=0;i<r;i++){
        int flg=0;
        for(int j=0;j<c;j++){
            char c;cin>>c;
            v[i][j]=c;
            if(c=='S' && flg==0){
                shor++;
                flg=1;
            }
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            if(v[j][i]=='S'){
                sver++;
                break;
            }
        }
    }
    int ans = (r-shor)*c+(c-sver)*r-(r-shor)*(c-sver);
    cout<<ans;
}
