#include<iostream>	//used to invoke the commonly used functions like cout,cin 
#include<conio.h>	//used to provide console input/output
#include<string.h>	//used for string handling
#include<windows.h>	//used for moving cursor in this program
#include<time.h>	//for current time and date 
#include<fstream>	//file input and output
#include<iomanip>	//Header providing parametric manipulators
using namespace std;
int count = 0,count1=0,temp=0,temp1=0;
//for cursor in co-ordinate 
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//for Sleep 
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void messagebox()
{
	gotoxy(40,8);
	cout<<"\xc9";
	for(int i=1;i<=35;i++)
	{
		cout<<"\xcd";
	}
	gotoxy(75,8);
	cout<<"\xbb";
	for(int i=1;i<=15;i++)
	{
		gotoxy(40,8+i);
		cout<<"\xba";
		gotoxy(75,8+i);
		cout<<"\xba";
	}
	gotoxy(40,24);
    cout<<"\xc8";
	for(int i=1;i<=34;i++)
	{
		cout<<"\xcd";
	}
	cout<<"\xbc";
}
//box drawing function in login and register page
void box_draw()
{
	gotoxy(50,8);
	cout<<"\xc9";
	for(int i=1;i<=20;i++)
	{
		cout<<"\xcd";
	}
	gotoxy(70,8);
	cout<<"\xbb";
	for(int i=1;i<=1;i++)
	{
		gotoxy(50,8+i);
		cout<<"\xba";
		gotoxy(70,8+i);
		cout<<"\xba";
	}
	gotoxy(50,10);
    cout<<"\xc8";
	for(int i=1;i<=19;i++)
	{
		cout<<"\xcd";
	}
	cout<<"\xbc";
}
//declaring class
class c_mail
{
	private:
	string firstname,lastname,regUsername,logUsername,msgtext,reg_pass,log_pass,phone,msgUsername;
	char name[20];
	public:
		void Loading();
		void mainMenu();
		void login();
		void Register();
		void Reg_rec_file();
		void login_validation();
		void message();
		void messageValidation();
		void home();
		void back();
		void messageLog();
		void clearLog();
		void ViewTeam();
		void Delete();
		//for user input login validation 
		void username_Validation(string Username);
		void password_Validation(string Password);
	};
//starting loading function
void c_mail::Loading()
{
	char n=177;
	gotoxy(53,14);
	cout<<"Loading...";
	gotoxy(41,15);
	for(int i=0;i<35;i++)
	{
		delay(150);
		cout<<n;
	}
}

void c_mail::mainMenu()
{
	system("cls");
	char n=177;
	gotoxy(40,9);
	for(int i=0;i<5;i++)
	{
		cout<<n;
	}
	cout<<"  Welcome to our C-mail Service  ";
	for(int i=0;i<5;i++)
	{
		cout<<n;
	}
	gotoxy(42,12);
	cout<<"\xc9";
	for(int i=1;i<=38;i++)
	{
		cout<<"\xcd";
	}
	gotoxy(80,12);
	cout<<"\xbb";
	for(int i=1;i<=10;i++)
	{
	gotoxy(42,12+i);
	cout<<"\xba";
	gotoxy(80,12+i);
	cout<<"\xba";
    }
    gotoxy(42,23);
    cout<<"\xc8";
	for(int i=1;i<=37;i++)
	{
		cout<<"\xcd";
	}
	cout<<"\xbc";
	gotoxy(35,25);
	cout<<">> If you are new to our service, Please register first.";
	gotoxy(35,26);
	cout<<">> Already a member\? You can directly Login.";
	gotoxy(50,16);
	cout<<"LOG IN";
	gotoxy(50,19);
	cout<<"REGISTER";
	gotoxy(82,14);
	cout<<"'L' for LOGIN";
	gotoxy(82,16);
	cout<<"'R' for REGISTER";
	gotoxy(82,18);
	cout<<"'T' for viewing Developer TEAMS";
	char c = toupper(getch());
	switch(c)
	{
		case 'L':
			login();
			break;
		case 'R':
			Register();
			break;
		case 'T':
			ViewTeam();
			break;
		default:
			mainMenu();
			break;
	}

	
}
//login page function
void c_mail::login()
{
	system("cls");
	box_draw();
	gotoxy(55,9);
	cout<<"LOG-IN PAGE";
	//second box
	gotoxy(41,12);
	cout<<"\xc9";
	for(int i=1;i<=39;i++)
	{
		cout<<"\xcd";
	}
	gotoxy(80,12);
	cout<<"\xbb";
	for(int i=1;i<=10;i++)
	{
	gotoxy(41,12+i);
	cout<<"\xba";
	gotoxy(80,12+i);
	cout<<"\xba";
    }
    gotoxy(41,23);
    cout<<"\xc8";
	for(int i=1;i<=38;i++)
	{
		cout<<"\xcd";
	}
	cout<<"\xbc";
	gotoxy(48,16);
	cout<<"Username :";
	gotoxy(48,18);
	cout<<"Password :";
	gotoxy(60,16);
	cin>>logUsername;
	username_Validation(logUsername);
	if(temp==0)
	{
		gotoxy(82,16);
		cout<<"Username doesn't exists.";
		getch();
		exit(4);
	}
	gotoxy(60,18);
	int ch,n=0;
	do
    {
		ch = getch();
       	if(ch!=8&&isprint(ch))
        {
            cout<<"*";
            name[n++] = ch;
        }
       	if(ch==8&&n)
        {
        	name[n--] = '\0';
            cout<<"\b \b";
    	}
    }while( ch != 13 );
	log_pass = name;
	password_Validation(log_pass);
	if(temp1==0)
	{
		gotoxy(82,18);
		cout<<"Invalid Password.";
		getch();
		exit(1);
	}
	login_validation();
	getch();
	
}

