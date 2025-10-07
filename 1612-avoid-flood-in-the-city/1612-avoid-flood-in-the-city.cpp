class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);  // Default 1 for dry days
        unordered_map<int, int> full; // lake -> last filled day
        set<int> dryDays; // indices of dry days (rains[i] == 0)

        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                dryDays.insert(i);
            } else {
                int lake = rains[i];
                ans[i] = -1;
                if (full.find(lake) != full.end()) {
                    // Find dry day after last fill day
                    auto it = dryDays.upper_bound(full[lake]);
                    if (it == dryDays.end()) return {};
                    ans[*it] = lake; // Dry this lake on that day
                    dryDays.erase(it);
                }
                full[lake] = i;
            }
        }
        return ans;
    }
};