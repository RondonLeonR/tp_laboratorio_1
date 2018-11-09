#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee *this;
    this = employee_new();
    int r;
    char var1[30],var2[30],var3[30],var4[30];

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r == 4)
        {
            this =  employee_newParametros(var1,var2,var3,var4);
            ll_add(pArrayListEmployee,this);
        }

        if(feof(pFile) != 0)
        {
            printf("Se cargo todo el Archivo.\n\n");
            system("pause");
        }

    }
    while(!feof(pFile));

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee *this;

    int r;

    do
    {
        this = employee_new();
        r = fread(this,sizeof(Employee),1,pFile);
        if(r == 1)
        {
            ll_add(pArrayListEmployee,this);
        }

        if(feof(pFile) != 0)
        {
            printf("Se cargo todo el Archivo.\n\n");
            system("pause");
        }

    }
    while(!feof(pFile));
    return 1;
}
