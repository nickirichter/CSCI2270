struct TreeNode{

	int key;

	TreeNode *leftChild;

	TreeNode *rightChild;

	TreeNode *parent;

};

void replaceMaxWithMin(TreeNode* root)
{
	int minimum;
	TreeNode* temp=root;
	while(temp!=NULL)
	{
	    if(temp->leftChild==NULL)
	    {
	        minimum=temp->key;
	        if (temp->rightChild!=NULL)
	        {
	            
	            temp->parent->leftChild = temp->>rightChild;
	        }
			else
			{
			    temp->parent->leftChild= NULL;   
			}
		}
		temp=temp->leftChild;
	}
	temp=root;
	while(temp!=NULL)
	{
	    if (temp->rightChild==NULL)
	    {
	        temp->key=minimum;
	    }
	    temp=temp->rightChild;
	}
}