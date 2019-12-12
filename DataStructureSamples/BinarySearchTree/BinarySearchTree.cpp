#include "BinarySearchTree.h"
#include <stdlib.h>
#include <iostream>

namespace ds
{
	namespace bst
	{
		BSTinputs::BSTinputs(const BSTinputType& inputType, DSuint numNodes) :
			m_inputType(inputType)
		{
			m_inputs.reserve(numNodes);
			if (m_inputType == BSTinputType::Auto)
			{
				for (DSuint i = 0; i < numNodes; ++i)
				{
					DSuint rndNum = rand() % numNodes + 1;
					m_inputs.push_back(rndNum);
				}
			}
		}

		const DSuintPtr BSTinputs::getInputs(size_t* numInputs) const
		{
			if (numInputs != nullptr)
			{
				*numInputs = m_inputs.size();
			}

			return (DSuintPtr)m_inputs.data();
		}

		void BSTinputs::push(DSuint nodeID)
		{
			m_inputs.push_back(nodeID);
		}

		void BSTinputs::pop()
		{
			m_inputs.pop_back();
		}

		BSTinputs::~BSTinputs()
		{
		}

		BSTnodePtr BSTgenerator::insertRecursive(BSTnodePtr rootNode, DSuint nodeID)
		{
			if (rootNode == nullptr)	return new BSTnode{ nodeID };

			if (nodeID < rootNode->id)
				rootNode->left = insertRecursive(rootNode->left, nodeID);

			if (nodeID > rootNode->id)
				rootNode->right = insertRecursive(rootNode->right, nodeID);

			return rootNode;
		}

		BSTnodePtr BSTgenerator::insertIterative(BSTnodePtr rootNode, DSuint nodeID)
		{
			BSTnodePtr newNode = new BSTnode{ nodeID, nullptr, nullptr };

			BSTnodePtr trailingNode = nullptr;
			BSTnodePtr currNode = rootNode;

			while (currNode != nullptr)
			{
				trailingNode = currNode;

				if (nodeID < currNode->id)
					currNode = currNode->left;
				else
					currNode = currNode->right;
			}

			if (trailingNode == nullptr)
				return newNode;
			else
			{
				if (nodeID < trailingNode->id)
					trailingNode->left = newNode;
				else
					trailingNode->right = newNode;
			}

			return trailingNode;
		}

		BSTnodePtr BSTgenerator::genRecursive(const BSTinputs & inputter)
		{
			size_t numNodes;
			DSuint* nodeIDs = inputter.getInputs(&numNodes);

			if (numNodes < 1)
				return nullptr;

			BSTnodePtr rootNode = new BSTnode{ nodeIDs[0], nullptr, nullptr };

			if (nodeIDs != nullptr)
			{

				for (DSuint i = 1; i < numNodes; ++i)
				{
					insertRecursive(rootNode, nodeIDs[i]);
				}
			}

			return rootNode;
		}

		BSTnodePtr BSTgenerator::genIterative(const BSTinputs& inputter)
		{
			size_t numNodes;
			DSuint* nodeIDs = inputter.getInputs(&numNodes);

			if (numNodes < 1)
				return nullptr;

			BSTnodePtr rootNode = new BSTnode{ nodeIDs[0], nullptr, nullptr };
			if (nodeIDs != nullptr)
			{
				for (DSuint i = 1; i < numNodes; ++i)
				{
					insertIterative(rootNode, nodeIDs[i]);
				}
			}

			return rootNode;
		}

		BSTnodePtr BSTgenerator::generateTree(const BSTinputs& inputter, const BSTgenerationType& genType)
		{
			switch (genType)
			{
			case BSTgenerationType::Recursive:
				return genRecursive(inputter);

			case BSTgenerationType::Iterative:
				return genIterative(inputter);
			}

			return nullptr;
		}

		void BSTgenerator::disposeTree(BSTnodePtr node)
		{
			if (node == nullptr) return;

			disposeTree(node->left);
			disposeTree(node->right);

			delete node;
			node = nullptr;
		}

		void BSTformatter::visitInorder(const BSTnodePtr node)
		{
			if (node == nullptr) return;

			visitInorder(node->left);

			std::cout << node->id << " ";

			visitInorder(node->right);
		}

		void BSTformatter::visitPostorder(const BSTnodePtr node)
		{
			if (node == nullptr) return;
			
			std::cout << node->id << " ";

			visitPostorder(node->right);

			visitPostorder(node->left);
		}

		void BSTformatter::visitPreOrder(const BSTnodePtr node)
		{
			if (node == nullptr) return;

			std::cout << node->id << " ";

			visitPreOrder(node->left);

			visitPreOrder(node->right);
		}

		void BSTformatter::formatPrint(const BSTnodePtr node, const BSTtraversalType& traversalType)
		{
			switch (traversalType)
			{
			case BSTtraversalType::InOrder:
				visitInorder(node);
				break;

			case BSTtraversalType::PreOrder:
				visitPreOrder(node);
				break;

			case BSTtraversalType::PostOrder:
				visitPostorder(node);
				break;
			}
		}
	}
}
