#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int up, down, goal;
	cin >> up >> down >> goal;

	int day = 1;
	goal -= up;

	// 하루보다 더 걸리는 경우
	if(goal > 0){
		int distancePerDay = up - down;
		
		day += (goal / distancePerDay);
		day += (goal % distancePerDay > 0) ? 1 : 0;
	}

	cout << day;

    return 0;
}
