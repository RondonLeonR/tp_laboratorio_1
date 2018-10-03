#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#define CANT 10
#define FREE 1
#define OCUP 0


int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informar\n");
    printf("5- Salir\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int initEmployees(Employee* list, int len)
{
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=FREE;
        list[i].id=i;
    }
    return 0;
}

int showSectors(Sector sectors[],int len)
{
    int opc;

    for(int j=0; j<len; j++)
    {
        printf("\n\t%d\t%s",sectors[j].id,sectors[j].descripcion);
    }
    printf("\nSeleccione su Sector: ");
    scanf("%d",&opc);

    return opc;
}

void LoadDescrip(Sector sectors[],int lenSec,int idSector,char description[])
{

    for(int i=0; i<lenSec; i++)
    {
        if(sectors[i].id == idSector)
        {
            strcpy(description,sectors[i].descripcion);
            break;
        }
    }
}

void showEmployee(Employee list,Sector sectors[],int lenSec)
{
    char description[20];

    LoadDescrip(sectors,lenSec,list.sector,description);

    printf("%d   %10s   %10s    %.2f   %10s\n",list.id,list.name,list.lastName,list.salary,description);
}

void showEmployees(Employee list[],int len,Sector sectors[],int lenSec)
{
    printf("ID     Nombre     Apellido     Salario     Sector\n");
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==OCUP)
        {
            showEmployee(list[i],sectors,lenSec);
        }
    }
}

int findEmployeeById(Employee* list, int len,int id)
{
    int ret=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].id==id && list[i].isEmpty==OCUP)
        {
            ret=i;
        }
    }
    return ret;
}



void addEmployee(Employee* list, int len,Sector* sectors,int lenSec)
{
    int flag=1;

    system("cls");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==FREE)
        {
            flag=0;
            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(list[i].name);
            printf("\nIngrese Apellido: ");
            fflush(stdin);
            gets(list[i].lastName);
            printf("\nIngrese Salario: ");
            scanf("%f",&list[i].salary);

            list[i].sector=showSectors(sectors,lenSec);
            list[i].isEmpty=OCUP;

            printf("\n\nDatos Ingresado Con Exito\n");
            system("pause");

            break;
        }
    }


    if(flag==1)
    {
        printf("\n\nNo hay mas lugar.\n");
        system("pause");
    }
}


void modifyEmployee(Employee list[],int len,Sector sector[],int lenSec)
{
    int opc,opc2,idSearched;

    system("cls");
    showEmployees(list,len,sector,lenSec);
    printf("\n\nSeleccione el ID del usuario a modificar: ");
    scanf("%d",&opc);

    idSearched=findEmployeeById(list,len,opc);
    if(idSearched==-1)
    {
        printf("\n\nEl ID ingresado no existe.\n");
        system("pause");
    }
    else
    {

        system("cls");
        printf("\nID encontrado. Seleccione que desea Modificar: \n\n");
        printf("  1- Nombre\n");
        printf("  2- Apellido\n");
        printf("  3- Salario\n");
        printf("  4- Sector\n");
        printf("  5- Cancelar\n");
        scanf("%d",&opc2);
        switch(opc2)
        {
        case 1:
            printf("Ingrese nuevo Nombre: ");
            fflush(stdin);
            gets(list[idSearched].name);
            break;
        case 2:
            printf("Ingrese nuevo Apellido: ");
            fflush(stdin);
            gets(list[idSearched].lastName);
            break;
        case 3:
            printf("Ingrese nuevo Salario: ");
            scanf("%f",&list[idSearched].salary);
            break;
        case 4:
            showEmployees(list,len,sector,lenSec);
            printf("Seleccione nuevo Sector: ");
            scanf("%d",&list[idSearched].sector);
            break;
        default:
            break;

        }

    }


}


int removeEmployee(Employee* list, int len,Sector sector[],int lenSec)
{
    int opc,idSearched;
    char opc2;

    system("cls");
    showEmployees(list,len,sector,lenSec);
    printf("\n\nSeleccione el ID del usuario que Desea Borrar: ");
    scanf("%d",&opc);

    idSearched = findEmployeeById(list,len,opc);

    if(idSearched==-1)
    {
        printf("\n\nId No Encontrado.\nOperacion Cancelada.\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("Usuario Encontrado: \n");
        showEmployee(list[idSearched],sector,lenSec);
        printf("\nDesea Darlo de baja? ('s' o 'n')");
        fflush(stdin);
        scanf("%c",&opc2);
        if(opc2=='s' || opc2== 'S')
        {
            system("cls");
            list[idSearched].isEmpty=FREE;
            printf("\nUsuario Dado de Baja.\n");
            system("pause");
        }
        else
        {
            system("cls");
            printf("\nOperacion Cancelada.\n");
            system("pause");
        }
    }

    return 0;
}

void reports(Employee list[],int len,Sector sectors[],int lenSec)
{
    int opc;
    system("cls");
    printf("INFORMAR: \n");
    printf("\n 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n");
    printf(" 2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio. \n\n Seleccione Opcion:  ");
    scanf("%d",&opc);
    switch(opc)
    {
    case 1:
        sortEmployees(list,len,sectors,lenSec);
        break;
    case 2:
        averageSalary(list,len,sectors,lenSec);
        break;
    default:
        break;
    }
}

void sortEmployees(Employee list[],int len,Sector sectors[],int lenSec)
{

    Employee EmployeeAux;
    char descriptionOne[20],descriptionTwo[20];

    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(strcmp(list[i].lastName,list[j].lastName)>0)
            {
                EmployeeAux=list[i];
                list[i]=list[j];
                list[j]=EmployeeAux;
                LoadDescrip(sectors,lenSec,list[i].sector,descriptionOne);
                LoadDescrip(sectors,lenSec,list[j].sector,descriptionTwo);
            }
            else if(strcmp(list[i].lastName,list[j].lastName)==0 && strcmp(descriptionOne,descriptionTwo)>0)
            {
                EmployeeAux=list[i];
                list[i]=list[j];
                list[j]=EmployeeAux;
            }
        }
    }
    system("cls");
    showEmployees(list,len,sectors,lenSec);
    system("pause");


}

void averageSalary(Employee list[],int len,Sector sectors[],int lenSec)
{
    int flag=1;
    int contador=0;
    float salaries=0.00;
    float average;

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==OCUP)
        {
            salaries=salaries+list[i].salary;
            contador++;
        }
    }

    average=salaries/contador;

    system("cls");

    printf("Salario Total: %.2f\n",salaries);
    printf("Promedio: %.2f\n",average);

    printf("\nUsuarios con mayor sueldo que el Promedio: %.2f\n\n");

    for(int j=0;j<len;j++)
    {
        if(list[j].salary>average && list[j].isEmpty==OCUP)
        {
            showEmployee(list[j],sectors,lenSec);
            flag=0;
        }
    }
    if(flag==1)
    {

        printf("\nNo se encontraron Usuarios con el Sueldo Mayor que el Promedio.\n");

    }
    system("pause");
}


