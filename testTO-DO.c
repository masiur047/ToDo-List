#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define ENTER 13
#define BKSP 8
#define SPACE 32
#define TAB 9


struct item
{
    char Title[40],Description[40],c;
    int Priority;
    int Id;
} st;

void wel_come(void);
void menu(void);
void add_item();
void delete_item(void);
void search_item();
void edit_item();
void read_item();
void search_priority();

void main(void)

{
    wel_come(); //call for welcome screen function
    menu();
    //login(); //call for login function
}


void wel_come(void)

{
    time_t t;
    time(&t);
    printf("                                                                                                         \n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t%s",ctime(&t));
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t==================================\t\t\t\t\t|\n");
    printf("|\t\t\t\t|\t     WELCOME TO \t |\t\t\t\t\t|\n");
    printf("|\t\t\t\t|\t     TO-DO LIST  \t |\t\t\t\t\t|\n");
    printf("|\t\t\t\t==================================\t\t\t\t\t|\n");
    //printf("|\t\t\t\t            Address      \t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|Press any key to continue.........\t\t\t\t\t\t\t\t\t|\n");

    printf("---------------------------------------------------------------------------------------------------------\n");

    getch();
    system("cls");
}


void menu(void)
{
    int choice;
    system("cls");
main:
    printf("\n======================== TO-DO LIST ========================");
    printf("                                                                                          ");
    printf("                                                                                          ");
    printf("\n\t\tPress <1> Add New To-Do");
    printf("\n\t\tPress <2> Display all To-Do");
    printf("\n\t\tPress <3> Delete a To-Do");
    printf("\n\t\tPress <4> Update a To-Do");
    printf("\n\t\tPress <5> Search a To-Do");
    printf("\n\t\tPress <6> Display all To-Do in a Priority");
    printf("\n\t\tPress <7> Exit!");

    printf("\n\n\t\tEnter your choice[1-7] : ");
    scanf("%d", &choice);

    system("cls");
    //add_item();

    switch(choice)
    {
    case 1:
        add_item();
        break;
    case 2:
        read_item();
        break;
    case 3:
        delete_item();
        break;
    case 4:
        edit_item();
        break;
    case 5:
        search_item();
        break;
    case 6:
        search_priority();
        break;

    case 7:
        printf("System Exit");
        exit(0);
        break;


    default:
        printf("Invalid Choice! System Exit\n");
        getch();

    }


}


void add_item()
{
    int index, valid;
    char c;
    int a=0;

    FILE *fp;


    system("cls");
    printf("============ Enter Details ============");
    int ID;//for comparing TO-DO ID if file is not NULL
    fp = fopen("To-Do.dat","a+");//opening file and creating a To-Do.dat file to append or write

    if(fp!=NULL)//if condition to check file is NULL or not
    {
        int size=1000;
        //printf("\nEnter  ID\t :");
        //scanf("%d",&ID);
        char test[size];
        int i=0,tId=0;
        while((fgets(test,size,fp))!=NULL)
        {
            if(i%4==0)
            {
                tId= atoi(test);
                /*
                fscanf reads every data stored in the file
                if entered TO-DO ID already exist then jumps to
                position I declared inside if(TO-DO!=NULL) at top
                */

            }
            i++;
        }
        st.Id = tId+1;
    }
    else//runs if TO-DO is empty
    {
        printf("NuLLLLLLLLLL\n");
        st.Id=1;
    }

    //add Title:
    fflush(stdin);
    printf("\nEnter Title\t :");
    gets(st.Title); // get input string
    st.Title[0]=toupper(st.Title[0]);



    //Description
    fflush(stdin);
    printf("\nEnter Description\t :");
    gets(st.Description); // get input string
    st.Description[0]=toupper(st.Description[0]);


    //Priority
    printf("\nEnter Priority:");
    scanf("%d",&st.Priority);



    //fp=fopen("To-DO.dat","a");
    for(int i=0; i<4; i++)
    {
        if(i==0)
        {
            fprintf(fp,"%d", st.Id);
        }
        else if(i==1)
        {
            fprintf(fp,"\n%s",st.Title);
        }
        else if(i==2)
        {
            fprintf(fp,"\n%s",st.Description);
        }
        else if(i==3)
        {
            fprintf(fp,"\n%d\n",st.Priority);
        }
    }

    fclose(fp);
    menu();
}


