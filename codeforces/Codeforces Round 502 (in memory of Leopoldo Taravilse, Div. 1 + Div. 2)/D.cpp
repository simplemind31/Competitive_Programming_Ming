#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,q,con[1<<12],k;
vector<pair<int,int>> posi[1<<12];
bitset<12> temp;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    int nums[n],corressum[1<<n];
    for(int i=n-1;i>=0;i--)cin >> nums[i];
    for(int i=0;i<m;i++){
        cin >> st;
        con[bitset<12>(st).to_ulong()]++;
    }
    cout << endl;
    for(int mask=0;mask<(1<<n);mask++)for(int j=corressum[mask]=0;j<n;j++)if(mask&(1<<j))corressum[mask]+=nums[j];
    for(int mask=0;mask<(1<<n);mask++){
        for(int mask2=0;mask2<(1<<n);mask2++)posi[mask].push_back({corressum[(~(mask^mask2))&((1<<n)-1)],con[mask2]});
        sort(ALL(posi[mask]));
        for(int i=1;i<(1<<n);i++)posi[mask][i].second+=posi[mask][i-1].second;
    }
    while(q--){
        cin >> st >> k;
        int a=bitset<12>(st).to_ulong();
        cout << (--upper_bound(ALL(posi[a]),make_pair(k,(int)1e9)))->second << '\n';
    }
}