#include<bits/stdc++.h>
using namespace std;

int main() {
	int cnt = 0;
	for (int x = -100; x <= 100; x++) {
		for (int y = -100;y <= 100; y++) {
			if (x + y == 2)cnt++;
		}
	}

	cout << cnt << endl;
}
