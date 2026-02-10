#include <bits/stdc++.h>
using namespace std;
int nums[10],al,con;
int main(){
    for(int i=0;i<10;i++)cin >> nums[i];
    cin >> al;
    al+=30;
    for(int i=0;i<10;i++)con+=nums[i]<=al;
    cout << con;
}