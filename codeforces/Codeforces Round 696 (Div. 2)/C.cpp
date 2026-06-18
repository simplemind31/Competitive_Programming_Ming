#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        n*=2;
        int nums[n];
        for(int i=0;i<n;i++)cin >> nums[i];
        sort(nums,nums+n);
        //1,2,4,4,5,5
        // si la primera suma no es el maximo, entonces el nuevo x va a ser <maximo por lo que es imposible
        /*
        -> el maximo numero siempre está involucrado en la primera suma
        y ese maximo sera el nuevo x para la siguiente ronda
        // supongamos que tengo x fixed tengo que elegir el maximo numero que sobra con el complemento
        */
        bool lol=false;
        for(int i=0;i<n-1 && !lol;i++){
            // supongamos que x=nums[i]+nums[n-1]
            int x=nums[n-1];
            vector<pair<int,int>> operaciones;
            operaciones.push_back({nums[i],nums[n-1]});
            multiset<int> disponibles;
            for(int j=0;j<n-1;j++){
                if(j==i)continue;
                disponibles.insert(nums[j]);
            }
            bool xd=true;
            while(!disponibles.empty()){
                auto p=disponibles.lower_bound(x-*prev(disponibles.end()));
                if(p==disponibles.end() || x-*prev(disponibles.end())!=*p || p==prev(disponibles.end())){
                    xd=false;
                    break;
                }
                x=*prev(disponibles.end());
                operaciones.push_back({*p,*prev(disponibles.end())});
                disponibles.erase(p);
                disponibles.erase(prev(disponibles.end()));
            }
            if(xd){
                cout << "YES\n" << operaciones[0].first+operaciones[0].second << '\n';
                for(auto u:operaciones){
                    cout << u.first << ' ' << u.second << '\n';
                }
                lol=true;
            }
        }
        if(!lol){
            cout << "NO\n";
        }
    }
}