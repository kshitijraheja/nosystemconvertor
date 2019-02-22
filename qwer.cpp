#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
long long bin_to_dec (char a[])
{
	int b,e;
	long long d,c;
	for (b=0,d=0,c=1,e=strlen(a)-1;e>=0;e--,c=c*2)
	{
		b=((int) a[e]-48)%10;
		d=d+b*c;
	}
return d;
}
long long oct_to_dec (long long a)
{
	long long c,d;
	int b;
	for (b=0,d=0,c=1;a!=0;a=a/10,c=c*8)
	{
		b=a%10;
		d=d+b*c;
	}
return d;
}
char * dec_to_hex(long long a)
{
   int c,d[100],i,e;
	const int b=16;
	static char r[100];
	for (i=0;a!=0;a/=b,i++)
	{
		c=a%b;
		d[i]=c;
	}
	i--;
	for (e=0;i>=0;i--,e++)
	{
		switch(d[i])
		{
			case 10:r[e]='A';
			break;
			case 11:r[e]='B';
			break;
		    case 12:r[e]='C';
			break;
			case 13:r[e]='D';
			break;
			case 14:r[e]='E';
			break;
			case 15:r[e]='F';
			break;
			default:r[e]=d[i]+48;
		}
	}
	r[e]='\0';
	return r;
//	if else goto for while do int char float int double void return signed unsigned short auto static extern const break case switch register sizeof typedef union struct default volatile 
	
	
}
long long dec_to_oct(long long a)
{
	long long c,d;
	const int b=8;
	for (d=1;a!=0;a/=b)
	{
		c=a%b;
		d=d*10+c;
	}
	a=d;
	for (d=0;!(a<9);a/=10)
	{
		c=a%10;
		d=d*10+c;
	}
	return d;
}
char *dec_to_bin(long long a)
{
	long long c;
	int i,l;
	static char e[100],d[100];
	const int b=2;
	for (i=0;a!=0;a/=b,i++)
	{
		c=a%b;
		d[i]=c+48;
	}
	
	for (l=0,i=strlen(d)-1;i>=0;i--,l++)
	{
		e[l]=d[i];
	}
	return e;
}
long long hex_to_dec(char a[])
{
char b;
int c,f;
long long d,e;
strupr(a);
c=strlen(a);
for(c=c-1,e=1,d=0;c>=0;c--,e*=16)
{
	switch(a[c])
		{
			case 'A':d=d+(e*10);
			break;
			case 'B':d=d+(e*11);
			break;
		    case 'C':d=d+(e*12);
			break;
			case 'D':d=d+(e*13);
			break;
			case 'E':d=d+(e*14);
			break;
			case 'F':d=d+(e*15);
			break;
			default:d=d+(e*( (int) a[c]-48));
		}
}
return d;
}
int main ()
{
start:	
char a[50],*e;
long long c,d;
long long b;
printf("enter from which to convert\n1 for binary\n2 for decimal\n3 for hexadecimal\n4 for octal\n");
scanf("%d",&c);
printf("enter to which to convert\n1 for binary\n2 for decimal\n3 for hexadecimal\n4 for octal\n");	
scanf("%d",&d);
if ((c>0&&c<5)&&(d<5&&d>0))
{
	printf("enter the value\n");
	if (c==3||c==1)
	{
		scanf("%s",a);
	}
	else
	{
		scanf("%lli",&b);
	}
switch(c)
{
		case 1:
			switch(d)
			{
					case 1:
						e=a;
				break;
					case 2:
					b=bin_to_dec(a);
				break;
					case 3:
					b=bin_to_dec(a);
					e=dec_to_hex(b);
				break;
					case 4:
					b=bin_to_dec(a);
					b=dec_to_oct(b);
			}
	break;
		case 2: 
				
				switch (d)
				{
					case 1: 
					e=dec_to_bin(b);
				break;
					case 2:
					
				break;
					case 3:
					e=dec_to_hex(b);
				break;
					case 4:
					b=dec_to_oct(b);
				
				}
	break;
		case 3:
				switch (d)
				{
					case 1:
					b=hex_to_dec(a);
					e=dec_to_bin(b);
				break;
					case 2:
					b=hex_to_dec(a);
				break;
					case 3:
					//printf("hello");	
					e=a;
					//puts(e);
				break;
					case 4:
					b=hex_to_dec(a);
					b=dec_to_oct(b);
				}
	break;
		case 4:
					switch (d)
				{
					case 1:
					b=oct_to_dec(b);
					e=dec_to_bin(b);
				break;
					case 2:
					b=oct_to_dec(b);
				break;
					case 3:
					b=oct_to_dec(b);
					e=dec_to_hex(b);
				break;
					case 4:b=b;
				}
	break;	
}
if (d==3||d==1)
{
	printf("\nthe result is %s",e);
}
else
{
	printf("\nthe result is %lli",b);
}
}
else
{
	
	MessageBox(NULL,"ERROR input now start again","ERROR",MB_OK);
	//clrscr();
	goto start;
}
return 0;	

}
