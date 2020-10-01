#define TAM 1000

typedef struct eEmployee
{
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
    int id;
}eEmployee;

eEmployee eEmployeeArray[TAM];

/** \brief Adds an employee to the eEmployeeArray struct
 *
 * \param eEmployee[]
 * \param int
 * \return eEmployee
 *
 */
eEmployee addEmployees(eEmployee[],int);
/** \brief Prints the employees stored in the eEmployee array
 *
 * \param eEmployee[]
 * \param int
 * \return void
 *
 */
void PrintEmployees(eEmployee[],int);
/** \brief Allows you to modify one element from an employee
 *
 * \param eEmployee[]
 * \return void
 *
 */
void ModifyEmployee(eEmployee[]);
/** \brief Orders the employees by their last name
 *
 * \param eEmployee[]
 * \param int
 * \return void
 *
 */
void OrderByName(eEmployee[],int);
/** \brief Orders the employees by their sector
 *
 * \param [] eEmployee
 * \param int
 * \return void
 *
 */
void OrderBySector(eEmployee [],int);
/** \brief Initializes all employees with isEmpty 1 and with their ids on -1
 *
 * \param eEmployee[]
 * \param int
 * \return void
 *
 */
void InitEmployees(eEmployee[],int);
/** \brief Searchs for a free spot on the eEmployees array
 *
 * \param eEmployee[]
 * \param int
 * \return int
 *
 */
int SearchForFree(eEmployee[],int);
/** \brief Allows you to remove an employee from the struct
 *
 * \param eEmployee[]
 * \return void
 *
 */
void RemoveEmployee(eEmployee[]);

/** \brief The menu that the user sees when he executes the program
 *
 * \param eEmployee[]
 * \return void
 *
 */
void Menu(eEmployee[]);

/** \brief Finds an employee by searching his ID
 *
 * \param eEmployee[]
 * \param int
 * \return int
 *
 */
int findEmployeeById(eEmployee[],int);
