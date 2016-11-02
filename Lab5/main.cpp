#include "ListaConArreglo.h"
#include "Pila.h"
#include "Lista.h"
#include "Mesa.h"
#include "admision.h"


using namespace std;
/**
 * @brief Ejecuta el programa.
 *
 * @param argc Lista de personas por entrar al juego.
 * @param argv Argumentos del usuario.
 */
int main(int argc, char** argv) {

    //admision(argv,7);


    Mesa m1, m2, m3;

    ListaConArreglo<char>*Admision = new ListaConArreglo<char>();
    Admision = admision(argv, 7);

    while (Admision->vacio() == false) {

        if (m1.lleno() != true && Admision->vacio() == false) {
            cout << endl << "Mesa m1." << endl;
            m1.llenar(Admision);
            cout << endl << "Blackjack m1." << endl;
            m1.Blackjack(Admision);
             cout << "Cola de admision restante: ";
            Admision->imprimir();

        } else if (m2.lleno() != true && Admision->vacio() == false) {
           
            cout << endl << "Mesa m2." << endl;
            m2.llenar(Admision);
            cout << endl << "Blackjack m2." << endl;
            m2.Blackjack(Admision);
        } else if (m3.lleno() != true && Admision->vacio() == false) {
            cout << endl << "Mesa m3." << endl;
            m3.llenar(Admision);
            cout << endl << "Blackjack m3." << endl;
            m2.Blackjack(Admision);
        }
        cout << endl << "Tamaño de Admision: " << Admision->tam << endl;

    }

    cout << "Salida de while en el main" << endl;

    return 0;


}

