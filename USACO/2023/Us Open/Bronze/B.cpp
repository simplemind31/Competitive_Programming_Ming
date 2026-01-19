#include <bits/stdc++.h>
using namespace std;
int t,n,c,p;
string st,ty;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> c >> p;
        vector<string> words[4];
        while(n--){
            cin >> st >> ty;
            if(ty=="noun")words[0].push_back(st);
            else if(ty=="transitive-verb")words[1].push_back(st);
            else if(ty=="intransitive-verb")words[2].push_back(st);
            else words[3].push_back(st);
        }
        int maxi=0,posi,posj;
        for(int i=0;i<=words[2].size();i++){
            for(int j=0;j<=words[1].size();j++){
                if(i+2*j>words[0].size())continue;
                int numwo=2*i+3*j;
                int numsent=i+j;
                if(j)numwo+=min((int)words[0].size()-i-2*j,c);
                numwo+=min(numsent/2,(int)words[3].size());
                numsent-=min(numsent/2,(int)words[3].size());
                if(numsent>p)continue;
                if(numwo>maxi){
                    maxi=numwo;
                    posi=i;
                    posj=j;
                }
            }
        }
        if(maxi==0){
            cout << "0\n\n";
            continue;
        }
        cout << maxi << '\n';
        //cout << posi << ' ' << posj << '\n';
        vector<string> simpsent,compsent;
        for(int i=0;i<posi;i++){
            simpsent.push_back(words[0].back()+' '+words[2].back());
            words[0].pop_back();
            words[2].pop_back();
        }
        for(int j=0;j<posj;j++){
            string now=words[0].back()+' '+words[1].back()+' ';
            words[0].pop_back();
            words[1].pop_back();
            now+=words[0].back();
            words[0].pop_back();
            simpsent.push_back(now);
        }
        if(posj){
            while(c-- && !words[0].empty()){
                simpsent.back().append(", "+words[0].back());
                words[0].pop_back();
            }
        }
        while(!words[3].empty() && simpsent.size()>1){
            string s=simpsent.back()+' '+words[3].back()+' ';
            words[3].pop_back();
            simpsent.pop_back();
            s.append(simpsent.back());
            simpsent.pop_back();
            compsent.push_back(s);
        }
        if(compsent.empty()){
            cout << simpsent.back() << '.';
            simpsent.pop_back();
        }else{
            cout << compsent.back() << '.';
            compsent.pop_back();
        }
        while(!compsent.empty()){
            cout << ' ' << compsent.back() << '.';
            compsent.pop_back();
        }
        while(!simpsent.empty()){
            cout << ' ' << simpsent.back() << '.';
            simpsent.pop_back();
        }
        cout << '\n';
    }
}