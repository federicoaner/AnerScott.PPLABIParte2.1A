

#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED


typedef struct{

int id; //PK
char descripcion[20];

}eTipo;

typedef struct{

int id; //PK
char descripcion[20];

}eColor;



typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int rodado;
    int idCliente;
    int isEmpty;

} eBicicleta;

typedef struct
{
int id; //PK
char nombre[20];
char sexo;


} eCliente;


#endif // BICICLETAS_H_INCLUDED


void inicializarBicicletas(eBicicleta vec[],int tam);
void mostrarBicicleta(eBicicleta x, eTipo tiposB[],int tamTip,eColor tiposC[],int tamColor,eCliente z );
void mostrarBicicletas (eBicicleta vec[],int tam, eTipo tiposB[], int tamTip,eColor tiposC[],int tamColor,eCliente listaCli[],int tamCLi);
int buscarLibre(eBicicleta vec[], int tam);
void hardcodearBicicletas(eBicicleta vec[],int cant);
int cargarDescripcionTipoBicicleta(char descripcion[],int id, eTipo tiposB[], int tam );
void mostrarTiposBicicleta( eTipo tiposB[], int tam);
int altaBicicleta(int idx,eBicicleta vec[], int tam,eTipo tiposB[],int tamTip,eColor tiposC[],int tamColor);
int cargarDescripcionColorBicicleta(char descripcion[],int id, eColor tiposC[], int tam );
void mostrarColorBicicleta( eColor tiposC[], int tam);
int buscarBicicleta(int id,eBicicleta vec[],int tam);
void bajaBicicleta(eBicicleta vec[],int tam, eTipo tiposB[],int tamTip,eColor tiposC[],int tamColor,eCliente listaCli[],int tamCli);
void ordenarBicicletas(eBicicleta vec[],int tam,eTipo tiposB[],int tamTip,eColor tiposC[],int tamColor);
void modificarBicicleta(eBicicleta vec[],int tam, eTipo tiposB[],int tamTip,eColor tiposC[],int tamColor);
int menuModificar();

