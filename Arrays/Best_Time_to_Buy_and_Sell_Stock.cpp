/*

Problem: Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Difficulty: Easy

To solve this problem optimally,
we track the minimum price (costPrice) seen so far while iterating through the array.
For each price, we compute the profit if we sold at that price,
and update the maximum profit accordingly.

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int costPrice = INT_MAX;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++) {
            costPrice = min(costPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - costPrice);
        }
        return maxProfit;
    }
};

int main() {
    // Example usage:
    // Solution sol;
    // vector<int> prices = {7, 1, 5, 3, 6, 4};
    // cout << sol.maxProfit(prices) << endl;
    return 0;
}
