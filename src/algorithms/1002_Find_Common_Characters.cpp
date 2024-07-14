/**
 * Given a string array words, return an array of all characters that show up in all strings within the words 
 * (including duplicates). You may return the answer in any order.
 */


#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;


/**
 * METHOD 1.
 */
vector<string> commonChars(vector<string>& words) {
       // Create a vector to store the result.
    vector<string> result;  
    // Iterate through the characters of the first word.
    for(int i = 0; i < words[0].size(); i++){
        // Iterate through the rest of the words.
        int j = 1;
        for(; j < words.size(); j++){
            // If the current character is not in the current word, break out of the loop.  
            size_t itr = words[j].find(words[0][i] );
            if(itr != string::npos) {
                words[j][itr] = ' ';
            }else{
                break;
            }
        }
        // If the current character is in all the words, add it to the result.
        if(j == words.size()) result.push_back(string(1, words[0][i]));
    }
    return result;
}


/**
 * METHOD 2.
 * This function takes a string array words, and returns an array of all characters that show up in all strings within the words 
 * (including duplicates). You may return the answer in any order.
 * 
 * The algorithm works by iterating through the characters of the first word, and then comparing the characters with the rest of the words.
 * If a character is found in all the words, it is added to the result vector.
 */
vector<string> commonChars(vector<string>& words) {
    unordered_multiset<char> st; // Store the characters of the first word.
    vector<string> out; // Prepare an output vector for common characters.

    // Insert all characters of the first word into the set.
    for(int i = 0; i < words[0].size(); i++){
        st.insert(words[0][i]);
    }

    // Compare characters with the rest of the words.
    for(int i = 1; i < words.size(); i++){
        unordered_multiset<char> tmp; // Temporary set for current word comparison.
        for(int j = 0; j < words[i].size(); j++){
            auto itr = st.find(words[i][j]); // Search for the character in the set.
            if(itr != st.end()){ // If found, erase from 'st' to ensure it's not counted again.
                st.erase(itr);
                tmp.insert(words[i][j]); // Insert into temporary set.
            }
        }
        st = tmp; // Update the set with the common characters found in the current iteration.
    }
    
    // Convert characters in the set to strings and add to the output vector.
    for(auto ch: st){
        string s(1, ch);
        out.push_back(s);
    }
    return out; // Return the vector containing common characters.
}


/**
 * METHOD 3.
 * 
 * This function takes a string array words, and returns an array of all characters that show up in all strings within the words 
 * (including duplicates). You may return the answer in any order.
 * 
 * The algorithm works by first finding the frequency of each character in the first word.
 * Then, for each subsequent word, it finds the minimum frequency of each character between the current word and the first word.
 * Finally, it constructs the common characters by repeating each character by its frequency.
 */
vector<string> commonChars(vector<string>& words) {
    vector<string> out; // Prepare an output vector for common characters.
    vector<int> freq(26,0); // Frequency of each character in the first word.

    // Find the frequency of each character in the first word.
    for(int i =0; i< words[0].size(); i++){
        freq[words[0][i]-'a']++;
    }

    // Compare characters with the rest of the words.
    for(int i= 1; i< words.size(); i++){
        vector<int> tmp(26,0); // Temporary vector for current word comparison.
        // Find the frequency of each character in the current word.
        for(int j =0; j< words[i].size(); j++){
            tmp[words[i][j]-'a']++;
        }
        // Update the frequency of each character with the minimum between the current word and the first word.
        for(int j =0; j< 26; j++){
            freq[j] = min(freq[j], tmp[j]);
        }
    }

    // Construct the common characters by repeating each character by its frequency.
    for(int i =0; i< 26; i++){
        for(int j =0; j< freq[i]; j++){
            out.push_back(string(1, 'a'+i));
        }
    }
    return out; // Return the vector containing common characters.
}
