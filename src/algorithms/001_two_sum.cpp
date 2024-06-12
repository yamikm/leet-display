/**
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

*/

/*
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/

//code: 
#include <map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> out(2,0);
    map<int,int> tmp;
    for(int i=0; i< nums.size(); i++){
        int rem = target -nums[i]; 
        if(tmp.find(rem)!= tmp.end()){
            out[0] = i;
            out[1] = tmp[rem];
            return out;
        }
        tmp[nums[i]] =i; 
    }
    return out;
}