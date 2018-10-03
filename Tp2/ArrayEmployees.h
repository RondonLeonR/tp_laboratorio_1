#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

typedef struct
{
    int id;
    char descripcion[20];
}Sector;


int initEmployees(Employee* list, int len);
void addEmployee(Employee* list, int len,Sector* sectors,int lenSec);
void modifyEmployee(Employee list[],int len,Sector sector[],int lenSec);
int removeEmployee(Employee* list, int len,Sector sector[],int lenSec);

int findEmployeeById(Employee* list, int len,int id);
void sortEmployees(Employee list[],int len,Sector sectors[],int lenSec);

void LoadDescrip(Sector sectors[],int lenSec,int idSector,char description[]);
int showSectors(Sector sectors[],int len);
void showEmployee(Employee list,Sector sectors[],int lenSec);
void showEmployees(Employee list[],int len,Sector sectors[],int lenSec);

int menu();


#endif // ARRAYEMPLOYEES_H_INCLUDED
