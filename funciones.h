#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/// DECLARACIÓN/PROTOTIPO DE FUNCIONES
int main();

void cargarVector(int v[], int tam);///asigna valores a cada una de las posiciones del vector

void mostrarVector(int v[], int tam);/// muestra lo que contiene cada una de las posiciones del vector

void ponerCero(int v[], int tam);/// pone en 0 todas las posiciones del vector

int posicionNumeroEnVector(int v[],int tam, int numero);/// devuelve la posición que ocupa un número que se //envía como parámetro. Devuelve la primera posición que encuentra el número. Si no lo encuentra devuelve -1

int contarNumerosRepetidos(int v[], int numero, int tam);///cuenta la cantidad de veces que se repite un //número en el vector

int maximoVector(int v[], int tam);///devuelve  la posición (primera) que ocupa el máximo en el vector

int minimoVector(int v[], int tam);///devuelve  la posición (primera) que ocupa el mínimo en el vector

void cargarAleatorio(int v[], int tam, int limite);///asigna valores aleatorios a cada al vector

void cargarManual(int v[], int tam);// asigna valores al modo de juego de testeo

void ordenarVector(int v[], int tam );/// ordena de menor a mayor un vector

int sumarVector(int v[], int tam ); /// suma los valores contenidos en el vector

void copiarVector(int v[], int v2[],int tam ); ///copia el vector v en v2

bool compararVectores(int v[], int v2[],int tam );// compara los dos vectores que recibe. Si son iguales ///devuelve true, si no devuelve false

void cargarNombre(int v[], int tam); /// agrega nombres de los jugadores a vectores de formato char

void dibujarCuadrado(int posx, int posy, int tam = 7); ///dibujar cuadrados de los dados

void dibujarDado(int posx, int posy, int num, int tam = 7); ///dibujar dados

void comenzarRonda();// funcion principal que encapsula todo

void cargarCadena();// cargamos cadena a vector char

void cargarNombre();// carga nombre en modo de juego de un jugador

void mostrarNombre();//  muestra nombre en modo de juego de un jugador

void asignarValores(); // asigna los valores de dados a puntajes de los distintos tipos de combinaciones de juegos

void imprimirDados();//imprime tirada de dados

void cuadrado();
                     //Dibujan la cuadricula
void cuadrado2();





/// Desarrollo de funciones / Definiciones

void cuadrado(){
int i;
rlutil::locate(25,5);
cout<<"-----------------------------------------------------------------"<<endl;
for(i=1;i<19;i++){
    rlutil::locate(24,5+i);
    cout<<"|"<<endl;
    }
for(i=1;i<19;i++){
    rlutil::locate(90,5+i);
    cout<<"|"<<endl;
    }
 rlutil::locate(25,24);
cout<<"-----------------------------------------------------------------"<<endl;
}

void cuadrado2(){
rlutil::locate(10,10);
cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
rlutil::locate(10,20);
cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
}

int posicionNumeroEnVector(int v[],int tam, int numero){
    int i;
    for(i=0;i<tam;i++){
        if(v[i]==numero) return i;
        }
    return -1;
}

int minimoVector(int v[], int tam){
    int i, posMin=0;
    for(i=1;i<tam;i++){
        if(v[i]<v[posMin]) {
                posMin=i;
        }
    }
    return posMin;
}
void ordenarVector(int v[], int tam ){
    int i,j, posmin, aux;
    for(i=0;i<tam-1;i++){
        posmin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

int maximoVector(int v[], int tam){
    int i, posMax=0;
    for(i=1;i<tam;i++){
        if(v[i]>v[posMax]) {
                posMax=i;
        }
    }
    return posMax;
}

void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}

void mostrarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
      cout<<v[i]<<"\t";
    }
    cout<<endl;
}


int contarNumerosRepetidos(int v[], int numero, int tam){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(v[i]==numero) cant++;
        }
    return cant;
}


void ponerCero(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=0;
    }
}


int sumarVector(int v[], int tam ){
    int i, suma=0;
    for(i=0;i<tam;i++){

        if(v[i] > 0){
        suma+=v[i];
        }
    }
    return suma;
}


