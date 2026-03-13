#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll pro=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<bool> nums(n);
    for(int i=1;i<n;i++){
        if(gcd(i,n)==1){
            nums[i]=true;
            pro*=i;
            pro%=n;
        }
    }
    if(pro!=1)nums[pro]=false;
    vector<int> res;
    for(int i=0;i<n;i++){
        if(nums[i])res.push_back(i);
    }
    cout << res.size() << '\n';
    for(auto u:res){
        cout << u << ' ';
    }
}
/*
2
1

3
1

4
1

5
1 2 3

6
1

7
1 3 5

8
1 3 5 7

9
1 2 4 5 7 8
*/