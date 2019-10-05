#include<bits/stdc++.h>
using namespace std;

int main() {

	// the given sequence can be paraphrased with stack.
	// if +1: stack.push(x)
	// if -1: stack.pop()

	// you simulate these sequence from the prefix.
	// when stack is empty and the current operation is pop,
	// this sequence is not Dyck word.

	bool is_dyck_word = true;
	stack<int>st;
	int input;
	while (cin >> input) {
		if (input == 1) {
			st.push(1);
		}
		else {
			if (st.empty) {
				is_dyck_word = false;
			}
			else {
				st.pop();
			}
		}
	}
	cout << (is_dyck_word ? "OK" : "NG") << endl;

}