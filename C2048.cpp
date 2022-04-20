#include <iostream>
#include <iomanip>
#include <array>
#include <cstdlib>
#include <cmath>
#include <time.h> // Incluyo la libreria time para usar time().
#include "C2048.hpp"
#include <fstream>

using namespace std;

namespace bblProgIIB
{
    C2048::C2048()
    {
        for (int i = 0; i < 4; i++)
        { // INICIALIZO LAS 16 POSICIONES A 0.
            for (int j = 0; j < 4; j++)
            {
                tablero[i][j] = 0;
            }
        }
        puntos = 0; // INICIALIZO LOS PUNTOS A 0.
    }
    // Constructor de copia
    C2048::C2048(const C2048 &otro_tablero)
    {
        tablero = otro_tablero.tablero; // COPIO EL TABLERO.
        puntos = otro_tablero.puntos;   // COPIO LOS PUNTOS.
    }
    // Destructor
    C2048::~C2048(){};

    // Muestra el estado del juego después de un movimiento.
    void C2048::mostrarTablero() const
    {
        // system("clear"); // En Linux y Mac
        system("cls"); // En Windows (MI CASO).
        cout << setw(12) << "2048" << setw(10) << " "
             << "Points: " << puntos << endl;

        cout << setw(2) << "*";
        for (int i = 0; i <= 18; i++)
            if (i == 4 || i == 9 || i == 14)
                cout << "*";
            else
                cout << "*";
        cout << "*" << endl;
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                if (tablero[i][j] == 0)
                    cout << setw(2) << "*" << setw(4) << " ";
                else
                    cout << setw(2) << "*" << setw(4) << tablero[i][j];
                if (j == 3 && i < 3)
                {
                    cout << setw(2) << "*" << endl;
                    cout << setw(2) << "*";
                    for (int i = 0; i <= 18; i++)
                        if (i == 4 || i == 9 || i == 14)
                            cout << "*";
                        else
                            cout << "*";
                    cout << setw(2) << "*" << endl;
                }
                if (i == 3 && j == 3)
                {
                    cout << setw(2) << "*" << endl;
                    cout << setw(2) << "*";
                    for (int i = 0; i <= 18; i++)
                        if (i == 4 || i == 9 || i == 14)
                            cout << "*";
                        else
                            cout << "*";
                    cout << setw(2) << "*" << endl;
                }
            }
        }
    }

    // Muestra la puntuación
    int C2048::mostrarPuntos() const
    {
        return puntos;
    }

    // Inicia el juego.
    void C2048::iniciarjuego()
    {
        for (int i = 0; i < 4; i++)
        { // INICIALIZO LAS 16 POSICIONES A 0.
            for (int j = 0; j < 4; j++)
            {
                tablero[i][j] = 0;
            }
        }
        puntos = 0; // INICIALIZO LOS PUNTOS A 0.

        srand(time(0)); // CAMBIO LA SEED
        int x1 = rand() % 4;
        int y1 = rand() % 4; // GENERO 4 NÚMEROS (DEL 0 AL 3) ALEATORIAMENTE.
        int x2 = rand() % 4; // LOS USO COMO COORDENADAS PARA INICIAR EL TABLERO
        int y2 = rand() % 4; // CON DOS 2.

        tablero[x1][y1] = tablero[x2][y2] = 2;

        return;
    }

    // Realiza el movimiento hacia arriba;
    void C2048::moverup()
    {
        apilar('w');
        sumar('w');
        apilar('w'); // LA SUMA ANTERIOR PODRÍA HABER DEJADO HUECOS, POR ESO APILO DE NUEVO
        addNum();
    }

    // Realiza el movimiento hacia abajo;
    void C2048::moverdown()
    {
        apilar('s');
        sumar('s');
        apilar('s');
        addNum();
    }

    // Realiza el movimiento hacia la izquierda;
    void C2048::moverleft()
    {
        apilar('a');
        sumar('a');
        apilar('a');
        addNum();
    }

    // Realiza el movimiento hacia la derecha;
    void C2048::moverright()
    {
        apilar('d');
        sumar('d');
        apilar('d');
        addNum();
    }

    // Devuelve el estado del juego en dos variables una para indicar si el juego ha finalizado o no y la otra
    // para indicar si hemos ganado.  Si el juego no ha finalizado, la variable win no es significativa, en
    // caso de finalizar el juego, fin es true, win nos indica si hemos ganado o no.
    void C2048::estadojuego(bool &fin, bool &win)
    {
        if (!libres())
        {
            fin = 1; // SI EL TABLERO ESTÁ LLENO, PONGO LA CONDICIÓN fin A 1.
            win = 0;

            // SI EL TABLERO ESTA LLENO, PERO SE PUEDE SEGUIR JUGANDO, LA CONDICIÓN fin VOLVERÁ A 0.
            for (int i = 0; i < 3; i++) // COMPRUEBO EN SENTIDO VERTICAL
            {
                for (int j = 0; j < 4; j++)
                {
                    if (tablero[i][j] == tablero[i + 1][j])
                    {
                        fin = 0;
                    }
                }
            }

            for (int j = 0; j < 3; j++) // COMPRUEBO EN SENTIDO HORIZONTAL
            {
                for (int i = 0; i < 4; i++)
                {
                    if (tablero[i][j] == tablero[i][j + 1])
                    {
                        fin = 0;
                    }
                }
            }
        }

        // CONDICION DE VICTORIA
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (tablero[i][j] == 2048)
                {
                    fin = 1;
                    win = 1;
                }
            }
        }
    }

    void C2048::maxpunt(char a)
    {
        ifstream flujo_ent;
        unsigned int i;
        flujo_ent.open("points.txt");
        flujo_ent >> i;

        if (a == 's' && i < puntos)
        {
            ofstream flujo_sal;
            flujo_sal.open("points.txt");
            flujo_sal << puntos;
            flujo_sal.close();
        }

        if (a == 'e')
        {
            cout << endl;
            cout << "La mayor puntuacion obtenida es: " << i << endl;
            system("pause");
        }
        flujo_ent.close();
    }

    // AQUI COMIENZAN LOS MÉTODOS PRIVADOS
    // Comprueba si la posición x,y está libre
    bool C2048::poslibre(int x, int y) const
    {
        return tablero[x][y] == 0;
    }

    // Comprueba si quedan casillas libres en el tablero
    bool C2048::libres() const
    {
        int flag = 0;
        for (int i = 0; i < 4; i++)
        { // INICIALIZO LAS 16 POSICIONES A 0.
            for (int j = 0; j < 4; j++)
            {
                if (tablero[i][j] == 0)
                {
                    flag = 1;
                }
            }
        }
        return flag;
    }

    // Genera aleatoriamente un 2 o un 4;
    // Los numeros aleatorios no son aleatorios sino son generados usando una ecuación que depende de un valor inicial
    // Si le paso un valor fijo siempre genera los mismos números aleatorios
    // Para que cambie le pasamos la hora actual (time(0) - segundos transcurridos desde el 1 de enero de 1970)
    int C2048::generanum() const
    {
        srand(time(0));
        int res = rand() % 2;
        return (res + 1) * 2;
    }

    // Genera unas coordenadas aleatorias en una posición libre en el tablero y devuelve true si existen
    // posiciones libre y ha generado las coordenadas.
    void C2048::generaCoord(int &x, int &y, bool &vacia) const
    {
        srand(time(0)); // CAMBIO LA SEED
        int xgen = rand() % 4;
        int ygen = rand() % 4;
        if (libres())
        {
            vacia = true;
            while (!poslibre(xgen, ygen))
            {
                xgen = rand() % 4;
                ygen = rand() % 4; // GENERO DE NUEVO OTRAS COORDENADAS
            }
            x = xgen; // GUARDO LAS COORDENADAS DE LA POSICION LIBRE
            y = ygen;
        }
        else
        {
            vacia = false;
        }
        return;
    }

    // Inserta num en las coordenadas x,y del tablero.
    void C2048::insertanumero(const int &x, const int &y, const int &num)
    {
        tablero[x][y] = num;
        return;
    }

    // HE CONSIDERADO AÑADIR ESTA FUNCION PARA SIMPLIFICAR EL AÑADIR UN NUMERO DESPUES DE CADA MOVIMIENTO
    void C2048::addNum()
    {
        int num, x, y;
        bool vacio;
        num = generanum();
        generaCoord(x, y, vacio);
        if (vacio)
        {
            insertanumero(x, y, num);
        }
        return;
    }

    // Elimina num de las coordenadas x,y del tablero.
    void C2048::eliminanumero(const int &x, const int &y)
    {
        tablero[x][y] = 0;
        return;
    }

    // Apila todos los números de una columna o una fila en el sentido del movimiento
    bool C2048::apilar(const char mov)
    {
        int flag = 0;
        // APILAR HACIA ARRBIA
        if (mov == 'w')
        {
            for (int a = 0; a < 3; a++) // REPITO 3 VECES PARA MOVER LAS CASILLAS MÁS LEJANAS
            {
                for (int j = 0; j < 4; j++) // COLUMNAS
                {
                    for (int i = 0; i < 3; i++) // FILAS
                    {
                        if (tablero[i][j] == 0)
                        {
                            tablero[i][j] = tablero[i + 1][j];
                            eliminanumero(i + 1, j);
                            flag = 1;
                        }
                    }
                }
            }
        }
        // APILAR HACIA ABAJO
        if (mov == 's')
        {
            for (int a = 0; a < 3; a++)
            {
                for (int j = 0; j < 4; j++) // COLUMNAS
                {
                    for (int i = 3; i > 0; i--) // FILAS
                    {
                        if (tablero[i][j] == 0)
                        {
                            tablero[i][j] = tablero[i - 1][j];
                            eliminanumero(i - 1, j);
                            flag = 1;
                        }
                    }
                }
            }
        }
        // APILAR HACIA LA IZQ.
        if (mov == 'a')
        {
            for (int a = 0; a < 3; a++)
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (tablero[i][j] == 0)
                        {
                            tablero[i][j] = tablero[i][j + 1];
                            eliminanumero(i, j + 1);
                            flag = 1;
                        }
                    }
                }
            }
        }
        // APILAR HACIA LA DER.
        if (mov == 'd')
        {
            for (int a = 0; a < 3; a++)
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 3; j > 0; j--)
                    {
                        if (tablero[i][j] == 0)
                        {
                            tablero[i][j] = tablero[i][j - 1];
                            eliminanumero(i, j - 1);
                            flag = 1;
                        }
                    }
                }
            }
        }
        return flag;
    }

    // Calcula la suma de los puntos de las casillas adyacentes con valores iguales en el sentido del movimiento
    void C2048::sumar(const char mov)
    {
        // SUMA HACIA ARRIBA
        if (mov == 'w')
        {
            for (int j = 0; j < 4; j++)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (tablero[i][j] == tablero[i + 1][j])
                    {
                        tablero[i][j] += tablero[i + 1][j];
                        puntos += tablero[i][j];
                        eliminanumero(i + 1, j);
                    }
                }
            }
        }
        // SUMA HACIA ABAJO
        if (mov == 's')
        {
            for (int j = 0; j < 4; j++)
            {
                for (int i = 3; i > 0; i--)
                {
                    if (tablero[i][j] == tablero[i - 1][j])
                    {
                        tablero[i][j] += tablero[i - 1][j];
                        puntos += tablero[i][j];
                        eliminanumero(i - 1, j);
                    }
                }
            }
        }
        // SUMA HACIA LA IZQ.
        if (mov == 'a')
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (tablero[i][j] == tablero[i][j + 1])
                    {
                        tablero[i][j] += tablero[i][j + 1];
                        puntos += tablero[i][j];
                        eliminanumero(i, j + 1);
                    }
                }
            }
        }
        // SUMA HACIA LA DER.
        if (mov == 'd')
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 3; j > 0; j--)
                {
                    if (tablero[i][j] == tablero[i][j - 1])
                    {
                        tablero[i][j] += tablero[i][j - 1];
                        puntos += tablero[i][j];
                        eliminanumero(i, j - 1);
                    }
                }
            }
        }
    }
} // Fin namespace bblProgIIB