#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <windows.h> 
#include <conio.h> 

using namespace std;

struct people //creating student infomation structure to store in a vector
{
 string name;
 string icno;
 string contact;
 string temperature;
 string venue;
 string date;
};


void printQueue(queue<string> q1); //queue funtion to display without remove the queue element //queue algorithm

void modifyName(vector<people> &info, string name, string new_name); //modify function by entering thier name  //vector algorithm and linear search
void modifyIcno(vector<people> &info, string mtno, string new_icno);//modify function by entering thier ic no  //vector algorithm and linear search
void modifyContact(vector<people> &info, string contact, string new_Contact);//modify function by entering thier contact no  //vector algorithm and linear search
void delRecordIcno(vector<people> &info, string icno);//delete record by using ic no  //vector algorithm and linear search
void displayAllRecord(vector<people> &info);//display all data  //vector algorithm and linear search
void searchRecordByName(vector<people> &info, string name);//search record by using name  //vector algorithm and linear search
void searchRecordByIcno(vector<people> &info, string icno);//search record by using icno  //vector algorithm and linear search
void searchRecordByDate(vector<people> &info, string date);//search record by using date  //vector algorithm and linear search
void searchRecordByVenue(vector<people> &info, string venue);//search record by using venue  //vector algorithm and linear search


