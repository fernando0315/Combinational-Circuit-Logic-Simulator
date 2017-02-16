#ifndef CCIRCUIT_H
#define CCIRCUIT_H

#include "CCircuit.h"
#include <bitset>

void node::calcOut()
{
	output = *input[0];

	if(gateType == Gate::NOT)
		output = !(*input[0]);
	else if(gateType == Gate::AND)
		for (int i = 1; i < input.size(); i++)
			output &= *input[i];
	else if (gateType == Gate::OR)
	{
		for (int i = 1; i < input.size(); i++)
			output |= *input[i];
	}
	else if (gateType == Gate::XOR)
		for(int i = 1; i<input.size(); i++)
			output |= *input[i];
	else if(gateType == Gate::NAND)
	{
		for (int i = 1; i < input.size(); i++)
			output &= *input[i];
		output = !output;
	}
	else if(gateType == Gate::NOR)
	{
		for (int i = 1; i < input.size(); i++)
			output |= *input[i];
		output = !output;
	}
	else
	{
		for (int i = 1; i < input.size(); i++)
			output ^= *input[i];
		output = !output;
	}
}

void CCircuit::addGate(Gate gType, string gateName, vector<string> inputPtr)
{
	node *newNode = new node(gType);

	for (string i : inputPtr)
	{
		if (isdigit(i[0]))
		{
			if (gatesPtr.find(i) == gatesPtr.end())
			{
				cout << "Circuit is not well defined" << endl;
				exit(1);
			}

			node *nodePtr = gatesPtr[i];
			newNode->input.push_back(&(nodePtr->output));
		}
		else
		{
			cout << "Added const input: " << i << endl;
			if (cktInput.find(i) == cktInput.end()) cktInput[i] = 0;
			newNode->input.push_back(&cktInput[i]);
		}
	}
	cktOutput[gateName] = &(newNode->output);
	gatesPtr[gateName] = newNode;
}

void CCircuit::printTruthTable()
{
	int inputSize = cktInput.size();
	int maxValue = (int)pow(2, inputSize);

	for (int i = 0; i < maxValue; i++)
	{
		bitset<8> inputValue(i);
		int j = 0;
		for (map<string, bool>::iterator it = cktInput.begin(); it != cktInput.end(); it++)
			it->second = inputValue[j++];
		
		for (unordered_map<string, node*>::iterator it = gatesPtr.begin(); it != gatesPtr.end(); it++)
			it->second->calcOut();
	
		for (map<string, bool>::reverse_iterator it = cktInput.rbegin(); it != cktInput.rend(); it++)
			cout << it->second << '\t';

		cout << "|\t";

		for (map<string, bool*>::iterator it = cktOutput.begin(); it != cktOutput.end(); it++)
			cout << *(it->second) << '\t';

		cout << endl;
	}
}

#endif // !CCIRCUIT_H