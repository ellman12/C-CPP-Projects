/////////////////////////////////////////////////////////////////////
//  File:  numericalRepresentation.cpp
/////////////////////////////////////////////////////////////////////
//
//  Purpose:  Illustration of fundamentals:
//
//    1:  Simple C/C++ implementation.  This file contains the 
//        definitions of the member functions declared in the 
//        class definitions in the .h file.
//    2:  Illustration of variable types and storage within memory.
//    3:  Introduction to pointers and explicit casting.
//    4:  Representations of data as decimal, binary, and hexidecimal.
//    5:  As this file is updated, there may be additional descriptions
//        and examples of floating point storage format as is 
//        currently implemented per IEEE375.
//
//  Programmer:  Larry Basegio
//               Mentor:  Caledonia Robotic Warriors team #5914
//
//  Compiler Environment:  This was developed on Microsoft Community
//  C/C++ but should be completely portable to other C++ compilers.
//
//  Revisions:  Original Development 04/21/2018, edited 06/13/2020.
//
//  Remarks:  This is intended to provide an example of good programming
//  practice.  Comments are generous, certain standards are adhered to:
//
//  1.  Locally declared variables are lower case with use of underscores
//      vs. capitals.  Names are indicative of type or function for
//      readability.
//  2.  Each function is described in a header that indicates purpose,
//      arguments, return values, and additional remarks.
//
//  4/24/2018:   Encapsulated the conversion to binary representation
//  into a single function that is called within the respective
//  type (overloaded) binary conversion functions.
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


//  This allows us to ignore Microsoft BS with regard to their "improvements".
#pragma warning(disable : 4996)

#include "numericalRepresentation.h"

extern 	char RetStr[];

/////////////////////////////////////////////////////////////////////
//  Function:  NumericRep::NumericRep(void)
/////////////////////////////////////////////////////////////////////
//
//  Purpose:  Simple constructor that assigns the value of the
//            private member variable to 4.  This is the number
//            of bytes for int, long, and float.
//
//  Arguments:void
//
//  Returns:  void
//
//  Remarks:
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
NumericRep::NumericRep(void)  {

	n_bytes=4;

}

/////////////////////////////////////////////////////////////////////
//  Function:  NumericRep::NumericRep(int bytes)
/////////////////////////////////////////////////////////////////////
//
//  Purpose:  An example of an overloaded constructor.  It must have
//            a different type or a compiler error will result.
//
//  Arguments:int bytes:  How many bytes to set the private member
//            variable to.
//
//  Returns:
//
//  Remarks:  Not of much use, simply included to illustrate the
//            process.
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
NumericRep::NumericRep(int bytes)  {

	n_bytes=bytes;

}

/////////////////////////////////////////////////////////////////////
//  Function:  NumericRep::~NumericRep()
/////////////////////////////////////////////////////////////////////
//
//  Purpose:  Default destructor.
//
//  Arguments:void
//
//  Returns:  no return value.
//
//  Remarks:
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
NumericRep::~NumericRep()  {

}

/////////////////////////////////////////////////////////////////////
//  Function:  int NumericRep::RepHexidecimal(long value)
/////////////////////////////////////////////////////////////////////
//
//  Purpose:  Prints to the console the submitted value in
//            hexidecimal (base 16).
//
//  Arguments:Accepts "value" as long, a 32 bit signed integer.
//
//  Returns:  Zero
//
//  Remarks:  Illustrates little endian memory layout for long.
//            flips the bytes for hexidecimal representation.
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
int NumericRep::RepHexidecimal(long value)  {
	int i;
	unsigned char *buf;
	unsigned char *cptr;


	n_bytes=sizeof(long);  // number of bytes will be four

	buf=(unsigned char*)malloc((size_t)(n_bytes*sizeof(unsigned char)));
	if(buf==NULL)return(-1);

	cptr=(unsigned char*)&value;  //  point to the address of value

	//  Break up individual bytes representing memory storage of value
	for(i=0;i<n_bytes;i++)  {
		buf[i]=*cptr++;
	}

	//  Print out memory layout as bytes separated by vertical lines.
	printf("\nMemory layout of %ld in hexidecimal.\n",value);
	for(i=0;i<n_bytes;i++)  {
		printf("0x%X | ",(unsigned int)buf[i]);
	}

	//  Print out memory layout as unicode symbols separated by vertical lines.
	printf("\nMemory layout of %ld in unicode.\n",value);
	for(i=0;i<n_bytes;i++)  {
		printf("%c | ",(unsigned int)buf[i]);
	}

	printf("\n\nIn hexidecimal this would be represented as 0x%X",value);
	printf("\nNote that the byte order is reversed from the memory configuration");
	return(0);
}

