/*
Problem: Find All Duplicates in an Array
Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/
Difficulty: Medium

To do it in order(1) space, we cannot use map or set
We have to make some modifications in input array but also shouldn't lose the original input number
Given hint : range [1-n]
To mark an element as visited inplace and still not lose original input 
    * Just mark it as negative so that you can easily take the absolute value whenever needed
    * If some number is already marked as visited add it to ans
But important thing is to relate the array element with corresponding index
Index is the only key to makae changes in place
    * So if you to mark an element as visited, go to its corresponding index
     and change that value as negative.
    * Also keep in mind that corresponding index for an element x is x-1 and not x itself
    * Bcs, range [1-10], the imdex of 10 cannot be 10. index must be from [0-9] so decrement 1
Most importantly, 
while accessing the array elements always take absolute value
since it can become negative at any point

Time Complexity: O(n)
Space Complexity: O(1) extra (excluding output)

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(auto i:nums){
            if(nums[abs(i)-1]<0){
                ans.push_back(abs(i));
            }
            nums[abs(i)-1]*=-1;
        }
        return ans;
    }
};

int main() {
    // Example usage:
    // Solution sol;
    // vector<int> nums = {4,3,2,7,8,2,3,1};
    // vector<int> result = sol.findDuplicates(nums);
    // for (int num : result) cout << num << " ";
    return 0;
}
