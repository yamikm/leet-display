/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/// @brief This function generates all possible permutations of the input array using a stack and a recursive approach.
/// @param nums Input array of integers.
/// @return A vector of vectors containing all possible permutations of the input array.
vector<vector<int>> permute(vector<int>& nums) {
    // Initialize a stack to store the current permutation and the index of the last inserted element
    stack< pair<vector<int>, int> > stk;
    // Initialize a vector to store the final result
    vector<vector<int>>  out; 

    // Push each element of the input array into the stack as a new permutation starting with that element
    for(int i = 0; i< nums.size();i++){
        // Create a temporary vector to store the current permutation
        vector<int> tmp ;
        // Add the current element to the temporary vector
        tmp.emplace_back(nums[i]);
        // Push the temporary vector and the index of the last inserted element into the stack
        stk.push( pair(tmp ,i));
    }

    // Keep popping elements from the stack until it's empty
    while(!stk.empty()){
        // Get the current permutation and the index of the last inserted element from the top of the stack
        pair<vector<int> ,int> s = stk.top();
        stk.pop();
        vector<int> curr = s.first; 

        // If the current permutation has the same length as the input array, it's a complete permutation so add it to the result
        if(curr.size() == nums.size()){
            out.push_back(curr);
            continue;
        }

        // For each element in the input array that hasn't been used in the current permutation yet
        for(int i = 0 ; i< nums.size(); i++ ){
            // If the element has not been used in the current permutation
            if( find(curr.begin(), curr.end(),nums[i]) == curr.end() ){
                // Add the element to the current permutation and push the modified permutation and the index of the last inserted element onto the stack
                curr.emplace_back(nums[i]);
                stk.push(pair(curr, i));
                // Remove the last inserted element from the current permutation to backtrack and try other permutations
                curr.pop_back();
            } 
        }
    }

    // Return the result
    return out;
}

// Second method for generating permutations
// This method assumes that all elements in the input array are less than 11
vector<vector<int>> out;

/// @brief This function generates permutations of the input array using recursion.
/// @param nums Input array of integers.
/// @param curr Current permutation.
/// @param idx Index of the last inserted element.
void rec(vector<int>& nums, vector<int> curr, int idx){
    // If all elements in the input array have been used, add the current permutation to the result
    if(idx == nums.size()){
        out.push_back(curr);
        return;
    }

    // For each element in the input array that hasn't been used in the current permutation yet
    for(int i =0; i< nums.size(); i++){
        // If the current element is still unused in the current permutation
        if(curr[i] == 11 ){
            // Move the current element to the next position in the permutation
            curr[i] = nums[idx];
            // Recursively generate permutations for the next position
            rec(nums,curr, idx+1);
            // Move the current element back to the original position in the permutation
            curr[i] = 11;
        }
    }
}

/// @brief This function generates all possible permutations of the input array using recursion.
/// @param nums Input array of integers.
/// @return A vector of vectors containing all possible permutations of the input array.
vector<vector<int>> permute(vector<int>& nums) {
    // Create a temporary vector with all elements set to 11
    vector<int> tmp(nums.size(),11);
    // Generate permutations starting from the first position
    rec(nums,tmp ,0);
    // Return the result
    return out;
}