/////////////////////////////////////////////////////////////////////
//  Function:  int NumericRep::RepHexidecimal(float value)
/////////////////////////////////////////////////////////////////////
//
//  Purpose:  Represents the storage format of the submitted
//            float value in hexidecimal.  Tests the reverse
//            operation to restore the original decimal value.
//
//  Arguments:Accepts value as float.
//
//  Returns:  Zero
//
//  Remarks:  This is an exercise to demonstrate explicit casting
//            of pointer types to a fixed address in memory of
//            equal size.  A float occupies 32 bits as does an
//            int in most modern compilers.  "value" is orginally
//            4 bytes at an address syntactically specified as
//            &value.  We then look at those 4 bytes as a 32 bit
//            int and interpret the 32 bits as int.  We then
//            reverse the process.
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
int NumericRep::RepHexidecimal(float value)  {
	int i;
	int j;
	unsigned char *buf;
	unsigned char *hex_buf;
	unsigned char *cptr;

	long hex_rep=0;

	n_bytes=sizeof(float);  // number of bytes will be four

	buf=(unsigned char*)malloc((size_t)(n_bytes*sizeof(unsigned char)));
	if(buf==NULL)return(-1);

	hex_buf=(unsigned char*)malloc((size_t)(n_bytes*sizeof(unsigned char)));
	if(buf==NULL)return(-1);

	cptr=(unsigned char*)&value;  //  point to the address of value

	//  Break up individual bytes representing memory storage of value
	for(i=0;i<n_bytes;i++)  {
		buf[i]=*cptr++;
	}

	//  Print out memory layout as bytes separated by vertical lines.
	printf("\nMemory layout of %f in hexidecimal.\n",value);
	for(i=0;i<n_bytes;i++)  {
		printf("0x%X | ",(unsigned int)buf[i]);
	}

	//  Print out memory layout as unicode symbols separated by vertical lines.
	printf("\nMemory layout of %f in unicode.\n",value);
	for(i=0;i<n_bytes;i++)  {
		printf("%c | ",(unsigned int)buf[i]);
	}

	//  Next we flip the bytes to provide the floating point representation
	//  in hexidecimal - essentially binary.
	j=0;
	for(i=(n_bytes-1);i>=0;i--)  {
		hex_buf[j]=buf[i];
		j++;
	}

	printf("\n\n");
	printf("bytes in reverse order\n");
	for(i=0;i<n_bytes;i++)  {
		printf("0x%X | ",(unsigned int)hex_buf[i]);
	}

	for(j=0;j<n_bytes;j++)  {
		hex_rep+=buf[j]<<8*j;
	}

	printf("\n\nIn hexidecimal %f would be represented as 0x%X",value,hex_rep);
	printf("\nNote that the byte order is reversed from the memory configuration");

	if(hex_buf!=NULL)free(hex_buf);
	if(buf!=NULL)free(buf);
	return(0);
}

/////////////////////////////////////////////////////////////////////
//  Function:  int NumericRep::RepHexidecimal(double value)
/////////////////////////////////////////////////////////////////////
//
//  Purpose:  Very similar to the previous exercise but with some
//            significant differences with regard to data type.
//
//            1.  A double precision floating point type occupies
//                64 bits or 8 bytes.
//            2.  Curiously enough, many modern compilers have int
//                and long the same size (4 bytes or 32 bits).  Some
//                compilers support type "long long" but not all.
//            3.  In this example we will use the data type "char"
//                to dissect the double value into individual bytes
//                and then interpret as hexidecimal.  There may be
//                a simpler way to do this but this method illustrates
//                a most fundamental process for computer science
//                and electrical engineering where your data could
//                10-bits, 12-bits, 20-bits, etc.
//            4.  This stuff will not be taught in schools typically
//                but is of widespread use in the industries I have
//                worked in.
//
//  Arguments:  Accepts a double as value.
//
//  Returns:  Zero.
//
//  Remarks:
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
int NumericRep::RepHexidecimal(double value)  {
	int i;
	int j;

	unsigned char *buf;
	unsigned char *hex_buf;
	unsigned char *cptr;

	n_bytes=sizeof(double);  // number of bytes will be eight

	buf=(unsigned char*)malloc((size_t)(n_bytes*sizeof(unsigned char)));
	if(buf==NULL)return(-1);

	hex_buf=(unsigned char*)malloc((size_t)(n_bytes*sizeof(unsigned char)));
	if(buf==NULL)return(-1);

	cptr=(unsigned char*)&value;  //  point to the address of value

	//  Break up individual bytes representing memory storage of value
	for(i=0;i<n_bytes;i++)  {
		buf[i]=*cptr++;
	}

	//  Print out memory layout as bytes separated by vertical lines.	
	printf("\nMemory layout of %lf in hexidecimal.\n",value);
	for(i=0;i<n_bytes;i++)  {
		printf("0x%X | ",(unsigned int)buf[i]);
	}

	//  Print out memory layout as unicode symbols separated by vertical lines.
	printf("\nMemory layout of %lf in unicode.\n",value);
	for(i=0;i<n_bytes;i++)  {
		printf("%c | ",buf[i]);
	}

	//  Next we flip the bytes to provide the floating point representation
	//  in hexidecimal - essentially binary.
	j=0;
	for(i=(n_bytes-1);i>=0;i--)  {
		hex_buf[j]=buf[i];
		j++;
	}
	
	printf("\n\n");
	printf("bytes in reverse order\n");
	for(i=0;i<n_bytes;i++)  {
		printf("0x%X | ",(unsigned int)hex_buf[i]);
	}

	printf("\n\nIn hexidecimal %lf would be represented as:\n",value);
	printf("0x%X",hex_buf[0]);
	for(i=1;i<n_bytes;i++)  {
		printf("%X",hex_buf[i]);
	}
	printf("\nNote that the byte order is reversed from the memory configuration");

	if(hex_buf!=NULL)free(hex_buf);
	if(buf!=NULL)free(buf);
	return(0);
}

