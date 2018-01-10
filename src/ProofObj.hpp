#include <vector>
#include "ProofNode.hpp"

class {
	public:
		// The set of all nodes in the proof.
		vector<ProofNode&> nodes;

		// The set of nodes which are assumed.
		vector<ProofNode&> premiseNodes;
		
		// The set of nodes which logically follow 
		// from the premiseNodes.
		vector<ProofNode&> followingNodes;


		void addPremise(ProofNode& prem);

		void removePremise(ProofNode& prem);

		// Adds a node to the list of all nodes.
		void appendNode(ProofNode& node);

		// Adds a node to the list of nodes that
		// follow from the premises.
		void appendFollowingNode(ProofNode& follow);

		// Removes the node at the given index
		// if valid. Returns 1 if successful,
		// 0 otherwise.
		int removeNodeAt(int index);
};
