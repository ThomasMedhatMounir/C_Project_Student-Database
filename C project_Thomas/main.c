 /******************************************************************************
 * File Name: C project_Thomas
 *
 * Description: Simple student database
 *
 * Author: Thomas Medhat Mounir Botros
 ******************************************************************************/
/*  to include all the functions and library
in functions*/
#include "Functions.h"


/*to use it here without error  */
extern studentDp students_info[maximum_size];

int main()
{
    /*n is for switch case where user enter it
     to choose what he want to do  */
    /*Answer is were the response
    of the function will be stored*/
    u8 n = 0 , Answer = 0 ;
    /*id is where the user enter the id of the
    student
    year is the year of study
    NOTICE id and Year Can NOT be zero for entrance
    data
    Also i put them in u32 as when i use scanf for
    two u8 or u16 the compiler sets the first to zero*/
    u32 id = 0 , year = 0 ;
    /*subjects is an array to every subject the
    student takes and we will pass it using it is
    address later as well as grades
    same for them as id and year thats why they are 32
     */
    u32 subjects[Number_of_courses], grades[Number_of_grades];
    /*get list parameters */
    u8 count , list ;
    /*some printf for gui sake */
    printf("Welcome to Our Program\n\n");
    printf("Choose form the following using index\n\n");
    printf("1- check for Full\n2- Get used size\n3- Add Entry\n4- Delete Entry\n5- Read Entry\n6- Get Id list\n7- check if id exists\n8- Exit\n");
    /*read the choice of the user and store it in n*/
    printf("\nEnter your choice : ");
    scanf("%u",&n);
    printf("\n");
    /*to make the code goes multiple of times
    and only the user can stop it by entering
    the value of Exit
    Note all of Exits and check for full have
    macros in Function.h*/
    while (n != Exit)
    {
        /*start to choose what to do
        using switch case*/
        switch (n)
        {
        case check_for_Full :  // 1
            /*SDB_isFull() will be called
            and if all data are full
            it will return 1 if not it
            will return 0 */
            Answer = SDB_isFull();
            /*print it to user*/
            printf("\nAnswer = %u\n\n",Answer);
            break; //to get out of switch case
        case Get_used_size:  // 2
            /*SDB_GetUsedSize() and it will
            return number of students data
            we have*/
            Answer = SDB_GetUsedSize();
            /*print it for the user*/
            printf("\nAnswer = %u\n\n",Answer);
            break;// get out of switch
        case Add_Entry : // 3
            /*first we check if the data is full*/
            if (!SDB_isFull())
            {
                /*if not we take the data from
                the user */
                printf("\nEnter ID : ");
                scanf("%u",&id);
                printf("Enter year : ");
                scanf("%u",&year);
                printf("Enter subject 1 : ");
                scanf("%u",&subjects[0]);
                printf("Enter subject 1 grade : ");
                scanf("%u",&grades[0]);
                /*grades must be <= 100 if the user
                enter a larger number we keep him
                in loop till he enters the right one*/
                while (grades[0]<0||grades[0]>100)
                {
                    printf("Wrong value please Enter subject 1 grade : ");
                    scanf("%u",&grades[0]);
                }
                printf("Enter subject 2 : ");
                scanf("%u",&subjects[1]);
                printf("Enter subject 2 grade : ");
                scanf("%u",&grades[1]);
                while (grades[1]<0||grades[1]>100)
                {
                    printf("Wrong value please Enter subject 2 grade : ");
                    scanf("%u",&grades[1]);
                }
                printf("Enter subject 3 : ");
                scanf("%u",&subjects[2]);
                printf("Enter subject 3 grade : ");
                scanf("%u",&grades[2]);
                while (grades[2]<0||grades[2]>100)
                {
                    printf("Wrong value please Enter subject 3 grade : ");
                    scanf("%u",&grades[2]);
                }
                Answer = SDB_AddEntry( id , year , subjects , grades);
                printf("Answer = %u\n",Answer);
            }
            else
            {
                /*if it was full the we do not allow
                him to enter more*/

                printf("You have reatched you limit of %u\n",maximum_size);
            }
            break;
        case Delete_Entry :  // 4
            /*we ask the user to enter the id
            of the student the user wants to delete
            then we call SDB_DeleteEntry(id) and
            delete it */
            printf("\nEnter ID : ");
            scanf("%u",&id);
            SDB_DeleteEntry(id);
            break;
        case Read_Entry : // 5
            /*we ask the user to enter the id
            of the student the user want to read
            his/her data then we print the data*/
            printf("\nEnter ID : ");
            scanf("%u",&id);
            Answer = SDB_ReadEntry(id , &year , subjects , grades);
            if (year != 0)
            {
                printf("\nID  : %u\n",id);
                printf("year  : %u\n",year);
                printf("subject 1 : %u\n",subjects[0]);
                printf("grade 1 : %u\n",grades[0]);
                printf("subject 2 : %u\n",subjects[1]);
                printf("grade 2 : %u\n",grades[1]);
                printf("subject 3 : %u\n",subjects[2]);
                printf("grade 3 : %u\n",grades[2]);
            }
            else{}
            printf("Answer = %u\n",Answer);
            break;
        case Get_Id_list :  // 6
            /*first we put the value
            of the used data in count
            then we call SDB_GetidList
            and prints all the ids of the the
            students in our data*/
            count = SDB_GetUsedSize();
            SDB_GetidList(&count ,&list);
            break;
        case check_if_id_exists :  // 7
            /*we ask the user to enter
            an id to check if it exist or not*/
            printf("Enter ID : ");
            scanf("%u",&id);
            Answer = SDB_IsIdExists (id);
            printf("Answer = %u\n",Answer);
            break;
        default :
            /*if the user enters any value other
            than form 1 to 8 we print it is
            wrong entry*/
            printf("Wrong Entry\n");
            break;
        }
        /*we remember the user that if he wants to
        Exit he/she can write 8 */
        printf("\n\nIf you want to exit enter n = 8\n");
        printf("\nEnter your choice : ");
        scanf("%u",&n);

    }
    return 0;
}
