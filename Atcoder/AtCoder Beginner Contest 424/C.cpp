#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int n,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    pair<int,int> nums[n];
    queue<int> cola;
    vector<int> set[n];
    vector<bool> visited(n);
    for(int i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
        if(nums[i]==make_pair(0,0)){
            cola.push(i);
            visited[i]=true;
            continue;
        }
        set[--nums[i].first].push_back(i);
        set[--nums[i].second].push_back(i);
    }
    while(!cola.empty()){
        int top=cola.front();
        cola.pop();
        for(auto u:set[top]){
            if(!visited[u]){
                visited[u]=true;
                cola.push(u);
            }
        }
    }
    for(int i=0;i<n;i++){
        con+=visited[i];
    }
    cout << con;
}