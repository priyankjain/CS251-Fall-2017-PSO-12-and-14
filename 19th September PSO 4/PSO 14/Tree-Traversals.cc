// Different traversals for a binary tree

#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int val): val(val), left(nullptr), right(nullptr) {}
	~Node() {
		if(left)
			delete left;
		if(right)
			delete right;
	}
};

void Inorder(Node* root) {
	if(root != nullptr) {
		Inorder(root->left);
		// Process current node
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
	if(root != nullptr) {
		Postorder(root->left);
		Postorder(root->right);
		cout << root->val << " ";
	}
}
/* Walk through level-order traversal with example
			1

		2		3

	4	  5   6	   7

	queue
	1
			Output: 1
	2,3
	3		Output: 2
	3,4,5
	4,5		Output: 3
	4,5,6,7 
	5,6,7	Output: 4
	*/
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
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	cout << "Printing inorder traversal of the tree" << endl;
	Inorder(root);
	cout << endl;

	cout << "Printing preorder traversal of the tree" << endl;
	Preorder(root);
	cout << endl;

	cout << "Printing postorder traversal of the tree" << endl;
	Postorder(root);
	cout << endl;

	cout << "Printing level-order traversal of the tree" << endl;
	Levelorder(root);
	cout << endl;

	delete root;
	return 0;
}