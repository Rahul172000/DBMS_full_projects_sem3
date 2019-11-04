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
        qstate = mysql_query(conn, "SELECT * from sailor,reserve where sailor.Sid=reserve.sid and reserve.bid=103");
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
        qstate = mysql_query(conn, "SELECT DISTINCT sailor.Name,sailor.Age from sailor,reserve,boat WHERE sailor.Sid=reserve.sid and reserve.bid=boat.id and boat.color='red' ORDER by sailor.age");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<<"Name:"<<row[0]<<"\n"
                    <<"Age:"<<row[1]<<endl<<endl;
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
    /*int option;
        while(option!=5)
        {
            cout<<"1.FIND SAILORS WITH BOAT NUMBER 101 RESERVED\n"
            <<"2.FIND THE SAILOR NAMES WHO RESERVED RED BOAT ORDERED BY AGE\n"
            <<"3.FIND THE SAILORS WHO RESERVED ATLEAST ONE BOAT\n"
            <<"4.USE EXPRESSION AND STRINGS IN SELECT COMMAND\n"
            <<"5:PRESS THIS TO EXIT\n";
            cin>>option;
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
            }
        }*/
        cout<<"QUERIES AND THEIR ANSWERS:\n";
        cout<<"1.Sailor who reserved at least one boat\n";
        querywriter("SELECT DISTINCT sailor.Sid,sailor.Name from sailor,reserve where sailor.Sid=reserve.sid");
        cout<<"\n2.Sailors who reserved a red boat or a green boat in the month of september\n";
        querywriter("SELECT DISTINCT sailor.Sid,sailor.name from sailor,reserve,boat where sailor.Sid=reserve.sid AND boat.id=reserve.bid AND reserve.day BETWEEN '1998-09-01' AND '1998-09-31' AND (boat.color='red' OR boat.color='green')");
        cout<<"\n3.Sailors who reserved a red and a green boat\n";
        querywriter("SELECT DISTINCT sailor.Sid,sailor.Name from sailor,reserve AS r1,reserve AS r2,boat AS b1,boat AS b2 where sailor.Sid=r1.sid AND sailor.Sid=r2.sid AND r1.bid=b1.id AND r2.bid=b2.id AND b1.color='red' AND b2.color='green'");
        cout<<"\n4.Sailors who did not reserve a boat after september 1998\n";
        querywriter("SELECT sailor.Sid,sailor.Name from sailor where (SELECT max(reserve.day) from reserve where reserve.sid=sailor.Sid)<='1998-09-30'");
        cout<<"\n5.Sailors whose ratings is greater than that of all sailors named HORATIO\n";
        querywriter("SELECT sailor.Sid,sailor.Name from sailor where sailor.Rating>(SELECT max(sailor.Rating) from sailor WHERE sailor.Name='HORATIO');");
        cout<<"\n6.Sailors who reserved all boats\n";
        querywriter("SELECT sailor.Sid,sailor.Name from sailor WHERE (SELECT COUNT(DISTINCT reserve.bid) from reserve where reserve.sid=sailor.Sid)=(SELECT COUNT(boat.id) from boat)");
        cout<<"\n7.Name and age of oldest sailor\n";
        querywriter("SELECT sailor.Name,sailor.Age from sailor WHERE sailor.Age=(SELECT max(sailor.Age) from sailor);");
        cout<<"\n8.Name and age of youngest sailor for each rating\n";
        querywriter("SELECT head.Name,head.Age from sailor AS head where head.Age=(SELECT MIN(sailor.Age) from sailor where sailor.Rating=head.Rating) GROUP BY head.Rating;");
        return 0;
}
