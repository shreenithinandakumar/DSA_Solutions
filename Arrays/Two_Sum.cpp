/*

Problem: Two Sum
Link: https://leetcode.com/problems/two-sum/
Difficulty: Easy

To solve the problem in a single pass,
we have to keep track of the visited numbers so that,
    for each current element (a) we can check if the complementary no. (b=n-a) was already present in the array or not.
for this we use an unorderedmap to store the visited numbers along with their indices
if a complementory number is founud, return {i, map[complement]}
else add the current number to the map

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map1;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map1.find(complement) != map1.end()) {
                return {map1[complement], i};
            }
            map1[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    // Example usage:
    // Solution sol;
    // vector<int> nums = {2, 7, 11, 15};
    // int target = 9;
    // vector<int> result = sol.twoSum(nums, target);
    // for (int idx : result) cout << idx << " ";
    return 0;
}
