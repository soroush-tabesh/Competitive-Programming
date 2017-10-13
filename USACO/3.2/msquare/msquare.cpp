//In The Name of God
/*
ID: soroosh4
LANG: C++11
TASK: msquare
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("msquare.in","r",stdin),freopen("msquare.out","w",stdout)
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

enum{
	mrA = 1<<0,mrB = 1<<1,mrC = 1<<2,mrO = 1<<3
};

int dist[2100*1000];
char mark[2100*1000];
int orig,tar;
set<int> topro,tnpro;
bool found = false;
string sol = "Z";
string solmake;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

int mA(int v,bool r = false){
	// decode the hash
	int temp = v;
	bool digs[8] = {0,0,0,0,0,0,0,0};
	int res[8];
	if(v < 262744){
		res[0] = 0;
		digs[0] = 1;
	}
	int j = 6;
	while(temp > 0){
		digs[temp%8] = 1;
		res[j] = temp%8;
		j--;
		temp /= 8;
	}
	forar(i,8){
		if(!digs[i]){
			res[7] = i;
		}
	}
	// process
	forar(i,4)
		swap(res[i],res[7-i]);
	// encode
	v = 0;
	forar(i,8){
		v*=8;
		v+=res[i];
	}
	return v/8;
}

int mB(int v,bool r = false){
	// decode the hash
	int temp = v;
	bool digs[8] = {0,0,0,0,0,0,0,0};
	int res[8];
	if(v < 262744){
		res[0] = 0;
		digs[0] = 1;
	}
	int j = 6;
	while(temp > 0){
		digs[temp%8] = 1;
		res[j] = temp%8;
		j--;
		temp /= 8;
	}
	forar(i,8){
		if(!digs[i]){
			res[7] = i;
		}
	}
	// process
	if(!r){
		forar(i,3){
			swap(res[7],res[7-i-1]);
			swap(res[0],res[i+1]);
		}
	}else{
		forar(i,3){
			swap(res[7],res[7-(2-i)-1]);
			swap(res[0],res[(2-i)+1]);
		}
	}
	// encode
	v = 0;
	forar(i,8){
		v*=8;
		v+=res[i];
	}
	return v/8;
}

int mC(int v,bool r = false){
	// decode the hash
	int temp = v;
	bool digs[8] = {0,0,0,0,0,0,0,0};
	int res[8];
	if(v < 262744){
		res[0] = 0;
		digs[0] = 1;
	}
	int j = 6;
	while(temp > 0){
		digs[temp%8] = 1;
		res[j] = temp%8;
		j--;
		temp /= 8;
	}
	forar(i,8){
		if(!digs[i]){
			res[7] = i;
		}
	}
	// process
	if(!r){
		swap(res[1],res[2]);
		swap(res[1],res[5]);
		swap(res[1],res[6]);
	}else{
		swap(res[1],res[6]);
		swap(res[1],res[5]);
		swap(res[1],res[2]);
	}
	// encode
	v = 0;
	forar(i,8){
		v*=8;
		v+=res[i];
	}
	return v/8;
}

void bfs(){
	for(int v : topro){
		int va = mA(v);
		int vb = mB(v);
		int vc = mC(v);

		if(!mark[va]){
			mark[va] = mark[va] | mrA;
			dist[va] = dist[v]+1;
			tnpro.insert(va);
		}else if(dist[va] == dist[v]+1){
			mark[va] = mark[va] | mrA;
		}

		if(!mark[vb]){
			mark[vb] = mark[vb] | mrB;
			dist[vb] = dist[v]+1;
			tnpro.insert(vb);
		}else if(dist[vb] == dist[v]+1){
			mark[vb] = mark[vb] | mrB;
		}

		if(!mark[vc]){
			mark[vc] = mark[vc] | mrC;
			dist[vc] = dist[v]+1;
			tnpro.insert(vc);
		}else if(dist[vc] == dist[v]+1){
			mark[vc] = mark[vc] | mrC;
		}

		if(va == tar || vb == tar || vc == tar){
			found = true;
		}
	}
}

void dfs(int v){
	if(v == orig){
		if(lexicographical_compare(solmake.rbegin(),solmake.rend(),sol.rbegin(),sol.rend()))
			sol = solmake;
		return;
	}
	if(mark[v] & mrA){
		solmake += 'A';
		dfs(mA(v,true));
		solmake.pop_back();
	}
	if(mark[v] & mrB){
		solmake += 'B';
		dfs(mB(v,true));
		solmake.pop_back();
	}
	if(mark[v] & mrC){
		solmake += 'C';
		dfs(mC(v,true));
		solmake.pop_back();
	}
}

void Solution(){
	forar(i,8){
		int a;
		cin >> a;
		tar*=8;
		tar+=a-1;
	}
	tar /= 8;
	
	//init
	orig = 42798;
	mark[orig] = mark[orig] | mrO;
	tnpro.insert(orig);
	
	// do floodfill
	while(!found){
		topro.clear();
		swap(topro,tnpro);
		bfs();
	}
	
	// output solution
	dfs(tar);
	reverse(sol.begin(),sol.end());
	
	cout << dist[tar] << endl;
	cout << sol << endl;
}
