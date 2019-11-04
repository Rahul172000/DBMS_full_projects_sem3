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
    cout<<"\nQUERIES AND ANSWERS:\n";
    cout<<"\n1.Find the apartment number with max rent in all buildings\n";
    querywriter("SELECT apartment.ano,apartment.b_num from apartment where apartment.rent=(SELECT max(temp.rent) from apartment AS temp where temp.b_num=apartment.b_num) GROUP BY apartment.b_num ");
    cout<<"\n2.Find total apartments in first floor in building number 1\n";
    querywriter("SELECT apartment.b_num,count(DISTINCT apartment.ano) from apartment where apartment.b_num='1' AND apartment.floor='1'");
    cout<<"\n3.List the building number with floor greater than 1\n";
    querywriter("SELECT building.name,building.b_num from building where (SELECT max(apartment.floor) from apartment where apartment.b_num=building.b_num)>1");
    cout<<"\n4.List the building names in order of their number of floors\n";
    querywriter("SELECT temp.floor,temp.name from (SELECT max(apartment.floor)floor,(apartment.b_num)b_num,(building.name)name from apartment,building where building.b_num=apartment.b_num GROUP BY apartment.b_num)temp ORDER BY temp.floor");
    return 0;
}
