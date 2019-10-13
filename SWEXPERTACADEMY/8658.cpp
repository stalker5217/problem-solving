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

    // Algorithm
   int T;
   cin >> T;
   for(int test_case = 1 ; test_case <= T ; test_case++){
	   vector<int> result;
	   int temp;
	   for(int i = 0 ; i < 10 ; i++){
		   cin >> temp;
		   int sum = 0;
		   
		   while(1){  
			   if(temp == 0)
			   		break;
				
				sum += temp % 10;
				temp /= 10;
		   }

			result.push_back(sum);
	   }

	   sort(result.begin(), result.end());

	   int mymin = result[0];
	   int mymax = result[9];

	   cout << "#" << test_case << " " << mymax << " " << mymin << "\n";
   }
    
    return 0;
}
