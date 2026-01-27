#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int n;
char mat[50][50],mat1[50][50],mat2[50][50];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n/2;i+=2)mat[i][i]=mat[n-i-1][i]='#';
    for(int i=n-1;i>=n/2;i-=2)mat[i][i]=mat[n-i-1][i]='#';
    if(n&1 && ((n/2)&1)==0)mat[n/2][n/2]=' ';
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]=='#'){
                for(int k=j+1;k<n;k++){
                    if(mat[i][k]=='#')break;
                    mat1[i][k]='#';
                }
                break;
            }
        }
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(mat[i][j]=='#'){
                for(int k=i+1;k<n;k++){
                    if(mat[k][j]=='#')break;
                    mat2[k][j]='#';
                }
                break;
            }
        }
    }
    if(n&1 && ((n/2)&1)==0)mat[n/2][n/2]='#';
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]=='#' || mat1[i][j]=='#' || mat2[i][j]=='#')mat[i][j]='#';
            if(mat[i][j]!='#')mat[i][j]='.';
            cout << mat[i][j];
        }
        cout << '\n'; 
    }
}