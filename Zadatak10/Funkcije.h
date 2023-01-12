#pragma once
#include <stdio.h>

#define MAX_COUNTRY_NAME_LEN 128

typedef struct node* NodeP;
typedef struct node {
	char CountryName[MAX_COUNTRY_NAME_LEN];
	TreeP treehead;
	NodeP next;
}Node;
typedef struct tree* TreeP;
typedef struct tree {
	char cityName[MAX_COUNTRY_NAME_LEN];
	int popCount;
	TreeP left;
	TreeP right;
}Tree;

