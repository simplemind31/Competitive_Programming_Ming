#include <bits/stdc++.h>
using namespace std;
pair<int,int> operator+(pair<int,int> a,pair<int,int> b){return {a.first+b.first,a.second+b.second};}
pair<int,int> operator*(int a,pair<int,int> b){return {a*b.first,a*b.second};}
class Robot {
public:
    string dir[4]={"East","North","West","South"};
    pair<int,int> directions[4]={{1,0},{0,1},{-1,0},{0,-1}};
    int acum=0,W,H,d=0;
    pair<int,int> pos={0,0};
    int val(pair<int,int> a){
        return max(0,0-a.first)+max(0,a.first-(W-1))+max(0,0-a.second)+max(0,a.second-(H-1));
    }
    void adjust(){
        if(acum>=2*W+2*H-4){
            acum%=(2*W+2*H-4);
            if(pos==make_pair(0,0))d=3;
            else if(pos==make_pair(W-1,0))d=0;
            else if(pos==make_pair(W-1,H-1))d=1;
            else if(pos==make_pair(0,H-1))d=2;
        }
        // mover acum
        while(acum){
            int temp=val(pos+acum*directions[d]);
            pos=pos+(acum-temp)*directions[d];
            acum=temp;
            if(temp==0)break;
            d=(d+1)%4;
        }
    }
    Robot(int width, int height){
        // 2*witdh+2*height-4;
        W=width;
        H=height;
    }
    void step(int num){acum+=num;}
    vector<int> getPos(){
        adjust();
        return {pos.first,pos.second};
    }
    string getDir() {
        adjust();
        return dir[d];
    }
};