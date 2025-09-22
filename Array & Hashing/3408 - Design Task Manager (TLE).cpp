/*TLE on case 660 due to row 26*/

class TaskManager {
public:
    unordered_map<int, pair<int, int>> umap;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); i++) {
            umap[tasks[i][1]] = make_pair(tasks[i][0], tasks[i][2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        umap[taskId] = make_pair(userId, priority);
    }
    
    void edit(int taskId, int newPriority) {
        umap[taskId].second = newPriority;
    }
    
    void rmv(int taskId) {
        umap.erase(taskId);
    }
    
    int execTop() {
        if(umap.empty())    return -1;
        auto max_it = max_element(umap.begin(), umap.end(),
                      [](const auto &a, const auto &b){
                        if(a.second.second == b.second.second){
                            return a.first < b.first;
                        }
                        return a.second.second < b.second.second;
                      });
        int res = max_it->second.first;
        umap.erase(max_it->first);
        return res;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */