#include <iostream>

using namespace std;

int main(){
	int hour, minute;

	cin >> hour >> minute;

	if(minute >= 45){
		cout << hour << " " << minute - 45;
	}
	else{
		if(hour > 0){
			cout << hour - 1 << " " << minute - 45 + 60;
		}
		else{
			cout << "23" << " " << minute - 45 + 60;
		}
	}
}