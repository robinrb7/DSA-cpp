class Solution {
private:
    struct Event {
        double x, y1, y2;
        int type; // +1 add, -1 remove
        bool operator<(const Event& other) const {
            return x < other.x;
        }
    };

    double unionArea(const vector<Event>& events) {
        multiset<pair<double,double>> active;
        double area = 0.0;

        for (int i = 0; i + 1 < events.size(); i++) {
            if (events[i].type == 1)
                active.insert({events[i].y1, events[i].y2});
            else
                active.erase(active.find({events[i].y1, events[i].y2}));

            double dx = events[i + 1].x - events[i].x;
            if (dx == 0 || active.empty()) continue;

            double covered = 0, curL = -1e18, curR = -1e18;
            for (auto &[l, r] : active) {
                if (l > curR) {
                    covered += max(0.0, curR - curL);
                    curL = l;
                    curR = r;
                } else {
                    curR = max(curR, r);
                }
            }
            covered += max(0.0, curR - curL);
            area += covered * dx;
        }
        return area;
    }

    double areaBelow(double y, vector<vector<int>>& squares) {
        vector<Event> events;
        for (auto &s : squares) {
            double x = s[0], b = s[1], l = s[2];
            double top = min(b + l, y);
            if (top <= b) continue;
            events.push_back({x, b, top, 1});
            events.push_back({x + l, b, top, -1});
        }
        sort(events.begin(), events.end());
        return unionArea(events);
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;
        for (auto &s : squares) {
            low = min(low, (double)s[1]);
            high = max(high, (double)s[1] + s[2]);
        }

        double total = areaBelow(high, squares);

        for (int i = 0; i < 60; i++) {
            double mid = (low + high) / 2;
            if (areaBelow(mid, squares) * 2 < total)
                low = mid;
            else
                high = mid;
        }
        return low;
    }
};