//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;

void Solution();

int n;
ll sumglob;
multiset<ll> numsl,numsr;
ll seq[100*1000];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> seq[i];
		numsr.insert(seq[i]);
		sumglob += seq[i];
	}
	if(sumglob % 2 == 1){
		cout << "NO";
		return;
	}
	
	ll sumcur = 0;
	forar(i,n){
		sumcur += seq[i];
		numsl.insert(seq[i]);
		numsr.erase(numsr.find(seq[i]));
		
		ll dif = sumglob;
		dif = dif - sumcur;
		dif = dif - sumcur;
		
		if(dif % 2 != 0)
			continue;
		
		if(dif == 0){
			cout << "YES";
			return;
		}
		
		if(dif < 0){
			dif = -dif;
			dif = dif / 2;
			if(numsl.find(dif) != numsl.end()){
				cout << "YES";
				return;
			}
		}else{
			dif = dif / 2;
			if(numsr.find(dif) != numsr.end()){
				cout << "YES";
				return;
			}
		}
	}
	
	cout << "NO";
}