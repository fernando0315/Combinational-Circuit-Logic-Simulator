#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

#define MAX_INPUT 8

using namespace std;

enum Gate { NOT, AND, OR, NAND, NOR, XOR, XNOR };

struct node {
	Gate gateType;
	vector<bool*> input;
	string id;
	bool output;
	bool lastOutput;

	node() : input(MAX_INPUT) {}
	node(Gate gType) : lastOutput(true) { gateType = gType; }
	void calcOut();
};

class CCircuit
{
private:
	unordered_map<string, node*> gatesPtr;
	map<string, bool*> cktOutput;
	map<string, bool> cktInput;
public:
	CCircuit() {}
	~CCircuit() {}
	void addGate(Gate, string, vector<string>);
	void printTruthTable();
};

