
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"bicicletas.h"

#include "dataWarehouse.h"
#include "validacion.h"
#include "trabajos.h"
//#include "informes.h"




void inicializarBicicletas(eBicicleta vec[],int tam)
{

    for(int i=0; i<tam; i++)
    {
     vec[i].isEmpty=1;
    }

}

void mostrarBicicleta(eBicicleta x, eTipo tiposB[],int tamTip,eColor tiposC[],int tamColor,eCliente z )
{
    char nombreTipo[20];
    char nombreColor[20];
    cargarDescripcionTipoBicicleta(nombreTipo,x.idTipo,tiposB,tamTip);
    cargarDescripcionColorBicicleta(nombreColor,x.idColor,tiposC,tamColor);
    printf(" %d     %15s         %d       %10s     %10s   %10s\n",x.id,x.marca ,x.rodado,nombreTipo,nombreColor,z.nombre);

}

void mostrarBicicletas (eBicicleta vec[],int tam, eTipo tiposB[], int tamTip,eColor tiposC[],int tamColor,eCliente listaCli[],int tamCLi)
{
    system("cls");
    int flag=0;

    printf("************listado de Bicicletas***************\n ");
    printf("id               marca           rodado          tipo         color   Nombre\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarBicicleta(vec[i],tiposB,tamTip,tiposC,tamColor,listaCli[i]);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("*****No hay Bicicletas para mostrar******\n");
    }
}

