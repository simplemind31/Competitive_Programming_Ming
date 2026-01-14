#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,t;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> st;
        vector<int> nums(26);
        bool xd=true;
        for(int i=0;i<n && xd;i++){
            if(++nums[st[i]-'a']>2)xd=false;
        }
        if(xd)cout << "YES\n";
        else cout << "NO\n";
    }
}