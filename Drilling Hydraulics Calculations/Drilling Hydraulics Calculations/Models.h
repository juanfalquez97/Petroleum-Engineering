#include <iostream>
#include <iomanip>
#include <limits.h>
#include <string>

using namespace std;

#ifndef _MODELS_H
#define _MODELS_H


class Models
{

public:

	//Class members that calculate values for Pressure Loss (Modified Power Law Model)
	void pipeflowcalcsPLM(double flowRateValue, double pipeID, double pipeLength, double mudDensity, double dR600, double dR300);
	void annularflowcalcsPLM(double flowRateValue, double wellAnnular, double annularLength, double mudDensity, double dR100, double dR3); // "wellAnnular": Equivalent Diameter; "annularLength": Length of the Annular Section

	// Class members that calculate values for Pressure Loss, Mean and Critical Velocities (Bingham Plastic Model)
	void pipeflowcalcsBPM(double fRateV, double pipeID, double pipeLength, double plasticViscosity, double yieldPoint, double mudDensity);
	void annularflowcalcsBPM(double fRateV, double wellAnnular, double annularLength, double annularArea, double plasticViscosity, double yieldPoint, double mudDensity); // "wellAnnular": Equivalent Diameter; "annularLength": Length of the Annular Section

	// Class members to calculate reological properties of the fluid thorugh Dial Readings
	double plasticViscosityCalc1(double dR600, double dR300);
	double yieldPointCalc1(double dR300, double plasticV);

	// Class memebers to calculate geometrical properties of the well and the bottomhole assembly
	double pipeLengthCalc1(double holeLength, double bhaAccessLength);
	double wellAnnularCalc1(double holeD, double pipeOD);
	double annularAreaCalc1(double holeD, double pipeOD);


	// Class Constructors and Destructors
	Models();
	~Models();
};

#endif