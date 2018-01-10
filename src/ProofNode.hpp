#include <vector>

/*
 * A ProofNode is a general representation of a
 * single element or line in a proof.
 */
class ProofNode {
	public:
		ProofNode *previous;
		ProofNode *next;

		char *content;

		ProofNode();
		ProofNode(char *con);

		int number;
		vector<ProofNode&> references;
};
