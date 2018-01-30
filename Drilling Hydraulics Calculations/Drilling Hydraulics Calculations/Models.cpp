#include "Models.h"

Models::Models()
{
	cout << "Drilling Hydraulics Calculations Algorithm" << endl;
	cout << endl;
}


Models::~Models()
{
}

// Pipe Length Calculations (Only used for calculating Drill Pipe Length)
double Models::pipeLengthCalc1(double holeLength, double bhaAccessLength)
{
	double lengthDP;

	lengthDP = (holeLength - bhaAccessLength);

	return lengthDP;
}

// Bingham Plastic Model for Pipe Flow Calculations
void Models::pipeflowcalcsBPM(double fRateV, double pipeID, double pipeLength, double plasticViscosity, double yieldPoint, double mudDensity)
{

	// Variables created to simplify expressions when calculating Critical and Mean Velocities
	double meanVelocity;
	double criticalVelocity;
	double cVNum;
	double cVDen;
	double cVsqrtValue;

	// Mean and Critical Velocity Variables with expressions
	meanVelocity = ((24.5)*(fRateV)) / (pow(pipeID, 2));
	
	cVsqrtValue = sqrt(((pow(plasticViscosity, 2)) + ((8.2)*(mudDensity)*(pow(pipeID, 2))*(yieldPoint))));

	cVNum = ((97)*(plasticViscosity)) + ((97)*(cVsqrtValue));
	
	cVDen = ((pipeID)*(mudDensity));

	criticalVelocity = ((cVNum) / (cVDen));

	// Logical variables to allow Laminar or Turbulent Flow calculations be selected and applied
	bool condLaminarFlow;
	bool condTurbFlow;

	condLaminarFlow = (meanVelocity < criticalVelocity);
	condTurbFlow = (meanVelocity > criticalVelocity);

	// Laminar Flow Variables
	double lamFlowPressLoss;
	double lamFPL1;
	double lamFPL2;

	// Turbulent Flow Variables
	double turbFlowPressLoss1; // Calculated Pressure Loss Depending on Mean Velocity
	double turbFPL1;
	double turbFPL2;

	double turbFlowPressLoss2; // Calculated Pressure Loss Depending on Flow Rate
	double turbFPLFR1;
	double turbFPLFR2;

	if (condLaminarFlow == true)
	{
		lamFPL1 = ((pipeID)*(plasticViscosity)*(meanVelocity)) / ((1000)*(pow(pipeID, 2)));
		lamFPL2 = ((pipeLength)*(yieldPoint)) / ((200)*(pipeID));

		lamFlowPressLoss = ((lamFPL1)+(lamFPL2)); // Laminar Flow Calculation

		// Mean and Critical Velocity Values displayed when Laminar Flow Calculations are done
		cout << "Mean Velocity is: " << meanVelocity << endl;
		cout << endl;
		cout << "Critical Velocity is: " << criticalVelocity << endl;

		cout << endl;
		cout << endl;

		cout << "Pressure loss through the calculated pipe section (Laminar Flow) is: " << flush;
		cout << lamFlowPressLoss << endl; // Laminar Flow Calculated Value Displayed
	}
	else if (condTurbFlow == true)
	{
		turbFPL1 = ((pow(mudDensity, 0.75))*(pow(meanVelocity, 1.75))*(pow(plasticViscosity, 0.25))*(pipeLength));
		turbFPL2 = ((1396)*(pow(pipeID, 1.25)));

		turbFlowPressLoss1 = ((turbFPL1) / (turbFPL2)); // Pressure Loss Calculated with Mean Velocity

		// Mean and Critical Velocity Values displayed when Turbulent Flow Calculations are done
		cout << "Mean Velocity is: " << meanVelocity << endl;
		cout << endl;
		cout << "Critical Velocity is: " << criticalVelocity << endl;

		cout << endl;
		cout << endl;

		turbFPLFR1 = ((pow(mudDensity, 0.75))*(pow(fRateV, 1.75))*(pow(plasticViscosity, 0.25))*(pipeLength));
		turbFPLFR2 = ((8624)*(pow(pipeID, 4.75)));

		turbFlowPressLoss2 = (turbFPLFR1 / turbFPLFR2); // Pressure Loss Calculated with Flow Rate


		// Prints the results of the calculated Pressure Losses (both, depending on Mean Velocity and Flow Rate, respectively)
		cout << "Pressure loss through the calculated pipe section (Turbulent Flow calculated with Mean Velocity Values) is: " << flush;
		cout << turbFlowPressLoss1 << endl; // Pressure Loss depending on Mean Velocity
		cout << endl;

		cout << "Pressure loss through the calculated pipe section (Turbulent Flow calculated with the Critical Velocity Values) is: " << flush;
		cout << turbFlowPressLoss2 << endl; // Pressure Loss depending on Flow Rate

		cout << endl;
	}
}

// Additional Calculations Performed on Annular Flow

