// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

// global constants
#define PASSWORD_LENGTH 50
// Declaring all the functions;
void checkbalance(char *);
void transfermoney(void);
void display(char *);
void person(char *);
void login(void);
void loginsu(void);
void account(void);
void accountcreated(void);
void afterlogin(void);
void logout(void);
void forgotpassword(void);
// Declaring gotoxy
// function for setting
// cursor position
// COORD is a structure that defines the x (column) and y (row)
// coordinates in the console screen buffer.
// gotoxy is used to define the coordinated on the screen
// wher the desied text is to be shown
void gotoxy(int x, int y)
{
	// COORD is predefined in <windows.h>
	COORD c;
	// Set X coordinate
	c.X = x;
	// Set Y coordinate
	c.Y = y;

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// Creating a structure to store
// data of the user
struct pass
{
	char username[50];
	int date, month, year;
	char contact_number[10];
	char adhar_number[20];
	char fname[20];
	char lname[20];
	char father_name[20];
	char mother_name[20];
	char address[50];
	char account_type[20];
};
int generateOTP()
{
	// Ensure a 6-digit number (100000 to 999999)
	return 100000 + rand() % 900000;
}

// Structure to keep track
// of amount persent in bank account
struct money
{
	char usernameto[50];
	char userpersonfrom[50];
	long int money1;
};

struct userpass
{
	char password[50];
};

// Driver Code
int main()
{

	int i, a, b, choice;
	int passwordlength;

	gotoxy(30, 3);

	// Creating a Main
	// menu for the user
	printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
	gotoxy(30, 5);

	printf("");
	gotoxy(30, 7);

	printf("DEVELOPERS\n");
	gotoxy(30,8);
	printf("Advik Rajvansh\n");
	gotoxy(30,9);
	printf("Anant Kumar Verma\n");
	gotoxy(30,10);
	printf("Tushar Tandon\n");
	gotoxy(30,11);
	printf("Shourya Handa\n");


	gotoxy(30, 13);
	printf("1.... CREATE A BANK ACCOUNT\n");

	gotoxy(30, 15);
	printf("2.... ALREADY A USER? LOGIN IN\n");
	gotoxy(30, 17);
	printf("3.... EXIT\n");
	gotoxy(30, 19);

	// press the desired command you want to use
	printf("\n\nENTER YOUR CHOICE..");

	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		system("cls");
		printf("\n\n USERNAME 50 CHARACTERS MAX!!");
		printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
		// press on create account
		// this is used to create a new account
		account();
		break;

	case 2:
		// press login button
		// to enter login credentials
		login();
		break;

	case 3:
		// press exit button
		// to exit app
		exit(0);
		break;

		getch();
	}
}

