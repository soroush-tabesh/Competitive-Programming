//In The Name of Allah
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
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

void Solution();

struct Node{
	int prev;
	int next;
	char val;
};

vector<Node> data(2);
int cur = 0;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void ins(char c){
	Node t;
	t.prev = cur;
	t.next = data[cur].next;
	t.val = c;
	data.pb(t);
	
	data[data[cur].next].prev = data.size()-1;
	data[cur].next = data.size()-1;
	cur = data.size()-1;
}

void mprev(){
	if(cur == 0)
		return;
	cur = data[cur].prev;
}

void mnext(){
	cur = data[cur].next;
	if(cur == 1){
		cur = data[cur].prev;
	}
}

void Solution(){
	data[0].next = 1;
	data[0].prev = -1;
	data[1].next = -1;
	data[1].prev = 0;
	string s;
	cin >> s;
	forar(i,s.length()){
		if(s[i] == 'L'){
			mprev();
		}else if(s[i] == 'R'){
			mnext();
		}else{
			ins(s[i]);
		}
	}
	cur = 0;
	do{
		mnext();
		cout << data[cur].val;
	}
	while(cur != data[1].prev);
}