int main() 
{
string username, password;
int option;
int maxSize, addSize, minusSize,totalSize = 0;
string sname; 
queue<string>q1;//queue algorithm
vector<people>info;
people s;
string name_input,icno_input,contact_input,temperature_input,venue_input,date_input;
string newName,newIcno,newContact,newDate;
string editName,editIcno,editContact,editDate;
string delIcno,delDate;
string searchName,searchIcno,searchDate,searchVenue;

while(1)//Login
{
cout <<"---------------------------------------------------"<<endl;
cout<<"\nUMSKAL QUEUE MONITORING SYSTEM\n\n";
cout<< "---------------------------------------------------"<<endl<<endl;
cout<<"LOGIN PAGE\n\n";
cout<<"Username: ";
cin>>username;
cout<<endl;
cout<<"Password: ";
cin>>password;
cout<<endl;
system("cls");//It is used to clear screen

if(username=="admin"&&password=="admin123")//Admin Page
{
while(1)//Main Page
{
cout <<"---------------------------------------------------"<<endl;
cout<<"\nUMSKAL QUEUE MONITORING SYSTEM\n\n";
cout<< "---------------------------------------------------"<<endl<<endl;
cout<<"MAIN PAGE (ADMIN)\n\n";
cout<<"1.Operation Info"<<endl;
cout<<"2.Crowd Control"<<endl;
cout<<"3.Queue Control"<<endl;//queue algorithm
cout<<"4.Record Management"<<endl;
cout<<"5.Logout"<<endl<<endl;
cout<<"Choose the operation you want to perform by choosing an option number: ";
cin>>option;
cout<<endl;

while(option<1||option>5)
{
cout<<"Error input, please choose again"<<endl;
cin>>option;
cout<<endl;
}

system("cls");
    
    if(option==1)//operation info
    {
    while(1)
    {
    cout<<"Enter the date for this operation(format:14/07/2020): ";
    cin.ignore();
    getline(cin,date_input);
    cout<<endl;
    cout<<"Enter the venue for this operation: ";
    getline(cin,venue_input);
    cout<<endl;
    cout<<"Added Successfully"<<endl<<endl;
    cout<<"Please press any key to continue..."<<endl;
    getch();
    system("cls");
    break;
    }
    continue;
    }
    
    else if(option==2)//crowd control
    {
    while(1)
    {
        cout <<"-----------------"<<endl;
        cout<<"CROWD CONTROL\n";
        cout<< "------------------\n\n";
        cout<<"1.Enter maximum crowd Size"<<endl;
        cout<<"2.Display current crowd size"<<endl;
        cout<<"3.Enter people entered"<<endl;
        cout<<"4.Enter people left"<<endl;
        cout<<"5.Back to main page"<<endl<<endl;
        cout<<"Choose the operation you want to perform by choosing an option number: ";
        cin>>option;
        cout<<endl;
        while(option<1||option>5)
        {
        cout<<"Error input, please choose again"<<endl;
        cin>>option;
        cout<<endl;
        }
        system("cls");
    
                if(option==1)//Enter Maximum Size
                {  
                cout<<"Enter the maximum crowd size (number of people) allowed: ";
                cin>>maxSize;
                cout<<endl<<endl;
                cout<<"Added Successfully"<<endl<<endl;
                cout<<"Please press any key to continue..."<<endl;
                getch();//hold screen data
                system("cls");
                }
                
                else if(option==2)//Display current crowd size
                {  
                cout<<"Current crowd size: ";
                cout<<totalSize;
                cout<<endl<<endl;
                cout<<"Please press any key to continue..."<<endl;
                getch();
                system("cls");
                }

                else if (option==3)//Add people
                {
                cout<<"Enter the number of people entered: ";
                cin>>addSize;
                cout<<endl<<endl;
                
                totalSize = totalSize + addSize;
                
                while(totalSize>maxSize)
                {
                cout<<"Error Entry"<<endl<<endl;
                totalSize = totalSize - addSize;
                cout<<"Current crowd size: "<<totalSize<<endl<<endl;
                cout<<"Enter the number of people entered: ";
                cin>>addSize;
                cout<<endl;
                totalSize = totalSize + addSize;
                }
                
                if(totalSize==maxSize)
                {
                cout<<"The place is full. No more people is allowed to enter."<<endl<<endl;
                cout<<"Please press any key to continue..."<<endl;
                getch();
                system("cls");
                }
                
                else
                {
                cout<<"Added Successfully"<<endl<<endl;
                cout<<"Please press any key to continue..."<<endl;
                getch();
                system("cls");
                }
                }
                
                 else if (option==4)//Remove people
                {
                cout<<"Enter the number of people left: "<<endl;
                cin>>minusSize;
                cout<<endl;
                
                totalSize = totalSize - minusSize;
                
                while(totalSize<0)
                {
                cout<<"Error Entry"<<endl<<endl;
                totalSize = totalSize + minusSize;
                cout<<"Current crowd size: "<<totalSize<<endl<<endl;
                cout<<"Enter the number of people left: ";
                cin>>minusSize;
                cout<<endl;
                totalSize = totalSize - minusSize;
                }
                
                if(totalSize==0)
                {
                cout<<"The place is empty."<<endl<<endl;
                cout<<"Please press any key to continue..."<<endl;
                getch();
                system("cls");
                }
                
                else
                {
                cout<<"Minused Successfully"<<endl<<endl;
                cout<<"Please press any key to continue..."<<endl;
                getch();
                system("cls");
                }
                }
                
                else if (option==5)
                {
                break;
                }
    }
    continue;
    }
    
    else if(option==3)//Queue Control Page
    {
        while (1)
        {
        
        cout <<"-----------------"<<endl;
        cout<<"QUEUE CONTROL\n";
        cout<< "------------------\n\n";
        cout<<"1.Add a New Short Name Into The Queue"<<endl;
        cout<<"2.Remove The Front Name From The Queue"<<endl;
        cout<<"3.Check The Queue Status"<<endl;
        cout<<"4.Check The Queue Size"<<endl;
        cout<<"5.Display The Current Queue"<<endl;
        cout<<"6.Back to The Main Page"<<endl<<endl;
        cout<<"Choose the operation you want to perform by choosing an option number: ";
        cin>>option;
        cout<<endl;
        while(option<1||option>6)
        {
        cout<<"Error input, please choose again"<<endl;
        cin>>option;
        cout<<endl;
        }
        system("cls");

                if(option==1)//Enter name into queue
                {  
                cout<<"Enter a New Short Name For the Queue"<<endl;
                cin>>sname;
                q1.push(sname);//queue algorithm
                cout<<endl;
                cout<<"Added Successfully"<<endl<<endl;
                cout<<"Please press any key to continue..."<<endl;
                getch();
                system("cls");
                }

                else if (option==2)//Remove name from queue
                {
                q1.pop();//queue algorithm
                cout<<"Removed Successfully"<<endl<<endl;
                cout<<"Please press any key to continue..."<<endl;
                getch();
                system("cls");
                }

                else if (option==3)//check queue is empty or not
                {
                                if(!q1.empty())//queue algorithm
                                {
                                cout<<"The Queue is not empty"<<endl<<endl;
                                cout<<"Please press any key to continue..."<<endl;
                                getch();
                                system("cls");
                                }
                                else
                                {
                                cout<<"The Queue is empty"<<endl<<endl;
                                cout<<"Please press any key to continue..."<<endl;
                                getch();
                                system("cls");
                                }
                }

                else if (option==4)//check queue size
                {
                cout<<"Current number of people of the queue: "<<q1.size()<<endl<<endl;//queue algorithm
                cout<<"Please press any key to continue..."<<endl;
                getch();
                system("cls");
                }

                else if (option==5)//display queue list
                {
                cout<<"Current Queue (All Name):";
                printQueue(q1);//queue algorithm
                cout<<"Please press any key to continue..."<<endl;
                getch();
                system("cls");
                }

                else if (option==6)
                {
                break;
                }
        }

      continue;
      }

      else if(option==4)
      {
            while(1)//Record Management Page
            {
            cout <<"-----------------"<<endl;
            cout<<"RECORD MANAGEMENT\n";
            cout<< "------------------\n\n";
            cout<<"1.Add a New Record"<<endl;
            cout<<"2.Modify Record"<<endl;
            cout<<"3.Delete Record"<<endl;
            cout<<"4.Search and Display Record"<<endl;
            cout<<"5.Back to The Main Page"<<endl<<endl;
            cout<<"Choose the operation you want to perform by choosing an option number: ";
            cin>>option;
            cout<<endl;
            while(option<1||option>5)
            {
            cout<<"Error input, please choose again"<<endl;
            cin>>option;
            cout<<endl;
            }
            system("cls");

                        
                       
                        if(option==1)//Add record page
                        {
                        
                        
                        cout <<"-----------------"<<endl;
                        cout<<"NEW RECORD\n";
                        cout<< "------------------\n\n";
                        cin.ignore();
                        cout<<"Enter the name: ";
                        getline(cin,name_input);
                        cout<<"Enter the ic no: ";
                        getline(cin,icno_input);
                        cout<<"Enter the contact no: ";
                        getline(cin,contact_input);
                        cout<<"Enter the body temperature: ";
                        getline(cin,temperature_input);
                        cout<<endl;

                        s.name = name_input;
                        s.icno = icno_input;
                        s.contact = contact_input;
                        s.temperature = temperature_input;
                        s.date = date_input;
                        s.venue = venue_input;

                        info.push_back(s);//vector algorithm
                        
                        cout<<"Added successfully"<<endl<<endl;
                        
                        cout<<"Please press any key to continue..."<<endl;
                        getch();
                        system("cls");
                        }

                        else if(option==2)//Modify record page  //vector algorithm and linear search
                        {
                        cout<<"1.Name"<<endl;
                        cout<<"2.Ic No"<<endl;
                        cout<<"3.Contact No"<<endl;
                        cout<<"4.Back to Record Management"<<endl<<endl;
                        cout<<"Choose the data you want to modify by choosing an option number: ";
                        cin>>option;
                        cout<<endl;
                        while(option<1||option>5)
                        {
                        cout<<"Error input, please choose again"<<endl;
                        cin>>option;
                        cout<<endl;
                        }
                        system("cls");

                               while(1)
                              {
                              if(option==1)
                              {
                              cin.ignore();
                              cout<<"Enter the name you want to modify: ";
                              getline(cin,editName);
                              cout<<endl;
                              cout<<"Enter the new name: ";
                              getline(cin,newName);
                              cout<<endl;

                              modifyName(info, editName, newName);
                              cout<<"Please press any key to continue..."<<endl;
                              getch();
                              system("cls");
                              }

                              else if(option==2)
                              {
                              cin.ignore();
                              cout<<"Enter the ic no you want to modify: ";
                              getline(cin,editIcno);
                              cout<<"Enter the new ic no: ";
                              cout<<endl;

                              modifyIcno(info, editIcno, newIcno);
                              cout<<"Please press any key to continue..."<<endl;
                              getch();
                              system("cls");
                              }

                              else if(option==3)
                              {
                              cin.ignore();
                              cout<<"Enter the contact no you want to modify: ";
                              getline(cin,editContact);
                              cout<<endl;
                              cout<<"Enter the new contact no: ";
                              getline(cin,newContact);
                              cout<<endl;

                              modifyContact(info, editContact, newContact);
                              cout<<"Please press any key to continue..."<<endl;
                              getch();
                              system("cls");
                              }
                              

                              else if(option==4)
                              {
                              break;
                              }
                              break;
                              }
                        
                        }

                        else if(option==3)//delete record page  //vector algorithm and linear search
                        {
                              cin.ignore();
                              cout<<"Enter the ic no of the record that you want to delete: ";
                              getline(cin,delIcno);
                              delRecordIcno(info,delIcno);
                              cout<<"Please press any key to continue..."<<endl;
                              getch();
                              system("cls");
                              break;
                        }

                        else if(option==4)//search and display  //vector algorithm and linear search
                       {
                       cout<<"1.Display all record"<<endl;
                       cout<<"2.Name"<<endl;
                       cout<<"3.Ic No."<<endl;
                       cout<<"4.Date"<<endl;
                       cout<<"5.Venue"<<endl;
                       cout<<"6.Back to Record Management"<<endl<<endl;
                       cout<<"Display all data or choose the data you want to search by choosing an option number: ";
                       cin>>option;

                       system("cls");

                       while(1)//search record page
                       {
                       
                       if(option==1)//display all
                       {
                       displayAllRecord(info);
                       cout<<"Please press any key to continue..."<<endl<<endl;
                       getch();
                       system("cls");
                       }
                       
                       else if(option==2)//enter name to search
                       {
                       cin.ignore();
                       cout<<"Enter the name you want to search: ";
                       getline(cin,searchName);
                       cout<<endl;
                       searchRecordByName(info,searchName);
                       cout<<"Please press any key to continue..."<<endl<<endl;
                       getch();
                       system("cls");
                       }

                       else if(option==3)//enter ic no to search
                       {
                       cin.ignore();
                       cout<<"Enter the ic no you want to search: ";
                       getline(cin,searchIcno);
                       cout<<endl;
                       searchRecordByIcno(info,searchIcno);
                       cout<<"Please press any key to continue..."<<endl<<endl;
                       getch();
                       system("cls");
                       }

                       else if(option==4)//enter date to search
                       {
                       cin.ignore();
                       cout<<"Enter the date you want to search: ";
                       getline(cin,searchDate);
                       cout<<endl;
                       searchRecordByDate(info,searchDate);
                       cout<<"Please press any key to continue..."<<endl<<endl;
                       getch();
                       system("cls");
                       }
                       
                       else if(option==5)//enter venue to search
                       {
                       cin.ignore();
                       cout<<"Enter the venue you want to search: ";
                       getline(cin,searchVenue);
                       cout<<endl;
                       searchRecordByVenue(info,searchVenue);
                       cout<<"Please press any key to continue..."<<endl<<endl;
                       getch();
                       system("cls");
                       }

                       else if(option==6)//back to search and display
                       {
                       break;
                       }
                       break;
                       }                       
                       }
                        
                       else if(option==5)//back to record management
                       {
                          break;
                       }
            }
                        
            continue;
        }

        else if(option == 5)//back to main page
        {
            break;
        }
        
        
}
continue;
}

else if(username=="user"&&password=="user123")//user login
{
while(1)
{
system("cls");

cout <<"---------------------------------------------------"<<endl;
cout<<"\nUMSKAL QUEUE MONITORING SYSTEM\n\n";
cout<< "---------------------------------------------------"<<endl<<endl;
cout<<"MAIN PAGE (USER)\n\n";
cout<<"1.Display The Queue Status"<<endl;
cout<<"2.Check The Queue Size"<<endl;
cout<<"3.Add a New Record For Entry"<<endl;
cout<<"4.Modify Record"<<endl;
cout<<"5.Logout"<<endl<<endl;
cout<<"Choose the operation you want to perform by choosing an option number: ";
cin>>option;
cout<<endl;

while(option<1||option>5)
{
cout<<"Error input, please choose again"<<endl;
cin>>option;
cout<<endl;
}//While For Error Entry

system("cls");
                        if(option==1)//check queue status //queue algorithm
                        {
                        cout<<"Current Queue (All Name):";
                        printQueue(q1);
                        cout<<"Please press any key to continue..."<<endl;
                        getch();
                        system("cls");
                        }
                        
                        else if(option==2)//check queue size  //queue algorithm
                        {
                        cout<<"Current number of people of the queue: "<<q1.size()<<endl<<endl;
                        cout<<"Please press any key to continue..."<<endl;
                        getch();
                        system("cls");
                        }
                        
                        else if(option==3)//enter information for entry
                        {
                        cout <<"-----------------"<<endl;
                        cout<<"NEW RECORD\n";
                        cout<< "------------------\n\n";
                        cin.ignore();
                        cout<<"Enter the name: ";
                        getline(cin,name_input);
                        cout<<"Enter the ic no: ";
                        getline(cin,icno_input);
                        cout<<"Enter the contact no: ";
                        getline(cin,contact_input);
                        cout<<"Enter the body temperature: ";
                        getline(cin,temperature_input);
                        cout<<endl;

                        s.name = name_input;
                        s.icno = icno_input;
                        s.contact = contact_input;
                        s.temperature = temperature_input;
                        s.date = date_input;
                        s.venue = venue_input;

                        info.push_back(s);//vector algorithm
                        
                        
                        cout<<"Added successfully"<<endl<<endl;
                        cout<<"Please press any key to continue..."<<endl;
                        getch();
                        system("cls");
                        }//else if 
                        
                        else if(option==4)//modify information  //vector algorithm and linear search
                        {
                        cout<<"1.Name"<<endl;
                        cout<<"2.Ic No"<<endl;
                        cout<<"3.Contact No"<<endl;
                        cout<<"4.Back to Main Page"<<endl<<endl;
                        cout<<"Choose the data you want to modify by choosing an option number: ";
                        cin>>option;
                        cout<<endl;
                        while(option<1||option>5)
                        {
                        cout<<"Error input, please choose again"<<endl;
                        cin>>option;
                        cout<<endl;
                        }
                        system("cls");

                               while(1)
                              {
                              if(option==1)
                              {
                              cin.ignore();
                              cout<<"Enter the name you want to modify: ";
                              getline(cin,editName);
                              cout<<endl;
                              cout<<"Enter the new name: ";
                              getline(cin,newName);
                              cout<<endl;

                              modifyName(info, editName, newName);
                              cout<<"Please press any key to continue..."<<endl;
                              getch();
                              system("cls");
                              }

                              else if(option==2)
                              {
                              cin.ignore();
                              cout<<"Enter the ic no you want to modify: ";
                              getline(cin,editIcno);
                              cout<<endl;
                              cout<<"Enter the new ic no: ";
                              getline(cin,newIcno);
                              cout<<endl;

                              modifyIcno(info, editIcno, newIcno);
                              cout<<"Please press any key to continue..."<<endl;
                              getch();
                              system("cls");
                              }

                              else if(option==3)
                              {
                              cin.ignore();
                              cout<<"Enter the contact no you want to modify: ";
                              getline(cin,editContact);
                              cout<<endl;
                              cout<<"Enter the new contact no: ";
                              getline(cin,editContact);
                              cout<<endl;

                              modifyContact(info, editContact, newContact);
                              cout<<"Please press any key to continue..."<<endl;
                              getch();
                              system("cls");
                              }

                              else if(option==4)//back to user page
                              {
                              break;
                              }
                              break;
                              }
                        }//else if
                        
                        else if(option==5)//logout
                        {
                        break;
                        }//else if
                        

}//while(1) in User Interface loop
continue;
}//else if (user)

system("PAUSE");
return 0;
}//Starting while(1) loop
}//int main

