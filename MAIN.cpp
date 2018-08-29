#include<iostream>
#include<conio.h>
#include<String.h>
#include<fstream>
using namespace std;
char gch;
class UMS
{
	public:
   
   char mentor[50],hod[50],pmentor[50],coun[50],ecell[50],pco[50];
   int  mb,hb,pb,cb,eb,pcb;
   char sec[5];
   int  mbm,hbm,pbm,cbm,ebm,pcbm;
   public:
      void display(); 
      void create();
};
void UMS::create()
{
	
	cout<<"\nENTER THE SECTION NAME:";
	cin>>sec;
	fflush(stdin);
	cout<<"\n\nENTER SECTION MENTOR NAME:";
	cin>>mentor;
	cout<<"\nENTER BLOCK NUMBER OF SECTION MENTOR:";
	cin>>mb;
	cout<<"\nENTER ROOM NUMBER OF SECTION MENTOR:";
	cin>>mbm;
	cout<<"\n\nENTER SECTION HEAD OF DEPARTMENT  NAME:";
	cin>>hod;
	cout<<"\nENTER BLOCK NUMBER OF HOD:";
	cin>>hb;
	cout<<"\nENTER ROOM NUMBER OF HOD:";
	cin>>hbm;
	cout<<"\n\nENTER SECTION PLACEMENT MENTOR NAME:";
	cin>>pmentor;
	cout<<"\nENTER BLOCK NUMBER OF PLACEMENT MENTOR:";
	cin>>pb;
	cout<<"\nENTER ROOM NUMBER OF PLACEMENT MENTOR:";
	cin>>pbm;
	cout<<"\n\nENTER SECTION STUDENT COUNSELLOR NAME:";
	cin>>coun;
	cout<<"\nENTER BLOCK NUMBER OF STUDENT COUNSELLOR:";
	cin>>cb;
	cout<<"\nENTER ROOM NUMBER OF STUDENT COUNSELLOR:";
	cin>>cbm;
	cout<<"\n\nENTER E-CELL CO-ORDINATOR NAME:";
	cin>>ecell;
	cout<<"\nENTER BLOCK NUMBER OF E-CELL CO-ORDINATOR:";
	cin>>eb;
	cout<<"\nENTER ROOM NUMBER OF E-CELL CO-ORDINATOR:";
	cin>>ebm;
	cout<<"\n\nENTER SECTION PLACEMENT CO-ORDINATOR NAME:";
	cin>>pco;
	cout<<"\nENTER BLOCK NUMBER OF PLACEMENT CO-ORDINATOR:";
	cin>>pcb;
	cout<<"\nENTER ROOM NUMBER OF PLACEMENT CO-ORDINATOR:";
	cin>>pcbm;
	cout<<"SECTION INFO RECORDED!!...";
	gch='*';
}

