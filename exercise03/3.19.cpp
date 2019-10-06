#include<bits/stdc++.h>
using namespace std;

int main() {

	// The key point is that inverse is itself in xor operation.
	int x = 0b10101011;
	int y = 0b00110101;
	//             [pre]   -> [after]
	x = x ^ y; // (x  , y) -> (x^y, x)
	y = x ^ y; // (x^y, y) -> (x^y, x)
	x = x ^ y; // (x^y, x) -> (y  , x)

	cout << x << ", " << y << endl;

}
