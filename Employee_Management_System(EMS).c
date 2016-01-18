/// List of library functions
#include<stdio.h> ///for input output functions like printf, scanf
#include<conio.h>
#include<stdlib.h>
#include<string.h> ///for windows related functions
#include<windows.h> ///string operations

/** List of Global Variable */
COORD coord = {0,0}; /// from top-left corner of window

/**
    function : gotoxy
    input: x and y coordinates
    output: moves the cursor in specified position of console
*/
void gotoxy(int x, int y)
{
    coord.X = x ; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

FILE *fp,*ft,*f_id; /// File pointer
int i=1,j=1,k=1,p=1;
int choice,search,update,zero=0;; /// integers to store choices, searches and update id of employees
char e_name[50]; /// string to store name of the employee
long double recsize; /// size of each record of employee

/** structure that represent a employee */
struct emp
{
    int id; /// Employee ID
    char name[50]; /// Name of Employee
    char email[34]; /// Email of Employee
    double c_no; /// Contact No. of Employee
    int d_join[3]; /// Joining Date
    double salary; /// Employee Salary
    char status[30]; /// Employee Position
}e_add[99];  /// structure variable creation

/// sizeo of each record i.e. size of structure variable e_view
long double recsize = sizeof(e_add[0]);

    /** open the file in binary read and write mode
    * if the file EMP.txt already exists then it open that file in read write mode
    * if the file doesn't exit it simply create a new copy
    */

int main()
{


    time_t t;
    fp = fopen("EMP.txt","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMP.txt","wb+");
        if(fp == NULL)
        {
            printf("Cannot open file");
            exit(1);
        }
    }

    f_id = fopen("e_id.txt","a+");
    if(f_id == NULL)
    {
        f_id = fopen("e_id.txt","w");
        if(f_id == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }

    system("cls");

    int d,p=0;
    char pass[10],ans;
    system("COLOR 5E");
    time(&t);
    gotoxy(59,2);
    printf("Date :: %0.10s",ctime(&t));
    gotoxy(26,8);
    printf("******************************\n");
    gotoxy(28,10);
    printf("Employee Management System");
    gotoxy(26,12);
    printf("******************************\n\n\n\n\n\n");
    gotoxy(49,28);
    printf("Press any Key to Continue...");
    getchar();
    system("cls");
    system("COLOR 3A");
    gotoxy(45,12);
    printf(" Enter your ID :: ");
    scanf("%d",&d);

    while(fread(&e_add[i],recsize,1,fp) == 1 || d == 99)
    {
        if(d == e_add[i].id)
        {
            //admin();
            emp();
        }
        else if(d == 99)
        {
            system("cls");

            gotoxy(45,12);
            printf(" Password :: ");
            fflush(stdin);
            gets(pass);
            if(strcmp(pass,"Password")== 0) /// Password to enter Admin Menu
            {
                system("cls");
                gotoxy(45,12);
                printf("Password Matched !!");
                gotoxy(45,14);
                printf("Loading your Console Window");
                for(i=0;i<=6;i++)
                {
                    fordelay(60000000);
                    printf(".");
                }
                system("cls");

                admin();
            }
            else
            {
                system("cls");

                gotoxy(45,12);
                printf(" Wrong Password");
                while(p==2)
                {
                    printf("\n\n TIME OUT \n\n");
                    system("cls");
                    system("COLOR 70");
                    gotoxy(30,10);
                    printf("Presented By KV IT Solutions\n");
                    gotoxy(30,12);
                    printf("Thanks for Visiting  !!!!!!!\n\n\n\n\n\n");
                    exit(0);
                }
                p++;
                printf("\n\n Attempt No. %d",p);
                printf("\n\n Would you like to Try again... ? ( Y/N ) :: ");
                ans = getche();
                if(ans=='y' || ans=='Y')
                {
                    continue;
                }
                else
                {
                    system("cls");
                    gotoxy(30,10);
                    printf("Presented By KV IT Solutions\n");
                    gotoxy(30,12);
                    printf("Thanks for Visiting  !!!!!!!\n\n\n\n\n\n");
                    exit(0);
                }
            }
        }
        else
        {
            i++;
            continue;
        }
    }

}

int emp()
{
    while(1)
    {
        system("cls");

        admin_box();
        gotoxy(48,8); /// move the cursor to postion 48, 8 from top-left corner
        printf("****>> Employee Menu <<****");
        gotoxy(53,10);
        printf("1. Present"); /// option for filling Present
        gotoxy(53,12);
        printf("2. List Records"); /// option for showing existing record
        gotoxy(53,14);
        printf("3. Modify Records"); /// option for editing record
        gotoxy(53,16);
        printf("4. Exit");
        gotoxy(53,20);  /// exit from the program
        printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
        fflush(stdin); /// flush the input buffer
        scanf("%d",&choice); /// get the input from keyboard

        printf("\n\n\n\n\n\n");

        switch(choice)
        {
        case 1:
            present();
            getch();
            break;
        case 2:
            view_record();

        case 3:
            update_record();

        case 4:
            {
                    system("cls");
                    gotoxy(30,10);
                    printf("Presented By KV IT Solutions\n");
                    gotoxy(30,12);
                    printf("Thanks for Visiting  !!!!!!!\n\n\n\n\n\n");
                    exit(0); /// exit from the program
            }


        }
    }
}

int admin()
{
    /// infinite loop continues untile the break statement encounter
    while(1)
    {
        system("cls");
        f_id=fopen("f_id.txt","a+");
        admin_box();

        gotoxy(48,8); /// move the cursor to postion 48, 8 from top-left corner
        printf("****>> Admin Menu <<****");
        gotoxy(53,10);
        printf("1. Add Record"); /// option for add record
        gotoxy(53,12);
        printf("2. List Records"); /// option for showing existing record
        gotoxy(53,14);
        printf("3. Modify Records"); /// option for editing record
        gotoxy(53,16);
        printf("4. Delete Records"); /// option for deleting record
        gotoxy(53,18);
        printf("5. Exit"); /// exit from the program
        gotoxy(53,20);
        printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
        fflush(stdin); /// flush the input buffer
        scanf("%d",&choice); /// get the input from keyboard
        printf("\n\n\n");

        switch(choice)
        {

        case 1:
            add_record();

        case 2:
            view_record();

        case 3:
            update_record();

        case 4:
            delete_record();

        case 5:
            {
                    system("cls");

                    gotoxy(30,10);
                    printf("Presented By KV IT Solutions\n");
                    gotoxy(30,12);
                    printf("Thanks for Visiting  !!!!!!!\n\n\n\n\n\n");
                    exit(0); /// exit from the program
            }


        }
    }
}

int add_record()
{

    char ans,ch,name[15];
    int c=0,n,j=0,w=0;

    system("cls");

    fseek(fp,0,SEEK_END); /// search the file and move cursor to end of the file
                            /// here 0 indicates moving 0 distance from the end of the file

    while((ch=getc(f_id))!=EOF)
    {
        c++;
    }
    i=(c/2);

    do
    {
        system("cls");

        printf("\n Employee No. :: %d",i);
        printf("\n Enter Full Name of the Employee :: ");
        fflush(stdin);
        gets(e_add[i].name);

        while(e_add[i].name[w]!=32) /// Gets First Name of Employee
        {
            w++;
        }

        printf("\n Enter %*.*s's Email :: ",w,w,e_add[i].name); /// %*.*s is printing First Name of Employee
        fflush(stdin);
        gets(e_add[i].email);

        again_contact:
        printf("\n Enter %*.*s's Contact No. :: ",w,w,e_add[i].name);
        scanf("%lf",&e_add[i].c_no);


        again_date:
        printf("\n Enter %*.*s's Joining Date : ",w,w,e_add[i].name);
        printf("\n Date  :: ");
        scanf("%d",&e_add[i].d_join[0]);
        if(e_add[i].d_join[0]>31)
        {
            printf("\n Invalid Date... Please write Valid Join Date\n");
            goto again_date;
        }

        printf(" Month :: ");
        scanf("%d",&e_add[i].d_join[1]);
        if(e_add[i].d_join[1]>12)
        {
            printf("\n Invalid Month... Please write Valid Join Month\n");
            goto again_date;
        }

        printf(" Year  :: ");
        scanf("%d",&e_add[i].d_join[2]);
        if(e_add[i].d_join[3]>2016)
        {
            printf("\n Invalid Year... Please write Valid Join Year\n");
            goto again_date;
        }

        printf("\n Enter %*.*s's Designation :: ",w,w,e_add[i].name);
        fflush(stdin);
        gets(e_add[i].status);
        printf("\n Enter %*.*'s Salary :: ",w,w,e_add[i].name);
        scanf("%lf",&e_add[i].salary);

        e_add[i].id=i;

        fwrite(&e_add[i],recsize,1,fp); /// write the record in the file

        if(i>=10)
        {
            fprintf(f_id,"%d",i); /// Writing ID into another File, so it can be retrieved
        }

        else
        {
            fprintf(f_id,"%d%d",zero,i);
        }

        e_add[i].id++;
        i++;

        printf("\n\n Record added Successfully ...");

        printf("\n\n Do you want Add another Record ? ( Y/N ) :: ");
        scanf(" %c",&ans);
    }while(ans=='y' || ans=='Y');

    if(ans!='y' || ans!='Y')
    {
        admin();
    }
}

int view_record()
{
    int view_id;
    long double view_int;
    char ans,view_name[32],view_char[32];
    i=1;
    system("cls");

    rewind(fp); ///this moves file cursor to start of the file

    printf("\n View Record :::::::::::: ");
    printf("\n\n How do you like to Search the Database ?");
    printf("\n 1.By ID \n 2.By Name \n 3.By Email \n\n Choice :: ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        {
            printf("\n\n Enter Employee ID :: ");
            scanf("%d",&view_id);
            break;
        }
    case 2:
        {
            printf("\n\n Enter Employee Name :: ");
            fflush(stdin);
            gets(view_name);
            break;
        }
    case 3:
        {
            printf("\n\n Enter Employee Email :: ");
            fflush(stdin);
            gets(view_char);
            break;
        }

    default:
        {
            printf("\n\n Wrong Input \n\n");
            view_record();
        }
    }

    while(fread(&e_add[i],recsize,1,fp)==1) /// read the file and fetch the record one record per fetch
    {
        switch(choice)
        {
            case 1:
                {
                    if(view_id==e_add[i].id)
                    {
                        printf("\n\n Record Found ...... ");

                        printf("\n ID          :: %d \n Name        :: %s \n Email       :: %s \n Mobile      :: %10.0lf \n Join Date   :: %d/%d/%d \n Designation :: %s \n Salary      :: %lf \n\n",e_add[i].id,e_add[i].name,e_add[i].email,e_add[i].c_no,e_add[i].d_join[0],e_add[i].d_join[1],e_add[i].d_join[2],e_add[i].status,e_add[i].salary); /// print the name, email, contact no, Joining Date, Designation and Salary.

                        printf("\n\n Do you want to View another Record ? ( Y/N ) :: ");
                        scanf(" %c",&ans);

                        if(ans=='y' || ans=='Y')
                        {
                            view_record();
                        }
                        else
                        {
                            main();
                        }
                    }
                    else
                    {
                        i++;
                        continue;
                    }
                }
            case 2:
                {
                    if(strcmp(view_name,e_add[i].name)==0)
                    {

                        printf("\n ID          :: %d \n Name        :: %s \n Email       :: %s \n Mobile      :: %10.0lf \n Join Date   :: %d/%d/%d \n Designation :: %s \n Salary      :: %lf \n\n",e_add[i].id,e_add[i].name,e_add[i].email,e_add[i].c_no,e_add[i].d_join[0],e_add[i].d_join[1],e_add[i].d_join[2],e_add[i].status,e_add[i].salary); /// print the name, email, contact no, Joining Date, Designation and Salary.

                        printf("\n\n Do you want to View another Record ? ( Y/N ) :: ");
                        scanf(" %c",&ans);

                        if(ans=='y' || ans=='Y')
                        {
                            view_record();
                        }
                        else
                        {
                            main();
                        }
                    }
                    else
                    {
                        i++;
                        continue;
                    }
                }
            case 3:
                {
                    if(strcmp(view_char,e_add[i].email)==0)
                    {

                        printf("\n ID          :: %d \n Name        :: %s \n Email       :: %s \n Mobile      :: %10.0lf \n Join Date   :: %d/%d/%d \n Designation :: %s \n Salary      :: %lf \n\n",e_add[i].id,e_add[i].name,e_add[i].email,e_add[i].c_no,e_add[i].d_join[0],e_add[i].d_join[1],e_add[i].d_join[2],e_add[i].status,e_add[i].salary); /// print the name, email, contact no, Joining Date, Designation and Salary.

                        printf("\n\n Do you want to View another Record ? ( Y/N ) :: ");
                        scanf(" %c",&ans);

                        if(ans=='y' || ans=='Y')
                        {
                            view_record();
                        }
                        else
                        {
                            main();
                        }
                    }
                    else
                    {
                        i++;
                        continue;
                    }
                }
            case 4:
                {
                    if(view_int==e_add[i].c_no)
                    {
                        printf("\n ID          :: %d \n Name        :: %s \n Email       :: %s \n Mobile      :: %10.0lf \n Join Date   :: %d/%d/%d \n Designation :: %s \n Salary     :: %lf \n\n",e_add[i].id,e_add[i].name,e_add[i].email,e_add[i].c_no,e_add[i].d_join[0],e_add[i].d_join[1],e_add[i].d_join[2],e_add[i].status,e_add[i].salary); /// print the name, email, contact no, Joining Date, Designation and Salary.

                        printf("\n\n Do you want to View another Record ? ( Y/N ) :: ");
                        scanf(" %c",&ans);

                        if(ans=='y' || ans=='Y')
                        {
                            view_record();
                        }
                        else
                        {
                            main();
                        }
                    }
                    else
                    {
                        i++;
                        continue;
                    }
                }
        }
    }
}

