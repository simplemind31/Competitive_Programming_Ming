#include <bits/stdc++.h>
using namespace std;
class Bank {
public:
    vector<long long> res;
    int n;
    Bank(vector<long long>& balance) {
        n=(res=balance).size();
    }
    bool transfer(int account1, int account2, long long money) {
        if(--account1>=n || --account2>=n)return false;
        if(res[account1]<money)return false;
        res[account1]-=money;
        res[account2]+=money;
        return true;
    }
    bool deposit(int account, long long money) {
        if(--account>=n)return false;
        res[account]+=money;
        return true;
    }
    bool withdraw(int account, long long money) {
        if(--account>=n)return false;
        if(res[account]<money)return false;
        res[account]-=money;
        return true;
    }
};