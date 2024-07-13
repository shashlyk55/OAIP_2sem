#pragma once
struct Branch
{
	int Data;
	Branch* LeftBranch;
	Branch* RightBranch;
};

void menu();
Branch* Add(int aData, Branch*& aBranch);
void print(Branch* aBranch);
Branch* search(Branch* n, int a);
Branch* deleteNode(Branch* root, int key);
Branch* minValueNode(Branch* node);
void deleteTree(Branch* node);
int counting(Branch* aBranch);
void inOrderTraversal(Branch* root);
void preOrderTraversal(Branch* root);
int checkHeight(Branch* node);
bool isBalanced(Branch* root);