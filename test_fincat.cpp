//JA - it is good practice to insert comment about intended use, context, contributors, etc
//KE - Included libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cassert> //KE - Used for asserting whether 2 things are the same. Used to test functions. See https://learn.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2022

using namespace std;

float dollarsToRands(float x)
{
    float exchangeRate = 20;
    return(x * exchangeRate);
}
void test_dollarsToRands()
{
    //KE - Testing with positive number
    float result = dollarsToRands(10);
    assert(result == 200);
     
    //KE - Testing with 0
    result = dollarsToRands(0);
    assert(result == 0);
}

double calcRatioPM(double revenue, double expenses)
{
    return((revenue - expenses) / revenue);
}
void test_calcRatioPM()
{
    //KE - Testing with positive values
    double revenue=100, expenses = 10;
    double result = calcRatioPM(revenue, expenses);
    assert(result == 0.9);

    //KE - Testing with negative values
    revenue = -100;
    expenses = -10;
    result = calcRatioPM(revenue, expenses);
    assert(result == 0.9);

    //KE - Testing with zero values
    revenue = 0;
    expenses = 0;
    result = calcRatioPM(revenue, expenses);
    assert(result == 0);
}

double calcRatioRoA(double revenue, double expenses, double assets)
{
    return ((revenue - expenses) / assets); //KE - fixed equation 
}
void test_calcRatioRoA()
{
    //KE - Testing with all positive values
    double revenue = 100, expenses = 10, assets=100;
    double result = calcRatioRoA(revenue, expenses, assets);
    assert(result == 0.9);

    //KE - Testing with negative values
    revenue = -100, expenses = -10, assets = -100;
    result = calcRatioRoA(revenue, expenses, assets);
    assert(result == 0.9);

    //KE - Testing with zero values
    revenue = 0, expenses = 0, assets = 0;
    result = calcRatioRoA(revenue, expenses, assets);
    assert(result == 0);
}

double calcRatioDE(double assets, double liabilities)
{
    return(liabilities / assets);  //KE - fixed equation
}
void test_calcRatioDE()
{
    //KE - Test with positive numbers 
    double assets = 100, liabilities = 200;
    double result = calcRatioDE(assets, liabilities);
    assert(result == 2);

    //KE - Test with negative numbers
    assets = -100, liabilities = -200;
    result = calcRatioDE(assets, liabilities);
    assert(result == 2);

    //KE - Test with zero values
    assets = 0, liabilities = 0;
    result = calcRatioDE(assets, liabilities);
    assert(result == 2);
}

string categorisePM(double ratio)
{
    string cat;
    if (ratio < 0.08)
        cat = "unhealty";
    else if (ratio < 0.15 && ratio>0.08)  //KE - fixed condition
        cat = "average";
    else
        cat = "healthy";
    return(cat);
}
void test_categorisePM()
{
    //KE - Testing small ratio values - should be categorized as "unhealthy"
    double ratio = 0.0025;
    string result = categorisePM(ratio);
    assert(result == "unhealthy");

    //KE - Testing ratio values slighly below 0.08 - should be categorized as "unhealthy"
    ratio = 0.0799;
    result = categorisePM(ratio);
    assert(result == "unhealthy");

    //KE - Testing ratio values slightly above 0.08 - should be categorized as "average"
    ratio =0.08001;
    result = categorisePM(ratio);
    assert(result == "average");

    //KE - Testing ratio values slighly below 0.15 - should be categorized as "average"
    ratio = 0.1499;
    result = categorisePM(ratio);
    assert(result == "average");

    //KE - Testing ratio values slighly above 0.15 - should be categorized as "healthy"
    ratio = 0.1501;
    result = categorisePM(ratio);
    assert(result == "healthy");

    //KE - Testing ratio values above 0.15 - should be categorized as "healthy"
    ratio = 0.2;
    result = categorisePM(ratio);
    assert(result == "healthy");

    //KE - Testing ratio values at exactly 0.15 - should be categorized as "average"
    ratio = 0.15;
    result = categorisePM(ratio);
    assert(result == "average");  
    
    //KE - Testing ratio values at exactly 0.08 - should be categorized as "average"
    ratio = 0.08;
    result = categorisePM(ratio);
    assert(result == "average");
}

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
void test_categoriseRoA()
{
    //KE - Testing small ratio values - should be categorized as "unhealthy"
    double ratio = 0.0025;
    string result = categoriseRoA(ratio);
    assert(result == "unhealthy");

    //KE - Testing ratio values slighly below 0.08 - should be categorized as "unhealthy"
    ratio = 0.0799;
    result = categoriseRoA(ratio);
    assert(result == "unhealthy");

    //KE - Testing ratio values slightly above 0.08 - should be categorized as "average"
    ratio = 0.08001;
    result = categoriseRoA(ratio);
    assert(result == "average");

    //KE - Testing ratio values slighly below 0.15 - should be categorized as "average"
    ratio = 0.1499;
    result = categoriseRoA(ratio);
    assert(result == "average");

    //KE - Testing ratio values slighly abov 0.15 - should be categorized as "healthy"
    ratio = 0.1501;
    result = categoriseRoA(ratio);
    assert(result == "healthy");

    //KE - Testing ratio values above 0.15 - should be categorized as "healthy"
    ratio = 0.2;
    result = categoriseRoA(ratio);
    assert(result == "healthy");

    //KE - Testing ratio values at exactly 0.15 - should be categorized as "average"
    ratio = 0.15;
    result = categoriseRoA(ratio);
    assert(result == "average");

    //KE - Testing ratio values at exactly 0.08 - should be categorized as "average"
    ratio = 0.08;
    result = categoriseRoA(ratio);
    assert(result == "average");
}

