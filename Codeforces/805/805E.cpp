//In The Name of God
// Weird wrong answer on test 81
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

int n,m;
int cols[3*100*1000+1];
int ice[100*1000];

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
	cin >> n >> m;
	int mmax = 0;
	forar(k,n){
		int s;
		cin >> s;
		mmax = max(mmax,s);
		set<int> used;
		forar(k2,s){
			cin >> ice[k2];
			if(cols[ice[k2]] != 0)
				used.insert(cols[ice[k2]]);
		}
		int col = 1;
		set<int>::iterator it = used.begin();
		forar(k2,s){
			if(cols[ice[k2]] == 0){
				if(used.size() == 0){
					cols[ice[k2]] = 1;
					it = used.insert(col).first;
					continue;
				}
				while(col == *it){
					it++;
					col++;
					if(it == used.end()){
						break;
					}
				}
				cols[ice[k2]] = col;
				it = used.insert(col).first;
			}
		}
	}
	cout << mmax << endl;
	forar(i,m){
		cout << cols[i+1] << ' ';
	}
}




