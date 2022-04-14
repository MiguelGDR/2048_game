#include <iostream>
#include <iomanip>
#include <array>
#include <cstdlib>
#include <cmath>
#include "C2048.hpp"

using namespace std;

namespace bblProgIIB
{
    C2048::C2048(){
        for(int i=0; i<4; i++){         // INICIALIZO LAS 16 POSICIONES A 0.
            for(int j=0; i<4; i++){
                tablero[i][j] = 0;
            }
        }
        puntos = 0;                     // INICIALIZO LOS PUNTOS A 0.
    }
        // Constructor de copia
    C2048::C2048(const C2048 &otro_tablero){
        tablero = otro_tablero.tablero; // COPIO EL TABLERO.
        puntos = otro_tablero.puntos;   // COPIO LOS PUNTOS.
    }
        // Destructor
    C2048::~C2048(){};

        // Muestra el estado del juego después de un movimiento.
        void C2048::mostrarTablero() const{
            // system("clear"); // En Linux y Mac
            system("cls");  // En Windows (MI CASO).
            cout<<setw(12)<<"2048"<<setw(10)<<" "<<"Puntuación: "<<puntos<<endl;

            cout<<setw(2)<<"\u2554";
            for(int i=0;i<=18;i++)
                if (i == 4 || i == 9 || i == 14)
                    cout << "\u2566";
                else
                    cout<<"\u2550";
            cout<<"\u2557"<<endl;
            for(int i=0;i<=3;i++) 
            {
                for(int j=0;j<=3;j++)
                {
                    if(tablero[i][j]==0)
                        cout<<setw(2)<<"\u2551"<<setw(4)<<" ";
                    else
                        cout<<setw(2)<<"\u2551"<<setw(4)<<tablero[i][j];
                    if(j==3 && i < 3)
                    {
                        cout<<setw(2)<<"\u2551"<<endl;
                        cout<<setw(2)<<"\u2560";
                        for(int i=0;i<=18;i++)
                            if (i == 4 || i == 9 || i == 14)
                                cout<<"\u256c";
                            else
                                cout<<"\u2550";
                        cout<<setw(2)<<"\u2563"<<endl;
                    }
                    if (i == 3 && j == 3)
                    {
                        cout<<setw(2)<<"\u2551"<<endl;
                        cout<<setw(2)<<"\u255a";
                        for(int i=0;i<=18;i++)
                            if (i == 4 || i == 9 || i == 14)
                                cout<<"\u2569";
                            else
                                cout<<"\u2550";
                        cout<<setw(2)<<"\u255d"<<endl; 
                    }
                }
            }

        }
        
        // Muestra la puntuación
        int C2048::mostrarPuntos() const{
            cout << puntos << endl;
        }

        // Inicia el juego.
        void C2048::iniciarjuego(){}
        
        // Realiza el movimiento hacia arriba;
        void C2048::moverup(){}

        // Realiza el movimiento hacia abajo;
        void C2048::moverdown(){}

        // Realiza el movimiento hacia la izquierda;
        void C2048::moverleft(){}

        // Realiza el movimiento hacia la derecha;
        void C2048::moverright(){}

        //Devuelve el estado del juego en dos variables una para indicar si el juego ha finalizado o no y la otra
        // para indicar si hemos ganado.  Si el juego no ha finalizado, la variable win no es significativa, en 
        //caso de finalizar el juego, fin es true, win nos indica si hemos ganado o no.
        void C2048::estadojuego(bool &fin, bool &win){}

        //Comprueba si la posición x,y está libre
        bool C2048::poslibre(int x, int y) const{}

        //Comprueba si quedan casillas libres en el tablero
        bool C2048::libres()const{}

        // Genera aleatoriamente un 2 o un 4;
        // Los numeros aleatorios no son aleatorios sino son generados usando una ecuación que depende de un valor inicial
        // Si le paso un valor fijo siempre genera los mismos números aleatorios
        // Para que cambie le pasamos la hora actual (time(0) - segundos transcurridos desde el 1 de enero de 1970)
        int C2048::generanum() const {}

        // Genera unas coordenadas aleatorias en una posición libre en el tablero y devuelve true si existen
        // posiciones libre y ha generado las coordenadas.
        void C2048::generaCoord(int &x, int &y, bool &vacia) const {}

        //Inserta num en las coordenadas x,y del tablero.
        void C2048::insertanumero(const int &x, const int &y, const int &num){}
        
        //Elimina num de las coordenadas x,y del tablero.        
        void C2048::eliminanumero(const int &x, const int &y){}

        //Apila todos los números de una columna o una fila en el sentido del movimiento
        bool C2048::apilar(const char mov){} 
        
        //Calcula la suma de los puntos de las casillas adyacentes con valores iguales en el sentido del movimiento
        void C2048::sumar(const char mov){}
}// Fin namespace bblProgIIB