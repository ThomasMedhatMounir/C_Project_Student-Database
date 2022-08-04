#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
/*need libraries for the project
stdio.h for printf and scanf
stdbool.h for bool type*/
#include <stdio.h>
#include <stdbool.h>
/*to use our data */
#include "STD_TYPES.h"

/*some macros needed*/
#define maximum_size 10
#define check_for_Full 1
#define Get_used_size 2
#define Add_Entry 3
#define Delete_Entry 4
#define Read_Entry 5
#define Get_Id_list 6
#define check_if_id_exists 7
#define Exit 8
#define Number_of_courses 3
#define Number_of_grades 3



/*the Database we need*/
typedef struct
{
    u8 student_id ;
    u8 student_year;
    u8 course_1;
    u8 grade_1;
    u8 course_2;
    u8 grade_2;
    u8 course_3;
    u8 grade_3;
}studentDp;

/*make objects from the data base*/
studentDp students_info[maximum_size];


/*function prototypes*/
bool SDB_isFull(void);
u8 SDB_GetUsedSize(void);
bool SDB_AddEntry(u8 id , u8 year , u8 *subjects , u8 *grades);
void SDB_DeleteEntry(u8 id);
bool SDB_ReadEntry(u8 id , u8* year , u8 *subjects , u8* grades );
void SDB_GetidList(u8* count ,u8* list );
bool SDB_IsIdExists (u8 id);



#endif // FUNCTIONS_H_INCLUDED
