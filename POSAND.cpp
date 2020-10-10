#include<iostream>
#include<vector>

bool isPowerofTwo(int a) {
	if (a == 0 | a == 1) {
		return false;
	}
	while (a != 1) {
		if (a % 2 != 0) {
			return false;
		}
		else {
			a = a / 2;
		}
	}
	return true;

}


int main() {
	int T, n;
	std::cin >> T;
	std::vector<std::vector<int>>ans;
	for (int i = 0; i < T; i++) {
		std::cin >> n;
		if (isPowerofTwo(n)) {
			ans.insert(ans.end(), std::vector<int>{-1});
		}
		else {
			std::vector<int>f5 = { 2,3,1,5,4 };
			if (n < 6) {
				if (n == 1) {
					std::vector<int>a = { 1 };
					ans.insert(ans.end(), a);
				}
				else if (n == 3) {
					std::vector<int>a = { 2, 3, 1 };
					ans.insert(ans.end(), a);
				}
				else if (n == 5) {
					ans.insert(ans.end(), f5);
				}
			}
			else {
				int poweroftwo = 8;
				for (int j = 6; j <= n; j++) {
					if (j < poweroftwo) {
						f5.insert(f5.end(), j);
					}
					else {
						f5.insert(f5.end(), j + 1);
						f5.insert(f5.end(), j);
						j = j + 1;
						poweroftwo *= 2;
					}
				}
				ans.insert(ans.end(), f5);
			}

		}
	}

	for (int i = 0; i < T; i++) {
		for (int a : ans[i]) {
			std::cout << a << " ";
		}
		std::cout << "\n";
	}

	return 0;
}