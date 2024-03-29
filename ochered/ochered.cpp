#include <iostream>
#include <string>

using namespace std;
class Queue         ///����� �������
{
private:
	int * point;
	int s;          ///������
	int l;          ///������ ������
	int fst;        ///������ �������
	int lst;        ///��������� �������
	bool nF();      ///��������, ������ �� �������
	bool nE();      ///��������, ������ �� �������
public:
	Queue(); 
	void add();     ///���������� �������� � �������
	void take();    ///�������� ��������
	void print();   ///����� ��������
	~Queue();
};
Queue::Queue()      ///�����������, ��������� ������
	:l(0)
	,fst(0)
	,lst(-1)
{
	std::cout<<"enter size:";
	std::cin>>s;
	while (s<=0)
	{
		std::cout<<"\nwrong size of the queue\n"<<std::endl;
		std::cout<<"enter size:";
		std::cin>>s;
	}
	point=new int [s];
}
bool Queue::nF()    ///�������� ������ �� �������
{
	if (l<s) 
		return true;
	else
		return false;
}
bool Queue::nE()   /// ��������, ������ �� �������
{
	if (l>0)
		return true;
	else
		return false;
}
void Queue::add()  ///���������� ��������
{
	if(nF())
	{
		int num;
		cout<<"\nenter the element: ";
		cin>>num;
		lst=(lst+1)%s;
		point[lst]=num;
		l++;
		cout<<endl;
	}
	else
		cout<<"\nqueue is full\n"<<endl;
}
void Queue::take()   ///�������� ��������
{
	if (nE())
	{
		cout<<"\ndeleted the element: "<<point[fst]<<endl<<endl;
		fst=(fst+1)%s;
		l--;
	}
	else
		cout<<"\nqueue is full\n"<<endl;
}
void Queue::print()   ///����� ��������
{
	if (nE())
	{
		int number=0;
		cout<<"\nenter number of the element:";
		cin>>number;
		while (!((0<number)&&(number<=l)))
		{
			cout<<
				"\nnumber of element should be more than zero and "
				"and don't push the limits of the queue\n"
				    <<endl;
			cout<<"enter number of the element:";
			cin>>number;
		}
		cout<<endl<<point[(fst+number-1)%s]<<endl<<endl;
	}
	else
		cout<<"\nqueue is empty\n"<<endl;
}
Queue::~Queue()
{
	delete [] point;
};
char ask()    ///���� ����������� ������
{
	cout<<"choose action: "<<endl;
	cout<<"1)add"<<endl;
	cout<<"2)delete"<<endl;
	cout<<"3)show i element"<<endl;
	cout<<"4)exit"<<endl;
	char ask;
	cin.clear();
	cin>>ask;
	return ask;
}
void main()
{
	setlocale(LC_ALL, "Russian");
	Queue Queue1;
	char exit_=1;
	while(exit_)
	{
		switch(ask())
		{
		case '1':
			{
				Queue1.add();
				break;
			}
		case '2':
			{
				Queue1.take();
				break;
			}
		case '3':
			{
				Queue1.print();
			}
			break;
		case '4':
			exit_=0;
			break;
		default:
			std::cout<<"\nwrong input. repeat the input\n\n";
			break;
		}
	}
	system("pause");
}