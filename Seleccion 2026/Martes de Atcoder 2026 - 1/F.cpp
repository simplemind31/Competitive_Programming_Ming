#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,corres[500000];
string st,res;
// de iz a de=0
// de de a iz=1
void solve(int iz,int de,bool estad){
    //si encuentro parentesis empiezo con corres[i]
    if(!estad){
        for(int i=iz+1;i<de;i++){
            if(st[i]=='('){
                solve(i,corres[i],!estad);
                i=corres[i];
            }else{
                res.push_back(st[i]);
            }
        }
    }else{
        for(int i=de-1;i>iz;i--){
            if(st[i]==')'){
                solve(corres[i],i,!estad);
                i=corres[i];
            }else{
                res.push_back(st[i]);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    n=st.size();
    stack<int> par;
    int con=0;
    for(int i=0;i<n;i++){
        if(st[i]=='('){
            par.push(i);
        }else if(st[i]==')'){
            corres[i]=par.top();
            corres[par.top()]=i;
            par.pop();
        }else{
            if(par.size()&1){
                if(st[i]<='Z')st[i]+='a'-'A';
                else st[i]-='a'-'A';
            }
        }
    }
    solve(-1,n,0);
    cout << res;
}
/*
((AB)y)x
(yab)x
*/