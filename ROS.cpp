#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include <limits>
using namespace std;
int TotalSale,Record,ItemsSold,Sold;
int a;
int b;
int c,sum=0,x=0;
int back,back1,back2,CTotal;
string first,cname,bname;
//Setting
void Setting(){
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\t\tSettings";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;	
cout<<"\n\t\t\t\t1.Add New Item"<<endl;
cout<<"\t\t\t\t2.Delete Item"<<endl;
cout<<"\t\t\t\t3.Edit Item"<<endl;
//cout<<"\t\t\t\t4.Change Username or Password"<<endl;
cout<<"\t\t\t\t0.Back\n"<<endl;
cout<<"\t\t\t\tEnter: ";	
}
//End Setting

//Admin
void Admin(){
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\t\tSettings";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;	
cout<<"\n\t\t\t\t1.Change Username"<<endl;
cout<<"\t\t\t\t2.Change Password"<<endl;
cout<<"\t\t\t\t0.Back\n"<<endl;
cout<<"\t\t\t\tEnter: ";	
}
//TotalSale
void TSale(){
	string line,Line2;
	//
	 int Ats=0,F=0,It=0,ISold=0;
	//
	int Test1,Tempsale;
	ofstream myfile;
	ofstream myItemsold;
	ofstream temp;
    temp.open("temp.txt");
    myfile.open("Sales.txt",ios::app);
	myItemsold.open("itemssold.txt",ios::app);
	cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<"\t\t\t\t\t\tSale";
	cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"<<endl;	
	cout<<"\n\t\t\t\t"<<"THIS SESSION SALE: PKR "<<Record<<".00"<<endl;
	cout<<"\n\t\t\t\t"<<"Items Sold in this Session: "<<Sold<<endl;
	cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"<<endl;
	myItemsold<<ItemsSold<<endl;
	myfile<<TotalSale<<endl;
	myfile.close();
	myItemsold.close();
    TotalSale=0;
    ItemsSold=0;
	Test1=1;
    if(Test1==1){
ifstream myfile("Sales.txt");
if(myfile.is_open()){
while(myfile>>Ats){
F=F+Ats;
}

cout<<"\t\t\t\tALL TIME SALE: PKR "<<F<<".00"<<endl;
myfile.close();
}
/////////////Items Sold/////////////////////
ifstream myItemsold("itemssold.txt");
if(myItemsold.is_open()){

while(myItemsold>>It){
ISold=ISold+It;
}
cout<<"\n\t\t\t\tTotal Items Sold: "<<ISold<<endl;
myItemsold.close();
///////////////Items Sold Ends//////////////
cout<<"\n\t\t\t\t0.Back\n"<<endl;
cout<<"\t\t\t\tEnter: ";
}
}
}


