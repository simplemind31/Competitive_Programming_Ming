#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x,y,k,m,mini=1e9;
map<pair<int,int>,int> visited;
void solve(int a,int b,int c){
    if(c>k)return;
    if(!visited.count({a,b})){
        visited[{a,b}]=c;
    }else{
        if(visited[{a,b}]<=c)return;
        visited[{a,b}]=c;
    }
    mini=min(mini,abs(a+b-m));
    solve(x,b,c+1);// a full
    solve(a,y,c+1);// b full
    solve(0,b,c+1);// a empty
    solve(a,0,c+1);// b empty
    int temp=min(a,y-b);
    solve(a-temp,b+temp,c+1);// a a b;
    temp=min(x-a,b);
    solve(a+temp,b-temp,c+1);// b a a
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("pails.in","r",stdin);
    freopen("pails.out","w",stdout);
    cin >> x >> y >> k >> m;
    solve(0,0,0);
    cout << mini;
}