#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,s,a,mini=1e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> s;
    int last[s+1];
    for(int i=0;i<=s;i++)last[i]=-1e9;
    // ultimo primer elemento en formar i de suma
    for(int i=0;i<n;i++){
        cin >> a;
        last[0]=i;
        for(int j=s;j>=a;j--)last[j]=max(last[j-a],last[j]);
        mini=min(mini,i-last[s]+1);
    }
    if(mini==1e9)mini=-1;
    cout << mini;
}