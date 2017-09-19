// Different traversals for a binary tree
// Inorder, postorder, preorder, level-order

#include <queue>
#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int val): val(val), left(nullptr), right(nullptr) {}
	~Node() {
		if(left != nullptr)
			delete left;
		if(right != nullptr)
			delete right;
	}
};

void Inorder(Node* root) {
	if(root != nullptr) {
		Inorder(root->left);
		cout << root->val << " ";
		Inorder(root->right);
	} 
}

void Preorder(Node* root) {
	if(root != nullptr) {
		cout << root->val << " ";
		Preorder(root->left);
		Preorder(root->right);
	}
}

void Postorder(Node* root) {
	if(root!=nullptr) {
		Postorder(root->left);
		Postorder(root->right);
		cout << root->val << " ";
	}
}

void Levelorder(Node* root) {
	queue<Node*> q;
	if(root != nullptr)
		q.push(root);
	while(!q.empty()) {
		Node* node = q.front();
		q.pop();
		cout << node->val << " ";
		if(node->left != nullptr)
			q.push(node->left);
		if(node->right != nullptr)
			q.push(node->right);
	}
}

int main() {
	/*
				1
			  /   \ 
			2		3
		   /  \    /  \
		 4	   5  6    7
*/
	Node* node = new Node(1);
	node->left = new Node(2);
	node->right = new Node(3);
	node->left->left = new Node(4);
	node->left->right = new Node(5);
	node->right->left = new Node(6);
	node->right->right = new Node(7);

	cout << "Printing inorder traversal" << endl;
	Inorder(node);
	cout << endl;

	cout << "Printing preorder traversal" << endl;
	Preorder(node);
	cout << endl;

	cout << "Printing postorder traversal" << endl;
	Postorder(node);
	cout << endl;

	cout << "Printing level-order traversal" << endl;
	Levelorder(node);
	cout << endl;

	delete node;
	return 0;
}