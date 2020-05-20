#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "validacion.h"
#include"bicicletas.h"
#include "trabajos.h"
#include "informes.h"





int menuInformes()
{
    char opcion;

    system("cls");
    printf("***** Informes Bicicletas *****\n\n");
    printf("a. Informar bicicletas x color\n");
    printf("b. informar bicicletas x tipo\n");
    printf("c. Bicicletas menor rodado\n");
    printf("d. informar bicicletas separadas x tipo\n");
    printf("e. trabajos x servicio y fecha\n");
    printf("f. ----------------\n");
    printf("g.  Salir\n");


    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}

//---------------------------------------------------------------------------------------------------

void informar(eBicicleta vec[], int tamB, eTipo tiposB[], int tamTip, eColor tiposC[], int tamC, eTrabajo tiposT[],int tamTra, eServicio tipoServ[], int tamServ,eCliente listaCli[],int tamCli)
{
    char seguir = 's';
    char confirma;

    do{
        switch(menuInformes())
        {
        case 'a':
          informarBiciletasxColours(vec,tamB,tiposB,tamTip,tiposC,tamC,listaCli,tamCli);
            break;
        case 'b':
            informarBiciletasxTipo(vec,tamB,tiposB,tamTip,tiposC,tamC,listaCli,tamCli);
            break;
        case 'c':
           informarMenorRodado(vec,tamB,tiposC,tamC,tiposB,tamTip,listaCli,tamCli);
            break;
        case 'd':
            informarBicicletasSeparadasXtipo(vec,tamB,tiposC,tamC,tiposB,tamTip,listaCli,tamCli);
            break;
        case 'e':
            informarTrabajosxServicio(tiposT,tamTra,tipoServ,tamServ,listaCli,tamCli);
            break;
        case 'f':
           // informarTrabajosxServicio(tiposT,tamTra,tipoServ,tamServ,listaCli,tamCli);

        case 'g':
            printf("Confirme salida: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }

        system("pause");

    }while(seguir == 's');

}





void informarBiciletasxTipo (eBicicleta vec[], int tam, eTipo tiposBic[], int tamTipos,eColor tipoC[], int tamC,eCliente listaCli[],int tamCli)
{
    int tipo;
    int flag = 0;

    system("cls");
    printf("***** Bicicletas por Tipo *****\n");
    mostrarTiposBicicleta(tiposBic,tamTipos);
    printf("Ingrese tipo: ");
    scanf("%d", &tipo);


    printf("  Id                Marca       Rodado       Tipo          Color     Nombre\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].idTipo == tipo)
        {
            mostrarBicicleta(vec[i], tiposBic, tamTipos,tipoC,tamC,listaCli[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** No hay bicicletas de este  tipo ***\n\n");
    }


}


void informarTrabajosxServicio (eTrabajo vec[], int tam, eServicio tipoServ[], int tamServ,eCliente listaCli[],int tamCli)
{
    int tipoServicio;
    int flag = 0;
    //int cantidad=0;

    system("cls");
    printf("***** Informar Trabajos por Tipo de Servicio *****\n");
    mostrarServicios(tipoServ,tamServ);
    printf("\nIngrese tipo de servicio: ");
    scanf("%d", &tipoServicio);


    printf("Id         IdBicicleta          Servicio        Precio     Fecha\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].idServicio == tipoServicio)
        {
            mostrarTrabajo(vec[i],tipoServ,tamServ);
            flag = 1;

        }
       // cantidad++;
    }

    // printf("\nhay %d trabajos realizados con este servicioo\n",cantidad);

    if(flag == 0)
    {
        printf("*** No hay  trabajos realizados con este servicio ***\n\n");
    }
}

void informarBicicletasXColor(eBicicleta listaB[], int tam, eColor tiposC[], int tamC, eTipo tipoB[], int tamTip,eCliente listaCli[],int tamCli)
{
    int flag;

    system("cls");
    printf("***** Informe Bicicletas x color *****\n\n");

    //recorro los sectores
    for(int c=0; c<tamC; c++)
    {
        flag = 0;
        printf("Color: %s\n", tiposC[c].descripcion);
        printf(" ---------\n\n");


        //recorro los empleados buscando aquellos del sector donde estoy parado
        for(int b=0; b<tam; b++)
        {
            if(listaB[b].isEmpty == 0 && listaB[b].idColor == tiposC[c].id)
            {

                mostrarBicicleta(listaB[b],tipoB,tamTip,tiposC,tamC,listaCli[c]);//
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\nNo hay bicicletas con este color\n");
        }
        printf("\n--------------------------------------------------------------\n");
    }

}


void informarBicicletasSeparadasXtipo(eBicicleta listaB[], int tam, eColor tiposC[], int tamC, eTipo tipoB[], int tamTip,eCliente listaCli[],int tamCli)
{
    int flag;

    system("cls");
    printf("***** Informe Bicicletas x Tipo *****\n\n");


    for(int t=0; t<tamC; t++)
    {
        flag = 0;
        printf("tipo: %s\n", tipoB[t].descripcion);
        printf(" ---------\n\n");



        for(int b=0; b<tam; b++)
        {
            if(listaB[b].isEmpty == 0 && listaB[b].idTipo == tipoB[t].id)
            {
                //mostrarBicicleta(listaB[b],tipoB,tamTip,tiposC,tamC,listaCli[t]);//
                mostrarBicicleta(listaB[b],tipoB,tamTip,tiposC,tamC,listaCli[t]);//
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\nNo hay bicicletas con este tipo\n");
        }
        printf("\n--------------------------------------------------------------\n");
    }

}

void informarMenorRodado(eBicicleta listaB[], int tam, eColor tiposC[], int tamC, eTipo tipoB[], int tamTip,eCliente listaCli[],int tamCli)
{
    //int rodado;
    int flag = 0;
    int menorRodado;


    system("cls");
    printf("***** Informe menor rodado *****\n\n");

    for(int i = 0; i < tam; i++)
	{
		if(flag == 0 && listaB[i].isEmpty == 0)
		{
			menorRodado = listaB[i].rodado;
			flag = 1;
		}
		else if (listaB[i].isEmpty == 0 && listaB[i].rodado < menorRodado)
		{
			menorRodado = listaB[i].rodado;
		}
	}
	printf("El menor es :  %.d   \n\n", menorRodado);

	for(int i = 0; i < tam; i++)
	{
		if(listaB[i].rodado == menorRodado)
		{
			mostrarBicicleta(listaB[i],tipoB,tamTip,tiposC,tamC,listaCli[i]);
		}
	}
}

void informarBiciletasxColours (eBicicleta vec[], int tam, eTipo tiposBic[], int tamTipos,eColor tipoC[], int tamC,eCliente listaCli[],int tamCli)
{
    int color;
    int flag = 0;

    system("cls");
    printf("***** Bicicletas por Color *****\n");
    mostrarColorBicicleta(tipoC,tamC);
    printf("Ingrese color: ");
    scanf("%d", &color);


    printf("  Id                Marca       Rodado       Tipo          Color     Nombre\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].idColor == color)
        {
            mostrarBicicleta(vec[i], tiposBic, tamTipos,tipoC,tamC,listaCli[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** No hay bicicletas de este  color ***\n\n");
    }


}


