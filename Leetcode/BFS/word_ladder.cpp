/* BFS */

/* 
 * Shorest transformation from one word to another word,
 * each intermediate word must exist in the dictionary
 *
 * e.g. start = "hit", end = "cog", dict = ["hot","dot","dog","lot","log"]
 *
 *
 * */

#include <string>
#include <unordered_set>
#include <queue>

using namespace std;


// A typical BFS structure

class SolutionBFS{
public:
	int ladderLength(string beginWord, string endWord, vector<string> & wordList){
		//vector to dict
		unordered_set<string> dict(wordList.begin(),wordList.end());
		queue<string> q;

		q.push(beginWord);
		int ladder = 1;
		
		// finished when queue is empty
		while(!q.empty()){
			// because it it BFS,
			// read all element in current queue state(level)
			int n = q.size();
			for(int i = 0; i < n; ++i){
				string word = q.front(); // get the first q word
				q.pop();
				// find our target
				if(word == endWord){
					return ladder;
				}


				// for each element in the last level,
				// find all one-step word in dict and push them into queue =>
				// construct a new level
				for(int j = 0; j < word.size(); j++){
					char c = word[j];
					for (int k = 0; k< 26; k++) {
						word[j] = 'a' + k;
						if (dict.find(word) != dict.end()){
							q.push(word);
							dict.erase(word);
						}
					}
					// don't forget to change it back
					word[j] = c;
				}
			}
			ladder++;
		}
		return 0;
	}
};


/* 
 * Two-end search
 *
 *
 * */
class SolutionTwoEnd{
public:
	int ladderLength(const string& beginWord, const string& endWord, vector<string>& wordList){
		unordered_set<string> dict(wordList.begin(),wordList.end()), head, tail, *phead, *ptail;

		if (dict.find(endWord) == dict.end()){
			return 0;
		}

		head.insert(beginWord);
		tail.insert(endWord);

		int ladder = 2;

		while(!head.empty() && !tail.empty()){
			// always take the smaller one as head
			if(head.size() < tail.size()){
				phead = &head;
				ptail = &tail;
			} else {
				phead = &tail;
				ptail = &head;
			}

			unordered_set<string> temp;

			for(auto it = phead->begin(); it != phead->end(); it++){
				string word = *it;
				for(int i = 0; i< word.size();++i){
					char c = word[i];
					for(int j = 0; j< 26; ++j){
						word[i] = 'a' + j;
						if(ptail->find(word) != ptail->end())
							return ladder;
						if(dict.find(word) != dict.end()){
							temp.insert(word);
							dict.erase(word);
						}
					}
					word[i] = c;
				}
			}
			ladder ++;
			phead->swap(temp);
		}
		return 0;
	}
};


// The following is a more professional and complete method

struct state_t {
	string word;
	int level;

	state_t() {word = ""; level = 0;}
	state_t(const string& word, int level){
		this->word = word;
		this->level = level;
	}
	bool operator==(const state_t &other) const{
		return this->word == other.word;
	}
};

namespace std {
	template<> struct hash<state_t>{
	public:
		size_t operator()(const state_t& s) const {
			return str_hash(s.word);
		}
	private:
		std::hash<std::string> str_hash;

	};
};

class Solution{
public:
	int ladderLength(const string& start,const string& end,const unordered_set<string>& dict){
		queue<state_t> q;
		unordered_set<state_t> q; // 
		// TODO : Unfinished
	}
};


