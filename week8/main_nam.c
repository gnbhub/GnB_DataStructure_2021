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
	

	destroyTree(tNode[0]);
	free(tNode);
	printf("end\n");

	return 0;
}
void BreadthFirst(Queue* q, TreeNode* root) {

}
