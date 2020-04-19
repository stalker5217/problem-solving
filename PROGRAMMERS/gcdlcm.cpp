#include <string>
#include <vector>

using namespace std;

int gcd(int, int);

vector<int> solution(int n, int m) {
    vector<int> answer;

    answer.push_back(gcd(n, m));
    answer.push_back(n * m / gcd(n, m));

    return answer;
}

int gcd(int a, int b){
    if(a < b) swap(a, b);

    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}