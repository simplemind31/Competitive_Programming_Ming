#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
const int MAXN=300000;
int n,s,t;
bitset<MAXN+1> criba;
vector<int> primos,graph[MAXN+1][2];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    criba[0]=criba[1]=true;
    for(int i=4;i<=MAXN;i+=2)criba[i]=true;
    primos.push_back(2);
    for(int i=3;i*i<=MAXN;i+=2){
        if(!criba[i]){
            for(int j=i*i;j<=MAXN;j+=i)criba[j]=true;
        }
    }
    for(int i=3;i<=MAXN;i+=2){
        if(!criba[i])primos.push_back(i);
    }
    cin >> n;
    int nums[n],exi[MAXN+1];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cin >> s >> t;
    s--;t--;
    int oris=nums[s],orit=nums[t];
    for(int i=0;i<n;i++){
        exi[nums[i]]=i;
        int ante=nums[i];
        for(int j=2;j*j<=nums[i];j++){
            if(nums[i]%j!=0)continue;
            graph[ante][0].push_back(j);
            graph[j][1].push_back(ante);
            while(nums[i]%j==0)nums[i]/=j;
        }
        if(nums[i]!=1){
            graph[ante][0].push_back(nums[i]);
            graph[nums[i]][1].push_back(ante);
        }
    }
    if(s==t){
        cout << "1\n" << s+1;
        return 0;
    }
    if(oris==1 || orit==1){
        cout << -1;
        return 0;
    }
    if(oris==orit){
        cout << "2\n" << s+1 << ' ' << t+1;
        return 0;
    }
    vector<vector<int>> dist(MAXN+1,vector<int> (2,1e9)),pad(MAXN+1,vector<int>(2,-1));
    queue<pair<int,int>> bfs;
    bfs.push({oris,0});
    dist[oris][0]=0;
    while(!bfs.empty()){
        pair<int,int> top=bfs.front();
        bfs.pop();
        for(auto u:graph[top.first][top.second]){
            if(dist[u][1-top.second]==1e9){
                dist[u][1-top.second]=dist[top.first][top.second]+1;
                pad[u][1-top.second]=top.first;
                bfs.push({u,1-top.second});
            }
        }
    }
    if(dist[orit][0]==1e9){
        cout << -1;
        return 0;
    }
    vector<int> res;
    int now=orit;
    exi[orit]=t;
    exi[oris]=s;
    while(now!=oris && now!=-1){
        res.push_back(exi[now]);
        now=pad[pad[now][0]][1];
    }
    res.push_back(s);
    cout << res.size() << '\n';
    reverse(res.begin(),res.end());
    for(auto u:res)cout << u+1 << ' ';
}