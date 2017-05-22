class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        std::map<int, std::set<int>> tree;
        for (int i = 0; i < ppid.size(); ++i) {
            if (tree.find(ppid[i]) == tree.end()) {
                std::set<int> s;
                tree[ppid[i]] = s;
            }
            tree[ppid[i]].insert(pid[i]);
        }
        
        std::queue<int> que;
        std::vector<int> ans;
        que.push(kill);
        while (!que.empty()) {
            int id = que.front();
            ans.push_back(id);
            que.pop();
            for (auto it = tree[id].begin(); it != tree[id].end(); ++it)
                que.push(*it);
        }
        return ans;
    }
};