/**
 * A string can be abbreviated by replacing any number of non-adjacent, 
 * non-empty substrings with their lengths. The lengths should not have leading zeros.
 * For example, a string such as "substitution" could be abbreviated as (but not limited to):

    "s10n" ("s ubstitutio n")
    "sub4u4" ("sub stit u tion")
    "12" ("substitution")
    "su3i1u2on" ("su bst i t u ti on")
    "substitution" (no substrings replaced)
& The following are not valid abbreviations:

    "s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
    "s010n" (has leading zeros)
    "s0ubstitution" (replaces an empty substring)

* Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.

* A substring is a contiguous non-empty sequence of characters within a string.

* Example 1:
    Input: word = "internationalization", abbr = "i12iz4n"
    Output: true
    Explanation: The word "internationalization" can be abbreviated as "i12iz4n" ("i nternational iz atio n").

* Example 2:
    Input: word = "apple", abbr = "a2e"
    Output: false
    Explanation: The word "apple" cannot be abbreviated as "a2e".

* Constraints:
    1 <= word.length <= 20
    word consists of only lowercase English letters.
    1 <= abbr.length <= 10
    abbr consists of lowercase English letters and digits.
    All the integers in abbr will fit in a 32-bit integer.
 */

/**
 * Algorithm approach:
 * The algorithm takes a word and an abbreviation as input, and verifies whether the word matches the given abbreviation.
 * The algorithm works by iterating through the characters in the abbreviation and comparing them with the characters in the word.
 * If the characters match, the algorithm moves on to the next character in both the abbreviation and the word.
 * If the characters don't match, the algorithm checks if the current character in the abbreviation is a digit.
 * If it is, the algorithm moves the position in the word forward by the number given by the digit.
 * If the character is not a digit, the algorithm returns false, because the string doesn't match the given abbreviation.
 * If the algorithm reaches the end of the abbreviation, but there are still characters left in the word, the algorithm returns false.
 * If the algorithm reaches the end of the word, but there are still characters left in the abbreviation, the algorithm returns false.
 * If the algorithm runs out of characters in both the abbreviation and the word, the algorithm returns true.
 */

#include <sstream>
#include <string>

using namespace std;
bool validWordAbbreviation(string word, string abbr) {
    // the index of the current character in the word
    int wc = 0;
    for (int i = 0; i < abbr.size(); i++) {
        // if we have already iterated through all the characters in the word, return false
        if (wc >= word.size()) return false;
        // if the current character in the abbreviation is equal to the current character in the word,
        // move on to the next character in both the abbreviation and the word
        if (word[wc] == abbr[i]) {
            wc++;
            continue;
        }
        // if the current character in the abbreviation is '0', return false
        if (abbr[i] == '0') return false;
        // if the current character in the abbreviation is not a digit, return false
        if (!(abbr[i] >= '0' && abbr[i] <= '9')) return false;
        // read the number of characters to skip from the abbreviation
        string skipstr = "";
        while (i < abbr.size() && (abbr[i] >= '0' && abbr[i] <= '9')) {
            skipstr += abbr[i++];
        }
        // move the index of the current character in the abbreviation back to the last digit
        i--;
        int skip = 0;
        stringstream ss;

        ss << skipstr;
        ss >> skip;
        // skip the given number of characters in the word
        wc += skip;
    }
    // if the index of the current character in the word is not equal to the length of the word, return false
    if (wc != word.size()) return false;
    // if the algorithm has finished iterating through all the characters in the abbreviation and the word, return true
    return true;
}
