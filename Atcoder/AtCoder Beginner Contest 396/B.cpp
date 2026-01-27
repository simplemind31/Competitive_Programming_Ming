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
int n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    stack<int> card;
    for(int i=0;i<100;i++)card.push(0);
    cin >> n;
    while(n--){
        cin >> a;
        if(a==2){
            cout << card.top() << '\n';
            card.pop();
        }else{
            cin >> a;
            card.push(a);
        }
    }
}