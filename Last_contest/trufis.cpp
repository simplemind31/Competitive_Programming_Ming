//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <array>
#include <queue>
#include <stack>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m;
int main(){
	cin >> n;
	vector<vector<int>> nums(n,vector<int>(3));
	vector<int> combus(n),tiempo(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin >> nums[i][j];
		}
	}
	cin >> m;
	vector<int> ace(m);
	for(int i=0;i<m;i++){
		cin >> ace[i];
	}
	sort(ALL(ace));
	int posace=0;
	for(int i=1;i<=300;i++){
		// el tiempo que tarda en llegar al acutal
		vector<pair<int,int>> distindi(n);
		for(int j=0;j<n;j++){
			if(combus[j]){
				tiempo[j]++;
				combus[j]--;
			}else{
				tiempo[j]+=nums[j][(i-1)/100];
			}
			distindi[j]={tiempo[j],j};
		}
		if(!binary_search(ALL(ace),i))continue;
		sort(ALL(distindi));
		// no añado el rimero
		int can=0;
		for(int j=1;j<n;j++){
			if(distindi[j].first==distindi[j-1].first)can++;
			else can=0;

			if(combus[distindi[j].second])continue;
			combus[distindi[j].second]=(j-can)%20;
		}
	}
	for(int i=0;i<n;i++){
		cout << tiempo[i] << '\n';
	}
}
