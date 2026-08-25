#include <bits/stdc++.h>
using namespace std;
int n,x,maxi,now;
struct node{
    node *hij[2];
    node(){hij[0]=hij[1]=nullptr;}
};
node *raiz;
void almacenar(int x){
    node *temp=raiz;
    for(int i=31;i>=0;i--){
        if(!temp->hij[(x&(1<<i))>0])temp->hij[(x&(1<<i))>0]=new node();
        temp=temp->hij[(x&(1<<i))>0];
    }
}
int buscar(int x){
    int res=0;
    node *temp=raiz;
    for(int i=31;i>=0;i--){
        if(temp->hij[!(x&(1<<i))]){
            res|=1<<i;
            temp=temp->hij[!(x&(1<<i))];
        }else temp=temp->hij[!!(x&(1<<i))];
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    raiz=new node();
    almacenar(0);
    for(int i=0;i<n;i++){
        cin >> x;
        now^=x;
        maxi=max(maxi,buscar(now));
        almacenar(now);
    }
    cout << maxi;
}