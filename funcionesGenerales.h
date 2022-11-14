#ifndef FUNCIONESGENERALES_H_INCLUDED
#define FUNCIONESGENERALES_H_INCLUDED


void PARTIDA(char nombre[30], int &puntos, int &tiradasGanador);
void PARTIDA2(char nombre[30], int &puntos, int &tiradasGanador);
void showItem(const char* text, int posx, int posy, bool selected);

////
void showItem(const char* text, int posx, int posy, bool selected){
    if(selected){
        rlutil::setBackgroundColor(rlutil::BLACK);
    }else{
        rlutil::setBackgroundColor(rlutil::GREEN);
    }
    rlutil::locate(posx, posy);
    cout<< text <<endl;
    rlutil::setBackgroundColor(rlutil::GREEN);

}

    void PARTIDA(char nombre[30], int &puntos, int &tiradasGanador){
        rlutil::setBackgroundColor(rlutil::GREEN);
    int dados[5], vPuntos[10], puntajeFinal[10], opc1, rondas=0, tiradasTotales=0, sumaPuntaje = 0, tiradas = 0;
    bool ganoPartida = false, testeo = false, manual=false;
    rlutil::cls();
    rlutil::locate(30,9);
    cout<<"-INGRESE SU NOMBRE: ";
    cargarNombre(nombre);
    rlutil::locate(30,10);
    cout<<"- INGRESE 1(UNO) PARA LA VERSION NORMAL DEL JUEGO."<<endl;
    rlutil::locate(30,11);
    cout<<"- INGRESE 2(DOS) PARA LA VERSION DE TESTEO"<<endl;
    rlutil::locate(30,12);
    cin>>opc1;

    if(opc1 == 2){
    testeo = true;
    }
    switch(opc1){

case 1:

    ponerCero(puntajeFinal,10);
    while(rondas < 10 && ganoPartida == false){
    rondas++;
    manual=false;
    cargarAleatorio(dados, 5, 6);
    ordenarVector(dados, 5);
    RONDA(dados, 5, vPuntos, puntajeFinal, testeo, ganoPartida, manual, tiradas, rondas, nombre, sumaPuntaje, tiradasTotales);
    if((ganoPartida==false)&&(rondas<10)){
    cuadrado();
    rlutil::locate(48,13);
    cout<<"RONDA N "<<rondas<<endl;
    rlutil::locate(48,14);
    cout<<"PROXIMO TURNO:"<<nombre<<endl;
    rlutil::locate(48,16);
    cout<<"PUNTAJE "<<nombre<<": "<<sumaPuntaje<<endl;
    rlutil::anykey();
        }
    }
    if(ganoPartida == true){
    cuadrado2();
    rlutil::locate(10,15);
    cout<<"FELICIDADES "<<nombre<<", OBTUVISTE GENERALA SERVIDA Y GANASTE CON UN PUNTAJE DE: "<<sumaPuntaje<<", CON UNOS TIROS TOTALES DE: "<<tiradasTotales<<endl;
    rlutil::anykey();
    }
    if(rondas == 10){
    rlutil::cls();
    cuadrado2();
    rlutil::locate(20,15);
    cout<<"TERMINASTE LA PARTIDA "<<nombre<<" CON UN PUNTAJE DE: "<<sumaPuntaje<<", CON UNOS TIROS TOTALES DE: "<<tiradasTotales<<endl;
    rlutil::anykey();
    }
    break;

case 2:
    ponerCero(puntajeFinal,10);
    while(rondas < 10 && ganoPartida == false){
    rondas++;
    manual=true;
    RONDA(dados, 5, vPuntos, puntajeFinal, testeo, ganoPartida, manual, tiradas, rondas, nombre, sumaPuntaje, tiradasTotales);
    if((ganoPartida==false)&&(rondas<10)){
    cuadrado();
    rlutil::locate(48,13);
    cout<<"RONDA N "<<rondas<<endl;
    rlutil::locate(48,14);
    cout<<"PROXIMO TURNO:"<<nombre<<endl;
    rlutil::locate(48,16);
    cout<<"PUNTAJE "<<nombre<<": "<<sumaPuntaje<<endl;
    rlutil::anykey();
        }
    }
    if(ganoPartida == true){
    rlutil::cls();
    cuadrado2();
    rlutil::locate(10,15);
    cout<<"FELICIDADES "<<nombre<<", OBTUVISTE GENERALA SERVIDA Y GANASTE CON UN PUNTAJE DE: "<<sumaPuntaje<<" CON UNOS TIROS TOTALES DE: "<<tiradasTotales<<endl;
    rlutil::anykey();
    }
    if(rondas == 10){
    rlutil::cls();
    cuadrado2();
    rlutil::locate(20,15);
    cout<<"TERMINASTE LA PARTIDA "<<nombre<<", CON UN PUNTAJE DE: "<<sumaPuntaje<<", CON UNOS TIROS TOTALES DE: "<<tiradasTotales<<endl;
    rlutil::anykey();
    }
    break;
    }
    puntos = sumaPuntaje;
    tiradasGanador = tiradasTotales;
}

    void PARTIDA2(char nombre[30], int &puntos, int &tiradasGanador){
    rlutil::setBackgroundColor(rlutil::GREEN);
    int dados[5], vPuntos[10], puntajeFinal[10], puntajeFinal2[10], rondas=0, tiradasTotales=0, tiradasTotales2= 0, sumaPuntaje = 0, sumaPuntaje2 = 0, tiradas = 0;
    char vNombre[30], vNombre2[30];
    bool ganoPartida = false, ganoPartida2 = false, manual=false, testeo=false;
    rlutil::cls();
    rlutil::locate(30,11);
    cout<<"- INGRESE EL NOMBRE DEL JUGADOR UNO(1): ";
    cargarNombre(vNombre);
    rlutil::locate(30,12);
    cout<<"- INGRESE EL NOMBRE DEL JUGADOR DOS(2): ";
    cargarNombre(vNombre2);
    ponerCero(puntajeFinal,10);
    ponerCero(puntajeFinal2,10);


    while(rondas < 10 && ganoPartida == false && ganoPartida2 == false){
            ///jugador 1
    rondas++;
    cargarAleatorio(dados, 5, 6);
    ordenarVector(dados, 5);
    RONDA(dados, 5, vPuntos, puntajeFinal, testeo, ganoPartida, manual, tiradas, rondas, vNombre, sumaPuntaje, tiradasTotales);
    if(rondas<=10){
    cuadrado();
     rlutil::locate(48,13);
    cout<<"RONDA N "<<rondas<<endl;
    rlutil::locate(48,14);
    cout<<"PROXIMO TURNO:"<<vNombre2<<endl;
    rlutil::locate(48,16);
    cout<<"PUNTAJE "<<vNombre<<": "<<sumaPuntaje<<endl;
    rlutil::locate(48,17);
    cout<<"PUNTAJE "<<vNombre2<<": "<<sumaPuntaje2<<endl;
    rlutil::anykey();}

    ///jugador 2
    cargarAleatorio(dados, 5, 6);
    ordenarVector(dados, 5);
    RONDA(dados, 5, vPuntos, puntajeFinal2, testeo, ganoPartida2, manual, tiradas, rondas, vNombre2, sumaPuntaje2, tiradasTotales2);
    if(rondas<10){
    cuadrado();
    rlutil::locate(48,13);
    cout<<"RONDA N "<<rondas<<endl;
    rlutil::locate(48,14);
    cout<<"PROXIMO TURNO:"<<vNombre<<endl;
    rlutil::locate(48,16);
    cout<<"PUNTAJE "<<vNombre<<": "<<sumaPuntaje<<endl;
    rlutil::locate(48,17);
    cout<<"PUNTAJE "<<vNombre2<<": "<<sumaPuntaje2<<endl;
    rlutil::anykey();
     }
    }
    sumaPuntaje = sumarVector(puntajeFinal, 10);
    sumaPuntaje2 = sumarVector(puntajeFinal2, 10);

    if(sumaPuntaje > sumaPuntaje2){
    rlutil::cls();
    cuadrado2();
    rlutil::locate(20,15);
    cout<<"EL GANADOR ES EL JUGADOR: "<<vNombre<<" CON UN PUNTAJE DE: "<<sumaPuntaje<<" CON UNOS TIROS TOTALES DE: "<<tiradasTotales<<endl;
    puntos = sumaPuntaje;
    tiradasGanador = tiradasTotales;
    strcpy(nombre, vNombre);
    rlutil::anykey();
    }else{
    rlutil::cls();
    cuadrado2();
    rlutil::locate(20,15);
    cout<<"EL GANADOR ES EL JUGADOR: "<<vNombre2<<" CON UN PUNTAJE DE: "<<sumaPuntaje2<<" CON UNOS TIROS TOTALES DE: "<<tiradasTotales2<<endl;
    puntos = sumaPuntaje2;
    tiradasGanador = tiradasTotales2;
    strcpy(nombre, vNombre2);
    rlutil::anykey();
    }
}
#endif // FUNCIONESGENERALES_H_INCLUDED
