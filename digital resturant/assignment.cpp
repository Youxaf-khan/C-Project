

/*------------- Yousaf khan --------------*/



#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct menu 
{
	int sn[10], price[10] ;
	string item1[10], item2[10];
	int index;
	int quant;
	int amunt;
	int bill;
	int sum, tot;
	float t;
	char ch,c;
	string men;
	


	
	void data(ifstream &in)
	{
				
		in.open("Yousaf.txt");
		int i = 0;
		while (i<10)
		{
			in>>sn[i]>>item1[i]>>item2[i]>>price[i];
			i++;
		}
		
	}

	void  amnt()
	{
		ofstream ofile , result;
		ofile.open("alpha.txt",ios::app);
		result.open("earn.txt",ios::app);
		ifstream infile;
		
		amunt =0;
		amunt += price[index-1]*quant;
	
		cout<<item1[index-1]<<" "<<item2[index-1]<<" "<<amunt<<endl;
		
		ofile<<item1[index-1]<<" "<<item2[index-1]<<" "<<amunt<<endl;
	
		result<<amunt<<endl;
		infile.open("earn.txt");
		while(infile)
		{
			infile>>sum;
			tot= tot + sum;
			
		}
		
	}

	void total_bill()
	{
		bill += price[index-1]*quant;
		
	}
	
	void tax()
	{
		t = 0.15*bill;
		t = t + bill;
		cout<<"your bill after including 15% tax : "<<t<<endl;
		
		tot=tot-bill;
		ifstream xyz;
		xyz.open("alpha.txt");
	
		cout<<"if you want to see the order of the whole day press 'q'"<<endl;
		cin>>c;	
		if (c == 'q' || c == 'Q')
		{
		
			cout<<"orders of the day "<<endl;
			while(xyz)
			{
				getline(xyz, men);
				cout<<men<<endl;
			}
			cout<<"total earning of the day : "<<tot<<endl;
		}
	}
	void print()
	{
		cout<<"your total bill : "<<bill<<endl;
		
	}
	
	void next_order()
	{
	
		do
		{
		cout<<"Enter index of order : "<<endl;
		cin>>index;
		
		cout<<"enter quantity "<<endl;
		cin>>quant;
		
		amnt();
		total_bill();
		
		cout<<"press 'y' to place another order "<<endl;
		cin>>ch;
		}while(ch == 'y' || ch == 'Y');
	
	 }
	 
	
	
};

	
	


int main()
{
	string menu1;
	menu m;
	m.bill=0;
	m.tot = 0;
	m.sum=0;
	//earning e;

	cout<<"---------------- Welcome to our Resturant ---------------"<<endl
		<<"Here you can see our Menu Card"<<endl;
	
	ifstream in , f , a;
	in.open("menu.txt");
	
	if (in.is_open())
	{
		while(in)
		{
			getline(in,menu1);
			cout<<menu1<<endl;
		}
	}
	else 
	{
		cout<<"error in your file !!!!!!!!!!!!"<<endl;
	}

	m.data(f);
	m.next_order();
	
	system("cls");
	
	m.print();
	m.tax();

	system ("pause");
	return 0;
}

