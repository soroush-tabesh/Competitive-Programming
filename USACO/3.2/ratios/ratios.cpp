//In The Name of God
/*
ID: soroosh4
LANG: C++11
TASK: ratios
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("ratios.in","r",stdin),freopen("ratios.out","w",stdout)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;
const int M = 100*1000+5;

void Solution();

int rat[4][3];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	forar(i,4){
		forar(j,3){
			cin >> rat[i][j];			
		}
	}
	int ans[4] = {101,101,101,101};
	int mul[3] = {0,0,0};
	for(;mul[0] <= 100;mul[0]++){
		for(;mul[1] <= 100;mul[1]++){
			for(;mul[2] <= 100;mul[2]++){
				int res[3] = {0,0,0};
				fori(i,1,4){
					forar(j,3){
						res[j] += rat[i][j] * mul[i-1];
					}
				}
				int ratio = res[0]/rat[0][0];
				if(res[0] == ratio*rat[0][0] && res[1] == ratio*rat[0][1] && res[2] == ratio*rat[0][2] && (mul[0] || mul[1] || mul[2]) && ratio < ans[3]){
					//cout << res[0] << " " << res[1] << " " << res[2] << "  ratio :  " << mul[0] << " " << mul[1] << " " << mul[2] << endl;
					ans[0] = mul[0];
					ans[1] = mul[1];
					ans[2] = mul[2];
					ans[3] = ratio;
				}
			}
			mul[2] = 0;
		}
		mul[1] = 0;
	}
	if(ans[0] == 101){
		cout << "NONE";
	}else{
		forar(i,4){
			if(i)
				cout << ' ';
			cout << ans[i];
		}		
	}
	cout << endl;
}
