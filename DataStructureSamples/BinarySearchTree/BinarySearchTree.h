#pragma once
#include <vector>

namespace ds
{
#define INVALID_ID ~0;
	typedef unsigned int DSuint;
	typedef unsigned int* DSuintPtr;

	namespace bst
	{
		struct BSTnode;
		typedef BSTnode* BSTnodePtr;

		struct BSTnode
		{
			DSuint id = INVALID_ID;
			BSTnodePtr left = nullptr;
			BSTnodePtr right = nullptr;
		};

		enum BSTinputType
		{
			Manual,
			Auto
		};

		/**
		* A storage for user inputs for Binary Search Tree nodes.
		*/
		class BSTinputs
		{
		private:
			std::vector<DSuint> m_inputs;
			BSTinputType m_inputType;

		public:
			BSTinputs(const BSTinputType& inputType, DSuint numNodes);
			void push(DSuint nodeID);
			void pop();
			const DSuintPtr getInputs(size_t* numInputs = nullptr) const;
			~BSTinputs();
		};

		/**
		* A factory to generate Binary Search Trees.
		*/
		class BSTgenerator
		{
			static BSTnodePtr insertRecursive(BSTnodePtr rootNode, DSuint nodeID);

		public:
			static BSTnodePtr generateTree(const BSTinputs& inputter);
			static void disposeTree(BSTnodePtr node);
		};
		
		enum BSTtraversalType {
			InOrder,
			PreOrder,
			PostOrder
		};

		/**
		* A formatter to output a tree with ASCII diagram to the console window.
		*/
		class BSTformatter
		{
		private:
			static void visitInorder(const BSTnodePtr node);
			static void visitPostorder(const BSTnodePtr node);
			static void visitPreOrder(const BSTnodePtr node);

		public:
			static void formatPrint(const BSTnodePtr node, const BSTtraversalType& traversalType);
		};

	}

}

