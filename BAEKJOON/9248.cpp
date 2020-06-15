#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getSuffixArray(const string &);
vector<int> getLCPArray(const string &, vector<int>);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    vector<int> sa = getSuffixArray(s);
    vector<int> lcp = getLCPArray(s, sa);

    for(int i = 0 ; i < sa.size() ; i++) cout << sa[i] + 1 << " ";
    cout << "\n";
    cout << "x ";
    for(int i = 1 ; i < lcp.size() ; i++) cout << lcp[i] << " ";
    cout << "\n";

    return 0;
}

vector<int> getSuffixArray(const string & s){
    int n = s.size();
    int t = 1;

    // group 배열
    // 각 접미사들을 [0:t]를 기준으로 정렬했을 때 속하는 그룹을 나타냄
    vector<int> group(n+1);
    // 초기 세팅에서는 그냥 문자열 character를 그대로 사용한다.
    // 0부터 시작하는 값은 아니지만 대소 관계 비교에는 문제가 없다.
    for(int i = 0 ; i < n ; ++i) group[i] = s[i];
    // group은 길이가 0인 접미사도 포함하며 -1로 세팅한다.
    group[n] = -1;

    // return array
    vector<int> ret(n);
    for(int i = 0 ; i < n ; ++i) ret[i] = i;

    
    while(t < n){
        // compare 함수
        auto compare = [&group, t](int a, int b){
            // 첫 t글자가 다르면 판단 가능
            if(group[a] != group[b]) return group[a] < group[b];
            // 아니면 s[a+t:]와 s[b+t:]를 비교한다.
            // group[a] == group[b]이므로 두 길이는 t 이상임을 알 수 있다.
            // a + t, b + t 모두 n보다 작으므로 out of index는 없다.
            return group[a+t] < group[b+t];
        };
        sort(ret.begin(), ret.end(), compare);

        t *= 2;
        if(t >= n) break;

        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[ret[0]] = 0;
        for(int i = 1 ; i < n ; ++i){
            if(compare(ret[i-1], ret[i])) newGroup[ret[i]] = newGroup[ret[i-1]] + 1;
            else newGroup[ret[i]] = newGroup[ret[i-1]];
        }
        group = newGroup;
    }

    return ret;
}

vector<int> getLCPArray(const string& s, vector<int> sa){
    int n = s.size();

    vector<int> lcp(n);

    // 접미사 시작 인덱스 : suffix array 인덱스
    vector<int> rank(n);
    for(int i = 0 ; i < n ; i++) rank[sa[i]] = i;

    int matched = 0;
    for(int i = 0 ; i < n ; i++){
        int k = rank[i];
        if (k){
            for(int j = sa[k-1] ; s[i + matched] == s[j + matched] ; matched++);
            lcp[k] = matched;
 
            if (matched) --matched;
        }
    }
    return lcp;
}