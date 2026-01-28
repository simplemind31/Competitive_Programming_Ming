#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int x,y,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> x >> y;
    vector<bool> nums(x);
    while(y--){
        cin >> a;
        if(!nums[--a])x--;
        else x++;
        nums[a]=!nums[a];
    }
    cout << x;
}