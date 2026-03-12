#include <bits/stdc++.h>
using namespace std;
int main(){
    int produ=0,a,b;
    cin >> a >> b;
    while(a>1){
        if(a&1)produ+=b;
        b*=2;
        a/=2;
    }
    produ+=b;
    cout << produ;
}
/*
3,7 

3 7 g
3 6 g
3 5 g
3 4 p
3 3 g
3 2 g
3 1 g
3 0 p


2 7 g
2 6 p
2 5 g
2 4 g
2 3 g
2 2 p
2 1 g
2 0 g


1 7 g
1 6 g
1 5 p
1 4 g
1 3 g
1 2 g
1 1 p
1 0 g

0 7 g
0 6 g
0 5 g
0 4 p
0 3 g
0 2 g
0 1 g
0,0 p
*/