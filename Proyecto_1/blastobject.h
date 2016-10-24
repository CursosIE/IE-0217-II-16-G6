#ifndef blastobject_H
#define blastobject_H

#include "getmatrix.h"
#include <iostream>
#include <stdlib.h> 
#include <string>

using namespace std;

class blastobject{

public:

    blastobject();
    blastobject(const blastobject& orig);
    virtual ~blastobject();
    
    int rawscore;
    int gapcounter;
    int size;
    const char * base;
    int T;

    int gapclear(char** lista);
    int raw(char** lista);
    int gap(char** lista, int n);
    int repeater(char** lista, int n);
    int rescore(char* arr_out, char** list, double* matrix);
    char* extend(int ind_extend, int ptr_match, int  ptr_match2, int wrd_size, char** list, char* arr_out, double* matrix);
    void printer(char* arr_out);

};
#endif /* blastobject_H */
