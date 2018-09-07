#include <stdio.h>
#include <stdlib.h>
#include "FuncionesTP1.h"

int main()
{
    int opc,flag=0;
    float num1=0,num2=0,sum,rest,div,mult,factNum1,factNum2;
    do{
    system("cls");
    printf("\n\t*****MENU*****");
    printf("\n\n1.Ingresar 1er Operando(A=%.1f)",num1);
    printf("\n2.Ingresar 2do Operando(B=%.1f)",num2);
    printf("\n3.Calcular todas las Operaciones.");
    printf("\n\ta) Calcular la suma (A+B)");
    printf("\n\tb) Calcular la resta (A-B)");
    printf("\n\tc) Calcular la division (A/B)");
    printf("\n\td) Calcular la multiplicacion (A*B)");
    printf("\n\te) Calcular la factorial (A! y B!)");
    printf("\n4.Informar Resultados.");
    printf("\n5.Salir");

    printf("\n\n\tSeleccione Opcion: ");
    scanf("%d",&opc);
        switch(opc){
        case 1:
            fun_OpcOne(&num1);
            break;
        case 2:
            fun_OpcTwo(&num2);
            break;
        case 3:
            fun_OpcThree(&sum,&rest,&div,&mult,&factNum1,&factNum2,&flag,num1,num2);
            break;
        case 4:
            fun_OpcFour(sum,rest,div,mult,factNum1,factNum2,flag);
            break;
        case 5:
            break;
        default:
            printf("ERROR");




        }

    }while(opc!=5);


    return 0;
}

