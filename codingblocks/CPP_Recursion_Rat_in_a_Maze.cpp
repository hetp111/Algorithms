//Carefully Crafted by hetp111
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

//CB

bool solvMz(vector<vector<char> > &mz, int i, int j, int m, int n){
    if(i==m && j==n){
        mz[m][n]='1';
        cout<<"\n";
        for(i=0;i<=m;i++){
            for(j=0;j<=n;j++){
                cout<<mz[i][j]<<"";
            }
            cout<<"\n";
        }
        return true;
    }

    if(i>m || j>n)return false;
    if(mz[i][j]=='X')return false;

    mz[i][j]='1';
    bool right = solvMz(mz, i, j+1, m, n);
    bool down = solvMz(mz, i+1, j, m, n);
    mz[i][j]='O';

    if(right || down)return true;

    return false;//or true, dosent matter if prining, return false if u want check in main function

}

signed main(){
    FASTER;
    int n,m;cin>>m>>n;
    vector<vector<char> > mz(m,vector<char>(n,'O'));//n row m column
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mz[i][j];//X or O
        }
    }
    bool ans = solvMz(mz,0,0,m-1,n-1);
    if(!ans)cout<<"Doesn't exist!";
}
