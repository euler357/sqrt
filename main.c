#ifdef TEST
#include <stdio.h>
#include <math.h>
#endif

/* Function to print a character to the console using a syscall */
void myputchar(char ch)
{
	int ret=0;
		
	asm
    	(	
       		"syscall"
       		:"=a" (ret) 
       		: "0"(1), "D"(1), "S"(&ch), "d"(1)
       		: 
    	);
}

/* Implementation of Newtons Method */
float newtonsqrt(float number)
{
	double temp = 1.1;
	double diff = 1e88;
	while(diff > (number*1e-12))
	{
		temp = (number/temp + temp)/2.0;
		if((temp*temp)>=number)
			diff=temp*temp-number;
		else
			diff=number-(temp*temp);
	}
	return((float)temp);
}

/* Converts a float to a printable format and prints it */
void printfloat(float invalue)
{
	double tempf=0;
	int decimal_places=0,digits=10;
	char tempchar=0;

	tempf=invalue;

	for(int d=0;d<40;d++)
	{
		if(tempf>10)
		{
			decimal_places++;
			tempf=tempf*.1;
		}
	}

	if(decimal_places>digits)
		digits=decimal_places;

	for(int d=0;d<digits;d++)
	{
		tempchar=0x30+(int)tempf;
	 	myputchar(tempchar);
		tempf=(tempf-(int)tempf)*10;	
		if(decimal_places==d)
			myputchar('.');	
	}

	myputchar('\n');	
}

/* Main */
int main(void)
{
	float input_number=212313;
	float answer = 0;
	unsigned int n=0;

	char header[256]="\n******************************************\n* Chris's Sqrt without library functions *\n******************************************\n\nInput:      ";
	char string2[64]="Sqrt input: ";

	n=0;
	while((header[n]!=0)&&(n<255))
		myputchar(header[n++]);

	printfloat(input_number);
	answer = newtonsqrt(input_number);
	
	n=0;
	while((header[n]!=0)&&(n<63))
		myputchar(string2[n++]);

	printfloat(answer);

	myputchar('\n');

#ifdef TEST	
	printf("Test Values:\n");
	printf("Input:      %f\n",input_number);
	printf("Sqrt input: %f\n\n",sqrt(input_number));
#endif
	
}


