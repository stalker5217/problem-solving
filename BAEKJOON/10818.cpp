#include <iostream>

using namespace std;

int main(){
	int mymax = -1000001;
	int mymin = 1000001;

	int cnt;

	cin >> cnt;

	int temp;	
	for(int i = 0 ; i < cnt ; i++){
		cin >> temp;
		if(temp > mymax)
			mymax = temp;
		
		if(temp < mymin)
			mymin = temp;
	}

	cout << mymin << " " << mymax << endl;
}