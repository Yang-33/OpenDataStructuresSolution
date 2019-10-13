#include<bits/stdc++.h>
using namespace std;

int main() {
	for (int x = -100; x <= 100; x++) {
		int y = -x;
		assert(y + x == 0);
		make_pair(x, y);
	}
}
