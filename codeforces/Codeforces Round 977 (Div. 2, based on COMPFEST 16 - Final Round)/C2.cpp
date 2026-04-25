#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,q,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m >> q;
        int ord[n+2],nums[m+n+2];
        nums[0]=ord[0]=0;
        nums[m+n+1]=ord[n+1]=n+1;
        for(int i=1;i<=n;i++){
            cin >> a;
            ord[a]=i;
        }
        for(int i=1;i<=m;i++){
            cin >> nums[i];
            nums[i]=ord[nums[i]];
        }
        for(int i=m+1;i<=m+n;i++)nums[i]=i-m;
        set<int> ocurrencias[n+2];
        int canerror=0;
        set<pair<int,int>> primero;
        for(int i=0;i<=m+n+1;i++){
            if(ocurrencias[nums[i]].empty()){
                primero.insert({i,nums[i]});
            }
            ocurrencias[nums[i]].insert(i);
        }
        for(int i=1;i<=n+1;i++){
            int pos=*ocurrencias[i].begin();
            auto p=primero.lower_bound({pos,i});
            auto ante=prev(p);
            if(ante->second!=i-1)canerror++;          
        }
        //cout << canerror << '\n';
        /*for(int i=0;i<=m+n+1;i++)cout << nums[i] << ' ';
        cout << endl;*/
        if(canerror)cout << "TIDAK\n";
        else cout << "YA\n";
        //cout << canerror << '\n';
        while(q--){
            cin >> a >> b;
            b=ord[b];
            // cambiar la posicion del a a b
            // primero quitamos
            int pos=*ocurrencias[nums[a]].begin();
            if(pos!=a){
                // no afecta si quito nums[a]
                ocurrencias[nums[a]].erase(a);
                if(a<*ocurrencias[b].begin()){
                    // afecta si añado b
                    // el antiguo b se convierte a nuevo 
                    // quitar
                    int pos=*ocurrencias[b].begin();
                    auto p=primero.lower_bound({pos,b});
                    auto ante=prev(p),desp=next(p);
                    if(ante->second==b-1)canerror++;
                    if(desp->second==b+1)canerror++;
                    if(ante->second==desp->second-1)canerror--;
                    // añadir
                    primero.erase(p);
                    ocurrencias[b].insert(a);
                    pos=*ocurrencias[b].begin();
                    primero.insert({pos,b});
                    p=primero.lower_bound({pos,b});
                    ante=prev(p);
                    desp=next(p);
                    if(ante->second==desp->second-1)canerror++;
                    if(ante->second==b-1)canerror--;
                    if(desp->second==b+1)canerror--;
                }else{
                    // no afecta si añado b
                    ocurrencias[b].insert(a);
                }
            }else{
                // si afecta si quito nums[a]
                // el antiguo nums[a] se convierte a nuevo 
                // quitar
                int pos=*ocurrencias[nums[a]].begin();
                auto p=primero.lower_bound({pos,nums[a]});
                auto ante=prev(p),desp=next(p);
                if(ante->second==nums[a]-1)canerror++;
                if(desp->second==nums[a]+1)canerror++;
                if(ante->second==desp->second-1)canerror--;
                // añadir
                primero.erase(p);
                ocurrencias[nums[a]].erase(a);
                pos=*ocurrencias[nums[a]].begin();
                primero.insert({pos,nums[a]});
                p=primero.lower_bound({pos,nums[a]});
                ante=prev(p);
                desp=next(p);
                if(ante->second==desp->second-1)canerror++;
                if(ante->second==nums[a]-1)canerror--;
                if(desp->second==nums[a]+1)canerror--;
                if(a<*ocurrencias[b].begin()){
                    // afecta si añado b
                    pos=*ocurrencias[b].begin();
                    p=primero.lower_bound({pos,b});
                    ante=prev(p);
                    desp=next(p);
                    if(ante->second==b-1)canerror++;
                    if(desp->second==b+1)canerror++;
                    if(ante->second==desp->second-1)canerror--;
                    // añadir
                    primero.erase(p);
                    ocurrencias[b].insert(a);
                    pos=*ocurrencias[b].begin();
                    primero.insert({pos,b});
                    p=primero.lower_bound({pos,b});
                    ante=prev(p);
                    desp=next(p);
                    if(ante->second==desp->second-1)canerror++;
                    if(ante->second==b-1)canerror--;
                    if(desp->second==b+1)canerror--;
                }else{
                    // no afecta si añado b
                    ocurrencias[b].insert(a);
                }
            }
            nums[a]=b;
            if(canerror)cout << "TIDAK\n";
            else cout << "YA\n";
        }
    }
}
/*
3 1 4 2
3 1 1 2 3 4
1 2 2 4 1 3 5
1 2 4 3 5

3->3
*/