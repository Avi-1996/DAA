#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,temp,maxWait=40,n1,n2;
	float   price[]={200,400,50,80,100},wait[]={10,5,20,5,20},costwait[100];
	n1=5;
	clrscr();
	//printf("%f\n",(price[2] / wait[2]));
	for(i=0;i<n1;i++)
	{
		costwait[i]=(price[i] / wait[i]);
	}
	for(i=0;i<n1;i++)
	{

		for(j=i+1;j<n1;j++)
		{
			if(costwait[j] > costwait[i])
			{
				temp = costwait[i];
				costwait[i] = costwait[j];
				costwait[j] = temp;
				temp = price[i];
				price[i] = price[j];
				price[j] = temp;
				temp = price[i];

				price[i] = price[j];
				price[j] = temp;
			}
		}
	}
	for(i=0;i<n1;i++)
	{
		printf("%f  \n",costwait[i]);
	}

	getch();
	return 0;
}
