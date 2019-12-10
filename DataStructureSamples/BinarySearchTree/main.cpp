#include "BinarySearchTree.h"

using namespace ds::bst;

int main(int argc, char* argv[])
{
	BSTinputs inputs;
	unsigned int nodeIDs[7] = { 5, 3, 2, 1, 4, 9, 8 };
	for (ds::BSTuint i = 0; i < 7; ++i)
	{
		inputs.push(nodeIDs[i]);
	}

	BSTnodePtr rootNode = BSTgenerator::generateTree(inputs);


	return 0;
}