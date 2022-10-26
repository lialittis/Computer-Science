/* Array, String, Hashing*/

/* 
 * Two strings s and t, return true if t is an anagram of s
 *
 * An Anagram is a word or phrase formed by rearranging the 
 * letters of a different word or phrase, 
 * typically using all the original letters exactly once.
 * 
 * e.g. : s = "anagram", t = "nagaram" => true
 * e.g. : s = "rat", t = "car" => false
 *
 * */

// First idea : hash table for first one, check the second containning
// with counts
// O(n) & O(n)

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution{
public:
	bool isAnagram(string s, string t){
		// first method
		if(s.size() != t.size()) return false;

		unordered_map<char,int> hash;
		for(auto c : s){
			if(hash.find(c) == hash.end())
				hash[c] = 1;
			else
				hash[c] += 1;
		}

		for(auto c : t){
			if(hash.find(c) == hash.end() || hash[c] <= 0)
				return false;
			else
				hash[c] -= 1;
		}

		// another method to ensure anagram:
		// read the hash table and make sure each value is 0

		return true;
	}
};

// A better idea is to use vector store 26 counts
// faster than unordered map
//
class SolutionVector{
public:
	bool isAnagram(string s, string t){
		if (s.size() != t.size())
			return false;

		vector<int> count(26); // initialize as 0s

		for (int i = 0; i < s.size(); i++) {
			count[s[i] - 'a'] ++;
		}

		// second string
		for (int j = 0; j< t.size(); j++){
			count[t[j] - 'a']--;
			if(count[t[j] - 'a'] < 0)
				return false;
		}
		return true;
	}
};


