/* Hashing */

// Given a string s, sort it in decreasing order based on the frequency of the characters. 
// The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.
//
//

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {

        // bucket sorting, record each char and its frequency in bucktes,
        // indice are frequency
        unordered_map<char, int> freq;

        int max_count = 0;
        for(auto c : s){
            max_count = max(max_count,++freq[c]); // freq[c] initialize to 0;
        }
        vector<vector<char>> buckets(max_count+1);
        for(auto it : freq){
            buckets[it.second].push_back(it.first);
        }

        string sorted = "";
        for(int i = max_count; i >= 0; --i){
            for(auto c : buckets[i]){
                for(int j = 0; j<i; j++){
                    sorted.push_back(c);
                }
            }
        }
        return sorted;

        // One optimized way is to store string instead of char
    }
};


class SolutionOpt{ // using 8min 40seconds, with small bug of string constructor // string(number,char)
public:
	string frequencySort(string s){
		// firstly conclude the freq for each character
		unordered_map<char, int> freq;
		int max_freq = 0;
		for(auto c: s){
			max_freq = max(max_freq,++freq[c]);
		}

		// build bucket for characters => using string to record
		vector<string> buckets(max_freq+1);
		for(auto it : freq){
			buckets[it.second].append(it.second,it.first);
		}

		// read them from bucket to constuct a new string
		string ans;
		for(int i = max_freq; i>=0 ;--i){
			ans.append(buckets[i]);
		}
		return ans;
	}
};

