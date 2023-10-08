#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>
#include <sstream>
#include <iomanip>
using namespace std;


const char* HOST = "localhost";
const char* USER = "root";
const char* PW = "QvaL898+"; 
const char* DB = "mydb";

class Hostel{
	private:
		string ROOM_TYPE;
		int Bed, Fee;
	public:
		Hostel(string room, int bed, int fee){
			ROOM_TYPE = room;
			Bed = bed;
			Fee = fee;
		}
	
	string getName(){
		return ROOM_TYPE;
	}
	
	int getBed(){
		return Bed;
	}
	
	int getFee(){
		return Fee;
	}
};

int main() {
MYSQL* conn;
conn = mysql_init(NULL);

if(!mysql_real_connect(conn, HOST, USER, PW, DB, 3306, NULL, 0)){
	cout<<"Error: "<<mysql_error(conn)<<endl;
}
else{
	cout<<"Logged In Database!"<<endl;
}
	
Hostel h("2 BED AC", 2, 175000);
int intB =h.getBed();
int intF = h.getFee(); 

stringstream ss;
ss<<intB;
string strB = ss.str();

stringstream as;
as<<intF;
string strF = as.str();

string insert= "INSERT INTO hostel(ROOM_TYPE, Bed, Fee) VALUES ('"+h.getName()+"', '"+strB+"', '"+strF+"' )";
if(mysql_query(conn,insert.c_str())){
	cout<<"Error: "<<mysql_error(conn)<<endl;
}
else{
	cout<<"Inserted Successfuly!"<<endl;
}

Hostel h1("4 BED AC", 12, 150000);
int intB1 =h1.getBed();
int intF1 = h1.getFee(); 


stringstream ss1;
ss1<<intB1;
string strB1 = ss1.str();

stringstream as1;
as1<<intF1;
string strF1 = as1.str();

string insert1= "INSERT INTO hostel(ROOM_TYPE, Bed, Fee) VALUES ('"+h1.getName()+"', '"+strB1+"', '"+strF1+"' )";
if(mysql_query(conn,insert1.c_str())){
	cout<<"Error: "<<mysql_error(conn)<<endl;
}
else{
	cout<<"Inserted Successfuly!"<<endl;
}

Hostel h2("2 BED NON-AC", 20, 100000);
int intB2 =h2.getBed();
int intF2 = h2.getFee(); 


stringstream ss2;
ss2<<intB2;
string strB2 = ss2.str();

stringstream as2;
as2<<intF2;
string strF2 = as2.str();

string insert2= "INSERT INTO hostel(ROOM_TYPE, Bed, Fee) VALUES ('"+h2.getName()+"', '"+strB2+"', '"+strF2+"' )";
if(mysql_query(conn,insert2.c_str())){
	cout<<"Error: "<<mysql_error(conn)<<endl;
}
else{
	cout<<"Inserted Successfuly!"<<endl;
}


Hostel h3("4 BED NON-AC", 15, 70000);
int intB3 =h3.getBed();
int intF3 = h3.getFee(); 


stringstream ss3;
ss3<<intB3;
string strB3 = ss3.str();

stringstream as3;
as3<<intF3;
string strF3 = as3.str();

string insert3= "INSERT INTO hostel(ROOM_TYPE, Bed, Fee) VALUES ('"+h3.getName()+"', '"+strB3+"', '"+strF3+"' )";
if(mysql_query(conn,insert3.c_str())){
	cout<<"Error: "<<mysql_error(conn)<<endl;
}
else{
	cout<<"Inserted Successfuly!"<<endl;
}


bool exit = false;
while(!exit){
	system("cls");
	cout<<endl;
cout<<"Welcome To Hostel Management System"<<endl;
cout<<"***********************************"<<endl;
cout<<"1. RESERVE BED: "<<endl;
cout<<"2. FEE Structure: " <<endl;
cout<<"3. GET HOSTELLER DETAILS: " <<endl;
cout<<"4. Exit: " <<endl;
cout<<"Enter Your Choice: ";
int val;
cin>>val;
int total;
string room;
int fee;
if(val==1){
	string n;
	cout<<endl;
cout<<"Enter Student Name: ";
cin>>n;
cout<<"SELECT ROOM TYPE: "<<endl;
cout<<"1.2 BED AC "<<endl;
cout<<"2.4 BED AC"<<endl;
cout<<"3.2 BED NON-AC "<<endl;
cout<<"4.4 BED NON-AC"<<endl;
int m;
cin>>m;
if(m==1){
total=h.getBed();
room=h.getName();
fee=h.getFee();	
}else if(m==2){
total=h1.getBed();
room=h1.getName();
fee=h1.getFee();		
}else if(m==3){
total=h2.getBed();
room=h2.getName();
fee=h2.getFee();	
}else{
	total=h3.getBed();
room=h3.getName();
fee=h3.getFee();
}


string check= "SELECT Bed FROM hostel WHERE ROOM_TYPE = '"+room+"'";
if(mysql_query(conn,check.c_str())){
	cout<<"Error: "<<mysql_error(conn)<<endl;
}
else{
MYSQL_RES* res; 
res= mysql_store_result(conn);
if(res){
	MYSQL_ROW row = mysql_fetch_row(res);
if(row){
	total = atoi(row[0]);
}
mysql_free_result(res);
}
}
if(total > 0){
	total--;
stringstream zs;
zs<<total;
string strT = zs.str();

string update= "UPDATE hostel SET Bed = '"+strT+"' WHERE ROOM_TYPE='"+room+"' ";
if(mysql_query(conn,update.c_str())){
	cout<<"Error: "<<mysql_error(conn)<<endl;
}
else{
	cout<<endl;
cout<<"Bed is Reserved Successfuly in "<<room<< " Hostel For Student "<<n<<endl;
cout<<"Please Pay "<<fee<<" Rupees."<<endl;

string insert_s= "INSERT INTO STUDENT(NAME,ROOM_TYPE) VALUES ('"+n+"', '"+room+"')";
if(mysql_query(conn,insert_s.c_str())){
	cout<<"Error: "<<mysql_error(conn)<<endl;
}
else{
	cout<<"Inserted Successfuly!"<<endl;
}
}
}
else if(total ==0){
	cout<<endl;
	cout<<"Sorry! No Bed Available"<<endl;
} 
Sleep(8000);
}//if 1
else if(val==2){
	
	string name[100]={h.getName(),h1.getName(),h2.getName(),h3.getName()};
	int fee[100]={h.getFee(),h1.getFee(),h2.getFee(),h3.getFee()};
cout << setw(5) << "ID" << setw(15) << "ROOM TYPE" << setw(10) <<""<< "FEE (in rupees)" << endl;
   cout << "---------------------------------------" << endl;

    for (int i = 0; i <=3; i++) {
       cout << setw(5) << i+1 << setw(15) << name[i] << setw(10)<<"" << fee[i] << endl;
    }
Sleep(8000);
}
else if (val == 3) { 
   
    cout << "STUDENT DETAILS:" << endl;
    cout << setw(10) << "ID" << setw(20) << "Student Name" << setw(20) << "Room Type" << endl;
    cout << "--------------------------------------------" << endl;

    string selectStudentQuery = "SELECT * FROM STUDENT";
    if (mysql_query(conn, selectStudentQuery.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    }
    else {
        MYSQL_RES* res = mysql_store_result(conn);
        if (res) {
            int rowCount = 0;
            while (MYSQL_ROW row = mysql_fetch_row(res)) {
                rowCount++;
                string studentName = row[1];
                string roomType = row[2];
                cout << setw(10) << rowCount << setw(20) << studentName << setw(20) << roomType << endl;
            }
            mysql_free_result(res);
        }
    }
    cout << "--------------------------------------------" << endl;
    Sleep(8000);
}
else if(val==4){
	exit = true;
	cout<<"Good Luck"<<endl;
Sleep(3000);
}
else{
	cout<<"Invalid Input"<<endl;
	Sleep(3000);
}
}//while
mysql_close(conn);
return 0;
}