void printQueue(queue<string> q1)//queue algorithm
{
	//printing content of queue 
	while (!q1.empty()){
		cout<<q1.front()<<" - ";
		q1.pop();
	}
	cout<<endl<<endl;
}

void modifyName(vector<people> &info, string name, string new_name) //vector algorithm and linear search
{
    vector<people>::iterator it;
    for (it = info.begin(); it != info.end(); it++)
    {
        if (it->name == name)
        {
            it->name = new_name;
            cout<<"Modify successfully"<<endl<<endl;
        }
        

    }
}

void modifyIcno(vector<people> &info, string icno, string new_icno)//vector algorithm and linear search
{
    vector<people>::iterator it;
    for (it = info.begin(); it != info.end(); it++)
    {
        if (it->icno == icno)
        {
            it->icno = new_icno;
            cout<<"Modify successfully"<<endl<<endl;
        }
        

    }
}

void modifyContact(vector<people> &info, string contact, string new_Contact)//vector algorithm and linear search
{
    vector<people>::iterator it;
    for (it = info.begin(); it != info.end(); it++)
    {
        if (it->contact == contact)
        {
            it->contact = new_Contact;
            cout<<"Modify successfully"<<endl<<endl;
        }
        
    }
}

void delRecordIcno(vector<people> &info, string icno)//vector algorithm and linear search
{
    vector<people>::iterator it;
    for(it = info.begin(); it != info.end();++it)
    {
    if(it->icno == icno)
    {
        it = info.erase(it);
        --it;
        cout<<endl;
        cout<<"Delete successfully"<<endl<<endl;
    }
    }
}