void c_mail::Register()
{
	
	system("cls");
	int m=0,temp2=0;
	string user_,username[15];
	ifstream userfile;
	userfile.open("Username.txt");
	while(getline(userfile,user_))
	{
		username[m]=user_;
		m++;
	}
	box_draw();
	gotoxy(54,9);
	cout<<"REGISTER PAGE";
	//second box
	gotoxy(39,12);
	cout<<"\xc9";
	for(int i=1;i<=55;i++)
	{
		cout<<"\xcd";
	}
	gotoxy(95,12);
	cout<<"\xbb";
	for(int i=1;i<=10;i++)
	{
	gotoxy(39,12+i);
	cout<<"\xba";
	gotoxy(95,12+i);
	cout<<"\xba";
    }
    gotoxy(39,23);
    cout<<"\xc8";
	for(int i=1;i<=55;i++)
	{
		cout<<"\xcd";
	}
	cout<<"\xbc";
	gotoxy(42,24);
	cout<<"Information:";
	gotoxy(41,25);
	cout<<">> Username should be characters only.";
	gotoxy(41,26);
	cout<<">> Password should be characters only.";
	//Entity
	gotoxy(42,14);
	cout<<"First Name :";
	gotoxy(68,14);
	cout<<"Last Name :";
	gotoxy(42,16);
	cout<<"Phone      :";
	gotoxy(42,18);
	cout<<"Username   :";
	gotoxy(42,20);
	cout<<"Password   :";
	//Input Value
	gotoxy(55,14);
	cin>>firstname;
	gotoxy(80,14);
	cin>>lastname;
	gotoxy(55,16);
	cin>>phone;
	gotoxy(55,18);
	cin>>regUsername;
	for(int k=0;k<m;k++)
	{
		if(regUsername.compare(username[k])==0)
		{
			temp2=1;
		}
	}
	if(temp2==1)
	{
		system("cls");
		gotoxy(40,9);
		cout<<"Username already exists. Please try another";
		getch();
		Register();
	}
	gotoxy(55,20);
	cin>>reg_pass;
	Reg_rec_file();
	system("cls");
	gotoxy(40,11);
	cout<<"!!! Registered Successfully !!!";
	gotoxy(45,13);
	cout<<"Do you want to login\?";
	gotoxy(48,15);
	cout<<"1. Yes"<<"\t"<<"2. No";
	int ch = getch();
	switch(ch)
		{
			case '1':
				login();
				break;
			default:
				mainMenu();
				break;	
		}
	getch();
}

//Function for viewing developers team
void c_mail::ViewTeam()
{
	system("cls");
	string view_team;
	ifstream view;
	view.open("TEAMS.txt");
	int b=0;
	while(getline(view,view_team))
		{
		gotoxy(10,5+b);
		cout<<view_team;
		b++;
		}
	getch();
	mainMenu();
}
// message deleting function
void c_mail::Delete()
{
	system("cls");
	gotoxy(35,8);
	cout<<"\xc9";
	for(int i=1;i<=38;i++)
	{
		cout<<"\xcd";
	}
	gotoxy(73,8);
	cout<<"\xbb";
	for(int i=1;i<=30;i++)
	{
	gotoxy(35,8+i);
	cout<<"\xba";
	gotoxy(73,8+i);
	cout<<"\xba";
    }
	ofstream Delete;
	ifstream del;
	char showmsg;
	ifstream Nfile;
	Nfile.open((logUsername+"-message").c_str());
	Nfile>>showmsg;
	del.open((logUsername+"-message").c_str());
	if(!del||(showmsg=='\0'))
	{
	gotoxy(37,12);
	cout<<"You don't have any message to delete";
	}
	else
	{
	Delete.open((logUsername+"-message").c_str());
	Delete<<"";
	gotoxy(37,12);
	cout<<"All message deleted successfully";
	}
	back();
}