double Models::wellAnnularCalc1(double holeD, double pipeOD)
{
	double wellAnnular;

	wellAnnular = ((holeD)-(pipeOD));

	return wellAnnular;
}

double Models::annularAreaCalc1(double holeD, double pipeOD)
{
	double annularArea;

	annularArea = ((pow(holeD, 2)) - (pow(pipeOD, 2)));

	return annularArea;
}

// Calculations Performed for Mean Velocity, Critical Velocity, Laminar Flow and Turbulent Flow Pressure losses
void Models::annularflowcalcsBPM(double fRateV, double wellAnnular, double annularLength, double annularArea, double plasticViscosity, double yieldPoint, double mudDensity)
{
	// Variables created to simplify expressions when calculating Critical and Mean Velocities
	double meanVelocity;
	double criticalVelocity;
	double cVNum;
	double cVDen;
	double cVsqrtValue;

	// Mean and Critical Velocity Variables with expressions
	meanVelocity = ((24.5)*(fRateV)) / (annularArea);

	cVsqrtValue = sqrt(((pow(plasticViscosity, 2)) + ((6.2)*(mudDensity)*(pow(wellAnnular, 2))*(yieldPoint))));

	cVNum = ((97)*(plasticViscosity)) + ((97)*(cVsqrtValue));

	cVDen = ((wellAnnular)*(mudDensity));

	criticalVelocity = ((cVNum) / (cVDen));

	// Logical variables to allow Laminar or Turbulent Flow calculations be selected and applied
	bool condAnnLaminarFlow;
	bool condAnnTurbFlow;

	condAnnLaminarFlow = (meanVelocity < criticalVelocity);
	condAnnTurbFlow = (meanVelocity > criticalVelocity);

	// Laminar Flow Variables
	double lamFlowPressLoss;
	double lamFPL1;
	double lamFPL2;

	// Turbulent Flow Variables
	double turbFlowPressLoss1; // Calculated Pressure Loss Depending on Mean Velocity
	double turbFPL1;
	double turbFPL2;

	double turbFlowPressLoss2; // Calculated Pressure Loss Depending on Flow Rate
	double turbFPLFR1;
	double turbFPLFR2;

	if (condAnnLaminarFlow == true)
	{
		lamFPL1 = ((annularLength)*(plasticViscosity)*(meanVelocity)) / ((1000)*(pow(wellAnnular, 2)));
		lamFPL2 = ((annularLength)*(yieldPoint)) / ((200)*(wellAnnular));

		lamFlowPressLoss = ((lamFPL1)+(lamFPL2)); // Laminar Flow Calculation

		// Mean and Critical Velocity Values displayed when Laminar Flow Calculations are done
		cout << "Mean Velocity is: " << meanVelocity << endl;
		cout << endl;
		cout << "Critical Velocity is: " << criticalVelocity << endl;

		cout << endl;
		cout << endl;

		cout << "Pressure loss through the calculated pipe section (Laminar Flow) is: " << flush;
		cout << lamFlowPressLoss << endl; // Laminar Flow Calculated Value Displayed
	}
	else if (condAnnTurbFlow == true)
	{
		turbFPL1 = ((pow(mudDensity, 0.75))*(pow(meanVelocity, 1.75))*(pow(plasticViscosity, 0.25))*(annularLength));
		turbFPL2 = ((1396)*(pow(wellAnnular, 1.25)));

		turbFlowPressLoss1 = ((turbFPL1) / (turbFPL2)); // Pressure Loss Calculated with Mean Velocity

		// Mean and Critical Velocity Values displayed when Turbulent Flow Calculations are done
		cout << "Mean Velocity is: " << meanVelocity << endl;
		cout << endl;
		cout << "Critical Velocity is: " << criticalVelocity << endl;

		cout << endl;
		cout << endl;

		turbFPLFR1 = ((pow(mudDensity, 0.75))*(pow(fRateV, 1.75))*(pow(plasticViscosity, 0.25))*(annularLength));
		turbFPLFR2 = ((8624)*(pow(wellAnnular, 4.75)));

		turbFlowPressLoss2 = (turbFPLFR1 / turbFPLFR2); // Pressure Loss Calculated with Flow Rate


		// Prints the results of the calculated Pressure Losses (both, depending on Mean Velocity and Flow Rate, respectively)
		cout << "Pressure loss through the calculated pipe section (Turbulent Flow calculated with Mean Velocity Values) is: " << flush;
		cout << turbFlowPressLoss1 << endl; // Pressure Loss depending on Mean Velocity
		cout << endl;

		cout << "Pressure loss through the calculated pipe section (Turbulent Flow calculated with the Critical Velocity Values) is: " << flush;
		cout << turbFlowPressLoss2 << endl; // Pressure Loss depending on Flow Rate

		cout << endl;
	}
}


// Plastic viscosity calculated through dial readings
double Models::plasticViscosityCalc1(double dR600, double dR300)
{
	double plasticV;

	plasticV = ((dR600)-(dR300));

	return plasticV;
}