void searchRecordByName(vector<people> &info, string name)//vector algorithm and linear search
{
    int x = 0;
    vector<people>::iterator it;
    for(it = info.begin(); it != info.end(); it++)
    {
    if(it->name != name)
    {
        x++;
        if(x == info.size())
        {
          cout<<"No record found"<<endl;
        }
    }
    else if(it->name == name)
    {
        cout<<"Name :"<< it->name<<endl;
        cout<<"Ic No: "<< it->icno << endl;
        cout<<"Contact No: "<< it->contact << endl;
        cout<<"Body Temperature: "<< it->temperature << endl;
        cout<<"Date: "<< it->date << endl;
        cout<<"Venue: "<< it->venue << endl<<endl;
        cout<<"Searched successfully"<<endl<<endl;
    }
    }
    
}

void searchRecordByIcno(vector<people> &info, string icno)//vector algorithm and linear search
{
    int x = 0;
    vector<people>::iterator it;
    for(it = info.begin(); it != info.end(); it++)
    {
    if(it->icno != icno)
    {
        x++;
        if(x == info.size())
        {
          cout<<"No record found"<<endl;
        }
    }
    else if(it->icno == icno)
    {
        cout<<"Name :"<< it->name<<endl;
        cout<<"Ic No: "<< it->icno << endl;
        cout<<"Contact No: "<< it->contact << endl;
        cout<<"Body Temperature: "<< it->temperature << endl;
        cout<<"Date: "<< it->date << endl;
        cout<<"Venue: "<< it->venue << endl<<endl;
        cout<<"Searched successfully"<<endl<<endl;
    }
    }
    
}

