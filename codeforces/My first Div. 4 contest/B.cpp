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
int t=1,n;
char c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> con(26);
        for(int i=0;i<n;i++){
            cin >> c;
            con[c-'a']++;
        }
        bool xd=false;
        for(int i=0;i<26 && !xd;i++){
            if(con[i]>1){
                cout << char(i+'a') << char(i+'a') << '\n';
                xd=true;
            }
        }
        if(!xd)cout << "-1\n";
    }
}