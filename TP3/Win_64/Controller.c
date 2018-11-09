#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    pFile = fopen(path,"r");

    if(pFile == NULL)
    {
        system("cls");
        printf("\nEl Archivo %s \nNo existe O No se ha encontrado\n",path);
        return 1;
    }
    parser_EmployeeFromText(pFile,pArrayListEmployee);
    fclose(pFile);
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    pFile = fopen(path,"rb");

    if(pFile == NULL)
    {
        system("cls");
        printf("\nEl Archivo %s \nNo existe O No se ha encontrado\n",path);
        return 1;
    }
    parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    fclose(pFile);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee *this = employee_new();
    Employee *thisAux = employee_new();
    char name[50];
    int hours,r,id,idAux,tam,i;
    float salary;
    tam = ll_len(pArrayListEmployee);

    printf("Ingrese ID: \n");
    scanf("%d",&id);
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        thisAux = ll_get(pArrayListEmployee,i);
        if(thisAux!=NULL)
        {
            employee_getId(thisAux,&idAux);
            if(idAux == id)
            {
                system("cls");
                printf("El ID ingresado ya existe\n\n");
                system("pause");
                return 1;
            }
        }
    }
    printf("Ingrese Nombre: \n");
    gets(name);
    printf("Ingrese Horas Trabajadas: \n");
    scanf("%d",&hours);
    printf("Ingrese Salario: \n");
    scanf("%f",&salary);

    employee_setId(this,id);
    employee_setNombre(this,name);
    employee_setHorasTrabajadas(this,hours);
    employee_setSueldo(this,salary);

    r=ll_add(pArrayListEmployee,this);
    if(r == 0)
    {
        printf("\nSe agrego con Exito\n\n");
        system("pause");
    }
    else
    {
        printf("Hubo un error al guardar. \n\n");
        system("pause");
    }

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee *this = employee_new();
    Employee *thisAux = employee_new();
    int i,r,opc,idAux,id,horasAux,tam,flag = 0,flag2 = 0;
    char nombreAux[50];
    float sueldoAux;
    controller_ListEmployee(pArrayListEmployee);

    printf("\n\n\tIngrese ID del usuario a Modificar: ");
    scanf("%d",&r);
    tam = ll_len(pArrayListEmployee);
    for(i=0; i<tam; i++)
    {
        this = ll_get(pArrayListEmployee,i);
        if(this!=NULL)
        {
            employee_getId(this,&id);
            if(r == id)
            {
                printf("El ID ingresado fue encontrado\n");
                system("pause");
                flag2 = 1;
            }
        }
    }

    if(flag2 == 0)
    {
        printf("El id Ingresado no existe o no fue encontrado\n\n");
        system("pause");
        return 1;
    }

    system("cls");
    if(this != NULL && flag2 == 1)
    {
        printf("Empleado a Modificar: \n");
        printf("%4d %10s   %4d   %6.2f\n\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
        do
        {
            printf("MODIFICAR: \n");
            printf("1- ID\n");
            printf("2- Nombre\n");
            printf("3- Horas Trabajadas\n");
            printf("4- Sueldo\n");
            printf("5- Cancelar\n\n");
            printf("Seleccione opcion\n");
            scanf("%d",&opc);

            switch(opc)
            {
            case 1:
                printf("\n\nIngrese nuevo ID: ");
                scanf("%d",&idAux);
                for(i=0; i<tam; i++)
                {
                    thisAux = ll_get(pArrayListEmployee,i);
                    if(thisAux!=NULL)
                    {
                        employee_getId(thisAux,&id);
                        if(idAux == id)
                        {
                            system("cls");
                            printf("El ID ingresado ya existe\n");
                            printf("Operacion cancelada.\n\n");
                            system("pause");
                        }
                    }
                }
                employee_setId(this,idAux);
                printf("\nModificar Realizada\n");
                system("pause");
                flag=1;
                break;
            case 2:
                printf("\n\nIngrese nuevo Nombre: ");
                fflush(stdin);
                gets(nombreAux);
                employee_setNombre(this,nombreAux);
                printf("\nModificar Realizada\n");
                system("pause");
                flag=1;
                break;
            case 3:
                printf("\n\nIngrese nuevas Horas Trabajadas: ");
                scanf("%d",&horasAux);
                employee_setHorasTrabajadas(this,horasAux);
                printf("\nModificar Realizada\n");
                system("pause");
                flag=1;
                break;
            case 4:
                printf("\n\nIngrese nuevo Sueldo: ");
                scanf("%f",&sueldoAux);
                employee_setSueldo(this,sueldoAux);
                printf("\nModificar Realizada\n");
                system("pause");
                flag=1;
                break;
            case 5:
                system("cls");
                printf("\tOperacion Cancelada\n\n");
                system("pause");
                flag=1;
                break;
            }
        }
        while(flag == 0);
    }


    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee *this = employee_new();
    int r,tam,i,flag = 0,flag2=0;
    char opc;

    controller_ListEmployee(pArrayListEmployee);
    printf("\nIngrese el ID que desea Borrar: ");
    scanf("%d",&r);

    tam = ll_len(pArrayListEmployee);

    for(i=0; i<tam; i++)
    {
        if(i==r-1)
        {
            this = (Employee*)ll_get(pArrayListEmployee,i);
            flag2=1;
            break;
        }
    }

    if(flag2 == 0)
    {
        system("cls");
        printf("El id Ingresado no existe o no fue encontrado\n\n");
        system("pause");
    }
    system("cls");
    if(this != NULL && flag2 == 1)
    {
        printf("Empleado a Borrar: \n");
        printf("%4d %10s   %4d   %6.2f\n\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
        do
        {
            printf("Desea Borrarlo? s o n\n");
            fflush(stdin);
            scanf("%c",&opc);
            if(opc == 'S' || opc == 's')
            {
                ll_remove(pArrayListEmployee,i);
                printf("\nEmpleado Borrado\n\n");
                flag = 1;
                system("pause");
            }
            else if(opc == 'N' || opc == 'n')
            {
                printf("\nOperacion cancelada.\n\n");
                flag =1;
                break;
            }
        }
        while(flag != 1);
    }


    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* this;
    int i,tam,idAux,HorasAux;
    char nombreAux[50];
    float sueldoAux;

    tam = ll_len(pArrayListEmployee);

    printf("  ID     NAME     HOURS    SALARY\n");
    for(i=0; i<tam; i++)
    {
        this = (Employee*)ll_get(pArrayListEmployee,i);
        employee_getId(this,&idAux);
        employee_getNombre(this,nombreAux);
        employee_getHorasTrabajadas(this,&HorasAux);
        employee_getSueldo(this,&sueldoAux);

        printf("%4d %10s   %4d   %6.2f\n",idAux,nombreAux,HorasAux,sueldoAux);
    }
    if(tam == 0)
    {
        printf("No se cargaron archivos.\n\n");
    }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opc;
    printf("Ordenamiento por: \n\n");
    printf("1- Id\n");
    printf("2- Nombre\n");
    printf("3- Horas Trabajadas\n");
    printf("4- Sueldo\n\n");
    printf("Seleccione Opcion: ");
    scanf("%d",&opc);
    switch(opc)
    {
        case 1:
            printf("Ordenamiento por ID realizado.\n\n");
            ll_sort(pArrayListEmployee,sortById,1);
            system("pause");
            break;
        case 2:
            printf("Ordenamiento por Nombre realizado.\n\n");
            ll_sort(pArrayListEmployee,sortByName,1);
            system("pause");
            break;
        case 3:
            printf("Ordenamiento por Horas Trabajadas realizado.\n\n");
            ll_sort(pArrayListEmployee,sortByHours,1);
            system("pause");
            break;
        case 4:
            printf("Ordenamiento por Sueldo realizado.\n\n");
            ll_sort(pArrayListEmployee,sortBySalary,1);
            system("pause");
            break;
    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    Employee *this = employee_new();
    int tam,i,idAux,horasAux;
    float sueldoAux;
    char nombreAux[50];

    pFile = fopen(path,"w");
    tam = ll_len(pArrayListEmployee);
    system("cls");

    if(this == NULL || pFile == NULL)
    {
        printf("\nEl archivo no se encontro. \n\n");
        system("pause");
        return 1;
    }

    fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
    for(i=0; i<tam; i++)
    {
        this = (Employee*)ll_get(pArrayListEmployee,i);
        employee_getId(this,&idAux);
        employee_getNombre(this,nombreAux);
        employee_getHorasTrabajadas(this,&horasAux);
        employee_getSueldo(this,&sueldoAux);
        fflush(stdin);
        fprintf(pFile,"%d,%s,%d,%.2f\n",idAux,nombreAux,horasAux,sueldoAux);
    }

    fclose(pFile);
    printf("Informacion guardada en un archivo de texto\n\n");
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    Employee *this = employee_new();
    int tam,i,r;

    pFile = fopen(path,"wb");
    tam = ll_len(pArrayListEmployee);
    system("cls");

    if(this == NULL || pFile == NULL)
    {
        printf("\nEl archivo no se encontro. \n\n");
        system("pause");
        return 1;
    }

    rewind(pFile);
    for(i=0; i<tam; i++)
    {
        this = (Employee*)ll_get(pArrayListEmployee,i);
        r = fwrite(this,sizeof(Employee),1,pFile);
    }
    if(r == 1)
    {
        printf("Informacion guardada en un archivo binario\n\n");
        system("pause");
    }

    fclose(pFile);

    return 1;
}

