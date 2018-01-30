//In The Name of Allah
//Fri 6/11/96
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

int lps[M*5];

int main()
{
	Init;
	int _t;
	cin >> _t;
	while(_t--)
		Solution();
	return 0;
}

void Solution(){
	string s,t;
	cin >> s >> t;
	int len = 0;
	lps[0] = 0; // lps[last_index] = lps_length
	fori(i,1,t.length()){
		lps[i] = 0;
		while(len > 0 && t[i] != t[len]){
			len = lps[len-1];
		}
		if(t[i] == t[len]){
			lps[i] = ++len;
		}
	}
	int j = 0;
	vector<int> anslist;
	forar(i,s.length()){
		while(j>0 && s[i] != t[j])
			j = lps[j-1];
		if(s[i] == t[j])
			j++;
		if(j == t.length())
			j = lps[j-1],anslist.pb(i+2-t.length());
	}
	if(anslist.empty()){
		cout << "Not Found" << endl << endl;
	}else{
		cout << anslist.size() << endl;
		for(int x : anslist){
			cout << x << " ";
		}
		cout << endl << endl;
	}
}
