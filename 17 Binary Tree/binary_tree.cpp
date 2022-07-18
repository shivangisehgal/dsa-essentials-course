#include<iostream>
#include<vector>
using namespace std;
//Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

// Output : 1 2 4 5 7 3 6
// Inorder : 4, 2,7,5,1,3,6
// Postorder : 4,7,5,2,6,3,1
class Node{

public:
	int data;
	Node * left;
	Node * right;

	Node(int d){
		data = d;
		left = right = NULL;
	}
};
//Preorder Build of the Tree Root, Left, Right Tree
Node* buildTree(){

	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}

	Node* n = new Node(d);
	n->left = buildTree();
	n->right = buildTree();
	return n;
}

void printPreorder(Node *root){
	if(root==NULL){
		return;
	}
	cout << root->data <<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}
void printInorder(Node *root){
	if(root==NULL){
		return;
	}
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

void postOrder(Node * root){
	if(root==NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data <<" ";
}

//PRINTING A TREE IN LEVEL ORDER
//O(N)
vector<int> levelOrder(Node* node)
    {
        if(node == NULL)
            return {};
        
        queue<Node*> q;
        vector<int> v;
        
        q.push(node);
        q.push(NULL)
        
        while(!q.empty())
        {
            Node* front = q.front();
            
            if(front == NULL)
            {
                q.pop();
                //cout << '\n'
                //insert a new NULL for the next level
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                q.pop();
            
                v.push_back(front->data);
                //cout << front->data > " "; 
                if(front->left != NULL)
                {
                    q.push(front->left);
                }
                if(front->right != NULL)
                {
                    q.push(front->right);
                }
            }
        }
        
        return v;
    }
    
//CREATING A TREE IN LEVEL ORDER
//O(N)
Node* createLevelOrder()
{
    if (root == NULL)
        return;
    queue<Node*> q;
    
    int d;
    cin >> d;
    Node* root = new Node(d);
    q.push(root);
    
    while (!q.empty()) {
        
        int front = q.front();
        q.pop();
        
        int c1, c2;
        cin >> c1 >> c2;
        if(c1 != -1)
        {
            front->left = new Node(c1);
            q.push(front->left);
        }
        if(c2 != -1)
        {
            front->right = new Node(c2);
            q.push(front->right);
        }
    }
    
    return root;
}
//HEIGHT OF A BINARY TREE
//O(N)
int height(Node* root)
    {
        if(root == NULL)
        return 0;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        return max(leftHeight, rightHeight) + 1;
    }
    
//DIAMETER OF A TREE
// M1
//O(N^2)
int treeDiameter(Node* root)
{
    int dRoot = height(root->left) + height(root->right); //(h1 - 1 + h2 - 1 + 1 + 1) 
    int dLeft = treeDiameter(root->left);
    int dRight = treeDiameter(root->right);
    
    return max(dRoot, dLeft, dRight);
}

//M2
//O(N)
class hdpair{
    public:
    int height;
    int diameter;
};

hdpair optDiameter(Node* root)
{
    hdpair obj;
    
    if(root == NULL)
    {
        obj.height = obj.diameter = 0;
        return obj;
    }
    
    hdpair Left =  optDiameter(root->left);
    hdpair Right =  optDiameter(root->right);
    
    obj.height = max(Left.height, Right.height) + 1;
    
    int rootDiameter = Left.height + Right.height + 1;
    int leftDiameter = Left.diameter;
    int rightDiameter = Right.diameter;
    
    obj.diameter = max(rootDiameter, max(leftDiameter, rightDiameter));
    
    return obj;
}
int diameter(Node* root) {
        
        hdpair obj = optDiameter(root);
        return obj.diameter;
}


void printRoot2LeafPaths(Node * root,vector<int> &path){

	if(root==NULL){
		return;
	}

	if(root->left==NULL and root->right==NULL){
		//print the vector
		for(int node:path){
			cout<<node<<"->";
		}
		cout<<root->data<<"->";
		cout<<endl;
		return;
	}

	//rec case
	path.push_back(root->data);
	printRoot2LeafPaths(root->left,path);
	printRoot2LeafPaths(root->right,path);
	//backtracking
	path.pop_back();
	return;

}

int main(){

	Node * root = buildTree();
	printPreorder(root);
	cout<<endl;

	printInorder(root);
	cout<<endl;

	postOrder(root);
	cout<<endl;

	vector<int> path;
	printRoot2LeafPaths(root,path);

	return 0;
}


