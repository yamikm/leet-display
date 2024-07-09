/**
 * You are given an integer array nums. You want to maximize the number of points 
 * you get by performing the following operation any number of times:
 * Pick any nums[i] and delete it to earn nums[i] points. 
 * Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
 * Return the maximum number of points you can earn by applying the above operation some number of times.
 * 
Example 1:
Input: nums = [3,4,2]
Output: 6
Example 2:
Input: nums = [2,2,3,3,3,4]
Output: 9

Constraints:
1 <= nums.length <= 2 * 104
1 <= nums[i] <= 104

 */


#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>
using namespace std;

/**
 * This function implements the solution for the problem described in the comment block above
 * The idea is to use dynamic programming to compute the maximum number of points that can be earned
 * We compute this value for each possible value of the maximum element in the array
 * For each value, we compute the maximum number of points that can be earned by deleting that value
 * @param nums The input array of integers
 * @return The maximum number of points that can be earned
 */
int deleteAndEarn(vector<int>& nums) {
    // Base cases
    if (nums.size() == 0) return 0;  
    if (nums.size() == 1) return nums[0];  
    if (nums.size() == 2) return max(nums[0], nums[1]);  

    // Find the maximum element in the array and store the points associated with each element
    int maxEle = INT_MIN;
    unordered_map<int, int> points;
    for (int n : nums) {
        points[n] += n;  // Add the value of the element to the points of that element
        maxEle = max(maxEle, n);  // Update the maximum element
    }

    // Create a cache vector to store the maximum points that can be earned up to each element
    vector<int> cache(maxEle + 1, 0);
    cache[0] = 0;  // Initialize the cache with 0 points for element 0
    cache[1] = points[1];  // Initialize the cache with the points of element 1

    // Fill the cache vector by iterating from element 2 to the maximum element
    for (int i = 2; i <= maxEle; i++) {
        // The maximum points that can be earned by deleting element i is the max of:
        // - The points earned by deleting the previous element (i-1)
        // - The points earned by deleting the previous-previous element (i-2) plus the points of element i
        cache[i] = max(cache[i - 1], cache[i - 2] + points[i]);
    }

    // Return the maximum points that can be earned by deleting the maximum element
    return cache[maxEle];
}