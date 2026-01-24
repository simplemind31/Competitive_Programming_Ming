#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int q,t,x,y;
queue<pair<int,int>> largeque;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> q;
    while(q--){
        cin >> t;
        if(t==1){
            cin >> x >> y;
            largeque.push({x,y});
        }else{
            cin >> x;
            ll sum=0;
            while(!largeque.empty() && x>=largeque.front().first){
                sum+=1LL*largeque.front().first*largeque.front().second;
                x-=largeque.front().first;
                largeque.pop();
            }
            if(x!=0){
                sum+=1LL*x*largeque.front().second;
                largeque.front().first-=x;
            }
            cout << sum << '\n';
        }
    }
}