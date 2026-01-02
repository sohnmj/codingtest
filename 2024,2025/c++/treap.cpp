#include<iostream>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;


class Node {
public:
	int num;
	Node* left;
	Node* right;
	int prior;
	int size;
	Node(int num) :num(num), prior(rand()),left(NULL),right(NULL),size(1) {

	}
	void setleft(Node* nleft) {
		left = nleft;
		calcsize();
	}
	void setright(Node* nright) {
		right = nright;
		calcsize();
	}
	void calcsize() {
		size = 1;
		if (left) size +=left->size;
		if (right) size += right->size;

	}


};
typedef pair<Node, Node> Nodepair;
Nodepair split(int num,Node*root) {
	if (root->num > num) {
		Node* cur = root;
		while (true) {
			if (num > cur->left->num) {
				break;
			}
			else {
				cur = cur->left;
			}
		}
		cur->size -= cur->left->size;
		cur->left = NULL;
		


	}
}
Node* insert(Node*root,Node* node) {
	if (root == NULL){
		return node;
	}
	if (root->prior > node->prior) {
		if (root->num > node->num) {
			root->setleft(insert(root->left, node));
		}
		else {
			root->setright(insert(root->right, node));
		}
	}
	else {
		Nodepair child = split(node->num,root);
		node->setleft(child.first);
		node->setright(child.second);
		return node;
	}
}
int main() {
	int arr[] = {1,2,3,4,5,6};
	Node *root;
	for (int i = 0; i < 6; i++) {
		Node newnode(arr[i]);
		root=
	}

	


	
		
}
