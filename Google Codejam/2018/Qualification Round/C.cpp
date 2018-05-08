//In The Name of Allah
//Sat 18/1/97
#include <bits/stdc++.h>

using namespace std;

bool land[1000][10];

int main()
{
	int t;
	cin >> t;
	while(t--){
		int a;
		cin >> a;
		for(int i = 0;i < 1000;i++){
			for(int j = 0;j < 10;j++){
				land[i][j] = 0;
			}
		}
		bool k = true;
		for(int ind = 0;ind < (a+8)/9;ind++){
			int i = 2 + ind*3;
			int j = 2;
			for(int c = 0;c < 40;c++){
				cout << i;
				cout.flush();
				cout << j;
				cout.flush();
				int i2,j2;
				cin >> i2 >> j2;
				if(i2 < 1){
					k = false;
					break;
				}
			}
			if(!k)
				break;
		}
	}
	return 0;
}
