// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0;
		int right = mountainArr.length() - 1;
        
        // find peak
		while(left < right) {
			int mid = (right + left) / 2;
			if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		int peak = left;

		int answer = -1;
		// 앞 쪽에 대한 검색
		left = 0;
		right = peak;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (mountainArr.get(mid) == target) {
				answer = mid;
				break;
			} else if (mountainArr.get(mid) < target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}

		if (answer != -1) {
			return answer;
		}

		// 뒷 쪽에 대한 검색
		left = peak;
		right = mountainArr.length() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (mountainArr.get(mid) == target) {
				answer = mid;
				break;
			} else if (mountainArr.get(mid) < target) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}

		return answer;
    }
};