// Yield Point calculated through dial readings and Plastic Viscosity
double Models::yieldPointCalc1(double dR300, double plasticV)
{
	double yieldP;

	yieldP = ((dR300)-(plasticV));

	return yieldP;
}

// Modified Power Law Model for Pipe Flow Calculations
void Models::pipeflowcalcsPLM(double flowRateValue, double pipeID, double pipeLength, double mudDensity, double dR600, double dR300)
{
	// Variables created to simplify expressions when calculating Critical Velocities, Mean Velocities and Reynolds Numbers
	double meanVelocity;

	double reynoldsNumber;
	double rNNum;
	double rNDen;

	double equivViscosity;
	double eVisc1;
	double eVisc2;
	double eVisc3;
	double eVisc4;
	double eVisc5;

	// Calculations for "n" value
	double nValue;

	nValue = ((3.32)*(log10((dR600) / (dR300))));

	// Calculations for "k" value
	double kValue;

	kValue = (((5.11)*(dR300)) / ((pow(511, nValue))));

	// Mean Velocity Variables with expressions
	meanVelocity = ((24.5)*(flowRateValue)) / (pow(pipeID, 2));

	// Equivalent Viscosity Variables with expressions. "**" Expressions used in the final expression for Equivalent Viscosity Calculations
	eVisc1 = ((100)*(kValue));// **
	eVisc2 = (((1.6)*(meanVelocity)) / (pipeID));
	eVisc3 = (pow(eVisc2, (nValue - 1)));// **
	eVisc4 = ((((3)*(nValue)) + 1) / ((4)*(nValue)));
	eVisc5 = (pow(eVisc4, nValue));// **

	equivViscosity = ((eVisc1)*(eVisc3)*(eVisc5));
 
	// Reynolds number Calculation
	rNNum = ((15.467)*(meanVelocity)*(pipeID)*(mudDensity));
	rNDen = ((equivViscosity));

	reynoldsNumber = ((rNNum) / (rNDen));

	// Reynolds number conditions
	bool condNumbReynolds1;
	bool condNumbReynolds2;

	condNumbReynolds1 = (reynoldsNumber < 2100); // Laminar Flow
	condNumbReynolds2 = (reynoldsNumber > 2100); // Turbulent Flow

	// Variables for Fanning Factor and Pressure Loss
	double fanningLaminar;
	double fanningTurbulent;
	double pipeFlowPressLoss;

	if (condNumbReynolds1 == true)
	{
		cout << "Mean Velocity is: " << meanVelocity << endl;
		cout << "n Value is: " << nValue << endl;
		cout << endl;
		cout << "k Value is: " << kValue << endl;
		cout << endl;
		cout << "Equivalent Viscosity is: " << equivViscosity << endl;
		cout << endl;
		cout << "Reynolds Number is (Laminar Flow): " << reynoldsNumber << endl;
		cout << endl;

		fanningLaminar = ((16) / (reynoldsNumber));

		pipeFlowPressLoss = ((fanningLaminar)*(pow(meanVelocity, 2))*(mudDensity)*(pipeLength)) / ((92916)*(pipeID));

		cout << "Fanning Factor is: " << fanningLaminar << endl;
		cout << endl;
		cout << "Pipe Flow Pressure Loss (Laminar Flow) is: " << pipeFlowPressLoss << endl;
	}
	else if (condNumbReynolds1 == true)
	{
		// Variables for Turbulent Flow Fanning Factor calculations
		double ffExp1;
		double ffExp2;
		double ffExp3;

		// Expressions for variables declared to calculate Turbulent Flow Fanning Factor
		ffExp1 = ((log10(nValue) + (3.93)) / (50));
		ffExp2 = (((1.75) - (log10(nValue))) / (7));
		ffExp3 = (pow(reynoldsNumber, ffExp2));

		cout << "Mean Velocity is: " << meanVelocity << endl;
		cout << "n Value is: " << nValue << endl;
		cout << endl;
		cout << "k Value is: " << kValue << endl;
		cout << endl;
		cout << "Equivalent Viscosity is: " << equivViscosity << endl;
		cout << endl;
		cout << "Reynolds Number is (Laminar Flow): " << reynoldsNumber << endl;
		cout << endl;

		fanningTurbulent = ((ffExp1) / (ffExp3));

		pipeFlowPressLoss = ((fanningTurbulent)*(pow(meanVelocity, 2))*(mudDensity)*(pipeLength)) / ((92916)*(pipeID));

		cout << "Fanning Factor is: " << fanningTurbulent << endl;
		cout << endl;
		cout << "Pipe Flow Pressure Loss (Turbulent Flow) is: " << pipeFlowPressLoss << endl;

	}
}

// Modified Power Law Model for Annular Flow Calculations
void Models::annularflowcalcsPLM(double flowRateValue, double pipeID, double pipeLength, double mudDensity, double dR100, double dR3)
{

}