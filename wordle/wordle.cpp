#include <bits/stdc++.h>
using namespace std;
int pregunta;
string st,answer,prime="serai";
vector<string> tot,rango;
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    ifstream fin1("words5.txt");
    ifstream fin2("target.txt");
    while(fin1 >> st)tot.push_back(st);
    while(fin2 >> st)rango.push_back(st);
    //preguntar primero raise
    cout << prime << '\n';
    cin >> answer;
    // cuantos encajan?
    vector<string> nue;
    for(int j=0;j<rango.size();j++){
        string temp=rango[j];
        string tempres(5,' ');
        for(int k=0;k<5;k++){
            if(temp[k]==prime[k]){
                tempres[k]='2';
                temp[k]=' ';
            }
        }
        for(int k=0;k<5;k++){
            if(tempres[k]=='2')continue;
            if(temp.find(prime[k])!=-1){
                tempres[k]='1';
                temp[temp.find(prime[k])]=' ';
            }else tempres[k]='0';
        }
        if(answer==tempres)nue.push_back(rango[j]);
    }
    rango=nue;
    nue.clear();
    while(rango.size()>1){
        int mini=1e9;
        for(int i=0;i<rango.size();i++){
            // que pasa si uso este 
            string now=rango[i];
            map<int,int> con;
            for(int j=0;j<rango.size();j++){
                // si la respuesta es j
                string temp=rango[j];
                string tempres(5,' ');
                for(int k=0;k<5;k++){
                    if(temp[k]==now[k]){
                        tempres[k]='2';
                        temp[k]=' ';
                    }
                }
                for(int k=0;k<5;k++){
                    if(tempres[k]=='2')continue;
                    if(temp.find(now[k])!=-1){
                        tempres[k]='1';
                        temp[temp.find(now[k])]=' ';
                    }else tempres[k]='0';
                }
                con[stoi(tempres)]++;
            }
            int maxi=0;
            for(auto u:con){
                maxi=max(maxi,u.second);
            }
            if(maxi<mini){
                mini=maxi;
                prime=rango[i];
                //cout << i << ' ' << mini << ' ' << rango[i] << '\n';
            }
        }
        for(int i=0;i<tot.size();i++){
            // que pasa si uso este 
            string now=tot[i];
            map<int,int> con;
            for(int j=0;j<rango.size();j++){
                // si la respuesta es j
                string temp=rango[j];
                string tempres(5,' ');
                for(int k=0;k<5;k++){
                    if(temp[k]==now[k]){
                        tempres[k]='2';
                        temp[k]=' ';
                    }
                }
                for(int k=0;k<5;k++){
                    if(tempres[k]=='2')continue;
                    if(temp.find(now[k])!=-1){
                        tempres[k]='1';
                        temp[temp.find(now[k])]=' ';
                    }else tempres[k]='0';
                }
                con[stoi(tempres)]++;
            }
            int maxi=0;
            for(auto u:con){
                maxi=max(maxi,u.second);
            }
            if(maxi<mini){
                mini=maxi;
                prime=tot[i];
                //cout << i << ' ' << mini << ' ' << rango[i] << '\n';
            }
        }
        cout << prime << '\n';
        cin >> answer;
        if(answer=="show"){
            cout << "===========\n";
            for(auto u:rango){
                cout << u << '\n';
            }
            cout << "===========\n";
            cin >> answer;
        }
        vector<string> nue;
        for(int j=0;j<rango.size();j++){
            string temp=rango[j];
            bool xd=true;
            string tempres(5,' ');
            for(int k=0;k<5;k++){
                if(temp[k]==prime[k]){
                    tempres[k]='2';
                    temp[k]=' ';
                }
            }
            for(int k=0;k<5;k++){
                if(tempres[k]=='2')continue;
                if(temp.find(prime[k])!=-1){
                    tempres[k]='1';
                    temp[temp.find(prime[k])]=' ';
                }else tempres[k]='0';
            }
            if(answer==tempres)nue.push_back(rango[j]);
        }
        rango=nue;
    }
    cout << rango[0];
    // si la respuesta es x, pregunto y, cuanto posibles me queda?
}
/*
193 1300 aesir
837 1235 arles
2402 1221 canes
2445 1190 cares
4322 1104 earls
9449 1089 nares
11229 833 raise
NOTCH
*/