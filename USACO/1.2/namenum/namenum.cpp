/*
ID: soroosh4
LANG: C++11
TASK: namenum
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("namenum.in","r",stdin),freopen("namenum.out","w",stdout)
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

ll n;
map<ll,vector<string> > dict;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	ifstream fin;
	fin.open("dict.txt");
	while(!fin.eof()){
		string s;
		getline(fin,s);
		ll id = 0;
		forar(j,s.length()){
			if((s[j]-65-(s[j]>=81))/3+2 > 9 || (s[j]==81)){
				id = 0;
				break;
			}
			id += (s[j]-65-(s[j]>=81))/3+2;
			id *= 10;
		}
		id/=10;
		if(id)
			dict[id].pb(s);
	}
	if(dict[n].size()){
		forar(i,dict[n].size()){
			cout << dict[n][i] << '\n';
		}
	}else{
		cout << "NONE\n";
	}
	
}
