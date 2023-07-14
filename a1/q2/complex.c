#include "complex.h"
#include <stdlib.h>
#include <assert.h>
#include <math.h>

Complex INIT(int n)
{
        Complex c = (Complex)malloc(sizeof(struct complex));
        assert(c != NULL);
        c->terms = (Element *)malloc(sizeof(Element) * n);
        c->num = n;
        return c;
}

Complex ADD(const Complex c1, const Complex c2)
{
        Complex c = (Complex)malloc(sizeof(struct complex));
        assert(c != NULL);
        c->terms = (Element *)malloc(sizeof(Element) * c1->num);
        c->num = c1->num;
        for (int i = 0; i < c->num; i++)
                c->terms[i] = c1->terms[i] + c2->terms[i];
        return c;
}

Complex SUB(const Complex c1, const Complex c2)
{
        Complex c = (Complex)malloc(sizeof(struct complex));
        assert(c != NULL);
        c->terms = (Element *)malloc(sizeof(Element) * c1->num);
        c->num = c1->num;
        for (int i = 0; i < c->num; i++)
                c->terms[i] = c1->terms[i] - c2->terms[i];
        return c;
}

float MOD(const Complex c)
{
        float sum = 0;
        for (int i = 0; i < c->num; i++)
                sum += (c->terms[i] * c->terms[i]);
        return sqrt(sum);
}

float DOT(const Complex c1, const Complex c2)
{
        float sum = 0;
        for (int i = 0; i < c1->num; i++)
                sum += (c1->terms[i] * c2->terms[i]);
        return sum;
}

float COS(const Complex c1, const Complex c2)
{
        float ans = 0, x = 0;
        x = (MOD(c1) * MOD(c2));
        ans = (float)(DOT(c1, c2) / x);
        return ans;
}