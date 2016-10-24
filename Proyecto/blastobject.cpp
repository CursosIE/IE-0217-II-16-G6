#include "blastobject.h"



/**
 * @brief Constructor vacio de clase blastobject.
 */
blastobject::blastobject() {
    const char * base = "GGAATTGCAGGG"; //AGCCACGCACTA
    this->size = 12; //buscar funcion para esto
    this->rawscore = 0;
    this->gapcounter = 0;
    this->base = base;
    this->T=13;
}

/**
 * @brief Constructor de la clase blastobject.
 *
 * @param blastobject& Constante objeto.
 */
blastobject::blastobject(const blastobject& orig) {
}

/**
 * @brief Destructor de la clase blastobject.
 */
blastobject::~blastobject() {
}

/**
 * @brief Divide la secuencia ingresada y la conocida en varias palabras que después se comparan. 
 * 
 * @param list Datos ingresados por el usuaio.
 * @param wrd_size Tamaño de cada palabra.
 */

int blastobject::repeater(char** list, int wrd_size) {

    char secuencia[this->size - wrd_size][wrd_size];

    char comparador[this->size - wrd_size][wrd_size];

    int score = 0;

    int aux = 0, maxscre = 13, scre=0, ptr_match, ptr_match2;

    char HSP[3];    
    char* arr_out;
    arr_out = (char*) calloc (12,sizeof(char));
    double* matrix;
    matrix = (double*) calloc (600,sizeof(double));
    
    get_blosum(matrix);

    cout << "Separando secuencia" << endl << "..." << endl;

    // Separa la secuencia ingresada por el usuario
    for (int i = 0; i <= this->size - wrd_size; i++) {
        for (int j = 0; j <wrd_size; j++) {
            secuencia[i][j] = list[1][j + i];
            cout << secuencia[i][j];
        }
        cout << endl;
    }

    cout << "..." << endl << "Fin de separacion de secuencia" << endl;

    // Separa la secuencia de la base de datos
    for (int i = 0; i <= this->size - wrd_size; i++) {
        for (int j = 0; j < wrd_size; j++) {
            comparador[i][j] = this->base[j + i];
            // cout << comparador[i][j];
        }
        // cout << endl;
    }
    
    // Compara ambas secuencias y devuelve cantidad de resultados positivos
    for (int x = 0; x < this->size - wrd_size; x++) {
        for (int z = 0; z < this->size - wrd_size; z++) {
            for (int w = 0; w < wrd_size; w++) {
                aux++;
                //cout<< "in value: "<< scre << "   ";
                scre += funct_score(secuencia[x][w], comparador[z][w], matrix);
                //cout<< "out value: "<< scre <<endl ;
                if (aux == wrd_size) {
                    if (scre >= this->T) {
                        if (scre >= maxscre) {
                            maxscre = scre;
                            ptr_match = z;
                            ptr_match2 = x;
                            
                            cout << "Secuencia actual de puntaje máximo: ";
                            for (int i = 0; i < wrd_size; i++) {
                                HSP[i] = secuencia[x][i];
                                cout << HSP[i];
                            }
                            cout << endl ;
                        }
                    } else {
                        aux = 0;
                    }
                    score++;
                    aux = 0;
                    scre=0;
                }
                // cout << "aux " << aux << endl;
                //cout << score << endl;
            }
            aux = 0;
            scre=0;
        }
        scre=0;
    }
    int ind_extend=0;    
    strncpy(arr_out, this->extend(ind_extend, ptr_match,  ptr_match2, wrd_size, list, arr_out, matrix), this->size);
    cout<< "Comenzando la expansión de la secuencia: "<< endl;
    this->printer(arr_out);
    while (this->rescore(arr_out, list, matrix) >= this->T  && strlen(arr_out) < this->size) {
        ind_extend++;
        strncpy(arr_out, this->extend(ind_extend, ptr_match,  ptr_match2, wrd_size, list, arr_out, matrix), this->size);
         this->printer(arr_out);
    }
    strncpy(arr_out, this->extend(ind_extend, ptr_match,  ptr_match2, wrd_size, list, arr_out, matrix), this->size);
    // cout<< strlen(arr_out)<< endl << arr_out<< endl;
    this->printer(arr_out);
    

    delete[] matrix;
    delete[] arr_out;
    return 0;
}

/**
 * @brief Reevalúa el puntaje del array de salida para que se pueda obtener la secuencia con el mejor puntaje.
 *
 * @param list Lista ingresada por el usuario.
 * @param arr_out Secuencia de caracteres a extender.
 * @param matrix Arreglo de punteros que con los puntajes.
 * @warning El primer dato de la lista es el nombre del ejecutable.
 */
int blastobject::rescore(char* arr_out, char** list, double* matrix) {  
    int new_score=0;
    for (int index = 0; index < this->size; index++) 
    {
        //out<< "arr_out[index]: "<< arr_out[index]<< " this->base"<< this->base[index]<<endl;
        if (arr_out[index] != ' ') {            
            new_score += funct_score(arr_out[index], this->base[index], matrix);
            //cout<< "new_score: "<<new_score<< endl;            
        }
        //cout<< endl;
    }
    return new_score;
}

