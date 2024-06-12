/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.

*/

// Method 1, with recurssion: 
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * This function is a recursive helper function for the isInterleave method.
 * It checks if the string s3 can be formed by interleaving the characters of
 * s1 and s2.
 * 
 * @param s1 The first string to interleave.
 * @param s2 The second string to interleave.
 * @param s3 The string to check if it can be formed by interleaving s1 and s2.
 * @param s1dx The current index into s1.
 * @param s2dx The current index into s2.
 * @param s3dx The current index into s3.
 * @param mp A map used to store the results of previous calls to this function.
 * 
 * @return True if s3 can be formed by interleaving s1 and s2, false otherwise.
 */
bool rec( string& s1 , string& s2, string& s3 , int s1dx, int s2dx, int s3dx, unordered_map<string, int>& mp ){
    // Create a string that uniquely identifies the current state of the recursion.
    string seen = to_string(s1dx) + to_string(s2dx) + to_string(s3dx); 
    
    // If we have already computed the result for this state, return it.
    if(mp.find(seen) != mp.end()) return mp[seen];
    
    // If we have reached the end of s3, it means we have successfully interleaved s1 and s2.
    if(s3dx >= s3.size()) return true; 

    // If the current character of s1 matches the current character of s3, try to interleave the rest of s1 and s2.
    if(  s1dx < s1.size()  && s1[s1dx] == s3[s3dx] ){
        if(rec(s1, s2,s3, s1dx+1, s2dx,s3dx+1 , mp)) {
            mp[seen] = 1;
            return true;
        }
    }
    // If the current character of s2 matches the current character of s3, try to interleave the rest of s1 and s2.
    if ( s2dx < s2.size() && s2[s2dx] == s3[s3dx] ){
        if(rec(s1, s2,s3, s1dx, s2dx+1,s3dx+1,mp)) {
            mp[seen] = 1;
            return true;
        }
    }
    
    // If we have not successfully interleaved s1 and s2, mark this state as unsuccessful.
    mp[seen] = 0;
    return false;
}

bool isInterleave(string s1, string s2, string s3) {
    if(s1.size() + s2.size() != s3.size()) return false;
    unordered_map<string, int> mp;
    return rec(s1,s2,s3,0,0,0, mp);   
}


// This function checks if the string s3 can be formed by interleaving the characters
// of s1 and s2. It uses a memoization technique to avoid redundant calculations.
//
// Parameters:
// - s1: the first string to interleave
// - i: the index of the current character in s1
// - s2: the second string to interleave
// - j: the index of the current character in s2
// - s3: the string to check if it can be formed by interleaving s1 and s2
// - k: the index of the current character in s3
// - memo: a 2D vector to store the results of previous calculations
//
// Returns:
// - true if s3 can be formed by interleaving s1 and s2, false otherwise
bool is_Interleave(string s1, int i, string s2, int j, string s3, int k,
                       vector<vector<int>>& memo) {
        // Base case: if we have reached the end of s1, s2, or s3, check if the remaining
        // characters of s2 and s3 are equal
        if (i == s1.length()) {
            return s2.substr(j) == s3.substr(k);
        }
        if (j == s2.length()) {
            return s1.substr(i) == s3.substr(k);
        }
        
        // If we have already computed the result for this state, return it
        if (memo[i][j] >= 0) {
            return memo[i][j] == 1 ? true : false;
        }
        
        bool ans = false;
        
        // If the current character of s1 matches the current character of s3, try to
        // interleave the rest of s1 and s2.
        if (s3[k] == s1[i] &&
            is_Interleave(s1, i + 1, s2, j, s3, k + 1, memo)) {
            ans = true;
        }
        
        // If the current character of s2 matches the current character of s3, try to
        // interleave the rest of s1 and s2.
        if (!ans && s3[k] == s2[j] &&
            is_Interleave(s1, i, s2, j + 1, s3, k + 1, memo)) {
            ans = true;
        }
        
        // Store the result of the current calculation
        memo[i][j] = ans ? 1 : 0;
        
        return ans;
}
/**
 * Determines if the characters of s1 and s2 can be interleaved to form s3.
 *
 * @param s1 The first string to interleave.
 * @param s2 The second string to interleave.
 * @param s3 The string to check if it can be formed by interleaving s1 and s2.
 *
 * @return True if s3 can be formed by interleaving s1 and s2, false otherwise.
 *
 * 
 */
bool is_Interleave_iterative(string s1, string s2, string s3) {
    if(s1.size() + s2.size() != s3.size()) return false;
    vector<bool> dp(s2.size() + 1 , 0);
   
    for(int i= 0; i<= s1.size(); i++){
        for(int j = 0; j <= s2.size() ; j++ ){
            if (i == 0 && j == 0) {
                dp[j] = true;
            } else if (i == 0) {
                dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
            } else if (j == 0) {
                dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
            }
            else if (  (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                        (dp[j - 1] && s2[j - 1] == s3[i + j - 1]) ) {
                dp[j] = true;
            }else{
                dp[j] = false;
            }
        }
    }
    return dp[s2.size()];
}
