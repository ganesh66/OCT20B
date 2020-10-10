#include<iostream>
#include<vector>

int main() {
	int T, n;
	long k;
	std::vector<long>ans;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		std::cin >> n >> k;
		long extra = 0;
		bool free = false;
		std::vector<long>q(n, 0);
		for (int i = 0; i < n; i++) {
			std::cin >> q[i];	
		}
		for (int i = 0; i < n; i++) {
			if (extra + q[i] < k) {
				ans.insert(ans.end(), i + 1);
				free = true;
				break;
			}
			extra = extra + q[i] - k;
		}
		if (!free) {
			ans.insert(ans.end(), n + extra / k + 1);
		}
	}
	for (long i : ans) {
		std::cout << i << "\n";
	}
	return 0;
}