int update_record()  /// if user press 3 then do editing existing record
{
    system("cls");

    int view_id,mod;
    long double view_int;
    char ans,view_name[32],view_char[32];
    i=1,j=0;
    system("cls");

    rewind(fp); ///this moves file cursor to start of the file

    printf("\n Update Record :::::::::::: ");
    printf("\n\n How do you like to Search the Database ?");
    printf("\n 1.By ID \n 2.By Name \n 3.By Email \n\n Choice :: ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 0:
        {
            present();
            break;
        }
    case 1:
        {
            printf("\n\n Enter Employee ID :: ");
            scanf("%d",&view_id);
            break;
        }
    case 2:
        {
            printf("\n\n Enter Employee Name :: ");
            fflush(stdin);
            gets(view_name);
            break;
        }
    case 3:
        {
            printf("\n\n Enter Employee Email :: ");
            fflush(stdin);
            gets(view_char);
            break;
        }
    default:
        {
            printf("\n\n Wrong Input \n\n");
            update_record();
        }
    }

    while(fread(&e_add[i],recsize,1,fp)==1) /// read the file and fetch the record one record per fetch
    {
        switch(choice)
        {
            case 1:
                {
                    if(view_id==e_add[i].id)
                    {
                        printf("\n ID          :: %d \n Name        :: %s \n Email       :: %s \n Mobile      :: %10.0lf \n Join Date   :: %d/%d/%d \n Designation :: %s \n Salary     :: %lf \n\n",e_add[i].id,e_add[i].name,e_add[i].email,e_add[i].c_no,e_add[i].d_join[0],e_add[i].d_join[1],e_add[i].d_join[2],e_add[i].status,e_add[i].salary); /// print the name, email, contact no, Joining Date, Designation and Salary.

                        printf("\n\n What do you want to Modify ? ");
                        printf("\n 1.Name \n 2.Email \n 3.Mobile No. \n 4.Everything \n\n Choice :: ");
                        scanf("%d",&mod);

                        if(mod==1)
                        {
                            printf("\n Enter new Name :: ");
                            fflush(stdin);
                            gets(e_add[i].name);
                            fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                            fwrite(&e_add[i],recsize,1,fp); /// override the record

                            printf("\n ID          :: %d \n Name        :: %s \n Email       :: %s \n Mobile      :: %10.0lf \n Join Date   :: %d/%d/%d \n Designation :: %s \n Salary     :: %lf \n\n",e_add[i].id,e_add[i].name,e_add[i].email,e_add[i].c_no,e_add[i].d_join[0],e_add[i].d_join[1],e_add[i].d_join[2],e_add[i].status,e_add[i].salary); /// print the name, email, contact no, Joining Date, Designation and Salary.
                        }
                        else if(mod==2)
                        {
                            printf("\n Enter new Email :: ");
                            fflush(stdin);
                            gets(e_add[i].email);
                            fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                            fwrite(&e_add[i],recsize,1,fp); /// override the record

                            printf("\n ID          :: %d \n Name        :: %s \n Email       :: %s \n Mobile      :: %10.0lf \n Join Date   :: %d/%d/%d \n Designation :: %s \n Salary     :: %lf \n\n",e_add[i].id,e_add[i].name,e_add[i].email,e_add[i].c_no,e_add[i].d_join[0],e_add[i].d_join[1],e_add[i].d_join[2],e_add[i].status,e_add[i].salary); /// print the name, email, contact no, Joining Date, Designation and Salary.
                        }
                        else if(mod==3)
                        {
                            printf("\n Enter new Mobile No. :: ");
                            fflush(stdin);
                            scanf("%lf",&e_add[i].c_no);
                            fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                            fwrite(&e_add[i],recsize,1,fp); /// override the record

                            printf("\n ID          :: %d \n Name        :: %s \n Email       :: %s \n Mobile      :: %10.0lf \n Join Date   :: %d/%d/%d \n Designation :: %s \n Salary     :: %lf \n\n",e_add[i].id,e_add[i].name,e_add[i].email,e_add[i].c_no,e_add[i].d_join[0],e_add[i].d_join[1],e_add[i].d_join[2],e_add[i].status,e_add[i].salary); /// print the name, email, contact no, Joining Date, Designation and Salary.
                        }
                        else if(mod==4)
                        {
                            printf("\n Enter New Name :: ");
                            fflush(stdin);
                            gets(e_add[i].name);
                            printf("\n Enter new Email :: ");
                            fflush(stdin);
                            gets(e_add[i].email);
                            printf("\n Enter New mobile No. :: ");
                            scanf("%lf",&e_add[i].c_no);

                            fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                            fwrite(&e_add[i],recsize,1,fp); /// override the record

                            printf("\n ID          :: %d \n Name        :: %s \n Email       :: %s \n Mobile      :: %10.0lf \n Join Date   :: %d/%d/%d \n Designation :: %s \n Salary     :: %lf \n\n",e_add[i].id,e_add[i].name,e_add[i].email,e_add[i].c_no,e_add[i].d_join[0],e_add[i].d_join[1],e_add[i].d_join[2],e_add[i].status,e_add[i].salary); /// print the name, email, contact no, Joining Date, Designation and Salary.
                        }

                        printf("\n\n Do you want to Modify another Record ? ( Y/N ) :: ");
                        scanf(" %c",&ans);

                        if(ans=='y' || ans=='Y')
                        {
                            update_record();
                        }
                        else
                        {
                            main();
                        }
                    }
                    else
                    {
                        i++;
                        continue;
                    }
                }
            case 2:
                {
                    if(strcmp(view_name,e_add[i].name)==0)
                    {

                        printf("\n ID          :: %d \n Name        :: %s \n Email       :: %s \n Mobile      :: %10.0lf \n Join Date   :: %d/%d/%d \n Designation :: %s \n Salary     :: %lf \n\n",e_add[i].id,e_add[i].name,e_add[i].email,e_add[i].c_no,e_add[i].d_join[0],e_add[i].d_join[1],e_add[i].d_join[2],e_add[i].status,e_add[i].salary); /// print the name, email, contact no, Joining Date, Designation and Salary.

                        printf("\n\n Do you want to View another Record ? ( Y/N ) :: ");
                        scanf(" %c",&ans);

                        if(ans=='y' || ans=='Y')
                        {
                            update_record();
                        }
                        else
                        {
                            main();
                        }
                    }
                    else
                    {
                        i++;
                        continue;
                    }
                }
            case 3:
                {
                    if(strcmp(view_char,e_add[i].email)==0)
                    {

                        printf("\n ID          :: %d \n Name        :: %s \n Email       :: %s \n Mobile      :: %10.0lf \n Join Date   :: %d/%d/%d \n Designation :: %s \n Salary     :: %lf \n\n",e_add[i].id,e_add[i].name,e_add[i].email,e_add[i].c_no,e_add[i].d_join[0],e_add[i].d_join[1],e_add[i].d_join[2],e_add[i].status,e_add[i].salary); /// print the name, email, contact no, Joining Date, Designation and Salary.

                        printf("\n\n Do you want to View another Record ? ( Y/N ) :: ");
                        scanf(" %c",&ans);

                        if(ans=='y' || ans=='Y')
                        {
                            update_record();
                        }
                        else
                        {
                            main();
                        }
                    }
                    else
                    {
                        i++;
                        continue;
                    }
                }
        }
    }
}

