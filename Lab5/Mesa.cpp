#include "Mesa.h"

/**
 * @brief Constructor de clase Mesa.
 *
 */
Mesa::Mesa() {
    puntajes = new ListaConArreglo<int>();
    jugadores = new ListaConArreglo<char>();
    this->baraja = new Pila<int>();

    ronda = 0;

}

/**
 * @brief Constructor de clase Mesa sobrecargado.
 *
 * @param N dimension del arreglo.
 */
Mesa::Mesa(/*ListaConArreglo* admision,*/ int N) {

    this->puntajes = new ListaConArreglo<int>(N); 
    this->jugadores = new ListaConArreglo<char>(N);

}

/**
 * @brief Imprime una cadena de caracteres dada por el usuario.
 *
 * @param Mesa& Objeto del tipo Mesa.
 */
Mesa::Mesa(const Mesa& orig) {
}

/**
 * @brief Destructor de la clase Mesa.
 *
 */
Mesa::~Mesa() {
}

/**
 * @brief Funcion principal de distribucion para el juego de Blackjack.
 *
 * @param Admision Lista de personas por entrar al juego.
 */
void Mesa::Blackjack(ListaConArreglo<char>* Admision) {

    
    //cout << "Tamaño de Admision: " << Admision->tam << endl;*/
    bool fin_juego=false;
    ronda = 0;
    for (int i = 0; i < puntajes->tam; i++) {
        puntajes->agregark(i, 0);
    }
    cout << "Puntajes al incio de Blackjack: ";
    puntajes->imprimir();
    int i = 0;
    while (fin_juego==false) {

        cout << "Ronda: " << ronda << endl;
        if (ronda == 0) {
            
            this->barajar();
            //cout << "Baraja tras barajar en Blackjack(): ";
            //baraja->imprimir();
            for (int i = 0; i < jugadores->tam; i++) {
                puntajes->sumark(i, baraja->pop());
                puntajes->sumark(i, baraja->pop());
                cout << "Puntajes tras repartir en ronda " << ronda << " a jugador " << jugadores->recuperar(i) << " : ";
                puntajes->imprimir();
            }

            ronda++;
        }

        for (int i = 0; i < jugadores->tam; i++) {
            //cout<< endl<< "punta"<<endl;
            if (puntajes->recuperar(i) < 19) {
                puntajes->sumark(i, baraja->pop());
                cout << "Puntajes tras repartir en ronda " << ronda << " a jugador " << jugadores->recuperar(i) << " : ";
                puntajes->imprimir();
                //break;
                
            }if (puntajes->recuperar(i) > 21) {
                this->sacar_jugador(i);
                //jugadores->imprimir();
                //break;
                //this->agregar_jugador(admision->recuperar(admision->tam-1));
                //admision->eliminarK(admision->tam-1);
            } if (jugadores->tam == 0) {
                //ronda = 0;
                cout << "No hay más jugadores." << endl;
                fin_juego = true;
            } else {
                //ronda = 0;
                //cout << endl << "Otros." << endl;
                fin_juego = true;
            }
        }
        ronda++;
        if (fin_juego==true) {
            ronda=0;
            cout << "fin de juego" << endl;
            break;
        }
        //i++;
        /*ronda = 0;
        if (Admision->tam == 0) {
            break;
        }*/
    }

}

/**
 * @brief Agrega jugador a la mesa de juego.
 *
 * @param Admision Lista de personas por entrar al juego.
 */
void Mesa::agregar_jugador(ListaConArreglo<char>* admision) {
    jugadores->agregar(admision->recuperar(admision->tam - 1));
    admision->eliminarK(admision->tam - 1);
    cout << endl << "Se ha agregado un jugador a la mesa." << endl << endl;
    puntajes->agregar(0);
    cout << "Jugadores: ";
    jugadores->imprimir();
    cout << "Puntajes: ";
    puntajes->imprimir();
    cout << endl;
}

/**
 * @brief Elimina jugador a la mesa de juego.
 *
 * @param i Orden del jugador.
 */
void Mesa::sacar_jugador(int i) {
    jugadores->eliminarK(i);
    puntajes->eliminarK(i);
    cout << endl << "Se ha eliminado un jugador de la mesa." << endl << endl;
    cout << "Jugadores: ";
    jugadores->imprimir();
    cout << "Puntajes: ";
    puntajes->imprimir();
    cout << endl;
}

/**
 * @brief Prepara las cartas para el juego.
 *
 */
void Mesa::barajar() {
    //baraja= 0;
    //this->baraja=new Pila<int>();
    //cout << endl << "Baraja inicial: " << endl;
    //this->baraja->imprimir();
    if (baraja->vacio() == false) {
        //cout << endl << "Se ha entrado al if de baraja->vacio: " << baraja->vacio() << endl;
        for (int i = 0; baraja->vacio()!=true; i++) {
                this->baraja->pop();
                //cout << endl << "pop" << endl;
        }

        //cout<< "Baraja tras vaciar: ";
        //baraja->imprimir();
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 2; j < 12; j++) {
            this->baraja->push(j);
            //cout << endl << "push" << endl;
        }
    }
    //cout << "Barajar: ";
    this->baraja->aleatorizar();
    //cout << "Baraja después de aleatorizar: " << endl;
    //this->baraja->imprimir();
}

/**
 * @brief Revisa si la mesa esta llena o no.
 *
 */
bool Mesa::lleno() {
    if (this->jugadores->tam == 3) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Llena las mesas para el juego.
 *
 * @param Admision Lista de personas por entrar al juego.
 */
void Mesa::llenar(ListaConArreglo<char>* Admision) {
    //cout << "Tamaño de admsion al entrar a llenar(): " << Admision->tam << endl;
    while (this->lleno() != true && Admision->vacio() == false) {
        this->agregar_jugador(Admision);
        //cout << "Tamaño de admsion tras agregar_jugador(): " << Admision->tam << endl;
        //cout << "Tamaño de jugadores tras agregar_jugador(): " << this->jugadores->tam << endl;
    }
    //cout << "Tamaño de admsion tras salir de llenar(): " << Admision->tam << endl;
}

/**
 * @brief Vacia la mesa.
 *
 */
void Mesa::vaciar() {
    //cout << "Tamaño de jugadores al entrar a vaciar(): " << this->jugadores->tam << endl;
    while (this->jugadores->tam != 0) {
        int i = this->jugadores->tam - 1;
        //cout << "tamaño de admsion:" << Admision->tam << endl;        
        this->sacar_jugador(i);
        //cout << "Tamaño de jugadores tras sacar_jugador(): " << this->jugadores->tam << endl;
        --i;
        //cout << "tamaño de jugadores:" << this->jugadores->tam << endl;
    }
    //cout << "Tamaño de jugadores al salir de vaciar(): " << this->jugadores->tam << endl;
}
