#include "getmatrix.h"
int base2num(char b)
// just a numbering scheme for the input characters. This indexing will be used
// in the matrix into which it is read
{
    switch (b) 
    {
    case 'A': return 0; break;
    case 'R': return 1; break;
    case 'N': return 2; break;
    case 'D': return 3; break;
    case 'C': return 4; break;
    case 'Q': return 5; break;
    case 'E': return 6; break;
    case 'G': return 7; break;
    case 'H': return 8; break;
    case 'I': return 9; break;
    case 'L': return 10; break;
    case 'K': return 11; break;
    case 'M': return 12; break;
    case 'F': return 13; break;
    case 'P': return 14; break;
    case 'S': return 15; break;
    case 'T': return 16; break;
    case 'W': return 17; break;
    case 'Y': return 18; break;
    case 'V': return 19; break;
    case 'B': return 20; break;
    case 'Z': return 21; break;
    case 'X': return 22; break;
    default: return -1;
    }
}

void str2int(char *line, int i, double *mat, char *arr)
{
    int m,k;
    char * endptr;
    endptr=line+1;
    for (m=0;m<23;m++)
    {
        k=base2num(arr[m]);
        if (k==-1)
            continue;
        mat[i*22+k]=strtol(endptr,&endptr,0);


    }
 }
 
 
void parseinp(FILE *fp, double *mat)
{
    int i,j;
    char line[256];
    char arr[23];

    while (fgets(line,256,fp)!=NULL)
    {    
        if (line[0]=='#')
            continue;

        i=3;
        j=0;
        if (base2num(line[3])!=-1) 
        //assumption: the first character is
        //part of the 20 bases
        {
            while(line[i]!='*') 
            // this is the first line of the table,
            // that which contains  A R N D etc.
            // store the chars in arr
            {
                arr[j]=line[i];
                j++;
                i+=3;
            }   
            continue;
        }   
        i=base2num(line[0]);
        if (i<0) // not one of the 20 core bases
        {
            continue;
        }
        else
        {
          //  printf("%d\n",i);
            str2int(line,i,mat,arr);
        }
    }
    
}

void get_blosum( double* mat)
{
    FILE *fp;
    
    fp =fopen("BLOSUM62","r");
    if (fp==NULL)
    {
        perror("failed to open protein matrix file!");
    }
    parseinp(fp, mat);
    
    

    fclose(fp);
	//cout<<endl<<"caramba";
    
}

int funct_score(char a, char b, double * mat)
{
	int i, j, scre;
	 
	i = base2num(a);
	j= base2num(b);
	scre= mat[i*22+j];
	return scre;
	free(mat);
        for (int i=0; i<600;i++){
        cout<<mat[i]<< " ";
        }
}
