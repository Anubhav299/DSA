// leetcode question
// see carefully how we don't need the previous node to delete a specific node.



//we do this by overwriting the value of the node to be deleted by the data of next node
/*
    node->val = node->next->val;
    node->next = node->next->next;
*/