//Add
void Add(string itemName,int itemCategory,int itemPrice){
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
ofstream myfile;
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\t\tAdding Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;	
cout<<"\n\t\t\t\tSelect Item Category"<<endl;
cout<<"\n\t\t\t\t1.Fastfood, 2.Coldrinks, 3.Desert, 4.Spicy, 5.Salad"<<endl;
cout<<"\n\t\t\t\t";
cin>>back;
system("cls");
do{
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\t\tAdding Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;	
cout<<"\n\t\t\t\tSelect Item Category"<<endl;
cout<<"\n\t\t\t\t1.Fastfood, 2.Coldrinks, 3.Desert, 4.Spicy, 5.Salad"<<endl;
cout<<"\n\n\t\t\t\t0.Back";
cout<<"\n\t\t\t\t";
itemCategory=back;
if(itemCategory==1){
myfile.open("fastfood.txt",ios::app);
}
else if(itemCategory==2){
myfile.open("coldrinks.txt",ios::app);
}
else if(itemCategory==3){
myfile.open("Desert.txt",ios::app);
}
else if(itemCategory==4){
myfile.open("Spicy.txt",ios::app);
}
else if(itemCategory==5){
myfile.open("Salad.txt",ios::app);
}

if(itemCategory==1||itemCategory==2||itemCategory==3||itemCategory==4|itemCategory==5){
 cin.ignore(1, '\n');
cout<<"\n\t\t\t\tEnter Item Name: ";
cin>>itemName;
do{
cout<<"\n\t\t\t\tEnter Item Price: ";
cin>>itemPrice;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
if(itemPrice==0){
	system("cls");
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\t\tAdding Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;	
cout<<"\n\t\t\t\tSelect Item Category"<<endl;
cout<<"\n\t\t\t\t1.Fastfood, 2.Coldrinks, 3.Desert, 4.Spicy, 5.Salad"<<endl;
SetConsoleTextAttribute(h, 12);	
cout<<"\n\n\t\t\t\tError!!!! Please Enter a Valid Price\n";	
SetConsoleTextAttribute(h, 15);
}
}while(itemPrice==0);
myfile<<itemName<<"(PKR "<<itemPrice<<")"<<endl;
myfile.close();
cout<<"\n\t\t\t\t0.Back\n"<<endl;
cout<<"\t\t\t\tEnter: ";
cin>>back;
system("cls");
}
else if(itemCategory!=1||itemCategory!=2||itemCategory!=3||itemCategory!=4||itemCategory!=5){
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
back=0;
back1=back;
}	
}while(back!=0);
system("cls");
}
//Delete item
void deleteItem(){
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\tDeleting Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;	
cout<<"\n\t\t\t\tSelect Item Category"<<endl;
cout<<"\n\t\t\t\t1.Fastfood, 2.Coldrinks, 3.Desert, 4.Spicy, 5.Salad"<<endl;
cout<<"\n\t\t\t\t";
}
//fastfood delete item
void FFdeleteItem(string itemName,int itemCategory,int itemPrice){
int no=1;
string line;
ifstream myfile ("fastfood.txt");
ofstream temp;
temp.open("temp.txt");
itemCategory=1;
if(itemCategory==1){
system("cls");
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\tDeleting Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl<<endl<<endl;	
ifstream myfile ("fastfood.txt");
if(myfile.is_open()){
while(getline (myfile,line)){
cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
no++;
}
myfile.close();
}
}
cout<<"\n\t\t\t\tEnter Item name to Remove: ";
cin>>itemName;
while(getline(myfile,line)){
if(line.find(itemName) != string::npos){
}else{
temp<<line<<endl;
}
}
temp.close();
myfile.close();
remove("fastfood.txt");
rename("temp.txt","fastfood.txt");
cout<<"\n\t\t\t\tItem has been Deleted! \n\n\t\t\t\t----------------------------------------\n";
cout<<"\n\t\t\t\t0.Back\n"<<endl;
cout<<"\n\t\t\t\tEnter any other key to Refresh\n"<<endl;
cout<<"\t\t\t\tEnter: ";
}
//Coldrink delete item
void CDdeleteItem(string itemName,int itemCategory,int itemPrice){
int no=1,Goback;
string line;
ifstream myfile ("coldrinks.txt");
ofstream temp;
temp.open("temp.txt");
system("cls");
itemCategory=1;
if(itemCategory==1){
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\tDeleting Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl<<endl<<endl;
ifstream myfile ("coldrinks.txt");
if(myfile.is_open()){
while(getline (myfile,line)){
cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
no++;
}
myfile.close();
}
}
cout<<"\n\t\t\t\tEnter Item name to Remove: ";
cin>>itemName;
while(getline(myfile,line)){
if(line.find(itemName) != string::npos){
}else{
temp<<line<<endl;
}
}
temp.close();
myfile.close();
remove("coldrinks.txt");
rename("temp.txt","coldrinks.txt");
cout<<"\n\t\t\t\tItem has been Deleted! \n\n\t\t\t\t----------------------------------------\n\n";
cout<<"\n\t\t\t\t0.Back\n"<<endl;
cout<<"\n\t\t\t\tEnter any other key to Refresh\n"<<endl;
cout<<"\t\t\t\tEnter: ";
}
//Desert delete item
void DdeleteItem(string itemName,int itemCategory,int itemPrice){
int no=1;
string line;
ifstream myfile ("Desert.txt");
ofstream temp;
temp.open("temp.txt");
itemCategory=1;
if(itemCategory==1){
system("cls");
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\tDeleting Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl<<endl<<endl;
ifstream myfile ("Desert.txt");
if(myfile.is_open()){
while(getline (myfile,line)){
cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
no++;
}
myfile.close();
}
}
cout<<"\n\t\t\t\tEnter Item name to Remove: ";
cin>>itemName;
while(getline(myfile,line)){
if(line.find(itemName) != string::npos){
}else{
temp<<line<<endl;
}
}
temp.close();
myfile.close();
remove("Desert.txt");
rename("temp.txt","Desert.txt");
cout<<"\n\t\t\t\tItem has been Deleted! \n\n\t\t\t\t----------------------------------------\n\n";
cout<<"\n\t\t\t\t0.Back\n"<<endl;
cout<<"\n\t\t\t\tEnter any other key to Refresh\n"<<endl;
cout<<"\t\t\t\tEnter: ";
}
//Spicy delete item
void SPdeleteItem(string itemName,int itemCategory,int itemPrice){
int no=1;
string line;
ifstream myfile ("Spicy.txt");
ofstream temp;
temp.open("temp.txt");
itemCategory=1;
if(itemCategory==1){
system("cls");
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\tDeleting Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl<<endl<<endl;
ifstream myfile ("Spicy.txt");
if(myfile.is_open()){
while(getline (myfile,line)){
cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
no++;
}
myfile.close();
}
}
cout<<"\n\t\t\t\tEnter Item name to Remove: ";
cin>>itemName;
while(getline(myfile,line)){
if(line.find(itemName) != string::npos){
}else{
temp<<line<<endl;
}
}
temp.close();
myfile.close();
remove("Spicy.txt");
rename("temp.txt","Spicy.txt");
cout<<"\n\t\t\t\tItem has been Deleted! \n\n\t\t\t\t----------------------------------------\n\n";
cout<<"\n\t\t\t\t0.Back\n"<<endl;
cout<<"\n\t\t\t\tEnter any other key to Refresh\n"<<endl;
cout<<"\t\t\t\tEnter: ";
}
//Salad delete item
void SdeleteItem(string itemName,int itemCategory,int itemPrice){
int no=1;
string line;
ifstream myfile ("Salad.txt");
ofstream temp;
temp.open("temp.txt");
itemCategory=1;
if(itemCategory==1){
system("cls");
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\tDeleting Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl<<endl<<endl;
ifstream myfile ("Salad.txt");
if(myfile.is_open()){
while(getline (myfile,line)){
cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
no++;
}
myfile.close();
}
}
cout<<"\n\t\t\t\tEnter Item name to Remove: ";
cin>>itemName;
while(getline(myfile,line)){
if(line.find(itemName) != string::npos){
}else{
temp<<line<<endl;
}
}
temp.close();
myfile.close();
remove("Salad.txt");
rename("temp.txt","Salad.txt");
cout<<"\n\t\t\t\tItem has been Deleted! \n\n\t\t\t\t----------------------------------------\n\n";
cout<<"\n\t\t\t\t0.Back\n"<<endl;
cout<<"\n\t\t\t\tEnter any other key to Refresh\n"<<endl;
cout<<"\t\t\t\tEnter: ";
}

