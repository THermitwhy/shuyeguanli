#include "socket.h"
#include "json.h"
#include "sql_sy.h"

socket_sy sy;
int main(){


//SQL_USE sy("localhost","root","200514why","his");
sy.setPort(7788);
sy.start();
sy.accep();
sy.Close();
return 0;

}
