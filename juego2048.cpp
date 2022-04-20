#include <iostream>
#include <iomanip>
#include <array>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <time.h> // Incluyo la libreria time para usar time().
#include "C2048.hpp"

using namespace std;
using namespace bblProgIIB;

int main()
{

    bool flag = 0;
    char menu;
    ifstream flujo_ent;
    C2048 juego;

    while (!flag)
    {
        system("cls");

        cout << "2048 game" << endl;
        cout << "Pulsa:" << endl;
        cout << "1. Empezar nueva partida." << endl;
        cout << "2. Reglas del juego." << endl;
        cout << "3. Maxima puntuacion obtenida" << endl;
        cout << "4. Salir." << endl;

        cin >> menu;
        switch (menu)
        {
        case '1':
        {
            flag = 1;
            bool fin = 0;
            bool win = 0;
            char mov;

            juego.iniciarjuego();

            juego.mostrarTablero();

            while (!fin)
            {
                cin >> mov;
                switch (mov)
                {
                case 'w':
                    juego.moverup();
                    break;
                case 's':
                    juego.moverdown();
                    break;
                case 'a':
                    juego.moverleft();
                    break;
                case 'd':
                    juego.moverright();
                    break;
                }
                juego.estadojuego(fin, win);
                juego.mostrarTablero();
            }

            juego.maxpunt('s');

            if (fin == 1 && win == 1)
            {
                cout << "Congratulations!" << endl;
                cout << "Pulsa:" << endl;
                cout << "1. Volver al menu principal." << endl;
                cout << "2. Cerrar juego." << endl;
            }
            else
            {
                cout << "Game over :(" << endl;
                cout << "Pulsa:" << endl;
                cout << "1. Volver al menu principal." << endl;
                cout << "2. Cerrar juego." << endl;
            }

            cin >> mov;
            if (mov == '1')
            {
                flag = 0;
            }
            if (mov == '2')
            {
                flag = 1;
            }
            break;
        }

        case '2':
        {
            system("cls");
            cout << "El objetivo del juego 2048 es combinar los numeros por parejas (2+2, 4+4, etc...), en un area cuadrada de 4x4 casillas, con el fin de conseguir una casilla con el valor 2048." << endl;
            cout << "Los movimientos se realizan con las teclas W A S D." << endl;
            cout << "W = Arriba." << endl;
            cout << "A = Izquierda" << endl;
            cout << "S = Abajo" << endl;
            cout << "D = Derecha" << endl;
            system("pause");
            break;
        }

        case '3':
        {
            juego.maxpunt('e');
            break;
        }

        case '4':
        {
            flag = 1;
            break;
        }

        }
    }
    return 0;
}