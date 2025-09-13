#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string sorted_key;
        unordered_map<string, vector<string>> umap;
        for(int i = 0; i < strs.size(); i++) {
        	sorted_key = strs[i];
        	sort(sorted_key.begin(), sorted_key.end());
        	umap[sorted_key].push_back(strs[i]);
	    }
	    vector<vector<string>> res;
	    for (auto it = umap.begin(); it != umap.end(); ++it) {
    		res.push_back(it->second);
		}
    	return res;
    }
};
