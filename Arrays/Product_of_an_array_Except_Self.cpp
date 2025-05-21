/*

Problem: Product of Array Except Self
Link: https://leetcode.com/problems/product-of-array-except-self/
Difficulty: Medium

*/

/*
1. Calculate a prefix product array : pre[0]=1, start from nums[1]=pre[0]*nums[0]
2. Calculate a suffix product array : suf[n-1]=1, start from nums[n-2]=suf[n-1]*nums[n-1]
3. Calculate a answer array : ans[i] = pre[i]*suf[i]

T.C O(3n)
S.C O(2n)
*/

class Solution1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preprod(n, 1), sufprod(n, 1), ans(n);
        for (int i = 1; i < n; i++) {
            preprod[i] = preprod[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            sufprod[i] = sufprod[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = preprod[i] * sufprod[i];
        }
        return ans;
    }
};

/*
To reduce space complexity, 
    * instead of creating prefix sum array, compute it directly in ans array
    * instead of suffix array, simply use a variable and update it with help of loop variable i
    * for final answer, ans[i] = ans[i] * sufprod i.e. preprod[i]*sufprod[i]

T.C O(2n)
S.C O(1)
*/

class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Prefix sum array
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Suffix sum array
        int sufprod = 1;
        for (int i = n - 2; i >= 0; i--) {
            sufprod = sufprod * nums[i + 1];
            ans[i] = ans[i] * sufprod;
        }

        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Example usage:
    // vector<int> nums = {1,2,3,4};
    // Solution1 sol1;
    // vector<int> result1 = sol1.productExceptSelf(nums);
    // for (int val : result1) cout << val << " ";
    // cout << endl;

    // Solution2 sol2;
    // vector<int> result2 = sol2.productExceptSelf(nums);
    // for (int val : result2) cout << val << " ";

    return 0;
}
