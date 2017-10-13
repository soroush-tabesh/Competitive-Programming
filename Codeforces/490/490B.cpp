#include <bits/stdc++.h>

using namespace std;

#define frw first
#define bck second
#define pb push_back
#define pf push_front

int main()
{
	int n;
	cin >> n;
	map<int,pair<int,int> > data;
	set<int> used;
	for(int i = 0;i < n;i++){
		int a,b;
		cin >> a >> b;
		data[a].bck=(b);
		data[b].frw=(a);
		used.insert(a);
		used.insert(b);
	}

	int * ans = new int[n+1];
	
	// count even
	ans[2] = data[0].bck;
	used.erase(ans[2]);
	//ans[n-1] = data[0].frw;
	for(int i=2;2*i<=n;i++){
		ans[2*i] = data[ans[2*i-2]].bck;
		used.erase(ans[2*i]);
	}
	used.erase(0);
	
	// count odd
	deque<int> odds;
	odds.pf(*used.begin());
	//cout << odds[0] << endl;
	while(odds.size() != used.size()){
		int tempa = data[odds.front()].frw;
		//cout << "dbg: " << tempa << endl;
		if(tempa != 0){
			odds.pf(tempa);
		}
		int tempb = data[odds.back()].bck;
		if(tempb != 0){
			odds.pb(tempb);
		}
	}
	
	//add odd
	for(int i = 1;i <= odds.size();i++){
		ans[2*i-1] = odds[i-1];
	}
	
	// print
	for(int i = 1;i <= n;i++){
		cout << ans[i] << ' ';
	}

}



