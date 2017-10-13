//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("shopping.in","r",stdin),freopen("shopping.out","w",stdout)
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
	if(s[0] == '1' && s.length() == 1){
		cout << 1;
		return;
	}
	if(s[0] == '2' && s.length() == 1){
		cout << 2;
		return;
	}
	
	if(s[s.length()-1] != '0'){
		s[s.length()-1]--;
	}else{
		int i = s.length()-1;
		s[i]--;
		while(s[i] < '0'){
			s[i] = '9';
			if(i)
				s[i-1]--;
			i--;
			if(i == 0)
				break;
		}
		if(s[0] <= '0'){
			s.erase(s.begin());
		}
	}
	cout << s;
}
