/* A program to convert Binary Tree to Binary Search Tree */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/* A binary tree Node structure */
typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

/* A helper function that stores inorder traversal of a tree rooted
with Node */
void storeInorder(Node* Node, int inorder[], int* index_ptr)
{
	// Base Case
	if (Node == NULL)
		return;

	/* first store the left subtree */
	storeInorder(Node->left, inorder, index_ptr);

	/* Copy the root's data */
	inorder[*index_ptr] = Node->data;
	(*index_ptr)++; // increase index for next entry

	/* finally store the right subtree */
	storeInorder(Node->right, inorder, index_ptr);
}

/* A helper function to count nodes in a Binary Tree */
int countNodes(Node* root)
{
	if (root == NULL)
		return 0;
	return countNodes(root->left) + countNodes(root->right) + 1;
}

// Following function is needed for library function qsort()
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

/* A helper function that copies contents of arr[] to Binary Tree.
This function basically does Inorder traversal of Binary Tree and
one by one copy arr[] elements to Binary Tree nodes */
void arrayToBST(int* arr, Node* root, int* index_ptr)
{
	// Base Case
	if (root == NULL)
		return;

	/* first update the left subtree */
	arrayToBST(arr, root->left, index_ptr);

	/* Now update root's data and increment index */
	root->data = arr[*index_ptr];
	(*index_ptr)++;

	/* finally update the right subtree */
	arrayToBST(arr, root->right, index_ptr);
}

// This function converts a given Binary Tree to BST
void binaryTreeToBST(Node* root)
{
	// base case: tree is empty
	if (root == NULL)
		return;

	/* Count the number of nodes in Binary Tree so that
	we know the size of temporary array to be created */
	int n = countNodes(root);

	// Create a temp array arr[] and store inorder traversal of tree in arr[]
	int* arr = (int *)malloc(sizeof(int)*10);
	int i = 0;
	storeInorder(root, arr, &i);

	// Sort the array using library function for quick sort
	qsort(arr, n, sizeof(arr[0]), compare);

	// Copy array elements back to Binary Tree
	i = 0;
	arrayToBST(arr, root, &i);

	// delete dynamically allocated memory to avoid memory leak
	free(arr);
}

/* Utility function to create a new Binary Tree Node */
Node* newNode(int data)
{
	Node* temp =(Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

/* Utility function to print inorder traversal of Binary Tree */
void printInorder(Node* Node)
{
	if (Node == NULL)
		return;

	/* first recur on left child */
	printInorder(Node->left);

	/* then print the data of Node */
	printf("%d ", Node->data);

	/* now recur on right child */
	printInorder(Node->right);
}

/* Driver function to test above functions */
int main()
{
	Node* root = NULL;

	/* Constructing tree given in the above figure
		10
		/ \
		30 15
	/	 \
	20	 5 */
	root = newNode(10);
	root->left = newNode(30);
	root->right = newNode(15);
	root->left->left = newNode(20);
	root->right->right = newNode(5);

	// convert Binary Tree to BST
	binaryTreeToBST(root);

	printf("Following is Inorder Traversal of the converted BST: \n");
	printInorder(root);

	return 0;
}