void UMS::display()
{
   int mop;
   ifstream dis("minimenu.txt",ios::in);
    char distext;
    if(dis.is_open())
    {
	   while(!dis.eof())
       {
           dis.get(distext);
           cout<<distext;
        }
    }
    dis.close();
    cout<<"\n\t\t\t\tSELECT ABOUT WHOM YOU WANT TO FIND:";
    cin>>mop;
    switch(mop)
    {
    	case 1:
    	   cout<<"\t\t\t\t\t******MENTOR******";
    	   cout<<"\n\t\t\t\t\tNAME:"<<mentor;
    	   cout<<"\n\t\t\t\t\tBLOCK:"<<mb;
    	   cout<<"\n\t\t\t\t\tROOM:"<<mbm;
    	   break;
    	case 2:
    	   cout<<"\t\t\t\t\t******HEAD OF DEPARTMENT*****";
    	   cout<<"\n\t\t\t\t\tNAME:"<<hod;
    	   cout<<"\n\t\t\t\t\tBLOCK:"<<hb;
    	   cout<<"\n\t\t\t\t\tROOM:"<<hbm;
    	   break;
    	case 3:
    	   cout<<"\t\t\t\t\t******PLACEMENT MENTOR*****";
    	   cout<<"\n\t\t\t\t\tNAME:"<<pmentor;
    	   cout<<"\n\t\t\t\t\tBLOCK:"<<pb;
    	   cout<<"\n\t\t\t\t\tROOM:"<<pbm;
    	   break;
    	case 4:
    	   cout<<"\t\t\t\t\t******STUDENT COUNSELLER*****";
    	   cout<<"\n\t\t\t\t\tNAME:"<<coun;
    	   cout<<"\n\t\t\t\t\tBLOCK:"<<cb;
    	   cout<<"\n\t\t\t\t\tROOM:"<<cbm;
    	   break;
    	case 5:
    	   cout<<"\t\t\t\t\t******E-CELL CO-ORDINATOR*****";
    	   cout<<"\n\t\t\t\t\tNAME:"<<ecell;
    	   cout<<"\n\t\t\t\t\tBLOCK:"<<eb;
    	   cout<<"\n\t\t\t\t\tROOM:"<<ebm;
    	   break;
    	case 6:
    	   cout<<"\t\t\t\t\t******PLACEMENT CO-ORDINATOR*****";
    	   cout<<"\n\t\t\t\t\tNAME:"<<pco;
    	   cout<<"\n\t\t\t\t\tBLOCK:"<<pcb;
    	   cout<<"\n\t\t\t\t\tROOM:"<<pcbm;
    	   break;	
	}
   
}

void search()
{
  try_again:
  char sea[5];
  system("cls");
  cout<<"\n\n\n\n\t\t\t\tENTER THE NAME OF THE SECTION:";
  cin>>sea;
  ifstream file_obj;
  UMS obj;
  int flag=0;
  file_obj.open("SectionList.dat",ios::in|ios::binary);
  file_obj.read((char*)&obj, sizeof(obj));
   while (!file_obj.eof()) 
   {
   	    if(strcmp(sea,obj.sec)==0)
   	    {
   	    	flag=1;
   	    	obj.display();
		   }
       file_obj.read((char*)&obj, sizeof(obj));
    }   
    file_obj.close();
	if(flag==0)
	{
		char ch;
		cout<<"SECTION NOT FOUND!!";
		cout<<"PRESS \"*\" to go to main menu"<<endl;
		cout<<"PRESS \"$\" try again"<<endl;
		ch=getch();
		if(ch=='$')
		{
		 goto try_again;
	    }
		else if(ch=='*')
		{
			file_obj.close();
			system("cls");
			gch='*';
		}
	}
	    char ch;
	    cout<<"\nPRESS \"*\" to go to main menu"<<endl;
		cout<<"\nPRESS \"$\" try again"<<endl;
		ch=getch();
		if(ch=='$')
		{
		 goto try_again;
	    }
		else if(ch=='*')
		{
			file_obj.close();
			system("cls");
			gch='*';
		}
}

void writeinfo()
{
	UMS s;
	ofstream outFile;
	outFile.open("SectionList.dat",ios::app|ios::binary);
	s.create();
	outFile.write((char*) (&s), sizeof(s));
	outFile.close();
}

int main()
{
    char o;
     mainmenu:
    ifstream ost("menu.txt");
    char weltext;
    if(ost.is_open())
    {
	   while(!ost.eof())
       {
           ost.get(weltext);
           cout <<weltext;
        }
    }
    ost.close();
   
    cout<<"\n\t\t\t\tPLEASE ENTER YOUR CHOICE:";
    o=getche();
    int flag=1;
    switch(o)
    {
    	case '1':
    		  	search();
				break;
		case '2':
		          writeinfo();
				  break;
	    case '3':
	    	     exit(0);
	    	     break;
		default:
			 cout<<"\nINVALID OPTION";
			 flag=0;
			 break;
		        	
	}
	if(flag==0||gch=='*')
	 goto mainmenu;
	   
}

