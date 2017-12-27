//In The Name of Allah
//Thu 30/9/96
#include <vector>
#include <utility>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define F first
#define S second
#define pb push_back

using namespace std;

int n;
vector<pair<int,int> > data;

int m_comp(pair<int,int>  a,pair<int,int>  b,pair<int,int>  c){
	return (((b.F-a.F)*(c.S - a.S))-((c.F-a.F)*(b.S - a.S)));
}

int m_dist(pair<int,int>  a,pair<int,int>  b){
	return (((a.S-b.S)*(a.S-b.S))+((a.F-b.F)*(a.F-b.F)));
}

bool cmp(pair<int,int>  a,pair<int,int>  b){
	return ((a.F < b.F)||(a.F==b.F && a.S < b.S));
}

void Solution(){
	cin >> n;
	for(int i = 0;i < n;i++){
		pair<int,int> kk;
		cin >> kk.F >> kk.S;
		data.pb(kk);
	}
	sort(data.begin(),data.end(),cmp);
	if(n <= 2){
		for(int i = 0;i < n;i++){
			cout << data[i].F << " " << data[i].S;
			if(i != n-1)
				cout << endl;
		}
		return;
	}
	vector<int> ans;
	ans.pb(0);
	int ind1=1,ind2=0;
	for(int k = 0;k < n;k++){
		for(int i = 0;i < n;i++){
			if(i == ind2){
				continue;
			}
			if(m_comp(data[ind2],data[ind1],data[i]) < 0){
				ind1=i;
			}else if(m_comp(data[ind2],data[ind1],data[i]) == 0){
				if(m_dist(data[ind2],data[i]) > m_dist(data[ind2],data[ind1])){
					ind1=i;
				}else if(m_dist(data[ind2],data[i]) == m_dist(data[ind2],data[ind1])){
					if(i > ind1)
						ind1 = i;
				}
			}
		}
		if(ind1 != 0){
			ans.pb(ind1);
			ind2 = ind1;
			ind1=0;
		}else{
			break;
		}
	}
	for(int i = 0;i < ans.size();i++){
		cout << data[ans[i]].F << " " << data[ans[i]].S;
		if(i!=(ans.size()-1))
			cout << endl;
	}
	
	
}

int32_t main()
{
	Solution();
	return 0;
}
