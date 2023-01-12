#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funkcije.h"

#define MAX_LINE_LEN 128
#define MAX_NUMBER_INT 10
#define MAX_STRING_LEN 128


InitTreeNode(TreeP treeNode){
	memset(treeNode->cityName, 0, MAX_COUNTRY_NAME_LEN);
	treeNode->popCount = 0;
	treeNode->left = NULL;
	treeNode->right = NULL;
}
InitListNode(NodeP node) {
	memset(node->CountryName, 0, MAX_COUNTRY_NAME_LEN);
	node->next = NULL;
	node->tree
}



int readFileCountries(char* filename) {
	FILE* fp = NULL;
	char buffer[MAX_LINE_LEN]= "\0";
	char CountryName[MAX_LINE_LEN] = "\0";
	char countryFilename[MAX_LINE_LEN] = "\0";



	fp = fopen(filename, "r");
	if (fp == NULL) {
		return EXIT_FAILURE;
	}
	fgets(buffer, MAX_LINE_LEN, fp);
	if (sscanf(buffer, " %s %s", CountryName, countryFilename) != 2){
		return EXIT_FAILURE;
	}



}

int readFileCities(char* filename)) {
	FILE* fp = NULL;
	char buffer[MAX_LINE_LEN] = "\0";
	char TownName[MAX_LINE_LEN] = "\0";
	int townPop = 0;



	fp = fopen(filename, "r");
	if (fp == NULL) {
		return EXIT_FAILURE;
	}
	while (!feof(fp)) {
		fgets(buffer, MAX_LINE_LEN, fp);
		if (sscanf(buffer, " %s %i", TownName, townPop) != 2) {
			return EXIT_FAILURE;
		}
			
	}
	
}

int getInputInt(int* val)
{
	*val = 0;
	char input[MAX_NUMBER_INT] = "\0";
	memset(input, 0, MAX_NUMBER_INT);

	fgets(input, sizeof(input), stdin);

	if (sscanf(input, " %i", val) == 1) {
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
int getInputString(char* string)
{
	char input[MAX_STRING_LEN] = "\0";
	memset(input, 0, MAX_STRING_LEN);

	fgets(input, sizeof(input), stdin);

	if (sscanf(input, " %s", string) == 1) {
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}