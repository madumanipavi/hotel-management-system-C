
#include<stdio.h>

char Fname1[25],Fname2[25],Email[25],NIC[12],CPNumber[12];                           //Costumer detail
int Rtype,Rquantity,Rdays,Rbill=0;                                                   //Room
int Fpackage,Fbreakfast,Flunch,Fdinner,Fbill=0;                                      //Food
int Ppackage,Pdays,Pbill=0;                                                          //Pool
int FullBill,Dis=0,LastBill=0;                                                       //Cal
int a=0,ab,tday=0;                                                                   //repeat



void Details()
{
    printf("\t\t\t**WELCOME TO OASIS HOTEL**\n\n\n\n");
    printf("PRICE LIST\n\n");

    printf("\tRoom types      \n\n\t\t");
    printf("Single room(1)   -");     printf("8000LKR\n\t\t");
    printf("Double room(2)   -");     printf("12000LKR\n\n\n");

    printf("\tFoods\n\t\t");
    printf("Food package 1    (for 5 persons)\n\t\t\t");
    printf("Breakfast      -");      printf("4000LKR\n\t\t\t");
    printf("Lunch          -");       printf("5500LKR\n\t\t\t");
    printf("Dinner         -");      printf("4000LKR\n\n\t\t");

    printf("Food package 2    (for 5+ persons)\n\t\t\t");
    printf("Breakfast      -");     printf("7000LKR\n\t\t\t");
    printf("Lunch          -");     printf("9000LKR\n\t\t\t");
    printf("Dinner         -");     printf("7000LKR\n\n\n");

    printf("\tPool packages\n\n");
    printf("\t\tPackage 1        -10,000LKR       (for 5+ persons)\n");
    printf("\t\tPackage 2        -5,000LKR        (for 5 persons)\n\n\n");

    printf("\tdiscounts\n\n");
    printf("\t\t**if room used days more than 10   :-   25 percent off from total payment\n");
    printf("\t\t**if room used days more than 5    :-   15 percent off from total payment\n\n");


}
void Costumerdetail()
{
    printf("Enter Costumer Fist Name     :");
    scanf("%s",&Fname1);

    printf("\nEnter Costumer Last Name     :");
    scanf("%s",&Fname2);

    printf("\nEnter Costumer Phone Number  :");
    scanf("%s",&CPNumber);

    printf("\nEnter Costumer Email Address :");
    scanf("%s",&Email);

    printf("\nEnter Costumer NIC Number    :");
    scanf("%s",&NIC);
}

void Room()     
{
    printf("enter\n *1 for Single package\n *2 for Double package\n");
    printf("enter room type\t\t\t:");
    scanf("%d",&Rtype);

        switch(Rtype)
        {
            case 1:
            printf("enter room quantity\t\t:");
            scanf("%d",&Rquantity);
            printf("enter how many days used\t:");
            scanf("%d",&Rdays);
            Rbill=8000*Rdays*Rquantity;
            break;

        case 2:
            printf("enter room quantity\t\t:");
            scanf("%d",&Rquantity);
            printf("enter how many days used\t:");
            scanf("%d",&Rdays);
            Rbill=12000*Rdays*Rquantity;
            break;

        default:

            printf("entered room type wrong\n\n");
            Room();
        }
}
void Food()    
{
    printf("enter\n *1 for 5 persons\n *2 for 5+persons\n");
    printf("enter food package\t\t:");
    scanf("%d",&Fpackage);

    if (Fpackage==1)
    {    printf("how many time had Breakfast\t:");
        scanf("%d",&Fbreakfast);
        printf("how many times had Launch\t:");
        scanf("%d",&Flunch);
        printf("how many time had Dinner\t:");
        scanf("%d",&Fdinner);
        Fbill=4000*Fbreakfast+5500*Flunch+4000*Fdinner;
    }
    else if(Fpackage==2)
    {
        printf("how many time had breakfast\t:");
        scanf("%d",&Fbreakfast);
        printf("how many times had launch\t:");
        scanf("%d",&Flunch);
        printf("how many time had dinner\t:");
        scanf("%d",&Fdinner);
        Fbill=7000*Fbreakfast+9000*Flunch+7000*Fdinner;
    }
    else if (Fpackage==0)
    {
        Fbill=0;
    }
    else
    {
        printf("you entered food package is wrong");
        Food();
    }

}
void Pool()     
{
    printf("enter\n *1 for 5+ persons\n *2 for 5 persons\n");
    printf("enter swimming pool package\t:");
    scanf("%d",&Ppackage);

        if (Ppackage==1)
        {
        printf("how many days pool used\t\t:");
        scanf("%d",&Pdays);
        Pbill=10000*Pdays;
        }
        else if(Ppackage==2)
        {printf("how many days pool used\t\t:");
         scanf("%d",&Pdays);
         Pbill=4000*Pdays;
        }
        else if (Ppackage==0)
        {
            Pbill=0;
        }
        else
        {
            printf("you entered swimming pool package is wrong");
            Pool();
        }

}
void Cal()    
{
    FullBill=Rbill+Fbill+Pbill;

    if (Rdays>=10)
    {
        Dis=FullBill*25/100;
    }
    else if (Rdays>=5)
    {
        Dis=FullBill*15/100;

    }
    else
    {
        Dis=0;
    }
        LastBill=FullBill-Dis;


}

void Print()
{
 printf("\n\n\n*****************************************WELCOME TO OASIS HOTEL*****************************************\n\n\n");
 printf("\t\t\tCostumer Name is           :%s %s\n",Fname1,Fname2);
 printf("\t\t\tCostumer Phone Number is   :%s\n",CPNumber);
 printf("\t\t\tCostumer Email Address     :%s\n",Email);
 printf("\t\t\tCostumer NIC Number        :%s\n\n\n",NIC);


 printf("\tRoom Charges    = %d",Rbill);
 printf("\t\tDiscount        = %d\n",Dis);
 printf("\tFood Charges    = %d\n",Fbill);
 printf("\tPool Charges    = %d\n\n\n\n",Pbill);



printf("\t\t\tTotal Bill is   = %d\n\n\n",LastBill);

printf("Please press enter to next bill");

    getch();
    system("cls");
}



void repeat()      
{
    while(a<=14)
    {
    Details();
    Costumerdetail();
    Room();
    Food();
    Pool();
    Cal();
    Print();
    a++;
    tday=tday+LastBill;
    }

    printf("\t\t\tTotal Income Of The Day Is   = %d\n\n\n",tday);


    printf("enter\n *1 Continue\n *2 Don't Continue\n");
    printf("Do you want to continue:");
    scanf("%d",&ab);

    if(ab==1)
    {
        a=0;
       repeat();
    }
    else if(ab==2)
    {
        exit(0);

    }
    else
    {
        exit(0);
    }
}



int main()
{

    repeat();
    return 0;
}
