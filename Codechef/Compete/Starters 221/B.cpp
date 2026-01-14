#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
int t;
string n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        if((n.back()-'0')&1){
            cout << "0\n";
            continue;
        }
        if(n.size()==1){
            cout << "-1\n";
            continue;
        }
        int con0=0,maxi=0;
        bool xd=false;
        for(int i=0;i<n.size();i++){
            if(n[i]=='0')con0++;
            maxi=max(maxi,n[i]-'0');
            if((n[i]-'0')&1)xd=true;
        }
        if(con0==n.size()-1){
            if(xd)cout << "1\n";
            else cout << "2\n";
            continue;
        }
        if(xd){
            cout << "1\n";
            continue;
        }
        if(n.back()-'0'<maxi){
            cout << "2\n";
        }else{
            cout << "3\n";
        }
    }
}