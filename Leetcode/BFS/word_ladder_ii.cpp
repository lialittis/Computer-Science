/* BFS */

/* Word Ladder II
 *
 * find all shortest transformation sequence(s)
 *
 *
 * */

#include <vector>
#include <string>
#include <unordered_set>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

// ERROR memory List Exceeded
class SolutionBFS{
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList){
		// solve it by standard BFS
		// do BFS os paths instead of words

		vector<vector<string>> ans;
		queue<vector<string>> paths;

		//wordList.insert(endWord);

		paths.push({beginWord});

		int level = 1;
		int minLevel = INT_MAX;

		unordered_set<string> visited;

		while(!paths.empty()){
			// first level path
			vector<string> path = paths.front();
			paths.pop();
			if(path.size() > level) {
				// reach a new level
				for(string w:visited) wordList.erase(w);
				visited.clear();
				if(path.size()>minLevel) // when path is longer that min paths, stop the searching
					break;
				else
					level = path.size();
			}
			string last = path.back();
			// find next words in wordList by changing
			// each element form 'a' to 'z'
			for (int i = 0; i< last.size(); i++){
				string news = last;
				for(char c = 'a'; c<'z';c++){
					news[i] = c;
					if(wordList.find(news) != wordList.end()){
						vector<string> newpath = path;
						newpath.push_back(news);
						visited.insert(news); // we could erase w here as well. TODO:optimize
						if(news == endWord){
							minLevel = level;
							ans.push_back(newpath);
						}
						else
							paths.push(newpath);
					}
				}
			}
		}
		return ans;
	}
};
