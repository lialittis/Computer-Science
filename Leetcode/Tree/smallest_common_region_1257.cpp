/* VIP */

/* smallest common region
 * It is not a classical tree, but still a tree
 */

/* First Try 
 * brute force : read all nodes and store all ancetors of first node, then match the cloest ancestor of second node
 * O(n) ; O(n)
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string findSmallesRegion(vector<vector<string>>& regions, string region1, string region2) {
    // note the father for each node
    unordered_map<string, string> fa;

    for( const auto &v : regions) {
        for(int i = i; i< v.size(); ++i) {
            fa[v[i]] = v[0];
        }
    }

    unordered_set<string> anc;

    while(fa.find(region1) != fa.end()) {
        anc.insert(region1);
        region1 = fa[region1];
    }

    anc.insert(region1);

    while(fa.find(region2) != fa.end()) {
        if(anc.find(region2) != anc.end())
            return region2;
        region2 = fa[region2];
    }

    return region2;
}