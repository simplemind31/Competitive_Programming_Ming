#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n;
ll res=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int cows[n],stalls[n];
    for(int i=0;i<n;i++)cin >> cows[i];
    for(int i=0;i<n;i++)cin >> stalls[i];
    sort(cows,cows+n);
    sort(stalls,stalls+n);
    int j=n;
    for(int i=n-1;i>=0;i--){
        while(j && stalls[j-1]>=cows[i])j--;
        if(i<j){
            cout << 0;
            return 0;
        }
        res*=(i-j+1);
    }
    cout << res;
}