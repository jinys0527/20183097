#include <stdio.h>
#include <stdlib.h>
#define max(a,b)		(((a) > (b)) ? (a) : (b))			//a�� b�߿� ū ���� TRUE�� a,  FALSE�� b 
typedef struct node {
	int element;
	struct node* left;
	struct node* right;
}Node;

Node* makeNode(void)			//��忡 �����Ҵ��ϴ� �Լ� 
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->element = 0;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

Node* setNode(Node* node, int element, Node* leftchild, Node* rightchild)		//����� element, leftchild, rightchild�� �ʱ�ȭ�ϴ� �Լ� 
{
	node->element = element;
	node->left = leftchild;
	node->right = rightchild;
	return node;
}

Node* treeRR(Node* node)		//avlTree�� �뷱���� ���߱����� RR�����̼��� ���ִ� �Լ� 
{
	Node* child;				
	child = node->right;			//child�� node�� rightchild�� �̵���Ų��. 
	node->right = child->left;		//node�� rightchild�� child�� leftchild�� ����Ű���Ѵ�. 
	child->left = node;				//child�� leftchild�� node�� ����Ű���Ѵ�. 
	return child;					//�뷱���� ���߰� ���� child�� root�� �ǹǷ� child�� �����Ѵ�. 
}
	
Node* treeLL(Node* node)		//avlTree�� �뷱���� ���߱����� LL�����̼��� ���ִ� �Լ�
{
	Node* child;
	child = node->left;				//child�� node�� leftchild�� �̵���Ų��. 
	node->left = child->right;		//node�� leftchild�� child�� rightchild�� ����Ű�� �Ѵ�. 
	child->right = node;			//child�� rightchild�� node�� ����Ű���Ѵ�. 
	return child;					//�뷱���� ���߰� ���� child�� root�� �ǹǷ� child�� �����Ѵ�. 
}

Node* treeRL(Node* node)		//avlTree�� �뷱���� ���߱����� RL�����̼��� ���ִ� �Լ�
{
	Node* child;				
	child = node->right;			//child�� node�� rightchild�� �̵���Ų��. 
	node->right = treeLL(child);	//node�� rightchild�� treeLL(child)�� ������� ����Ű���Ѵ�. 
	return treeRR(node);			//���� ���� ����ǰ� ���� RR�����̼��� �ϵ��� Ʈ���� �����ǹǷ� RR�����̼��� �����Ѵ�. 
}

Node* treeLR(Node* node)		//avlTree�� �뷱���� ���߱����� LR�����̼��� ���ִ� �Լ�
{
	Node* child;				
	child = node->left;				//child�� node�� leftchild�� �̵���Ų��. 
	node->left = treeRR(child);		//node�� leftchild�� treeRR(child)�� ������� ����Ű���Ѵ�. 
	return treeLL(node);			//���� ���� ����ǰ� ���� LL�����̼��� �ϵ��� Ʈ���� �����ǹǷ� LL�����̼��� �����Ѵ�. 
}

int getHeight(Node* node)		//Ʈ���� height�� ���ϴ� �Լ� 
{
	int height = 0;
	if(node != NULL)
	{
		height = 1 + max(getHeight(node->left), getHeight(node->right));	//max�� ���� define�س��� ��� getHeight(node->left)�� getHeight(node->right)�� ���� ū ���� �ǹǷ� height�� ���� ����Ʈ���� �����ʼ���Ʈ���� ���̰� �ȴ�. 
	}

	return height;
}


int getBalance(Node* node) {		//Ʈ���� �뷱���� ������ ���� �ִ��� üũ�ϴ� �Լ� 
	if(node == NULL)
	{
		return 0;
	}
	
	return getHeight(node->left)-getHeight(node->right);	//����� ���ʿ� �������� ���̸� ���� ������ �뷱�������� ���� �����Ѵ�.  
}

Node* treeBalance(Node* node) {					//Ʈ���� �뷱���� ���߾� �ִ� �Լ� 
	int height;
	
	height = getBalance(node);					//Ʈ���� �뷱���� �������� Ȯ���ϱ� ���� height�� �ʱ�ȭ 
	if(height>1)								//height�� 1���� ũ�� ������ ���̰� �����ʺ��� �Ǳ⶧���� L?�����̼��� ����ȴ�. 
	{
		if(getBalance(node->left)>0)			//getBalance(node->left)�� ���� 0���� Ŭ ��� �ٽ� ������ ���̰� �� �Ǳ� ������ �� ��쿡�� LL�����̼��� ����ȴ�. 
		{
			node = treeLL(node);				//node�� treeLL(node)�� ��������� �̵���Ų��. 
		}
		else									//getBalance(node->left)�� ���� 0���� �۰ų� ���ٸ� ������ ���̰� �����ʺ��� �۰ų� ���ұ� ������ �� ��쿡�� LR�����̼��� ����ȴ�. 
		{
			node = treeLR(node);				//node�� treeLR(node)�� ��������� �̵���Ų��.
		}
	}
	else if(height<-1)							//height�� -1���� ������ �������� ���̰� ���ʺ��� �Ǳ� ������ R?�����̼��� ����ȴ�. 
	{
		if(getBalance(node->right)<0)			//getBalance(node->right)�� ���� 0���� ������ �ٽ� �������� ���̰� ���ʺ��� �Ǳ� ������ �� ��쿡�� RR�����̼��� ����ȴ�. 
		{
			node = treeRR(node);				//node�� treeRR(node)�� ��������� �̵���Ų��.
		}
		else									//getBalance(node->right)�� ���� 0���� ũ�ų� ���ٸ� �������� ���̰� ���ʺ��� �۰ų� ���ұ� ������ �� ��쿡�� RL�����̼��� ����ȴ�. 
		{
			node = treeRL(node);				//node�� treeRL(node)�� ��������� �̵���Ų��.
		}
	} 
	return node;								//�뷱���� ������ ���� �ִٸ� �׿� �ش��ϴ� node�� ���ϵǰ� �뷱���� �¾����� �״�� node�� ���ϵȴ�. 
}

