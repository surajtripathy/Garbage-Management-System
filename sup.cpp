#include<iostream>
#include "supervisor.h"
#include <cstring>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include "add_delete.h"
#include "display.h"
using namespace std;
using namespace supervisor;
using namespace mainpage;
string *users=new string;
string *passwd=new string;
class user
{
public:
int usercheck(string *user,string *users)
{
       if (users->find(*user) != string::npos)
        return 2;
}
int passcheck(string *pass,string *passwd)
{
    if(passwd->find(*pass)!= string::npos)
        return 2;
}
virtual int login()=0;
};
class supervis_content:public user
{
public:
    int login()
{
ifstream *fin=new ifstream;
fin->open("login.csv");
    int i=0,j,k;
    while (!fin->eof())
	{
		*fin >> *users >> *passwd;
		 //This represents the number of lines we could extract from the database
	}

	string *user=new string;
	string *pass=new string;
	*user=entryuser();
	j=usercheck(user,users);
	if(j==2){
	*pass=entrypass();
	k=passcheck(pass,passwd);
	if(k==2){
        cout<<"Login successful!"<<endl;
        system("cls");
        return 2;}
    else{
        cout<<"Login Failed"<<endl;
	return 0;}}
	else{
        cout<<"Please enter a valid username"<<endl;
        return 0;
    fin->close();
    delete user;
    delete pass;
    delete fin;
	}
}
    void content()
    {
    cout<<"Press 1 to Update/change details of garbage collection\nPress 2 to Only view details\nPress 3 to Add vehicle details\nPress anything else to exit"<<endl;
    int i;
    cin>>i;
    try{
    switch(i)
    {
    case 1:
        {
            cout<<"Enter the number of data you want to add"<<endl;
            int j,i;
            cin>>i;
            string str,str1,str2,str3,str4,str5,str6;
            fstream *fi=new fstream;
        fi->open("dumb.csv",ios::app);
        for(j=1;j<=i;j++){
        cout<<"Enter the vehicle number"<<endl;
        cin>>str;
        *fi<<str<<',';
        cout<<"Enter the Date of loading"<<endl;
        cin>>str1;
        *fi<<str1<<',';
        cout<<"Enter the time of loading "<<endl;
        cin>>str2;
        *fi<<str2<<',';
        cout<<"Enter the place of loading "<<endl;
        cin>>str3;
        *fi<<str3<<',';
        cout<<"Enter the date of  unloading "<<endl;
        cin>>str4;
        *fi<<str4<<',';
        cout<<"Enter the time of unloading "<<endl;
        cin>>str5;
        *fi<<str5<<',';
        cout<<"Enter the place of unloading "<<endl;
        cin>>str6;
        *fi<<str6<<','<<'\n';
            }
        fi->close();
        delete fi;
        break;
        }
    case 2:
        {
        fstream *fi=new fstream;
        fi->open("vehicle.csv");
        char str[1000];
        int i,j=1,k=0;
        char ch;
        fi->get(ch);
        str[0]=ch;
        while(!fi->eof())
        {
            fi->get(ch);
            str[j]=ch;
            j++;
        }
        for(i=0;i<j;i++)
        {
            if(str[i]==',')
            {
                cout<<' ';
                i++;
            }
             cout<<str[i];
        }
        fi->close();
        delete fi;
        break;
    }
    case 3:
        {
            fstream *fi=new fstream;
            fi->open("vehicle.csv",ios::app);
            cout<<"Enter the number of data you want to add"<<endl;
            int j,i;
            cin>>i;
            string s,s1,s2;
            for(j=1;j<=i;j++){
                cout<<"Enter the vehicle number"<<endl;
                cin>>s;
                *fi<<s<<',';
                cout<<"Enter the capacity of the vehicle"<<endl;
                cin>>s1;
                *fi<<s1<<',';
                cout<<"Enter the driver name of the vehicle"<<endl;
                cin>>s2;
                *fi<<s2<<','<<'\n';
            }
            fi->close();
            delete fi;
            break;
        }
    default:
        {
         throw 2;
        }
    }}
    catch(...)
    {
        cout<<"PROGRAM TERMINATED"<<endl;
        exit(0);
    }

    }
};
class citizen
{
public:
    friend void content_cust();
};
void content_cust()
    {
    cout<<"Press 1 to View the registration,capacity and Driver name\nPress 2 To view the Details of Time and Place\nPress anything else to terminate "<<endl;
    int o;
    cin>>o;
    try{
    switch(o)
    {
    case 1:
        {
        fstream *fi=new fstream;
        fi->open("vehicle.csv");
        char str[10000];
        int i,j=1,k=0;
        char ch;
        fi->get(ch);
        str[0]=ch;
        while(!fi->eof())
        {
            fi->get(ch);
            str[j]=ch;
            j++;
        }

        for(i=0;i<j;i++)
        {
            if(str[i]==',')
            {
                cout<<' ';
                i++;
            }
             cout<<str[i];
        }
        fi->close();
        delete fi;{
        break;}
    }
    case 2:
        {
        fstream *fi=new fstream;
        fi->open("dumb.csv");
        char str[1000];
        int i,j=1,k=0;
        char ch;
        fi->get(ch);
        str[0]=ch;
        while(!fi->eof())
        {
            fi->get(ch);
            str[j]=ch;
            j++;
        }

        for(i=0;i<j;i++)
        {
            if(str[i]==',')
            {
                cout<<' ';
                i++;
            }
             cout<<str[i];
        }
        fi->close();
        delete fi;
        break;
    }
    default:
        {
        throw 2;
    }
    }
    }
    catch(...)
    {
        cout<<"PROGRAM TERMINATED"<<endl;
        exit(0);
    }
    }
