#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

string lectura (string& nombre);
string codificacion (string& texto,int metodo ,int semilla) ;
string decodificacion (string& texto, int metodo, int semilla);
string  binario_caracter (string& texto);
string caracter_binario (string& texto);
void escritura (string&,string&);
void menu_codificacion ();
void menu_decodificacion ();
void menu_app();
int inicio_sesion(string&);

int main()
{
    int opcion1 = 1;
    while (opcion1 != 0)
    {
        system("cls");
        cout<<"***** Practica 3 *****\n"<<endl;
        cout<<"seleccione una opcion \n"<<endl;
        cout<<"1) Codificacion."<<endl;
        cout<<"2) Decodificacion."<<endl;
        cout<<"3) Aplicacion. "<<endl;
        cout<<"\n Presione 0 para salir"<<endl;
        cin>>opcion1;

        switch (opcion1)
        {
        case 1:
            menu_codificacion();
            break;

        case 2:
            menu_decodificacion ();
            break;

        case 3:
            menu_app();
            break;

        default:
            cout <<"La opcion ingresada no es valida\n";
            break;

        } //switch
    }//while opcion1

}

void menu_codificacion ()
{
    int metodo=0,semilla=0; string nombre="",texto="";string verificacion = "";
    system("cls");
    cout << "***** CODIFICACION *****\n"<<"Problema 1"<<endl;
    cout << "Ingrese nombre de texto a codificar:"<<endl;
    cin>>nombre;
    cout << "Ingrese numero de particiones:"<<endl;
    cin >> semilla;
    texto = lectura(nombre);
    texto = caracter_binario(texto);
    cout<<"seleccione una opcion \n"<<endl;
    cout<<"1) Codificacion metodo 1."<<endl;
    cout<<"2) Codificacion metodo 2."<<endl;
    cin >> metodo;
    texto = codificacion ( texto, metodo , semilla);
    escritura(nombre,texto);
}

void menu_decodificacion ()
{
    int metodo=0,semilla=0; string nombre="",texto="";string verificacion = "";
    system("cls");
    cout << "***** DECODIFICACION *****\n"<<"Problema 1"<<endl;
    cout << "Ingrese nombre de texto.txt a decodificar:"<<endl;
    cin>>nombre;
    cout << "Ingrese numero de particiones:"<<endl;
    cin >> semilla;
    cout << "Ingrese metodo de decodificacion:"<<endl;
    cin >> metodo;
    texto = lectura(nombre);
    texto = decodificacion ( texto, metodo,  semilla);
    texto = binario_caracter(texto);
    escritura(nombre,texto);
}

