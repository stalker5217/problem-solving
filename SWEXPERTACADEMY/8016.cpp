#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int test_case = 1 ; test_case <= T ; ++test_case){
        long long n;
        cin >> n;

        long long result1 =  (2 * n * n) - (4 * n) + 3;
        long long result2 =  (2 * n * n) - 1;
        cout << "#" << test_case << " " << result1 << " " << result2 << "\n";
    }

    return 0;
}