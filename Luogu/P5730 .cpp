#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string st,res[5];
vector<string> nums[10];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> st;
    nums[0]={"XXX.","X.X.","X.X.","X.X.","XXX."};
    nums[1]={"..X.","..X.","..X.","..X.","..X."};
    nums[2]={"XXX.","..X.","XXX.","X...","XXX."};
    nums[3]={"XXX.","..X.","XXX.","..X.","XXX."};
    nums[4]={"X.X.","X.X.","XXX.","..X.","..X."};
    nums[5]={"XXX.","X...","XXX.","..X.","XXX."};
    nums[6]={"XXX.","X...","XXX.","X.X.","XXX."};
    nums[7]={"XXX.","..X.","..X.","..X.","..X."};
    nums[8]={"XXX.","X.X.","XXX.","X.X.","XXX."};
    nums[9]={"XXX.","X.X.","XXX.","..X.","XXX."};
    for(int i=0;i<5;i++){
        for(int j=0;j<n;j++){
            res[i].append(nums[st[j]-'0'][i]);
        }
    }
    for(int i=0;i<5;i++){
        res[i].pop_back();
        cout << res[i] << '\n';
    }
}