/*
ID: soroosh4
LANG: C++11
TASK: lamps
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("lamps.in","r",stdin),freopen("lamps.out","w",stdout)
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

vector<int> on,off;
set<string> ans;
int n,c;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> c;
	int in;
	cin >> in;
	while(in != -1){
		on.pb(in);
		cin >> in;
	}
	cin >> in;
	while(in != -1){
		off.pb(in);
		cin >> in;
	}
	forar(mask,16){
		int cnt = 0,temp = mask;
		
		while(temp>0){
			cnt++;
			temp -= temp & (-temp);
		}
		
		// check cnt valid
		if(cnt > c)
			continue;
		
		//apply masks and check on and off
		bool is = true;
		for(int lamp : on){
			bool test = true;
			if(mask & (1<<0))
				test = !test;
			
			if(mask & (1<<1))
				if(lamp%2 == 1)
					test = !test;
				
			if(mask & (1<<2))
				if(lamp %2 == 0)
					test = !test;
			
			if(mask & (1<<3))
				if(lamp % 3 == 1)
					test = !test;
			if(!test)
				is = false;
		}
		
		for(int lamp : off){
			bool test = true;
			if(mask & (1<<0))
				test = !test;
			
			if(mask & (1<<1))
				if(lamp%2 == 1)
					test = !test;
				
			if(mask & (1<<2))
				if(lamp %2 == 0)
					test = !test;
			
			if(mask & (1<<3))
				if(lamp % 3 == 1)
					test = !test;
			if(test)
				is = false;
		}
		
		if(!is)
			continue;
		
		if(c - cnt != 1){
			//add answer
			string state;
			fori(lamp,1,n+1){
				bool test = true;
				if(mask & (1<<0))
					test = !test;
				
				if(mask & (1<<1))
					if(lamp%2 == 1)
						test = !test;
					
				if(mask & (1<<2))
					if(lamp %2 == 0)
						test = !test;
				
				if(mask & (1<<3))
					if(lamp % 3 == 1)
						test = !test;
				state += (test ? "1" : "0");
			}
			ans.insert(state);
		}
	}
	for(string s : ans){
		cout << s << endl;
	}
	if(ans.size()==0){
		cout << "IMPOSSIBLE" << endl;
	}
}
