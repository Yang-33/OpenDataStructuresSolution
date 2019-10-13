#include<bits/stdc++.h>
using namespace std;

struct Node {
	Node(Node* l = nullptr, Node* r = nullptr, int s = 1)
		: left(l), right(r), subtree_size(s) {}
	Node* left;
	Node* right;
	int subtree_size;
};

void subsize_update(Node *root) {
	int size = 1;
	if (root->left != nullptr) {
		subsize_update(root->left);
		size += root->left->subtree_size;
	}
	if (root->right != nullptr) {
		subsize_update(root->right);
		size += root->right->subtree_size;
	}
	root->subtree_size = size;
}

bool isBalanced(Node* root) {

	bool ok = 1;
	int Lsize = 0;
	int Rsize = 0;
	if (root->left != nullptr) {
		ok &= isBalanced(root->left);
		Lsize = root->left->subtree_size;
	}
	if (root->right != nullptr) {
		ok &= isBalanced(root->right);
		Rsize = root->right->subtree_size;
	}

	if (abs(Lsize - Rsize) <= 1) {
		ok &= true;
	}
	else {
		ok &= false;
	}

	return ok;
}

void add_edge_left(Node *from, Node *to) {
	from->left = to;
}
void add_edge_right(Node *from, Node *to) {
	from->right = to;
}

int main() {
	vector<Node>nodes(9);
	add_edge_left(&nodes[0], &nodes[1]);
	add_edge_left(&nodes[1], &nodes[2]);
	add_edge_right(&nodes[1], &nodes[3]);
	add_edge_right(&nodes[3], &nodes[4]);

	add_edge_right(&nodes[0], &nodes[5]);
	add_edge_left(&nodes[5], &nodes[6]);
	add_edge_right(&nodes[5], &nodes[7]);
	add_edge_right(&nodes[7], &nodes[8]);


	subsize_update(&nodes[0]);

	isBalanced(&nodes[0]);
}
