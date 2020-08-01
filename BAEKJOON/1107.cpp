#define DEBUG 0
#define LOG(string) cout << string
#define INT_MAX 2147483647

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int target;
int minCnt;
int digit;

vector<int> validBtn = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int checkDigit(int);
void handleEdge();
void permutation(vector<int>);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> target;

    digit = checkDigit(target);

    int brokenCnt;
    cin >> brokenCnt;

    for(int i = 0 ; i < brokenCnt ; i++){
        int broken;
        cin >> broken;
        validBtn.erase(remove(validBtn.begin(), validBtn.end(), broken));
    }

    minCnt = INT_MAX;

    vector<int> channel;
    permutation(channel);

    handleEdge();

    cout << minCnt;

    return 0;
}

// 자리 수 계산
int checkDigit(int n){
    if(n==0) return 1;
    
    int digit = 0;
    while(n > 0){
        digit++;
        n /= 10;
    }

    return digit;
}

void permutation(vector<int> channel){
    if(channel.size() == digit){
        int cur = 0;
        bool isStart = false;
        
        for(int i = 0, power = 1 ; i < digit ; i++, power*=10){
            cur += (channel[i] * power);
        }

        int pushCnt = checkDigit(cur);
        int result = pushCnt + abs(cur - target);
        minCnt = (minCnt < result) ? minCnt : result;

        return;
    }

    for(int i = 0 ; i < validBtn.size() ; i++){
        channel.push_back(validBtn[i]);
        permutation(channel);
        channel.pop_back();
    }
}

void handleEdge(){
    // 최초 기본 채널에서 이동.
    minCnt = (minCnt < abs(100 - target)) ? minCnt : abs(100- target);

    // Target보다 자리수 하나 작은 최대 값에서 이동
    if(validBtn.size() > 0 && digit > 1){
        int edge = 0;
        for(int i = 0, power = 1 ; i < digit - 1; i++, power *= 10){
            edge += validBtn[validBtn.size() - 1] * power;
        }

        int result = abs(edge - target) + checkDigit(edge);
        minCnt = (minCnt < result) ? minCnt : result;
    }

    // Target보다 자리수 하나 큰 최소 값에서 이동
    if(validBtn.size() > 0){
        int edge = 0;
        if(validBtn[0] == 0 && validBtn.size() > 1){
            int power = 1;
            for(int i = 0 ; i < digit ; i++){
                power *= 10;
            }
            edge = validBtn[1] * power;
        }
        else{
            for(int i = 0, power = 1 ; i < digit + 1 ; i++, power *= 10){
                edge += validBtn[0] * power;
            }   
        }

        int result = abs(edge - target) + checkDigit(edge);
        minCnt = (minCnt < result) ? minCnt : result;
    }
}