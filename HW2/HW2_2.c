#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

/// tree 루트의 inorder traversal을 저장하는 함수
void storeInorder(Node* Node, int inorder[], int* index_ptr)
{
	
	if (Node == NULL)
		return;

	// 먼저 왼쪽 하위 트리를 저장 
	storeInorder(Node->left, inorder, index_ptr);

	// 루트 데이터 복사 
	inorder[*index_ptr] = Node->data;
	(*index_ptr)++; // increase index for next entry

	// 마지막으로 올바른 하위 트리 저장
	storeInorder(Node->right, inorder, index_ptr);
}

// 이진 트리에서 노드를 세는 도우미 함수
int countNodes(Node* root)
{
	if (root == NULL)
		return 0;
	return countNodes(root->left) + countNodes(root->right) + 1;
}


int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

// arr[]의 내용을 Binary Tree로 복사하는 도우미 함수.이 함수는 기본적으로 Binary Tree의 Inorder 순회를 수행하고 
// arr[] 요소를 이진 트리 노드에 하나씩 복사
void arrayToBST(int* arr, Node* root, int* index_ptr)
{
	if (root == NULL)
		return;

	// 먼저 왼쪽 하위 트리 업데이트
	arrayToBST(arr, root->left, index_ptr);

	// 이제 루트의 데이터를 업데이트하고 인덱스를 증가
	root->data = arr[*index_ptr];
	(*index_ptr)++;

	// 하위 트리 업데이트
	arrayToBST(arr, root->right, index_ptr);
}

void binaryTreeToBST(Node* root)
{
	
	if (root == NULL)
		return;


	int n = countNodes(root);

	int* arr = (int *)malloc(sizeof(int)*10);
	int i = 0;
	storeInorder(root, arr, &i);

	
	qsort(arr, n, sizeof(arr[0]), compare);

	i = 0;
	arrayToBST(arr, root, &i);

	free(arr);
}


Node* newNode(int data)
{
	Node* temp =(Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void printInorder(Node* Node)
{
	if (Node == NULL)
		return;


	printInorder(Node->left);
	printf("%d ", Node->data);
	printInorder(Node->right);
}


int main()
{
	Node* root = NULL;

	root = newNode(10);
	root->left = newNode(30);
	root->right = newNode(15);
	root->left->left = newNode(20);
	root->right->right = newNode(5);

	// 변환함수
	binaryTreeToBST(root);

	printf("Following is Inorder Traversal of the converted BST: \n");
	printInorder(root);

	return 0;
}
