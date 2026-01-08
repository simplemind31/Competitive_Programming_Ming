#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,l,x,y,a,b,j;
double mini=1e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> l >> x >> y;
    vector<pair<int,double>> bus(n);
    vector<pair<int,int>> ord(m);
    vector<double> res(m);
    for(int i=0;i<n;i++){
        cin >> a >> b;
        bus[i]={a,(double)(b-a)/x+(double)(l-b)/y};
    }
    for(int i=0;i<m;i++){
        cin >> a;
        ord[i]={a,i};
        bus.push_back({a,(double)(l-a)/y});
    }
    sort(ALL(bus));
    sort(ALL(ord));
    n=bus.size();
    for(int i=0;i<m;i++){
        while(j<n && bus[j].first<=ord[i].first){
            mini=min(mini,bus[j].second);
            j++;
        }
        res[ord[i].second]=mini;
    }
    cout << fixed << setprecision(6);
    for(int i=0;i<m;i++)cout << res[i] << '\n';
}