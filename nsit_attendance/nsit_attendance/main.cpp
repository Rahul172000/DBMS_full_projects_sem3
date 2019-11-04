#include <iostream>
#include <windows.h>
#include <mysql.h>
using namespace std;

/*#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}*/

void dailyattendance(string sid,string cid)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
    if(conn)
    {
        string query="SELECT choose_present.present from choose_present where choose_present.cid='"+cid+"' AND choose_present.sid="+sid+";";
        const char *q=query.c_str();
        qstate = mysql_query(conn,q);
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<<"PRESENT:"
                <<row[0]<<endl;
            }
        }
        else
        {
        cout<< "Query Execution Problem!" << mysql_error(conn) << endl;
        }

        query="SELECT choose_absent.absent from choose_absent where choose_absent.cid='"+cid+"' AND choose_absent.sid="+sid+";";
        q=query.c_str();
        qstate = mysql_query(conn,q);
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<<"ABSENT:"
                <<row[0]<<endl;
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

void querywriter(string query)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
    if(conn)
    {
        const char*q=query.c_str();
        qstate = mysql_query(conn, q);
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<<row[0]<<"\n"
                <<row[1]<<endl;
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

int main()
{
    cout<<"\nQUERIES AND THEIR ANSWERS ARE:";
    cout<<"\n1.Print students name who have taken physics course\n";
    querywriter("SELECT student_attendance.name,choose_course.sid from student_attendance,choose_course where student_attendance.sid=choose_course.sid AND choose_course.cid='Physics'");
    cout<<"\n2.Print students name and their attendance in COA course\n";
    querywriter("SELECT student_attendance.name,(COUNT(choose_present.present)*100/course.total_classes)percent from student_attendance,choose_present,course WHERE choose_present.sid=student_attendance.sid AND choose_present.cid=course.cid AND choose_present.cid='COA' GROUP BY choose_present.sid");
    cout<<"\n3.Find if Prateek was present on 2019-03-12 in DS class\n";
    querywriter("SELECT 'Prateek',count(choose_present.present) from choose_present where choose_present.sid='1109' AND choose_present.cid='DS' AND choose_present.present='2019-03-12';");
    cout<<"\n4.Print daily attendance of Sachin in DBMS\n";
    dailyattendance("1112","DBMS");
    cout<<"\n5.Print blacklisted students in PHYSICS course\n";
    querywriter("SELECT student_attendance.name,(COUNT(choose_present.present)*100/course.total_classes)Percent from student_attendance,choose_course,choose_present,course where student_attendance.sid=choose_course.sid AND course.cid='Physics' AND choose_present.sid=choose_course.sid AND choose_present.cid=course.cid AND choose_course.cid='Physics' AND (SELECT COUNT(choose_absent.absent)*100/course.total_classes from choose_absent,course where course.cid='Physics' AND choose_absent.cid=course.cid AND choose_absent.sid=choose_course.sid)>25 GROUP BY choose_course.sid");
    return 0;
}
