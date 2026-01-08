#include <bits/stdc++.h>
using namespace std;
int n,t,p;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> p;
        vector<int> nums(n);
        set<int> conj;
        map<int,bool> exis;
        vector<pair<int,int>> comp;
        int last,nextnop1=0;
        for(int i=0;i<n;i++){
            cin >> nums[i];
            exis[nums[i]]=1;
            conj.insert(nums[i]);
        }
        last=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]!=p-1){
                nextnop1=nums[i];
                break;
            }
        }
        auto pun=conj.begin();
        int ulti=*pun,ante=ulti;
        while((++pun)!=conj.end()){
            if(*pun!=ante+1){
                comp.push_back({ulti,ante});
                ulti=*pun;
            }
            ante=*pun;
        }
        comp.push_back({ulti,*(--pun)});
        n=comp.size();
        if(comp[0].first==0 && comp[0].second==p-1){
            cout << "0\n";
        }else{
            int res=0;
            if(comp[0].first==0 && last<=comp[0].second){
                if(comp[n-1].second!=p-1)res=p-1-last;
                else res=comp[n-1].first-last-1;
            }else{
                // doy vuelta
                int inde;
                vector<pair<int,int>> nue;
                for(int i=0;i<n;i++){
                    if(comp[i].first<=last && last<=comp[i].second){
                        inde=i;
                        break;
                    }
                    nue.push_back(comp[i]);
                }
                res=p-last;
                last=0;
                nextnop1++;
                nue.push_back({comp[inde].first,p-1});
                nue.push_back({0,0});
                nue.push_back({nextnop1,nextnop1});
                sort(nue.begin(),nue.end());
                //merge
                vector<pair<int,int>> ayud;
                ayud.push_back(nue[0]);
                for(int i=1;i<nue.size();i++){
                    if(nue[i].first-1==ayud.back().second || nue[i].first<=ayud.back().second){
                        ayud.back().second=max(ayud.back().second,nue[i].second);
                    }else{
                        ayud.push_back(nue[i]);
                    }
                }
                if(ayud.size()>1){
                    res+=ayud[ayud.size()-1].first-1;
                }
            }
            cout << res << '\n';
        }
    }
}