/////////////////////////////////////////////////////////////////////
//  Function:  int NumericRep::RepBinary(long value)
/////////////////////////////////////////////////////////////////////
//
//  Purpose:  Here we attempt to represent the binary representation
//            of the submitted number.  Learning that Intel and 
//            AMD processors use the "little endian" storage format
//            is essential.
//
//  Arguments:Accepts a long as value.
//
//  Returns:
//
//  Remarks:  We introduce the concept of a "nibble", 4-bits or
//            one half of a byte.  If we convert our values to
//            hexidecimal the interpretation of each nibble as
//            a string becomes easier.  The interpretation is
//            evident in the switch statement in the function
//            code.
//
//            Note that when playing with character strings, one
//            needs to remember that a string is always terminated
//            with the NULL character, i.e., '\0'.
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
int NumericRep::RepBinary(long value)  {
	int debug=1;

	int i;
	int j;

	unsigned char *cptr;
	unsigned char *buf;

	char *bin_rep;  //  note that 4 bytes implies 8 nibbles.  8 nibbles
	                   //  are represented here by 4 char each plus one for the '\0'.
	                   //  Hence we need 33.
	long *l_ptr;

	n_bytes=sizeof(long);  //  The answer will be 4.

	//***********************************************************************
	//  memory allocation - for illustrative purposes we use dynamic memory
	//  allocation.  Note that it must be released at the end of this 
	//  function or memory leaks and unpredictable behaviour can result.
    //***********************************************************************

	//  first our buffer.
	buf=(unsigned char*)malloc((size_t)(n_bytes*sizeof(unsigned char)));
	if(buf==NULL)return(-1);

	bin_rep=(char*)malloc((size_t)(129*sizeof(char)));

	//************************************************************************

	cptr=(unsigned char*)&value;  //  point to the location of the LSByte of value
	                              //  remember Intel stores as little endian.
	//  load buf with the raw bytes
    //  buf[0] should be the LSByte
	for(i=0;i<n_bytes;i++)  {
		buf[i]=*cptr++;
	}

	//  This should display a proper storage representation (little endian)
	if(debug)  {
		printf("\n\n\nStorage representation of %ld as long\n",value);
		printf("\nNote that lower memory addresses proceed from left to right (little endian).\n");
		for(i=0;i<n_bytes;i++)  {
			printf("0x%X | ",(unsigned int)buf[i]);
		}
		printf("\n\n\nStorage representation in UNICODE\n");
		for(i=0;i<n_bytes;i++)  {
			printf("%c | ",(unsigned int)buf[i]);
		}

		printf("\n\nInterpretation of buf[] as long:\n");
		l_ptr=(long*)buf;
		printf("%ld",*l_ptr);
	}

	Convert2Binary(buf);
	
	//***************************************************************
	//  memory cleanup
	//***************************************************************
	if(bin_rep!=NULL)free(bin_rep);
	if(buf!=NULL)free(buf);

	return(0);
}

/////////////////////////////////////////////////////////////////////
//  Function:  int NumericRep::RepBinary(float value)  
/////////////////////////////////////////////////////////////////////
//
//  Purpose:
//
//  Arguments:
//
//  Returns:
//
//  Remarks:
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
int NumericRep::RepBinary(float value)  {
	int debug=1;

	int i;
	int j;

	unsigned char *cptr;
	unsigned char *buf;

	char *bin_rep;  //  note that 4 bytes implies 8 nibbles.  8 nibbles
	                   //  are represented here by 4 char each plus one for the '\0'.
	                   //  Hence we need 33.
	float *f_ptr;

	n_bytes=sizeof(float);  //  The answer will be 4.

	//***********************************************************************
	//  memory allocation - for illustrative purposes we use dynamic memory
	//  allocation.  Note that it must be released at the end of this 
	//  function or memory leaks and unpredictable behaviour can result.
    //***********************************************************************

	//  first our buffer.
	buf=(unsigned char*)malloc((size_t)(n_bytes*sizeof(unsigned char)));
	if(buf==NULL)return(-1);

	bin_rep=(char*)malloc((size_t)(129*sizeof(char)));

	//************************************************************************

	cptr=(unsigned char*)&value;  //  point to the location of the LSByte of value
	                              //  remember Intel stores as little endian.
	//  load buf with the raw bytes
    //  buf[0] should be the LSByte
	for(i=0;i<n_bytes;i++)  {
		buf[i]=*cptr++;
	}

	//  This should display a proper storage representation (little endian)
	if(debug)  {
		printf("\n\n\nStorage representation of %f as float\n",value);
		printf("\nNote that lower memory addresses proceed from left to right (little endian).\n");
		for(i=0;i<n_bytes;i++)  {
			printf("0x%X | ",(unsigned int)buf[i]);
		}
		printf("\n\n\nStorage representation in UNICODE\n",value);
		for(i=0;i<n_bytes;i++)  {
			printf("%c | ",(unsigned int)buf[i]);
		}

		printf("\n\nInterpretation of buf[] as float:\n");
		f_ptr=(float*)buf;
		printf("%f",*f_ptr);
	}

	Convert2Binary(buf);

	//***************************************************************
	//  memory cleanup
	//***************************************************************
	if(bin_rep!=NULL)free(bin_rep);
	if(buf!=NULL)free(buf);

	return(0);
}

