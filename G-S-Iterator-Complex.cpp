#include <iostream>
#include <complex>
#include <math.h>

#define uint unsigned int

using namespace std;

complex<double> x[1001][1001] = {0};	//x _i ^k
complex<double> y[1001] = {0};	//y _i ^k
complex<double> a[1001][1001] = {0};	//a _i _j

double accuracy = 1, current_accuracy = 2;//精确度 
uint times = 0;		//迭代次数 
uint size = 1;			//矩阵规模
uint i=0,j=0,k=0;	//矩阵元素下标与迭代次数上标 

bool method = true; //"true"表示迭代到指定精确度，"false"表示迭代到指定次数 

void GS_init(void)
{
	cout<<"请输入矩阵规模[uint]:"; 
	cin>>size;
	cout<<"\n是否使用精确度作为迭代指标[bool 0/1]:"; 
	cin>>method;
	if(method)
	{
		cout<<"\n选择了精确度作为迭代指标，请输入精确度:";
		cin>>accuracy;
	}
	else
	{
		cout<<"\n选择了迭代次数作为迭代指标，请输入次数:";
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
	complex<double> tmp = 0;	//没法直接在 标记1 处的括号内嵌套循环，因此使用临时变量来间接解决 
	uint n = 0; //循环变量不够用，临时设一个 
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
				
				x[i][k+1] = (y[i]-tmp)/a[i][i];	//标记1 详见上文 
			
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
				
				x[i][k+1] = (y[i]-tmp)/a[i][i];	//标记1 详见上文 
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
		cout<<"\n\n在固定精确度迭代模式下，经过"<<times<<"次迭代后，当前精确度为"<<current_accuracy<<endl; 
	}
	else
	{
		cout<<"\n\n在固定次数迭代模式下，经过"<<times<<"次迭代后，当前精确度为"<<current_accuracy<<endl; 
	}
	for(i=0;i<size;i++)
	{
		cout<<"x["<<i<<"]["<<k<<"] = "<<x[i][k]<<endl;
	}
	return 0; 
}
