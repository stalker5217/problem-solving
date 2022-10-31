#include <vector>

using namespace std;

class Solution {
private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        
        // 정렬 전 한 쪽으로 쏠려 있으면 O(n^2)까지 떨어짐
        int randomIndex = left + (rand() % (right - left + 1));
        swap(nums[left], nums[randomIndex]);
        
        int pivotIndex = partition(nums, left, right);
        
        quickSort(nums, left, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, right);
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int& pivot = nums[left];
        
        int front = left + 1;
        int tail = right;
        
        while (true) {
            while(front <= right && pivot > nums[front]) {
                front++;
            }
            
            while(tail > left && pivot < nums[tail]) {
                tail--;
            }
            
            if (front < tail) {
                swap(nums[front++], nums[tail--]);
            } else {
				break;
			}
        }
        
        swap(pivot, nums[tail]);
        
        return tail;
    }
    
public:
    /**
     * Quick Sort
     */
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        
        return nums;
    }
};