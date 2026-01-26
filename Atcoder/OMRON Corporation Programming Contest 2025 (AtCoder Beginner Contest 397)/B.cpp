#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int con,res;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=0;i<st.size();i++){
        if(con%2){
            if(st[i]=='i'){
                res++;
                i--;
            }
        }else{
            if(st[i]=='o'){
                res++;
                i--;
            }
        }
        con++;
    }
    if(con&1)res++;
    cout << res;
}