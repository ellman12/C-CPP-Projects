
/////////////////////////////////////////////////////////////////////
//  File:
/////////////////////////////////////////////////////////////////////
//
//  Purpose:  
//
//  Programmer:  Larry Basegio
//               Mentor:  Caledonia Robotic Warriors team #5914
//
//  Compiler Environment:  This was developed on Microsoft Enterprise
//  C/C++ but should be completely portable to other C++ compilers.
//
//  Revisions:  Original Development 04/21/2018
//
//
//  Remarks:
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#include <stdio.h>   //  routine C library input/output
#include <stdlib.h>  
#include <string.h>  

class NumericRep  {

private:
	int n_bytes;   //  important parameter used throughout the class

public:
	NumericRep(void);  //  constructor

	NumericRep(int bytes);  //  overloaded constructor for illustration.

	~NumericRep(void);

	//  Converts type to hexidecimal representation.  Also
	//  displays little endian memory storage in both
	//  hexidecimal and unicode.
	//int NumericRep::RepHexidecimal(long value);
	int RepHexidecimal(long value);
	int RepHexidecimal(float value);
	int RepHexidecimal(double value);


	//  Converts type to binary representation.  Also
	//  displays little endian memory storage in both
	//  hexidecimal and unicode.
	int RepBinary(long value);
	int RepBinary(float value);
	int RepBinary(double value);

	//  Utility used in the three binary conversion functions
	int Convert2Binary(unsigned char *buf);
};