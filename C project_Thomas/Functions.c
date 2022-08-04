/*  to include all the functions prototypes
 and libraries in functions*/

#include "Functions.h"

/*to use it here without error  */
extern  studentDp students_info[maximum_size];


/*------------------------------------------*/
/*since id can not be equal zero
then when students_info[9].id and Year
 has a value then the database is full */
bool SDB_isFull(void) // done
{
    if (students_info[maximum_size-1].student_id != 0 &&students_info[maximum_size-1].student_year != 0)
    {
        return 1 ;
    }
    else
    {
        return 0 ;
    }
}
/*------------------------------------------*/
/*we counts the data and we stop when
we find id = 0 or year*/
u8 SDB_GetUsedSize(void)
{
    u8 count = 0 ;
    for (int i = 0 ; i < maximum_size ;i++)
    {
        if (students_info[i].student_id == 0 || students_info[i].student_year == 0)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    return count;
}
/*------------------------------------------*/
/*first we find the size of data
to get the point where we will enter */
bool SDB_AddEntry(u8 id , u8 year, u8 *subjects , u8 *grades)
{
    u8 count = SDB_GetUsedSize();
    students_info[count].student_id = id ;
    students_info[count].student_year = year ;
    students_info[count].course_1 = *subjects;
    students_info[count].grade_1 = *grades;
    /*to go to the next address*/
    subjects++;
    grades++;
    subjects++;
    grades++;
    subjects++;
    grades++;
    subjects++;
    grades++;
    students_info[count].course_2 = *subjects;
    students_info[count].grade_2 = *grades;
    subjects++;
    grades++;
    subjects++;
    grades++;
    subjects++;
    grades++;
    subjects++;
    grades++;
    students_info[count].course_3 = *subjects;
    students_info[count].grade_3 = *grades;

    /*we check if the id at this count is
    zero then our entry failed if not
    then we did it*/


    if (students_info[count].student_id == 0)
    {
        return 0 ;
    }
    else
    {
        return 1;
    }
}

/*------------------------------------------*/
/*first we find the index of the id
want to be deleted then we change the index
of id to fill the gap if existed */
void SDB_DeleteEntry(u8 id)
{
    u8 count = 0 ;
    for (int i = 0 ; i < maximum_size ;i++)
    {
        if (students_info[i].student_id == id)
        {
            break;
        }
        else
        {
            count++;
        }

    }

    for (count ; count < maximum_size ; count++)
    {
        students_info[count].student_id = students_info[count+1].student_id;
        students_info[count].student_year = students_info[count+1].student_year;
        students_info[count].course_1 = students_info[count+1].course_1;
        students_info[count].grade_1 = students_info[count+1].grade_1;
        students_info[count].course_2 = students_info[count+1].course_2;
        students_info[count].grade_2 = students_info[count+1].grade_2;
        students_info[count].course_3 = students_info[count+1].course_3;
        students_info[count].grade_3 = students_info[count+1].grade_3;
    }

    students_info[count].student_year = 0;
    students_info[count].course_1 = 0;
    students_info[count].grade_1 = 0;
    students_info[count].course_2 = 0;
    students_info[count].grade_2 = 0;
    students_info[count].course_3 = 0;
    students_info[count].grade_3 = 0;

}
/*------------------------------------------*/
/*from the id we get the index then print
the data*/
bool SDB_ReadEntry(u8 id , u8* year , u8 *subjects , u8* grades  )
{
     u8 count = 0 ;

    for (int i = 0 ; i < maximum_size ;i++)
    {
        if (students_info[i].student_id == id)
        {
            break;
        }
        else
        {
            count++;
        }

    }

    if (students_info[count].student_id == id &&students_info[count].student_year != 0)
    {
        *year = students_info[count].student_year;
        *subjects = students_info[count].course_1;
        *grades = students_info[count].grade_1;
        subjects++;
        grades++;
        subjects++;
        grades++;
        subjects++;
        grades++;
        subjects++;
        grades++;
        *subjects = students_info[count].course_2;
        *grades = students_info[count].grade_2;
        subjects++;
        grades++;
        subjects++;
        grades++;
        subjects++;
        grades++;
        subjects++;
        grades++;
        *subjects = students_info[count].course_3;
        *grades = students_info[count].grade_3;
        return 1 ;
    }
    else
    {
        *year = 0;
        return 0 ;
    }
}
/*------------------------------------------*/
/*from count we find out the number of data
we have then we print the existing id*/
void SDB_GetidList(u8* count ,u8* list )
{
    for (int i = 0 ; i < *count ; i++)
    {
        if (students_info[i].student_id == 0 && students_info[i].student_year == 0 )
        {
            continue;
        }
        else
        {
            *list = students_info[i].student_id;
            printf("%u - %u\n",i+1,*list);
        }
    }
}
/*------------------------------------------*/
/*we check using id if the data existed or not*/
bool SDB_IsIdExists (u8 id)
{
    u8 exist = 0 ;
    for (int i = 0 ; i < maximum_size ; i++)
    {
        if (students_info[i].student_id == id && students_info[i].student_year != 0 )
        {
            exist++;
            break;
        }
        else
        {

        }
    }
    if (exist == 0)
    {
        return 0;
    }
    else
    {
        return 1 ;
    }
}

