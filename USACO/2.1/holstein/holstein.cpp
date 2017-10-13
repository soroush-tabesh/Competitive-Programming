/*
ID: soroosh4
LANG: C++11
TASK: holstein
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("holstein.in","r",stdin),freopen("holstein.out","w",stdout)
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

int v,g;
int need[26];
int t[26];
int foods[16][26];
string give = "------------------------------";

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void add(int f){
	forar(i,v){
		t[i] += foods[f][i];
	}
}

bool check(){
	forar(i,v){
		if(t[i] < need[i])
			return false;
	}
	return true;
}

void Solution(){
	cin >> v;
	forar(i,v){
		cin >> need[i];
	}
	cin >> g;
	forar(i,g){
		forar(j,v){
			cin >> foods[i][j];
		}
	}
	forar(mask,1<<g){
		memset(t,0,sizeof t);
		int cnt = 0;
		forar(i,g){
			if(mask & (1<<i)){
				add(i);
				cnt++;
			}
		}
		if(check() && cnt <= give.length()){
			string t;
			forar(i,g){
				if(mask & (1<<i)){
					t+=i;
				}
			}
			if((cnt == give.length() && lexicographical_compare(t.begin(),t.end(),give.begin(),give.end()))|| cnt != give.length()){
					give = t;
			}
		}
	}
	cout << give.length();
	forar(i,give.length()){
		cout << ' ';
		cout << int(give[i])+1;
	}
	cout << endl;
}
