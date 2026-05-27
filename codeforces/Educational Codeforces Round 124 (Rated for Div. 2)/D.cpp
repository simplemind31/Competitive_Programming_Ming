#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
typedef long long ll;
int n;
vector<pair<pair<int,int>,int>> nums;
set<pair<int,int>> posi;
int exis(int x,int y){
    int pos=lower_bound(ALL(nums),make_pair(make_pair(x,y),0))-nums.begin();
    if(pos>=n)return -1;
    if(nums[pos].first==make_pair(x,y))return pos;
    return -1;
}
bool nose(int x,int y){
    int pos=lower_bound(ALL(nums),make_pair(make_pair(x,y),0))-nums.begin();
    if(pos>=n || nums[pos].first!=make_pair(x,y))return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    nums.resize(n);
    for(int i=0;i<n;i++){
        cin >> nums[i].first.first >> nums[i].first.second;
        nums[i].second=i;
    }
    sort(ALL(nums));
    queue<int> bfs;
    vector<pair<int,int>> res(n,{-10000000,-10000000});
    for(int i=0;i<n;i++){
        if(nose(nums[i].first.first-1,nums[i].first.second)){
            res[nums[i].second]={nums[i].first.first-1,nums[i].first.second};
            bfs.push(i);
            continue;
        }
        if(nose(nums[i].first.first+1,nums[i].first.second)){
            res[nums[i].second]={nums[i].first.first+1,nums[i].first.second};
            bfs.push(i);
            continue;
        }
        if(nose(nums[i].first.first,nums[i].first.second-1)){
            res[nums[i].second]={nums[i].first.first,nums[i].first.second-1};
            bfs.push(i);
            continue;
        }
        if(nose(nums[i].first.first,nums[i].first.second+1)){
            res[nums[i].second]={nums[i].first.first,nums[i].first.second+1};
            bfs.push(i);
            continue;
        }
    }
    while(!bfs.empty()){
        int top=bfs.front();
        bfs.pop();
        pair<int,int> u=nums[top].first;
        int pos=exis(u.first-1,u.second);
        if(pos!=-1 && res[nums[pos].second]==make_pair(-10000000,-10000000)){
            res[nums[pos].second]=res[nums[top].second];
            bfs.push(pos);
        }
        pos=exis(u.first+1,u.second);
        if(pos!=-1 && res[nums[pos].second]==make_pair(-10000000,-10000000)){
            res[nums[pos].second]=res[nums[top].second];
            bfs.push(pos);
        }
        pos=exis(u.first,u.second-1);
        if(pos!=-1 && res[nums[pos].second]==make_pair(-10000000,-10000000)){
            res[nums[pos].second]=res[nums[top].second];
            bfs.push(pos);
        }
        pos=exis(u.first,u.second+1);
        if(pos!=-1 && res[nums[pos].second]==make_pair(-10000000,-10000000)){
            res[nums[pos].second]=res[nums[top].second];
            bfs.push(pos);
        }
    }
    for(int i=0;i<n;i++){
        cout << res[i].first << ' ' << res[i].second << '\n';
    }
}