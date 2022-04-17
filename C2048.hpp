#include <iostream>
#include <array>

namespace bblProgIIB
{

    typedef std::array<unsigned int, 4> Filas;
    typedef std::array<Filas, 4> Tablero;

    class C2048
    {
    public:
        C2048();
        // Constructor de copia
        C2048(const C2048 &Otro_tablero);
        // Destructor
        ~C2048();

        // Muestra el estado del juego después de un movimiento.
        void mostrarTablero() const;

        // Muestra la puntuación
        int mostrarPuntos() const;

        // Inicia el juego.
        void iniciarjuego();

        // Realiza el movimiento hacia arriba;
        void moverup();

        // Realiza el movimiento hacia abajo;
        void moverdown();

        // Realiza el movimiento hacia la izquierda;
        void moverleft();

        // Realiza el movimiento hacia la derecha;
        void moverright();

        // Devuelve el estado del juego en dos variables una para indicar si el juego ha finalizado o no y la otra
        //  para indicar si hemos ganado.  Si el juego no ha finalizado, la variable win no es significativa, en
        // caso de finalizar el juego, fin es true, win nos indica si hemos ganado o no.
        void estadojuego(bool &fin, bool &win);

    private:
        Tablero tablero;
        unsigned puntos;

        // Comprueba si quedan casillas libres en el tablero
        bool libres() const;

        // Comprueba si la posición x,y esta libre
        bool poslibre(int x, int y) const;

        // Genera aleatoriamente un 2 o un 4;
        int generanum() const;

        // Genera unas coordenadas aleatorias en una posición libre en el tablero y devuelve true si existen
        // posiciones libre y ha generado las coordenadas.
        void generaCoord(int &x, int &y, bool &vacia) const;

        // Inserta num en las coordenadas x,y del tablero.
        void insertanumero(const int &x, const int &y, const int &num);

        // HE CONSIDERADO AÑADIR ESTA FUNCION PARA SIMPLIFICAR EL AÑADIR UN NUMERO DESPUES DE CADA MOVIMIENTO
        void addNum();

        // Elimina num de las coordenadas x,y del tablero.
        void eliminanumero(const int &x, const int &y);

        // Apila todos los números de una fila o columna en el sentido del movimiento.
        bool apilar(const char mov);

        // Realiza la suma de las casillas con valores iguales en el sentido del movimiento.
        void sumar(const char mov);
    }; // Fin Class
} // Fin bblProgIIB