void c_mail::back()
{
	gotoxy(80,11);
	cout<<"Press 'B' to go back";
	gotoxy(80,13);
	cout<<"Press any other key to exit.";
	switch(getch())
		{
			case 'b':
				home();
				break;
			default:	
				exit(0);	
		}
}

//Home page after login
void c_mail::home()
{
	system("cls");
	gotoxy(41,12);
	cout<<"\xc9";
	for(int i=1;i<=39;i++)
	{
		cout<<"\xcd";
	}
	gotoxy(80,12);
	cout<<"\xbb";
	for(int i=1;i<=10;i++)
	{
	gotoxy(41,12+i);
	cout<<"\xba";
	gotoxy(80,12+i);
	cout<<"\xba";
    }
    gotoxy(41,23);
    cout<<"\xc8";
	for(int i=1;i<=38;i++)
	{
		cout<<"\xcd";
	}
	cout<<"\xbc";
	gotoxy(43,7);
	cout<<"LOGGED IN !!!SUCCESSFULLY!!!";
	gotoxy(43,8);
	cout<<"____________________________";
	gotoxy(43,10);
	cout<<"Welcome, "<<logUsername;
	gotoxy(43,14);
	cout<<"1. For Showing message.";
	gotoxy(43,15);
	cout<<"2. For Sending message.";
	gotoxy(43,16);
	cout<<"3. For Deleting all receiced message.";
	gotoxy(43,17);
	cout<<"4. For Viewing sent Message Log";
	gotoxy(43,18);
	cout<<"5. For Clearing Log";
	gotoxy(43,19);
	cout<<"6. For Log Out";
	switch(getch())
	{
		case '1':
			messageValidation();
			break;
		case '2':
			message();
			break;
		case '3':
			Delete();
			break;
		case '4':
			messageLog();
			break;
		case '5':
			clearLog();
			break;
		case '6':
			system("cls");
			gotoxy(42,10);
			cout<<"Logging Out";
			for(int i=0;i<=10;i++)
			{
			gotoxy(54+i,10);
			delay(150);
			cout<<".";
			}
			mainMenu();
			break;
		default:
			home();
			break;
	}
}
// clearing log
void c_mail::clearLog()
{
	system("cls");
	gotoxy(35,8);
	cout<<"\xc9";
	for(int i=1;i<=38;i++)
	{
		cout<<"\xcd";
	}
	gotoxy(73,8);
	cout<<"\xbb";
	for(int i=1;i<=30;i++)
	{
	gotoxy(35,8+i);
	cout<<"\xba";
	gotoxy(73,8+i);
	cout<<"\xba";
    }
	ofstream Delete;
	ifstream del;
	char showmsg;
	ifstream Nfile;
	Nfile.open((logUsername+"-log").c_str());
	Nfile>>showmsg;
	del.open((logUsername+"-log").c_str());
	if(!del||(showmsg=='\0'))
	{
	gotoxy(37,12);
	cout<<"No message in the log.";
	}
	else
	{
	Delete.open((logUsername+"-log").c_str());
	Delete<<"";
	gotoxy(37,12);
	cout<<"All log cleared successfully";
	}
	back();
}

//Function for showing message
void c_mail::messageValidation()
{
	system("cls");
	gotoxy(35,8);
	cout<<"\xc9";
	for(int i=1;i<=38;i++)
	{
		cout<<"\xcd";
	}
	gotoxy(73,8);
	cout<<"\xbb";
	for(int i=1;i<=30;i++)
	{
	gotoxy(35,8+i);
	cout<<"\xba";
	gotoxy(73,8+i);
	cout<<"\xba";
    }
	string showmsg;
	char text;
	ifstream Nfile,Kfile;
	Nfile.open((logUsername+"-message").c_str());
	Kfile.open((logUsername+"-message").c_str());
	int k=0;
	Kfile>>text;
	if(!Nfile&&!Kfile)
	{
		gotoxy(44,15);
		cout<<"No message received yet.!!!";
	}
	else if(text=='\0')
	{
	gotoxy(44,15);
	cout<<"No Messages.";
	}
	else
	{
		while(getline(Nfile,showmsg))
		{
		gotoxy(37,12+k);
		cout<<showmsg;
		k++;
		}
	}
	Nfile.close();
	gotoxy(80,10);
	cout<<"Press 'B' to go back";
	gotoxy(80,12);
	cout<<"Press 'R' to refresh";
	gotoxy(80,14);
	cout<<"Press any other key to exit.";
	switch(getch())
		{
			case 'b':
				home();
				break;
			case 'r':
				messageValidation();
				break;
			default:	
				exit(0);	
		}
}


