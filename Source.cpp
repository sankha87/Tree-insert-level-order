#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "Stack.h"
#include <time.h>

typedef struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* createTree(int num);
void inorder(TreeNode* root);
void preorder(TreeNode* root);
void postorder(TreeNode* root);
void treeTraversal(TreeNode* root, char choice);

TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n)
{
	// Base case for recursion
	if (i < n)
	{

		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->data = arr[i];
		temp->left = NULL;
		temp->right = NULL;
		root = temp;

		root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);		// insert left child
																			//arr   = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
																			//index = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

		root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);		// insert right child
	}
	return root;
}

int main()
{
	int num;
	printf("Enter number of nodes : ");
	scanf("%d", &num);
	TreeNode *root = createTree(num);

	printf("Inorder : \n");
	treeTraversal(root, 'i');

	printf("\n\nPreorder : \n");
	treeTraversal(root, 'p');

	printf("\n\nPostorder : \n");
	treeTraversal(root, 't');

	_getch();
}

TreeNode* createTree(int num)
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));

	int* arr = (int*)malloc(num * sizeof(int));
	for (int i = 1; i <= num; i++)
		arr[i - 1] = i;
	// arr = 1,2,3,4...10
	root = insertLevelOrder(arr, root, 0, num);

	return root;
}

void treeTraversal(TreeNode* root, char choice)
{
	switch (choice)
	{
	case 'i':
		inorder(root);
		break;
	case 'p':
		preorder(root);
		break;
	case 't':
		postorder(root);
		break;
	default:
		printf("\nWrong choice \n");
	}
}

void inorder(TreeNode* root)
{
	if (root == NULL)
		return;
	else
	{
		inorder(root->left);
		printf("%d \t", root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode* root)
{
	if (root == NULL)
		return;
	else
	{
		printf("%d \t", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode* root)
{
	if (root == NULL)
		return;
	else
	{

		postorder(root->left);
		postorder(root->right);
		printf("%d \t", root->data);
	}
}