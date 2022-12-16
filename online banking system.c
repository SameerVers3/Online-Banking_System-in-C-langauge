#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>

int i, j, choice=0;
const char pass_w[] = "Fast1234";

//----------------------------------------------------------------------
//-------------------------------FUNCTIONS------------------------------
void load_screen();
void reg_account();
void up_info();
void transect();
void check_detail();
void deposit();
void withdraw();
void remove_acc();
void acc_list();
void ty();
void wc();
void gotoxy (int x, int y);


//----------------------------------------------------------------------
//-------------------------------Structures-----------------------------
struct date{
	int  day, mon, year;
};

//structure for Client imformation handling
struct data {
	int age;
	char name[50];
	char address[60];
	char acc_type[60];
	char acc_no[100];
	float balance;
	struct date dob;
	struct date depo;
}add,tem,update,check,rmv, trans1, trans2;

//----------------------------------------------------------------------
//-------------------------------MAIN FUNCTION------------------------------

int main() {
	
	load_screen();
	
	int count=0, choi=0;
	
	wc();
	flag1: {
	char pass[30];
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter password:  ");
	fflush(stdin);
	gets(pass);
	
	if (strcmp(pass, pass_w)==0) {
		
		printf("\n\t\t\t\t\t\tPASSWORD MATCHED !!");
		sleep(1);
		system("cls");
		while (choice != 9) {
			
			flag2: {
			printf("************************************************************************************************************************");
			printf("------------------------------------------------------------------------------------------------------------------------\n\n\n\n\n");
			printf("\t\t\t\t\t\tEnter your Choice: \n\n");
			printf("\t\t\t\t\t _______________________________________________\n");
			printf("\t\t\t\t\t|  1. Register new account:\n");
			printf("\t\t\t\t\t|_______________________________________________\n");
			printf("\t\t\t\t\t|  2. Update Account Information\n");
			printf("\t\t\t\t\t|_______________________________________________\n");
			printf("\t\t\t\t\t|  3. Make Transection \n");
			printf("\t\t\t\t\t|_______________________________________________\n");
			printf("\t\t\t\t\t|  4. Deposit \n");
			printf("\t\t\t\t\t|_______________________________________________\n");
			printf("\t\t\t\t\t|  5. Withdraw \n");
			printf("\t\t\t\t\t|_______________________________________________\n");
			printf("\t\t\t\t\t|  6. Check Account Details\n");
			printf("\t\t\t\t\t|_______________________________________________\n");
			printf("\t\t\t\t\t|  7. Delete Account \n");
			printf("\t\t\t\t\t|_______________________________________________\n");
			printf("\t\t\t\t\t|  8. List \n");
			printf("\t\t\t\t\t|_______________________________________________\n");
			printf("\t\t\t\t\t|  9. Exit\n");
			printf("\t\t\t\t\t|_______________________________________________\n\n\n\n\n");
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			printf("************************************************************************************************************************\n");
			printf("\n\t\t\t\t==> ");
		
			scanf("%d", &choice);
			
			switch(choice) {
				case 1: {
						load_screen();
						reg_account();
					break;
				}
				
				case 2: {
						load_screen();
	     				up_info();
					break;
				}
				
				case 3: {
					load_screen();
					transect();	
					break;
				}
				
				case 4: {
					load_screen();
					deposit();
					break;
				}
				
				case 5: {
					load_screen();
					withdraw();
					break;
				}
				
				case 6: {
					load_screen();
					check_detail();
					break;
				}
				
				case 7: {
					load_screen();
					remove_acc();
					break;
				}
				
				case 8: {
					load_screen();
					acc_list();
					break;
				}
				
				case 9: {
					ty();
					exit(1);
					break;
				}
				
				default: {
					printf("\n\t\t\t\t------>>    Invalid Input RETRY    <<---------");
					sleep(1);
					system("cls");
					goto flag2;
					break;
				}
			}		
		}
	}
	}
	else {
		
		printf("\n\t\t\t\t\t\tPassword INCORRECT:");
		flag3: {
		printf("\n\n\t\t\t\t\t\tEnter 1. to retry password   2. to exit\n\t\t\t\t\t==> :");
		scanf("%d", &choi);

		if (choi == 1) {
			goto flag1;
		}
		else if (choi == 2) {
			ty();
			sleep(2);
			exit(1);
		}
		
		else {
			printf("\t\t\t\t\t INVALID CHOICE !!");
			
			goto flag3;
		}	
	}
	}
	}
}

