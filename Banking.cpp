#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>

//Simple Banking System

struct acc
{
	int tbal;
	char name[100],ups[100],ups1[100];	
};

acc s[100];
int ch1,ch2,i=0,amtd,amtd1;
char un[100],pass[100];


void display1()
{
	printf("\n\n**********Welcome To MSP Bank**********\n\n");
	
	printf("\n0. Exit\n1. For Creating New Account \n2. Already A Customer \nEnter Your Choice: ");
	scanf("%d",&ch1);
	fflush(stdin);
}

void newacc()
{
	int f=0,k=0;
	
	for(f=0;f<=100;f++)
	{
		if(s[f].name[0]==0)
		{
			k++;
		}
	}
	
	if(k==100)
	{
		printf("\n\n***Sorry No Users Left***");
	}
	
	printf("\n\n***Creating New Account***\n\n");

    printf("\n\nPlease Enter A Unique Username: ");
    gets(s[i].name);
	
	printf("\n\nPlease Enter Your New Password: ");
	gets(s[i].ups);
	
	printf("\nTo Conform Your New Password Please Re-enter Your Password: ");
	gets(s[i].ups1);
	
	if((strcmp(s[i].ups,s[i].ups1))==0)
	{
		printf("\n\n*****New Account Created Successfully*****\n\n");
		i++;
	}
	else
	{
		printf("\n\nPlease Re-conform your password\n\n");
	}
	printf("%5d",i);
}

void Balance(int *tbal)
{
	printf("Currently You Total Balance Is %d rupees",*tbal);
}

void Cashd(int *tbal)
{
	printf("\n\nPlease Enter The Amount In Multiples Of 50,100,500\n\n");
	
	printf("\nplease Enter The Amount You Want To Deposit: ");
	scanf("%d",&amtd);
	
	*tbal = *tbal + amtd;
	printf("\n\n***%d Amount Deposited Successfully***\n\n",amtd);
	
	printf("\n\nYour Total Balance Is %d rupees",*tbal);
}

void Cashw(int *tbal)
{
	printf("\n\nPlease Enter The Amount In Multiples Of 50,100,500\n\n");
	
	printf("\nplease Enter The Amount You Want To Withdraw: ");
	scanf("%d",&amtd1);
	
	if(*tbal>=amtd1)
	{
		*tbal = *tbal - amtd1;
		printf("\n\n***%d Amount Withdrawn From Your Account Successfully***",amtd1);
		printf("\n\nYour New Balance Is %d",*tbal);
	}
	else
	{
		printf("\n\nNot Able To Make The Transaction Due To Insufficient Balance");
	}
}

void functions(int *tbal)
{
	printf("\n\n\n*****Please Select Anything From The Bellow*****\n\n");
	
	printf("\n0. Exit\n1. Balance Inquiry\n2. Cash Deposit\n3. Cash Withdrawl\nEnter Your Choice: ");
	scanf("%d",&ch2);
	
	switch(ch2)
	{
		case 0:exit(0);
		case 1:Balance(tbal);break;
		case 2:Cashd(tbal);break;
		case 3:Cashw(tbal);break;
		default :printf("\n\n***Please Enter A Valid Choice***\n\n");break;
	}
}

void acc()
{
	printf("\n\nPlease Enter Your Username/Id: ");
	gets(un);
	
	printf("\n\nPlease Enter Your Password: ");
	gets(pass);
	
	int j;
	for(j=0; j<i; j++)
	{
		if((strcmp(un,s[j].name))==0 && (strcmp(pass,s[j].ups))==0)
		{
			printf("Correct Username And Password");
			while(1)
			{
				functions(&s[j].tbal);
			}
			return;
		}
	}
	
	printf("Invalid username or password");
}


int main()
{
	while(1)
	{
		display1();
		switch(ch1)
		{
			case 0:exit(0);
			case 1:newacc();break;
			case 2:acc();break;
			default :printf("\n\n***Please Enter A Valid Choice***\n\n");break;
		}
	}
}
