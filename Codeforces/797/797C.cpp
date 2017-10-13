#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;

void Solution();

string in;
queue<char> s;
stack<char> t;
string u;
multiset<char> m;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void Solution(){
	cin >> in;
	for(int i = 0;i < in.length();i++){
		m.insert(in[i]);
		s.push(in[i]);
		//Log(in[i]);
	}
	//Log("Next");
	while(s.size() > 0){
		char tar = *m.begin();
		if(!t.empty() && t.top() <= tar){
			tar = t.top();
			t.pop();
			u += tar;
		}else{
			//Log("A");
			while(s.front() != tar){
				//Log(s.front());
				m.erase(m.find(s.front()));
				t.push(s.front());
				s.pop();
			}
			//Log("B");
			u += tar;
			m.erase(m.find(tar));
			s.pop();
		}
	}
	while(!t.empty()){
		u += t.top();
		t.pop();
	}
	cout << u;
}