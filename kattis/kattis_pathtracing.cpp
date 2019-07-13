//https://open.kattis.com/problems/pathtracing ||  KATTIS IS NOT ACCEPTING ALL THE CASESES EVEN THOUGH ALL MY OUTPUT IS CORRECT TO MY BEST KNOWLEDGE  ||
//het patel - hetp111                          ||  ADDING A NEWLINE IN THE END PASSED 2 CASES, ALTHOUGH IN SAMPLE OUTPUT NO NEWLINE WAS GIVEN. THIS MADE ME HATE KATTIS!  ||
#include <bits/stdc++.h>
using namespace std;
main(){
        vector<vector<char>> v;int noin=1;
        for(int i=0;i<2000;i++){
            vector<char> vv;
            for(int j=0;j<2000;j++){
                vv.push_back(' ');
            }
            v.push_back(vv);
        }
        string s;int i=1000,j=1000;v[1000][1000]='S';
        string lst;
        int Xmi=1999,Ymi=1999,Xmx=0,Ymx=0;
        if(Xmi>=j){Xmi=j;}
        if(Ymi>=i){Ymi=i;}
        if(Xmx<=j){Xmx=j;}
        if(Ymx<=i){Ymx=i;}
        while(cin>>s){
            noin=0;
            lst=s;
            if(s=="up"){
                v[--i][j]='*';
            }else if(s=="down"){
                v[++i][j]='*';
            }else if(s=="right"){
                v[i][++j]='*';
            }else if(s=="left"){
                v[i][--j]='*';
            }
            if(Xmi>=j){Xmi=j;}
            if(Ymi>=i){Ymi=i;}
            if(Xmx<=j){Xmx=j;}
            if(Ymx<=i){Ymx=i;}
        }
        v[i][j]='E';
        int hor=Xmx-Xmi+3;int tyty=hor;
        while(hor--)cout<<"#";cout<<"\n";
        for(i=Ymi;i<=Ymx;i++){
            cout<<"#";
            for(j=Xmi;j<=Xmx;j++){
                cout<<v[i][j];
            }
            cout<<"#"<<endl;
        }
        while(tyty--)cout<<"#";
        cout<<"\n";
}