/////////////////////////////////////////////////////////////////////
//  Function:
/////////////////////////////////////////////////////////////////////
//
//  Purpose:
//
//  Arguments:
//
//  Returns:
//
//  Remarks:
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
int NumericRep::RepBinary(double value)  {
	int debug=1;

	int i;
	int j;

	unsigned char *cptr;
	unsigned char *buf;
	char *bin_rep;

	double *d_ptr;

	n_bytes=sizeof(double);  //  The answer will be 8.

	//***********************************************************************
	//  memory allocation - for illustrative purposes we use dynamic memory
	//  allocation.  Note that it must be released at the end of this 
	//  function or memory leaks and unpredictable behaviour can result.
    //***********************************************************************
	//  first our buffer.
	buf=(unsigned char*)malloc((size_t)(n_bytes*sizeof(unsigned char)));
	if(buf==NULL)return(-1);

	bin_rep=(char*)malloc((size_t)(129*sizeof(char)));

	//************************************************************************

	cptr=(unsigned char*)&value;  //  point to the location of the LSByte of value
	                              //  remember Intel stores as little endian.
	//  load buf with the raw bytes
    //  buf[0] should be the LSByte
	for(i=0;i<n_bytes;i++)  {
		buf[i]=*cptr++;
	}

	//  This should display a proper storage representation (little endian)
	if(debug)  {
		printf("\n\n\nStorage representation of %lf as double\n",value);
		printf("\nNote that lower memory addresses proceed from left to right (little endian).\n");
		for(i=0;i<n_bytes;i++)  {
			printf("0x%X | ",(unsigned int)buf[i]);
		}
		printf("\n\n\nStorage representation in UNICODE\n",value);
		for(i=0;i<n_bytes;i++)  {
			printf("%c | ",(unsigned int)buf[i]);
		}

		printf("\n\nInterpretation of buf[] as double:\n");
		d_ptr=(double*)buf;
		printf("%lf",*d_ptr);
	}

	Convert2Binary(buf);

	//***************************************************************
	//  memory cleanup
	//***************************************************************
	if(bin_rep!=NULL)free(bin_rep);
	if(buf!=NULL)free(buf);

	return(0);
}


/////////////////////////////////////////////////////////////////////
//  Function:  char* NumericRep::Convert2Binary( ... )
/////////////////////////////////////////////////////////////////////
//
//  Purpose:  Create a string that represents the binary configuration
//            of the specified number and type.
//
//  Arguments:  Accepts an array of unsigned char[] that is ordered
//              little endian - exactly as ordered in memory.
//
//  Returns:  An int error code.  '-1' indicates a memory allocation
//            failure, '0' indicates successful execution.
//
//  Remarks:  This is a rather complex function, used in many
//            places so it was better to create it's own body.
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
int NumericRep::Convert2Binary(unsigned char* buf)
{
	int debug=1;

	int i;
	int j;

	//char RetStr[150];  //  return string - extra large
	char **substring;

	unsigned int *nibble;

	// for each byte there are 2"nibbles.  We create a double array of 
	// strings.  There will be 16 strings (one for each nibble), 
	// each string will have 4 characters
	// (0's and 1's) + the NULL character for a total of 5.
	//  First we create the space for the array of arrays and
	//  then we allocate the individual arrays.  This is how it's
	//  done!
	substring=(char**)malloc((size_t)((2*n_bytes)*sizeof(char*)));
	if(substring==NULL)return(-1);
	for(i=0;i<2*n_bytes;i++)  {
		substring[i]=(char*)malloc((size_t)(8*sizeof(char)));  //  include NULL character
		if (substring[i] == NULL)return(-1);
	}
	
	//  We will have 8 nibbles.
	nibble=(unsigned int*)malloc((size_t)(2*n_bytes*sizeof(unsigned int)));
	if(nibble==NULL)return(-1);

    // Number of 4-bit nibbles will be twice the number of bytes
	// We attempt to reverse the order of dissecting the stored
	// bytes to acheive a proper bit representation.
	//
	printf("\n\nBreak bytes into 4-bit nibbles to aid in binary representation.\n");
	j=0;
	for(i=0;i<(2*n_bytes)-1;i+=2)  {
		nibble[i]=(unsigned int)(buf[j]&0xF);
		nibble[i+1]=(unsigned int)((buf[j]>>4)&0xF);
		if(debug)  {
			printf("\nnibble[%d]=0x%X\n",i,(int)nibble[i]);
			printf("\nnibble[%d]=0x%X\n",i+1,(int)nibble[i+1]);
		}
		j++;
	}

	//  Determine the string representations of each nibble, converts
	//  hexidecimal to 4-bit strings.  The vertical separators make
	//  reading the binary representation easier, converting to
	//  hexidecimal and back and forth, etc..
	for(i=0;i<(2*n_bytes);i++)  {

		switch(nibble[i])  {

		case 0 :
			strcpy(substring[i],"0000 | ");
			break;
		case 1 :
			strcpy(substring[i],"0001 | ");
			break;
		case 2 :
			strcpy(substring[i],"0010 | ");
			break;
		case 3 :
			strcpy(substring[i],"0011 | ");
			break;
		case 4 :
			strcpy(substring[i],"0100 | ");
			break;
		case 5 :
			strcpy(substring[i],"0101 | ");
			break;
		case 6 :
			strcpy(substring[i],"0110 | ");
			break;
		case 7 :
			strcpy(substring[i],"0111 | ");
			break;
		case 8 :
			strcpy(substring[i],"1000 | ");
			break;
		case 9 :
			strcpy(substring[i],"1001 | ");
			break;
		case 0xA :
			strcpy(substring[i],"1010 | ");
			break;
		case 0xB :
			strcpy(substring[i],"1011 | ");
			break;
	    case 0xC :
			strcpy(substring[i],"1100 | ");
			break;
		case 0xD :
			strcpy(substring[i],"1101 | ");
			break;
		case 0xE :
			strcpy(substring[i],"1110 | ");
			break;
		case 0xF :
			strcpy(substring[i],"1111 | ");
			break;
		}
	}

	strcpy(RetStr,substring[(2*n_bytes)-1]);

	//  Assemble the binary representation, nibbles in reverse order
	//  to get MSBit to LSBit (left to right)
	for(i=(2*n_bytes)-2;i>=0;i--)  {
		strcat(RetStr,substring[i]);
	}


	//  Free memory in reverse order of allocation
	if(nibble!=NULL)free(nibble);

	for(i=0;i<(2*n_bytes);i++)  {
		if(substring[i]!=NULL)free(substring[i]);
	}
	if(substring!=NULL)free(substring);
	
	return(0);
}

























