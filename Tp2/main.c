#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define CANT 1000
#define CANT_SEC 5

int main()
{

    char seguir = 's';
    int flag=1;
    Employee list[CANT];
    Sector sectors[] = {{1,"RRHH"},{2,"Ventas"},{3,"Compras"},{4,"Contable"},{5,"Sistemas"}};

    initEmployees(list,CANT);

    do
    {
        switch(menu())
        {

        case 1:
            flag=0;
            addEmployee(list,CANT,sectors,CANT_SEC);
            break;
        case 2:
            if(flag==0)
            {
                modifyEmployee(list,CANT,sectors,CANT_SEC);
            }
            else
            {
                printf("\nNo se Agrego Ningun Usuario.\nAgregue un Usuario para Continuar. \n");
                system("pause");
            }
            break;
        case 3:
            if(flag==0)
            {
                removeEmployee(list,CANT,sectors,CANT_SEC);
            }
            else
            {
                printf("\nNo se Agrego Ningun Usuario.\nAgregue un Usuario para Continuar. \n");
                system("pause");
            }
            break;
        case 4:
            if(flag==0)
            {
                reports(list,CANT,sectors,CANT_SEC);
            }
            else
            {
                printf("\nNo se Agrego Ningun Usuario.\nAgregue un Usuario para Continuar. \n");
                system("pause");
            }
            break;
        case 5:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');



    return 0;
}

