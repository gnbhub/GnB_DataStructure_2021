#include "Binary_Tree.h"
#include "Tree_Queue.h"
#include <math.h>
#include <string.h>

void BreadthFirst(Queue* q, TreeNode* root);

int main() {

    char input[100];

    printf("Input a string : ");
    scanf("%s", input);

    TreeNode** tNode = (TreeNode**)malloc(strlen(input) * sizeof(TreeNode*));
    Queue* q = CreateQueue();

    for (int i = 0; i < strlen(input); i++) {
        tNode[i] = CreateNode(NULL, input[i], NULL);
        Enqueue(q, tNode[i]);
        if (i == 0) {
            continue;
        }
        if (q->front->data->left == NULL && q->front->data->right == NULL) {
            q->front->data->left = tNode[i];
        }
        else if (q->front->data->right == NULL) {
            q->front->data->right = tNode[i];
        }
        if ((q->front->data->left != NULL) && (q->front->data->right != NULL)) {
            Dequeue(q);
        }

    }
    DestroyQueue(q);

    q = CreateQueue();

    //PreOrder -> root 먼저 읽고 왼쪽 subtree 읽고 그다음 오른쪽 subtree 읽는거
    printf("Pre-order : ");
    preOrder(*tNode);

    printf("\n");

    //InOrder -> left subtree 먼저 읽고 root값을 중간에 읽고 right subtree 읽는거
    printf("In-order : ");
    inOrder(*tNode);

    printf("\n");

    //PostOrder - > left subtree 읽고 right subtree 읽고 root값을 ㅁㅏ지막에 읽는거
    printf("Post-order : ");
    postOrder(*tNode);

    printf("\n");

    //BreadFirst
    printf("BreadFirst : ");
    BreadthFirst(q, *tNode);

    return 0;
}
void BreadthFirst(Queue* q, TreeNode* root) {
    TreeNode* curNode;
    curNode = root;
    while (curNode) { //curNode가 비어있으면 실행 종료

        printf("%c", curNode->data); //root값 읽기

        if (curNode->left != NULL) //left subtree가 비어있지 않으면
            Enqueue(q, curNode->left); //인큐

        if (curNode->right != NULL) //right subtree가 비어있지 않으면
            Enqueue(q, curNode->right); //인큐

        if (!IsEmptyQueue(q)) //큐가 비어있지 않으면
            curNode = Dequeue(q); //디큐
        else //큐가 비어있으면
            curNode = NULL; //끝
    }
}