// Function to create accounts
// of users
void account()
{
	char password[PASSWORD_LENGTH], confirmPassword[PASSWORD_LENGTH];
	char ch;
	// Declares a file pointer to handle the file operations.
	FILE *fp;
	FILE *fu;
	struct pass u1;
	struct userpass p1;
	// Opening file to
	// write data of a user
	// Opens the file for appending in binary mode.
	// It handles the error if the file cannot be opened.
	// a: Append mode - data is written to the end of the file, preserving existing data.
	// b: Binary mode - this is important on some operating systems (like Windows) to handle binary data correctly.
	fp = fopen("username.txt", "a");
	if (fp == NULL)
	{
		printf("Error opening file!");
		return;
	}

	// Inputs
	system("cls");
	printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

	printf("\n\nFIRST NAME..");
	scanf("%s", &u1.fname);

	printf("\n\n\nLAST NAME..");
	scanf("%s", &u1.lname);

	printf("\n\nFATHER's NAME..");
	scanf("%s", &u1.father_name);

	printf("\n\nMOTHER's NAME..");
	scanf("%s", &u1.mother_name);

	printf("\n\nADDRESS..");
	scanf("%s", &u1.address);

	gotoxy(20, 20);
	printf("ACCOUNT TYPE");

	gotoxy(20, 22);
	printf("1....SAVINGS ACCOUNT");

	gotoxy(20, 24);
	printf("2....CURRENT ACCOUNT");

	gotoxy(20, 26);
	printf("3....CORPORATE ACCOUNT");

	int account_choice;
	printf("\n\nACCOUNT TYPE");
	scanf("%d", &account_choice);

	if (account_choice == 1)
	{
		strcpy(u1.account_type, "Savings");
	}
	else if (account_choice == 2)
	{
		strcpy(u1.account_type, "Current");
	}
	else if (account_choice == 3)
	{
		strcpy(u1.account_type, "Corporate");
	}
	if (account_choice != 1 && account_choice != 2 && account_choice != 3)
	{
		printf("Invalid account type. Please try again.\n");
		exit(0);
	}

	printf("\n\nDATE OF BIRTH..");
	printf("\nDATE-");
	scanf("%d", &u1.date);
	printf("\nMONTH-");
	scanf("%d", &u1.month);
	printf("\nYEAR-");
	scanf("%d", &u1.year);
	if (u1.year > 2006)
	{
		printf("you are underage for creating an account\n");
		exit(0);
	}
	printf("\n\nADHAR NUMBER");
	scanf("%s", u1.adhar_number);
	if (strlen(u1.adhar_number) != 12)
	{
		printf("Invalid Aadhaar number. Please try again.\n");
		exit(0);
	}
	printf("\n\nPHONE NUMBER");
	scanf("%s", u1.contact_number);
	if (strlen(u1.contact_number) != 10)
	{
		printf("Invalid contact  number. Please try again.\n");
		exit(0);
	}
	int temp2;
	printf("press 5 to verify: ");
	scanf("%d", &temp2);
	if (temp2 == 5)
	{
		srand(time(0));

		// Generate and print the OTP
		int otp = generateOTP();
		printf("Your OTP is: %d\n", otp);

		// Optional: Simulate user entering OTP
		int enteredOTP;
		printf("Enter the OTP: ");
		scanf("%d", &enteredOTP);

		// Check if the entered OTP matches
		if (enteredOTP == otp)
		{
			printf("OTP verified successfully!\n");
		}
		else
		{
			printf("Invalid OTP. Please try again.\n");
			exit(0);
		}
	}

	printf("\n\nUSERNAME.. ");
	scanf("%s", &u1.username);

	printf("\n\nPASSWORD..");

	// Read a character from user input
	// Check if the character is not Enter (ASCII 13)
	// Store the character in the password array
	// Set the character to an asterisk for display
	// Print the asterisk instead of the actual character
	// Exit the loop if Enter is pressed

	printf("\nPassword: ");
	int i = 0;
	while (i < PASSWORD_LENGTH - 1)
	{
		ch = getch();
		if (ch == 13)
			break; // Enter key pressed
		password[i++] = ch;
		printf("*");
	}
	password[i] = '\0';

	printf("\nConfirm Password: ");
	int j = 0;
	while (j < PASSWORD_LENGTH - 1)
	{
		ch = getch();
		if (ch == 13)
			break;
		confirmPassword[j++] = ch;
		printf("*");
	}
	confirmPassword[j] = '\0';

	if (strcmp(password, confirmPassword) != 0)
	{
		printf("\nPasswords do not match. Please try again.\n");
		fclose(fp);
		exit(0);
	}
	// Writing to the file
	fwrite(&u1, sizeof(u1), 1, fp);

	// Closing file
	fclose(fp);

	// Calling another function
	// after successful creation
	// of account
	accountcreated();
}

