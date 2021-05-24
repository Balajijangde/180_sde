/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* merge(Node *a, Node *b){
    Node root = Node(0);
    Node *temp = &root;
    
    while(a != NULL && b != NULL){
        if(a->data <= b->data){
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if(a == NULL){
        temp->bottom = b;
        return root.bottom;
    }else if(b == NULL){
        temp->bottom = a;
        return root.bottom;
    }
}    

Node *flatten(Node *root)
{
    Node *next, *current;
   if(root == NULL || root->next == NULL){
       return root;
   }
   next = flatten(root->next);
   return merge(root, next);
   
}