void menu_app()
{
    string sudo="sudo.txt",usuario="usuario.txt";

    int opcion=1;
    while (opcion!=0)
    {
        int veri = 0;
        string archivo_sudo="", archivo_usuario="";
        cout << "***** APLICACION *****\n\n"<<endl;
        cout<<"seleccione una opcion \n"<<endl;
        cout<<"1) Inicio Administrador."<<endl;
        cout<<"2) Inicio Usuario."<<endl;
        cout<< "0) Salir.\n";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "ADMINISTRADOR\n";
            archivo_sudo = lectura(sudo);
            archivo_sudo = decodificacion(archivo_sudo,2,4);
            archivo_sudo = binario_caracter(archivo_sudo);
            veri = inicio_sesion(archivo_sudo);

            if (veri == -1)
                cout << "usuario y contrasena errada.\n";

            if (veri != -1)
            {
                int opcion1 = 1;
                while (opcion1 !=0 )
                {
                    cout << "********* BIENVENIDO ADMINISTRADOR*********\n";
                    cout << "1) Ingresar nuevo usuario.\n";
                    cout << "0) Salir.\n";
                    string dato = "",nuevo = "";
                    cin >> opcion1;

                    switch (opcion1)
                    {
                    case 1:
                        cout << "Ingresar Cedula:\n";
                        cin>>dato;  dato = dato +',';
                        int verificacion = 0;
                        archivo_usuario = lectura(usuario);
                        archivo_usuario = decodificacion(archivo_usuario,2,4);
                        archivo_usuario = binario_caracter(archivo_usuario);

                        verificacion = archivo_usuario.find(dato);
                        if (verificacion == -1)
                        {
                            nuevo = dato;
                            cout << "ingrese clave y saldo separados por (,).\n";
                            cin>> dato;
                            nuevo = nuevo + dato +'.'+'\n';

                            archivo_usuario = archivo_usuario + nuevo;

                        }//(verificacion != -1)

                        else if (verificacion != -1)
                            cout << "usuario ya se encuentra registrado.\n";

                        break;

                        /* default:
                cout << "la opcion no es valida.\n";
                break;*/

                    }//switch (opcion1)

                } // while opcion1 != 0

            }//if veri != -1
            break;

        case 2:
            cout << "********* USUARIO ********* \n";
            archivo_usuario = lectura(usuario);
            archivo_usuario = decodificacion(archivo_usuario,2,4);
            archivo_usuario = binario_caracter(archivo_usuario);

            int veri = 0;
            string usuario,contrasena,verificacion = "";
            cout << "Ingrese nombre de usuario:\n";
            cin >> usuario;
            cout << "Ingrese contrasena:\n";
            cin >> contrasena;
            verificacion = usuario +','+ contrasena + ',';

            veri = archivo_usuario.find(verificacion);

            cout << archivo_usuario<<endl;

            if (veri == -1)
                cout << "usuario y contrasena errada.\n";
            if (veri != -1)
            {
                string usuario_saldo, inicio="",fin="";
                usuario_saldo = archivo_usuario.substr(veri,archivo_usuario.length());
                int  saldo,longitud_verificacion = verificacion.length();
                saldo = usuario_saldo.find('.');
                saldo = saldo - longitud_verificacion;
                usuario_saldo = archivo_usuario.substr(longitud_verificacion,saldo);
                saldo = stoi(usuario_saldo);
                saldo = saldo - 1000;

                inicio =  archivo_usuario.substr(0,veri);
                fin = archivo_usuario.substr(longitud_verificacion+veri+usuario_saldo.length()+1,veri+longitud_verificacion);

                int opcion1=1;
                while (opcion1 !=0){
                    cout << "\n********* BIENVENIDO "<<usuario <<"*********\n";
                    cout << " 1. Consultar saldo.\n 2. Retirar dinero.\n 3. salir.\n";
                    cin>> opcion1;
                    switch (opcion1)
                    {
                    case 1:
                        cout << " 1. Consultar saldo.\n\n";
                        cout << "Su saldo es :" <<saldo<<endl;
                        break;

                    case 2:
                        cout << "2. Retirar dinero.";
                        int retiro;
                        cout << "ingrese cantidad de dinero que desea retirar:\n";
                        cin >> retiro;
                        if (retiro > saldo )
                            cout << "No se puede realizar retiro \n Saldo insuficiente\n";
                        else if (retiro < saldo){
                            saldo = saldo - retiro;
                            cout << "Saldo:" << saldo<<endl;
                        }
                        break;

                    case 3:
                        usuario_saldo= to_string(saldo);
                        verificacion = verificacion + usuario_saldo + '.';
                        archivo_usuario = inicio + verificacion + fin;
                        codificacion(archivo_usuario,2,4);
                        escritura(usuario,archivo_usuario);
                        opcion1 = 0;

                    default:
                        cout <<"La opcion ingresada no es valida\n";
                        break;

                    } //switch

                }//  (opcion1 !=0)

            }//(veri != -1)
            break;

            /* default:
            cout <<"La opcion ingresada no es valida\n";
            break;*/

        } //switch



    } // while pricipal

}

int  inicio_sesion(string& texto)
{
    int veri = 0;
    string usuario,contrasena,verificacion = "";
    cout << "Ingrese nombre de usuario:\n";
    cin >> usuario;
    cout << "Ingrese contrasena:\n";
    cin >> contrasena;
    verificacion = usuario +','+ contrasena + '\n';
    veri = texto.find(verificacion);

    return veri;
}

