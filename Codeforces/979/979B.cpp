//In The Name of Allah
//Mon 24/2/97
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int n;
int occ[3][52];
string s[3];
int res[3];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> n;
	forar(i,3){
		cin >> s[i];
		forar(j,s[i].length()){
			res[i] = max(res[i],++occ[i][(s[i][j]-'A' < 26 ? s[i][j]-'A' : s[i][j]-'a'+26)]);
		}
	}
	int ind = 0;
	int cnt = 0;
	forar(i,3){
		if(n==1 && res[i] == s[i].length()){
			res[i]--;
		}else{
			res[i] += min(n,(int)s[i].length()-res[i]);
		}
		if(res[i] > res[ind]){
			ind = i;
			cnt = 1;
		}else if(res[i] == res[ind]){
			cnt++;
		}
	}
	if(cnt-1){
		cout << "Draw" << endl;
	}else{
		if(ind == 0){
			cout << "Kuro" << endl;
		}else if(ind == 1){
			cout << "Shiro" << endl;
		}else{
			cout << "Katie" << endl;
		}
	}
}
