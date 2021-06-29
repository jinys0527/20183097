#include <stdio.h>
#include <stdlib.h>
#define max(a,b)		(((a) > (b)) ? (a) : (b))			//a와 b중에 큰 것이 TRUE면 a,  FALSE면 b 
typedef struct node {
	int element;
	struct node* left;
	struct node* right;
}Node;

Node* makeNode(void)			//노드에 동적할당하는 함수 
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->element = 0;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

Node* setNode(Node* node, int element, Node* leftchild, Node* rightchild)		//노드의 element, leftchild, rightchild를 초기화하는 함수 
{
	node->element = element;
	node->left = leftchild;
	node->right = rightchild;
	return node;
}

Node* treeRR(Node* node)		//avlTree의 밸런스를 맞추기위해 RR로테이션을 해주는 함수 
{
	Node* child;				
	child = node->right;			//child를 node의 rightchild로 이동시킨다. 
	node->right = child->left;		//node의 rightchild가 child의 leftchild를 가리키게한다. 
	child->left = node;				//child의 leftchild가 node를 가리키게한다. 
	return child;					//밸런스를 맞추고 나면 child가 root가 되므로 child를 리턴한다. 
}
	
Node* treeLL(Node* node)		//avlTree의 밸런스를 맞추기위해 LL로테이션을 해주는 함수
{
	Node* child;
	child = node->left;				//child를 node의 leftchild로 이동시킨다. 
	node->left = child->right;		//node의 leftchild가 child의 rightchild를 가리키게 한다. 
	child->right = node;			//child의 rightchild가 node를 가리키게한다. 
	return child;					//밸런스를 맞추고 나면 child가 root가 되므로 child를 리턴한다. 
}

Node* treeRL(Node* node)		//avlTree의 밸런스를 맞추기위해 RL로테이션을 해주는 함수
{
	Node* child;				
	child = node->right;			//child를 node의 rightchild로 이동시킨다. 
	node->right = treeLL(child);	//node의 rightchild가 treeLL(child)의 결과값을 가리키게한다. 
	return treeRR(node);			//위의 줄이 실행되고 나면 RR로테이션을 하도록 트리가 형성되므로 RR로테이션을 리턴한다. 
}

Node* treeLR(Node* node)		//avlTree의 밸런스를 맞추기위해 LR로테이션을 해주는 함수
{
	Node* child;				
	child = node->left;				//child로 node의 leftchild로 이동시킨다. 
	node->left = treeRR(child);		//node의 leftchild가 treeRR(child)의 결과값을 가리키게한다. 
	return treeLL(node);			//위의 줄이 실행되고 나면 LL로테이션을 하도록 트리가 형성되므로 LL로테이션을 리턴한다. 
}

int getHeight(Node* node)		//트리의 height를 구하는 함수 
{
	int height = 0;
	if(node != NULL)
	{
		height = 1 + max(getHeight(node->left), getHeight(node->right));	//max는 위에 define해놓은 대로 getHeight(node->left)와 getHeight(node->right)의 값중 큰 값이 되므로 height는 왼쪽 서브트리나 오른쪽서브트리의 높이가 된다. 
	}

	return height;
}


int getBalance(Node* node) {		//트리의 밸런스가 깨지는 곳이 있는지 체크하는 함수 
	if(node == NULL)
	{
		return 0;
	}
	
	return getHeight(node->left)-getHeight(node->right);	//노드의 왼쪽와 오른쪽의 높이를 빼서 나오는 밸런스펙터의 값을 리턴한다.  
}

Node* treeBalance(Node* node) {					//트리의 밸런스를 맞추어 주는 함수 
	int height;
	
	height = getBalance(node);					//트리의 밸런스가 깨졌는지 확인하기 위해 height에 초기화 
	if(height>1)								//height가 1보다 크면 왼쪽의 높이가 오른쪽보다 컸기때문에 L?로테이션이 실행된다. 
	{
		if(getBalance(node->left)>0)			//getBalance(node->left)의 값이 0보다 클 경우 다시 왼쪽의 높이가 더 컸기 때문에 이 경우에는 LL로테이션이 실행된다. 
		{
			node = treeLL(node);				//node를 treeLL(node)의 결과값으로 이동시킨다. 
		}
		else									//getBalance(node->left)의 값이 0보다 작거나 같다면 왼쪽의 높이가 오른쪽보다 작거나 같았기 때문에 이 경우에는 LR로테이션이 실행된다. 
		{
			node = treeLR(node);				//node를 treeLR(node)의 결과값으로 이동시킨다.
		}
	}
	else if(height<-1)							//height가 -1보다 작으면 오른쪽의 높이가 왼쪽보다 컸기 때문에 R?로테이션이 실행된다. 
	{
		if(getBalance(node->right)<0)			//getBalance(node->right)의 값이 0보다 작으면 다시 오른쪽의 높이가 왼쪽보다 컸기 때문에 이 경우에는 RR로테이션이 실행된다. 
		{
			node = treeRR(node);				//node를 treeRR(node)의 결과값으로 이동시킨다.
		}
		else									//getBalance(node->right)의 값이 0보다 크거나 같다면 오른쪽의 높이가 왼쪽보다 작거나 같았기 때문에 이 경우에는 RL로테이션이 실행된다. 
		{
			node = treeRL(node);				//node를 treeRL(node)의 결과값으로 이동시킨다.
		}
	} 
	return node;								//밸런스가 깨졌던 곳이 있다면 그에 해당하는 node가 리턴되고 밸런스가 맞았으면 그대로 node가 리턴된다. 
}

