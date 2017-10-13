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


struct Node {
	int left;
	int right;
	int val;
};

typedef struct Node Node;

map<int,bool> valid;
map<int,int> reps;
Node node[101*1000];
bool mark[101*1000];
int n,root,cnt;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void dfs(int v,int l,int h){
	if(v == -1)
		return;
	valid[node[v].val] = valid[node[v].val] || (node[v].val < h && node[v].val > l);
	dfs(node[v].left,l,min(h,node[v].val));
	dfs(node[v].right,max(l,node[v].val),h);
}

void Solution(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> node[i].val >> node[i].left >> node[i].right;
		if(node[i].left != -1)
			mark[node[i].left] = 1;
		if(node[i].right != -1)
			mark[node[i].right] = 1;
		reps[node[i].val]++;
	}
	for(int i = 1;i <= n;i++){
		if(!mark[i])
			root = i;
	}
	dfs(root,-1,1e9);
	for(map<int,bool>::iterator it = valid.begin();it != valid.end();it++){
		if(!(it->second)){
			cnt += reps[it->first];
		}
	}
	cout << cnt;
}