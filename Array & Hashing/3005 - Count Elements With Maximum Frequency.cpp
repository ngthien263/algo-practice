class Solution {
public:
    int maxFrequencyElements(vector<int>& n) {
        map<int, int> map;
        for(int i = 0; i < n.size(); i++) {
            map[n[i]]++;
        }
        auto max = max_element(map.begin(), map.end(), [](const auto &a, const auto &b){
            return a.second < b.second;
        });
        int res = 0;
        for(auto i = map.begin(); i != map.end(); i++) {
            if(max->second == i->second) res += i->second;
        }
        return res;
    }
};