node* minnode=NULL;
node*minelementofbst(node*root){
	if(!root)
	return NULL;
	do{
		minnode=root;
		root=root->left;
	}
	while(root!=NULL);
	return minnode;
}
