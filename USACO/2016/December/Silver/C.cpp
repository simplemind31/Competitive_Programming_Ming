#include <bits/stdc++.h>
using namespace std;
int n,maxi;
vector<int> graph[200];
bitset<200> visited;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    cin >> n;
    pair<pair<int,int>,int> cows[n];
    for(int i=0;i<n;i++){
        cin >> cows[i].first.first >> cows[i].first.second >> cows[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(pow(cows[i].first.first-cows[j].first.first,2)+pow(cows[i].first.second-cows[j].first.second,2)<=cows[i].second*cows[i].second){
                graph[i].push_back(j);
            }
        }
    }
    for(int i=0;i<n;i++){
        visited=0;
        visited[i]=1;
        queue<int> bfs;
        int con=0;
        bfs.push(i);
        while(!bfs.empty()){
            int top=bfs.front();
            bfs.pop();
            con++;
            for(auto u:graph[top]){
                if(visited[u])continue;
                visited[u]=true;
                bfs.push(u);
            }
        }
        maxi=max(maxi,con);
    }
    cout << maxi;
}