//username validation
void c_mail::username_Validation(string Username)
{
	int m=0;
	temp=0;
	string user,username[15];
	ifstream userfile;
	userfile.open("Username.txt");
	while(getline(userfile,user))
	{
		username[m]=user;
		m++;
	}
	for(int k=0;k<m;k++)
	{
		if(Username.compare(username[k])==0)
		{
			temp=1;
			break;
		}
	}

}


//password validation
void c_mail::password_Validation(string Password)
{
	int n=0;
	temp1=0;
	string pass,password[15];
	ifstream passfile;
	passfile.open("Password.txt");
	while(getline(passfile,pass))
	{
		password[n]=pass;
		n++;
	}
	for(int k=0;k<n;k++)
	{
		if(Password.compare(password[k])==0)
		{
			temp1=1;
			break;
		}
	}
	
}

//login function 
void c_mail::login_validation()
{
	system("cls");
	string password;
	string username;
	ifstream Lfile;
	ifstream Mfile;
	Lfile.open("Username.txt");
	Mfile.open("Password.txt");
	if(!Lfile||!Mfile)
	{
		cout<<"Register first to login";
	}
	else
	{
	while(getline(Lfile,username))
		{
			if(logUsername.compare(username)==0)
			{	
				while(getline(Mfile,password))
				{
					if(log_pass.compare(password)==0&&count==count1)
					{
						system("cls");
						gotoxy(42,10);
						cout<<"Logging in";
						for(int i=0;i<=15;i++)
						{
							gotoxy(54+i,10);
							delay(150);
							cout<<".";
						}
						home();
						break;
					}
					count1++;
				}
			}
			count++;	
		}
		Mfile.close();
		Lfile.close();
	}
}

//Writing in REG entries file, username file & password file
void c_mail::Reg_rec_file()
{
	ofstream myfile,Ufile,Pfile;
	myfile.open("REG-Entries.txt",ios::app);
	Ufile.open("Username.txt",ios::app);
	Pfile.open("Password.txt",ios::app);
	myfile<<firstname<<" "<<lastname<<"\t"<<regUsername<<"\t"<<phone<<endl;
	Ufile<<regUsername<<endl;
	Pfile<<reg_pass<<endl;
}

//for viewing message log
void c_mail::messageLog()
{
	system("cls");
	gotoxy(35,8);
	cout<<"\xc9";
	for(int i=1;i<=38;i++)
	{
		cout<<"\xcd";
	}
	gotoxy(73,8);
	cout<<"\xbb";
	for(int i=1;i<=30;i++)
	{
	gotoxy(35,8+i);
	cout<<"\xba";
	gotoxy(73,8+i);
	cout<<"\xba";
    }
	string showmsg;
	ifstream Nfile;
	Nfile.open((logUsername+"-log").c_str());
	int k=0;
	if(!Nfile)
	{
		gotoxy(38,15);
		cout<<"You haven't send any message yet.!";
	}
	else
	{
		while(getline(Nfile,showmsg))
		{
		gotoxy(37,12+k);
		cout<<showmsg;
		k++;
		}
	}
	Nfile.close();
	gotoxy(80,10);
	cout<<"Press 'B' to go back";
	gotoxy(80,12);
	cout<<"Press 'R' to refresh";
	gotoxy(80,14);
	cout<<"Press any other key to exit.";
	switch(getch())
		{
			case 'b':
				home();
				break;
			case 'r':
				messageValidation();
				break;
			default:	
				exit(0);	
		}
	
}

//sending message function
void c_mail::message()
{
	system("cls");
	messagebox();
	time_t t;
	time(&t);
	string times = ctime(&t);
	gotoxy(40,4);
	cout<<"Send To (Username):";
	gotoxy(40,7);
	cout<<"Message Text Below";
	gotoxy(61,4);
	cin>>msgUsername;
	string receiver;
	ofstream mymessage,mlog;
	ifstream Rfile;
	Rfile.open("Username.txt");
	mlog.open((logUsername+"-log").c_str(),ios::app);
		while(getline(Rfile,receiver))
			{
				if(msgUsername.compare(receiver)==0&&msgUsername.compare(logUsername)!=0)
				{
					mymessage.open((msgUsername+"-message").c_str(),ios::app);
					gotoxy(43,9);
					cin>>msgtext;
					mymessage<<"FROM : "<<logUsername<<endl;
					mymessage<<"MESSAGE:"<<endl<<msgtext<<endl<<"RECEIVED"<<endl<<times<<endl;
					mlog<<"To: "<<msgUsername<<endl<<"MESSAGE:"<<endl<<msgtext<<endl;
					system("cls");
					gotoxy(40,8);
					cout<<"Message sent successfully to "<<msgUsername;
					back();
					break;
				}
			}
	}


int main()
{
	c_mail C;
	C.Loading();
	C.mainMenu();
	getch();
	return 0;
}