int buscarLibre(eBicicleta vec[], int tam)
{

    int indice=-1;


    for(int i=0; i<tam; i++)
    {

        if (vec[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}


void hardcodearBicicletas(eBicicleta vec[],int cant){

    for(int i=0;i<cant;i++){

    vec[i].id=ids[i];
    strcpy(vec[i].marca,marcasBicicletas[i]);
    vec[i].rodado=rodados[i];
    vec[i].idTipo=idsTiposdeBicicleta[i];
    vec[i].idColor=idsColordeBicicleta[i];

    vec[i].isEmpty=0;
    }
}

int cargarDescripcionTipoBicicleta(char descripcion[],int id, eTipo tiposB[], int tam ){ //

    int todoOk=0;

    for (int i=0;i<tam;i++){
        if(tiposB[i].id==id){
        strcpy(descripcion, tiposB[i].descripcion);
        todoOk=1;
        }
    }

    return todoOk;
}

void mostrarTiposBicicleta( eTipo tiposB[], int tam)
{

    printf("************Tipos***************\n ");
    printf("Id      Descripcion    \n\n");

    for(int i=0; i<tam; i++)
    {
        printf(" %d    %10s\n",tiposB[i].id,tiposB[i].descripcion);
    }

}

int altaBicicleta(int idx,eBicicleta vec[], int tam,eTipo tiposB[],int tamTip,eColor tiposC[],int tamColor)

{

          int todoOk=0;

    int indice = buscarLibre(vec, tam);
    char auxChar[51];
        int auxInt;

    //int id;
    //int existe;
    eBicicleta auxBicicleta;

    system("cls");
    printf("*********ALTA Bicicleta**************\n\n");

    if(indice == -1) //hay lugar?
    {
        printf("Sistema completo\n\n");
    }

    else  //si hay lugar vengo aca
    {


            auxBicicleta.id=idx;



            utn_getCadena(auxChar,51,2,"Ingrese el marca: ","\nError. Reingrese el nombre\n");
            strcpy(auxBicicleta.marca,auxChar);


            utn_getEntero(&auxBicicleta.rodado,2,"Ingrese Rodado: ","\n error Reingrese Rodado entre 20 y 29\n",20,29);


            mostrarTiposBicicleta(tiposB, tamTip);
            utn_getEntero(&auxInt,2,"Ingrese tipo de bicicleta: ","\n error Reingrese rango valido\n",1000,1003);
            auxBicicleta.idTipo=auxInt;
            /*mostrarTiposBicicleta(tiposB, tamTip);
            printf("\nIngrese  Tipo de Bicicleta: ");
            scanf("%d",&auxBicicleta.idTipo);

             mostrarColorBicicleta(tiposC, tamColor);
            printf("\nIngrese  Color de Bicicleta: ");
            scanf("%d",&auxBicicleta.idColor);*/


            mostrarColorBicicleta(tiposC, tamColor);
            utn_getEntero(&auxBicicleta.idColor,2,"Ingrese color de bicicleta: ","\n error Reingrese rango valido\n",5000,5004);







            auxBicicleta.isEmpty=0;


            vec[indice] =auxBicicleta; //copio al vector el empleado nuevo
            todoOk=1;
         //else interior

    } //else exterior
 return todoOk;
} //fin funcion



int cargarDescripcionColorBicicleta(char descripcion[],int id, eColor tiposC[], int tam ){

    int todoOk=0;

    for (int i=0;i<tam;i++){
        if(tiposC[i].id==id){
        strcpy(descripcion, tiposC[i].descripcion);
        todoOk=1;
        }
    }
    return todoOk;
}

    void mostrarColorBicicleta( eColor tiposC[], int tam)
{

    printf("************Colores***************\n ");
    printf("Id      Descripcion    \n\n");

    for(int i=0; i<tam; i++)
    {
        printf("  %d    %10s\n",tiposC[i].id,tiposC[i].descripcion);
    }

}

int buscarBicicleta(int id,eBicicleta vec[],int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {

        if (vec[i].id == id && vec[i].isEmpty == 0)  //ve si en esa lista de empleados el id q le mande esta ocupado
        {
            indice=i;
            break; //se frena una vez q lo encontramos
        }
    }

    return indice;

}



void bajaBicicleta(eBicicleta vec[],int tam, eTipo tiposB[],int tamTip,eColor tiposC[],int tamColor,eCliente listaCli[],int tamCli)
{

    int indice;
    int id;
    char confirma;

    system("cls");
    printf("*********BAJA BICICLETA**************\n\n");


    printf("ingrese id: ");
    scanf("%d", &id);

    indice=buscarBicicleta(id,vec,tam);


    if(indice==-1) // el id  ya esta?
    {
        printf("no hay registro de una bicicleta con ese id: %d\n",id);
    }
    else
    {
        printf("Id               Marca         Rodado       Tipo         Color\n\n");
        mostrarBicicleta(vec[indice],tiposB,tamTip,tiposC,tamColor,listaCli[indice]);
        printf("\n\nconfirma baja?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            vec[indice].isEmpty=1;
            printf("se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("se ha cancelado la operacion\n\n");
        }
    }//else exterior
}

void ordenarBicicletas(eBicicleta vec[],int tam,eTipo tiposB[],int tamTip,eColor tiposC[],int tamColor)

{

    eBicicleta auxBicicleta;
    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
            if(vec[i].idTipo>vec[j].idTipo) // ordenar x nombre
                // if(vec[i].id>vec[j].id) //  ordenar por id
            {
                auxBicicleta=vec[i];
                vec[i]=vec[j];
                vec[j]=auxBicicleta;
            }
            else if(vec[i].idTipo>vec[j].idTipo && vec[i].rodado <vec[j].rodado) // ordenar x nombre
            {
                auxBicicleta=vec[i];
                vec[i]=vec[j];
                vec[j]=auxBicicleta;
            }
        }//for interior
    }//for exterior

}

void modificarBicicleta(eBicicleta vec[],int tam, eTipo tiposB[],int tamTip,eColor tiposC[],int tamColor)
{

    int indice;
    int id;
    char confirma;
    int nuevoRodado;
    int auxInt;


    system("cls");
    printf("*********MODIFICAR Bicicleta**************\n\n");


    printf("ingrese id: ");
    scanf("%d", &id);

    indice=buscarBicicleta(id,vec,tam);


    if(indice==-1) // el id  ya esta?
    {
        printf("no hay registro de una Bicicleta con ese id: %d\n",id);
    }
    else
    {
        system("cls");

        printf("Id               Marca         Rodado           Tipo         Color\n\n");
       //mostrarBicicleta(vec[indice], tiposB,tamTip,tiposC,tamColor);
//        mostrarBicicleta(vec[i],tiposB,tamTip,tiposC,tamColor,);

        printf("\n\nmodifica esta bicicleta?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            switch(menuModificar())
            {
            case 'a':
                mostrarTiposBicicleta(tiposB,tamTip);
                if((utn_getEntero(&auxInt,2,"Ingrese el nuevo tipo: ","Error. Reingrese el tipo\n",1000,1004))==0)
                {
                   vec[indice].idTipo=auxInt;
                }
                else
                {
                    printf("Se quedo sin reintentos\n");
                }
                break;
            case 'b':
                if((utn_getEntero(&nuevoRodado,2,"Ingrese el nuevo rodado entre 20 y 29: ","Error. Reingrese el rodado\n",20,29))==0)
                {
                    vec[indice].rodado=nuevoRodado;
                }
                else
                {
                    printf("Se quedo sin intentos  \n");
                }
                break;
            case 'c':
                printf("\n\nSe cancelo la operacion");
                break;
            default:
                printf("\n\nIngrese una opcion valida.");
            }
        }
        else
        {
            printf("\n\nSe cancelo la operacion\n\n");
        }

    }

} //fin funcion


int menuModificar()
{
    char opcion;

    printf("\n\nQUE DESEA MODIFICAR?\n\n");
    printf("a-Tipo de Bicicleta\n");
    printf("b-rodado\n");
    printf("c-Salir\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;

}

/*int cargarCliente(char descripcion[],int id, eCLiente tiposCli[], int tamCli ){

    int todoOk=0;

    for (int i=0;i<tam;i++){
        if(tiposC[i].id==id){
        strcpy(descripcion, tiposC[i].descripcion);
        todoOk=1;
        }
    }
    return todoOk;
*/
