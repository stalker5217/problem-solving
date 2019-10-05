#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef struct __consulting{
	int time;
	int profit;
} consulting;

int N;
vector<consulting> consult;
vector<consulting> consultStack;
int myMax = -1;

void calMax(int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Algorithm
    cin >> N;
	for(int i = 0 ; i < N ; i++){
		int time, profit;
		cin >> time >> profit;
		consulting temp;
		temp.time = time;
		temp.profit = profit;

		consult.push_back(temp);
	}
	calMax(0);

	cout << myMax;
    
    return 0;
}

void calMax(int offset){
	if(offset >= N){
		int sum = 0;
		for(int i = 0 ; i < consultStack.size() ; i++){
			sum += consultStack[i].profit;
		}

		if(sum > myMax){
			myMax = sum;
		}
	}
	
	for(int i = offset ; i < N ; i++){
		if(i + consult[i].time <= N){
			consultStack.push_back(consult[i]);
			calMax(i + consult[i].time);
			consultStack.pop_back();
		}
		else{
			calMax(i + consult[i].time);
		}
	}
}