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


/** \brief Inicializo el array de estructuras, poniendo los isEmpty en 1 y los ID segun su posicion en el array
 *
 * \param list Employee* Array a Inicializar
 * \param len int Tamanio del Array
 * \return int Devuelve 0
 *
 */
int initEmployees(Employee* list, int len);

/** \brief Agrego un Empleado
 *
 * \param list Employee* Estructura donde de guardara la informacion del empleado
 * \param len int Tamanio de la Array de la Estructura list
 * \param sectors Sector* Estructura de Sectores
 * \param lenSec int Tamanio de la Array de la Estructura Sectors
 * \return void
 *
 */
void addEmployee(Employee* list, int len,Sector* sectors,int lenSec);

/** \brief Modifico un Empleado
 *
 * \param list[] Employee Estructura donde se guarda la informacion del empleado
 * \param len int Tamanio de la Array de la Estructura list
 * \param sector[] Sector Estructura de Sectores
 * \param lenSec int Tamanio de la Array de la Estructura Sectors
 * \return void
 *
 */
void modifyEmployee(Employee list[],int len,Sector sector[],int lenSec);


/** \brief Doy de baja un Empleado
 *
 * \param list Employee* Estructura donde se guarda la informacion del empleado
 * \param len int Tamanio de la Array de la Estructura list
 * \param sector[] Sector Estructura de Sectores
 * \param lenSec int Tamanio de la Array de la Estructura Sectors
 * \return int
 *
 */
int removeEmployee(Employee* list, int len,Sector sector[],int lenSec);

/** \brief Busco un Empleado segun su ID
 *
 * \param list Employee* Estructura donde se guarda la informacion del empleado
 * \param len int Tamanio de la Array de la Estructura list
 * \param id int ID a buscar
 * \return int Devuelvo la pocision del array donde fue encontrado el Id
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Ordeno los empleados por apellido y sector
 *
 * \param list[] Employee Estructura donde se guarda la informacion del empleado
 * \param len int Tamanio de la Array de la Estructura list
 * \param sectors[] Sector Estructura de Sectores
 * \param lenSec int Tamanio de la Array de la Estructura Sectors
 * \return void
 *
 */
void sortEmployees(Employee list[],int len,Sector sectors[],int lenSec);

/** \brief Obtengo el Nombre del Sector
 *
 * \param sectors[] Sector Estructura de Sectores
 * \param lenSec int Tamanio de la Array de la Estructura Sectors
 * \param idSector int El id que corresponde al nombre del sector que deseo Obtener
 * \param description[] char Variable donde guardo el nombre del sector
 * \return void
 *
 */
void LoadDescrip(Sector sectors[],int lenSec,int idSector,char description[]);

/** \brief Muestro los sectores
 *
 * \param sectors[] Sector Estructura de Sectores
 * \param len int Tamanio de la Array de la Estructura Sectors
 * \return int
 *
 */
int showSectors(Sector sectors[],int len);

/** \brief Muestro SOLO un Empleado
 *
 * \param list Employee UNA estructura de Empleado
 * \param sectors[] Sector El array de Estructura
 * \param lenSec int Tamanio de la Array de la Estructura Sectors
 * \return void
 *
 */
void showEmployee(Employee list,Sector sectors[],int lenSec);

/** \brief Muestro TODOS los empleados ingresados
 *
 * \param list[] Employee El array de Estructuras de Empleados
 * \param len int tamanio del array de employee
 * \param sectors[] Sector array de estructuras sectors
 * \param lenSec int tamanio del array de sectors
 * \return void
 *
 */
void showEmployees(Employee list[],int len,Sector sectors[],int lenSec);

/** \brief Menu que muestro con la opciones del principio
 *
 * \return int Devuelvo la que eligio el Usuario
 *
 */
int menu();


#endif // ARRAYEMPLOYEES_H_INCLUDED
