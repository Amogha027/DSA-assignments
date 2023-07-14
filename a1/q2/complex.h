#ifndef __COMPLEX_H_
#define __COMPLEX_H_

typedef float Element;
typedef struct complex *Complex;

struct complex
{
	int num; // number of terms in the complex number
	Element *terms; // array containing the terms of complex number
};

Complex INIT(int n);
Complex ADD(const Complex c1, const Complex c2);
Complex SUB(const Complex c1, const Complex c2);
float MOD(const Complex c);
float DOT(const Complex c1, const Complex c2);
float COS(const Complex c1, const Complex c2);

#endif