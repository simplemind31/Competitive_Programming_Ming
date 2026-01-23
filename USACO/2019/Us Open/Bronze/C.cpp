#include <bits/stdc++.h>
using namespace std;
bool existcar[25][630];
int n,k,now=1;
vector<int> characow[25],padres[630];
string st;
map<string,int> chara;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("evolution.in","r",stdin);
    freopen("evolution.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> k;
        for(int j=0;j<k;j++){
            cin >> st;
            if(chara[st]==0)chara[st]=now++;
            existcar[i][chara[st]]=true;
            characow[i].push_back(chara[st]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<characow[i].size();k++){
                for(int l=0;l<characow[i].size();l++){
                    //si j tiene k pero no l entonces k es padre de l
                    if(existcar[j][characow[i][k]] && !existcar[j][characow[i][l]]){
                        padres[characow[i][l]].push_back(characow[i][k]);
                    }else if(!existcar[j][characow[i][k]] && existcar[j][characow[i][l]]){
                        padres[characow[i][k]].push_back(characow[i][l]);
                    }
                }
            }
        }
    }
    // existe algun caso que aparece el hijo pero no padre?
    for(int i=0;i<n;i++){
        for(int j=0;j<characow[i].size();j++){
            for(auto u:padres[characow[i][j]]){
                if(!existcar[i][u]){
                    cout << "no";
                    return 0;
                }
            }
        }
    }
    cout << "yes";
}