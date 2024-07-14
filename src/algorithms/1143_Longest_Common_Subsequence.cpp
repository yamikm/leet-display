/**
 * Given two strings text1 and text2, return the length of their longest common subsequence. 
 * If there is no common subsequence, return 0. A subsequence of a string is a new string generated 
 * from the original string with some characters (can be none) deleted without changing the relative 
 * order of the remaining characters. 
 * For example, "ace" is a subsequence of "abcde".
 * A common subsequence of two strings is a subsequence that is common to both strings.
 * 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 
Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.


 */


/*
 * This file contains the implementation of the longest common subsequence algorithm.
 * The algorithm finds the length of the longest subsequence that is common to both strings.
 * The longest common subsequence is a subsequence of the input strings, which is 
 * formed by selecting some characters from the first string and some characters 
 * from the second string.
 * 
 * The function `longestCommonSubsequence` takes two strings as input, `text1` and `text2`,
 * and returns the length of the longest common subsequence.
 * 
 * The algorithm works by using dynamic programming to build a table of the lengths 
 * of the longest common subsequence. The table is initialized with a row of zeros, and
 * each subsequent row is built by comparing each character in the second string with 
 * the corresponding character in the first string and adding the maximum of the two 
 * possibilities: either the length of the longest common subsequence ending at the
 * current character in the first string and the current character in the second string,
 * or the length of the longest common subsequence ending at the previous character
 * in the first string and the current character in the second string.
 * 
 * The algorithm runs in O(m * n) time, where m and n are the lengths of the input strings.
 */



/**
 * This problem is a classic example of a dynamic programming problem. The problem can be
 * broken down into smaller subproblems, and the solution to each subproblem can be used
 * to solve larger subproblems.
 * 
 * The key insight is that the length of the longest common subsequence ending at the
 * current character in the first string and the current character in the second string
 * depends only on the lengths of the longest common subsequence ending at the previous
 * character in the first string and the previous character in the second string, and
 * not on the characters themselves.
 * 
 * Therefore, we can build a table of the lengths of the longest common subsequence,
 * and fill it in bottom-up. The base case is when either string is empty, in which case
 * the length of the longest common subsequence is 0.
 * 
 * The time complexity of this algorithm is O(m * n), where m and n are the lengths of
 * the input strings.
 */

#include <vector>
#include <string>
using namespace std;

/**
 * Calculates the length of the longest common subsequence between two strings.
 * 
 * @param text1 The first string.
 * @param text2 The second string.
 * 
 * @return The length of the longest common subsequence.
 */
int longestCommonSubsequence(string text1, string text2) {
    // Base case: if either string is empty, return 0
    if(text1.size() == 0 || text2.size() ==0) return 0;
    
    // Base case: if the strings are equal, return the length of the first string
    if(text1 == text2) return text1.size();
    
    // Swap the strings if the first string is shorter than the second string
    if(text1.size() < text2.size()){
        string tmp = text1;
        text1 = text2;
        text2 = tmp;
    }
    
    // Create two vectors to store the lengths of the longest common subsequence
    vector<int> prev(text1.size()+1, 0);
    vector<int> curr(text1.size()+1, 0);

    // Iterate through the characters of the second string
    for(int i=text2.size()-1; i>= 0; i--){
        // Iterate through the characters of the first string
        for(int j=text1.size() -1; j>= 0; j--){
            // If the characters at the current positions are the same,
            // the length of the longest common subsequence is 1 + the length of the longest common subsequence ending at the previous positions
            if(text1[j] == text2[i]){
                curr[j] = 1 + prev[j+1];
            }
            // Otherwise, the length of the longest common subsequence is the maximum of the lengths of the longest common subsequence ending at the previous positions
            else{
                curr[j] = max(curr[j+1] ,prev[j] );
            }
        }
        // Update the vectors to store the lengths of the longest common subsequence for the next iteration
        prev = curr;
    }
    // Return the length of the longest common subsequence
    return curr[0];
}
