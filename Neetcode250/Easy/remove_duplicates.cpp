#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // number of removed elements from the array
        int slow = 0;
        int size = nums.size();
        
        for(int fast = 1; fast < size; ++fast) { 
            if(nums[slow] != nums[fast]) {
               slow++;
               nums[slow] = nums[fast];
            }
        }
        return slow+1;
    }
};