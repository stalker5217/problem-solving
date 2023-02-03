#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> answer;
        for(int hour = 0 ; hour < 12 ; hour++) {
            for(int minute = 0 ; minute < 60 ; minute++) {
                int hourBit = 0;
                int tempHour = hour;
                while (tempHour > 0) {
                    if (tempHour & 1) {
                        hourBit++;
                    }
                    tempHour >>= 1;
                }
                
                int minuteBit = 0;
                int tempMinute = minute;
                while (tempMinute > 0) {
                    if (tempMinute & 1) {
                        minuteBit++;
                    }
                    tempMinute >>= 1;
                }

                if (hourBit + minuteBit == turnedOn) {
                    string time = to_string(hour) + ":"; 

                    if (minute < 10) {
                        time += "0";
                    }
                    time += to_string(minute);

                    answer.push_back(time);
                }
            }
        }

        return answer;
    }
};