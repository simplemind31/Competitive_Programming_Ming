#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
bool nums[500002];
int n,q,a,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    while(q--){
        cin >> a;
        if(nums[a-1] && nums[a+1])con+=nums[a]?1:-1;
        else if(!nums[a-1] && !nums[a+1])con-=nums[a]?1:-1;
        nums[a]=!nums[a];
        cout << con << '\n';
    }
}