void delete_item(void)
{
    int target;
    int found=0,ck=0;
    FILE *sfile, *tfile;
    sfile=fopen("To-Do.dat","r+");
    tfile=fopen("TempFile.dat","w+");
    printf("\n Enter ID to Delete: ");
    fflush(stdin);
    scanf("%d",&target);
    int size=1000;
    char test[size];
    int i=0;
    while((fgets(test,size,sfile))!=NULL)
    {
        if(i%4==0)
        {
            st.Id=atoi(test);
        }
        else if(i%4==1)
        {
            strcpy(st.Title,test);
        }
        else if(i%4==2)
        {
            strcpy(st.Description,test);
        }
        else if(i%4==3)
        {
            st.Priority=atoi(test);
        }
        if(i%4==3)
        {
            if(target==st.Id)
            {
                found=1;
            }
            else
            {
                for(int i=0; i<4; i++)
                {
                    if(i==0)
                    {
                        fprintf(tfile,"%d", st.Id);
                    }
                    else if(i==1)
                    {
                        fprintf(tfile,"\n%s",st.Title);
                    }
                    else if(i==2)
                    {
                        fprintf(tfile,"%s",st.Description);
                    }
                    else if(i==3)
                    {
                        fprintf(tfile,"%d\n",st.Priority);
                    }
                }
            }

        }
        i++;

    }
    fclose(sfile);
    fclose(tfile);
    if(!found)
    {
        printf("\n Record not Found");
        getch();
        menu();
    }
    remove("To-Do.dat");
    if(rename("TempFile.dat","To-Do.dat")==0)
        printf("\n Record deleted");


    printf("\nPress any key to go to Main Menu!");
    getch();
    menu();
}

void edit_item()
{
    FILE *fp, *rp;
    int a=0;
    int target;
    char edit;
    fp=fopen("To-Do.dat","r");
    if(fp==NULL)
    {
        printf("NO RECORD ADDED.");
        menu();
    }
    else
    {
        rp = fopen("TempFile.dat","a");
        system("cls");
        printf("Enter Id to Update : ");
        scanf("%d",&target);
        fflush(stdin);
        int size = 1000,i=0,ck=0;
        char test[size];
        while((fgets(test,size,fp))!=NULL)
        {
            if(i%4==0)
            {
                st.Id=atoi(test);
            }
            else if(i%4==1)
            {
                strcpy(st.Title,test);
            }
            else if(i%4==2)
            {
                strcpy(st.Description,test);
            }
            else if(i%4==3)
            {
                st.Priority=atoi(test);
            }
            if(i%4==3)
            {
                if(target==st.Id)
                {
                    a=1;
                    printf("\n\t*****  Record Found  *****");
                    printf("Id : %d\nTitle : %s\nDescription : %s\nPriority : %d\n\n\n",st.Id, st.Title, st.Description, st.Priority);
                    printf("\n\n\t*** New Record ***");

                    fflush(stdin);
                    printf("\nNew Title \t\t: ");
                    gets(st.Title); // get input string
                    st.Title[0]=toupper(st.Title[0]);


                    //Description:
                    fflush(stdin);
                    printf("\n New Description \t\t: ");
                    gets(st.Description); // get input string
                    st.Description[0]=toupper(st.Description[0]);


                    //Priority:
                    printf("\nNew Priority :");
                    scanf("%d",&st.Priority);

                    for(int i=0; i<4; i++)
                    {
                        if(i==0)
                        {
                            fprintf(rp,"%d", st.Id);
                        }
                        else if(i==1)
                        {
                            fprintf(rp,"\n%s",st.Title);
                        }
                        else if(i==2)
                        {
                            fprintf(rp,"\n%s",st.Description);
                        }
                        else if(i==3)
                        {
                            fprintf(rp,"\n%d\n",st.Priority);
                        }
                    }
                }
                else
                {
                    for(int i=0; i<4; i++)
                    {
                        if(i==0)
                        {
                            fprintf(rp,"%d", st.Id);
                        }
                        else if(i==1)
                        {
                            fprintf(rp,"\n%s",st.Title);
                        }
                        else if(i==2)
                        {
                            fprintf(rp,"%s",st.Description);
                        }
                        else if(i==3)
                        {
                            fprintf(rp,"%d\n",st.Priority);
                        }
                    }
                }
            }
            i++;
        }

        fclose(rp);
        fclose(fp);

        if(!a)
        {
            printf("\n\nTHIS PRODUCT DOESN'T EXIST!!!!");
            menu();
        }

        printf("Press 'y' to edit the existing record or any key to cancel...");
        edit=getche();
        if(edit=='y' || edit=='Y')
        {

            remove("To-Do.dat");
            rename("TempFile.dat","To-Do.dat");

            printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
            getch();
            menu();
        }
        else
            menu();
    }
}


