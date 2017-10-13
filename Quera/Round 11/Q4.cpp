#include <bits/stdc++.h>

using namespace std;

int powmod_recursion(int pow, int val, int MOD)
{
    if(pow == 0)
        return 1;
    int v = powmod_recursion(pow/2, val, MOD);
    int temp = 0;
    if(pow % 2 == 0)
    {
        temp = (v*v) % MOD;
    }
    else
    {
        temp = (((v*val) % MOD) * v) % MOD;
    }
    return temp;
}

int powmod(int pow, int val, int mod){
	if(val == 0)
		return 0;
	return powmod_recursion(pow,val,mod);
}

vector<int> getpattern(int n, int k){
	vector<int> pattern;
	bool* mods = new bool[k];
	memset(mods,0,k);
	bool condition = true;
	int temp = n;

	do{
		int mod = temp % k;
		if(!mods[mod]){
			mods[mod] = true;
			pattern.push_back(mod);
		}else{
			condition = false;
		}
		temp = (temp*n) % k;
	} while(condition);

	return pattern;
}

int main()
{
    // your code goes here
    int n,k,result;
    cin >> n >> k;

    int base = 0;
    base = powmod(n,n,k);

	vector<int> pattern = getpattern(base,k);
	int topow = powmod(n,n,pattern.size());

	result = pattern[(topow+pattern.size()-1)%pattern.size()];

	cout << result << endl;

	/*
    cout << "Result: " << result << endl;

	for(vector<int>::iterator iter = pattern.begin();iter != pattern.end();iter++){
		cout << "" << *iter << endl;
	}
	*/

    return 0;
}
