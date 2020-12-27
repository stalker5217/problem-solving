class Solution {
public:
    int mySqrt(int x) {
        long start = 0;
		long end = x;

		int answer = -1;
		while(start <= end){
			long mid = (start + end) / 2;
			if(mid * mid < x){
				start = mid + 1;
				answer = mid;
			}
			else if(mid * mid > x) end = mid - 1;
			else return mid;
		}

		return answer;
    }
};