void deleteNode(Node* node) {					//Ʈ���� �̷�� �ִ� ��带 free�����ִ� �Լ� 
	if(node != NULL)
	{
		deleteNode(node->left);					//node�� leftchild�� free��Ų��. 
		deleteNode(node->right);				//node�� rightchild�� free��Ų��. 
		free(node);								//node�� free��Ų��. 
	}
}

void preOrder(Node* node)						//Ʈ���� preorder�� ����ϴ� �Լ� 
{
	if(node != NULL)
	{
		printf("%d ",node->element);			//node�� ������ �ִ� element�� ���� ����Ѵ�. 
		preOrder(node->left);					//node�� leftchild�� element���� ����Ѵ�. 
		preOrder(node->right);					//node�� rightchild�� element���� ����Ѵ�. 
	}
}

Node* insertNode(Node* node, int element)		//Ʈ���� element�� �Է��ϴ� �Լ� 
{
	if(node == NULL)							//node�� null�϶� 
	{
		node = makeNode();						//node�� �����Ҵ����ְ� 
		return setNode(node,element,NULL,NULL);	//node�� element,leftchild,rightchild�� �ʱ�ȭ��Ų��. 
	}
	else if(element<node->element)				//element�� ���� ���� node�� element�� ������ ���� ��� 
	{
		node->left = insertNode(node->left, element);	//node�� leftchild�� element�� ������ ��带 �߰��Ѵ�.  
		node = treeBalance(node);						//�� ��带 �߰��� �� �뷱���� �ٽ� �����. 
	}
	else if(element>node->element) {			//element�� ���� ���� node�� element�� ������ Ŭ ��� 
		node->right = insertNode(node->right, element);	//node�� rightchild�� element�� ������ ��带 �߰��Ѵ�. 
		node = treeBalance(node);						//�� ��带 �߰��� �� �뷱���� �ٽ� �����. 
	}
	return node;								//�뷱���� ���� Ʈ���� node�� �����Ѵ�. 
}

Node* leftmost(Node* node) {					//���� ���ʿ� �ִ� ��带 ã�� �Լ� 
	Node* cur = node;							//cur�� node�� �ű��. 
	while(cur->left != NULL){					//cur�� leftchild�� NULL�� �ƴϸ� 
		cur = cur->left;						//cur�� cur�� leftchild�� �ű��. 
	}
	return cur;									//���� ���ʿ� �ִ� ��尡 ���ϵȴ�. 
}

Node* removeNode(Node*node, int element) {		//element�� ���� ��带 �����ϴ� �Լ� 
	if(node == NULL)						
		return node;							//node�� NULL�̸� node�� ���� 
	if(node->element < element) 				//node�� element�� element���� ������ 
	{
		node->right = removeNode(node->right,element);		//node�� rightchild�� removeNode(node->right,element)�� ���� ����Ű���Ѵ�. 
	}
	else if(node->element > element)			//node�� element�� element���� ũ�� 
	{		
		node->left = removeNode(node->left,element);		//node�� leftchild�� removeNode(node->left,element)�� ���� ����Ű�� �Ѵ�. 
	}
	else {										//node�� element�� element�� ������ 
		Node* nodeL = node->left;				//nodeL�� node�� leftchild�� �ű��. 
		Node* nodeR = node->right;				//nodeR�� node�� rightchild�� �ű��. 
		if(nodeL == NULL || nodeR == NULL)		//nodeL�̳� nodeR�� NULL�̶�� 
		{
			node = nodeL == NULL ? nodeR : nodeL;	//nodeL�� ���� ��� node�� nodeR�� �ű��, nodeL�� ���� �ƴ� ��� node�� nodeL�� �ű��. 
		}
		else {
			Node* mostnextNode = leftmost(nodeR);	//mostnextNode�� leftmost(nodeR)�� ���� ����Ű���Ѵ�. 
			node->element = mostnextNode->element;	//node�� element�� mostnextNode�� element������ �ٲ۴�. 
			node->right = removeNode(nodeR, mostnextNode->element);		//node�� rightchild�� removeNode(nodeR, mostnextNode->element)�� ���� ����Ű���Ѵ�. 
			free(mostnextNode);			//������ ����� mostnextNode�� free��Ų��. 
		}
	}
	if(node == NULL)					//���� �� node�� NULL�̶��  
		return node;					//node�� �����Ѵ�. 
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
	preOrder(treeBalance(root));	//���� �� �뷱���� ���� Ʈ���� preOrder�� ����� ����Ѵ�. 
	deleteNode(root);
	
	return 0;
}
