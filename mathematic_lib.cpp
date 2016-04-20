/** \file
 * @file mathematic_lib.cpp
 * @author Zdenek Kamensky
 * @date 16 April 2016
 * @brief Implementace funkci matematicke knihovny
 */ 


#include "mathematic_lib.h"


/*SOUCET*/
double add_f(double a, double b)
{
    return (a + b);
}

/*ROZDIL*/
double sub_f(double a, double b)
{
    return (a - b);
}

/*SOUCIN*/
double mul_f(double a, double b)
{
    return (a * b);
}

/*PODIL*/
double div_f(double a, double b)
{
    return (a / b);
}

/*FAKTORIAL*/
double fact_f(double a)
{
    if((a - int(a)) == 0)
    {
        if(a == 0)
        {
            return 1;
        }
        if(a < 0)
        {
            return -2;//ERROR -2
        }
        else
        {
            double result = 1;
            while(a > 0)
            {
                result *= a;
                a--;
            }
            return result;
        }
    }
    else
    {
        return -1;//ERROR -1
    }
}

/*MOCNINA*/
double pow_f(double a, int n)
{
    if(n < 0)
    {
        double result = a;
        for(int i = 0; i > (n + 1); i--)
        {
            result *= a;
        }
        return (1/result);
    }
    else if(n == 0)
    {
        return 1;
    }
    else
    {
        double result = a;
        for(int i = 0; i < (n - 1); i++)
        {
            result *= a;
        }
        return result;
    }
}

/*ODMOCNINA*/
double sqrt_f(double a)
{
    if(a == 0)
    {
        return 0;
    }
    else if(a > 0)
    {
   	/*Implementace Heronova vzorce*/
        int x_1 = ((int)a + ((int)a / (int)a)) / 2;
        int x_2 = 0;

        while(x_2 != x_1) 
        {
            x_2 = (x_1 + ((int)a / x_1)) / 2;
            x_1 = (x_2 + ((int)a / x_2)) / 2;
        }	
	return x_1;
    }
    else
    {
        return -3;//ERROR -3
    }
}
