#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef char Element;

typedef struct tTreeNode {
    Element data;
    struct tTreeNode* left, * right;
}TreeNode;

typedef struct Queue Queue;

TreeNode* CreateNode(TreeNode* left, Element data, TreeNode* right);

TreeNode* CreateNode(TreeNode* left, Element data, TreeNode* right) {
    TreeNode* pNewNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (pNewNode == NULL)
        return NULL;
    pNewNode->data = data;
    pNewNode->left = left;
    pNewNode->right = right;
    return pNewNode;
}

void destroyTree(TreeNode* root) {
    if (root == NULL)
        return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

void preOrder(TreeNode* root) {
    if (root == NULL)
        return;
    printf("%c", root->data);
    preOrder(root->left); //left subtree의 root값을 읽게 되는거
    preOrder(root->right); //right subtree의 root값을 읽게 되는거
}

void inOrder(TreeNode* root) {
    if (root == NULL)
        return;
    inOrder(root->left); //left subtree의 root값 읽고
    printf("%c", root->data); //root값 읽고
    inOrder(root->right); //right subtree의 root값 읽고
}

void postOrder(TreeNode* root) {
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c", root->data);
}
