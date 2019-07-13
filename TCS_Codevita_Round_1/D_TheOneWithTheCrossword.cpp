/////////////////////////////////////////////////////



//This :
//https://www.geeksforgeeks.org/solve-crossword-puzzle/




/////////////////////////////////////////////////////////////////////


#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define pii pair<int,int>
#define prec(n) fixed<<setprecision(n)
#define MOD 1000000007
#define eps 1e-8
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){
    return out<<"("<<a.first<<","<<a.second<<")";}
template<class A> ostream& operator<<(ostream& out, const vector<A> &a){
	out<<"";for(auto it=a.begin();it!=a.end();it++){if(it!=a.begin())out<<" ";out<<*it;}out<<"";
	return out;}
template<class A, class B> istream& operator>>(istream& in, pair<A,B> &a){in>>a.first>>a.second;return in;}
template<class A> istream& operator>>(istream& in, vector<A> &a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

int ways = 0; 
vector<string> matrix; ////yeeee local tha
int n;

int qaz=0;

void printdown(int r,int c,vector<string>& Matrix){
    qaz++;
    cout<<qaz<<",D";
    for(int i=r;i<n;i++){
        cout<<Matrix[i][c];
        if(i+1>=n)break;
        if(Matrix[i+1][c]=='*')break;
    }
    cout<<"\n";
}
void printrig(int r,int c, vector<string>& Matrix){
    qaz++;
    cout<<qaz<<",A";
    for(int i=c;i<n;i++){
        cout<<Matrix[r][i];
        if(i+1>=n)break;
        if(Matrix[r][i+1]=='*')break;
    }
    cout<<"\n";
}
void printMatrix(vector<string>& Matrix, int n) 
{ 
    
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(Matrix[r][c]!='*'){
                    int flg=1;
                    if(c+1<n && Matrix[r][c+1]!='*' && flg){
                        if(c==0){printrig(r,c,Matrix);flg++;}
                        else if(Matrix[r][c-1]=='*'){
                            printrig(r,c,Matrix);flg++;
                        }
                    }
                    if(r+1<n && Matrix[r+1][c]!='*' && flg){
                        if(r==0){printdown(r,c,Matrix);flg++;}
                        else if(Matrix[r-1][c]=='*'){
                            printdown(r,c,Matrix);flg++;
                        }
                    }
                }
            }
        }
} 

vector<string> checkHorizontal(int x, int y, 
                               vector<string> matrix, 
                               string currentWord) 
{ 
    int n = currentWord.length(); 
  
    for (int i = 0; i < n; i++) { 
        if (matrix[x][y + i] == '#' ||  
            matrix[x][y + i] == currentWord[i]) { 
            matrix[x][y + i] = currentWord[i]; 
        } 
        else { 
            matrix[0][0] = '@'; 
            return matrix; 
        } 
    } 
  
    return matrix; 
} 

vector<string> checkVertical(int x, int y, 
                             vector<string> matrix, 
                             string currentWord) 
{ 
    int n = currentWord.length(); 
  
    for (int i = 0; i < n; i++) { 
        if (matrix[x + i][y] == '#' ||  
            matrix[x + i][y] == currentWord[i]) { 
            matrix[x + i][y] = currentWord[i]; 
        } 
        else { 
            matrix[0][0] = '@'; 
            return matrix; 
        } 
    } 
    return matrix; 
} 
  
void solvePuzzle(vector<string>& words, 
                 vector<string> matrix, 
                 int index, int n) 
{ 
    if (index < words.size()) { 
        string currentWord = words[index]; 
        int maxLen = n - currentWord.length(); 

        for (int i = 0; i < n; i++) { 
            for (int j = 0; j <= maxLen; j++) { 
                vector<string> temp = checkVertical(j, i, 
                                        matrix, currentWord); 
  
                if (temp[0][0] != '@') { 
                    solvePuzzle(words, temp, index + 1, n); 
                } 
            } 
        } 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j <= maxLen; j++) { 
                vector<string> temp = checkHorizontal(i, j, 
                                      matrix, currentWord); 
  
                if (temp[0][0] != '@') { 
                    solvePuzzle(words, temp, index + 1, n); 
                } 
            } 
        } 
    } 
    else { 


        printMatrix(matrix, n); 
        cout << endl; 

        ways++; 
        return; 
    } 
}



signed main(){
    FASTER;
    int m;cin>>n;
    matrix.resize(n,string(n,'#'));
    for(int i=0;i<n;i++){
        string s;cin>>s;
        int mm,cm;
        for(int j=0;j<s.size();j+=4){
            cm=s[j]-'0'-1;
            mm=s[j+2]-'0';
            if(cm==0 && mm==0)break;
            for(int asd=0;asd<mm;asd++)matrix[i][cm+asd]='*';
        }
    }
    cin>>m;
    vector<string> words;
    for(int i=0;i<m;i++){
        string asd;cin>>asd;
        words.push_back(asd);
    }
    ways=0;
    solvePuzzle(words, matrix, 0, n);
    
    
    
}