// Successful account creation
void accountcreated(void)
{
	int i;
	char ch;
	system("cls");
	printf(
		"PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	for (i = 0; i < 200; i++)
	{
		i++;
		i--;
		Sleep(0);
	}

	gotoxy(30, 10);

	printf("ACCOUNT CREATED SUCCESSFULLY....");
	gotoxy(0, 20);

	printf("Press enter to login");

	getch();
	login();
}
// Login function to check
// the username of the user
//void login(void)
/*{
	system("cls");

	char username[50];
	char password[50];

	int i, j, k;
	char ch;
	FILE *fp, *fu;
	struct pass u1;
	struct userpass u2;

	// Opening file of
	// user data
	// r: Read mode - the file must exist; it is opened for reading.
	fp = fopen("username.txt", "rb");

	if (fp == NULL)
	{
		printf("ERROR IN OPENING FILE");
	}
	gotoxy(34, 2);
	printf(" ACCOUNT LOGIN ");
	gotoxy(7, 5);
	printf("*"
		   "");

	gotoxy(35, 10);
	printf("==== LOG IN ====\n");

	// Take input
	gotoxy(35, 12);
	printf("USERNAME.. ");
	scanf("%s", username);

	gotoxy(35, 14);
	printf("PASSWORD..");
	// Input the password
	for (i = 0; i < 50; i++)
	{
		ch = getch();
		if (ch != 13)
		{
			password[i] = ch;
			ch = '*';
			printf("%s", ch);
		}

		else
			// press forget password
			// if user forget password
			printf("change password through phone number: ");
		scanf("%d", u1.contact_number);
		if (strlen(u1.contact_number) != 10)
		{
			printf("Invalid contact  number. Please try again.\n");
			exit(0);
		}
		// verify phone number
		int temp1;
		printf("press 1 to verify: ");
		scanf("%d", &temp1);
		if (temp1 == 1)
		{
			// Generate and print the OTP
			int otp = generateOTP();
			printf("Your OTP is: %d\n", otp);

			// Optional: Simulate user entering OTP
			int enteredOTP;
			printf("Enter the OTP: ");
			scanf("%d", &enteredOTP);

			// Check if the entered OTP matches
			if (enteredOTP == otp)
			{
				printf("OTP verified successfully!\n");
			}
			else
			{
				printf("Invalid OTP. Please try again.\n");
				exit(0);
			}
		}

		char confirm_password[50];
		printf("\n\nCONFIRM PASSWORD..");
		scanf("%s", confirm_password);
		if (strcmp(password, confirm_password) != 0)
		{
			printf("Passwords do not match. Try again.");
			exit;
		}

		// now type new password and enter
		// to verify that its you

		// Checking if username
		// exists in the file or not
		while (fread(&u1, sizeof(u1),
					 1, fp))
		{
			if (strcmp(username,
					   u1.username) == 0)
			{
				loginsu();
				display(username);
			}
		}

		// Closing the file
		fclose(fp);
	}
}*/
// Redirect after
// successful login
void login(void)
{
    system("cls");

    char username[50];
    char password[50], enteredPassword[50];
    char ch;
    FILE *fp;
    struct pass u1;

    // Open the user data file
    fp = fopen("username.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR IN OPENING FILE\n");
        return;
    }

    gotoxy(34, 2);
    printf(" ACCOUNT LOGIN ");
    gotoxy(35, 10);
    printf("==== LOG IN ====\n");

    // Take username input
    gotoxy(35, 12);
    printf("USERNAME: ");
    scanf("%s", username);

    // Take password input securely
    gotoxy(35, 14);
    /*printf("PASSWORD: ");
    int i = 0;
    while (i < PASSWORD_LENGTH - 1)
    {
        ch = getch();
        if (ch == 13) // Enter key
            break;
        if (ch == 8 && i > 0) // Backspace
        {
            i--;
            printf("\b \b"); // Erase character
        }
        else
        {
            password[i++] = ch;
            printf("*"); // Mask input
        }
    }
    password[i] = '\0';*/

    // Check if username exists and validate password
    int isValidUser = 0;


    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if (strcmp(username, u1.username) == 0)
        {
            isValidUser = 1;
            printf("\n");
            // Verify password here if stored securely

                loginsu();
                display(username);
                fclose(fp);
                return;

        }
        }


    /*if (!isValidUser)
    {
        printf("\nUsername not found. Try again.\n");
    }*/

    // Close file and return to menu
    fclose(fp);
}
void forgotPassword(void)
{
    char contact[10];
    printf("\nForgot Password? Enter your registered phone number: ");
    scanf("%s", contact);

    if (strlen(contact) != 10)
    {
        printf("Invalid phone number. Please try again.\n");
        return;
    }

    // OTP Verification
    srand(time(0));
    int otp = generateOTP();
    printf("Your OTP is: %d\n", otp);

    int enteredOTP;
    printf("Enter the OTP: ");
    scanf("%d", &enteredOTP);

    if (enteredOTP != otp)
    {
        printf("Invalid OTP. Try again.\n");
        return;
    }
}

    // Allow resetting the password
   /* char newPassword[PASSWORD_LENGTH];
    char confirmPassword[PASSWORD_LENGTH];
    printf("Enter your new password: ");
    scanf("%s", newPassword);
    printf("Confirm your new password: ");
    scanf("%s", confirmPassword);

    if (strcmp(newPassword, confirmPassword) != 0)
    {
        printf("Passwords do not match. Try again.\n");
        return;
    }

    printf("Password reset successful! Please log in with your new password.\n");
}*/

