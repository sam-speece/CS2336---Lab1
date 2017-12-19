/*TieFighters.cpp
Sam Speece - sds160130
August 31, 2016
CS 2336.004
This program takes in the name of the pilot and points of a polygon from a file.  It then finds the area of that polygon
and prints out the pilots name and the area of the polygon.*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

void getCoordinates(string&, double[], double[], ifstream&);
double findArea(double[], double[]);
void printCoordinates(string, double sum, ofstream&);
void clearCoordinates(double[], double[]);

int main()
{
    ifstream inData;
    ofstream outData;
    double xArray[15] = {0};
    double yArray[15] = {0};
    string name;
    double area;

    inData.open("pilot_routes3.txt");
    outData.open("pilot_areas.txt");

    if(inData.is_open())
    {
        while(!inData.eof())
        {
            getCoordinates(name, xArray, yArray, inData);
            area = findArea(xArray, yArray);
            printCoordinates(name, area, outData);
            clearCoordinates(xArray, yArray);
        }

    }else
        cout << "Could not find file.";

    inData.close();
    outData.close();
}

void getCoordinates(string& name, double xArray[], double yArray[], ifstream& inData)
{
    inData >> name;
    int i = 0;

    do
    {
        inData >> xArray[i];
        inData.ignore();
        inData >> yArray[i];
        i++;
    }while(i == 1 || (xArray[0] != xArray[i - 1]) || (yArray[0] != yArray[i - 1]));
}

double findArea(double xArray[], double yArray[])
{
    double area = 0;
    int i = 1;
    area += (xArray[1] + xArray[0]) * (yArray[1] - yArray[0]);

    while(xArray[i] != xArray[0] || yArray[i] != yArray[0])
    {
        area += (xArray[i+1] + xArray[i]) * (yArray[i+1] - yArray[i]);
        i++;
    }

    return abs(area) * .5;
}

void printCoordinates(string name, double area, ofstream& outData)
{
    outData << fixed << showpoint << setprecision(2);
    outData << name << setw(10) << area << endl;
}

void clearCoordinates(double xArray[], double yArray[])
{
    for(int i = 0; i < 15; i++)
    {
        xArray[i] = 0;
        yArray[i] = 0;
    }
}
