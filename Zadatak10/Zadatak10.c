// Zadatak10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include "Funkcije.h"
#include "List_func.h"

int main(void) {
	NodeP list = NULL;
	list = malloc(sizeof(Node));
	InitListNode(list);
	importFileCountries(list, "drzave.txt");
	printList(list);
	return EXIT_SUCCESS;
}
