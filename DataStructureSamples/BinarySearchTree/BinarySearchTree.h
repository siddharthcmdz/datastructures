#pragma once
#include <vector>

namespace ds
{
#define INVALID_ID ~0;
	typedef unsigned int BSTuint;
	typedef unsigned int* BSTuintPtr;

	namespace bst
	{
		struct BSTnode;
		typedef BSTnode* BSTnodePtr;

		struct BSTnode
		{
			BSTuint id = INVALID_ID;
			BSTnodePtr left = nullptr;
			BSTnodePtr right = nullptr;
		};

		/**
		* A storage for user inputs for Binary Search Tree nodes.
		*/
		class BSTinput
		{
		private:
			std::vector<BSTuint> m_inputs;

		public:
			BSTinput(BSTuint maxInputs);
			const BSTuintPtr getInputs(size_t& numInputs) const;
			~BSTinput();
		};

		/**
		* A factory to generate Binary Search Trees.
		*/
		class BSTgenerator
		{
			static BSTnodePtr insertRecursive(BSTnodePtr rootNode, BSTuint nodeID);

		public:
			static BSTnodePtr generateTree(const BSTinput& inputter);
		};

		/**
		* A formatter to output a tree with ASCII diagram to the console window.
		*/
		class BSTformatter
		{
		public:
			static void formatPrint(const BSTnodePtr node);
		};

	}

}