void copiarVector(int v[], int v2[],int tam ){
    int i;
    for(i=0;i<tam;i++){
        v2[i]=v[i];
    }
}

bool compararVectores(int v[], int v2[],int tam ){
   int i;
    for(i=0;i<tam;i++){
        if(v2[i]!=v[i]) return false;
    }
    return true;
}

void cargarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        rlutil::locate(20,10+i);
        cout<<"INGRESE NUMERO: ";
        rlutil::locate(37,10+i);
        cin>>v[i];
        while(v[i] < 1 || v[i]>6){
            rlutil::locate(20,10+i);
            cout<<"ERROR, INGRESE UN NUMERO DEL 1 AL 6: ";
            cin>>v[i];
        }
    }
}

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i = 0; i < tam; i++){
        pal[i] = cin.get();
        if(pal[i] == '\n')break;
    }
    pal[i]= '\0';
    fflush(stdin);
}

void cargarNombre(char nombre[30]){
    cargarCadena( nombre, 29);
    }
void mostrarNombre(char nombre[30]){

    cout<<nombre;
    }

void dibujarCuadrado(int posx, int posy, int tam) {
	for (int y = 1; y <= tam / 2; y++) {

		for (int x = 1; x <= tam; x++) {
			rlutil::locate(x + posx, y + posy);
			cout << (char)219;
		}
	}
}

void dibujarDado(int posx, int posy, int num, int tam) {
	rlutil::setColor(rlutil::WHITE);
	dibujarCuadrado(posx, posy);


	rlutil::setBackgroundColor(rlutil::WHITE);
	rlutil::setColor(rlutil::BLACK);

	switch (num)
	{
	case 1:
		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
		cout << (char)254;
		break;

	case 2:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;


		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		break;

	case 3:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
		cout << (char)254;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		break;


	case 4:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		break;

	case 5:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
		cout << (char)254;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		break;


	case 6:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		break;

	default:
		break;
	}
	rlutil::setBackgroundColor(rlutil::GREEN);

	rlutil::setColor(rlutil::GREY);
	// sombra

	for (int y = posy + 2; y <= posy + tam / 2 + 1; y++) {
		rlutil::locate(posx + tam + 1, y);
		cout << (char)219;
	}


	for (int x = posx + 2; x <= posx + tam + 1; x++) {
		rlutil::locate(x, posy + tam / 2 + 1);
		cout << (char)223;
	}

	rlutil::locate(posx + tam + 1, posy + 1);
	cout << (char)220;

	rlutil::locate(2, 10);

}

void imprimirDados(int d[], int tam){
for (int i = 0; i <= 4; i++) {

        switch(d[i]){

    case 1:
        dibujarDado(16*(i+1),10,d[i]);
        break;
    case 2:
        dibujarDado(16*(i+1),10,d[i]);
        break;
    case 3:
        dibujarDado(16*(i+1),10,d[i]);
        break;
    case 4:
        dibujarDado(16*(i+1),10,d[i]);
        break;
    case 5:
        dibujarDado(16*(i+1),10,d[i]);
        break;
    case 6:
        dibujarDado(16*(i+1),10,d[i]);
        break;
    default:
        break;
        }
    }

}