int delete_record()
{
    system("cls");

    int view_id,mod;
    long double view_int;
    char ans,view_name[32],view_char[32];

    printf("\n Delete Record :::::::::::: ");
    printf("\n\n How do you like to Search the Database ?");
    printf("\n 1.By ID \n 2.By Name \n 3.By Email \n\n Choice :: ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        {
            printf("\n\n Enter Employee ID :: ");
            scanf("%d",&view_id);
            break;
        }
    case 2:
        {
            printf("\n\n Enter Employee Name :: ");
            fflush(stdin);
            gets(view_name);
            break;
        }
    case 3:
        {
            printf("\n\n Enter Employee Email :: ");
            fflush(stdin);
            gets(view_char);
            break;
        }
    default:
        {
            printf("\n\n Wrong Input \n\n");
            delete_record();
        }
    }

    ft = fopen("Temp.txt","wb");  /// create a intermediate file for temporary storage
    rewind(fp); /// move record to starting of file

    while(fread(&e_add[i],recsize,1,fp) == 1) /// read all records from file
    {
        if(e_add[i].id==view_id != 0)
        {
            printf("\n\n ID :: %d",e_add[i].id);
            fwrite(&e_add[i],recsize,1,ft); /// move all records except the one that is to be deleted to temp file
            break;
        }
        else if(strcmp(e_add[i].name,view_name) != 0) /// if the entered record match
        {
            printf("\n\n NAME :: %s",e_add[i].name);
            fwrite(&e_add[i],recsize,1,ft); /// move all records except the one that is to be deleted to temp file
            break;
        }
        else if(strcmp(e_add[i].email,view_char) != 0)
        {
            printf("\n\n EMAIL :: %s",e_add[i].email);
            fwrite(&e_add[i],recsize,1,ft); /// move all records except the one that is to be deleted to temp file
            break;
        }
        else
        {
            i++;
            continue;
        }
    }

    fclose(fp);
    fclose(ft);

    remove("EMP.txt"); /// remove the orginal file
    rename("Temp.txt","EMP.txt"); /// rename the temp file to original file name
    fp = fopen("EMP.txt", "rb+");

    printf("\n\n Do you want Delete another record ? ( Y/N ) :: ");
    scanf(" %c",&ans);
    if(ans=='y' || ans=='Y')
    {
        delete_record();
    }
    else
    {
        main();
    }
}

