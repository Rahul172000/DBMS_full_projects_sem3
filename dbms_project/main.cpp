/*#include <iostream>


using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}*/

#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <string>
using namespace std;

void display()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    int ghg=1;
    bool resss=false;
    /*if (conn)
        cout<< "Connection object OK" <<conn<< endl;
    else
        cout<< "Connection object Problem!" << mysql_error(conn) << endl;*/
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
    if (conn)
        {
        //cout<< "Connection to Database done !!!" << conn <<endl;
        qstate = mysql_query(conn, "select * from student");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< "Student id  :"<< row[1] << " "
                    << "Name :"<< row[0]<<" "
                    << "AGE:"<<row[2]<<endl;
                    ghg++;
                    if(ghg==6)
                    {
                        cout<<endl<<"Press Enter key to continue"<<endl;
                        if(resss==false)
                        {std::cin.ignore();resss=true;}//TO IGNORE HE BUFER PART IN FIRST RUN
                        std::cin.get();
                        ghg=1;
                    }
            }
        }
    else
    {
       cout<< "Query Execution Problem!" << mysql_error(conn) << endl;
    }
        }

    else
    {
     cout<< "Connection object Problem!" << mysql_error(conn) << endl;
    }

}

void insertdata()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    /*if (conn)
        cout<< "Connection object OK" <<conn<< endl;
    else
        cout<< "Connection object Problem!" << mysql_error(conn) << endl;*/
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
    cout<<"\nEnter the student-id ";
    string name,id,age;
    cin>>id;
    cout<<"\nEnter the name ";
    cin>>name;
    cout<<"\nEnter the age ";
    cin>>age;
    string query="insert into student(name,id,age) values('"+name+"'"+",'"+id+"','"+age+"');";
    const char*q=query.c_str();
    qstate=mysql_query(conn,q);
    cout<<endl<<"INSRTED";

}

int main()
{

    int choice;
    cout<<"1.ENTER\n2.DISPLAY\n3.QUIT\n";
    cin>>choice;
    while(choice!=3)
    {
        if(choice==1)
        {
            insertdata();
        }
        else if(choice==2)
        {
            display();
        }
        else if(choice==3)
        {
            break;
        }
        cout<<endl<<endl<<"1.ENTER\n2.DISPLAY\n3.QUIT\n";
        cin>>choice;
    }




        return 0;
}

