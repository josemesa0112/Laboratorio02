#include <iostream>
#define W 20

using namespace std;

bool comparar(char pal1[20], char pal2[20]);
int transformar(char cade[]);
string enteroString(int num);
string minuMayus(char cade[]);
string eliminarRepetido(char cade[]);
void separarCaracteres(string *ptr1, string *ptr2, char cadena[]);
int sumarSeparar(int n, int num);
void contarFrecuencia (char arreglo[],int frecuencia[]);
void imprimirFrecuencia (int frecuencia[]);
void printcinema(char arreglo[15][20]);

int main()
{
    int opc = 0;
    while(opc != 100){
        cout<<"************MENU PRINCIPAL************"<<endl<<"1. Problema 1 "<<endl<<"2. Problema 2 "<<endl<<"3. Problema 3 "<<endl<<"4. Problema 4 "<<endl<<"5. Problema 5 "<<endl<<"6. Problema 6 "<<endl<<"7. Problema 7 "<<endl<<"8. Problema 8 "<<endl;
        cout <<"Digite su opcion: ";
        cin>>opc;
        switch(opc){
            case 1:{
                int dinero;
                int devuelto;
                cout << "Digite la cantidad de dinero a cambiar: ";
                cin >> dinero;
                int cambio[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};

                for(int i=0;i<11;i++){
                    devuelto = 0;
                    if(dinero < 50){
                        cout << "Faltante: "<<dinero;cout <<endl<<endl;
                        break;
                    }
                    else{
                        if(dinero > cambio[i]){
                            devuelto = dinero / cambio[i];
                            dinero -= devuelto * cambio[i];
                        }
                        cout << cambio[i]<<": "<<devuelto<<endl;
                    }
                }
                break;
            }
            case 2:{
                srand(time(nullptr));

                char mayus[200]; // Se crea el arreglo de letras con 200 letras

                int frecuencia[26] = {0}; // Se crea para comparar con las letras que salen y contar cuantas veces sale la letra

                for (int i = 0; i < 200 ; i++){
                    mayus [i] = 'A' + rand() % 26;

                }

                cout <<"El arreglo con 200 letras mayusculas es: "<<mayus<<endl;

                contarFrecuencia(mayus,frecuencia);
                cout<<"Frecuencia de cada letra:"<<endl;
                imprimirFrecuencia(frecuencia);

                break;
            }
            case 3:{
                char pal1[W] = {}, pal2[W] = {};
                cout<<"Digite la primer palabra: ";
                cin>>pal1;
                cout<<"Digite la segunda palabra: ";
                cin>>pal2;

                if(comparar(pal1, pal2)){
                    cout<<"Son iguales"<<endl;
                }else{
                    cout<<"Son diferentes"<<endl;
                }
                break;
            }
            case 4:{
                char cadena[20] = {};
                int numero = 0;
                cout<<"Digite la cadena de caracteres numericos: ";
                cin>>cadena;

                numero = transformar(cadena);
                cout<<"El numero es: "<<numero<<endl;
                break;
            }
            case 5:{
                int numero;
                cout<<"Digite el numero deseado: ";
                cin>>numero;

                numero += 1;
                break;
            }
            case 6:{
                char cadena[20] = {};
                string palabra;

                cout<<"Digite la palabra: ";
                cin>>cadena;

                palabra = minuMayus(cadena);

                cout<<palabra<<endl;
                break;
            }
            case 7:{
                char palabra[W] = {};
                string resultado;
                cout<<"Digite la palabra: ";
                cin>>palabra;

                resultado = eliminarRepetido(palabra);

                cout<<"Original: "<<palabra<<" Sin repetidos: "<<resultado<<endl;

                break;
            }
            case 8:{
                char cadena[W] = {};
                string letras = "", numeros = "";
                cout<<"Digite la cadena de caracteres: ";
                cin>>cadena;

                separarCaracteres(&numeros, &letras, cadena);

                cout<<"Original: "<<cadena<<endl<<"Texto: "<<letras<<" Numero: "<<numeros<<endl;
            }
            case 9:{
                int n=0,cond=0,acum=0,it=0,acum1=0,cambio=1;
                cout << "Ingrese n: ";
                cin>>n;
                char arreglo[] = "87512395";
                cout<< "Ingrese el arreglo: ";cin>>arreglo;
                int longitud = sizeof(arreglo);
                //cout<<longitud<<endl;
                int paso = longitud-1 ;

                while(cond!=n){
                    while(it!=n){
                        if(paso<0){
                            break;}
                        else{
                            acum += (arreglo[paso] - '0') * cambio;
                            paso--;
                            cambio*=10;
                            it++;
                        }
                    }
                    acum1+=acum;
                    acum=0;
                    cond++;
                    it=0;
                    cambio=1;

                }
                cout<<"Original: "<<arreglo<<endl;
                cout<<"Suma: "<<acum1<<endl;

                break;
            }
            case 10:{
                int cont=0,i,j,suma=0,k=0;
                char NumRomanos[7]={'M','D','C','L','X','V','I'};
                int  NumEquivalentes[7]={1000,500,100,50,10,5,1};
                char Letras[10]={};
                int Numero[10]={};
                cout<<"Ingrese el numero romano a convertir en MAYUSCULAS"<<endl;
                cin>>Letras;
                while(Letras[cont]!='\0')     //Para saber la longitud del numero romano ingresado
                    cont++;
                for(i=0;i<cont;i++){
                    for(j=0;j<7;j++){
                        if (Letras[i]==NumRomanos[j]){   //aqui recorro cada letra del numero romano ingresado y las comparo con el arreglo NumRomanos
                            Numero[i]=NumEquivalentes[j];//aqui si coinciden las letras en el anterior if les asigno el valor correspondiente al sistema arabigo
                        }
                    }
                }
                //aqui ya hemos almacenado todos los valores del numero ingresado por el usuario
                for (k=0;k<10;k++){
                    if (Numero[k]>Numero[k+1]) //aqui comparamos el numero en la posicion k con el de la posicion k+1 y si es mayor lo sumamos
                        suma+=Numero[k];
                    else if (Numero[k]<Numero[k+1]) //aqui el caso contrario si es menor lo restamos
                        suma-=Numero[k];
                    else					//aqui es el default por si depronto solo se ingreso solo una letra
                        suma+=Numero[k];
                }
                cout<<suma<<endl;
                break;
            }
            case 11:{
                char sala[15][20];
                string seleccion;

                for(int i=0;i<15;i++){ //ciclos que generan el arreglo en dos dimensiones de la sala
                    for(int j=0;j<20;j++){
                        sala[i][j] = '-';
                    }
                }
                printcinema(sala); //Impresión de la sala

                while(true){
                    cout << "Indique el asiento a reservar o a cancelar. Ejemplo: 'can A-17', 'res B-20', ingrese x para salir" << endl;
                    cout << "Comando: ";
                    getline(cin, seleccion);

                    if (seleccion == "x"){
                        break;
                    }

                    sala[15][20] = resycan(sala, seleccion); //Utilización de la función que reserva y cancela
                    printcinema(sala); //Impresión de la sala actualizada
                }
            }
            case 12:{
                int n, numeros, sumatoria=0, sumatoria1=0, ban = 1;
                cout << "Ingrese el tamano de la matriz: ";
                cin >> n;
                int matriz[n][n];
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        matriz[i][j] = '0';
                    }
                }
                while(true){
                    for(int i=0;i<n;i++){
                        for(int j=0; j<n;j++){
                            cout << "Ingrese un numero en la posicion: " << i << "," << j << ": ";
                            cin >> numeros;
                            matriz[i][j] = numeros;
                        }
                    }
                    break;
                }
                for(int i=0;i<n;i++){
                    sumatoria = 0;
                    for(int j=0; j<n;j++){
                        sumatoria += matriz[i][j];
                    }
                    if(sumatoria1==0){
                        sumatoria1=sumatoria;
                    }
                    if(sumatoria1!=sumatoria){
                        ban = 0;
                        break;
                    }
                }
                if(ban==1){
                    for(int j=0;j<n;j++){
                        sumatoria = 0;
                        for(int i=0; i<n;i++){
                            sumatoria += matriz[i][j];
                        }
                        if(sumatoria1!=sumatoria){
                            ban = 0;
                            break;
                        }
                    }
                }
                if(ban==1){
                    sumatoria = 0;
                    int t = n-1;
                    for(int i=0; i<n;i++){
                        sumatoria += matriz[i][i];
                    }
                    if((sumatoria)!=sumatoria1){
                        ban=0;
                    }
                    sumatoria = 0;
                    for(int i=0; i<n;i++,t--){
                        sumatoria += matriz[i][t];
                    }
                    if(sumatoria!=sumatoria1){
                        ban=0;
                    }
                }
                cout << endl;
                for(int i=0;i<n;i++){
                    for(int j=0; j<n;j++){
                        if(matriz[i][j]/104 >= 1){
                            cout << matriz[i][j] << " ";
                        }
                        else{
                            cout << " " << matriz[i][j] << " ";
                        }
                    }
                    cout << endl;
                }
                if(ban==1){
                    cout << "La matriz es magica" << endl;
                }
                else{
                    cout << "La matriz no es magica" << endl;
                }
            }

        }
    }
    return 0;
}

