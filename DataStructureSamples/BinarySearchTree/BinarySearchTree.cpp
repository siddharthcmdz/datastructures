#include "BinarySearchTree.h"


namespace ds
{
	namespace bst
	{
		BSTinput::BSTinput(BSTuint maxInputs)
		{
			m_inputs.resize(maxInputs);
		}

		const BSTuintPtr BSTinput::getInputs(size_t& numInputs) const
		{
			numInputs = m_inputs.size();
			return (BSTuintPtr)m_inputs.data();
		}

		BSTinput::~BSTinput()
		{
		}

		BSTnodePtr BSTgenerator::insertRecursive(BSTnodePtr rootNode, BSTuint nodeID)
		{
			if (rootNode == nullptr)	return new BSTnode{ nodeID };

			if (nodeID < rootNode->id)
				rootNode->left = insertRecursive(rootNode->left, nodeID);

			if (nodeID > rootNode->id)
				rootNode->right = insertRecursive(rootNode->right, nodeID);

			return rootNode;
		}

		BSTnodePtr BSTgenerator::generateTree(const BSTinput &inputter)
		{
			size_t numNodes;
			BSTuint* nodeIDs = inputter.getInputs(numNodes);
			
			if (numNodes < 1)
				return nullptr;

			BSTnodePtr rootNode = new BSTnode{ nodeIDs[0], nullptr, nullptr };

			if (nodeIDs != nullptr)
			{

				for (BSTuint i = 1; i < numNodes; ++i)
				{
					insertRecursive(rootNode, nodeIDs[i]);
				}
			}

			return rootNode;
		}

		void BSTformatter::formatPrint(const BSTnodePtr node)
		{
		}
	}
}