void RONDA(int d[], int tam, int j[], int pFinal[], bool testeo, bool &ganoPartida, bool manual, int  contTirada, int rondas, char vNombre[30], int &sumaPuntaje, int &tiradasTotales){
    rlutil::cls();
    int i, x, p, opc2, opc3, opc4;
    bool elegido = false;
    sumaPuntaje = sumarVector(pFinal, 10);
    tiradasTotales = tiradasTotales + contTirada;

    while (contTirada < 3 && elegido == false && ganoPartida == false){
    contTirada++;
    rlutil::locate(20,5);
    cout<<"TURNO DE ";
    mostrarNombre(vNombre);
    rlutil::locate(42,5);
    cout<<" | RONDA N "<<rondas<<" |";
    rlutil::locate(65,5);
    cout<<"PUNTAJE TOTAL: "<<sumaPuntaje;
    cout<<endl;
    rlutil::locate(20,6);
    cout<<"-----------------------------------------------------------------"<<endl;
    rlutil::locate(20,7);
    cout<<"TIRADA N *"<<contTirada<<"\t\t\t\t\tTIRADAS TOTALES: "<<tiradasTotales<<endl;
    rlutil::locate(20,8);
    cout<<"-----------------------------------------------------------------"<<endl;
    if(manual==true){
    cargarVector(d, 5);
    rlutil::cls();

    rlutil::locate(20,5);
    cout<<"TURNO DE ";
    mostrarNombre(vNombre);
    rlutil::locate(42,5);
    cout<<" | RONDA N "<<rondas<<" |";
    rlutil::locate(65,5);
    cout<<"PUNTAJE TOTAL: "<<sumaPuntaje;
    cout<<endl;
    rlutil::locate(20,6);
    cout<<"-----------------------------------------------------------------"<<endl;
    rlutil::locate(20,7);
    cout<<"TIRADA N *"<<contTirada<<"\t\t\t\t\tTIRADAS TOTALES: "<<tiradasTotales<<endl;
    rlutil::locate(20,8);
    cout<<"-----------------------------------------------------------------"<<endl;
    ordenarVector(d, 5);
    imprimirDados(d, 5);
    }
    else{
    ordenarVector(d, 5);
    imprimirDados(d, 5);

    }

    ///PONER EN CERO EL VECTOR
    for(i=0; i<9; i++){
    ponerCero(j, 10);
    }

    ///COMBINACIONES DEL 1 AL 6
    for(i = 0; i<6; i++){
            p = i+1;
            int hayRepetido = p * contarNumerosRepetidos( d, p, tam);
        j[i] = hayRepetido;
    }

    ///ESCALERA
    int cons=0;
    for(x=0; x<tam; x++){
    if(d[x]-d[x+1]==-1 || d[x]-d[x+1]==1){
    cons++;
    if(cons == 5 || cons==4){
    j[6]=25;
            }
        }
    }

    ///FULL
    int n1, n2 = 0, count1 = 1, count2 = 0;

    n1 = d[0];
    for (int i = 1; i < 5; i++){
    if (n1 == d[i])
    count1++;
    else if (n2 == 0)
        {
    n2 = d[i];
    count2++;
            }
    else if (n2 == d[i])
    count2++;
    }
    if((count1 == 3 && count2 == 2) || (count2 == 3 && count1 == 2)){
    j[7]=30;
    }

    ///POKER;
    for(i = 0; i <=6; i++){
    contarNumerosRepetidos(d, i, tam);

    if (contarNumerosRepetidos(d, i, tam) == 4){
    j[8]= 40;
        }
    }

    ///GENERALA
      int contGenerala = 1;
      for(i = 0; i <6; i++){
        if(d[i] == d[i-1]){
            contGenerala++;
            }
        }
    if (contGenerala == 5){
    j[9]= 50;
      }
    if(contTirada == 1 && j[9]==50){
        pFinal[9]=50;
        sumaPuntaje = sumarVector(pFinal, 10);
        rlutil::locate(42,17);
        cout<<"GENERALA SERVIDA, GANASTE!"<<endl;
        rlutil::anykey();
        ganoPartida = true;
        }

    while(elegido == false && ganoPartida == false){
    if(contTirada < 3){
    rlutil::locate(30,17);
    cout<<"1- ANOTAR EL PUNTAJE OBTENIDO EN LA TIRADA"<<endl;
    rlutil::locate(30,18);
    cout<<"2- VOLVER A TIRAR LOS DADOS"<<endl;
    rlutil::locate(30,19);
    cin>>opc2;
    }
    else{
    opc2 = 1;}
    int cantDados,dadosR;
    switch(opc2){
        case 1:
        rlutil::locate(30,17);
        cout<<"1- GUARDAR PUNTAJE\t\t\t\t"<<endl;
        rlutil::locate(30,18);
        cout<<"2- ANULAR PUNTAJE\t\t"<<endl;
        rlutil::locate(30,19);
        cout<<"\t\t"<<endl;
        rlutil::locate(30,19);
        cin>>opc3;

            switch(opc3){
            case 1:
                elegido = true;
                rlutil::cls();
                cuadrado();
                rlutil::locate(46,10);
                cout<<"Eliga opcion ganadora: "<<endl;
                for(i=0; i<6; i++){
                if(j[i] > 0 && pFinal[i] == 0){
                rlutil::locate(46,(11+i));
                cout<<i+1<<"- "<< j[i] <<" al "<<i+1<<endl;
                    }
                }
                if(j[6] > 0 && pFinal[6] == 0){
                rlutil::locate(46,17);
                cout<<"7- "<< j[6] <<" A LA ESCALERA "<<endl;
                    }
                if(j[7] > 0 && pFinal[7] == 0){
                rlutil::locate(46,18);
                cout<<"8- "<< j[7] <<" AL FULL "<<endl;
                    }
                if(j[8] > 0 && pFinal[8] == 0){
                rlutil::locate(46,19);
                cout<<"9- "<< j[8] <<" AL POKER "<<endl;
                    }
                if(j[9] > 0 && pFinal[9] == 0){
                rlutil::locate(46,20);
                cout<<"10- "<< j[9] <<" A LA GENERALA "<<endl;
                    }
            rlutil::locate(70,10);
            cin>>opc4;
            switch(opc4){
                case 1:
                if(pFinal[0] == 0){
                pFinal[0] = j[0];}

                else{

                    cout<<"ya posee valores en esta combinacion"<<endl;
                    }
                break;
                case 2:
                    if(pFinal[1] == 0){
                    pFinal[1] = j[1];}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                    }
                break;
                case 3:
                    if(pFinal[2] == 0){
                    pFinal[2] = j[2];}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                    }
                    break;
                case 4:
                if(pFinal[3] == 0){
                pFinal[3] = j[3];}
                else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                }
                break;
                case 5:
                    if(pFinal[4] == 0){
                    pFinal[4] = j[4];}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                }
                break;
                case 6:
                    if(pFinal[5] == 0){
                    pFinal[5] = j[5];}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                }
                break;
                case 7:
                    if(pFinal[6] == 0){
                    pFinal[6] = j[6];}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                }
                break;
                case 8:
                    if(pFinal[7] == 0){
                    pFinal[7] = j[7];}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                }
                break;
                case 9:
                    if(pFinal[8] == 0){
                    pFinal[8] = j[8];}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                }
                break;
                case 10:
                    if(pFinal[9] == 0){
                    pFinal[9] = j[9];}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                }
                break;
            }
            break;

        case 2:
                elegido = true;
                rlutil::cls();
                cuadrado();
                rlutil::locate(46,10);
                cout<<"ELIGA ANULACION: "<<endl;
                for(i=0; i<6; i++){
                if(pFinal[i] == 0){
                rlutil::locate(46,11+i);
                cout<<i+1<<"- "<< "ANULAR " <<i+1<<endl;
                    }
                }
                rlutil::locate(46,17);
                if(pFinal[6] == 0){
                cout<<"7- "<< "ANULAR ESCALERA "<<endl;
                    }
                rlutil::locate(46,18);
                if(pFinal[7] == 0){
                cout<<"8- "<< "ANULAR FULL "<<endl;
                    }
                rlutil::locate(46,19);
                if(pFinal[8] == 0){
                cout<<"9- "<< "ANULAR POKER "<<endl;
                    }
                rlutil::locate(46,20);
                if(pFinal[9] == 0){
                cout<<"10-"<< "ANULAR GENERALA "<<endl;
                    }
            rlutil::locate(63,10);
            cin>>opc4;
            switch(opc4){

                case 1:
                    if(pFinal[0] == 0){
                    pFinal[0] = -1;}

                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                    }
                    break;

                case 2:
                    if(pFinal[1] == 0){
                    pFinal[1] = -1;}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                    }
                    break;
                case 3:
                    if(pFinal[2] == 0){
                    pFinal[2] = -1;}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                    }
                    break;
                case 4:
                    if(pFinal[3] == 0){
                    pFinal[3] = -1;}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                    }
                    break;
                case 5:
                    if(pFinal[4] == 0){
                    pFinal[4] = -1;}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                    }
                    break;
                case 6:
                    if(pFinal[5] == 0){
                    pFinal[5] = -1;}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                    }
                    break;
                case 7:
                    if(pFinal[6] == 0){
                    pFinal[6] = -1;}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                    }
                    break;
                case 8:
                    if(pFinal[7] == 0){
                    pFinal[7] = -1;}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                    }
                    break;
                case 9:
                    if(pFinal[8] == 0){
                    pFinal[8] = -1;}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                    }
                    break;
                case 10:
                    if(pFinal[9] == 0){
                    pFinal[9] = -1;}
                    else{
                    cout<<"ya posee valores en esta combinacion"<<endl;
                        }
                    break;

                break;
                    }
                }
                break;