int admin_box()
{
    gotoxy(43,8);printf("*");gotoxy(44,8);printf("*");gotoxy(45,8);printf("*");gotoxy(46,8);printf("*");gotoxy(47,8);printf("*");
        gotoxy(43,9);printf("*");
        gotoxy(43,10);printf("*");
        gotoxy(43,11);printf("*");
        gotoxy(43,12);printf("*");
        gotoxy(43,13);printf("*");
        gotoxy(43,14);printf("*");
        gotoxy(43,15);printf("*");
        gotoxy(43,16);printf("*");
        gotoxy(43,17);printf("*");
        gotoxy(43,18);printf("*");
        gotoxy(43,19);printf("*");
        gotoxy(43,20);printf("*");
        gotoxy(43,21);printf("*");
        gotoxy(43,22);printf("*");
        gotoxy(44,22);printf("*");gotoxy(45,22);printf("*");gotoxy(46,22);printf("*");gotoxy(47,22);printf("*");gotoxy(48,22);printf("*");
        gotoxy(49,22);printf("*");gotoxy(50,22);printf("*");gotoxy(51,22);printf("*");gotoxy(52,22);printf("*");gotoxy(53,22);printf("*");
        gotoxy(54,22);printf("*");gotoxy(55,22);printf("*");gotoxy(56,22);printf("*");gotoxy(57,22);printf("*");gotoxy(58,22);printf("*");
        gotoxy(59,22);printf("*");gotoxy(60,22);printf("*");gotoxy(61,22);printf("*");gotoxy(62,22);printf("*");gotoxy(63,22);printf("*");
        gotoxy(64,22);printf("*");gotoxy(65,22);printf("*");gotoxy(66,22);printf("*");gotoxy(67,22);printf("*");gotoxy(68,22);printf("*");
        gotoxy(69,22);printf("*");gotoxy(70,22);printf("*");gotoxy(71,22);printf("*");gotoxy(72,22);printf("*");gotoxy(73,22);printf("*");
        gotoxy(74,22);printf("*");gotoxy(75,22);printf("*");gotoxy(76,22);printf("*");
        gotoxy(76,8);printf("*");
        gotoxy(76,9);printf("*");
        gotoxy(76,10);printf("*");
        gotoxy(76,11);printf("*");
        gotoxy(76,12);printf("*");
        gotoxy(76,13);printf("*");
        gotoxy(76,14);printf("*");
        gotoxy(76,15);printf("*");
        gotoxy(76,16);printf("*");
        gotoxy(76,17);printf("*");
        gotoxy(76,18);printf("*");
        gotoxy(76,19);printf("*");
        gotoxy(76,20);printf("*");
        gotoxy(76,21);printf("*");
        gotoxy(76,22);printf("*");
        gotoxy(75,8);printf("*");gotoxy(74,8);printf("*");gotoxy(73,8);printf("*");gotoxy(72,8);printf("*");
}

int fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

struct present
{
    int count;
    int ab;
    char e_id;
}emp1,emp2;

FILE *fn,*fpre;

int present()
{

    fn = fopen("present.txt","r+");
    if(fn == NULL)
    {
        fn = fopen("present.txt","w");
        fclose(fn);
    }

    system("cls");

    char ch;
    int c;

    emp1.count=0;
    emp1.ab=31;

    fn=fopen("present.txt","a+");
    gotoxy(45,12);
    printf("Employee No :: ");
    scanf(" %c",&emp1.e_id);
    fprintf(fn,"%c",emp1.e_id);
    fclose(fn);

    fpre=fopen("present.txt","r");

    while((ch=getc(fpre))!=EOF)
    {

        if(ch==emp1.e_id)
        {
            emp1.count++;
            emp1.ab--;
        }
    }

        gotoxy(45,14);
        printf("Present :: %d",emp1.count);
        gotoxy(45,16);
        printf("Absent :: %d",emp1.ab);
        getch();
        gotoxy(45,18);
        fclose(fpre);

    system("cls");
    main();
}

