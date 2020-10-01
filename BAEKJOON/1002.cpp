#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
    cin >> test_case;
    for(int t = 0 ; t < test_case ; t++){
        int x1, y1, r1;
        int x2, y2, r2;

        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;

        // 두 원 중심 사이 거리 제곱
        int dist_center = ((x1 -x2) * (x1 -x2)) + ((y1 - y2) * (y1 - y2));

        // 류재명과의 거리 합, 차 제곱
        int dist_ryu_sum = (r1 + r2) * (r1 + r2);
        int dist_ryu_diff = (r1 - r2) * (r1 - r2);
        
        int ret;
        if(dist_center < dist_ryu_sum && dist_center > dist_ryu_diff) ret = 2;
        // 내접
        else if(dist_center == dist_ryu_diff && dist_center > 0) ret = 1;
        // 외접
        else if(dist_center == dist_ryu_sum) ret = 1;
        // 만나는 점이 없음
        else if(dist_center < dist_ryu_diff || dist_center > dist_ryu_sum) ret = 0;
        // 만나는 점이 없음
        else if(dist_center == 0 && r1 != r2) ret = 0;
        // 완전 일치
        else ret = -1;

        cout << ret << "\n";
    }

    return 0;
}