string categoriseDE(double ratio)
{
    string cat;
    if (ratio < 1)
        cat = "healthy";
    else if (ratio >= 1 && ratio < 2)   //KE - fixed contition
        cat = "average";
    else
        cat = "unhealthy";
    return(cat);
}
void test_categoriseDE()
{
    //KE - Testing ratio values below 1 - should be categorized as "healthy"
    double ratio = 0.5;
    string result = categoriseDE(ratio);
    assert(result == "healthy");

    //KE - Testing ratio values slightly below 1 - should be categorized as "healthy"
    ratio = 0.999;
    result = categoriseDE(ratio);
    assert(result == "healthy");

    //KE - Testing ratio values slightly above 1 - should be categorized as "average"
    ratio = 1.001;
    result = categoriseDE(ratio);
    assert(result == "average");

    //KE - Testing ratio values slightly below 2 - should be categorized as "average"
    ratio = 1;
    result = categoriseDE(ratio);
    assert(result == "average");

    //KE - Testing ratio values slightly above 1 - should be categorized as "average"
    ratio = 1.001;
    result = categoriseDE(ratio);
    assert(result == "average");

    //KE - Testing ratio values slightly above 2 - should be categorized as "unhealthy"
    ratio = 2.001;
    result = categoriseDE(ratio);
    assert(result == "unhealthy");

    //KE - Testing ratio values exactly 1 - should be categorized as "average"
    ratio = 2;
    result = categoriseDE(ratio);
    assert(result == "unhealthy");

}

void process_data(char* input_file, char* output_file)
{
    //KE - Initializing variables
    ifstream f_in;
    ofstream f_out;
    string data;
    string company_id;
    double revenue_USD, expenses, assets, liabilities, ratio_PM, ratio_RoA, ratio_DE;
    float  revenue_ZAR=0;
    string cat, cat2, cat3; //KE - All char variables were changed to string variables

    //KE - Opening input and output files
    f_in.open(input_file, ios::in);
    f_out.open(output_file, ofstream::out);
    //KE - Setting variabes with data from the input file
    while (!f_in.eof())
    {
        f_in >> company_id >> revenue_USD >> expenses >> assets >> liabilities;
        revenue_ZAR = dollarsToRands(revenue_ZAR);
        ratio_PM = calcRatioPM(revenue_USD, expenses);
        cat = categorisePM(ratio_PM);
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

//KE - Unit test functions
int main()
{
    test_dollarsToRands();

    test_calcRatioPM();
    test_calcRatioRoA();
    test_calcRatioDE();

    test_categorisePM();
    test_categoriseRoA();
    test_categoriseDE();
}

