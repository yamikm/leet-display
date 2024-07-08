/**
 * You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
 * Once you pay the cost, you can either climb one or two steps.
 * You can either start from the step with index 0, or the step with index 1.
 * Return the minimum cost to reach the top of the floor.

Example 1:

Input: cost = [10,15,20]
Output: 15

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6

Constraints:
2 <= cost.length <= 1000
0 <= cost[i] <= 999
 */

#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <= 1) return 0;
        for(int i = 2; i < cost.size(); i++){
            cost[i]+= min(cost[i-1] , cost[i-2]);
        }
        return min(cost[cost.size()-1] , cost[cost.size()-2] ) ;
}