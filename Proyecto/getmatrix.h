#ifndef getmatrix_H
#define getmatrix_H

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int base2num(char b);
void str2int(char *line, int i, double *mat, char *arr);
void parseinp(FILE *fp, double *mat);
void get_blosum(double* mat);
int funct_score(char a, char b, double *mat);

#endif /* getmatrix_H */
