#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Bag {
public:
	Bag() {
		datas.emplace_back(USet());
	};
	const int kError = -1;
	void add(int x) {
		bool done_add = false;
		for (auto &it : datas) {
			if (it.find(x) != it.end()) {
				continue;
			}
			else {
				it.insert(x);
				done_add = true;
				break;
			}
		}
		if (done_add)return;
		USet new_set; new_set.insert(x);
		datas.emplace_back(new_set);
	}

	void remove(int x) {
		bool back_remove = false;
		for (auto it = datas.rbegin(); it != datas.rend(); it++) {
			if (it->find(x) != it->end()) {
				it->erase(x);
				if (it->size() == 0)back_remove = true;
				break;
			}
		}
		if(back_remove)datas.pop_back();
	}
	int find(int x) {
		for (auto &it : datas) {
			if (it.find(x) != it.end())return *it.find(x);
		}
		return kError;
	}

	vector<int> findAll(int x) {
		vector<int>res;
		for (auto &it : datas) {
			if (it.find(x) != it.end()) {
				res.emplace_back(*it.find(x));
			}
		}
		return res;
	}
	void printall() {
		for (auto &it : datas) {
			for (auto a : it) {
				cout << a << ", ";
			}cout << endl;
		}
		cout << "-----" << endl;
	}
private:
	using USet = unordered_set<int>;
	vector<USet>datas;
};

int main() {
	Bag bag;
	{
		bag.add(1);
		bag.add(1);
		bag.add(1);
		bag.printall();
	}
	{
		auto it = bag.findAll(1);
		for (auto a : it)cout << "!" << a;
		cout << endl;
		bag.printall();
	}
	{
		bag.remove(1);
		bag.printall();
	}

	{
		bag.add(2);
		bag.printall();
	}
	{
		bag.remove(1);
		bag.printall();
	}
	{

		bag.remove(2);
		bag.printall();
	}
}