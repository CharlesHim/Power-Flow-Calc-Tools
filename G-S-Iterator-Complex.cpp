#include <iostream>
#include <complex>
#include <math.h>

#define uint unsigned int

using namespace std;

complex<double> x[1001][1001] = {0};	//x _i ^k
complex<double> y[1001] = {0};	//y _i ^k
complex<double> a[1001][1001] = {0};	//a _i _j

double accuracy = 1, current_accuracy = 2;//��ȷ�� 
uint times = 0;		//�������� 
uint size = 1;			//�����ģ
uint i=0,j=0,k=0;	//����Ԫ���±�����������ϱ� 

bool method = true; //"true"��ʾ������ָ����ȷ�ȣ�"false"��ʾ������ָ������ 

void GS_init(void)
{
	cout<<"����������ģ[uint]:"; 
	cin>>size;
	cout<<"\n�Ƿ�ʹ�þ�ȷ����Ϊ����ָ��[bool 0/1]:"; 
	cin>>method;
	if(method)
	{
		cout<<"\nѡ���˾�ȷ����Ϊ����ָ�꣬�����뾫ȷ��:";
		cin>>accuracy;
	}
	else
	{
		cout<<"\nѡ���˵���������Ϊ����ָ�꣬���������:";
		cin>>times;
	}
	for(i=0;i<size;i++)	//a matrix
	{
		cout<<"\n Matrix A Row "<<i+1<<" elements:"<<endl;
		for(j=0;j<size;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"\nMatrix X elements:"<<endl;
	for(i=0;i<size;i++)	//x matrix
	{
		cin>>x[i][0];
	}
	cout<<"\nMatrix Y elements:"<<endl;
	for(j=0;j<size;j++)	//y matrix
	{
			cin>>y[j];
	}
	
	cout<<"\nParameters:"<<endl;
	cout<<"Matrix size = "<<size<<endl;
	
	if(method)
	{
		cout<<"Accuracy = "<<accuracy<<endl;
	}
	else
	{
		cout<<"Times = "<<times<<endl;
	}
	
	cout<<"\nA matrix:"<<endl;

	for(i=0;i<size;i++)
	{
		cout<<"|";
		for(j=0;j<size;j++)
		{
			cout<<" "<<a[i][j]<<" ";
		}
		cout<<"|\n"<<endl;
	}
	cout<<"XT matrix:"<<endl<<"{";
	for(i=0;i<size;i++)
	{
		cout<<" "<<x[i][0];
	}
	cout<<" }\n"<<endl<<"YT matrix:"<<endl<<"{";
	for(j=0;j<size;j++)
	{
		cout<<" "<<y[j];
	}
	cout<<" }"<<endl<<endl<<"Calc start...\n"<<endl;
}

void iterate(void)
{
	complex<double> tmp = 0;	//û��ֱ���� ���1 ����������Ƕ��ѭ�������ʹ����ʱ��������ӽ�� 
	uint n = 0; //ѭ�����������ã���ʱ��һ�� 
	if(method)
	{

		for(i=0;i<size;i++)
		{
			if(abs(x[i][k+1]-x[i][k]) > current_accuracy)
			{
				current_accuracy = abs(x[i][k+1]-x[i][k]);
			}
		}
		while(accuracy<current_accuracy)
		{
			cout<<".";
			times++;   
			for(i=0;i<size;i++)
			{
				tmp = 0;
				for(j=0;j<size;j++)
				{
					if(x[j][k+1] != 0.0)
					{
						tmp += a[i][j]*x[j][k+1];
					}
					else
					{
						tmp += a[i][j]*x[j][k];
					}
				}
				if(x[j][k+1] != 0.0)
				{
					tmp -= a[i][i]*x[j][k+1];
				}
				else
				{
					tmp -= a[i][i]*x[j][k];
				}
				
				x[i][k+1] = (y[i]-tmp)/a[i][i];	//���1 ������� 
			
				if(abs(x[i][k+1]-x[i][k]) > current_accuracy)
				{
					current_accuracy = abs(x[i][k+1]-x[i][k]);
				}
			}
			k++;
		}
	}
	else 
	{
		for(n=0;n<times;n++)
		{ 
			cout<<"."; 
			for(i=0;i<size;i++)
			{
				tmp = 0;
				for(j=0;j<size;j++)
				{
					if(x[j][k+1] != 0.0)
					{
						tmp += a[i][j]*x[j][k+1];
					}
					else
					{
						tmp += a[i][j]*x[j][k];
					}
				}
				if(x[j][k+1] != 0.0)
				{
					tmp -= a[i][i]*x[j][k+1];
				}
				else
				{
					tmp -= a[i][i]*x[j][k];
				}
				
				x[i][k+1] = (y[i]-tmp)/a[i][i];	//���1 ������� 
			}
			k++;
		} 		
		for(i=0;i<size;i++)
		{
			if(abs(x[i][k]-x[i][k-1]) > current_accuracy)
			{
				current_accuracy = abs(x[i][k]-x[i][k-1]);
			}
		}
	}
}

int main(void)
{
	GS_init(); 
	iterate();
	
	if(method)
	{
		cout<<"\n\n�ڹ̶���ȷ�ȵ���ģʽ�£�����"<<times<<"�ε����󣬵�ǰ��ȷ��Ϊ"<<current_accuracy<<endl; 
	}
	else
	{
		cout<<"\n\n�ڹ̶���������ģʽ�£�����"<<times<<"�ε����󣬵�ǰ��ȷ��Ϊ"<<current_accuracy<<endl; 
	}
	for(i=0;i<size;i++)
	{
		cout<<"x["<<i<<"]["<<k<<"] = "<<x[i][k]<<endl;
	}
	return 0; 
}
