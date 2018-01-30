//In The Name of Allah
//Tue 5/10/96
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int LIS(vector<int> &v) { // using patience sorting algorithm
	vector<int> tail(v.size()+1, int(1e9));
	for (size_t i = 0; i < v.size(); i++)
		*upper_bound(tail.begin(),tail.end(),v[i]) = v[i]; // use lower_bound for strictly increasing
	return lower_bound(tail.begin(),tail.end(),int(1e9))-tail.begin();
}

int main() {
	vector<int> v{ 5,1,1,2,3,3,3,4,3,3 };
	cout << "Length of Longest Non-decreasing Subsequence is " << LIS(v) << endl;
    return 0;
}
