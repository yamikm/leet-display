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

vector<vector<int>> permute(vector<int>& nums) {
    stack< pair<vector<int>, int> > stk;
    vector<vector<int>>  out; 
    for(int i = 0; i< nums.size();i++){
        vector<int>tmp ;
        tmp.emplace_back(nums[i]);
        stk.push( pair(tmp ,i));
    }
    while(!stk.empty()){
        pair<vector<int> ,int> s = stk.top();
        stk.pop();
        vector<int> curr = s.first; 
        if(curr.size() == nums.size()){
            out.push_back(curr);
            continue;
        }
        for(int i = 0 ; i< nums.size(); i++ ){
            if( find(curr.begin(), curr.end(),nums[i]) == curr.end() ){
                curr.emplace_back(nums[i]);
                stk.push(pair(curr, i));
                curr.pop_back();
            } 
            
        }
    }
    return out;
}

//Second Method;
vector<vector<int>> out;
void rec(vector<int>& nums, vector<int> curr, int idx){
    if(idx == nums.size()){
        out.push_back(curr);
        return;
    }

    for(int i =0; i< nums.size(); i++){
        if(curr[i] == 11 ){
            curr[i] = nums[idx];
            rec(nums,curr, idx+1);
            curr[i] = 11;
        }
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<int> tmp(nums.size(),11);
    rec(nums,tmp ,0);
    return out;
}