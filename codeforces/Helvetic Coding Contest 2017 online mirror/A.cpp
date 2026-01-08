#include <bits/stdc++.h>
using namespace std;
int n,k,con,a,cantiusado;
vector<int> aparece[400000];
int index[400000];
bitset<400000> usando;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
        aparece[--nums[i]].push_back(i);
    }
    for(int i=n;i<2*n;i++){
        aparece[i-n].push_back(i);
    }
    set<pair<int,int>> ayuda;
    //ulti,numero
    for(int i=0;i<n;i++){
        if(usando[nums[i]]){
            ayuda.erase({aparece[nums[i]][index[nums[i]]],nums[i]});
            index[nums[i]]++;
            ayuda.insert({aparece[nums[i]][index[nums[i]]],nums[i]});
            continue;
        }else if(ayuda.size()<k){
            index[nums[i]]++;
            usando[nums[i]]=true;
            ayuda.insert({aparece[nums[i]][index[nums[i]]],nums[i]});
            con++;
            continue;
        }
        auto p=ayuda.end();
        p--;
        usando[p->second]=false;
        usando[nums[i]]=true;
        con++;
        ayuda.erase(p);
        index[nums[i]]++;
        ayuda.insert({aparece[nums[i]][index[nums[i]]],nums[i]});
    }
    cout << con;
}