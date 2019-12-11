#include "BinarySearchTree.h"
#include <iostream>

using namespace ds::bst;

int main(int argc, char* argv[])
{
#define MAX_NODES 7
	BSTinputs inputs(BSTinputType::Manual, MAX_NODES);
	unsigned int nodeIDs[MAX_NODES] = { 5, 3, 2, 1, 4, 9, 8 };
	for (ds::DSuint i = 0; i < MAX_NODES; ++i)
	{
		inputs.push(nodeIDs[i]);
	}
	
	//write node inputs to console
	{
		std::cout << "Node Inputs" << std::endl;
		std::cout << "-----------" << std::endl;
		const ds::DSuintPtr nodeIDs = inputs.getInputs();
		for (int i = 0; i < MAX_NODES; ++i)
		{
			std::cout << nodeIDs[i] << " ";
		}
		std::cout << std::endl << std::endl;
	}

	BSTnodePtr rootNode = BSTgenerator::generateTree(inputs);

	//write traversal outputs to console.
	{
		std::cout << "Node Traversal(InOrder):" << std::endl;
		std::cout << "------------------------" << std::endl;

		BSTformatter::formatPrint(rootNode, BSTtraversalType::InOrder);
		std::cout << std::endl << std::endl;

		std::cout << "Node Traversal(PreOrder):" << std::endl;
		std::cout << "------------------------" << std::endl;
		BSTformatter::formatPrint(rootNode, BSTtraversalType::PreOrder);
		std::cout << std::endl << std::endl;

		std::cout << "Node Traversal(PostOrder):" << std::endl;
		std::cout << "------------------------" << std::endl;
		BSTformatter::formatPrint(rootNode, BSTtraversalType::PostOrder);
		std::cout << std::endl << std::endl;

	}

	getchar();

	return 0;
}