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
int a,con[13];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<7;i++){
        cin >> a;
        con[--a]++;
    }
    for(int i=0;i<13;i++){
        for(int j=0;j<13;j++){
            if(i!=j && con[i]>=3 && con[j]>=2){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}