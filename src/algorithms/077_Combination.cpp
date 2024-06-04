/*
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
*/

#include <vector>
#include <stack>
using namespace std;
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> out;
    stack< vector<int> > stk;
    for(int i = 1 ; i<= n ; i++){
        stk.push({i});
    }
    
    while(!stk.empty()){
        vector<int> curr = stk.top();
        stk.pop();
        if(curr.size() == k) {
            out.push_back(curr);
            continue;
        }
        for(int i = curr[curr.size()-1] +1; i<= n  ; i++){
            curr.push_back(i); 
            stk.push(curr);
            curr.pop_back();
        }
    }

    return out;
}

//2nd method:
vector<vector<int>> out;
void rec( int cn, int n , vector<int> curr, int k){
    if(curr.size() == k){
        out.push_back(curr);
        return;
    }
    if(cn > n) return;
    for(int i = cn; i<= n; i++ ){
        curr.push_back(i);
        rec(i +1, n, curr, k );
        curr.pop_back();
    }   

}
vector<vector<int>> combine(int n, int k) {
    vector<int> em;
    rec( 1 ,n, em, k );
    return out;
}
