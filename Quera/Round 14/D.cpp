#include <bits/stdc++.h>

using namespace std;

bool mark[100001];

bool isprime(int x){
	for(int i = 2;i*i<=x;i++){
		if(x%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	set<int> ans;
	for(int i = 2;i <= n;i++){
		if(mark[i])
			continue;
		if(isprime(i)){
			for(int j = 2;i*j <= n;j++){
				mark[i*j]=1;
			}
		}
	}
	for(int i = 2;i <= n;i++){
		if(mark[i] == 0){
			int l = (int)floor(log(n)/log(i));
			l = (int)pow(i,l);
			ans.insert(l);
		}
	}
	cout << ans.size() << endl;
	for(set<int>::iterator it = ans.begin();it != ans.end();it++){
		cout << (*it) << " ";
	}
}
