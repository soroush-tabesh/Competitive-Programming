//In The Name of Allah
//Sun 26/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e2+5;

void Solution();

list<char> ans;
bool vow[256];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	string s;
	cin >> s;
	vow['a'] = vow['e'] = vow['i'] = vow['o'] = vow['u'] = 1;
	forar(i,s.size()){
		ans.pb(s[i]);
	}
	char lst = *(ans.begin());
	int cntbl = 0;
	int cnteq = 1;
	if(!vow[lst])
		cntbl++;
	for(list<char>::iterator it = next(ans.begin());it != ans.end();it++){
		if(*it == lst){
			cnteq++;
		}else{
			cnteq = 1;
		}
		if(!vow[*it]){
			cntbl++;
		}else{
			cntbl = 0;
		}
		if(cntbl > 2 && cnteq < 3){
			cntbl = 0;
			if(!vow[*it]){
				cntbl++;
			}
			cnteq = 1;
			ans.insert(it,' ');
		}
		lst = *it;
	}
	for(list<char>::iterator it = ans.begin();it != ans.end();it++){
		cout << *it;
	}
	cout << endl;
}