//Edit item Starts
void editItem(){
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\tEditing Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;	
cout<<"\n\t\t\t\tSelect Item Category"<<endl;
cout<<"\n\t\t\t\t1.Fastfood, 2.Coldrinks, 3.Desert, 4.Spicy, 5.Salad"<<endl;
cout<<"\n\t\t\t\t";
}
//fastfood edit starts
void FFeditItem(string itemName,int itemCategory,int itemPrice){
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int no=1;
string line;
ifstream myfile ("fastfood.txt");
ofstream temp;
temp.open("temp.txt");
itemCategory=1;
system("cls");
if(itemCategory==1){
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\tEditing Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"<<endl;
ifstream myfile ("fastfood.txt");
if(myfile.is_open()){
while(getline (myfile,line)){
cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
no++;
}
myfile.close();
}
}
string newItem;
int NewPrice;
cout<<"\n\t\t\t\tEnter Item name to Edit: ";
cin>>itemName;
cout<<"\n\t\t\t\tEnter New Name: ";
cin>>newItem;
//
do{
cout<<"\n\t\t\t\tEnter Price: ";
cin>>NewPrice;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
if(NewPrice==0){
	system("cls");
SetConsoleTextAttribute(h, 12);	
cout<<"\n\n\t\t\t\tError!!!! Please Enter a Valid Price\n";	
SetConsoleTextAttribute(h, 15);
}

}while(NewPrice==0);
while(getline(myfile,line)){
if(line.find(itemName) != string::npos){
temp<<newItem<<"(PKR "<<NewPrice<<")"<<endl;
}else{
temp<<line<<endl;
}
}
temp.close();
myfile.close();
remove("fastfood.txt");
rename("temp.txt","fastfood.txt");
cout<<"\n\t\t\t\tItem has been Updated! \n\n\t\t\t\t----------------------------------------\n";
cout<<"\n\t\t\t\t0.Back\n"<<endl;
cout<<"\n\t\t\t\tEnter any other key to Refresh\n"<<endl;
cout<<"\t\t\t\tEnter: ";
}
//Cold drinks edit starts
void CDeditItem(string itemName,int itemCategory,int itemPrice){
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//	ofstream myfile;
	int no=1;
	string line;
	ifstream myfile ("coldrinks.txt");
	ofstream temp;
	temp.open("temp.txt");
	
itemCategory=1;
system("cls");
if(itemCategory==1){
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\tEditing Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"<<endl;
		ifstream myfile ("coldrinks.txt");
		if(myfile.is_open()){
			while(getline (myfile,line)){
				cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
				no++;
			}
		myfile.close();
		}
	}
	string newItem;
	int NewPrice;
	cout<<"\n\t\t\t\tEnter Item name to Edit: ";
	cin>>itemName;
	cout<<"\n\t\t\t\tEnter New Name: ";
	cin>>newItem;
do{
cout<<"\n\t\t\t\tEnter Price: ";
cin>>NewPrice;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
if(NewPrice==0){
	system("cls");
SetConsoleTextAttribute(h, 12);	
cout<<"\n\n\t\t\t\tError!!!! Please Enter a Valid Price\n";	
SetConsoleTextAttribute(h, 15);
}

}while(NewPrice==0);
while(getline(myfile,line)){
		if(line.find(itemName) != string::npos){
			temp<<newItem<<"(PKR "<<NewPrice<<")"<<endl;
		}else{
			temp<<line<<endl;
		}
	}
	temp.close();
	myfile.close();
	remove("coldrinks.txt");
	rename("temp.txt","coldrinks.txt");
cout<<"\n\t\t\t\tItem has been Updated! \n\n\t\t\t\t----------------------------------------\n";
cout<<"\n\t\t\t\t0.Back\n"<<endl;
cout<<"\n\t\t\t\tEnter any other key to Refresh\n"<<endl;
cout<<"\t\t\t\tEnter: ";
}
//Coldrink edit ends

