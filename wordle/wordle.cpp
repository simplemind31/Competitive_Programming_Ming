#include <bits/stdc++.h>
using namespace std;
int pregunta;
string st,answer;
bool imposi[5][26];
int asegu[5];
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    memset(asegu,-1,sizeof(asegu));
    freopen("words5.txt","r",stdin);
    vector<string> tot,rango;
    while(cin >> st)tot.push_back(st);
    rango=tot;
    //preguntar primero raise
    string prime="raise";
    /*cout << prime << '\n';
    cin >> answer;
    // cuantos encajan?
    for(int j=0;j<tot.size();j++){
        string temp=tot[j];
        bool xd=true;
        for(int k=0;k<5;k++){
            if(answer[k]=='2'){
                xd=prime[k]==temp[k];

            }else if(answer[k]=='0'){
                xd=temp.find(prime[k])==-1;
            }
        }
    }*/
    while(pregunta++<5){
        int mini=1e9;
        int pos=0;
        //3294
        for(int i=0;i<tot.size();i++){
            if(i%50==0){
                cout << i << '\n';
            }
            // que pasa si uso este 
            string now=tot[i];
            map<vector<int>,int> con;
            for(int j=0;j<tot.size();j++){
                // si la respuesta es j
                string temp=tot[j];
                vector<int> tempres(5,-1);
                for(int k=0;k<5;k++){
                    if(temp[k]==now[k]){
                        tempres[k]=2;
                        temp[k]=' ';
                    }
                }
                for(int k=0;k<5;k++){
                    if(tempres[k]==2)continue;
                    if(temp.find(now[k])!=-1){
                        tempres[k]=1;
                        temp[temp.find(now[k])]=' ';
                    }else tempres[k]=0;
                }
                con[tempres]++;
            }
            int maxi=0;
            for(auto u:con){
                maxi=max(maxi,u.second);
            }
            if(maxi<mini){
                mini=maxi;
                cout << i << ' ' << mini << ' ' << tot[i] << '\n';
            }
        }
        break;
    }
    // si la respuesta es x, pregunto y, cuanto posibles me queda?
}
//carse 1190
//earls 1104
//lares 1104
//nares 1089
//raise 11230 833

/*
slate 12785->1438
crane 3249->1711
salet 11956->1196
arose 854->1376
tales 13783->1196
*/