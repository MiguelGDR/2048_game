#include <iostream>
#include <iomanip>
#include <array>
#include <cstdlib>
#include <cmath>
#include <time.h>       // Incluyo la libreria time para usar time().
#include "C2048.hpp"

using namespace std;
using namespace bblProgIIB;

int main(){
    C2048 juego;
    bool fin = 0;
    bool win = 0;
    char mov;

    juego.iniciarjuego();

    juego.mostrarTablero();

    while(!fin){
        cin >> mov;
        switch(mov){
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
        juego.estadojuego(fin,win);
        juego.addNum(fin);
        juego.mostrarTablero();
    }

    if(fin==1 && win==1){
        cout << "Congratulations!" << endl;
    }
    else{
        cout << "Game over :(" << endl;
    }

    system("pause");
    return 0;
}