//Desert edit starts
void DeditItem(string itemName,int itemCategory,int itemPrice){
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//	ofstream myfile;
	int no=1;
	string line;
	ifstream myfile ("Desert.txt");
	ofstream temp;
	temp.open("temp.txt");
	
itemCategory=1;
system("cls");
if(itemCategory==1){
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\tEditing Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"<<endl;
		ifstream myfile ("Desert.txt");
		if(myfile.is_open()){
			while(getline (myfile,line)){
				cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
				no++;
			}
		myfile.close();
		}
	}
	string newItem;
	int NewPrice;
	cout<<"\n\t\t\t\tEnter Item name to Edit: ";
	cin>>itemName;
	cout<<"\n\t\t\t\tEnter New Name: ";
	cin>>newItem;
	do{
cout<<"\n\t\t\t\tEnter Price: ";
cin>>NewPrice;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
if(NewPrice==0){
	system("cls");
SetConsoleTextAttribute(h, 12);	
cout<<"\n\n\t\t\t\tError!!!! Please Enter a Valid Price\n";	
SetConsoleTextAttribute(h, 15);
}

}while(NewPrice==0);
	while(getline(myfile,line)){
		if(line.find(itemName) != string::npos){
			temp<<newItem<<"(PKR "<<NewPrice<<")"<<endl;
		}else{
			temp<<line<<endl;
		}
	}
	temp.close();
	myfile.close();
	remove("Desert.txt");
	rename("temp.txt","Desert.txt");
cout<<"\n\t\t\t\tItem has been Updated! \n\n\t\t\t\t----------------------------------------\n";
cout<<"\n\t\t\t\t0.Back\n"<<endl;
cout<<"\n\t\t\t\tEnter any other key to Refresh\n"<<endl;
cout<<"\t\t\t\tEnter: ";
}
//Desert edit ends

//Spicy edit starts
void SPeditItem(string itemName,int itemCategory,int itemPrice){
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);	
	//	ofstream myfile;
	int no=1;
	string line;
	ifstream myfile ("Spicy.txt");
	ofstream temp;
	temp.open("temp.txt");
	
	itemCategory=1;
system("cls");
if(itemCategory==1){
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\tEditing Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"<<endl;
		ifstream myfile ("Spicy.txt");
		if(myfile.is_open()){
			while(getline (myfile,line)){
				cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
				no++;
			}
		myfile.close();
		}
	}
	string newItem;
	int NewPrice;
	cout<<"\n\t\t\t\tEnter Item name to Edit: ";
	cin>>itemName;
	cout<<"\n\t\t\t\tEnter New Name: ";
	cin>>newItem;
do{
cout<<"\n\t\t\t\tEnter Price: ";
cin>>NewPrice;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
if(NewPrice==0){
	system("cls");
SetConsoleTextAttribute(h, 12);	
cout<<"\n\n\t\t\t\tError!!!! Please Enter a Valid Price\n";	
SetConsoleTextAttribute(h, 15);
}

}while(NewPrice==0);
	while(getline(myfile,line)){
		if(line.find(itemName) != string::npos){
			temp<<newItem<<"(PKR "<<NewPrice<<")"<<endl;
		}else{
			temp<<line<<endl;
		}
	}
	temp.close();
	myfile.close();
	remove("Spicy.txt");
	rename("temp.txt","Spicy.txt");
cout<<"\n\t\t\t\tItem has been Updated! \n\n\t\t\t\t----------------------------------------\n";
cout<<"\n\t\t\t\t0.Back\n"<<endl;
cout<<"\n\t\t\t\tEnter any other key to Refresh\n"<<endl;
cout<<"\t\t\t\tEnter: ";
}
//Spicy edit ends

