#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "CCircuit.h"

using namespace std;

int main()
{
	CCircuit c1;
	vector<string> inputList1;
	inputList1.push_back("A");
	inputList1.push_back("B");
	c1.addGate(XNOR, "XNOR1", inputList1);

	vector<string> inputList2;
	inputList2.push_back("1");
	inputList2.push_back("C");
	c1.addGate(XNOR, "SUM", inputList2);

	vector<string> inputList3;
	inputList3.push_back("A");
	inputList3.push_back("C");
	c1.addGate(AND, "AND2", inputList3);

	vector<string> inputList4;
	inputList4.push_back("A");
	inputList4.push_back("B");
	c1.addGate(AND, "AND1", inputList4);

	vector<string> inputList5;
	inputList5.push_back("B");
	inputList5.push_back("C");
	c1.addGate(AND, "AND3", inputList5);

	vector<string> inputList6;
	inputList6.push_back("3");
	inputList6.push_back("4");
	inputList6.push_back("5");
	c1.addGate(OR, "CARRY", inputList6);

	c1.printTruthTable();
}