/*
	int debug=1;

	int i;
	int j;
	int n_bytes;
	unsigned int *nibble;

	unsigned char *cptr;
	unsigned char *buf;
	char **substring;
	char bin_rep[65];

	double *d_ptr;  //  pointer to float to evaluate memory contents

	n_bytes=sizeof(double);

	//***********************************************************************
	//  memory allocation
    //***********************************************************************
	buf=(unsigned char*)malloc((size_t)(n_bytes*sizeof(unsigned char)));
	if(buf==NULL)return(-1);


	// for each byte there are 2 nibbles
	substring=(char**)malloc((size_t)((2*n_bytes)*sizeof(char*)));
	if(substring==NULL)return(-1);
	for(i=0;i<2*n_bytes;i++)  {
		substring[i]=(char*)malloc((size_t)(5*sizeof(char)));  //  include NULL character
	}
	
	nibble=(unsigned int*)malloc((size_t)(2*n_bytes*sizeof(unsigned int)));
	if(nibble==NULL)return(-1);

	printf("\n\nMemory configuration and binary representation of %.4f\n\n",value);

	//************************************************************************
	cptr=(unsigned char*)&value;  //  point to the location of the LSByte of value
	                              //  remember Intel stores as little endian.
	//  load buf with the raw bytes
    //  buf[0] should be the LSByte
	for(i=0;i<n_bytes;i++)  {
		buf[i]=*cptr++;
	}
	
	printf("\n\nStorage order is LSByte to MSByte (little endian)");
	for(i=0;i<n_bytes;i++)  {
		printf("\nbuf[%d]=0x%X",i,(unsigned int)buf[i]);
	}
	
	printf("\n\nTest of memory contents.\n");
	d_ptr=(double*)buf;
	printf("\nDereferenced pointer to buf = %.4lf\n",*d_ptr);
	
	printf("\nBreak up bytes into 4-bit nibbles.\n");
    // Number of 4-bit nibbles will be twice the number of bytes
	// We attempt to reverse the order of dissecting the stored
	// bytes to acheive a proper bit representation.
	j=0;
	for(i=0;i<(2*n_bytes)-1;i+=2)  {
		nibble[i]=(unsigned int)(buf[j]&0xF);
		nibble[i+1]=(unsigned int)((buf[j]>>4)&0xF);
		if(debug)  {
			printf("\nnibble[%d]=0x%X\n",i,(int)nibble[i]);
			printf("\nnibble[%d]=0x%X\n",i+1,(int)nibble[i+1]);
		}
		j++;
	}



	//  Determine the string representations of each nibble
	for(i=0;i<(2*n_bytes);i++)  {

		switch(nibble[i])  {

		case 0 :
			strcpy(substring[i],"0000");
			break;
		case 1 :
			strcpy(substring[i],"0001");
			break;
		case 2 :
			strcpy(substring[i],"0010");
			break;
		case 3 :
			strcpy(substring[i],"0011");
			break;
		case 4 :
			strcpy(substring[i],"0100");
			break;
		case 5 :
			strcpy(substring[i],"0101");
			break;
		case 6 :
			strcpy(substring[i],"0110");
			break;
		case 7 :
			strcpy(substring[i],"0111");
			break;
		case 8 :
			strcpy(substring[i],"1000");
			break;
		case 9 :
			strcpy(substring[i],"1001");
			break;
		case 0xA :
			strcpy(substring[i],"1010");
			break;
		case 0xB :
			strcpy(substring[i],"1011");
			break;
	    case 0xC :
			strcpy(substring[i],"1100");
			break;
		case 0xD :
			strcpy(substring[i],"1101");
			break;
		case 0xE :
			strcpy(substring[i],"1110");
			break;
		case 0xF :
			strcpy(substring[i],"1111");
			break;
		}
	}

	strcpy(bin_rep,substring[(2*n_bytes)-1]);

	//  Assemble the binary representation
	for(i=(2*n_bytes)-2;i>=0;i--)  {
		strcat(bin_rep,substring[i]);
	}

	printf("\n\ndouble value %.4lf represented in binary = %s",value,bin_rep);

	//***************************************************************
	//  memory cleanup
	//***************************************************************
	if(nibble!=NULL)free(nibble);

	for(i=0;i<(2*n_bytes);i++)  {
		if(substring[i]!=NULL)free(substring[i]);
	}
	if(substring!=NULL)free(substring);
	if(buf!=NULL)free(buf);

	return(0);
}
*/

