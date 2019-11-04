#include <iostream>
#include <windows.h>
#include <mysql.h>
using namespace std;

void query1()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    //if (conn)
    //    cout<< "Connection object OK" <<conn<< endl;
    //else
    //    cout<< "Connection object Problem!" << mysql_error(conn) << endl;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
    if(conn)
    {
        qstate = mysql_query(conn, "SELECT COUNT(employee.hire_date) from employee WHERE employee.hire_date>=2015-01-01");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<<row[0]<<endl<<endl;
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

void query2()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    //if (conn)
    //    cout<< "Connection object OK" <<conn<< endl;
    //else
    //    cout<< "Connection object Problem!" << mysql_error(conn) << endl;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
    if(conn)
    {
        qstate = mysql_query(conn, "SELECT department.name,sum(employee.salary) AS budget from employee,department where employee.department_id=department.id GROUP BY employee.department_id");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<<"Department:"<<row[0]<<"\n"
                    <<"budget:"<<row[1]<<endl<<endl;
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

void query3()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    //if (conn)
    //    cout<< "Connection object OK" <<conn<< endl;
    //else
    //    cout<< "Connection object Problem!" << mysql_error(conn) << endl;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
    if(conn)
    {
        qstate = mysql_query(conn, "SELECT DISTINCT sailor.Name from sailor,reserve WHERE sailor.Sid=reserve.sid");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<<"Name:"<<row[0]<<endl<<endl;
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

void query4()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    //if (conn)
    //    cout<< "Connection object OK" <<conn<< endl;
    //else
    //    cout<< "Connection object Problem!" << mysql_error(conn) << endl;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
    if(conn)
    {
        qstate = mysql_query(conn, "select sailor.Name,sailor.age,sailor.Rating from sailor where sailor.Name LIKE 'B_%B'");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<<"Name:"<<row[0]<<"\n"
                <<"Age:"<<row[1]<<"\n"
                <<"Rating:"<<row[2]<<endl<<endl;
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
        const char *q=query.c_str();
        qstate = mysql_query(conn,q);
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {cout<<row[0]<<" "<<row[1]<<endl;}
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
    /*MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    //if (conn)
    //    cout<< "Connection object OK" <<conn<< endl;
    //else
    //    cout<< "Connection object Problem!" << mysql_error(conn) << endl;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);

    if (conn)
        {
        cout<< "Connection to Database done !!!" << conn <<endl;
        qstate = mysql_query(conn, "select * from sailor");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<<"id:"<<row[0]<<"\n"
                    <<"Name:"<<row[1]<<"\n"
                    <<"Rating:"<<row[2]<<"\n"
                    <<"Age:"<<row[3]<<endl<<endl;
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
    }*/
    //int option;
        //while(option!=5)
        //{
            /*cout<<"1.FIND SAILORS WITH BOAT NUMBER 101 RESERVED\n"
            <<"2.FIND THE SAILOR NAMES WHO RESERVED RED BOAT ORDERED BY AGE\n"
            <<"3.FIND THE SAILORS WHO RESERVED ATLEAST ONE BOAT\n"
            <<"4.USE EXPRESSION AND STRINGS IN SELECT COMMAND\n"
            <<"5:PRESS THIS TO EXIT\n";*/
            /*cin>>option;
            if(option==1)
            {
               query1();
            }
            else if(option==2)
            {
                query2();
            }
            else if(option==3)
            {
                query3();
            }
            else if(option==4)
            {
                query4();
            }*/
            //query2();
        //}
        /*START FROM HERE FOR PRACTICAL FILE*/
        cout<<"QUERIES AND THEIR ANSWERS:\n";
        cout<<"\n1.Count the number of employees who joined after jan 2016\n";
        querywriter("SELECT COUNT(employee.id) from employee WHERE employee.hire_date>='2016-01-01'");
        cout<<"\n2.Budget that is sum of salaries of each department\n";
        querywriter("SELECT employee.department_id,SUM(employee.salary) from employee GROUP BY employee.department_id;");
        cout<<"\n3.Find the department with maximum budget\n";
        querywriter("SELECT department.id,department.name from department WHERE department.id=(SELECT tempo.dep_id from (SELECT sum(employee.salary)budget,(employee.department_id)dep_id from employee group by employee.department_id)tempo where tempo.budget=(SELECT max(tempi.budget) from (SELECT sum(employee.salary)budget from employee group by employee.department_id)tempi))");
        cout<<"\n4.Insert a trigger which will insert only those records in which employee dob is less than 2001-01-01\n";
        string temp="INSERT INTO `employee` (`id`, `name`, `dob`, `job_id`, `hire_date`, `salary`, `department_id`) VALUES ('092', 'test', '2002-10-01', '3', '2015-01-05', '10000', '2')";
        cout<<"trigger made,testing it with query:\n("<<temp<<")"<<endl;
        querywriter(temp);
        return 0;
        /*CREATE TRIGGER `check_age` BEFORE INSERT ON `employee` FOR EACH ROW BEGIN
IF NEW.dob > '2001-01-01' THEN
SIGNAL SQLSTATE '45000'
SET MESSAGE_TEXT = 'ERROR:
         AGE MUST BE ATLEAST 18 YEARS!';
END IF;
END;*/
}
