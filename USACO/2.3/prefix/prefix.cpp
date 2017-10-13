/*
ID: soroosh4
LANG: C++11
TASK: prefix
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("prefix.in","r",stdin),freopen("prefix.out","w",stdout)
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

vector<string> prim;
string seq;
bool mark[200*1000+5];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	string s;
	cin >> s;
	while(s != "."){
		string t = s;
		prim.pb(t);
		cin >> s;
	}
	string line;
	while(getline(cin,line)){
		seq += line;
	}
	int m_max = -1;
	forar(i,seq.length()){
		// check if we can extend
		for(string p : prim){
			if(p.length() <= i){
				if((seq.compare(i - p.length()+1,p.length(),p) == 0) && mark[i-p.length()]){
					mark[i] = 1;
					m_max = max(m_max,i);
				}
			}else if(p.length() == i+1){
				if(seq.compare(0,p.length(),p) == 0){
					mark[i] = 1;
					m_max = max(m_max,i);
				}
			}
		}
	}
	cout << m_max+1 << endl;
}
