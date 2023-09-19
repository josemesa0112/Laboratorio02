#include <iostream>
#define W 20

using namespace std;

bool comparar(char pal1[20], char pal2[20]);
int transformar(char cade[]);
string enteroString(int num);
string minuMayus(char cade[]);
string eliminarRepetido(char cade[]);
string separarCaracteres(string *ptr1, string *ptr2, char cadena[]);
int sumarSeparar(int n, int num);

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
                char letras[] = {};
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
                int n, numero;
                cout<<"Digite el numero en que quiere que se divida: ";
                cin>>n;
                cout<<"Digite el numero que quiere sumar: ";
                cin>>numero;

                sumarSeparar(n, numero);
            }
            case 10:{

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

string separarCaracteres(string *ptr1, string *ptr2, char cadena[]){
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
    return "";
}

int sumarSeparar(int n, int num){
    int cont = 0, sum = 0;
    char caracter = '';

    while(caracter != '\0'){
        caracter = num[cont];
        cont ++;
    }
}
