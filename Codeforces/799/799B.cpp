//In The Name of God
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

struct Tsh{
	int id;
	int price;
	int ca;
	int cb;
};
struct classcomp {
  bool operator() (const Tsh& lhs, const Tsh& rhs) const
  {return lhs.price<rhs.price;}
};

typedef struct Tsh Tsh;
Tsh tsh[200*1000];
set<Tsh,classcomp> tsh1;
set<Tsh,classcomp> tsh2;
set<Tsh,classcomp> tsh3;
int n,m,id;


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
	cin >> n;
	forar(i,n){
		cin >> tsh[i].price;
	}
	forar(i,n){
		cin >> tsh[i].ca;
	}
	forar(i,n){
		cin >> tsh[i].cb;
	}
	forar(i,n){
		tsh[i].id = i;
		if(tsh[i].ca == 1 || tsh[i].cb == 1)
			tsh1.insert(tsh[i]);
		if(tsh[i].ca == 2 || tsh[i].cb == 2)
			tsh2.insert(tsh[i]);
		if(tsh[i].ca == 3 || tsh[i].cb == 3)
			tsh3.insert(tsh[i]);
	}
	cin >> m;
	forar(i,m){
		int col;
		cin >> col;
		if(col == 1){
			if(tsh1.size()!=0){
				cout << (*tsh1.begin()).price;
				Tsh temp = (*tsh1.begin());
				if(temp.ca == 1 || temp.cb == 1){
					tsh1.erase(temp);
				}
				if(temp.ca == 2 || temp.cb == 2){
					tsh2.erase(temp);
				}
				if(temp.ca == 3 || temp.cb == 3){
					tsh3.erase(temp);
				}
			}else{
				cout << "-1";
			}
		}else if (col == 2){
			if(tsh2.size()!=0){
				cout << (*tsh2.begin()).price;
				Tsh temp = (*tsh2.begin());
				if(temp.ca == 1 || temp.cb == 1){
					tsh1.erase(temp);
				}
				if(temp.ca == 2 || temp.cb == 2){
					tsh2.erase(temp);
				}
				if(temp.ca == 3 || temp.cb == 3){
					tsh3.erase(temp);
				}
			}else{
				cout << "-1";
			}
		}else{
			if(tsh3.size()!=0){
				cout << (*tsh3.begin()).price;
				Tsh temp = (*tsh3.begin());
				if(temp.ca == 1 || temp.cb == 1){
					tsh1.erase(temp);
				}
				if(temp.ca == 2 || temp.cb == 2){
					tsh2.erase(temp);
				}
				if(temp.ca == 3 || temp.cb == 3){
					tsh3.erase(temp);
				}
			}else{
				cout << "-1";
			}
		}
		cout << " ";
		
	}
}




