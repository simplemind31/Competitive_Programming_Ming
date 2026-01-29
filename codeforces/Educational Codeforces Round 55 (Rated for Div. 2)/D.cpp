#include <bits/stdc++.h>
using namespace std;
int n,last=-1,nums[500],con,dia;
vector<pair<int,int>> res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<pair<int,int>> sobra;
    vector<int> uno;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        if(nums[i]>1 && last==-1)last=i;
        else if(nums[i]>1){
            res.push_back({last,i});
            nums[i]--;
            nums[last]--;
            if(nums[last])sobra.push_back({nums[last],last});
            con+=nums[last];
            last=i;
        }else{
            uno.push_back(i);
        }
    }
    dia=res.size();
    if(last!=-1){
        sobra.push_back({nums[last],last});
        con+=nums[last];
    }
    if(con<uno.size()){
        cout << "NO";
        return 0;
    }
    // uno a cada extremo
    if(uno.size()){
        res.push_back({uno.back(),sobra[0].second});
        dia++;
        sobra[0].first--;
        uno.pop_back();
    }
    if(uno.size()){
        res.push_back({uno.back(),sobra.back().second});
        dia++;
        if(--sobra.back().first==0)sobra.pop_back();
        uno.pop_back();
    }
    while(uno.size()){
        res.push_back({uno.back(),sobra.back().second});
        if(--sobra.back().first==0)sobra.pop_back();
        uno.pop_back();
    }
    cout << "YES " << dia << '\n';
    cout << res.size() << '\n';
    for(auto u:res)cout << u.first+1 << ' ' << u.second+1 << '\n';
}