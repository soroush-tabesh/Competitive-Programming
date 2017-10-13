//In The Name of Allah
//Tue 11/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e6+5;

void Solution();

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	int x;
	cin >> x;
	int old = x;
	string s;
	while(x>0){
		stringstream ss;
		ss << x%10;
		s.insert(0,ss.str());
		x/=10;
	}
	next_permutation(s.begin(),s.end());
	int sec = 0;
	forar(i,s.length()){
		sec*=10;
		sec+=s[i]-'0';
	}
	if(sec <= old){
		cout << 0;
	}else{
		cout << s;
	}
}
