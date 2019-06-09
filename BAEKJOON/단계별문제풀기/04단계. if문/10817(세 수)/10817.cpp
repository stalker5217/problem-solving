#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	vector<int> vec;
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);

	sort(vec.begin(), vec.end());

	printf("%d", vec[1]);
	return 0;
}