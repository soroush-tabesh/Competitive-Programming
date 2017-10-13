#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForI(i,a,b) for(long long int i = a; i < b;i++)
#define ForD(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;

using namespace std;

void Solution();

struct Node{
	vector<int> neib;
	int color; // cw=1 ccw=2 imp=-1
	int comp;
};
typedef struct Node Node;

bool mark[100*1000+2];
Node verts[100*1000+2];
int n,m,q,curcomp,cnt;
bool notbiq[100*1000+2];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

inline void Log(string s){
	cout << "Log: " << s << endl;
}

inline void Log(int s){
	cout << "Log: " << s << endl;
}

void dfs(int v,int col){
	mark[v] = 1;
	verts[v].color = col;
	verts[v].comp = curcomp;
	ForI(i,0,verts[v].neib.size()){
		if(!mark[verts[v].neib[i]]){
			dfs(verts[v].neib[i],col%2+1);
		} else if(verts[verts[v].neib[i]].color == col){
			notbiq[curcomp] = 1;
		}
	}
}

void Solution(){
	cin >> n >> m >> q;
	ForI(i,0,m){
		int a,b;
		cin >> a >> b;
		verts[a].neib.pb(b);
		verts[b].neib.pb(a);
	}
	ForI(i,0,n){
		if(!mark[i]){
			dfs(i,1);
			curcomp++;
		}
	}
	ForI(i,0,q){
		int a,b;
		cin >> a >> b;
		if(notbiq[verts[a].comp]){
			cout << "impossible" << endl;
			continue;
		}
		if(verts[a].comp != verts[b].comp){
			cout << "independent" << endl;
			continue;
		}
		if(verts[a].color == verts[b].color){
			cout << "cw" << endl;
		}else{
			cout << "ccw" << endl;
		}
	}
	
}

