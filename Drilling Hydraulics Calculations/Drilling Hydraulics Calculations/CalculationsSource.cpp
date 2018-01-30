#include <iostream>
#include <iomanip>
#include <limits.h>
#include <string>
#include "Models.h"
#define _USE_MATH_DEFINES
using namespace std;



int main()
{

	// Geometrical Properties
	double pipeLength;
	double annularArea;
	double wellAnnular;

	// Reological Properties
	double plasticVisc;
	double yieldP;

	// Method Call
	Models calculate;

	wellAnnular = calculate.wellAnnularCalc1(12.25, 8);
	annularArea = calculate.annularAreaCalc1(12.25, 8);
	pipeLength = calculate.pipeLengthCalc1(9000, 350);


	calculate.pipeflowcalcsBPM(500, 4.276, pipeLength, 40, 30, 17.5);

	cout << endl;

	calculate.annularflowcalcsBPM(500, wellAnnular, 350, annularArea, 40, 30, 17.5);

	return 0;
}
