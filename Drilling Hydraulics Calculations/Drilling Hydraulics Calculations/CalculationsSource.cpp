#include <iostream>
#include <iomanip>
#include <limits.h>
#include <string>
#include "Models.h"
#define _USE_MATH_DEFINES
using namespace std;



int main()
{

	// Available Data to Input for Calculations
	double flowRate;
	double mudDensity;
	double dCLength;
	double wellDepth;
	double pipeID;
	double pipeOD;
	double wellDiameter;

	// Data Available if Yield Point and Plastic Viscosity are not Available
	double dR600;
	double dR300;
	double dR100;
	double dR3;

	// Geometrical Properties
	double pipeLength;
	double annularArea;
	double wellAnnular;
	double annularLength;
	double stDepth;
	double bottomDepth;
	double prevSectionBottomDepth;

	// Reological Properties
	double plasticVisc;
	double yieldP;

	// Method Call
	Models calculate;

	// Command Selection Variables
	string flowSelection;
	string modelSelection;
	string pipeSelection;
	string dPSectionSelection;
	string yesnoSelection;
	string closeDHC;

	cout << "---------------------------------------------------------------------------------------" << endl;
	cout << endl;

	// Instructions to choose flow type or abort the algorithm
	cout << "For Pipe Flow, type: pipe" << endl;
	cout << endl;
	cout << "For Annular Flow, type: annular" << endl;
	cout << endl;
	cout << "To abort the execution, type: cancel" << endl;
	cout << endl;

	cout << "Select the flow type to be calculated: " << flush;
	cin >> flowSelection;
	cout << endl;

	cout << "---------------------------------------------------------------------------------------" << endl;
	cout << endl;

	if (flowSelection == "pipe") // Pipe Flow Calculations Selection
	{
		cout << "Pipe Flow Calculations Selected." << endl;
		cout << endl;
		cout << endl;

		cout << "For Bingham Plastic Model type: BPM. " << endl;
		cout << endl;

		cout << "For Modified Power Law Model type: MPLM." << endl;
		cout << endl;
		cout << endl;

		cout << "Select Model to Perform Drilling Hydraulics Calculations: " << flush;
		cin >> modelSelection;
		cout << endl;
		cout << endl;

		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << endl;

		if (modelSelection == "BPM") // Bingham Plastic Model Selection
		{
			cout << "BPM Selected." << endl;
			cout << endl;
			cout << endl;

			cout << "Type in the data provided by the problem." << endl;
			cout << endl;

			// Flow Rate Value Input
			cout << "Flow Rate: " << flush;
			cin >> flowRate;

			// Mud Density Value Input
			cout << "Mud Density: " << flush;
			cin >> mudDensity;

			// Drill Collars Length Value Input
			cout << "Drill Collars Length: " << flush;
			cin >> dCLength;


			// Well Depth Value Input
			cout << "Well Depth: " << flush;
			cin >> wellDepth;
			cout << endl;

			cout << "If PV and YP values are not available, type 0 to input Dial Readings Values to calculate PV and YP" << endl;
			cout << endl;

			// Plastic Viscosity Value Input
			cout << "Plastic Viscosity: " << flush;
			cin >> plasticVisc;

			// Yield Point Value Input
			cout << "Yield Point: " << flush;
			cin >> yieldP;
			cout << endl;

			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << endl;

			if ((plasticVisc == 0) && (yieldP == 0)) // Conditioning for PV and YP calculations with Dial Readings
			{
				// Dial Reading at 600 RPM Value Input
				cout << "Dial Reading at 600 RPM: " << flush;
				cin >> dR600;

				// Dial Reading at 300 RPM Value Input
				cout << "Dial Reading at 300 RPM: " << flush;
				cin >> dR300;

				plasticVisc = calculate.plasticViscosityCalc1(dR600, dR300);

				cout << endl;
				cout << "Plastic Viscosity from Dial Readings: " << flush;
				cout << plasticVisc << endl;


				yieldP = calculate.yieldPointCalc1(dR300, plasticVisc);
				cout << endl;
				cout << "Yield Point from Dial Readings is: " << flush;
				cout << yieldP << endl;

				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << endl;
			}

			// Pipe Selection
			cout << "Type in the pipe section to be used for calculations (DP for Drill Pipes, DC for Drill Collars): " << flush;
			cin >> pipeSelection;
			cout << endl;
			cout << endl;

			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << endl;

			if (pipeSelection == "DP") // Drill Pipe Selection
			{
				// Drill Pipe ID Input
				cout << "Pipe ID (Drill Pipe): " << flush;
				cin >> pipeID;
				cout << endl;

				// Call method to calculate Drill Pipe Length
				pipeLength = calculate.pipeLengthCalc1(wellDepth, dCLength);

				// Drill Pipe Length Value Output
				cout << "Drill Pipe Length: " << flush;
				cout << pipeLength;
				cout << endl;

				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << endl;

				// Call method to calculate Mean Velocity, Critical Velocity and Pressure Losses for pipe flow
				calculate.pipeflowcalcsBPM(flowRate, pipeID, pipeLength, plasticVisc, yieldP, mudDensity);
				cout << endl;

				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << endl;

				calculate.~Models();
				cout << endl;

				cout << "Type continue to Exit Algorithm..." << flush;
				cin >> closeDHC;
				cout << endl;

			}
			else if (pipeSelection == "DC") // Drill Collars Selection
			{
				// Drill Collars Pipe ID Input
				cout << "Pipe ID (Drill Collars): " << flush;
				cin >> pipeID;

				// Drill Collars Length Value Output
				pipeLength = dCLength;
				cout << "Drill Collars Length: " << flush;
				cout << pipeLength;
				cout << endl;

				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << endl;

				// Call method to calculate Mean Velocity, Critical Velocity and Pressure Losses for pipe flow
				calculate.pipeflowcalcsBPM(flowRate, pipeID, pipeLength, plasticVisc, yieldP, mudDensity);
				cout << endl;

				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << endl;

				calculate.~Models();
				cout << endl;

				cout << "Type continue to Exit Algorithm..." << flush;
				cin >> closeDHC;
				cout << endl;

			}


		}
		else if (modelSelection == "MPLM") // Modified Power Law Model Selection
		{
			cout << "MPLM Selected" << endl;
			cout << endl;
			cout << endl;

			cout << "Type in the data provided by the problem." << endl;
			cout << endl;

			// Flow Rate Value Input
			cout << "Flow Rate: " << flush;
			cin >> flowRate;

			// Mud Density Value Input
			cout << "Mud Density: " << flush;
			cin >> mudDensity;

			// Drill Collars Length Value Input
			cout << "Drill Collars Length: " << flush;
			cin >> dCLength;

			// Well Depth Value Input
			cout << "Well Depth: " << flush;
			cin >> wellDepth;

			// Dial Reading at 600 RPM Value Input
			cout << "Dial Reading at 600 RPM: " << flush;
			cin >> dR600;

			// Dial Reading at 300 RPM Value Input
			cout << "Dial Reading at 300 RPM: " << flush;
			cin >> dR300;

			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << endl;

			// Pipe Selection
			cout << "Type in the pipe section to be used for calculations (DP for Drill Pipes, DC for Drill Collars): " << flush;
			cin >> pipeSelection;
			cout << endl;

			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << endl;

			if (pipeSelection == "DP") // Drill Pipe Selection
			{
				// Drill Pipe ID Input
				cout << "Pipe ID (Drill Pipe): " << flush;
				cin >> pipeID;

				// Call method to calculate Drill Pipe Length
				pipeLength = calculate.pipeLengthCalc1(wellDepth, dCLength);

				// Drill Pipe Length Value Output
				cout << "Drill Pipe Length: " << flush;
				cout << pipeLength;
				cout << endl;

				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << endl;

				// Call method to calculate Mean Velocity, Critical Velocity and Pressure Losses for pipe flow
				calculate.pipeflowcalcsPLM(flowRate, pipeID, pipeLength, mudDensity, dR600, dR300);
				cout << endl;

				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << endl;

				calculate.~Models();
				cout << endl;

				cout << "Type continue to Exit Algorithm..." << flush;
				cin >> closeDHC;
				cout << endl;

			}
			else if (pipeSelection == "DC") // Drill Collars Selection
			{
				// Drill Collars Pipe ID Input
				cout << "Pipe ID (Drill Collars): " << flush;
				cin >> pipeID;

				// Drill Collars Length Value Output
				pipeLength = dCLength;
				cout << "Drill Collars Length: " << flush;
				cout << pipeLength;
				cout << endl;

				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << endl;

				// Call method to calculate Mean Velocity, Critical Velocity and Pressure Losses through pipe flow
				calculate.pipeflowcalcsPLM(flowRate, pipeID, pipeLength, mudDensity, dR600, dR300);
				cout << endl;

				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << endl;

				calculate.~Models();
				cout << endl;

				cout << "Type continue to Exit Algorithm..." << flush;
				cin >> closeDHC;
				cout << endl;

			}

		}
	}
	else if (flowSelection == "annular") // Annular Flow Calculations Selection
	{
		cout << "Annular Flow Calculations Selected" << endl;
		cout << endl;
		cout << endl;

		cout << "For Bingham Plastic Model type: BPM." << endl;
		cout << endl;
		cout << "For Modified Power Law Model type: MPLM." << endl;
		cout << endl;

		cout << "Select Model to Perform Drilling Hydraulics Calculations: " << flush;
		cin >> modelSelection;
		cout << endl;
		cout << endl;

		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << endl;

		if (modelSelection == "BPM") // Bingham Plastic Model Selection
		{
			cout << "BPM Selected" << endl;
			cout << endl;
			cout << endl;

			cout << "Type in the data provided by the problem." << endl;
			cout << endl;

			// Flow Rate Value Input
			cout << "Flow Rate: " << flush;
			cin >> flowRate;

			// Mud Density Value Input
			cout << "Mud Density: " << flush;
			cin >> mudDensity;

			// Drill Collars Length Value Input
			cout << "Drill Collars Length: " << flush;
			cin >> dCLength;

			// Well Depth Value Input
			cout << "Well Depth: " << flush;
			cin >> wellDepth;


			cout << "If PV and YP values are not available, type 0 to input Dial Readings Values to calculate PV and YP" << endl;
			cout << endl;

			// Plastic Viscosity Value Input
			cout << "Plastic Viscosity: " << flush;
			cin >> plasticVisc;

			// Yield Point Value Input
			cout << "Yield Point: " << flush;
			cin >> yieldP;

			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << endl;

			if ((plasticVisc == 0) && (yieldP == 0)) // Conditioning for PV and YP calculations with Dial Readings
			{

				// Dial Reading at 600 RPM Value Input
				cout << "Dial Reading at 600 RPM: " << flush;
				cin >> dR600;

				// Dial Reading at 300 RPM Value Input
				cout << "Dial Reading at 300 RPM: " << flush;
				cin >> dR300;

				plasticVisc = calculate.plasticViscosityCalc1(dR600, dR300);

				cout << endl;
				cout << "Plastic Viscosity from Dial Readings: " << endl;
				cout << plasticVisc << endl;


				yieldP = calculate.yieldPointCalc1(dR300, plasticVisc);
				cout << endl;
				cout << "Yield Point from Dial Readings is: " << flush;
				cout << yieldP << endl;

				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << endl;
			}


			// Pipe Selection
			cout << "Type in the pipe section to be used for calculations (DP for Drill Pipes, DC for Drill Collars): " << flush;
			cin >> pipeSelection;
			cout << endl;
			cout << endl;

			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << endl;

			if (pipeSelection == "DP") // Drill Pipes Selection
			{

				// Drill Pipe Outer Diameter Value Input
				cout << "Drill Pipe OD: " << flush;
				cin >> pipeOD;
				cout << endl;

				// Drill Pipe Section Selection
				cout << "Does the Drill Pipe Length covers a small section of the Drill Collars Section?" << endl;
				cout << "Type yes or no (type the words in lowercase): " << flush;
				cin >> yesnoSelection;
				cout << endl;

				if (yesnoSelection == "yes") // Drill Pipe in Drill Collars' Section Selection
				{
					// Well Borehole Diameter for the Drilled Section Value Input
					cout << "Drilled Section Diameter (Borehole): " << flush;
					cin >> wellDiameter;
					cout << endl;

					cout << "Drilled Section Starting Depth (Previous Section Bottom Depth): " << flush;
					cin >> prevSectionBottomDepth;
					cout << endl;

					wellAnnular = calculate.wellAnnularCalc1(wellDiameter, pipeOD);

					annularArea = calculate.annularAreaCalc1(wellDiameter, pipeOD);

					pipeLength = calculate.pipeLengthCalc1(wellDepth, dCLength);

					annularLength = calculate.pipeSectionLength(wellDepth, dCLength, prevSectionBottomDepth);

					cout << "---------------------------------------------------------------------------------------" << endl;
					cout << endl;

					// 
					calculate.annularflowcalcsBPM(flowRate, wellAnnular, annularLength, annularArea, plasticVisc, yieldP, mudDensity);
					cout << endl;

					cout << "---------------------------------------------------------------------------------------" << endl;
					cout << endl;

					calculate.~Models();
					cout << endl;

					cout << "Type continue to Exit Algorithm..." << flush;
					cin >> closeDHC;
					cout << endl;


				}
				else if (yesnoSelection == "no") // Drill Pipe in isolated Section Selection
				{
					// Drilled Section Diameter Value Input
					cout << "Drilled Section Diameter (Borehole): " << endl;
					cin >> wellDiameter;

					// Drilled Section Starting Depth
					cout << "Starting Depth: " << endl;
					cin >> stDepth;

					// Drilled Section Bottom Depth
					cout << "Bottom Depth: " << endl;
					cin >> bottomDepth;
					cout << endl;

					annularLength = calculate.pipeSectionLength1(stDepth, bottomDepth);

					wellAnnular = calculate.wellAnnularCalc1(wellDiameter, pipeOD);

					annularArea = calculate.annularAreaCalc1(wellDiameter, pipeOD);

					cout << "---------------------------------------------------------------------------------------" << endl;
					cout << endl;

					//
					calculate.annularflowcalcsBPM(flowRate, wellAnnular, annularLength, annularArea, plasticVisc, yieldP, mudDensity);
					cout << endl;

					cout << "---------------------------------------------------------------------------------------" << endl;
					cout << endl;

					calculate.~Models();
					cout << endl;

					cout << "Type continue to Exit Algorithm..." << flush;
					cin >> closeDHC;
					cout << endl;

				}


			}
			else if (pipeSelection == "DC") // Drill Collars Selection
			{
				// Drill Collars Pipe OD Input
				cout << "Pipe OD (Drill Collars): " << flush;
				cin >> pipeOD;

				// Drill Collars Length Value Input
				pipeLength = dCLength;
				cout << "Drill Collars Length: " << flush;
				cout << pipeLength;

				// Well Diameter Value Input
				cout << "Well Diameter for the Scoped Section: " << flush;
				cin >> wellDiameter;
				cout << endl;

				// Method Call to calculate Well Annular and the Annular Area
				wellAnnular = calculate.wellAnnularCalc1(wellDiameter, pipeOD);
				annularArea = calculate.annularAreaCalc1(wellDiameter, pipeOD);

				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << endl;

				// Call method to calculate Mean Velocity, Critical Velocity and Pressure Losses Through Annular flow
				calculate.annularflowcalcsBPM(flowRate, wellAnnular, pipeLength, annularArea, plasticVisc, yieldP, mudDensity);
				cout << endl;

				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << endl;

				calculate.~Models();
				cout << endl;

				cout << "Type continue to Exit Algorithm...: " << flush;
				cin >> closeDHC;
				cout << endl;

			}

		}
		else if (modelSelection == "MPLM") // Modified Power Law Model Selection
		{
			cout << "MPLM Selected" << endl;
			cout << endl;
			cout << endl;

			cout << "Type in the data provided by the problem." << endl;
			cout << endl;

			// Flow Rate Value Input
			cout << "Flow Rate: " << flush;
			cin >> flowRate;

			// Mud Density Value Input
			cout << "Mud Density: " << flush;
			cin >> mudDensity;

			// Drill Collars Length Value Input
			cout << "Drill Collars Length: " << flush;
			cin >> dCLength;

			// Well Depth Value Input
			cout << "Well Depth: " << flush;
			cin >> wellDepth;

			// Dial Reading at 600 RPM Value Input
			cout << "Dial Reading at 100 RPM: " << flush;
			cin >> dR100;

			// Dial Reading at 300 RPM Value Input
			cout << "Dial Reading at 3 RPM: " << flush;
			cin >> dR3;
			cout << endl;

			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << endl;

			// Pipe Selection
			cout << "Type in the pipe section to be used for calculations (DP for Drill Pipes, DC for Drill Collars): " << flush;
			cin >> pipeSelection;
			cout << endl;

			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << endl;

			if (pipeSelection == "DP") // Drill Pipe Selection
			{
				// Drill Pipe OD Value Input
				cout << "Pipe OD (Drill Pipe): " << flush;
				cin >> pipeOD;
				cout << endl;

				// Drill Pipe Section Selection (used when Drill Pipes partially take a small section of the last drilled section of the well)
				cout << "Does the Drill Pipe Length covers a small section of the Drill Collars Section?" << endl;
				cout << "Type yes or no (type the words in lowercase): " << flush;
				cin >> yesnoSelection;
				cout << endl;

				if (yesnoSelection == "yes") // Drill pipe in Drill Collars' section selection
				{

					// Well Diameter Value Input
					cout << "Well Diameter of the Scoped Section (Borehole): " << flush;
					cin >> wellDiameter;

					// Drilled Section Starting Depth or Previous Section Bottom Depth Value Input
					cout << "Drilled Section Starting Depth (Previous Section Bottom Depth): " << flush;
					cin >> prevSectionBottomDepth;
					cout << endl;

					pipeLength = calculate.pipeLengthCalc1(wellDepth, dCLength);

					annularLength = calculate.pipeSectionLength(wellDepth, dCLength, prevSectionBottomDepth);

					wellAnnular = calculate.wellAnnularCalc1(wellDiameter, pipeOD);

					annularArea = calculate.annularAreaCalc1(wellDiameter, pipeOD);

					cout << "---------------------------------------------------------------------------------------" << endl;
					cout << endl;

					// Call method to calculate Mean Velocity, Critical Velocity and Pressure Losses for Annular flow
					calculate.annularflowcalcsPLM(flowRate, wellAnnular, annularLength, annularArea, mudDensity, dR100, dR3);
					cout << endl;

					cout << "---------------------------------------------------------------------------------------" << endl;
					cout << endl;

					calculate.~Models();
					cout << endl;

					cout << "Type continue to Exit Algorithm..." << flush;
					cin >> closeDHC;
					cout << endl;

				}
				else if (yesnoSelection == "no") // Drill Pipe in isolated section Selection
				{

					// Well Diameter Value Input
					cout << "Well Diameter of the Scoped Section (Borehole): " << flush;
					cin >> wellDiameter;

					// Starting Depth Value Input
					cout << "Starting Depth of the Scoped Section: " << flush;
					cin >> stDepth;

					// Bottom Depth Value Input
					cout << "Bottom Depth of the Scoped Section: " << flush;
					cin >> bottomDepth;
					cout << endl;

					annularLength = calculate.pipeSectionLength1(stDepth, bottomDepth);

					wellAnnular = calculate.wellAnnularCalc1(wellDiameter, pipeOD);

					annularArea = calculate.annularAreaCalc1(wellDiameter, pipeOD);

					cout << "---------------------------------------------------------------------------------------" << endl;
					cout << endl;

					// Call method to calculate Mean Velocity, Critical Velocity and Pressure Losses for pipe flow
					calculate.annularflowcalcsPLM(flowRate, wellAnnular, annularLength, annularArea, mudDensity, dR100, dR3);
					cout << endl;

					cout << "---------------------------------------------------------------------------------------" << endl;
					cout << endl;

					calculate.~Models();
					cout << endl;

					cout << "Type continue to Exit Algorithm..." << flush;
					cin >> closeDHC;
					cout << endl;

				}


			}
			else if (pipeSelection == "DC") // Drill Collars Selection
			{

				// Well Diameter Value Input
				cout << "Well Diameter of the Scoped Section: " << flush;
				cin >> wellDiameter;

				// Drill Collars Pipe ID Input
				cout << "Pipe OD (Drill Collars): " << flush;
				cin >> pipeOD;

				// Drill Collars Length Value Output
				annularLength = dCLength;
				cout << "Drill Collars Length: " << flush;
				cout << annularLength;
				cout << endl;

				wellAnnular = calculate.wellAnnularCalc1(wellDiameter, pipeOD);

				annularArea = calculate.annularAreaCalc1(wellDiameter, pipeOD);

				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << endl;

				// Call method to calculate Mean Velocity, Critical Velocity and Pressure Losses through pipe flow
				calculate.annularflowcalcsPLM(flowRate, wellAnnular, annularLength, annularArea, mudDensity, dR100, dR3);
				cout << endl;

				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << endl;

				calculate.~Models();
				cout << endl;

				cout << "Type continue to Exit Algorithm..." << flush;
				cin >> closeDHC;
				cout << endl;

			}
		}

	}
	else if (flowSelection == "cancel") // Abort algorithm command
	{
		cout << "Drilling Hydraulics Models Algorithm Execution Canceled" << endl;
		cout << endl;

		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << endl;

		calculate.~Models();
		cout << endl;

		cout << "Type continue to Exit Algorithm..." << flush;
		cin >> closeDHC;
		cout << endl;

	}

	return 0;
}
