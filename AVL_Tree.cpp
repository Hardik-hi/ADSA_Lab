/*Program for insertion, deletion and searching in AVL tree*/

#include<bits/stdc++.h>
using namspace std;

class AVLTreeNode{
	AVLTreeNode* left;
	AVLTreeNode* right;
	AVLTreeNode* parent;
	int data;
	int height;
	
	AVLTreeNode(int x){
		left=right=NULL;
		parent=NULL;
		data=x;
		height=0;
	}
	
	AVLTreeNode(int x,AVLTreeNode* parent){
		left=right=NULL;
		parent=NULL;
		data=x;
		height=0;
		this.parent=parent;
	}
	
	
};

class AVLTree{
	
	AVLTreeNode* root;
	AVLTreeNode* searchNode(AVLTreeNode* root, int x);
	void insertNode(int x);
	void deleteNode(int x);
	void insertHelper(AVLTreeNode* root, int x);
		
	/* Functions*/
	
	void updateHeight(AVLTreeNode* z){
		int val=1;
		if (root->left != NULL)
			val = root->left->height + 1;

		if (root->right != NULL)
			val = max(
				val, root->right->height + 1);
		
		z->height=val;
				
	}
	AVLTreeNode* RR(AVLTreeNode* z){
		AVLTreeNode* temp=z->right;
		
		z->right=temp->left;
		if(temp->left)
			temp->left->parent=z;
			
		temp->parent=z->parent;
		if(temp->parent){
			if(temp->parent->data < z->data)	temp->parent->right=temp;
			else	temp->parent->left=temp;
		}
				
		z->parent=temp;
		temp->left=z;
		
		z=temp;
		
		updateHeight(z->left);
		updateHeight(z->right);
		updateHeight(z);
		updateHeight(z->parent);
		
		return z;
		
	}
	
	AVLTreeNode* LL(AVLTreeNode* z){
		AVLTreeNode* temp=z->left;
		
		z->left=temp->right
		if(temp->right)
			temp->right->parent=z;
			
		temp->parent=z->parent;
		if(temp->parent){
			if(temp->parent->data < z->data)	temp->parent->right=temp;
			else	temp->parent->left=temp;
		}
				
		z->parent=temp;
		temp->right=z;
		
		z=temp;
		
		updateHeight(z->left);
		updateHeight(z->right);
		updateHeight(z);
		updateHeight(z->parent);
		
		return z;
		
	}
	
	AVTreeNode* RL(AVLTreeNode* z){
		z->right=LL(z->right);
		RR(z);
	}
	
	AVTreeNode* LR(AVLTreeNode* z){
		z->left=RR(z->left);
		LL(z);
	}
	
	//function to search a given node
	AVLTreeNode* searchNode(AVLTreeNode* r, int x){
		
		if(!r)	return NULL;
		
		if(r->data < x)	return searchNode(r->right,x);
		if(r->data > x)	return searchNode(r->left,x);
		
		return root;
		
	}
	
	//insertion helper function
	AVLTreeNode* insertHelper(AVLTreeNode* r, int val,AVLTreeNode* parent){
		
		if(r==NULL)
			r=new AVLTreeNode(val,parent);
		
        //insert to left
        else if(val < r->data){
        	
			AVLTreeNode* left_child=insertHelper(r->left,val,r);
        	
        	//compare the heights after insertion
        	int lh=0,rh=0;
        	if(r->left)
        		lh=r->left->height;
        	if(r->right)
        		rh=r->right->height;
        	
        	if(abs(lh-rh)==2){
        		
        		if(r->left && r->left->data > val){
        			//LL rot
        			LL(r);
				}
				else{
					LR(r);
				}
			}	
		}
		
		else if(val > r->data){
        	
			AVLTreeNode* right_child=insertHelper(r->right,val,r);
        	
        	//compare the heights after insertion
        	int lh=0,rh=0;
        	if(r->left)
        		lh=r->left->height;
        	if(r->right)
        		rh=r->right->height;
        	
        	if(abs(lh-rh)==2){
        		
        		if(r->right && r->right->data > val){
        			//LL rot
        			RL(r);
				}
				else{
					RR(r);
				}
			}
		}
		
		updateHeight(r);
		return r;
        
    }

	//function to insert a given node
	AVLTreeNode* insertNode(int key){
		//inserting the node at appropriate position
		AVLTreeNode* x=insertHelper(root,val);
        return x;        
	}
	
};

int main(){
	
}
