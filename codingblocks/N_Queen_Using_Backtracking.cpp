//Carefully Crafted by hetp111
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

//CB https://www.youtube.com/watch?v=jFwREev_yvU   N - Queen Problem using Backtracking Algorithm [Hinglish]

bool canPlace(const vector<vector<int> > &v, int i, int j, int n){
    int R=i,C=j;
    while(R>=0 && C<n){
        if(v[R][C])return false;
        R--;C++;
    }
    R=i,C=j;
    while(R>=0 && C>=0){
        if(v[R][C])return false;
        R--;C--;
    }

    for(R=i-1;R>=0;R--){
        if(v[R][j])return false;
    }

    return true;

}

bool nQueen(vector<vector<int> > &v, int i, int n){
    if(i==n-1+1){
        for(int ii=0;ii<n;ii++){
            for(int j=0;j<n;j++){
                cout<<v[ii][j]<<"";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return false;
    }
    //place queen in curr row and call the rest rows
    for(int j=0;j<n;j++){
        if(canPlace(v,i,j,n)){
            v[i][j]=1;
            bool nextQpossible = nQueen(v,i+1,n);
            if(nextQpossible){
                return true;
            }else{
                v[i][j]=0;//backtrack!!!!!!!!!!
            }
        }
    }
    return false;
}

signed main(){
    FASTER;
    int n;cin>>n;
    vector<vector<int> > v(n,vector<int>(n,0));
    nQueen(v,0,n);
}
