#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#define MAX_INPUT 8

using namespace std;

class CCircuit
{
private:
	enum Gate {NOT, AND, OR, NAND, NOR, XNOR};
	struct node{
		node() : input(MAX_INPUT) {}
		Gate gateType;
		vector<bool*> input;
		bool output;
	};

	vector<bool*> cktOutput;

public:


};