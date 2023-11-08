#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

int n;
vii ls;

vi dp;
int ans;
void solve() {
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < i; ++j) {
			if (ls[j].second < ls[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		ans = max(ans, dp[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;

	ls = vii(n);
	for (auto&& [a, b] : ls) {
		cin >> a >> b;
	}

	sort(ls.begin(), ls.end());
	dp = vi(n, 1);
	ans = 0;
	solve();

	cout << n - ans;

	return 0;
}