/**
 * @brief Extiende la matriz para hacer un nuevo puntaje y determniar la mejor secuencia sobre el umbral.
 *
 * @param ind_extend Índice de las veces que se ha extendido la secuencia.
 * @param ptr_match2 Posición en el cadena interrogante donde se halló el mayor puntaje.
 * @param ptr_match Posición en el secuencia conocida donde se halló el mayor puntaje.
 * @param wrd_size Tamaño de la palabra.
 * @param list Lista ingresada por el usuario.
 * @param arr_out Secuencia de caracteres a extender.
 * @param matrix Arreglo de punteros que con los puntajes.
 * @warning El primer dato de la lista es el nombre del ejecutable.
 */
char* blastobject::extend(int ind_extend, int ptr_match, int ptr_match2, int wrd_size, char** list, char* arr_out, double* matrix) {
    char* arr_out_aux;
    arr_out_aux = (char*) calloc (12,sizeof(char));
    /*for (int i=0; i < 12;i++){
        cout << "list[1][i]"<< list[1][i]<<endl;
    }*/
    //cout<< endl<< arr_out<<endl<<arr_out_aux;
    for (int index = 0; index < ptr_match - ind_extend; index++) {
        arr_out_aux[index] = ' ';
    }
    for (int index = ptr_match-ind_extend; index < ptr_match + wrd_size + ind_extend; index++) {
        //for(int index2=ptr_match2; index2 < ptr_match2 + wrd_size + ind_extend; index2++){;
            arr_out_aux[index] = list[1][abs(index-ptr_match2)];
            //cout<< "list[1][index-ptr_match2]" << list[1][abs(index-ptr_match2)]<<endl;
        //}
    }
    //this->printer(arr_out_aux);
    if (this->rescore(arr_out_aux, list, matrix) >= this->T && sizeof(arr_out)/sizeof(arr_out[0]) < this->size){
        return arr_out_aux;
    }
    else{
        return arr_out;
    }
    delete[] arr_out_aux;    
     
}

/**
 * @brief Imprime la secuencia de la base de datos y el emparejamiento con el más alto puntaje.
 *
 * @param arr_out Secuencia de caracteres a imprimir.
 * @warning El primer dato de la lista es el nombre del ejecutable.
 */
// Prints the secuence from database and the best matched secuence over the threshold.
void blastobject::printer(char* arr_out) {
    cout<< endl;
    for (int index = 0; index < strlen(arr_out) ; index++) {
        cout << arr_out[index];
    }
    cout<< endl;
    for (int index= 0; index < this->size; index++) {
        cout << this->base[index];
    }
    cout << endl;
}

/**
 * @brief Compara las secuencias de caracteres con la referencia y cuenta su puntuacion cruda.
 *
 * La funcion recorre el arreglo ingresado para luego regresar la evaluacion correspondiente a la cantidad de puntuacion obtenida con respecto a la referencia.
 *
 * @param lista Secuencia de caracteres ingresados por el usuario.
 * @warning El primer dato de la lista es el nombre del ejecutable.
 */
int blastobject::raw(char** lista) {

    for (int i = 0; i < this->size; i++) {

        if (lista[1][i] == this->base[i]) {
            this->rawscore = this->rawscore + 1;
        } else {

            if (lista[1][i] == 'U') {
                this->rawscore = this->rawscore + 7;
            } else if (lista[1][i] == 'A') {
                this->rawscore = this->rawscore + 5;
            } else if (lista[1][i] == 'G') {
                this->rawscore = this->rawscore + 3;
            } else if (lista[1][i] == 'H') {
                this->rawscore = this->rawscore + 2;
            } else {
                this->rawscore = this->rawscore;
            }
        }

    }

    cout << "Puntuacion: " << this->rawscore << endl;
    return this->rawscore;

}

/**
 * @brief Retorna una secuencia con solo los caracteres similares.
 *
 * La funcion recorre el arreglo ingresado para luego imprimir la secuencia con los caracteres similares y los vacios rellenos con el simbolo de suma +.
 *
 * @param lista Secuencia de caracteres ingresados por el usuario.
 * @warning El primer dato de la lista es el nombre del ejecutable.
 */
int blastobject::gapclear(char** lista) {

    for (int i = 0; i < this->size; i++) {

        if (lista[1][i] == this->base[i]) {
            cout << this->base[i];
        } else {
            cout << "+";
        }

    }

    cout << endl;
    return 0;

}

/**
 * @brief Compara las secuencias de caracteres con la referencia y cuenta sus vacios.
 *
 * La funcion recorre el arreglo ingresado para luego regresar la evaluacion correspondiente a la cantidad de vacios existentes en la secuencia comparada.
 *
 * @param lista Secuencia de caracteres ingresados por el usuario.
 * @param n Variable de control para la cantidad de pasos de recorrido.
 * @warning El primer dato de la lista es el nombre del ejecutable.
 */
int blastobject::gap(char** lista, int n) {

    int aux = 0;

    cout << "Caracteres compartidos: " << endl;

    this->gapclear(lista);

    for (int i = 0; i < this->size; i++) {

        if (lista[1][i] == this->base[i]) {
            aux = aux + 1;

        } else {

            if (aux != 0) {
                aux = aux - 1;
            } else {
                aux = 0;
            }
        }

        if (aux == n) {
            this->gapcounter = this->gapcounter;
        } else {
            this->gapcounter = this->gapcounter + 1;
        }

    }

    int res = abs(100 - (100 * (abs(this->size - this->gapcounter * n)) / this->size));

    if (res > 100) {
        res = 100;
    }

    cout << "Resolucion: " << n << " paso(s)" << endl;

    cout << "Porcentaje de huecos: " << res << "%" << endl;
    return this->gapcounter;

}