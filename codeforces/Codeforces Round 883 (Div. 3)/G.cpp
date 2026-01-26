#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define INF 1e9
#define MOD 1000000007
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FIN "\n"
#define REP(i,a,b) for(int i=a;i<b;i++)
#define ALL(x) x.begin(),x.end()
#define LSOne(x) (x)&-(x)
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define beginzeros(x) __builtin_clz(x)
#define endzeros(x) __builtin_ctz(x)
#define countones(x) __builtin_popcount(x)
#define parity(x) __builtin_parity(x)
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<long long> vll;
int t,n,m,x=0;
vector<pii> graph[1<<10];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        bitset<10> aa;
        cin >> aa;
        vector<pair<pair<int,int>,int>> medi(m);
        int x=(int)aa.to_ulong();
        for(int i=0;i<m;i++){
            scanf("%d",&medi[i].second);
            cin >> aa;
            medi[i].first.first=((1<<n)-1)^(int)aa.to_ulong();
            cin >> aa;
            medi[i].first.second=(int)aa.to_ulong();
        }
        vector<bool> visited(1<<n);
        vi dis(1<<n,INF);
        priority_queue<pair<int,int>> orden;
        dis[x]=0;
        orden.push({0,x});
        while(!orden.empty()){
            int a=orden.top().second;
            orden.pop();
            if(visited[a]){
                continue;
            }
            visited[a]=true;
            for(int i=0;i<m;i++){
                dis[(a&medi[i].first.first)|medi[i].first.second]=min(dis[(a&medi[i].first.first)|medi[i].first.second],dis[a]+medi[i].second);
                orden.push({-dis[(a&medi[i].first.first)|medi[i].first.second],(a&medi[i].first.first)|medi[i].first.second});
            }
        }
        if(dis[0]==INF){
            printf("-1\n");
        }else{
            printf("%d\n",dis[0]);
        }
    }
}