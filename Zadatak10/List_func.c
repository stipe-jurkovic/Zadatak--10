#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List_func.h"
#include "Defined_sizes.h"
#include "Tree_func.h"

int InitListNode(NodeP node) {
	memset(node->CountryName, 0, MAX_COUNTRY_NAME_LEN);
	node->next = NULL;
	node->treehead = NULL;
	return EXIT_SUCCESS;
}



NodeP newListElement(NodeP list, char countryName[MAX_COUNTRY_NAME_LEN]) {

	NodeP Q = NULL;
	Q = malloc(sizeof(Node));
	if (!Q) {
		printf("Memory allocation fail!");
		return EXIT_FAILURE;
	}
	InitListNode(Q);
	strcpy(Q->CountryName, countryName);
	insertSorted(list, Q);

	return Q;
}
int insertSorted(NodeP list, NodeP Q) {
	NodeP temp = NULL;
	temp = list;

	while (temp->next != NULL && strcmp(Q->CountryName, temp->next->CountryName) > 0) {
		temp = temp->next;
	}
	if (temp != NULL) {
		Q->next = temp->next;
		temp->next = Q;
	}
	return EXIT_SUCCESS;
}

int printList(NodeP list) {
	NodeP temp;
	temp = list->next;
	if (!temp){
		printf("List is empty!\n"); 
		return EXIT_FAILURE;
	}
	while (temp!=NULL) {
		printf("Drzava: %s \n", temp->CountryName);
		printTreeinorder(temp->treehead);
		temp = temp->next;
	}
	return EXIT_SUCCESS;
}