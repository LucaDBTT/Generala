#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<conio.h>
#include"rlutil.h"
#include<cstring>
#include<windows.h>
#include<mmsystem.h>

using namespace std;

#include "funciones.h"
#include "funcionesGenerales.h"

int main(){

int puntaje= 0, tiradas= 0, puntajeMax= 0, tiradasMax = 0, y = 0;
char ganador[30], ganadorMax[30];
PlaySound(TEXT("generala.wav"), NULL, SND_ASYNC);
rlutil::setBackgroundColor(rlutil::GREEN);
while(true){
    rlutil::cls();
    rlutil::hidecursor();
    rlutil::locate(30,10);
    cout<<" JUEGO NUEVO DE A 1."<<endl;
    rlutil::locate(30,11);
    cout<<" JUEGO NUEVO ENTRE 2"<<endl;
    rlutil::locate(30,12);
    cout<<" MOSTRAR PUNTUACION MAS ALTA."<<endl;
    rlutil::locate(30,13);
    cout<<" SALIR."<<endl;
    showItem(" JUEGO NUEVO DE A 1.", 30, 10, y== 0);
    showItem(" JUEGO NUEVO DE A 2.", 30, 11, y== 1);
    showItem(" MOSTRAR PUNTUACION MAS ALTA.", 30, 12, y== 2);
    showItem(" SALIR.", 30, 13, y== 3);
    rlutil::locate(28,10 + y);
    cout<<(char)175 <<endl;

    int key = rlutil::getkey();
    switch(key){
        case 14: //arriba
            rlutil::locate(28,10 + y);
            cout<<" " <<endl;
            y--;
            if(y < 0){
                y = 0;
            }
            break;
        case 15: //abajo
            rlutil::locate(28,10 + y);
            cout<<" " <<endl;
            y++;
            if(y > 3){
                y= 3;
            }
            break;
        case 1: //enter
            switch(y){
                case 0 :
                    rlutil::locate(30,11);
                    PARTIDA(ganador, puntaje, tiradas);
                    break;
                case 1:
                    PARTIDA2(ganador, puntaje, tiradas);
                    break;
                case 2:
                    if(puntaje > puntajeMax){
                        puntajeMax = puntaje;
                        tiradasMax = tiradas;
                        strcpy(ganadorMax,ganador);
                    }
                    if(puntajeMax > 0){
                    rlutil::cls();
                    cuadrado2();
                    rlutil::locate(20,15);
                    cout<<"EL JUGADOR: "<<ganadorMax<<" POSEE EL RECORD DE PUNTUACION CON UN TOTAL DE: "<<puntajeMax<<" PUNTOS, EN "<<tiradasMax<<" TIRADAS."<<endl;
                    rlutil::anykey();
                    rlutil::cls();
                    }else{
                    rlutil::cls();
                    cuadrado2();
                    rlutil::locate(45,15);
                    cout<<"NINGUN JUGADOR POSEE RECORD."<<endl;
                    rlutil::anykey();
                    rlutil::cls();
                        }
                    break;
                case 3:
                    return 0;
                    break;
            }
            break;
    }
  }
}
