/* Array, Hashing */

/*
 * an array of strings,
 * group the anagrams together
 *
 * return the answer in any order
 * 
 *
Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]

 * */

// first idea : hash table+is_anagram check function, vector<vector<string>>
// O(n^2) time


// Better; using unordered_map

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


using namespace std;

class Solution{
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs){
		unordered_map<string, vector<string>> m;
		for(int i = 0; i < strs.size(); i++){
			string key = getKey(strs[i]);
			m[key].push_back(strs[i]);
		}

		vector<vector<string>> result;
		for(auto it = m.begin(); it != m.end(); it++){
			result.push_back(it->second);
		}

		return result;
	}
private:
	string getKey(string str){
		vector<int> count(26);
		for(int j = 0; j<str.size(); j++){
			count[str[j] - 'a']++;
		}

		string key = "";
		for(int i = 0; i < 26; i++){
			key.append(to_string(count[i]+'a'));
		}

		return key;
	}
};

// Keys:
// 1. using vector to generate unique key for each word
// 2. to_string : char to string
// 3. string.append(string)
// 4. unordered_map is more powerful that vector


// Much better one

class SolutionSort {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hash_table;

        for(string& s: strs){
            string t = s;
            sort(t.begin(),t.end()); // using sort to make a key
            hash_table[t].push_back(s);
        }

        for(auto& e: hash_table){
            ans.push_back(e.second);
        }

        return ans;
    }
};