/////////////////////////////////////////////////////////////////////
//  Function:
/////////////////////////////////////////////////////////////////////
//
//  Purpose:
//
//  Arguments:
//
//  Returns:
//
//  Remarks:
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/*
int NumericRep::RepBinary(double value)  {
	int debug=1;

	int i;
	int j;
	unsigned int *nibble;

	unsigned char *cptr;
	unsigned char *buf;
	char **substring;
	char bin_rep[129];  //  note that 4 bytes implies 8 nibbles.  8 nibbles
	                   //  are represented here by 4 char each plus one for the '\0'.
	                   //  Hence we need 33.
	double *d_ptr;

	n_bytes=sizeof(double);  //  The answer will be 4.

	//***********************************************************************
	//  memory allocation - for illustrative purposes we use dynamic memory
	//  allocation.  Note that it must be released at the end of this 
	//  function or memory leaks and unpredictable behaviour can result.
    //***********************************************************************

	//  first our buffer.
	buf=(unsigned char*)malloc((size_t)(n_bytes*sizeof(unsigned char)));
	if(buf==NULL)return(-1);

	
	// for each byte there are 2"nibbles.  We create a double array of 
	// strings.  There will be 16 strings (one for each nibble), 
	// each string will have 4 characters
	// (0's and 1's) + the NULL character for a total of 5.
	substring=(char**)malloc((size_t)((2*n_bytes)*sizeof(char*)));
	if(substring==NULL)return(-1);
	for(i=0;i<2*n_bytes;i++)  {
		substring[i]=(char*)malloc((size_t)(8*sizeof(char)));  //  include NULL character
	}
	
	//  We will have 8 nibbles.
	nibble=(unsigned int*)malloc((size_t)(2*n_bytes*sizeof(unsigned int)));
	if(nibble==NULL)return(-1);

	//************************************************************************

	cptr=(unsigned char*)&value;  //  point to the location of the LSByte of value
	                              //  remember Intel stores as little endian.
	//  load buf with the raw bytes
    //  buf[0] should be the LSByte
	for(i=0;i<n_bytes;i++)  {
		buf[i]=*cptr++;
	}

	//  This should display a proper storage representation (little endian)
	if(debug)  {
		printf("\n\n\nStorage representation of %lf as double\n",value);
		printf("\nNote that lower memory addresses proceed from left to right (little endian).\n");
		for(i=0;i<n_bytes;i++)  {
			printf("0x%X | ",(unsigned int)buf[i]);
		}
		printf("\n\n\nStorage representation in UNICODE\n",value);
		for(i=0;i<n_bytes;i++)  {
			printf("%c | ",(unsigned int)buf[i]);
		}

		printf("\n\nInterpretation of buf[] as double:\n");
		d_ptr=(double*)buf;
		printf("%lf",*d_ptr);
	}
	
    // Number of 4-bit nibbles will be twice the number of bytes
	// We attempt to reverse the order of dissecting the stored
	// bytes to acheive a proper bit representation.
	//
	printf("\n\nBreak bytes into 4-bit nibbles to aid in binary representation.\n");
	j=0;
	for(i=0;i<(2*n_bytes)-1;i+=2)  {
		nibble[i]=(unsigned int)(buf[j]&0xF);
		nibble[i+1]=(unsigned int)((buf[j]>>4)&0xF);
		if(debug)  {
			printf("\nnibble[%d]=0x%X\n",i,(int)nibble[i]);
			printf("\nnibble[%d]=0x%X\n",i+1,(int)nibble[i+1]);
		}
		j++;
	}


	//  Determine the string representations of each nibble
	for(i=0;i<(2*n_bytes);i++)  {

		switch(nibble[i])  {

		case 0 :
			strcpy(substring[i],"0000 | ");
			break;
		case 1 :
			strcpy(substring[i],"0001 | ");
			break;
		case 2 :
			strcpy(substring[i],"0010 | ");
			break;
		case 3 :
			strcpy(substring[i],"0011 | ");
			break;
		case 4 :
			strcpy(substring[i],"0100 | ");
			break;
		case 5 :
			strcpy(substring[i],"0101 | ");
			break;
		case 6 :
			strcpy(substring[i],"0110 | ");
			break;
		case 7 :
			strcpy(substring[i],"0111 | ");
			break;
		case 8 :
			strcpy(substring[i],"1000 | ");
			break;
		case 9 :
			strcpy(substring[i],"1001 | ");
			break;
		case 0xA :
			strcpy(substring[i],"1010 | ");
			break;
		case 0xB :
			strcpy(substring[i],"1011 | ");
			break;
	    case 0xC :
			strcpy(substring[i],"1100 | ");
			break;
		case 0xD :
			strcpy(substring[i],"1101 | ");
			break;
		case 0xE :
			strcpy(substring[i],"1110 | ");
			break;
		case 0xF :
			strcpy(substring[i],"1111 | ");
			break;
		}
	}

	strcpy(bin_rep,substring[(2*n_bytes)-1]);

	//  Assemble the binary representation, nibbles in reverse order
	//  to get MSBit to LSBit (left to right)
	for(i=(2*n_bytes)-2;i>=0;i--)  {
		strcat(bin_rep,substring[i]);
	}

	printf("\n\ndouble value %lf represented in binary = \n%s",value,bin_rep);

	//***************************************************************
	//  memory cleanup
	//***************************************************************
	if(nibble!=NULL)free(nibble);

	for(i=0;i<(2*n_bytes);i++)  {
		if(substring[i]!=NULL)free(substring[i]);
	}
	if(substring!=NULL)free(substring);
	if(buf!=NULL)free(buf);

	return(0);
}
*/
/*
int NumericRep::RepBinary(float value)  {
	int debug=1;

	int i;
	int j;
	//int n_bytes;
	unsigned int *nibble;

	unsigned char *cptr;
	unsigned char *buf;
	char **substring;
	char bin_rep[65];  //  note that 4 bytes implies 8 nibbles.  8 nibbles
	                   //  are represented here by 4 char each plus one for the '\0'.
	                   //  Hence we need 33.
	float *f_ptr;

	n_bytes=sizeof(float);  //  The answer will be 4.

	//***********************************************************************
	//  memory allocation - for illustrative purposes we use dynamic memory
	//  allocation.  Note that it must be released at the end of this 
	//  function or memory leaks and unpredictable behaviour can result.
    //***********************************************************************

	//  first our buffer.
	buf=(unsigned char*)malloc((size_t)(n_bytes*sizeof(unsigned char)));
	if(buf==NULL)return(-1);

	
	// for each byte there are 2"nibbles.  We create a double array of 
	// strings.  There will be 16 strings (one for each nibble), 
	// each string will have 4 characters
	// (0's and 1's) + the NULL character for a total of 5.
	substring=(char**)malloc((size_t)((2*n_bytes)*sizeof(char*)));
	if(substring==NULL)return(-1);
	for(i=0;i<2*n_bytes;i++)  {
		substring[i]=(char*)malloc((size_t)(8*sizeof(char)));  //  include NULL character
	}
	
	//  We will have 8 nibbles.
	nibble=(unsigned int*)malloc((size_t)(2*n_bytes*sizeof(unsigned int)));
	if(nibble==NULL)return(-1);

	//************************************************************************

	cptr=(unsigned char*)&value;  //  point to the location of the LSByte of value
	                              //  remember Intel stores as little endian.
	//  load buf with the raw bytes
    //  buf[0] should be the LSByte
	for(i=0;i<n_bytes;i++)  {
		buf[i]=*cptr++;
	}

	//  This should display a proper storage representation (little endian)
	if(debug)  {
		printf("\n\n\nStorage representation of %f as float\n",value);
		printf("\nNote that lower memory addresses proceed from left to right (little endian).\n");
		for(i=0;i<n_bytes;i++)  {
			printf("0x%X | ",(unsigned int)buf[i]);
		}
		printf("\n\n\nStorage representation in UNICODE\n",value);
		for(i=0;i<n_bytes;i++)  {
			printf("%c | ",(unsigned int)buf[i]);
		}

		printf("\n\nInterpretation of buf[] as float:\n");
		f_ptr=(float*)buf;
		printf("%f",*f_ptr);
	}
	
    // Number of 4-bit nibbles will be twice the number of bytes
	// We attempt to reverse the order of dissecting the stored
	// bytes to acheive a proper bit representation.
	//
	printf("\n\nBreak bytes into 4-bit nibbles to aid in binary representation.\n");
	j=0;
	for(i=0;i<(2*n_bytes)-1;i+=2)  {
		nibble[i]=(unsigned int)(buf[j]&0xF);
		nibble[i+1]=(unsigned int)((buf[j]>>4)&0xF);
		if(debug)  {
			printf("\nnibble[%d]=0x%X\n",i,(int)nibble[i]);
			printf("\nnibble[%d]=0x%X\n",i+1,(int)nibble[i+1]);
		}
		j++;
	}


	//  Determine the string representations of each nibble
	for(i=0;i<(2*n_bytes);i++)  {

		switch(nibble[i])  {

		case 0 :
			strcpy(substring[i],"0000 | ");
			break;
		case 1 :
			strcpy(substring[i],"0001 | ");
			break;
		case 2 :
			strcpy(substring[i],"0010 | ");
			break;
		case 3 :
			strcpy(substring[i],"0011 | ");
			break;
		case 4 :
			strcpy(substring[i],"0100 | ");
			break;
		case 5 :
			strcpy(substring[i],"0101 | ");
			break;
		case 6 :
			strcpy(substring[i],"0110 | ");
			break;
		case 7 :
			strcpy(substring[i],"0111 | ");
			break;
		case 8 :
			strcpy(substring[i],"1000 | ");
			break;
		case 9 :
			strcpy(substring[i],"1001 | ");
			break;
		case 0xA :
			strcpy(substring[i],"1010 | ");
			break;
		case 0xB :
			strcpy(substring[i],"1011 | ");
			break;
	    case 0xC :
			strcpy(substring[i],"1100 | ");
			break;
		case 0xD :
			strcpy(substring[i],"1101 | ");
			break;
		case 0xE :
			strcpy(substring[i],"1110 | ");
			break;
		case 0xF :
			strcpy(substring[i],"1111 | ");
			break;
		}
	}

	strcpy(bin_rep,substring[(2*n_bytes)-1]);

	//  Assemble the binary representation, nibbles in reverse order
	//  to get MSBit to LSBit (left to right)
	for(i=(2*n_bytes)-2;i>=0;i--)  {
		strcat(bin_rep,substring[i]);
	}

	printf("\n\nfloat value %f represented in binary = %s",value,bin_rep);

	//***************************************************************
	//  memory cleanup
	//***************************************************************
	if(nibble!=NULL)free(nibble);

	for(i=0;i<(2*n_bytes);i++)  {
		if(substring[i]!=NULL)free(substring[i]);
	}
	if(substring!=NULL)free(substring);
	if(buf!=NULL)free(buf);

	return(0);
}

*/

