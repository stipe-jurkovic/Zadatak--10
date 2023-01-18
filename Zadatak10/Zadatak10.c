// Zadatak10.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include "Funkcije.h"
#include "List_func.h"
#include <io.h>
#include <fcntl.h>

int main(void) {
	NodeP list = NULL;
	char filename[MAX_STRING_LEN] = "\0";
	int exit = 1, returnfromImport = 0;
	list = malloc(sizeof(Node));
	if (!list) {
		printf("Memory allocation fail!");
		return EXIT_FAILURE;
	}
	InitListNode(list);
	do {
	memset(filename, 0, MAX_STRING_LEN);
	printf("Insert filename (drzave.txt):    ");
	getInputString(&filename);
	returnfromImport = importFileCountries(list, filename);
	} while (returnfromImport);
	
	if(!returnfromImport) {
		printList(list);
		while (exit) {
			printf("Search cities by country that have a greater population than an entered number.\n");
			displayFilteredTowns(list);
			printf("\nSearch again?(0 - no, anything else for yes)\n");
			getInputInt(&exit);
		}
	}

	deleteList(list);
	free(list);
	return EXIT_SUCCESS;
}
