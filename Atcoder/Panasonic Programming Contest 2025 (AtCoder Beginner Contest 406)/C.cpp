#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    vector<pair<int,int>> pare;
    //<><>
    vector<int> pe,gr;
    for(int i=0;i<n-1;i++){
        if(nums[i]<nums[i+1])pe.push_back(i);
        else gr.push_back(i);
    }
    gr.push_back(n-1);
    for(int i=0;i<n-1;i++){
        if(nums[i]>nums[i+1])continue;
        //<
        int pos=lower_bound(ALL(gr),i)-gr.begin();
        if(pos==gr.size())continue;
        //<>
        pos=lower_bound(ALL(pe),gr[pos])-pe.begin();
        if(pos==pe.size())continue;
        //<><
        int nue=lower_bound(ALL(gr),pe[pos])-gr.begin();
        if(nue==gr.size())continue;
        //<><>
        res+=(gr[nue]-pe[pos]);
    }
    cout << res;
}