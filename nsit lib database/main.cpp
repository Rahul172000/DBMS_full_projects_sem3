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
using namespace std;

void printstudents()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);

    if (conn)
        {
        qstate = mysql_query(conn, "SELECT * FROM `student(1st oct)`;");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< "Student id  :"<< row[0] << "\n"
                    << "Student Name :"<< row[1]<<"\n"
                    << "Phone number :"<<row[2]<<endl<<endl;
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

void insertstudent()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
    string sid,sname,phone_num;
    cout<<"\nEnter the student-id ";
    cin>>sid;
    cout<<"\nEnter the student-name ";
    cin>>sname;
    cout<<"\nEnter the phone number ";
    cin>>phone_num;
    string query="insert into `student(1st oct)`(`id`,`name`,`number`) values('"+sid+"','"+sname+"','"+phone_num+"');";
    cout<<query;
    const char*q=query.c_str();
    qstate=mysql_query(conn,q);

    cout<<endl<<"INSRTED";

}

void insertbook()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
    string bid,bname,bcourse;
    cout<<"\nEnter the book-id ";
    cin>>bid;
    cout<<"Enter the book name ";
    cin>>bname;
    cout<<"Enter the related course ";
    cin>>bcourse;
    string query="insert into books(id,name,course) values('"+bid+"','"+bname+"','"+bcourse+"');";
    cout<<query;
    const char*q=query.c_str();
    qstate=mysql_query(conn,q);

    cout<<endl<<"INSRTED";

}

void insertissuea()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
    string bid,sid,issuedate,returndate,returned,query;
    cout<<"\nEnter the book-id ";
    cin>>bid;
    cout<<"\nEnter the student id ";
    cin>>sid;
    cout<<"\nEnter the issue date(YYYY-MM-DD) ";
    cin>>issuedate;
    cout<<"\nIts returned(true or false) ";
    cin>>returned;
    if(returned=="true")
    {
        cout<<"\nEnter the return date ";
        cin>>returndate;
        query="INSERT INTO `issues`(`sid`, `bid`, `issue_date`, `returned`, `return_date`) VALUES('"+sid+"','"+bid+"','"+issuedate+"','"+"1"+"','"+returndate+"');";
    }
    else
    {
        query="INSERT INTO `issues`(`sid`, `bid`, `issue_date`, `returned`, `return_date`) VALUES('"+sid+"','"+bid+"','"+issuedate+"','"+"0"+"','"+"NULL"+"');";
    }
    cout<<query;
    const char*q=query.c_str();
    qstate=mysql_query(conn,q);

    cout<<endl<<"INSRTED";

}

void printbooks()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
    if (conn)
        {
        qstate = mysql_query(conn, "SELECT * FROM `books`;");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< "Book id  :"<< row[0] << "\n"
                    << "Book Name :"<< row[1]<<"\n"
                    << "Course related :"<<row[2]<<endl<<endl;
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

void printissues()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);

    if (conn)
        {
        qstate = mysql_query(conn, "SELECT `student(1st oct)`.`name`,books.name,issues.issue_date,issues.return_date,issues.returned from `student(1st oct)`,books,issues WHERE issues.sid=`student(1st oct)`.`id` AND issues.bid=books.id;");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< "Student name  :"<< row[0] << "\n"
                    << "Book name :"<< row[1]<<"\n"
                    << "Issue date :"<<row[2]<<"\n"
                    << "Returned :"<<row[4]<<"\n"
                    << "Return date :"<<row[3]<<endl<<endl;
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

void returnbook()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
    string returndate,sid,bid;
    cout<<"\nEnter the student id ";cin>>sid;
    cout<<"\nEnter the book id ";cin>>bid;
    cout<<"\nEnter the return date (YYYY-MM-DD) ";cin>>returndate;
    if (conn)
    {
        string query="UPDATE issues SET `returned`='1',`return_date`='"+returndate+"' WHERE sid="+sid+" AND bid="+bid+";";
        const char*q=query.c_str();
        qstate = mysql_query(conn,q);
        cout<<"\nUPDATED";
    }
    else
    {
     cout<< "Connection object Problem!" << mysql_error(conn) << endl;
    }
}

int main()
{
    int op;
    while(true)
    {
        cout<<"\n1.Insert book\n2.Insert student\n3.Insert issue\n4.Print books\n5.Print students\n6.Print issued books\n7.Return book\n";
        cin>>op;
        if(op==1){insertbook();}
        else if(op==2){insertstudent();}
        else if(op==3){insertissuea();}
        else if(op==4){printbooks();}
        else if(op==5){printstudents();}
        else if(op==6){printissues();}
        else if(op==7){returnbook();}
        else{break;}
    }
    return 0;
}