//-------------------------------------------------------------------
//----------------------------Loading function-----------------------


void load_screen() {
	system("cls");
	gotoxy(50, 7);
	printf("Loading...");
	gotoxy(50, 8);
	for (i=1; i<=20;i++) {
		for (j=0; j<=10000000; j++);
		printf("%c", 219);
	}
	system("cls");
}

//-------------------------------------------------------------------
//------------------------Thankyou screen function-------------------

void ty() {
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading.");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	system("cls");
	printf("************************************************************************************************************************");
	printf("------------------------------------------------------------------------------------------------------------------------\n\n\n");
	printf("\n\n\n\t\t\t\t\tTHANK YOU! for using BANK \n\n\n\n\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("************************************************************************************************************************\n");
}

//-------------------------------------------------------------------
//----------------------------Welcome screen function----------------

void wc() {
	printf("************************************************************************************************************************");
	printf("------------------------------------------------------------------------------------------------------------------------\n\n\n\n\n\n");
	printf("\t\t\t\t\t\tWelcome To the BANK OF MINE.\n\n\n\n\n\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("***********************************************************************************************************************");
	sleep(1);
	system("cls");
}

//-------------------------------------------------------------------
//-----------------------Moving crusor position function-------------
void gotoxy (int x, int y) {
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//-------------------------------------------------------------------
//-------------------Register account function-----------------------

void reg_account() {
	FILE *ptr, *acc_ptr;
	char tem[500];
	acc_ptr = fopen("database.txt", "a+");

	if (acc_ptr == NULL ) {
		printf("\n\n\n\n\n\n\n\t\t\t\t\tSYSTEMIC ERROR! Try again in a while");
		goto close;
	}
	
	
	// --------------- retry goto function ----------
	retry: {
	rewind(acc_ptr);	
	printf("\n\n\n\n\n\n\n\t\t\t\t\tEnter Phone number (Account no.): ");
	scanf("%s", &check.acc_no);
	
	
	//to check phone number length
	if (strlen(check.acc_no) != 11) {
		printf("\n\n\n\t\t\t\t\tPhone number length should be 11 digits");
		sleep(1);
		system("cls");
		goto retry;
	}
	
	
	//to check phone number validity
	for (i=0; i<11; i++) {
		if (check.acc_no[i] < 48 || check.acc_no[i] > 57) {
			printf("\n\n\t\t\t\t\tINVALID PHONE NO.");
			printf("\n\n\t\t\t\t\tShould be digits only");
			sleep(1);
			system("cls");
			goto retry;
		}
	}
	
	char line[500];
	char *p;
	
	while(!feof(acc_ptr)) {

		fscanf(acc_ptr, "%s", line);
		p = strstr(line , check.acc_no);
		
		if (p) {
			printf("\n\t\t\t\t\tAccount no. Already exist: ");
			sleep(1);
			system("cls");
			printf("\n\n\n\n\n\n\n\t\t\t\tDo you want to retry or go back to menu ??");
			printf("\n\n\t\t\t\t\t 1.  Retry");
			printf("\n\t\t\t\t\t 2. Back to menu\n");
			ch_retry: {	
				printf("\n\t\t\t\t\t ==>");
				scanf(" %d", &choice);
				if (choice==1) {
					system("cls");
					goto retry;
				}
				else if (choice == 2) {
					system("cls");
					goto close;
				}
				else {
					printf("\t\t\t\t\t INVALID CHOICE !!");
					goto ch_retry;
					
				}
			}
		}
	}
	
	printf("\t\t\t\t\tEnter name:");
	fflush(stdin);
	gets(add.name);
	
	dateflag1: {                      // to check date
	printf("\t\t\t\t\tEnter date (current) (dd/mm/yyyy): ");
	scanf("%d %d %d", &add.depo.day, &add.depo.mon, &add.depo.year);
	}
	
		if (add.depo.day>31 || add.depo.mon>12 || add.depo.year>2023) {
			printf("\n\t\t\t\t\tINVALID DATE Enter date again: \n\n");
			goto dateflag1;
		}
	
	
	dateflag2: {                          // to check date
	printf("\t\t\t\t\tEnter date of birth (dd/mm/yyyy) :");
	scanf("%d %d %d", &add.dob.day, &add.dob.mon, &add.dob.year);
	}
	
		if (add.dob.day>31 || add.dob.mon>12 || add.dob.year<1900 || add.dob.year>add.depo.year) {
			printf("\n\t\t\t\t\tINVALID DATE Enter date again: \n\n");
			goto dateflag2;
		}
		
		else if (add.depo.year - add.dob.year < 15) {
			printf("\n\n\t\t\t\t\tNOT ELIGIBLE!! GROW UP AND COME BACK");
			
			goto close;
		}
	
	printf("\t\t\t\t\tEnter your age: ");
	scanf(" %d", &add.age);
	
	if (add.age < 15) {
		printf("\n\n\t\t\t\t\tNOT ELIGIBLE!! GROW UP AND COME BACK");
		goto close;
	}
	printf("\t\t\t\t\tEnter your address: ");
	fflush(stdin);
	gets(add.address);
	printf("\t\t\t\t\tEnter Account type: \n\t\t\t\t\tCurrent \n\t\t\t\t\tSaving\n\t\t\t\t\t==>: ");
	scanf("%s", add.acc_type);
	printf("\t\t\t\t\tEnter initial amount: ");
	scanf("%f", &add.balance);

	fprintf(acc_ptr, "%s\n", check.acc_no);
	ptr = fopen(strcat(check.acc_no, ".dat"), "a+");
	
	fwrite(&add ,sizeof(struct data), 1, ptr);
	fclose(ptr);

	system("cls");
	printf("\n\n\n\n\n\n\n\t\t\t\t\tAccount Successfully created!! ");
	goto close;
}
	close: {
		sleep(1);
		system("cls");
		fclose(ptr);
	}
	
	fclose(acc_ptr);
}

//-------------------------------------------------------------------
//-------------------Update info function----------------------------

void up_info() {
	FILE *ptr;
	int ch, cho;
	char acc[500], temp[100];
	gotoxy(40, 8);
	printf("Enter Account number: ");
	scanf("%s", &acc);
	
	strcat(acc, ".dat");
	
	ptr = fopen(acc, "r");
	
	if (ptr == NULL ) {
		printf("\n\n\n\n\n\n\n\t\t\t\t\tAccount NOT FOUND:  ");
		goto close;
	}
	
	fread(&tem, sizeof(tem), 1, ptr);
	
	fclose(ptr);
	
	update = tem;	
	
	
	flag2: {	
	gotoxy(45, 10);
	printf("Which information do you want to change ? \n\n");
	printf("\t\t\t\t\t1. Name\n\t\t\t\t\t2. Age\n\t\t\t\t\t3. Address\n\t\t\t\t\t4. Account type\n\t\t\t\t\t5. Date of Birth\n\n\t\t\t\t\t==>");
	
	scanf("%d", &ch);
	
	system("cls");
	gotoxy(40, 8);
	switch (ch) {
		case 1: {
			printf("Enter new name: ");
			fflush(stdin);
			gets(temp);
			strcpy(update.name, temp);
			break;
		}
		case 2: {
			printf("Enter new age: ");
			scanf("%d", &update.age);
			break;
		}
		case 3: {
			printf("Enter new Address: ");
			fflush(stdin);
			gets(temp);
			strcpy(update.address, temp);
			break;
		}
		case 4: {
			printf("Enter Account Type: \n\t\t\t\t\t\t\t=> Current\n\t\t\t\t\t\t\t=> Saving\n\n\t\t\t\t\t\t\t=> ");
			scanf("%s", &temp);
			strcpy(update.acc_type, temp);
			break;
		}
		
		case 5: {
			printf("Enter New Date of Birth (dd/mm/yyyy): \n");
			scanf("%d, %d, %d", update.dob.day, update.dob.mon, update.dob.year);
		}
		
		default: {
			flag: {
			printf("ERROR Wrong Input!!\n\n");
			printf("\t\t\t\t\tWhat do you want to do? \n\n\t\t\t\t\t1. retry or 2. Close ==> :");
			scanf("%d", &cho);
			
			if (cho==1 ) {
				system("cls");
				goto flag2;
			}
			else if (cho == 2) {
				goto close;
			}
			else {
				goto flag;
			}
			}
			break;
		}
	}
	
	
	ptr = fopen(acc, "w");
	
	if (ptr == NULL ) {
		printf("\n\n\n\n\n\n\n\t\t\t\t\tSystemic ERROR try again in while:  ");
		goto close;
	}
	
	
	fwrite(&update ,sizeof(struct data), 1, ptr);
	
	system("cls");
	gotoxy(40, 8);
	printf("Information Changed Successfully!! ");
	sleep(1);
	fclose(ptr);
	
	close: {
		system("cls");
	}
}
}

//-------------------------------------------------------------------
//-------------------Transection function----------------------------

void transect()  {
	FILE *ptr1, *ptr2;
	int ch, cho;
	float amount;
	char acc_s[500],acc_r[500],temp[100];
	flag2: {
	gotoxy(40, 8);
	printf("Enter Account number of sender: ");
	scanf("%s", &acc_s);
	
	
	strcat(acc_s, ".dat");
	ptr1 = fopen(acc_s, "r");
	
	if (ptr1 == NULL ) {
		gotoxy(40, 11);
		printf("Sender account Not Found!! \n\n");
		flag: {
			printf("\t\t\t\t\tWhat do you want to do? \n\n\t\t\t\t\t1. retry or 2. Close ==> :");
			scanf("%d", &cho);
			
			if (cho==1 ) {
				system("cls");
				goto flag2;
			}
			else if (cho == 2) {
				goto close;
			}
			else {
				printf("\t\t\t\t\tERROR Wrong Input!!\n\n");
				goto flag;
			}
			}
		goto close;
	}
	
	printf("\t\t\t\t\tEnter Account number of Receiver:  ");
	scanf("%s", &acc_r);
	
	strcat(acc_r, ".dat");
	
	ptr2 = fopen(acc_r, "r");
	
	if (ptr2 == NULL ) {
		gotoxy(40, 11);
		printf("Receiver account Not Found!! \n\n");
		flag3: {
			printf("\t\t\t\t\tWhat do you want to do? \n\n\t\t\t\t\t1. retry or 2. Close");
			scanf("%d", &cho);
			
			if (cho==1 ) {
				system("cls");
				goto flag2;
			}
			else if (cho == 2) {
				goto close;
			}
			else {
				printf("\t\t\t\t\tERROR Wrong Input!!\n\n");
				goto flag3;
			}
			}
		goto close;
	}
	
	fread(&trans1, sizeof(trans1), 1, ptr1);
	fread(&trans2, sizeof(trans2), 1, ptr2);
	
	fclose(ptr1);
	fclose(ptr2);
	
	
	bal_retry: {
	printf("\n\t\t\t\t\tEnter amount : ");
	scanf("%f", &amount);
	
	if (amount > trans1.balance) {
		printf("\n\n\t\t\t\t\tINSAFICIENT BALANCE!! \n");
		flag4: {
			printf("\t\t\t\t\tWhat do you want to do? \n\n\t\t\t\t\t1. retry or 2. Close");
			scanf("%d", &cho);
			
			if (cho==1 ) {
				system("cls");
				goto bal_retry;
			}
			else if (cho == 2) {
				goto close;
			}
			else {
				printf("\t\t\t\t\tERROR Wrong Input!!\n\n");
				goto flag4;
			}
			}
	}
	
	trans2.balance += amount;
	trans1.balance -= amount;
	
	ptr1 = fopen(acc_s, "w");
	ptr2 = fopen(acc_r, "w");
	
	fwrite(&trans1 ,sizeof(struct data), 1, ptr1);
	fwrite(&trans2 ,sizeof(struct data), 1, ptr2);
	
	system("cls");
	gotoxy(40, 8);
	printf("Amount successfully transfered...");
	sleep(1);
	
	fclose(ptr1);
	fclose(ptr2);
	
	close: {
		system("cls");
	}
}}}


//-------------------------------------------------------------------
//------------------Deposit info function----------------------------

void deposit() {
	char acc[100];
	int cho;
	FILE *ptr;
	
	
	flag2: {
	gotoxy(40, 8);
	printf("Enter Account number ");
	scanf("%s", &acc);
	float amount;
	
	
	gotoxy(40, 11);
	
	strcat(acc, ".dat");
	ptr = fopen(acc, "r");
	
	if (ptr == NULL ) {
		gotoxy(40, 11);
		printf("Account Not Found!! \n\n");
		flag: {
			printf("\t\t\t\t\tWhat do you want to do? \n\n\t\t\t\t\t1. retry or 2. Close ==> :");
			scanf("%d", &cho);
			
			if (cho==1 ) {
				system("cls");
				goto flag2;
			}
			else if (cho == 2) {
				goto close;
			}
			else {
				printf("\t\t\t\t\tERROR Wrong Input!!\n\n");
				goto flag;
			}
			}
		goto close;
	}
	
	
	
	fread(&trans1, sizeof(trans1), 1, ptr);
	
	fclose(ptr);
	
	
	printf("\n\t\t\t\t\tEnter amount : ");
	scanf("%f", &amount);

	trans1.balance += amount;
	
	ptr = fopen(acc, "w");
	
	fwrite(&trans1 ,sizeof(struct data), 1, ptr);
	system("cls");
	gotoxy(40, 8);
	printf("Amount successfully Deposited...");
	sleep(1);
	
	fclose(ptr);
}

	close: {
		system("cls");
	}
	
	
}


//-------------------------------------------------------------------
//----------------------Withdraw function----------------------------


void withdraw() {
	
	char pass[50], acc[100];
	int cho;
	float amount;
	FILE *ptr;
	
	
	flag2: {
	gotoxy(40, 8);
	printf("Enter Account number ");
	scanf("%s", &acc);
	
	
	strcat(acc, ".dat");
	ptr = fopen(acc, "r");
	
	if (ptr == NULL ) {
		gotoxy(40, 11);
		printf("Account Not Found!! \n\n");
		flag: {
			printf("\t\t\t\t\tWhat do you want to do? \n\n\t\t\t\t\t1. retry or 2. Close ==> :");
			scanf("%d", &cho);
			
			if (cho==1 ) {
				system("cls");
				goto flag2;
			}
			else if (cho == 2) {
				goto close;
			}
			else {
				printf("\t\t\t\t\tERROR Wrong Input!!\n\n");
				goto flag;
			}
			}
		goto close;
	}
	
	
	
	fread(&trans1, sizeof(trans1), 1, ptr);
	
	fclose(ptr);
	
	bal_retry: {
	printf("\n\t\t\t\t\tEnter amount : ");
	scanf("%f", &amount);
	
	
	if (amount > trans1.balance) {
		printf("\n\n\t\t\t\t\tINSAFICIENT BALANCE!! \n");
		flag4: {
			printf("\t\t\t\t\tWhat do you want to do? \n\n\t\t\t\t\t1. retry or 2. Close");
			scanf("%d", &cho);
			
			if (cho==1 ) {
				system("cls");
				goto bal_retry;
			}
			else if (cho == 2) {
				goto close;
			}
			else {
				printf("\t\t\t\t\tERROR Wrong Input!!\n\n");
				goto flag4;
			}
			}
	}
	
	trans1.balance -= amount;
	
	ptr = fopen(acc, "w");
	
	fwrite(&trans1 ,sizeof(struct data), 1, ptr);
	system("cls");
	gotoxy(40, 8);
	printf("Amount successfully Withdrawn...");
	sleep(1);
	
	fclose(ptr);
	
	close: {
		system("cls");
	}
	
	
}}}


//-------------------------------------------------------------------
//-------------------Check detail function---------------------------

void check_detail() {
	char acc[500];
	FILE *ptr;
	int cho;
	
	flag: {
	gotoxy(40, 8);
	printf("Enter Account no. to Check: ");
	scanf("%s", &acc);
	strcat(acc, ".dat");
	
	ptr = fopen(acc, "r");
	
	if (ptr == NULL ) {
		gotoxy(40, 11);
		printf("Account Not Found!! \n\n");
		flag2: {
			printf("\t\t\t\t\tWhat do you want to do? \n\n\t\t\t\t\t1. retry or 2. Close ==> :");
			scanf("%d", &cho);
			
			if (cho==1 ) {
				system("cls");
				goto flag;
			}
			else if (cho == 2) {
				goto close;
			}
			else {
				printf("\t\t\t\t\tERROR Wrong Input!!\n\n");
				goto flag2;
			}
			}
		goto close;
	}
	
	fread(&check, sizeof(check), 1, ptr);
	
	fclose(ptr);
	
	system("cls");
	gotoxy(50, 3);
	printf("The BANK OF MINE");
	gotoxy(0, 5);
	printf("************************************************************************************************************************");
	printf("------------------------------------------------------------------------------------------------------------------------");
	
	
	gotoxy(30, 8);
	
	printf("________________________________________________");
	gotoxy(30, 9);
	printf("|  Name :\t\t\t %s ", check.name);
	gotoxy(30, 10);
	printf("|_______________________________________________");
	gotoxy(30, 11);
	printf("|  Balance :\t\t Rs. %.3f /=", check.balance);
	gotoxy(30, 12);
	printf("|_______________________________________________");
	gotoxy(30, 13);
	printf("|  Address :\t\t %s ", check.address);
	gotoxy(30, 14);
	printf("|_______________________________________________");
	gotoxy(30, 15);
	printf("|  Date of Birth :\t %d / %d / %d ", check.dob.day, check.dob.mon, check.dob.year);
	gotoxy(30, 16);
	printf("|_______________________________________________");
	gotoxy(30, 17);
	printf("|  Account type :\t\t %s", check.acc_type);
	gotoxy(30, 18);
	printf("|_______________________________________________");
	
	gotoxy(30, 22);
	printf("Press any key to go back to MENU:  ");
	getch();
	

	close: {
		system("cls");
	}
	
}}

//-------------------------------------------------------------------
//-------------------Remove account function-------------------------

void remove_acc() {
	char to_rmv[500], acc[500], temp[500], temp2[500];
	FILE *ptr, *ftem;
	char *p;
	int cho, t;
	gotoxy(40, 8);
	printf("Enter Account no. to Delete:  ");
	scanf("%s", &acc);
	strcpy(temp2, acc);
	strcat(acc, ".dat");
	
	if (remove(acc) == 0) {
		printf("\n\n\t\t\t\t\t\tDeleted successfully");
		ptr = fopen("database.txt", "r");
		ftem = fopen("new.txt", "a+");
		
		
		while (!feof(ptr) ){
		
			fscanf(ptr, "%s", temp);
			p = strstr(temp , temp2);
			
			if (p){
			}
			else {
				fprintf(ftem, "%s\n", temp);
			}
		
		}
		
		fclose(ptr);
		fclose(ftem);
		t = 1;
		
  	}
   	else {
		printf("\n\n\t\t\t\t\tAccount no found!! ");
		sleep(1);
	}
	
	if (t==1) {
		remove("database.txt");
		rename("new.txt", "database.txt");
		
	}
	system("cls");
}

//-------------------------------------------------------------------
//-------------------Account list function---------------------------

void acc_list() {
	
	FILE *ptr, *tem_ptr;
	char temp[50], line[50], acc_no[50];
	int y = 12;
	
	ptr = fopen("database.txt", "r");
	
	if (ptr == NULL ) {
		gotoxy(30, 10);
		printf("SYSTEMIC ERROR! Try again in a while..");	
		goto close;			
	}
		
		
	gotoxy(50, 3);
	printf("The BANK OF MINE");
	gotoxy(0, 5);
	printf("************************************************************************************************************************");
	printf("------------------------------------------------------------------------------------------------------------------------");	
	
	gotoxy(2, 8);
	printf("______________________________________________________________________________________________________________________");
	gotoxy(2, 10);
	printf("| Name\t| Acc. no.\t| Balance\t| Address\t| Date of Birth\t| Account type\t|");
	gotoxy(2, 11);
	printf("______________________________________________________________________________________________________________________");
	
	do {
		fscanf(ptr, "%s", temp);
		strcpy(acc_no, temp);
		strcat(temp, ".dat");
		tem_ptr = fopen(temp, "r");
			
		if (tem_ptr == NULL) {
		}
			
			
			
		fread(&tem, sizeof(tem), 1, tem_ptr);
		fclose(tem_ptr);
		
		gotoxy(2, y);
		printf("| %s\t| %s\t| %.2f\ =\t| %s\t| %d/%d/%d\t| %s\t|", tem.name, acc_no, tem.balance, tem.address, tem.dob.day, tem.dob.mon, tem.dob.year, tem.acc_type);
		
		y += 2;
	} while (!feof(ptr));
			
	gotoxy(2, y);
	printf("______________________________________________________________________________________________________________________");
	
	
	getch();
	close: {
		system("cls");
	}		
	
}