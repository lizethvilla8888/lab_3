#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
void lectura (string& nombre);
void codificacion (string& texto,int metodo ,int semilla) ;
void decodificacion (string& texto, int metodo, int semilla);
void binario_caracter (string& texto);
void caracter_binario (string& texto);


int main()
{

}




void lectura (string& nombre)
{
    ifstream fin; //leer un archivo
    string frase,texto = "";
    try
    {
        fin.open(nombre.c_str()); //Abre un archivo para lectura
        while (!fin.eof()){
            getline (fin,frase);
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
cout << texto<<endl;
}

void codificacion (string& texto, int metodo ,int semilla)
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

    if (metodo == 2){cout << "Metodo de codificacion 2.\n";
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
    cout << "          :12341234123412341234123412341234"<<endl;
    cout << "TEXTO:     "<< texto<<endl;
    cout << "CODIFICADO:"<< codificado<<endl;
}

void decodificacion (string& texto, int metodo, int semilla)
{
string decodificado = "";

    if (metodo == 1){   cout << "Metodo de decodificacion 1.\n";
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
    cout << "             123412341234123412341234"<<endl;
    cout << "texto        " <<texto<<endl;
    cout << "decodificado:"<<decodificado<<endl;
}

void binario_caracter (string& texto)
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
    cout << texto_caracter<<endl;
}

void caracter_binario (string& texto)
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
cout <<"BINARIO: "<< binario <<endl;
}