void deleteNode(Node* node) {					//트리를 이루고 있는 노드를 free시켜주는 함수 
	if(node != NULL)
	{
		deleteNode(node->left);					//node의 leftchild를 free시킨다. 
		deleteNode(node->right);				//node의 rightchild를 free시킨다. 
		free(node);								//node를 free시킨다. 
	}
}

void preOrder(Node* node)						//트리를 preorder로 출력하는 함수 
{
	if(node != NULL)
	{
		printf("%d ",node->element);			//node가 가지고 있는 element의 값을 출력한다. 
		preOrder(node->left);					//node의 leftchild의 element값을 출력한다. 
		preOrder(node->right);					//node의 rightchild의 element값을 출력한다. 
	}
}

Node* insertNode(Node* node, int element)		//트리에 element를 입력하는 함수 
{
	if(node == NULL)							//node가 null일때 
	{
		node = makeNode();						//node를 동적할당해주고 
		return setNode(node,element,NULL,NULL);	//node의 element,leftchild,rightchild를 초기화시킨다. 
	}
	else if(element<node->element)				//element의 값이 기존 node의 element의 값보다 작을 경우 
	{
		node->left = insertNode(node->left, element);	//node의 leftchild에 element를 가지는 노드를 추가한다.  
		node = treeBalance(node);						//새 노드를 추가한 후 밸런스를 다시 맞춘다. 
	}
	else if(element>node->element) {			//element의 값이 기존 node의 element의 값보다 클 경우 
		node->right = insertNode(node->right, element);	//node의 rightchild에 element를 가지는 노드를 추가한다. 
		node = treeBalance(node);						//새 노드를 추가한 후 밸런스를 다시 맞춘다. 
	}
	return node;								//밸런스를 맞춘 트리의 node를 리턴한다. 
}

Node* leftmost(Node* node) {					//가장 왼쪽에 있는 노드를 찾는 함수 
	Node* cur = node;							//cur을 node로 옮긴다. 
	while(cur->left != NULL){					//cur의 leftchild가 NULL이 아니면 
		cur = cur->left;						//cur을 cur의 leftchild로 옮긴다. 
	}
	return cur;									//가장 왼쪽에 있는 노드가 리턴된다. 
}

Node* removeNode(Node*node, int element) {		//element와 같은 노드를 삭제하는 함수 
	if(node == NULL)						
		return node;							//node가 NULL이면 node를 리턴 
	if(node->element < element) 				//node의 element가 element보다 작으면 
	{
		node->right = removeNode(node->right,element);		//node의 rightchild가 removeNode(node->right,element)의 값을 가리키게한다. 
	}
	else if(node->element > element)			//node의 element가 element보다 크면 
	{		
		node->left = removeNode(node->left,element);		//node의 leftchild가 removeNode(node->left,element)의 값을 가리키게 한다. 
	}
	else {										//node의 element가 element와 같으면 
		Node* nodeL = node->left;				//nodeL을 node의 leftchild로 옮긴다. 
		Node* nodeR = node->right;				//nodeR을 node의 rightchild로 옮긴다. 
		if(nodeL == NULL || nodeR == NULL)		//nodeL이나 nodeR이 NULL이라면 
		{
			node = nodeL == NULL ? nodeR : nodeL;	//nodeL이 널일 경우 node를 nodeR로 옮기고, nodeL이 널이 아닐 경우 node를 nodeL로 옮긴다. 
		}
		else {
			Node* mostnextNode = leftmost(nodeR);	//mostnextNode가 leftmost(nodeR)의 값을 가리키게한다. 
			node->element = mostnextNode->element;	//node의 element를 mostnextNode의 element값으로 바꾼다. 
			node->right = removeNode(nodeR, mostnextNode->element);		//node의 rightchild가 removeNode(nodeR, mostnextNode->element)의 값을 가리키게한다. 
			free(mostnextNode);			//삭제할 노드인 mostnextNode를 free시킨다. 
		}
	}
	if(node == NULL)					//삭제 후 node가 NULL이라면  
		return node;					//node를 리턴한다. 
}

int main()
{
	Node* root = NULL;
	int i=0, element;
	printf("Insert node to AVL tree : \n");
	while(i<9)
	{
		scanf("%d", &element);
		root = insertNode(root, element);
		i++;
	}
	printf("\n");
	printf("Preorder traversal of the constructed AVL tree is\n");
	preOrder(root);
	printf("\n");
	printf("Preorder traversal after deletion of ");
	scanf("%d",&element);
	removeNode(root,element);	
	preOrder(treeBalance(root));	//삭제 후 밸런스를 맞춘 트리의 preOrder의 결과를 출력한다. 
	deleteNode(root);
	
	return 0;
}