string lectura (string& nombre)
{
    ifstream fin; //leer un archivo
    string frase,texto = "";
    try
    {
        fin.open(nombre.c_str()); //Abre un archivo para lectura
        while (!fin.eof()){
            getline (fin,frase);
            frase = frase + '\n';
            texto = texto + frase;
        }
    }
    catch(char c)
    {
        if(c=='1')
            cout<<"Error en el archivo de escritura"<<endl;
        else if(c=='2')
            cout<<"Error en el archivo de lectura"<<endl;
        else
            cout<<"Error inesperado";
    }
    return texto;
}

string codificacion (string& texto, int metodo ,int semilla)
{
    string codificado = "";
    if (metodo == 1){   cout << "Metodo de codificacion 1.\n";
        string auxiliar = "";
        int repeticiones =  texto.length()/ semilla;
        int aguja = semilla,cantidad_ceros=0, cantidad_unos= 0;
        auxiliar = texto.substr(0,semilla);
        for (int k=0; k<semilla ; k++)// ciclo que cuenta los 1 y 0 en cadena auxiliar del primer bloque
        {
            if (auxiliar [k]== '1')
                cantidad_unos++;
            if (auxiliar [k] == '0')
                cantidad_ceros++;
        }
        for (int i = 0; i < repeticiones; i++){ //for principal
            if (i>1)
            {
                cantidad_ceros=0, cantidad_unos= 0;
                // ciclo que cuenta los 1 y 0 en cadena auxiliar
                string cantidad = texto.substr((semilla*(i-1)),semilla);
                for (int k=0; k<semilla ; k++)
                {
                    if (cantidad [k]== '1')
                        cantidad_unos++;
                    if (cantidad [k] == '0')
                        cantidad_ceros++;
                }
            }
            if (cantidad_unos == cantidad_ceros || i == 0)
            {
                for (int j = 0; j<semilla ; j++ )
                {
                    if (auxiliar [j] == '1')
                        auxiliar [j]= '0';
                    else if(auxiliar [j] == '0')
                        auxiliar [j] = '1';
                }
            } // if cantida_unos == cantidad_ceros
            else  if  (cantidad_ceros >cantidad_unos )
            {
                for (int j = 1; j<semilla ; j=j+2)
                {
                    if (j % 2 != 0)
                    {
                        if (auxiliar [j] == '1')
                            auxiliar [j]= '0';
                        else if(auxiliar [j] == '0')
                            auxiliar [j] = '1';
                    }
                }
            } // if cantidad_ceros >cantidad_unos
            else if (cantidad_unos > cantidad_ceros) // else
            {
                for (int j = 2; j<semilla; j=j+3 )
                {
                    if (auxiliar [j] == '1')
                        auxiliar [j]= '0';
                    else if(auxiliar [j] == '0')
                        auxiliar [j] = '1';
                }
            } //if cantidad_unos>cantidad_ceros
            codificado = codificado + auxiliar;
            auxiliar = "";
            auxiliar= texto.substr(aguja, semilla);
            aguja = aguja+semilla;
        } // for repeticiones
    } // metodo 1

    if (metodo == 2){cout << "***** Metodo de codificacion 2. *****\n";
        int repeticiones = texto.length()/ semilla,aguja = semilla;
        string auxiliar = "";
        auxiliar = texto.substr(0,semilla);string copia;
        for (int i = 0; i< repeticiones;i++){
            copia = auxiliar;
            char inicio = copia[semilla-1];
            for (int j = 0; j<= semilla-1;j++){
                auxiliar [j+1]=copia[j]; // 1 0 _ 2 1 _ 3 2
                if (j==0){
                    auxiliar [0]= inicio; }
            }
            codificado = codificado + auxiliar;
            auxiliar = "";
            auxiliar = texto.substr(aguja, semilla);
            aguja = aguja+semilla;
            inicio = copia [semilla-1];
        }
    } //metodo 2

    return codificado;
}

