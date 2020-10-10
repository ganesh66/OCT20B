#include<iostream>
#include<vector>

int gcd(int a, int b) {
	//	std::cout << a << " " << b << "\n";
	int temp = b;
	if (a < b) {
		b = a;
		a = temp;
		temp = b;
	}
	b = a % b;
	if (b == 0) {
		return temp;
	}
	else {
		a = temp;
		return gcd(a, b);
	}
}

int main() {
	std::vector<int>ans;
	int T, N, K, X, Y;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		std::cin >> N >> K >> X >> Y;
		if (K == 0) {
			if (X == Y) {
				ans.insert(ans.end(), 1);
			}
			else {
				ans.insert(ans.end(), 0);
			}
		}
		else {
			K = gcd(N, K);
			//std::cout << K << "\n";
			if (abs(Y - X) % K == 0) {
				ans.insert(ans.end(), 1);
			}
			else {
				ans.insert(ans.end(), 0);
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == 1) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}
	}

	return 0;
}