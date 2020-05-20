#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 8
#define TAMTIP 4
#define TAMCOLOR 5
#define TAMSERV 4
#define TAMTRABAJOS 10
#define TAMCLI 8




#define CANTHARCODE 8

//#include "dataWarehouse.h"
#include "validacion.h"
#include"bicicletas.h"
#include "trabajos.h"
#include "informes.h"







int menu();

int cargarDescripcionServicios(char descripcion[],float* precio,int id, eServicio tiposServ[], int tam );
void mostrarServicios( eServicio tiposServ[], int tamServicio);



int main()
{



    char seguir='s';
    char confirma;
    int proximoId=100;
    int proximoIdTrabajo=200;

    int flagAltaBici=0;



    eBicicleta listaB[TAM];
    eTipo tiposB[TAMTIP]={ {1000,"Rutera"},{1001,"Carrera"},{1002,"Mountain"},{1003,"Bmx"} };
    eColor tiposC[TAMCOLOR]={{5000,"Gris"},{5001,"Negro"},{5002,"Blanco"},{5003,"Azul"},{5004,"Rojo"} };
    eServicio tiposServ[TAMSERV]={{2000,"Limpieza",250},{2001,"Parche",300},{2002,"Centrado",400},{2003,"Cadena",350}};
    eTrabajo listaTrabajo[TAMTRABAJOS];
    inicializarBicicletas(listaB ,TAM);
    inicializarTrabajos(listaTrabajo,TAMTRABAJOS);
    eCliente listaCliente[TAMCLI]={{1,"juan",'m'},{2,"roberto",'m'},{3,"juana",'f'},{4,"maria",'f'},{5,"oscar",'m'},{6,"felipe",'m'},{7,"anamaria",'f'},{8,"alberto",'m'}};

     hardcodearBicicletas(listaB,CANTHARCODE);//hardcodeo
    proximoId+=CANTHARCODE;

    ordenarBicicletas(listaB,TAM,tiposB,TAMTIP,tiposC,TAMCOLOR);



     do
    {
        switch(menu())
        {

        case 'a':

           if( altaBicicleta(proximoId,listaB,TAM,tiposB,TAMTIP,tiposC,TAMCOLOR)==1)
            {
             proximoId++;
            flagAltaBici=1;
           }

            break;

        case 'b':
            if(flagAltaBici==1){

            modificarBicicleta(listaB,TAM,tiposB,TAMTIP,tiposC,TAMCOLOR);
            }
            else
            {
               printf("\nprimero debe dar de alta una Bicicleta\n") ;
            }

            break;

        case 'c':
            bajaBicicleta(listaB,TAM,tiposB,TAMTIP,tiposC,TAMCOLOR,listaCliente,TAMCLI);
            break;

        case 'd':
            mostrarBicicletas(listaB,TAM,tiposB,TAMTIP,tiposC,TAMCOLOR,listaCliente,TAMCLI);

            break;

        case 'e':
        system("cls");
           // mostrarTiposBicicleta( tiposB , TAMSERV );
            informar(listaB,TAM,tiposB,TAMTIP,tiposC,TAMCOLOR,listaTrabajo,TAMTRABAJOS,tiposServ,TAMSERV,listaCliente,TAMCLI   );
            break;

        case 'f':
            system("cls");
            mostrarColorBicicleta(tiposC,TAMCOLOR);

            break;

        case 'g':
        system("cls");
            mostrarServicios( tiposServ, TAMSERV);

            break;

         case 'h':
            if(altaTrabajo(proximoIdTrabajo,listaTrabajo,TAMTRABAJOS,tiposServ,TAMSERV,listaB,TAM,tiposB,TAMTIP,tiposC,TAMCOLOR,listaCliente,TAMCLI  )){

                proximoIdTrabajo++;
            }
            break;

           case 'i':
          mostrarTrabajos(listaTrabajo,TAMTRABAJOS,tiposServ,TAMSERV); //

            break;

            case 'j':
          informar(listaB,TAM,tiposB,TAMTIP,tiposC,TAMCOLOR,listaTrabajo,TAMTRABAJOS,tiposServ,TAMSERV,listaCliente,TAMCLI   );

            break;



        case 'k':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma =='s')
            {
                seguir='n';
            }

            break;

        }
        system("pause");

    }
    while(seguir=='s');


    return 0;
}

int menu()
{
    char opcion;
    system("cls");
    printf("*********GESTION DE BICICLETAS**********\n\n");
    printf("a. Alta Bicicleta\n");
    printf("b. Modificar Bicicleta\n");
    printf("c. Baja Bicicleta\n");
    printf("d. Listar Bicicletas\n");
    printf("e. Listar Tipos\n");
    printf("f. Listar colores\n");
    printf("g. Listar Servicios\n");
    printf("h. Alta Trabajo\n");
    printf("i. Listar Trabajos\n");
    printf("j. Informar\n");
    printf("k. Salir\n\n");

    printf("Indique opcion: ");
    fflush(stdin);
    scanf("%s",&opcion);

    return opcion;

}