string decodificacion (string& texto, int metodo, int semilla)
{
    string decodificado = "";

    if (metodo == 1){   cout << "***** Metodo de decodificacion 1. *****\n\n";
        string auxiliar = "";
        int repeticiones =  texto.length()/ semilla;
        int aguja = semilla,cantidad_ceros=0, cantidad_unos= 0;
        auxiliar = texto.substr(0,semilla);  cout << "auxiliar"<<auxiliar<<endl;
        for (int i = 0; i < repeticiones; i++)  { //for principal
            if (cantidad_unos == cantidad_ceros || i == 0)
            {
                for (int j = 0; j<semilla ; j++ )
                {
                    if (auxiliar [j] == '1')
                        auxiliar [j]= '0';
                    else if(auxiliar [j] == '0')
                        auxiliar [j] = '1';
                }
            } // if cantida_unos == cantidad_ceros
            else  if  (cantidad_ceros >cantidad_unos )
            {
                for (int j = 1; j<semilla ; j=j+2)
                {
                    if (auxiliar [j] == '1')
                        auxiliar [j]= '0';

                    else if(auxiliar [j] == '0')
                        auxiliar [j] = '1';
                }
            } // if cantidad_ceros >cantidad_unos
            else if (cantidad_unos > cantidad_ceros) // else
            {
                for (int j = 2; j<semilla; j=j+3 )
                {
                    if (auxiliar [j] == '1')
                        auxiliar [j]= '0';
                    else if(auxiliar [j] == '0')
                        auxiliar [j] = '1';
                }
            } //if cantidad_unos>cantidad_ceros
            cantidad_ceros=0, cantidad_unos= 0;
            // ciclo que cuenta los 1 y 0 en cadena auxiliar
            for (int k=0; k<semilla ; k++)
            {
                if (auxiliar [k]== '1')
                    cantidad_unos++;
                if (auxiliar [k] == '0')
                    cantidad_ceros++;
            }
            decodificado = decodificado + auxiliar;
            auxiliar = "";
            auxiliar= texto.substr(aguja, semilla);
            aguja = aguja+semilla;
        } // for repeticiones
    } // if metodo == 1

    if (metodo == 2)
    {
        string auxiliar = "",copia="";
        int repeticiones =  texto.length()/ semilla;
        int aguja = semilla;
        auxiliar = texto.substr(0,semilla);
        copia = auxiliar;
        for (int i = 0; i < repeticiones; i++)  {
            copia = auxiliar;
            for (int j = 0; j<semilla;j++){
                if (j != semilla-1)
                    auxiliar[j] = copia [j+1];
                if (j == semilla-1)
                    auxiliar[j] = copia[0];
            }
            decodificado = decodificado + auxiliar;
            auxiliar = "";
            auxiliar= texto.substr(aguja, semilla);
            aguja = aguja+semilla;
        }//for principal metodo 2
    }

    return decodificado;
}

string binario_caracter (string& texto)
{
    string auxiliar="",texto_caracter= "";  // 01000001011000100100001101100100 A: 65, b:98, C:67, d:100
    int semilla = 8, repeticiones =  texto.length()/ semilla,aguja = semilla,vector []= {128,64,32,16,8,4,2,1};
    auxiliar = texto.substr(0,semilla);
    for (int i = 0; i < repeticiones; i++){ //for principal
        int resultado=0;
        for (int j=0; j<8; j++) // 0100 0001 65   64+1 = 65
        {
            if (auxiliar[j]== '1')
                resultado = resultado+vector [j];
        }
        auxiliar = "";
        auxiliar= texto.substr(aguja, semilla);
        aguja = aguja+semilla;
        char caracter = resultado;
        texto_caracter= texto_caracter + caracter ;
    } // for repeticiones

    return texto_caracter;
}

string caracter_binario (string& texto)
{
    int longitud_texto = texto.length();

    string binario ="";
    char letra;
    for (int i =0; i<longitud_texto;i++)
    {
        string copia= "";
        letra = texto [i];
        int num = letra, vector[8] = {128,64,32,16,8,4,2,1};

        for (int j=0; j <8;j++)
        {
            if (num >= vector [j])
            {
                copia = copia + '1';
                num -=vector[j];
            }
            else
                copia = copia + '0';
        }
        binario = binario + copia;
    }
    return binario;
}

void escritura (string& nombre, string& texto)
{
ofstream escribir;
escribir.open(nombre.c_str(),ios::out);

if (escribir.fail())
{
    cout << "No se pudo abrir el archivo.\n";
    exit(1);
}
escribir<< texto;
}

