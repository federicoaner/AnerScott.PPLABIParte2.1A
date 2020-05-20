#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


int menuInformes();
void informar(eBicicleta vec[], int tamB, eTipo tiposB[], int tamTip, eColor tiposC[], int tamC, eTrabajo tiposT[],int tamTra, eServicio tipoServ[], int tamServ,eCliente listaCli[],int tamCli);
void informarBiciletasxRodado (eBicicleta vec[], int tam, eTipo tiposBic[], int tamTipos,eColor tipoC[], int tamC,eCliente listaCli[],int tamCli);
void informarBiciletasxTipo (eBicicleta vec[], int tam, eTipo tiposBic[], int tamTipos,eColor tipoC[], int tamC,eCliente listaCli[],int tamCli);
void informarTrabajosxServicio (eTrabajo vec[], int tam, eServicio tipoServ[], int tamServ,eCliente listaCli[],int tamCli);
void informarBicicletasXColor(eBicicleta listaB[], int tam, eColor tiposC[], int tamC, eTipo tipoB[], int tamTip,eCliente listaCli[],int tamCli);
void informarBicicletasSeparadasXtipo(eBicicleta listaB[], int tam, eColor tiposC[], int tamC, eTipo tipoB[], int tamTip,eCliente listaCli[],int tamCli);
void informarMenorRodado(eBicicleta listaB[], int tam, eColor tiposC[], int tamC, eTipo tipoB[], int tamTip,eCliente listaCli[],int tamCli);
void informarBiciletasxColours (eBicicleta vec[], int tam, eTipo tiposBic[], int tamTipos,eColor tipoC[], int tamC,eCliente listaCli[],int tamCli);
