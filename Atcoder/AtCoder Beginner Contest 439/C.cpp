#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,con[10000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> res;
    int mid=sqrt(n);
    for(int i=1;i<=mid;i++){
        for(int j=i+1;j<=mid;j++){
            if(i*i+j*j<=n){
                con[i*i+j*j]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(con[i]==1){
            res.push_back(i);
        }
    }
    cout << res.size() << '\n';
    for(auto u:res){
        cout << u << ' ';
    }
}