#include <bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(int a,int b)const{
        return abs(a)<abs(b);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    set<int,cmp> v;
    int x=100;
    v.insert(x);
    cout << *v.begin() << ' ';
    x=10;
    v.insert(x);
    cout << *v.begin() << ' ';
    x=-100;
    v.insert(x);
    cout << *v.begin() << ' ';
    x=-4;
    v.insert(x);
    cout << *v.begin() << ' ';

}