//Salad edit starts
void SeditItem(string itemName,int itemCategory,int itemPrice){
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//	ofstream myfile;
	int no=1;
	string line;
	ifstream myfile ("Salad.txt");
	ofstream temp;
	temp.open("temp.txt");
	
	itemCategory=1;
system("cls");
if(itemCategory==1){
cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"\t\t\t\t\tEditing Item";
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"<<endl;
		ifstream myfile ("Salad.txt");
		if(myfile.is_open()){
			while(getline (myfile,line)){
				cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
				no++;
			}
		myfile.close();
		}
	}
	string newItem;
	int NewPrice;
	cout<<"\n\t\t\t\tEnter Item name to Edit: ";
	cin>>itemName;
	cout<<"\n\t\t\t\tEnter New Name: ";
	cin>>newItem;
	do{
cout<<"\n\t\t\t\tEnter Price: ";
cin>>NewPrice;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
if(NewPrice==0){
	system("cls");
SetConsoleTextAttribute(h, 12);	
cout<<"\n\n\t\t\t\tError!!!! Please Enter a Valid Price\n";	
SetConsoleTextAttribute(h, 15);
}

}while(NewPrice==0);
	while(getline(myfile,line)){
		if(line.find(itemName) != string::npos){
			temp<<newItem<<"(PKR "<<NewPrice<<")"<<endl;
		}else{
			temp<<line<<endl;
		}
	}
	temp.close();
	myfile.close();
	remove("Salad.txt");
	rename("temp.txt","Salad.txt");
cout<<"\n\t\t\t\tItem has been Updated! \n\n\t\t\t\t----------------------------------------\n";
cout<<"\n\t\t\t\t0.Back\n"<<endl;
cout<<"\n\t\t\t\tEnter any other key to Refresh\n"<<endl;
cout<<"\t\t\t\tEnter: ";
}
//Salad edit ends



//Menu
void Menu(int Total){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int temp=Total;
	
	cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<"\t\t\t\t\t\tMain Menu";
	cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;	
	cout<<"\n\t\t\t\t1.Fast Food"<<endl;
	cout<<"\t\t\t\t2.Cold Drinks"<<endl;
	cout<<"\t\t\t\t3.Desert"<<endl;
	cout<<"\t\t\t\t4.Spicy"<<endl;
	cout<<"\t\t\t\t5.Salad\n";SetConsoleTextAttribute(h, 10);cout<<"\t\t\t\t\t\tTotal: PKR "<<Total<<".00"<<endl;
	SetConsoleTextAttribute(h, 15);
	cout<<"\t\t\t\t6.Checkout"<<endl;
	cout<<"\t\t\t\t7.Setting"<<endl;
	cout<<"\t\t\t\t8.Sales"<<endl;
	cout<<"\t\t\t\t9.Exit\n"<<endl;
	cout<<"\t\t\t\t10.Reset Cart\n"<<endl;
	cout<<"\t\t\t\tEnter: ";
	
}
//End Menu


//Fast Food
void Fastfood(){
	int no=1;
	string line;
	ifstream myfile ("fastfood.txt");
	cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<"\t\t\t\t\t\tFast Food Menu";
	cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n"<<endl;		
	if(myfile.is_open()){
		while(getline (myfile,line)){
			cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
			no++;
		}
		myfile.close();
	}
cout<<"\t\t\t\t0.Back";
cout<<"\n\n\t\t\t\tEnter: ";
}

//End Fast Food


//Coldrinks

void Coldrinks(){
	int no=1;
	string line;
	ifstream myfile ("coldrinks.txt");
	cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<"\t\t\t\t\t\tColdrinks Menu";
	cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n"<<endl;		
	if(myfile.is_open()){
		while(getline (myfile,line)){
			cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
			no++;
		}
		myfile.close();
	}
	cout<<"\t\t\t\t0.Back";
	cout<<"\n\n\t\t\t\tEnter: ";
		
}


//End Coldrinks

//Desert

void Desert(){
	
		int no=1;
	string line;
	ifstream myfile ("Desert.txt");
	cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<"\t\t\t\t\t\tDesert Menu";
	cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n"<<endl;		
	if(myfile.is_open()){
		while(getline (myfile,line)){
			cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
			no++;
		}
		myfile.close();
	}
	cout<<"\t\t\t\t0.Back";
	cout<<"\n\n\t\t\t\tEnter: ";

}


//End Desert


//Spicy

void Spicy(){
	
	int no=1;
	string line;
	ifstream myfile ("Spicy.txt");
	cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<"\t\t\t\t\t\tSpicy Menu";
	cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n"<<endl;		
	if(myfile.is_open()){
		while(getline (myfile,line)){
			cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
			no++;
		}
		myfile.close();
	}
	cout<<"\t\t\t\t0.Back";
	cout<<"\n\n\t\t\t\tEnter: ";

}
//End Spicy

//Salad

void Salad(){
	
		int no=1;
	string line;
	ifstream myfile ("Salad.txt");
	cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<"\t\t\t\t\t\tSalad Menu";
	cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n"<<endl;		
	if(myfile.is_open()){
		while(getline (myfile,line)){
			cout<<"\t\t\t\t"<<no<<". "<<line<<endl;
			no++;
		}
		myfile.close();
	}
	cout<<"\t\t\t\t0.Back";
	cout<<"\n\n\t\t\t\tEnter: ";

}


