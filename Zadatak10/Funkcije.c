#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funkcije.h"
#include "List_func.h"
#include "Tree_func.h"
#include "Defined_sizes.h"


int importFileCountries(NodeP list, char* filename) {
	FILE* fp = NULL;
	char buffer[MAX_LINE_LEN]= "\0";
	char CountryName[MAX_LINE_LEN] = "\0";
	char countryFilename[MAX_LINE_LEN] = "\0";
	NodeP currentListNode = NULL;

	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("File not found!\n");
		return EXIT_FAILURE;
	}
	while (!feof(fp)) {
		fgets(buffer, MAX_LINE_LEN, fp);
		if (sscanf(buffer, " %[^,], %[^\n]", CountryName, countryFilename) == 2){   
			currentListNode = newListElement(list, CountryName);
			importFileCities(&currentListNode->treehead, &countryFilename);
		}
	}
	return EXIT_SUCCESS;
}
int importFileCities(TreeP *treehead, char* filename) {
	FILE* fp = NULL;
	char buffer[MAX_LINE_LEN] = "\0";
	char TownName[MAX_LINE_LEN] = "\0";
	char townPopchar[MAX_LINE_LEN] = "\0";
	int townPopint = 0;

	memset(buffer, 0, MAX_LINE_LEN);

	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Couldn't open file %s!\n", filename);
		return EXIT_FAILURE;
	}
	while (!feof(fp)) {
		fgets(buffer, MAX_LINE_LEN, fp);
		if (sscanf(buffer, " %[^,], %[^\n] ", &TownName, &townPopchar) == 2
			&& sscanf(townPopchar, "%i", &townPopint)==1) {
			*treehead = newTreeNode(*treehead, TownName, townPopint);
		}
	}
	return EXIT_SUCCESS;
}
int displayFilteredTowns(NodeP list) {
	char countryname[MAX_STRING_LEN] = "\0";
	int popcount = 0;
	NodeP tempNode = NULL;
	memset(countryname, 0, MAX_STRING_LEN);
	printf("Enter the country name:   ");
	getInputString(&countryname);
	tempNode = findElByNodeName(list, countryname);
	if (!tempNode) {
		printf("Country not found!\n");
		return EXIT_FAILURE;
	}
	printf("\nEnter population:");
	getInputInt(&popcount);
	printf("\nCities:\n");

	printTreeinorderAboveVal(tempNode->treehead, popcount);
	return EXIT_SUCCESS;
}
int getInputInt(int* val)
{
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