// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, 
// return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.

// TC - O(N)
// SC - O(1)

// Problem link - https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // ans vector stores the duplicate element
        vector<int> ans;
        // taking the size of the array
        int n = nums.size();
        
        // traversing in the array
        for(int i = 0; i < n; i++) {
            // Taking the current element as a index
            int index = abs(nums[i]);
            // Comparing if the element at index nums[i] is less than 0, it means the current element is a duplicate
            if(nums[index - 1] < 0) {
                // inserting the duplicate element in a ans vector
                ans.push_back(abs(nums[i]));
            } else {
                // marking the element negative
                nums[index - 1] *= -1;
            }
        }
        
        // returning the ans vector
        return ans;
    }
};