void search_item()
{
    int target;
    int found=0,i=0;
    FILE *sfile;
    sfile=fopen("To-Do.dat","r");
    printf("\nEnter ID to search:");
    fflush(stdin);
    scanf("%d",&target);
    int size = 1000;
    char test[1000];
    while((fgets(test,size,sfile))!=NULL)
    {
        if(i%4==0)
        {
            st.Id=atoi(test);
        }
        else if(i%4==1)
        {
            strcpy(st.Title,test);
        }
        else if(i%4==2)
        {
            strcpy(st.Description,test);
        }
        else if(i%4==3)
        {
            st.Priority=atoi(test);
        }
        if(i%4==3)
        {
            if(target==st.Id)
            {
                found=1;
                printf("Id : %d\nTitle : %s\nDescription : %s\nPriority : %d\n\n\n",st.Id, st.Title, st.Description, st.Priority);
            }
        }
        i++;
    }

    if(found==0)
    {
        printf("No Record found\n\n\n\n");
    }
    fclose(sfile);
    printf("\nPress any key to go to Main Menu!");
    getch();
    menu();

}


void read_item()
{
    FILE *sfile;
    sfile=fopen("To-Do.dat","r");
    printf("\nALL LIST OF TO_DO\n");
    printf("\n===================\n\n");
    fflush(stdin);
    int i=0,ck=0;
    int size=1000;
    char test[size];
    //size_t=len=0;
    while((fgets(test,size,sfile))!=NULL)
    {

        if(i%4==0)
        {
            st.Id=atoi(test);
        }
        else if(i%4==1)
        {
            strcpy(st.Title,test);
        }
        else if(i%4==2)
        {
            strcpy(st.Description,test);
        }
        else if(i%4==3)
        {
            st.Priority=atoi(test);
        }
        if(i%4==3)
        {
            printf("Id : %d\nTitle : %s\n\n\n",st.Id, st.Title);
        }
        i++;
        //test = NULL;
        //len=0;
    }

    fclose(sfile);
    printf("\nPress any key to go to Main Menu!");
    getch();
    menu();

}

void search_priority()
{
    int target;
    int found=0;
    FILE *sfile;
    sfile=fopen("To-Do.dat","r");
    printf("\nEnter Priority to search:");
    fflush(stdin);
    scanf("%d",&target);
    printf("\nDisplay all To-Do in %d Priority\n",target);
    printf("\n==================================\n\n");
    int i=0,ck=0,comp,j=0;
    int size=1000;
    char test[1000];

    while((fgets(test,size,sfile))!=NULL)
    {

        if(i%4==0)
        {
            st.Id=atoi(test);
        }
        else if(i%4==1)
        {
            strcpy(st.Title,test);
        }
        else if(i%4==2)
        {
            strcpy(st.Description,test);
        }
        else if(i%4==3)
        {
            st.Priority=atoi(test);
        }
        if(i%4==3)
        {
            if(target==st.Priority)
            {
                found=1;
                printf("Id : %d\nTitle : %s\n\n\n",st.Id, st.Title);
            }
        }
        i++;

    }

    if(found==0)
    {
        printf("No Record found");
    }
    fclose(sfile);
    printf("\nPress any key to go to Main Menu!");
    getch();
    menu();

}

