#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int sz = prices.size();
        if(!k || sz < 1) return 0;
        vector<int> profits;
        stack<pair<int, int> > ss;
        for(int ll = 0, rr = 0; rr < sz;) {
            for(ll = rr; ll + 1 < sz && prices[ll] >= prices[ll + 1]; ll++);
            for(rr = ll + 1; rr < sz && prices[rr] >= prices[rr - 1]; rr++);
	    cout << ll << ", " << rr << endl;
            while(!ss.empty() && prices[ll] <= prices[ss.top().first]) {
                profits.emplace_back(prices[ss.top().second - 1] - prices[ss.top().first]);
                ss.pop();
            }
            while(!ss.empty() && prices[rr - 1] >= prices[ss.top().second - 1]) {
                profits.emplace_back(prices[ss.top().second - 1] - prices[ll]);
                ll = prices[ss.top().first];
                ss.pop();
            }
	    cout << ll << ", " << rr << endl;
            ss.push(make_pair(ll, rr));
        }
        while(!ss.empty()) {
            profits.emplace_back(prices[ss.top().second - 1] - prices[ss.top().first]);
            ss.pop();
        }
        if(k >= profits.size()) {
            return accumulate(profits.begin(), profits.end(), 0);
        }
        else {
            nth_element(profits.begin(), profits.begin() + profits.size() - k, profits.end());
	    for(auto n : profits) {
		cout << n << " ";
	    }
	    cout << endl;
            return accumulate(profits.begin() + profits.size() - k, profits.end(), 0);
        }
    }
};

int main() {
    Solution *sol = new Solution();
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    sol->maxProfit(2, prices);
    return 0;
}
