// #Begin of Submit Code
class Solution {
public:
        vector<pair<int, int>> getSkyline(vector<vector<int>>& a) {
                const size_t n = a.size();
                auto cmpx = [&a](const int &u, const int &v) -> bool {
                        return a[u][1] == a[v][1] ? u > v : a[u][1] > a[v][1];
                };
                priority_queue<int, vector<int>, decltype(cmpx)> xpq(cmpx);
                auto cmph = [&a](const int &u, const int &v) -> bool {
                        return a[u][2] == a[v][2] ? u > v : a[u][2] < a[v][2];
                };
                priority_queue<int, vector<int>, decltype(cmph)> hpq(cmph);
                vector<pair<int, int>> ret;
                for (size_t i = 0; i < n || xpq.size(); ) {
                        int x;
                        if (xpq.empty() || (i < n && a[xpq.top()][1] >= a[i][0])) { // left
                                xpq.push(i); hpq.push(i);
                                x = a[i++][0];
                        } else { // right
                                x = a[xpq.top()][1]; xpq.pop();
                                while (hpq.size() && a[hpq.top()][1] <= x) hpq.pop();
                        }
                        int h = (hpq.empty() ? 0 : a[hpq.top()][2]);
                        if (ret.size() && x == ret.back().first) ret.back().second = max(h, ret.back().second);
                        else if (ret.empty() || h != ret.back().second) ret.emplace_back(x, h);
                }
                return ret;
        }
};
// #End of Submit Code




// #Begin of Submit Code
class Solution {
public:
        vector<pair<int, int>> getSkyline(vector<vector<int>>& a) {
                priority_queue<pair<int, int>> pq;
                vector<pair<int, int>> ret;
                for (size_t i = 0; i < a.size() || pq.size(); ) {
                        int x;
                        if (pq.empty() || (i < a.size() && pq.top().second >= a[i][0])) { // left
                                pq.emplace(a[i][2], a[i][1]);
                                x = a[i++][0];
                        } else { // right
                                x = pq.top().second;
                        }
                        while (pq.size() && pq.top().second <= x) pq.pop();
                        int h = (pq.empty() ? 0 : pq.top().first);
                        if (ret.size() && x == ret.back().first) ret.back().second = max(h, ret.back().second);
                        else if (ret.empty() || h != ret.back().second) ret.emplace_back(x, h);
                }
                return ret;
        }
};
// #End of Submit Code




#include "../../header.h"

// #Begin of Submit Code
class Solution {
public:
        vector<pair<int, int>> getSkyline(vector<vector<int>>& a) {
                vector<int> lines;
                for (size_t i = 0; i < 2*a.size(); i++) {
                        lines.emplace_back(i);
                }
                sort(lines.begin(), lines.end(), [&a](const int &u, const int &v) -> bool {
                        if (a[u/2][u&1] != a[v/2][v&1]) return a[u/2][u&1] < a[v/2][v&1];
                        if ((u&1) != (v&1)) return (u & 1) < (v & 1);
                        return (u & 1) ? a[u/2][2] < a[v/2][2] : a[u/2][2] > a[v/2][2];
                });

                vector<pair<int, int>> result;
                multiset<int> heights;
                for (auto id : lines) {
                        if (id & 1) {
                                heights.erase(heights.find(a[id/2][2]));
                        } else {
                                heights.insert(a[id/2][2]);
                        }
                        int h = heights.empty() ? 0 : *heights.rbegin();
                        if (result.empty() || h != result.back().second) {
                                result.emplace_back(a[id/2][id&1], h);
                        }
                }
                return result;
        }
};
// #End of Submit Code

#include "../../header.h"

// #Begin of Submit Code
class Solution {
public:
        vector<pair<int, int>> getSkyline(vector<vector<int>>& a) {
                vector<int> lines;
                for (size_t i = 0; i < 2*a.size(); i++) {
                        lines.emplace_back(i);
                }
                sort(lines.begin(), lines.end(), [&a](const int &u, const int &v) -> bool {
                        if (a[u/2][u&1] != a[v/2][v&1]) return a[u/2][u&1] < a[v/2][v&1];
                        if ((u&1) != (v&1)) return (u & 1) < (v & 1);
                        return (u & 1) ? a[u/2][2] < a[v/2][2] : a[u/2][2] > a[v/2][2];
                });

                auto cmp = [&a](const int &u, const int &v) -> bool {
                        return a[u][2] != a[v][2] ? a[u][2] > a[v][2] : u > v;
                };
                set<int, decltype(cmp)> rects(cmp);
                vector<pair<int, int>> result;
                for (auto id : lines) {
                        if (id & 1) {
                                rects.erase(id/2);
                        } else {
                                rects.insert(id/2);
                        }
                        int h = rects.empty() ? 0 : a[*rects.begin()][2];
                        if (result.empty() || h != result.back().second) {
                                result.emplace_back(a[id/2][id&1], h);
                        }
                }
                return result;
        }
};
// #End of Submit Code