void loginsu(void)
{
	int i;
	FILE *fp;
	struct pass u1;
	system("cls");
	printf("Fetching account details.....\n");
	for (i = 0; i < 20; i++)
	{
		i++;
		i--;
	}

	gotoxy(30, 10);
	printf("LOGIN SUCCESSFUL....");
	gotoxy(0, 20);
	printf("Press enter to continue");

	getch();
}

// Display function to show the
// data of the user on screen
void display(char username1[])
{
	system("cls");
	FILE *fp;
	int choice, i;
	fp = fopen("username.txt", "r");
	struct pass u1;

	if (fp == NULL)
	{
		printf("error in opening file");
	}

	while (fread(&u1, sizeof(u1), 1, fp))
	{
		if (strcmp(username1,
				   u1.username) == 0)
		{
			gotoxy(30, 1);
			printf("WELCOME, %s %s",
				   u1.fname, u1.lname);
			gotoxy(28, 2);
			printf("..........................");
			gotoxy(55, 6);
			printf("==== YOUR ACCOUNT INFO ====");
			gotoxy(55, 8);
			printf("*");
			gotoxy(55, 10);
			printf("NAME..%s %s", u1.fname,
				   u1.lname);

			gotoxy(55, 12);
			printf("FATHER's NAME..%s %s",
				   u1.father_name,
				   u1.lname);

			gotoxy(55, 14);
			printf("MOTHER's NAME..%s",
				   u1.mother_name);

			gotoxy(55, 16);
			printf("ADHAR CARD NUMBER..%s",
				   u1.adhar_number);

			gotoxy(55, 18);
			printf("MOBILE NUMBER..%s",
				   u1.contact_number);

			gotoxy(55, 20);
			printf("DATE OF BIRTH.. %d-%d-%d",
				   u1.date, u1.month, u1.year);

			gotoxy(55, 22);
			printf("ADDRESS..%s", u1.address);

			gotoxy(55, 24);
			printf("ACCOUNT TYPE..%s",
				   u1.account_type);
		}
	}

	fclose(fp);

	gotoxy(0, 6);

	// Menu to perform different
	// actions by user
		printf(" HOME ");
		gotoxy(0, 7);
		printf("");
		gotoxy(0, 9);
		printf(" 1....CHECK BALANCE");
		gotoxy(0, 11);
		printf(" 2....TRANSFER MONEY");
		gotoxy(0, 13);
		printf(" 3....LOG OUT\n\n");
		gotoxy(0, 15);
		printf(" 4....EXIT\n\n");

		printf(" ENTER YOUR CHOICES..");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			checkbalance(username1);
			break;

		case 2:
			transfermoney();
			break;

		case 3:
			logout();
			login();
			break;

		case 4:
			exit(0);
			break;
		}
	}

