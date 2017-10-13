// Incomplete
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

int mat[100*1000+2];
int matin[100*1000+2];
bool mark[100*1000+2];
vector<pair<int,int> > sol;
vector<int> mat2;
int n,np=0;

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

int dfs(int v,int dep,int vd){
	if(mark[v] == 1)
		return dep-1;
	mark[v] = 1;
	int s = dfs(mat[v],dep+1,vd);
	
	return s;
}

void Solution(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> mat[i];
		matin[mat[i]] = i;
	}
	int m_max=0;
	for(int i = 1;i<=n;i++){
		if(mark[i] == 0){
			int temp = dfs(i,0,i);
			m_max = max(temp,m_max);
		}
	}
	cout << m_max << endl;
	cout << sol.size() << endl;
	for(int i = 0 ;i < sol.size();i++)
		cout << sol[i].frs << " " << sol[i].scnd << endl;
	
}


