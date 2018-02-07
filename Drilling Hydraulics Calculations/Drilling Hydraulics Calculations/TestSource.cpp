#include <iostream>
#include <iomanip>
#include <limits.h>
#include <string>
#include "Models.h"
#define _USE_MATH_DEFINES
using namespace std;

int main()
{

	double a;
	double b;
	double c;

	Models calculate;

	a = calculate.annularAreaCalc1(12.25, 8);

	b = calculate.wellAnnularCalc1(12.25, 8);

	
	calculate.annularflowcalcsBPM(500, b, 350, a, 40, 30, 17.5);



	return 0;
}