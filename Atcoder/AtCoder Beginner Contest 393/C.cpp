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
int n,m,con,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    set<pair<int,int>> conj;
    while(m--){
        cin >> a >> b;
        if(a==b)con++;
        else{
            if(a>b)swap(a,b);
            if(conj.find({a,b})!=conj.end())con++;
            else conj.insert({a,b});
        }
    }
    cout << con;
}