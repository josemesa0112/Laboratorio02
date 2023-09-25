#include <iostream>
#define W 20

using namespace std;

bool comparar(char pal1[20], char pal2[20]);
int transformar(char cade[]);
string enteroString(int num);
string minuMayus(char cade[]);
void cadena_caracteres(int numero_entero, char *& numero_caracter);
string eliminarRepetido(char cade[]);
void separarCaracteres(string *ptr1, string *ptr2, char cadena[]);
int sumarSeparar(int n, int num);
void contarFrecuencia (char arreglo[],int frecuencia[]);
void imprimirFrecuencia (int frecuencia[]);
void printcinema(char arreglo[15][20]);
char resycan(char arreglo[15][20], string seleccion);
int sum_div(int n);
int ** llenarMatriz();
int estrellas(int **puntero,int filas,int columnas);
int *** rotate_matriz(int dim);
void imprimir_conjunto_matriz(int ***conj_mat , int dim);
int * interseccion_rectangulos_C(int A[],int B[]);
int Factorial(int a);

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

                char mayus[200];

                int frecuencia[26] = {0};

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
                int n = 0;
                char *numero_caracter;

                cout<<"Ingrese un numero: "<<endl;
                cin>>n;

                cadena_caracteres(n, numero_caracter);

                cout<<"El numero ingresado: "<<n<<" convertido a cadena es: "<<numero_caracter<<endl;

                delete[]numero_caracter;
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
                while(Letras[cont]!='\0')
                    cont++;
                for(i=0;i<cont;i++){
                    for(j=0;j<7;j++){
                        if (Letras[i]==NumRomanos[j]){
                            Numero[i]=NumEquivalentes[j];
                        }
                    }
                }
                for (k=0;k<10;k++){
                    if (Numero[k]>Numero[k+1])
                        suma+=Numero[k];
                    else if (Numero[k]<Numero[k+1])
                        suma-=Numero[k];
                    else
                        suma+=Numero[k];
                }
                cout<<suma<<endl;
                break;
            }
            case 11:{
                char sala[15][20];
                string seleccion;

                for(int i=0;i<15;i++){
                    for(int j=0;j<20;j++){
                        sala[i][j] = '-';
                    }
                }
                printcinema(sala);

                while(true){
                    cout << "Indique el asiento a reservar o a cancelar. Ejemplo: 'can A-17', 'res B-20', ingrese x para salir" << endl;
                    cout << "Comando: ";
                    getline(cin, seleccion);

                    if (seleccion == "x"){
                        break;
                    }

                    sala[15][20] = resycan(sala, seleccion);
                    printcinema(sala);
                }
                break;
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
                break;
            }
            case 13:{
                int **puntero=llenarMatriz();
                cout<<"El numero de estrellas es: "<<estrellas(puntero,6,8)<<endl;

                break;
            }
            case 14:{
                int dim = 5;

                int *** m = rotate_matriz(dim);

                imprimir_conjunto_matriz(m,dim);
                break;
            }
            case 15:{
                int A[]={0,0,8,4};
                int B[]={5,2,3,2};
                int *zoe=interseccion_rectangulos_C(A,B);
                cout<<"{"<<zoe[0]<<","<<zoe[1]<<","<<zoe[2]<<","<<zoe[3]<<"}"<<endl;
                break;
            }
            case 16:{
                long long int n=0,fact1=0,fact2=0;
                cout<<"Ingrese un numero"<<endl;
                cin>>n;
                fact1=Factorial(n);
                cout<<"Para una malla de "<<n<<"x"<<n<<" hay ";
                n=n+n;
                fact2=Factorial(n);
                n=fact2/(fact1*fact1);
                cout<<n<<" caminos"<<endl;
                break;
            }
            case 17:{
                int n1, n2, sum1, sum2;
                cout << "Ingrese dos numeros: " << endl;
                cin >> n1 >> n2;
                sum1 = sum_div(n1);
                sum2 = sum_div(n2);
                if (sum1 == n2 && sum2 == n1) {
                    cout << n1 << " y " << n2 << " son numeros amigos." << endl;
                    cout<<"El resultado de la suma es: "<<sum1 + sum2<<endl;
                } else {
                    cout << n1 << " y " << n2 << " no son numeros amigos." << endl;
                }

                break;
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

void cadena_caracteres(int numero_entero, char *& numero_caracter){
    int numero = numero_entero;
    int digitos = 0;

    while ( numero != 0){
        numero = numero / 10;
        digitos++;
    }
    numero_caracter = new char[digitos + 1];
    numero_caracter[digitos] = '\0';
    for (int i = digitos - 1; i >= 0; i-- ){
        numero_caracter[i] = 48 + numero_entero % 10;
        numero_entero = numero_entero / 10;
    }
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
    for (int i = 0; i < 200; i++){
        frecuencia[arreglo[i] - 65]++;
    }

}

void imprimirFrecuencia (int frecuencia[]){
    for (int i = 0; i < 26 ; i++){
        if (frecuencia[i] > 0){
            cout<<(char)('A' + i)<<": "<<frecuencia[i]<<endl;
        }
    }
}

void printcinema(char arreglo[15][20]){

    cout << endl << endl;
    cout << "Asientos disponibles en -, reservados en +." << endl;
    for(int i = 0; i < 15; i++){
        for(int t= 0; t < 20; t++){
            cout << arreglo[i][t] << " ";
        }
        cout << endl;
    }
}

char resycan(char arreglo[15][20], string seleccion){

    int t = 0;
    char des[3];
    int fila = seleccion[4]- 65;
    int columna;

    if(seleccion[7]-48 >= 0 and seleccion[7]-48 <= 9){
        columna =((seleccion[6]-48)*10) + (seleccion[7]-49);
    }
    else{
        columna = seleccion[6]-49;
    }
    if(fila < 0 or fila >= 15){
        cout << endl;
        cout << "Comando incorrecto." << endl;
        return arreglo[15][20];
    }
    else if(columna < 0 or columna >= 20){
        cout << endl;
        cout << "Comando incorrecto." << endl;
        return arreglo[15][20];
    }
    for(int i=0; seleccion[i], i <=2; i++,t++){
        *(des+i) = seleccion[i];
    }
    if(des[0] == 'r'){
        if(*(*(arreglo+fila)+columna)== '+'){
            cout << endl;
            cout << "Asiento ya reservado, lamentablemente deberas buscar otro." << endl;
        }
        else{
            *(*(arreglo+fila)+columna) = '+';
        }
    }
    else if(des[0] == 'c'){
        if(*(*(arreglo+fila)+columna) == '-'){
            cout << endl;
            cout << "Este asiento no esta reservado." << endl;
        }
        else{
            *(*(arreglo+fila)+columna) = '-';
        }
    }
    return arreglo[15][20];
}

int sum_div(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int ** llenarMatriz()
{
    // Funcion para el problema 13

    int **puntero_matriz;
    int nfilas;
    int ncol;

    cout<<"Digite el numero de filas: ";
    cin>>nfilas;
    cout<<"Digite el numero de columnas: ";
    cin>>ncol;

    puntero_matriz = new int*[nfilas];  //reservando memoria para la matriz
    for(int i=0;i<nfilas;i++){
        puntero_matriz[i]=new int[ncol];
    }
    cout<<endl;
    cout<<"Digite los elementos de la imagen: "<<endl;
    for(int i=0;i<nfilas;i++){
        for(int j=0;j<ncol;j++){
            cout<<"Digite el elemento["<<i+1<<"]["<<j+1<<"]: ";
            cin>>*(*(puntero_matriz+i)+j);
        }
    }
    return puntero_matriz;
}

int estrellas(int **puntero,int filas,int columnas)
{
    // Funcion para el problema 13

    int estrellas=0;

    for(int i=1;i<filas-1;i++){       //se recorre toda la matriz, sin tener en cuuenta los bordes
        for(int j=1;j<columnas-1;j++)
            if(((*(*(puntero+i)+j)+*(*(puntero+i)+j-1)+*(*(puntero+i)+j+1)+*(*(puntero+i-1)+j)+*(*(puntero+i+1)+j))/5)>6) //si se cumple la condicion se ha encontrado una estrella2
                estrellas++;
    }
    return estrellas;
}

int *** rotate_matriz(int dim)
{
    int *** conj_matriz = new int **[4];
    conj_matriz[0] = generar_matriz(dim);
    for (int i = 1; i<4; i++)
    {
        conj_matriz[i] = rotate_90(conj_matriz[i - 1],dim);
    }
    return conj_matriz;
}

void imprimir_conjunto_matriz(int ***conj_mat , int dim)
{
    for (int i = 0; i < 4 ; i++){
        cout<<"Matriz rotada "<<i*90<<" grados"<<endl<<endl;
        imprimir_matriz(conj_mat[i],dim);
        cout<<endl<<endl;
    }
}

int * interseccion_rectangulos_C(int A[],int B[]){
    int ancho ,x,y,alto;
    if (A[1]<=B[0]){
        ancho=A[0]+A[2]-B[0];}
    else{ancho=B[0]+B[2]-A[0];}
    if (A[0]<=B[0]){
        x=B[0];}
    else{x=A[0];}
    if (B[1]<=A[1]){
        y=A[1];}
    else{y=B[1];}
    if (B[1]<=A[1]){
        alto=B[1]+B[3]-A[1];}
    else{alto=A[1]+A[3]-B[1];}
    static int C[]={x,y,ancho,alto};
    return C;
}

int Factorial(int a){
    long long int fact=1;
    if (a==0){
        return fact;
    }
    else if(a!=0){
        for (int i=1;i<= a;i++){
            fact*=i;
        }
    }
    return fact;
}



