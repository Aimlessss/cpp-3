#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1; // Number of test cases
	cin >> t;

	while (t--) {
		ll n; // Length of the array
		cin >> n;
		ll a; // Temporary variable to store array elements
		vector<pair<ll, ll>> v; // Vector to store array elements along with their indices

		// Read the array elements and store them with their indices
		for (int i = 0; i < n; i++) { // O(n)
			cin >> a;
			v.push_back({a, i});
		}

		vector<ll> pre(n); // Prefix sum array
		// Sort the vector based on the array elements
		sort(v.begin(), v.end()); // O(nlogn)

		// Calculate prefix sums
		pre[0] = v[0].first;
		for (int i = 1; i < n; i++) { // O(n)
			pre[i] = pre[i - 1] + v[i].first;
		}

		vector<ll> ans(n); // To store the result for each element

		// Calculate the maximum number of additional elements that can be removed
		for (int i = 0; i < n; i++) { // O(nlogn)
			int j = i;
			int found = i;
			while (j < n) {
				pair<ll, ll> temp = {pre[j] + 1, INT_MIN};
				ll idx = lower_bound(v.begin(), v.end(), temp) - v.begin();
				idx--;
				if (idx == j) {
					break;
				}
				found += idx - j;
				j = idx;
			}
			ans[v[i].second] = found;
		}

		// Output the results for the current test case
		for (int i = 0; i < n; i++) { // O(n)
			cout << ans[i] << " ";
		}
		cout << endl;
	}

	// Time Complexity (TC): O(nlogn)
	// Space Complexity (SC): O(n)
}