//End Salad







//Main Program
int main(){

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(h, BACKGROUND_GREEN|BACKGROUND_INTENSITY);
	int iP,iC;
	int Amount,Change,Enter4;	
	string username,Name,ch,iN;
	string password,cpassword,newpassword;
	double input;	
	double Total=0;	
    time_t tt;
 // Declaring variable to store return value of
    // localtime()
    struct tm * ti;
    // Applying time()
    time (&tt);
    // Using localtime()
    ti = localtime(&tt);	
	do {
		
	cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<"\n\t\t\t\t\tPlease Login to Continue\t"<<endl;	
	cout << "\n\t\t\t\t\tUser Name: ";
	cin>>username;
	if (username == "Abdul") {
	cout << "\n\t\t\t\t\tPassword: ";
	cin>>password;
	cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<endl;
	if (password != "Haseeb") {
		system("cls");
	SetConsoleTextAttribute(h, 12);	
	cout << "\n\n\t\t\t\tinvalid password. try again." <<endl;
	SetConsoleTextAttribute(h, 15);
	}
	} else {
		system("cls");
	SetConsoleTextAttribute(h, 12);	
	cout << "\n\n\t\t\t\tinvalid username. try again." <<endl;
	SetConsoleTextAttribute(h, 15);
	}
	if(password == "Haseeb"){
	system("cls");	
	//cout<<"\t\t\t\t#########################################"<<endl;
	//cout<<"\n\t\t\t\t#                            \t#"<<endl;
	//cout<<"\n\t\t\t\t#   W            w   EEEEEE  LL      CCCCCCC  OOOOOOOO   MM          MM  EEEEEEE       \t"<<endl;
	//cout<<"\n\t\t\t\t#   W      w     w   E       LL      C        O      O   M  M      M  M  E             \t"<<endl;
	//cout<<"\n\t\t\t\t#   W    w   w   w   EEEEEE  LL      C        O      O   M    M   M   M  EEEEEEE       \t"<<endl;
	//cout<<"\n\t\t\t\t#   W  w       w w   E       LL      C        O      O   M      M     M  E             \t"<<endl;
	//cout<<"\n\t\t\t\t#   Ww          ww   EEEEEE  LLLLLL  CCCCCCC  OOOOOOOO   M            M  EEEEEEE       \t"<<endl;
	//cout<<"\n\t\t\t\t#########################################";
			
			cout<<"\n\n\n\t\t\t\t#############################################"<<endl;
			cout<<"\n\t\t\t\t#   Welcome to Restaurant Ordering System   #"<<endl;
			cout<<"\n\t\t\t\t#############################################";
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"\n\t\t\t\t";
			system("Pause");
			system("cls");
			
			cout<<endl;
			//***************************
	
			do {

				Menu(Total);
				
				cin>>input;
				system("cls");
				
//Setting
if(input==7){
Setting();
cin>>input;
system("cls");
//Add
if(input==1){
do{
Add(iN,iC,iP);
system("cls");
}while(back1!=0);
input=back1;
}
//Delete
if(input==2){

deleteItem();
cin>>input;

if(input==1){
do{
FFdeleteItem(iN,iC,iP);
cin>>input;
system("cls");
}while(input!=0);
}
if(input==2){
do{
CDdeleteItem(iN,iC,iP);
cin>>input;
system("cls");
}while(input!=0);
}
if(input==3){
do{
DdeleteItem(iN,iC,iP);
cin>>input;
system("cls");
}while(input!=0);
}
if(input==4){
do{
SPdeleteItem(iN,iC,iP);
cin>>input;
system("cls");
}while(input!=0);
}
if(input==5){
do{
SdeleteItem(iN,iC,iP);
cin>>input;
system("cls");
}while(input!=0);
}
else{
	system("cls");
	input=0;
}
}

//Edit
if(input==3){

editItem();
cin>>input;
if(input==1){
do{
FFeditItem(iN,iC,iP);
cin>>input;
system("cls");
}while(input!=0);
}
if(input==2){
do{
CDeditItem(iN,iC,iP);
cin>>input;
system("cls");
}while(input!=0);
}
if(input==3){
do{
DeditItem(iN,iC,iP);
cin>>input;
system("cls");
}while(input!=0);
}
if(input==4){
do{
SPeditItem(iN,iC,iP);
cin>>input;
system("cls");
}while(input!=0);
}
if(input==5){
do{
SeditItem(iN,iC,iP);
cin>>input;
system("cls");
}while(input!=0);
}
else{
	system("cls");
	input=0;
}
}
//Admin
/*else if(input==4){
Admin();
cin>>input;
if(input==1)

cout<<"Enter Password: ";
cin>>cpassword;
if(cpassword==password)

cout<<"Enter New Password: ";
cin>>newpassword;
password=newpassword;

}
*/

//Else
else if(input!=1 ||input!=2||input!=3){

system("cls");
input=0;
}
}
//End Setting
else if(input==1){
while(input!=0){
Fastfood();
cin>>input;
system("cls");
//Fastfood Conditions
if(input==1){
//exprement
ifstream file("fastfood.txt");
// This will loop until we can no longer 
// extract names from the file.
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
else if(input==2){
ifstream file("fastfood.txt");
file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

else if(input==3){
ifstream file("fastfood.txt");
file.ignore(25,'\n');
file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
else if(input==4){
ifstream file("fastfood.txt");
file.ignore(25,'\n');
file.ignore(25,'\n');
file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						else if(input==5){
							ifstream file("fastfood.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						
						else if(input==6){
							ifstream file("fastfood.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						
						else if(input==7){
							ifstream file("fastfood.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						
						else if(input==8){
							ifstream file("fastfood.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						
						else if(input==9){
							ifstream file("fastfood.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						    file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						
						else if(input==10){
							ifstream file("fastfood.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						
else if(input==11){
							ifstream file("fastfood.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');


						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						
else if(input==12){
							ifstream file("fastfood.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						
else if(input==13){
							ifstream file("fastfood.txt");
						 
						  file.ignore(25,'\n');
						 file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						
else if(input==14){
							ifstream file("fastfood.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						 file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						
else if(input==15){
							ifstream file("fastfood.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

//End Fastfood Conditions
						
					}	
					
				}
				//Coldrinks Conditions
				else if(input==2){
						
						
					while(input!=0){
					
						Coldrinks();
						cin>>input;
						system("cls");
						if(input==1){
//exprement
						ifstream file("coldrinks.txt");
// This will loop until we can no longer 
// extract names from the file.
						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						else if(input==2){
						ifstream file("coldrinks.txt");
						 
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						else if(input==3){
							
							ifstream file("coldrinks.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						else if(input==4){
							
								ifstream file("coldrinks.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						else if(input==5){
							ifstream file("coldrinks.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						else if(input==6){
							ifstream file("coldrinks.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						
						else if(input==7){
							ifstream file("coldrinks.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						
						else if(input==8){
							ifstream file("coldrinks.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}

						
						else if(input==9){
							ifstream file("coldrinks.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						    file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  

						while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==10){
							ifstream file("coldrinks.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

				while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
		
						else if(input==11){
							ifstream file("coldrinks.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');


while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==12){
							ifstream file("coldrinks.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==13){
							ifstream file("coldrinks.txt");
						 
						  file.ignore(25,'\n');
						 file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==14){
							ifstream file("coldrinks.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						 file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==15){
							ifstream file("coldrinks.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
}
}
//Desert Condtions
else if(input==3){
						
						
					while(input!=0){
						
						Desert();
						cin>>input;
						system("cls");
						if(input==1){
//exprement
						ifstream file("Desert.txt");
// This will loop until we can no longer 
// extract names from the file.
	while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
					else if(input==2){
						ifstream file("Desert.txt");
						 
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==3){
							
							ifstream file("Desert.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==4){
							
								ifstream file("Desert.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==5){
							ifstream file("Desert.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==6){
							ifstream file("Desert.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==7){
							ifstream file("Desert.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==8){
							ifstream file("Desert.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==9){
							ifstream file("Desert.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						    file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==10){
							ifstream file("Desert.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==11){
							ifstream file("Desert.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==12){
							ifstream file("Desert.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==13){
							ifstream file("Desert.txt");
						 
						  file.ignore(25,'\n');
						 file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==14){
							ifstream file("Desert.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						 file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==15){
							ifstream file("Desert.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
					}
					
				}
//Speciy Condtions
else if(input==4){
while(input!=0){
Spicy();
cin>>input;
system("cls");
if(input==1){
//exprement
						ifstream file("Spicy.txt");
// This will loop until we can no longer 
// extract names from the file.
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==2){
						ifstream file("Spicy.txt");
						 
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==3){
							
							ifstream file("Spicy.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==4){
							
								ifstream file("Spicy.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==5){
							ifstream file("Spicy.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==6){
							ifstream file("Spicy.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==7){
							ifstream file("Spicy.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==8){
							ifstream file("Spicy.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==9){
							ifstream file("Spicy.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						    file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==10){
							ifstream file("Spicy.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==11){
							ifstream file("Spicy.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');


while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==12){
							ifstream file("Spicy.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==13){
							ifstream file("Spicy.txt");
						 
						  file.ignore(25,'\n');
						 file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==14){
							ifstream file("Spicy.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						 file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==15){
							ifstream file("Spicy.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
					}
		
				}
//Salad
else if(input==5){
					
							
						while(input!=0){
						
						Salad();
						cin>>input;
						system("cls");
						if(input==1){
//exprement
						ifstream file("Salad.txt");
// This will loop until we can no longer 
// extract names from the file.
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==2){
						ifstream file("Salad.txt");
						 
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==3){
							
							ifstream file("Salad.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==4){
							
						ifstream file("Salad.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==5){
							ifstream file("Salad.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==6){
							ifstream file("Salad.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						else if(input==7){
							ifstream file("Salad.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==8){
							ifstream file("Salad.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==9){
							ifstream file("Salad.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						    file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==10){
							ifstream file("Salad.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');

while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==11){
							ifstream file("Salad.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');


while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==12){
							ifstream file("Salad.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==13){
							ifstream file("Salad.txt");
						 
						  file.ignore(25,'\n');
						 file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==14){
							ifstream file("Salad.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						 file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
						
						else if(input==15){
							ifstream file("Salad.txt");
						 
						  file.ignore(25,'\n');
						  file.ignore(25,'\n');
file.ignore(25,'\n');
file.ignore(25,'\n');
file.ignore(25,'\n');
file.ignore(25,'\n');
file.ignore(25,'\n');
file.ignore(25,'\n');
file.ignore(25,'\n');
file.ignore(25,'\n');
file.ignore(25,'\n');
file.ignore(25,'\n');
file.ignore(25,'\n');
file.ignore(25,'\n');
while (file >> first) {
cname=first;
file >> a >> b;
}
Total=Total+a;
cout<<endl;
cout<<"\t\t\t\tTotal: PKR "<<Total<<".00";
cout<<endl;
cout<<"\n\n\t\t\t\t"<<cname<<a<<") Added to Cart";
}
}
}
//Sales
else if(input==8){
TSale();
cin>>input;
system("cls");
if(input!=0){
	input=0;
}

}
//Exit
else if(input==9){
exit(0);
}

else if(input==10){
	Total=0;
	input=0;
}
//Checkout
else if(input==6){
	if(Total!=0){
	
	do{
system("cls");	
cout<<"\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";	
cout<<"\n\n\t\t\t\tTotal: PKR "<<Total;
cout<<"\n\n\t\t\t\tEnter Amount Given By User: ";
cin>>Amount;
if(Amount<Total){
	SetConsoleTextAttribute(h, 12);
	cout<<"\n\t\t\t\tError!!! Amount is Less then Total \n\n";
SetConsoleTextAttribute(h, 15);
cout<<"\n\t\t\t\tPress Any Key To Re-Enter Amount\n";
 cout<<"\n\t\t\t\t0.Back\n";
 cout<<"\n\t\t\t\tEnter: ";
cin>>input;
}

if(input==0){
system("cls");
}


}while(input!=0&&Amount<Total);
if(input!=0){


cin.ignore(1, '\n'); 
cout<<"\n\t\t\t\tEnter Customer Name: ";
getline( cin, Name);
do{
CTotal=Total;
cout<<"\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
system("cls");
cout<<"\n\n\n\n\n";
cout<<"\t\t\t\t********************Recipt***********************"<<endl;
cout<<"\n\t\t\t\t****************************************************";
cout<<"\n\t\t\t\t*  Customer Name: "<<Name<<"                           *"<<endl;
cout<<"\t\t\t\t*  Total: "<<Total<<"                                      *"<<endl;
back2=Total;
Total=Amount-Total;
Change=Total;
cout<<"\t\t\t\t*  Amount Given By Customer: "<<Amount<<"                  *"<<endl;
cout<<"\t\t\t\t*  Change: PKR "<<Change<<"                                 *"<<endl;
cout<<"\t\t\t\t*  "<<asctime(ti);
cout<<"\n\t\t\t\t****************************************************";
cout<<"\n\t\t\t\tPress '0' For New Customer: ";
cin>>input;
if(input!=0){
SetConsoleTextAttribute(h, 12);	
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
cout<<"\n\t\t\t\tError!!!! Please Enter a valid code\n";
SetConsoleTextAttribute(h, 15);
cout<<"\n\t\t\t\t";
system("Pause");
Total=CTotal;
}
}while(input!=0);

system("cls");
if(input==0){
ItemsSold++;
Sold++;		
TotalSale=TotalSale+back2;
Record=Record+back2;
Total=0.00;


}
}

}
else if(Total==0){
SetConsoleTextAttribute(h, 12);	
cout<<"\n\t\t\t\tCart is Empty!!!";
input=0;
SetConsoleTextAttribute(h, 15);
}
}
//Else
else if(input!=1 ||input!=2||input!=3||input!=4||input!=5||input!=6||input!=7||input!=8||input!=9||input!=10){
//

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	input=0;
SetConsoleTextAttribute(h, 12);
cout<<"\n\t\t\t\tPlease Enter a Valid Number!";


//

}
SetConsoleTextAttribute(h, 15);
}while(input==0);
} 
}while (password != "Freaks");		
return 0;
}
