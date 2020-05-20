#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;


typedef struct
{
   int id; //PK
    char descripcion[20];
    float precio;

} eServicio;


typedef struct
{
    int id;
    int idBicicleta;
    int idTipo;
    int idServicio;
    eFecha fecha;

    int isEmpty;
} eTrabajo;

#endif // TRABAJOS_H_INCLUDED

int cargarDescripcionServicios(char descripcion[],float* precio,int id, eServicio tiposServ[], int tam );
void mostrarServicios( eServicio tiposServ[], int tamServicio);
void inicializarTrabajos(eTrabajo vec[],int tam);
int buscarLibreTrabajo (eTrabajo vec[], int tam);
int altaTrabajo(int idX,eTrabajo vec[], int tamTrabajo,eServicio tiposServ[],int tamServicios,eBicicleta listaB[], int tamB,eTipo tiposB[],int tamTip,eColor tiposC[],int tamC,eCliente listaCli[],int tamCli);
void mostrarTrabajos(eTrabajo vec[],int tam , eServicio tiposServ[], int tamServ);
void mostrarTrabajo(eTrabajo x,eServicio tiposServ[],int tamServ);

