#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool sortfunc(pair<int,int> a,pair<int,int> b){
    return a.first < b.first;
}

int clamp_sub(int a, int b){
    return ( a>b ? a-b : 0);
}

int main() {
	// your code goes here
	int n;
	long long k;
	std::cin >> n >> k;
	std::vector< pair<int,int> > fru (n);
	for(int i = 0;i < n;i++){
	    std::cin >> fru[i].first >> fru[i].second;
	}
	sort(fru.begin(),fru.end(),sortfunc);
	
	for(int i = 0;i < fru.size();i++){
	    pair<int,int> temp = fru [i];
	    if(temp.first <= k){
	        k+= clamp_sub(temp.second,temp.first);
	    }
	}
	
	std::cout << k << std::endl;
	return 0;
}
