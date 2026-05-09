//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
string st;
string operator+(string x,string y){
	reverse(ALL(y));
	reverse(ALL(x));
	while(y.size()<x.size())y.push_back('0');
	while(x.size()<y.size())x.push_back('0');
	string res="";
	bool sobra=false;
	for(int i=0;i<x.size();i++){
		int digi=x[i]-'0'+y[i]-'0'+sobra;
		sobra=false;
		res.push_back(digi%10+'0');
		sobra=digi/10;
	}
	if(sobra)res.push_back('1');
	reverse(ALL(res));
	return res;
}
string operator*(string& x,int y){
	string res="";
	reverse(ALL(x));
	int sobra=0;
	int n=x.size();
	for(int i=0;i<n;i++){
		int digi=y*(x[i]-'0')+sobra;
		sobra=0;
		res.push_back(digi%10+'0');
		sobra=digi/10;
	}
	if(sobra)res.push_back(sobra+'0');
	reverse(ALL(res));
	return res;
}
int main(){
	cin >> st;
	pair<string,string> res={"1","1"};
	for(auto u:st){
		if(u=='P')continue;
		if(u=='L')res.first=res.first*2;
		else if(u=='R')res.first=(res.first*2+res.second);
		else{
			res.first=(res.first*5+res.second);
			res.second=res.second*3;
		}
	}
	cout << res.first;
}
	