void searchRecordByDate(vector<people> &info, string date)//vector algorithm and linear search
{
    int x = 0;
    vector<people>::iterator it;
    for(it = info.begin(); it != info.end(); it++)
    {
    if(it->date != date)
    {
        x++;
        if(x == info.size())
        {
          cout<<"No record found"<<endl;
        }
    }
    else if(it->date == date)
    {
        cout<<"Name :"<< it->name<<endl;
        cout<<"Ic No: "<< it->icno << endl;
        cout<<"Contact No: "<< it->contact << endl;
        cout<<"Body Temperature: "<< it->temperature << endl;
        cout<<"Date: "<< it->date << endl;
        cout<<"Venue: "<< it->venue << endl<<endl;
        cout<<"Searched successfully"<<endl<<endl;
    }
    }
    
}

void searchRecordByVenue(vector<people> &info, string venue)//vector algorithm and linear search
{
    int x = 0;
    
    vector<people>::iterator it;//vector
    for(it = info.begin(); it != info.end(); it++)
    {
    if(it->venue != venue)//linear search
    {
        x++;
        if(x == info.size())
        {
          cout<<"No record found"<<endl;
        }
    }
    else if(it->venue == venue)//linear search
    {
        cout<<"Name :"<< it->name<<endl;//vector
        cout<<"Ic No: "<< it->icno << endl;
        cout<<"Contact No: "<< it->contact << endl;
        cout<<"Body Temperature: "<< it->temperature << endl;
        cout<<"Date: "<< it->date << endl;
        cout<<"Venue: "<< it->venue << endl<<endl;
        cout<<"Searched successfully"<<endl<<endl;
    }
    }
    
}

void displayAllRecord(vector<people> &info)//vector algorithm and linear search
{
    vector<people>::iterator it;
    
    if(info.size()>0)
    {
    for(it = info.begin(); it != info.end(); it++)
    {
        cout<<"Name :"<< it->name<<endl;
        cout<<"Ic No: "<< it->icno << endl;
        cout<<"Contact No: "<< it->contact << endl;
        cout<<"Body Temperature: "<< it->temperature << endl;
        cout<<"Date: "<< it->date << endl;
        cout<<"Venue: "<< it->venue << endl<<endl;
        cout<<"Searched successfully"<<endl<<endl;
    }
    }
    
    else
    {
    cout<<"No record found"<<endl<<endl;
    }
}




