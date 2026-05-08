#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,con;
ll nums=123456789;
ll power[10];
unordered_map<ll,int> dist;
void swap(ll& n,int a,int b){
    // digito a y digito b
    //a<=b
    // 123456789
    ll digia=(n/power[9-a-1])%10;
    ll digib=(n/power[9-b-1])%10;
    n-=digia*power[9-a-1];
    n-=digib*power[9-b-1];
    n+=digib*power[9-a-1];
    n+=digia*power[9-b-1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    power[0]=1;
    for(int i=1;i<10;i++)power[i]=power[i-1]*10;
    dist[nums]=0;
    queue<ll> bfs;
    bfs.push(nums);
    while(!bfs.empty()){
        ll top=bfs.front();
        int ante=dist[top];
        bfs.pop();
        for(int i=0;i<3;i++){
            for(int j=0;j<2;j++){
                swap(top,i*3+j,i*3+j+1);
                if(!dist.count(top)){
                    dist[top]=ante+1;
                    bfs.push(top);
                }
                swap(top,i*3+j,i*3+j+1);
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                swap(top,i*3+j,(i+1)*3+j);
                if(!dist.count(top)){
                    dist[top]=ante+1;
                    bfs.push(top);
                }
                swap(top,i*3+j,(i+1)*3+j);
            }
        }
    }
    nums=0;
    for(int i=0;i<9;i++){
        cin >> a;
        nums=nums*10+a;
    }
    cout << dist[nums];
}