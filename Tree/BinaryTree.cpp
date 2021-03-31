// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
#include<iostream>
#include <queue>
using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};

// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node 
BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
//To search an element in BST, returns true if element is found
bool Search(BstNode* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

// to find minimum element in tree 
int findMin(BstNode* root) {
	if(root == NULL) {
		cout << "Error: Tree is empty \n";
		return -1;
	}
	BstNode* current = root;
	while(current->left != NULL) {
		current = current->left;
	}
	return current->data;
}

// to find maximum number in tree
int findMax(BstNode* root) {
	if(root == NULL) {
		cout << "Error: Tree is empty \n";
		return -1;
	}
	BstNode* current = root;
	while(current->right != NULL) 
		current = current->right;
	
	return current->data;
}
// height of tree = number of edges in longest path from the node to a leaf node
 int findHeight (BstNode* root) {
	 if(root == NULL) {
		 return -1;
	 }
	return max(findHeight(root->left),findHeight(root->right)) + 1;	 
 }

//  depth of a node = no. of edges in path from root to that node;
int findDepth(BstNode* root, int NodeData) { 
} 


// // Tree treversal algorithms
// 1: Breadth-first traversal or leavel order treversal O(n)
void breadthFirst(BstNode* root) {
	if(root == NULL) return ;

	queue<BstNode*> Q;
	Q.push(root);
	while(! Q.empty()) {
		BstNode* current = Q.front();
		cout << current->data << " ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
		Q.pop();
	}
}

// 2: depth-first traversal
	// i : preorder - root-left-right
	void depthFirstPreorder(BstNode* root) {
		if(root == NULL) return;
	
		cout << root->data << " ";
		depthFirstPreorder(root->left);
		depthFirstPreorder(root->right);
	}
	// ii : inorder - left-root-right
	void depthFirstInOrder(BstNode* root) {
		if(root == NULL) return;
	
		depthFirstInOrder(root->left);
		cout << root->data << " ";
		depthFirstInOrder(root->right);
	}
	// iii : postorder - left-right-root
	void depthFirstPostorder(BstNode* root) {
		if(root == NULL) return;
	
		depthFirstPostorder(root->left);
		depthFirstPostorder(root->right);
		cout << root->data << " ";
	}


// Delete a node in BST
	// 3 cases 
	/*
		case 1 : no child or leaf node
		case 2 : one child 
		case 3 : 2 child
			->find min in right-subTree
			->copy the value in targetted node
			->delete duplicate from right
				OR
			->find max in left-subtree;
			->copy the value in targetted node
			->delete duplicate from left
	*/
BstNode* deleteNode(BstNode* root,int deletedData) {

		if(root == NULL) return root;
		else if(deletedData < root->data) root->left = deleteNode(root->left,deleteNode);
		else if(data > root->data) root->right = deleteNode(root->right,deletedData);
		else {
			// case 1: no child node
			if(root->left == NULL and root->right) {
				delete root;
				root = NULL;
				return root;
			} 
			// case 2: 1 childe 
			else if(root->left == NULL) {
				BstNode* temp = root;
				root = root->right;
				delete temp;
			}
			else if(root->right == NULL) {
				BstNode* temp = root;
				root = root->left;
				delete temp;
			}
			/*case 3 : 2 child
				->find min in right-subTree
				->copy the value in targetted node
				->delete duplicate from right
					OR
				->find max in left-subtree;
				->copy the value in targetted node
				->delete duplicate from left
			*/
		else {
			BstNode* temp = findMin(root->right);
			root->data = temp->data;
			root->right = deletedData(root->right,temp->data);
		}


		}

}

int main() {
	BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	// Ask user to enter a number.  
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
}