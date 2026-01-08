#include <bits/stdc++.h>
using namespace std;
int suma,j,i,op1,op2,op3,tempi,tempj;
class Solution {
public:
    int maxSumDivThree(vector<int>& nums){
        vector<int> un,dos;
        i=j=suma=0;
        for(auto u:nums){
            if(u%3==0)suma+=u;
            else if(u%3==1)un.push_back(u);
            else dos.push_back(u);
        }
        sort(un.rbegin(),un.rend());
        sort(dos.rbegin(),dos.rend());
        //vector<int> psum(dos.size());
        // 0,1,2,3,4
        for(;i+5<un.size();i+=3)suma+=un[i]+un[i+1]+un[i+2];
        for(;j+5<dos.size();j+=3)suma+=dos[j]+dos[j+1]+dos[j+2];
        op1=op2=op3=suma;
        // dos opciones, 1:usar al fondo los dos y conbi
        tempi=i,tempj=j;
        for(;tempi+2<un.size();tempi+=3)op1+=un[tempi]+un[tempi+1]+un[tempi+2];
        for(;tempj+2<dos.size();tempj+=3)op1+=dos[tempj]+dos[tempj+1]+dos[tempj+2];
        for(;tempi<un.size() && tempj<dos.size();tempi++,tempj++)op1+=un[tempi]+dos[tempj];
        // usar al fondo un y combinar
        tempi=i,tempj=j;
        for(;tempi+2<un.size();tempi+=3)op2+=un[tempi]+un[tempi+1]+un[tempi+2];
        for(;tempi<un.size() && tempj<dos.size();tempi++,tempj++)op2+=un[tempi]+dos[tempj];
        // usar al fondo dos y combinar
        tempi=i,tempj=j;
        for(;tempj+2<dos.size();tempj+=3)op3+=dos[tempj]+dos[tempj+1]+dos[tempj+2];
        for(;tempi<un.size() && tempj<dos.size();tempi++,tempj++)op3+=un[tempi]+dos[tempj];
        return max({op1,op2,op3});
    }
};