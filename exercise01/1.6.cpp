#include<bits/stdc++.h>
using namespace std;

// not efficient. (for test!)

template<typename val_type = int>
class ListInterface {
public:
	ListInterface() {}

	size_t size() {
		return datas.size();
	}
	val_type get(int i) {
		return datas[i];
	}
	void set(int i, val_type x) {
		datas[i] = x;
	}
	void add(int i, val_type x) {
		datas.insert(datas.begin() + i, x);
	}
	void remove(int i) {
		datas.erase(datas.begin() + i, datas.begin() + i + 1);
	}
	void printAll() {
		for (auto it : datas) {
			cout << it << ",";
		}cout << endl;
		cout << "----------" << endl;
	}
private:
	vector<val_type>datas;
};


#include<unordered_set>
template<typename val_type = int>
class USetInterface {
public:

	USetInterface() {}

	size_t size() { return datas.size(); }

	bool add(val_type x) {
		if (datas.find(x) != datas.end())return false;
		datas.insert(x);
		return true;
	}

	val_type remove(val_type x) {
		if (datas.find(x) != datas.end()) {
			datas.erase(x);
			return *datas.find(x);
		}
		return NULL;
	}

	val_type find(val_type x) {
		if (datas.find(x) != datas.end()) {
			return *datas.find(x);
		}
		return NULL;
	}

private:
	unordered_set<val_type> datas;
};

template<typename val_type = int>
class SSetInterface {
public:
	SSetInterface() {}

	size_t size() { return datas.size(); }

	bool add(val_type x) {
		if (datas.find(x) != datas.end())return false;
		datas.insert(x);
		return true;
	}

	val_type remove(val_type x) {
		if (datas.find(x) != datas.end()) {
			datas.erase(x);
			return *datas.find(x);
		}
		return NULL;
	}

	val_type find(val_type x) {
		auto it = datas.lower_bound(x);
		if (it != datas.end())return *it;
		return NULL;
	}

private:
	set<val_type> datas;
};


int main() {

	if (0) {
		ListInterface<int> li;
		li.add(0, 1);
		li.printAll();
		li.add(0, 2);
		li.printAll();
		li.add(2, 3);
		li.printAll();

		li.remove(1);
		li.printAll();
	}

	USetInterface<int>uset;

	SSetInterface<int>sset;

}