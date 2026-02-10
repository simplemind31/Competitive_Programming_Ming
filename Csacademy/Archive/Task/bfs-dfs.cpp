#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int bfsord[4096],dfsord[4096],n;
vector<pair<int,int>> res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)cin >> bfsord[i];
    for(int i=0;i<n;i++)cin >> dfsord[i];
    if(bfsord[1]!=dfsord[1]){
        cout << -1;
        return 0;
    }
    cout << n-1+n-2 << '\n';
    for(int i=1;i<n;i++)cout << 1 << ' ' << bfsord[i] << '\n';
    for(int i=2;i<n;i++)cout << dfsord[i-1] << ' ' << dfsord[i] << '\n';
}