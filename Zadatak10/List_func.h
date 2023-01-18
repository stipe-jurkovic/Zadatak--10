#pragma once
#include "Tree_func.h"
#include "Defined_sizes.h"
#define _CRT_SECURE_NO_WARNINGS



typedef struct node* NodeP;
typedef struct node {
	char CountryName[MAX_COUNTRY_NAME_LEN];
	TreeP treehead;
	NodeP next;
}Node;

int InitListNode(NodeP node);
NodeP newListElement(NodeP list, char countryName[MAX_COUNTRY_NAME_LEN]);
int insertSorted(NodeP list, NodeP Q);
int printList(NodeP list);