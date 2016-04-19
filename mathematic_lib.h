/** \file
 *@file mathematic_lib.h
 *@author Zdenek Kamensky
 *@date 15 Apr 2016
 *@brief Hlavickovy soubor matematicke knihovny s prototypy vsech funkci
 *
 */ 


#ifndef MATH_H //podminky prekladu
#define MATH_H


/**
 * @brief add_f Funkce pro soucet dvou cisel
 * @param a Prvni cislo
 * @param b Druhe cislo
 * @return Vraci soucet techto cisel
 */
double add_f(double a, double b);


/**
 * @brief sub_f Funkce pro rozdil dvou cisel
 * @param a Prvni cislo
 * @param b Druhe cislo
 * @return Vraci rozdil techto cisel (b odecte od a)
 */
double sub_f(double a, double b);


/**
 * @brief mul_f Funkce pro nasobeni dvou cisel
 * @param a Prvni cislo
 * @param b Druhe cislo
 * @return Vraci soucin techto cisel
 */
double mul_f(double a, double b);


/**
 * @brief div_f Funkce pro deleni prvniho cisla druhym
 * @param a Prvni cislo
 * @param b Druhe cislo
 * @return Vraci podil techto cisel
 */
double div_f(double a, double b);


/**
 * @brief fact_f Funkce pro vypocet faktorialu zadaneho cisla
 * @param a Zadane cislo
 * @return Vraci faktorial
 */
double fact_f(double a);


/**
 * @brief pow_f Funkce pro vypocet n-te mocniny zadaneho cisla
 * @param a Mocnene cislo
 * @param n Exponent
 * @return Vraci n-tou mocninu cisla a
 */
double pow_f(double a, int n);


/**
 * @brief sqrt_f Funkce pro druhou odmocninu daneho cisla (Heronuv vzorec)
 * @param a Cislo ktere je odmocneno
 * @return Vraci odmocninu daneho cisla
 */
double sqrt_f(double a);


#endif // MATH_H
