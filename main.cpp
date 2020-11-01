#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
void lectura (string,int,int);

int main()
{
    int opcion = 1;
    while (opcion !=0)
    {
        cout << " ***** Parctica 3 ***** \n \n";
        cout << "1. Codificacion metodo 1 y 2. \n";
        cout << "2. Decodificacion. \n";
        cout << "3. Aplicacion de banco. \n\n";
        cout << "0. Precione 0 para salir.\n";

        cout << "Ingrese opcion.\n";
        cin >> opcion;

        switch (opcion) {
        case 1:
            system("cls"); //limpiar terminal
            int opc2=1;
            while (opc2!=0) {
                cout << "Ingrese nombre de archivo.txt a codificar."<<endl;
                string nombre; cin>>nombre;
                int metodo,semilla;
                cout << "Ingrese numero de particiones de las cadenas:"<<endl;
                cin>>semilla;
                cout << "1.Metodo de codificacion 1."<<endl;
                cout << "2.Metodo de codificacion 2."<<endl;
                cout << "0.Precione 0 para salir.\n"<<endl;
                cout << "Ingrese metodo de codificacion:"<<endl;
                cin >>metodo;

                lectura(nombre,metodo,semilla);
            }
            break;
        }
    }
return 0;
}

void lectura (string pun_nombre,int metodo ,int semilla)
{
    ifstream fin; //leer un archivo
    string texto="",codificado="";
    char letra;

    try
    {
        fin.open(pun_nombre.c_str()); //Abre un archivo para lectura   fin.open(pun_nombre.c_str());

        if (!fin.fail()){
            fin.get(letra);}

        while (!fin.eof()){
            int num = letra; string copia = "";

            for (int j = 7;j>=0;j--){
                if (num >= pow(2,j)){
                    num -= pow (2,j);
                    copia = copia + "1";
                }
                else
                    copia = copia +"0";
            }           // cout << " " <<letra << " " <<copia <<" " ;
            string linea = "";
            linea = linea+copia;
            fin.get(letra);
            texto = texto + linea;
        }
        fin.close();
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
            if (i>1){
                cantidad_ceros=0, cantidad_unos= 0;
                // ciclo que cuenta los 1 y 0 en cadena auxiliar
                string cantidad = texto.substr((semilla*(i-1)),semilla);
                for (int k=0; k<semilla ; k++)
                {
                    if (cantidad [k]== '1')
                        cantidad_unos++;
                    if (cantidad [k] == '0')
                        cantidad_ceros++;
                }}

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


    if (metodo == 2){
        cout << "Metodo de codificacion 2.\n";

        int repeticiones = texto.length()/ semilla,aguja = semilla;

        string auxiliar=""; auxiliar = texto.substr(0,semilla);string copia;

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
    }

    cout << "          :12341234123412341234123412341234"<<endl;
    cout << "TEXTO:     "<< texto<<endl;
    cout << "CODIFICADO:"<< codificado<<endl;


}
