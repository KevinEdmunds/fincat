// JA - it is good practice to insert comment about intended use, context, contributors, etc
//KE - Included libraries
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//KE - Function name changed for consistent naming convention
//KE - Converts the rand value to a dollar value
float dollarsToRands(float x)
{
    return(x*20);
}

//KE - Calculates profit margin ratio
double calcRatioPM(double revenue, double expenses)
{
    return((revenue-expenses)/revenue);
}

//KE - Calculates return on assets ratio
double calcRatioRoA(double revenue, double expenses, double assets)
{
    return ((revenue-expenses) / assets); //KE - fixed equation 
}

//KE - Caclulates debt-to-equite ratio
double calcRatioDE(double assets, double liabilities)
{
    return(liabilities/assets);  //KE - fixed equation
}

//KE - Categorises the profit margin ratio
string categorisePM(double ratio)
{
    string cat;
    if (ratio<0.08)
        cat="unhealty";
    else if (ratio<0.15&&ratio>0.08)  //KE - fixed condition
        cat="average";
    else
        cat="healthy";
    return(cat);
}

//KE - Categorises the return on assets ratio
string categoriseRoA(double ratio)
{
    string cat;
    if (ratio < 0.08)
        cat = "unhealthy";
    else if (ratio < 0.15 && ratio > 0.08)  //KE -fixed condition
        cat = "average";
    else
        cat = "healthy";
    return(cat);
}

//KE - Categorises the debt-to-equity ratio
string categoriseDE(double ratio)
{
    string cat;
    if (ratio < 1)
        cat = "healthy";
    else if (ratio>=1&&ratio < 2)   //KE - fixed contition
        cat = "average";
    else
        cat = "unhealthy";
    return(cat);
}

void process_data(char* input_file, char* output_file)
{
    //KE - Initializing variables
    ifstream f_in;
    ofstream f_out;
    string data;
    string company_id;
    double revenue_USD, expenses, assets, liabilities, revenue_ZAR, ratio_PM, ratio_RoA, ratio_DE;
    string cat, cat2, cat3; //KE - All char variables were changed to string variables

    //KE - Opening input and output files
    f_in.open(input_file,ios::in);
    f_out.open(output_file,ofstream::out);


    //KE - Setting variabes with data from the input file
    while (!f_in.eof())
    {
    	f_in >> company_id >> revenue_USD >> expenses >> assets >> liabilities;
        revenue_ZAR = dollarsToRands(revenue_ZAR);
        ratio_PM = calcRatioPM(revenue_USD, expenses);
        cat=categorisePM(ratio_PM);
        ratio_RoA = calcRatioRoA(revenue_ZAR, expenses, assets);;
        cat2 = categoriseRoA(ratio_RoA);
        ratio_DE = calcRatioDE(assets, liabilities);
        cat3 = categoriseDE(ratio_DE);;
	f_out << company_id << " " << ratio_PM << " " << cat << ratio_RoA << " " << cat3 << ratio_DE << " " << cat2 << endl;
    }

    //KE - Closing the files when they are no longer needed
    f_in.close();
    f_out.close();
}
        
int main(int argc, char *argv[])
{
    // JA - Need to check that 3 arguments were supplied upon execution
    process_data(argv[1], argv[2]);
}

