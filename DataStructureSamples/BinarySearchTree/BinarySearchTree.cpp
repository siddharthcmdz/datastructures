#include "BinarySearchTree.h"


namespace ds
{
	namespace bst
	{
		BSTinput::BSTinput()
		{
		}

		const BSTuintPtr BSTinput::getInputs(size_t& numInputs) const
		{
			numInputs = m_inputs.size();
			return (BSTuintPtr)m_inputs.data();
		}

		void BSTinput::push(BSTuint nodeID)
		{
			m_inputs.push_back(nodeID);
		}

		void BSTinput::pop()
		{
			m_inputs.pop_back();
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
