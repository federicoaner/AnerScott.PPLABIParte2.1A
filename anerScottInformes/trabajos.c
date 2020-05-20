
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacion.h"
#include"bicicletas.h"
#include "trabajos.h"
#include "informes.h"





int cargarDescripcionServicios(char descripcion[],float* precio,int id, eServicio tiposServ[], int tam ){

    int todoOk=0;

    for (int i=0;i<tam;i++){
        if(tiposServ[i].id==id){
        strcpy(descripcion, tiposServ[i].descripcion);
        *precio=tiposServ[i].precio;

        todoOk=1;
        }
    }
    return todoOk;
}

void mostrarServicios( eServicio tiposServ[], int tamServicio)
{

    printf("************Servicios***************\n\n ");
    printf("Id     Descripcion    Precio  \n\n");

    for(int i=0; i<tamServicio; i++)
    {
        printf(" %d    %10s    %.2f\n",tiposServ[i].id,tiposServ[i].descripcion,tiposServ[i].precio);
    }

}

void inicializarTrabajos(eTrabajo vec[],int tam)
{

    for(int i=0; i<tam; i++)
    {
     vec[i].isEmpty=1;
    }

}

int buscarLibreTrabajo (eTrabajo vec[], int tam)
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

void mostrarTrabajo(eTrabajo x,eServicio tiposServ[],int tamServ)
{
    char nombreServicio[21];
    float precioServicio;
    cargarDescripcionServicios(nombreServicio,&precioServicio,x.idServicio ,tiposServ,tamServ);
    //cargarDescripcionColorBicicleta(nombreColor,x.idColor,tiposC,tamColor);*/
    printf(" %d              %d            %10s     $%.2f    %d/%d/%d \n", x.id ,x.idBicicleta ,nombreServicio,precioServicio,x.fecha.dia,x.fecha.mes,x.fecha.anio );

}

void mostrarTrabajos(eTrabajo vec[],int tam , eServicio tiposServ[], int tamServ)
{
    system("cls");
    int flag=0;

    printf("************listado de Trabajos***************\n ");
    printf("Id         IdBicicleta          Servicio        Precio     Fecha\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarTrabajo(vec[i],tiposServ,tamServ);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("*****No hay Trabajos para mostrar******\n");
    }
}

/*int altaTrabajo(int idX,eTrabajo vec[], int tamTrabajo,eServicio servicios[],int tamServicios,eBicicleta listaB[], int tam,eTipo tipos[],int tamTipos,eColor colores[],int tamColores)*/
int altaTrabajo(int idX,eTrabajo vec[], int tamTrabajo,eServicio tiposServ[],int tamServicios,eBicicleta listaB[], int tamB,eTipo tiposB[],int tamTip,eColor tiposC[],int tamC,eCliente listaCli[],int tamCli)

{
    int todoOK = -1;
    int indice = buscarLibreTrabajo(vec,tamTrabajo);
    int auxInt;

    eTrabajo auxTrabajo;
    system("cls");

    printf("***** ALTA TRABAJO *****\n\n");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }

    else
    {
        while(todoOK==-1)
        {

            mostrarBicicletas(listaB,tamB,tiposB ,tamTip,tiposC,tamC,listaCli,tamCli);
            if((utn_getEntero(&auxInt,2,"Ingrese el id de la Bicicleta: ","Error. Reingrese el id de la Bicicleta\n",100,1000))==0)
            {
                if((buscarBicicleta(auxInt,listaB,tamB))!=-1)
                {
                    auxTrabajo.idBicicleta =auxInt;
                }
                else
                {
                    printf("No existe ninguna Bicicleta con el id indicado: %d\n\n",auxInt);
                    todoOK=0;
                    break;
                }

            }
            else
            {
                printf("Se quedo sin intentos\n");
                todoOK=0;
                break;
            }
            //SERVICIOS
            mostrarServicios(tiposServ,tamServicios);
            if((utn_getEntero(&auxInt,2,"Ingrese el servicio: ","Error. Reingrese rango valido\n",2000,2003))==0)
            {
                auxTrabajo.idServicio=auxInt;
            }
            else
            {
                printf("Se quedo sin intentos \n");
            }
            //DIA
            if((utn_getEntero(&auxInt,2,"Ingrese el dia: ","Error. Reingrese el dia\n",1,31))==0)
            {
                auxTrabajo.fecha.dia=auxInt;
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el dia\n");
                todoOK=0;
                break;
            }
            //MES
            if((utn_getEntero(&auxInt,2,"Ingrese el mes: ","Error. Reingrese el mes\n",1,12))==0)
            {
                auxTrabajo.fecha.mes=auxInt;
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el mes\n");
                todoOK=0;
                break;
            }
            //ANIO
            if((utn_getEntero(&auxInt,2,"Ingrese el anio: ","Error. Reingrese el anio\n",2019,2050))==0)
            {
                auxTrabajo.fecha.anio=auxInt;
                todoOK=1;
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el anio\n");
                todoOK=0;
                break;

            }


        }
        if(todoOK==1)
        {
            auxTrabajo.id = idX;

            auxTrabajo.isEmpty = 0;

            printf("El id del nuevo trabajo es: %d\n",idX);

            vec[indice] = auxTrabajo;
        }


    }


    return todoOK;
}


