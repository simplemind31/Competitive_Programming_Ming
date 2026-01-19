#include <bits/stdc++.h>
using namespace std;
int n;
string p1,p2,when,anim,_;
unordered_map<string,int> year={{"Ox",0},{"Tiger",1},{"Rabbit",2},{"Dragon",3},{"Snake",4},{"Horse",5},{"Goat",6},{"Monkey",7},{"Rooster",8},{"Dog",9},{"Pig",10},{"Rat",11}};
unordered_map<string,pair<string,int>> edad={{"Bessie",{"Ox",0}}};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> p1 >> _ >> _ >> when >> anim >> _ >> _ >> p2;
        if(when=="previous"){
            int ed=year[edad[p2].first]-year[anim];
            if(ed<=0)ed+=12;
            ed=edad[p2].second-ed;
            edad[p1]={anim,ed};
        }else{
            int ed=-year[edad[p2].first]+year[anim];
            if(ed<=0)ed+=12;
            ed=edad[p2].second+ed;
            edad[p1]={anim,ed};
        }
        if(p1=="Elsie"){
            cout << abs(edad[p1].second);
            return 0;
        }
    }
}