class manager:public supervis_content
{
public:
    int login()
    {
        cout<<"Enter your username"<<endl;
        string *user=new string;
        string *pass=new string;
        cin>>*user;
        cout<<"Enter your password"<<endl;
        cin>>*pass;
        if(user->compare("ADMIN")==0)
        {
            if(pass->compare("PASSWORD")==0)
            {
            return 2;
            }
        }
        else
        {
            cout<<"Invalid login"<<endl;
        }
    }
    void content_manger()
    {
    cout<<"Press 1 To Update Details of Garbage Collection\nPress 2 To View Details Only\nPress 3 To Add Vehicle Details\nPress 4 To update Supervisor Details\nPress 5 To Clear Data of Files\nPress anything else to exit"<<endl;
    int i;
    cin>>i;
    try{
    switch(i)
    {
    case 1:
        {
            cout<<"Enter the number of data you want to add"<<endl;
            int j,i;
            cin>>i;
            string str,str1,str2,str3,str4,str5,str6;
            fstream *fi=new fstream;
            fi->open("dumb.csv",ios::app);
            for(j=1;j<=i;j++){
            cout<<"Enter the vehicle number"<<endl;
            cin>>str;
            *fi<<str<<',';
            cout<<"Enter the Date of loading"<<endl;
            cin>>str1;
            *fi<<str1<<',';
            cout<<"Enter the time of loading "<<endl;
            cin>>str2;
            *fi<<str2<<',';
            cout<<"Enter the place of loading "<<endl;
            cin>>str3;
            *fi<<str3<<',';
            cout<<"Enter the date of  unloading "<<endl;
            cin>>str4;
            *fi<<str4<<',';
            cout<<"Enter the time of unloading "<<endl;
            cin>>str5;
            *fi<<str5<<',';
            cout<<"Enter the place of unloading "<<endl;
            cin>>str6;
            *fi<<str6<<','<<'\n';
            }
            fi->close();
            delete fi;
        break;
        }
    case 2:
        {
        content_cust();
        break;
    }
    case 3:
        {
            fstream *fi=new fstream;
            fi->open("vehicle.csv",ios::app);
            cout<<"Enter the number of data you want to add"<<endl;
            int j,i;
            cin>>i;
            string s,s1,s2;
            for(j=1;j<=i;j++){
                cout<<"Enter the vehicle number"<<endl;
                cin>>s;
                *fi<<s<<',';
                cout<<"Enter the capacity of the vehicle"<<endl;
                cin>>s1;
                *fi<<s1<<',';
                cout<<"Enter the driver name of the vehicle"<<endl;
                cin>>s2;
                *fi<<s2<<','<<'\n';
            }
            fi->close();
            delete fi;
            break;
        }
    case 4:
        {
            cout<<"Press 1 To only view the supervisor user-name and password \nPress 2 To add the supervisor password of individual username"<<endl;
            int a=0,b=0,i;
            cin>>i;
            switch(i)
            {
                char ch;
                char user[40];
                char user_pass[40];
                case 1:
                {
                    fstream *fi=new fstream;
                    int count=0;
                    fi->open("login.csv");
                    while(!fi->eof())
                    {

                            fi->get(ch);
                            if(ch=='\n')
                            {count++;}
                            if(ch!=',' && count==0)
                            {
                                user[a]=ch;
                                a++;
                            }
                            if(count==1)
                            {
                             if(ch!=',')
                             {
                                 user_pass[b]=ch;

                             }
                             b++;
                            }
                            if(ch==',')
                            {
                                user[a]=' ';
                                a++;
                            }
                    }
                    cout<<"The usernames are -:"<<endl;
                    for(int i=0;i<a;i++)
                    {
                        cout<<user[i];
                    }
                    cout<<endl;
                    cout<<"The password of respective usernames are :-";
                    for(int i=0;i<b;i++)
                    {
                        cout<<user_pass[i];
                    }
                    cout<<endl;
                    fi->close();
                    delete fi;
                    break;
                }
                case 2:
                    {
                    fstream *fi=new fstream;
                    fi->open("login.csv",ios::app);
                    cout<<"Enter the username you want to add a password to :-"<<endl;
                    string *com=new string;
                    string *s1=new string;
                    cin>>*com;
                    if(com->compare("Suraj")==0)
                    {
                    cout<<"Enter your new password"<<endl;
                    cin>>*s1;
                    *fi<<s1<<',';
                    }
                    if(com->compare("Natasha")==0)
                    {
                    cout<<"Enter your new password"<<endl;
                    cin>>*s1;
                    *fi<<','<<s1<<',';
                    }
                    if(com->compare("Ayush")==0)
                    {
                    cout<<"Enter your new password"<<endl;
                    cin>>*s1;
                    *fi<<','<<','<<s1<<',';
                    }
                    if(com->compare("Asutosh")==0)
                    {
                    cout<<"Enter your new password"<<endl;
                    cin>>*s1;
                    *fi<<','<<','<<','<<s1<<'\n';
                    }
                    fi->close();
                    delete fi;
                    delete com;
                    delete s1;
                    break;
                    }
                default:
                    {
                        break;
                    }
            }
         break;
        }
                case 5:
                    {
                        using namespace add_delete;
                        del();
                    }
                default:
                    {
                        throw 2;
                    }
    }
    }
    catch(...)
    {
        cout<<"PROGRAM TERMINATED"<<endl;
        exit(0);
    }
    }

};
int main()
{
    disp();
    char a;
    int i;
    cout<<"Press'A' FOR SUPERVISOR\nPress'B' FOR CITIZEN\nPress'Z' FOR MANAGER\nPress'C' TO EXIT "<<endl;
    a=getch();
    user *u;
    supervis_content s;
    citizen *c=new citizen;
    manager *m=new manager;
    u=&s;
    if(a=='A')
    {
    i=u->login();
    while(a!='C')
    {
    if(i==2)
    {
    s.content();
    }}}
    else if(a=='B')
    {
    while(a!='C'){
    content_cust();
    }}
    else if(a=='Z'){
            int i;
                i=m->login();
                while(a!='C'){
            if(i==2)
            {
                m->content_manger();
            }
            }
    }
    delete c;
    delete m;
return 0;
}
