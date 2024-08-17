#include"LinkedList.h"
#include<stdlib.h>

void delete_nodes(struct TreeNode **tree,struct TreeNode **result,int *resultSize,bool *should_delete) 
{
    // Guard clause to do nothing on NULL node
    if (!*tree) return;

    // Keep recursing post-order so that the latest deletions process first.
    // That way, we don't dangle any of our TreeNode references.
    delete_nodes(&(*tree)->left, result, resultSize, should_delete);
    delete_nodes(&(*tree)->right, result, resultSize, should_delete);

    // Here we process the deletion, though if this node isn't getting deleted we bail.
    if (should_delete[(*tree)->val] == false) return;

    // When a node is deleted, its children become new forest roots. We'll therefore have to
    // push each child (if existent) to the result array.
    if ((*tree)->left) result[(*resultSize)++] = (*tree)->left;
    if ((*tree)->right) result[(*resultSize)++] = (*tree)->right;

    // The reason why we use double/indirect pointers is so that we can overwrite the reference
    // pointing to the tree being deleted, instead of having to mangle return values and deal
    // with even more edge cases regarding leaves and roots.
    *tree = NULL;
}

struct TreeNode **delNodes(struct TreeNode *root, int *to_delete, int to_deleteSize, int *returnSize)
{
    // Initialize output variables
    *returnSize = 0;
    struct TreeNode **result = calloc(1001, sizeof(struct TreeNode *));

    // Create should_delete map
    bool *should_delete = calloc(1001, sizeof(bool));
    for (int i = 0; i < to_deleteSize; i++) {
        should_delete[to_delete[i]] = true;
    }

    // Post-order traversal; re-add root if it survives
    delete_nodes(&root, result, returnSize, should_delete);
    if (root) result[(*returnSize)++] = root;
    return result;
}
int main()
{
   
    return 0;
}