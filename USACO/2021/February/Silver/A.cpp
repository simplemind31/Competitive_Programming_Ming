#include <bits/stdc++.h>
using namespace std;
int n,a,b,con;
bitset<3000> cow[3000];
bool comfort(int x,int y){return cow[x-1][y]+cow[x+1][y]+cow[x][y-1]+cow[x][y+1]==3;}
void add(int x,int y);
void fill(int x,int y);
void fill(int x,int y){
    //if(visited[x][y])return;
    if(!cow[x-1][y])add(x-1,y);
    else if(!cow[x+1][y])add(x+1,y);
    else if(!cow[x][y-1])add(x,y-1);
    else add(x,y+1);
}
void add(int x,int y){
    if(cow[x][y])return;
    con++;
    cow[x][y]=true;
    if(comfort(x,y))fill(x,y);
    if(cow[x-1][y] && comfort(x-1,y))fill(x-1,y);
    if(cow[x+1][y] && comfort(x+1,y))fill(x+1,y);
    if(cow[x][y-1] && comfort(x,y-1))fill(x,y-1);
    if(cow[x][y+1] && comfort(x,y+1))fill(x,y+1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        a+=1500;b+=1500;
        add(a,b);
        con--;
        cout << con << '\n';
    }
}