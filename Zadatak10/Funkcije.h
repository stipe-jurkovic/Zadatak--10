#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "List_func.h"

int importFileCountries(NodeP list, char* filename);
int importFileCities(TreeP *treehead, char* filename);
int displayFilteredTowns(NodeP list);
int getInputInt(int* val);
int getInputString(char* string);
