node* maxnode=NULL;
node*maxelementofbst(node*root){
	if(!root)
	return NULL;
	do{
		maxnode=root;
		root=root->right;
	}
	while(root!=NULL);
	return maxnode;
}
