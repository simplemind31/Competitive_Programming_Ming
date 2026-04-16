#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
//const int raiz=448;
bitset<200001> res;
bitset<2000001> contador;
int n,q,a,b,con,nums[200001],raiz;
vector<pair<pair<int,int>,int>> blocks[10000];
bool cmp(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y){
    if(x.first.second==y.first.second)return x.first.first<=y.first.first;
    return x.first.second<y.first.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    raiz=500;
    for(int i=0;i<n;i++)cin >> nums[i];
    for(int i=0;i<q;i++){
        cin >> a >> b;
        a--;b--;
        blocks[a/raiz].push_back({{a,b},i});
    }
    // par no,impar gano siempre
    for(int i=0;i<raiz;i++){
        sort(ALL(blocks[i]),cmp);
        int last=(i+1)*raiz-1;
        for(auto u:blocks[i]){
            if(u.first.second/raiz==i){
                // dentro del bloque
                for(int j=u.first.first;j<=u.first.second;j++){
                    contador[nums[j]]=!contador[nums[j]];
                    if(contador[nums[j]])con++;
                    else con--;
                }
                if(con)res[u.second]=1;
                for(int j=u.first.first;j<=u.first.second;j++){
                    contador[nums[j]]=!contador[nums[j]];
                    if(contador[nums[j]])con++;
                    else con--;
                }
                continue;
            }
            while(last<u.first.second){
                last++;
                contador[nums[last]]=!contador[nums[last]];
                if(contador[nums[last]])con++;
                else con--;
            }
            // persist
            for(int j=(i+1)*raiz-1;j>=u.first.first;j--){
                contador[nums[j]]=!contador[nums[j]];
                if(contador[nums[j]])con++;
                else con--;
            }
            if(con)res[u.second]=1;
            for(int j=(i+1)*raiz-1;j>=u.first.first;j--){
                contador[nums[j]]=!contador[nums[j]];
                if(contador[nums[j]])con++;
                else con--;
            }
            //rollback
        }
        //rollback
        con=0;
        contador=0;
    }
    for(int i=0;i<q;i++){
        if(res[i])cout << "NO\n";
        else cout << "SI\n";
    }
}