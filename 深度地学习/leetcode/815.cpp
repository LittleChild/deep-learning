class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        auto query = unordered_map<int, vector<vector<int>*>> {};
        for (auto&& route : routes)
            for (auto e : route)
                query[e].push_back(&route);
        auto q = queue { deque { source } };
        for (auto cnt = 0; !q.empty(); ++cnt) {
            for (auto i = q.size(); i; --i) {
                auto f = q.front();
                q.pop();
                if (f == target) return cnt;
                for (auto&& r : query[f]) {
                    for (auto&& e : *r)
                        q.emplace(e);
                    r -> clear();
                }
            }
        }
        return -1;
    }
};
//将车站作为节点即可 每次将车站经过的线路的所有车站加入下一层