// Function to transfer
// money from one user to
// another
void transfermoney(void)
{
	int i, j;
	FILE *fm, *fp;
	struct pass u1;
	struct money m1;
	char usernamet[20];
	char usernamep[20];
	system("cls");

	// Opening file in read mode to
	// read user's username
	fp = fopen("username.txt", "r");

	// Creating a another file
	// to write amount along with
	// username to which amount
	// is going to be transferred
	fm = fopen("mon.txt", "a");

	gotoxy(33, 4);
	printf("---- TRANSFER MONEY ----");
	gotoxy(33, 5);
	printf("========================");

	gotoxy(33, 11);
	printf("FROM (your username).. ");
	scanf("%s", &usernamet);

	gotoxy(33, 13);
	printf(" TO (username of person)..");
	scanf("%s", &usernamep);

	// Checking for username if it
	// is present in file or not
	while (fread(&u1, sizeof(u1),
				 1, fp))

	{
		if (strcmp(usernamep,
				   u1.username) == 0)
		{
			strcpy(m1.usernameto,
				   u1.username);
			strcpy(m1.userpersonfrom,
				   usernamet);
		}
	}
	gotoxy(33, 16);

	// Taking amount input
	printf("ENTER THE AMOUNT TO BE TRANSFERRED..");
	scanf("%d", &m1.money1);

	// Writing to the file
	fwrite(&m1, sizeof(m1), 1, fm);

	gotoxy(0, 26);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 28);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 29);
	printf("transferring amount, Please wait..");

	gotoxy(10, 27);
	for (i = 0; i < 70; i++)
	{
		for (j = 0; j < 1200000; j++)
		{
			j++;
			j--;
		}
		printf("*");
	}

	gotoxy(33, 40);
	printf("AMOUNT SUCCESSFULLY TRANSFERRED....");
	getch();

	// Close the files
	fclose(fp);
	fclose(fm);

	// Function to return
	// to the home screen
	display(usernamet);
}

// Function to check balance
// in users account
void checkbalance(char username2[])
{
	system("cls");
	FILE *fm;
	struct money m1;
	char ch;
	int i = 1, summoney = 0;

	// Opening amount file record
	fm = fopen("mon.txt", "r");

	int k = 5, l = 10;
	int m = 30, n = 10;
	int u = 60, v = 10;

	gotoxy(30, 2);
	printf("==== BALANCE DASHBOARD ====");
	gotoxy(30, 3);
	printf("*");
	gotoxy(k, l);
	printf("S no.");
	gotoxy(m, n);
	printf("TRANSACTION ID");
	gotoxy(u, v);
	printf("AMOUNT");

	// Reading username to
	// fetch the correct record
	while (fread(&m1, sizeof(m1),
				 1, fm))
	{
		if (strcmp(username2,
				   m1.usernameto) == 0)
		{
			gotoxy(k, ++l);
			printf("%d", i);
			i++;
			gotoxy(m, ++n);
			printf("%s", m1.userpersonfrom);

			gotoxy(u, ++v);
			printf("%d", m1.money1);
			// Adding and
			// finding total money
			summoney = summoney + m1.money1;
		}
	}

	gotoxy(80, 10);
	printf("TOTAL AMOUNT");

	gotoxy(80, 12);
	printf("%d", summoney);

	getch();

	// Closing file after
	// reading it
	fclose(fm);
	display(username2);
}

// Logout function to bring
// user to the login screen
void logout(void)
{
	int i, j;
	system("cls");
	printf("please wait, logging out");

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 25000000; j++)
		{
			i++;
			i--;
		}
		printf(".");
	}

	gotoxy(30, 10);
	printf("Sign out successfully..\n");

	gotoxy(0, 20);
	printf("press any key to continue..");

	getch();
}
