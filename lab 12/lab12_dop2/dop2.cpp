#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
};

Node* createNode(int value) {
	Node* node = new Node;
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node* createTree(int arr[], int n) {
	Node* root = createNode(arr[0]);
	Node* curr = root;
	for (int i = 1; i < n; i += 2) {
		curr->left = createNode(arr[i]);
		if (i + 1 < n) {
			curr->right = createNode(arr[i + 1]);
		}
		curr = curr->right;
	}
	return root;
}

void printTree(Node* node, int depth = 0) {
	if (node == NULL) return;
	printTree(node->right, depth + 1);
	for (int i = 0; i < depth; i++) {
		cout << "  ";
	}
	cout << node->value << endl;
	printTree(node->left, depth + 1);
}


int main() {
	int size;
	cin >> size;
	int* a = new int[size];
	for (int i = 0; i < size; i++) {
		a[i] = rand() % 20;
		cout << a[i] << " ";
	}

	Node* root = createTree(a, size);

	cout << endl;
	printTree(root);

	return 0;
}
