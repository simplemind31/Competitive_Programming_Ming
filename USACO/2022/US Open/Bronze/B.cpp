#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,a;
char c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> G,L;
    L.push_back(1e9);
    while(n--){
        cin >> c >> a;
        if(c=='G')G.push_back(a);
        else L.push_back(a);
    }
    sort(ALL(L));
    sort(ALL(G));
    int res=1e9;
    for(int i=0;i<G.size();i++){
        int pos=lower_bound(ALL(L),G[i])-L.begin();
        res=min(res,(int)G.size()-i-1+pos);
    }
    cout << res;
}