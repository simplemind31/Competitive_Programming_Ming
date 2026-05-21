#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,k,mini;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k >> st;
    for(int i=0;i<n && mini<=k;i++){
        if(st[i]!='N')continue;
        for(int j=i;j<n && st[j]=='N' && mini<=k;j++)mini=max(mini,j-i+1);
    }
    if(mini>k){
        cout << "NO";
        return 0;
    }
    if(k==0){
        cout << "YES";
        return 0;
    }
    for(int i=0;n-i>=k;i++){
        // empezar aca
        if(st[i]=='Y' || (i && st[i-1]=='N'))continue;
        for(int j=i;j-i+1<=k && st[j]!='Y';j++){
            if(j-i+1==k){
                if(j+1<n && st[j+1]=='N')continue;
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}