bool comparar(char pal1[], char pal2[]){

    for(int i=0; i<W; i++){
        if(pal1[i] != pal2[i]){
            return false;
        }
    }
    return true;
}

int transformar(char cade[]){
    int numero = 0;
    char caracter;
    for(int i=0; i<(int)sizeof(cade); i++){
        caracter = cade[i];
        if(caracter != 0){
            numero = numero * 10 +(caracter - '0');
        }
        else{
            return numero;
        }
    }
    return numero;
}

string minuMayus(char cade[]){
    char caracter;
    int cont = 0;
    string palabra = "";

    caracter = cade[cont];
    while(caracter != '\0'){
        if(caracter > 96 && caracter < 123){
            caracter -= 32;
            palabra += caracter;
        }
        else{
            palabra += caracter;
        }
        cont+=1;
        caracter = cade[cont];
    }
    return palabra;
}

string eliminarRepetido(char cade[]){
    char caracter = cade[0];
    bool comprobar;
    string palabra = "";
    for(int i=0; i<(int)sizeof(cade); i++){
        caracter = cade[i];
        comprobar = true;
        for(int j=0; j<=i; j++){
            if(caracter == cade[j] && j != i){
                comprobar = false;
            }
        }
        if(comprobar){
            palabra += caracter;
        }
    }
    return palabra;
}

void separarCaracteres(string *ptr1, string *ptr2, char cadena[]){
    char caracter;
    *ptr1 = "";
    *ptr2 = "";

    for(int i=0; i<W ; i++){
        caracter = cadena[i];
        if(caracter == '\0'){
            break;
        }
        if(caracter > 47 && caracter < 58){
            *ptr1 += caracter;
        }
        else{
            *ptr2 += caracter;
        }
    }
}

void contarFrecuencia (char arreglo[],int frecuencia[]){
    // Funcion para el Problema 2
    for (int i = 0; i < 200; i++){
        frecuencia[arreglo[i] - 65]++;
    }

}

void imprimirFrecuencia (int frecuencia[]){
    // Funcion para el Problema 2
    for (int i = 0; i < 26 ; i++){
        if (frecuencia[i] > 0){
            cout<<(char)('A' + i)<<": "<<frecuencia[i]<<endl;
        }
    }
}

void printcinema(char arreglo[15][20]){
    // Funcion para el Problema 11

    cout << endl << endl;
    cout << "Asientos disponibles en -, reservados en +." << endl;
    for(int i = 0; i < 15; i++){
        for(int t= 0; t < 20; t++){
            cout << arreglo[i][t] << " ";
        }
        cout << endl;
    }
}