case 2:
    ponerCero(j,10);
    contTirada++;
    tiradasTotales++;
    rlutil::locate(30,17);
    cout<<"CUANTOS DADOS VOLVES A TIRAR? :\t\t\t\t";
    rlutil::locate(30,18);
    cout<<"\t\t\t\t\t\t";
    rlutil::locate(30,19);
    cout<<"\t\t\t\t\t\t";
    rlutil::locate(62,17);
    cin>>cantDados;
    srand(time(NULL));
    cout<<endl;
    for (i = 0; i < cantDados; i++){
        rlutil::locate(30,17+i);
        cout<<"ELIJA EL/LOS DADOS QUE QUIERE VOLVER A TIRAR: ";
        cin>>dadosR;
        if(testeo == false){
        d[dadosR-1]=(rand()%6)+1;
        }else{
        rlutil::locate(30,17+i);
        cout<<"INGRESE NUMERO: \t\t\t\t\t\t";
        rlutil::locate(46,17+i);
        cin>>d[dadosR-1];
        cout<<"\t";
        }
    }

    rlutil::cls();
    rlutil::locate(20,5);
    cout<<"TURNO DE ";
    mostrarNombre(vNombre);
    rlutil::locate(42,5);
    cout<<" | RONDA N "<<rondas<<" |";
    rlutil::locate(65,5);
    cout<<"PUNTAJE TOTAL: "<<sumaPuntaje;
    cout<<endl;
    rlutil::locate(20,6);
    cout<<"-----------------------------------------------------------------"<<endl;
    rlutil::locate(20,7);
    cout<<"TIRADA N *"<<contTirada<<"\t\t\t\t\tTIRADAS TOTALES: "<<tiradasTotales<<endl;
    rlutil::locate(20,8);
    cout<<"-----------------------------------------------------------------"<<endl;
    ordenarVector(d, 5);
    imprimirDados(d, 5);



    ///COMBINACIONES DEL 1 AL 6
    for(i = 0; i<6; i++){
            p = i+1;
            int hayRepetido = p * contarNumerosRepetidos( d, p, tam);
    //if (hayRepetido > 1){
        j[i] = hayRepetido;
    }

    ///ESCALERA
    int cons=0;
    for(x=0; x<tam; x++){
    if(d[x]-d[x+1]==-1 || d[x]-d[x+1]==1){
    cons++;
    if(cons == 5 || cons==4){
    j[6]=25;
            }
        }
    }

    ///FULL
    int n1, n2 = 0, count1 = 1, count2 = 0;

    n1 = d[0];
    for (int i = 1; i < 5; i++){
    if (n1 == d[i])
    count1++;
    else if (n2 == 0)
        {
    n2 = d[i];
    count2++;
            }
    else if (n2 == d[i])
    count2++;
    }
    if((count1 == 3 && count2 == 2) || (count2 == 3 && count1 == 2)){
    j[7]=30;
    }

    ///POKER;
    for(i = 0; i <=6; i++){
    contarNumerosRepetidos(d, i, tam);

    if (contarNumerosRepetidos(d, i, tam) == 4){
    j[8]= 40;
        }
    }

    ///GENERALA
      int contGenerala = 1;
      for(i = 0; i <6; i++){
        if(d[i] == d[i-1]){
            contGenerala++;
            }
        }
    if (contGenerala == 5){
    j[9]= 50;
      }
    break;
        }
    }
}
tiradasTotales++;
rlutil::cls();
sumaPuntaje = sumarVector(pFinal, 10);

}
#endif // FUNCIONES_H_INCLUDED
