#include <bits/stdc++.h>
using namespace std;
bool xd,xd1,xd2;
int n,m,con=0,posx=1,posy=0;
vector<pair<int,int>> res;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    cin >> n >> m;
    while(res.size()<n*m && con++<m){
        res.push_back({posx,++posy});
        if(res.size()==n*m)break;
        res.push_back({n-posx+1,m-posy+1});
    }
    int updown=n-1,leftri=m-1;
    // xd false updown xd2 false=up, xd3 false=left
    while(res.size()<n*m){
        if((xd=!xd)){
            con=0;
            while(res.size()<m*n && con++<updown-1){
                if(!xd1)posx++;
                else posx--;
                res.push_back({posx,posy});
                if(res.size()==n*m)break;
                res.push_back({n-posx+1,m-posy+1});
            }
            xd1=!xd1;
            updown-=2;
        }else{
            con=0;
            while(res.size()<m*n && con++<leftri-1){
                if(!xd2)posy--;
                else posy++;
                res.push_back({posx,posy});
                if(res.size()==n*m)break;
                res.push_back({n-posx+1,m-posy+1});
            }
            xd2=!xd2;
            leftri-=2;
        }
    }
    for(int i=0;i<res.size();i++)cout << res[i].first << ' ' << res[i].second << '\n';
}