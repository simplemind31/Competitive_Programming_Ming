#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll; 
int c,n;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n;
    int nums[n],dist[1<<c];
    for(int i=0;i<(1<<c);i++){
        dist[i]=c;
    }
    for(int i=0;i<n;i++){
        cin >> st;
        for(int j=nums[i]=0;j<c;j++){
            nums[i]|=(st[j]=='H')<<j;
        }
        dist[nums[i]]=0;
    }
    for(int j=0;j<c;j++){
        for(int i=0;i<(1<<c);i++){
            dist[i^(1<<j)]=min(dist[i^(1<<j)],dist[i]+1);
        }
    }
    for(int i=0;i<n;i++){
        cout << c-dist[nums[i]^((1<<c)-1)] << '\n';
    }
}