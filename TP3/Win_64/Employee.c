#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "parser.h"

Employee* employee_new()
{
    Employee *this;

    this =(Employee*)malloc(sizeof(Employee));

    if(this != NULL)
    {
        this->id=0;
        this->horasTrabajadas=0;
        this->sueldo=0;
        strcpy(this->nombre,"");
    }
    else
    {
        system("cls");
        printf("No se ha encontrado mas Lugar en Memoria.\n");
        exit(0);
    }

    return this;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    int id,hours;
    float salary;
    Employee *this;
    this = employee_new();

    if(this != NULL)
    {
        id = atoi(idStr);
        hours = atoi(horasTrabajadasStr);
        salary = atof(sueldo);

        employee_setId(this,id);
        employee_setNombre(this,nombreStr);
        employee_setHorasTrabajadas(this,hours);
        employee_setSueldo(this,salary);

    }

    return this;
}

int employee_setId(Employee* this,int id)
{
    int ret =0;
    if(id>0)
    {
        this->id = id;
        ret = 1;
    }
    return ret;
}

int employee_getId(Employee* this,int* id)
{
    *id = this->id;
    return 1;
}


int employee_setNombre(Employee* this,char* nombre)
{
    int ret = 0;
    if(nombre[0] != '\0')
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        ret = 1;
    }
    return ret;
}

int employee_getNombre(Employee* this,char* nombre)
{
    strcpy(nombre,this->nombre);
    return 1;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ret=0;
    if(horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        ret = 1;
    }
    return ret;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    *horasTrabajadas = this->horasTrabajadas;
    return 1;
}


int employee_setSueldo(Employee* this,float sueldo)
{
    int ret = 0;
    if(sueldo > 0)
    {
        this->sueldo = sueldo;
        ret = 1;
    }
    return ret;
}

int employee_getSueldo(Employee* this,float* sueldo)
{
    *sueldo = this->sueldo;
    return 1;
}

int sortById(void* pEmployee1,void* pEmployee2)
{
    int ret = 0;
    Employee *thisA;
    Employee *thisB;

    if(pEmployee1 != NULL && pEmployee2 != NULL )
    {
        thisA = pEmployee1;
        thisB = pEmployee2;
        if(thisA->id > thisB->id)
        {
            ret=1;
        }
    }
    return ret;
}

int sortByName(void* pEmployee1,void* pEmployee2)
{
    int ret = 0;
    Employee *thisA;
    Employee *thisB;

    if(pEmployee1 != NULL && pEmployee2 != NULL )
    {
        thisA = pEmployee1;
        thisB = pEmployee2;
        ret=strcmp(thisA->nombre, thisB->nombre);
    }
    return ret;
}

int sortByHours(void* pEmployee1,void* pEmployee2)
{
    int ret = 0;
    Employee *thisA;
    Employee *thisB;

    if(pEmployee1 != NULL && pEmployee2 != NULL )
    {
        thisA = pEmployee1;
        thisB = pEmployee2;
        if(thisA->horasTrabajadas > thisB->horasTrabajadas)
        {
            ret=1;
        }
    }
    return ret;
}

int sortBySalary(void* pEmployee1,void* pEmployee2)
{
    int ret = 0;
    Employee *thisA;
    Employee *thisB;

    if(pEmployee1 != NULL && pEmployee2 != NULL )
    {
        thisA = pEmployee1;
        thisB = pEmployee2;
        if(thisA->sueldo > thisB->sueldo)
        {
            ret=1;
        }
    }
    return ret;
}





