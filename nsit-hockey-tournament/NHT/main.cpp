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
    cout<<" QUERIES AND THEIR ANSWERS ARE:";
    cout<<"\n1.All players of team Avengers\n";
    querywriter("SELECT players.pid,players.name FROM players WHERE players.team='Avengers'");
    cout<<"\n2.Coach and captain of sherlock homies\n";
    querywriter("SELECT teams.coach,players.name FROM teams,players where teams.name='Sherlock Homies' AND teams.captain=players.pid;");
    cout<<"\n3.All team names in the order of the number of matches they have won\n";
    querywriter("SELECT temp.teams,temp.matches_won from(SELECT (teams.name)teams,(SELECT count(matches.winner) from matches where matches.winner=teams.name)matches_won from teams)temp ORDER BY `temp`.`matches_won` DESC");
    cout<<"\n4.Is Vyom captain of any team\n";
    querywriter("SELECT 'Vyom',COUNT(players.name) FROM players,teams WHERE teams.captain=players.pid AND players.name='Vyom'");
    return 0;
}