/*
int NumericRep::RepBinary(long value)  {
	int debug=1;

	int i;
	int j;
	//int n_bytes;
	unsigned int *nibble;

	unsigned char *cptr;
	unsigned char *buf;
	char **substring;
	char bin_rep[65];  //  note that 4 bytes implies 8 nibbles.  8 nibbles
	                   //  are represented here by 4 char each plus one for the '\0'.
	                   //  Hence we need 33.
	long *l_ptr;

	n_bytes=sizeof(long);  //  The answer will be 4.

	//***********************************************************************
	//  memory allocation - for illustrative purposes we use dynamic memory
	//  allocation.  Note that it must be released at the end of this 
	//  function or memory leaks and unpredictable behaviour can result.
    //***********************************************************************

	//  first our buffer.
	buf=(unsigned char*)malloc((size_t)(n_bytes*sizeof(unsigned char)));
	if(buf==NULL)return(-1);

	
	// for each byte there are 2"nibbles.  We create a double array of 
	// strings.  There will be 16 strings (one for each nibble), 
	// each string will have 4 characters
	// (0's and 1's) + the NULL character for a total of 5.
	substring=(char**)malloc((size_t)((2*n_bytes)*sizeof(char*)));
	if(substring==NULL)return(-1);
	for(i=0;i<2*n_bytes;i++)  {
		substring[i]=(char*)malloc((size_t)(8*sizeof(char)));  //  include NULL character
	}
	
	//  We will have 8 nibbles.
	nibble=(unsigned int*)malloc((size_t)(2*n_bytes*sizeof(unsigned int)));
	if(nibble==NULL)return(-1);

	//************************************************************************

	cptr=(unsigned char*)&value;  //  point to the location of the LSByte of value
	                              //  remember Intel stores as little endian.
	//  load buf with the raw bytes
    //  buf[0] should be the LSByte
	for(i=0;i<n_bytes;i++)  {
		buf[i]=*cptr++;
	}

	//  This should display a proper storage representation (little endian)
	if(debug)  {
		printf("\n\n\nStorage representation of %ld as long\n",value);
		printf("\nNote that lower memory addresses proceed from left to right (little endian)(.\n");
		for(i=0;i<n_bytes;i++)  {
			printf("0x%X | ",(unsigned int)buf[i]);
		}
		printf("\n\n\nStorage representation in UNICODE\n",value);
		for(i=0;i<n_bytes;i++)  {
			printf("%c | ",(unsigned int)buf[i]);
		}

		printf("\n\nInterpretation of buf[] as long in hex:\n");
		printf("Note reverse order of bytes to properly interpret value.\n");
		l_ptr=(long*)buf;
		printf("\n0x%X",*l_ptr);

		printf("\n\nInterpretation of buf[] as long in decimal:\n");
		l_ptr=(long*)buf;
		printf("%ld",*l_ptr);
	}
	
    // Number of 4-bit nibbles will be twice the number of bytes
	// We attempt to reverse the order of dissecting the stored
	// bytes to acheive a proper bit representation.
	//
	printf("\n\nBreak bytes into 4-bit nibbles to aid in binary representation.\n");
	j=0;
	for(i=0;i<(2*n_bytes)-1;i+=2)  {
		nibble[i]=(unsigned int)(buf[j]&0xF);
		nibble[i+1]=(unsigned int)((buf[j]>>4)&0xF);
		if(debug)  {
			printf("\nnibble[%d]=0x%X\n",i,(int)nibble[i]);
			printf("\nnibble[%d]=0x%X\n",i+1,(int)nibble[i+1]);
		}
		j++;
	}


	//  Determine the string representations of each nibble
	for(i=0;i<(2*n_bytes);i++)  {

		switch(nibble[i])  {

		case 0 :
			strcpy(substring[i],"0000 | ");
			break;
		case 1 :
			strcpy(substring[i],"0001 | ");
			break;
		case 2 :
			strcpy(substring[i],"0010 | ");
			break;
		case 3 :
			strcpy(substring[i],"0011 | ");
			break;
		case 4 :
			strcpy(substring[i],"0100 | ");
			break;
		case 5 :
			strcpy(substring[i],"0101 | ");
			break;
		case 6 :
			strcpy(substring[i],"0110 | ");
			break;
		case 7 :
			strcpy(substring[i],"0111 | ");
			break;
		case 8 :
			strcpy(substring[i],"1000 | ");
			break;
		case 9 :
			strcpy(substring[i],"1001 | ");
			break;
		case 0xA :
			strcpy(substring[i],"1010 | ");
			break;
		case 0xB :
			strcpy(substring[i],"1011 | ");
			break;
	    case 0xC :
			strcpy(substring[i],"1100 | ");
			break;
		case 0xD :
			strcpy(substring[i],"1101 | ");
			break;
		case 0xE :
			strcpy(substring[i],"1110 | ");
			break;
		case 0xF :
			strcpy(substring[i],"1111 | ");
			break;
		}
	}

	strcpy(bin_rep,substring[(2*n_bytes)-1]);

	//  Assemble the binary representation, nibbles in reverse order
	//  to get MSBit to LSBit (left to right)
	for(i=(2*n_bytes)-2;i>=0;i--)  {
		strcat(bin_rep,substring[i]);
	}

	printf("\n\nlong value %ld represented in binary = %s",value,bin_rep);

	//***************************************************************
	//  memory cleanup
	//***************************************************************
	if(nibble!=NULL)free(nibble);

	for(i=0;i<(2*n_bytes);i++)  {
		if(substring[i]!=NULL)free(substring[i]);
	}
	if(substring!=NULL)free(substring);
	if(buf!=NULL)free(buf);

	return(0);
}


*/