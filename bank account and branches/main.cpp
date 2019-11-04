#include <iostream>
#include <windows.h>
#include <mysql.h>
using namespace std;

/*int main()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    if (conn)
        cout<< "Connection object OK" <<conn<< endl;
    else
        cout<< "Connection object Problem!" << mysql_error(conn) << endl;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);

    if (conn)
        {
        cout<< "Connection to Database done !!!" << conn <<endl;
        qstate = mysql_query(conn, "select * from customer");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                string savings=row[3]==0?"Does not exist":"Exists";
                string employee=row[5]==0?"false":"true";
                cout<< "Customer id  :"<< row[0] << "\n"
                    << "Customer Name :"<< row[1]<<"\n"
                    << "Branch IFSC code :"<<row[2]<<"\n"
                    << "Savings Account :"<<savings<<"\n"
                    << "Number of FDs :" <<row[4]<<"\n"
                    << "Is an Employee :"<<employee<<endl<<endl;
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



        return 0;
}*/
void display(){
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

    if (conn)
    {
        //cout<< "Connection to Database done !!!" << conn <<endl;
        qstate = mysql_query(conn, "select * from customer");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< "Customer id  :"<< row[0] << "\n"
                    << "Customer Name :"<< row[1]<<"\n"
                    << "Branch IFSC code :"<<row[2]<<"\n"
                    << "Savings Account :"<<row[3]<<"\n"
                    << "Number of FDs :" <<row[4]<<"\n"
                    << "Is an Employee :"<<row[5]<<"\n"
                    << "Manager :"<<row[6]<<" "<< "Staff :"<<row[7]<<endl<<endl;
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

void insertdata(){
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
    string cust_id,cust_name,ifsc,num_fd,manager,staff;
    string savings,employee;
    cout<<"\nEnter the customer-id ";
    cin>>cust_id;
    cout<<"\nEnter the customer-name ";
    cin>>cust_name;
    cout<<"\nEnter the ifsc code ";
    cin>>ifsc;
    cout<<"\nEnter if savings account exist or not(0 for no and 1 for yes) ";
    cin>>savings;
    cout<<"Enter the number of Fixed Deposits ";
    cin>>num_fd;
    cout<<"Enter if you are an employee(0 for no and 1 for yes) ";
    cin>>employee;
    if(employee=="1")
    {
        cout<<"Manager(0 for no and 1 for yes) ";
        cin>>manager;
        if(manager=="1"){staff="0";}
        else{staff="1";}
    }
    else{manager="0";staff="0";}
    string query="insert into customer(cust_id,cust_name,ifsc,savings,num_fd,employee,manager,staff) values('"+cust_id+"','"+cust_name+"','"+ifsc+"','"+savings+"','"+num_fd+"','"+employee+"','"+manager+"','"+staff+"');";
    //cout<<query;
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

