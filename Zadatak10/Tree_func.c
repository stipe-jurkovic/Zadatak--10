#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funkcije.h"
#include "Defined_sizes.h"
#include "List_func.h"

#define MAX_LINE_LEN 128
#define MAX_NUMBER_INT 10
#define MAX_STRING_LEN 128



int InitTreeNode(TreeP treeNode){
	memset(treeNode->cityName, 0, MAX_COUNTRY_NAME_LEN);
	treeNode->popCount = 0;
	treeNode->left = NULL;
	treeNode->right = NULL;
	return EXIT_SUCCESS;
}
TreeP newTreeNode(TreeP P, char* cityName, int val)
{
	TreeP Q;
	Q = malloc(sizeof(Tree));
	if (Q == NULL)
	{
		printf("Insufficient ram space!");
		return P;
	}
	InitTreeNode(Q);
	Q->popCount = val;
	strcpy(Q->cityName, cityName);
	P = insertTreeNode(P, Q);
	return P;
}
TreeP insertTreeNode(TreeP P, TreeP Q) {
	if (P == NULL) return Q;
	if (Q->popCount > P->popCount) {
		P->right = insertTreeNode(P->right, Q);
		return P;
	}
	else if (Q->popCount < P->popCount) {
		P->left = insertTreeNode(P->left, Q);
		return P;
	}
	else if (Q->popCount == P->popCount) {
		if (strcmp(Q->cityName , P->cityName)>0) {
			P->right = insertTreeNode(P->right, Q);
			return P;
		}
		else if (strcmp(Q->cityName, P->cityName) < 0) {
			P->left = insertTreeNode(P->left, Q);
			return P;
		}
		else {
			printf("City already in tree!");
			free(Q);
		}
	}
	return P;
}
int printNode(TreeP P)
{
	printf("%s: %i\n", P->cityName, P->popCount);
	return EXIT_SUCCESS;
}
int printTreeinorder(TreeP P) {
	if (P == NULL) return EXIT_SUCCESS;
	printTreeinorder(P->left);
	printNode(P);
	printTreeinorder(P->right);
	return EXIT_SUCCESS;
}