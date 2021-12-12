/* Easy String */

/* ransomNote is constructed from magazine
 * connected ?
 * only once for each letter
 */





/* First Try */

/* Find each char of ransomNote in magazine */

/* Self Test : 15 min but too slow 
 * Time : O(mlogn)
 * Space : O(1)
 */

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isExisted(char c, string& magazine) {
    int left = 0, right = magazine.size();
    while(left < right) {
        int mid = left + (right - left)/2;
        if(c == magazine[mid]){
            magazine.erase(magazine.begin()+ mid);
            return true;
        }
        else if(c > magazine[mid]) left = mid+1;
        else right = mid - 1;
    }  

    return false;
}

bool isContructed(string ransomNote, string magazine) {
    if(magazine.empty()) return false;
    sort(magazine.begin(),magazine.end());

    for(char c : ransomNote) {
        if(!isExisted(c,magazine)) return false;
    }
    return true;
}

/* Second method from discussion of leetcode */

/* Using unordered map or vector to store information 

 */

bool canConstruct(string ransomNote, string magazine ) {
    unordered_map<char,int> map(26);
    for(int i = 0; i< magazine.size(); ++i) {
        ++map[magazine[i]];
    }

    for(int j = 0; j <ransomNote.size() ; ++j) {
        if(--map[ransomNote[j]] < 0)
            return false;
        
    }
    return true;
}

// simpler , using list

bool canConstruct(string ransomNote, string magazine) {
    int freq[26]={0};
    for(int i=0;i<magazine.size();i++){
        freq[int(magazine[i])-'a']++;
    }
    for(int i=0;i<ransomNote.size();i++){
        freq[int(ransomNote[i])-'a']--;
    }
    for(int i=0;i<26;i++){
        if(freq[i]<0)
            return false;
    }
    return true;
}
