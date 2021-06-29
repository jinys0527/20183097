#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int element;              //Node ����ü ���� 
	struct Node *next;
}Node;

int main()
{
	Node * head = NULL;	  //head ������ ���� 
	Node * tail = NULL;   //tail ������ ����
	Node * cur = NULL;    //���� ��ġ�� ����ų cur ������ ����  
	Node * del = NULL;    //Deletion�� ����ɶ� ������ ��带 ����ų del������ ���� 
	int option;       //����ڰ� � ������ ���� �Է¹ޱ� ���� ���� ���� 
	int element;     //Node->element�� ���� ���� �����ϱ� ���� ���� ���� 
	int insertcount=0;  //Insertion���� �߰��� ����� ���� ����ϱ� ���� ���� ���� 
	do
	{
		printf("1. Insertion\n");
		printf("2. Deletion\n");
		printf("3. Display\n");
		printf("0. Exit\n\n");
		printf("Select Option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				if(insertcount>=3)
					printf("Queue is Full\n");
				else
				{
					printf("Element : ");
					Node * newNode = (Node*)malloc(sizeof(Node));   //newNode�� �޸��Ҵ� 
					scanf("%d",&element);
					newNode->element = element;  //newNode->element�� element �ʱ�ȭ 
					newNode->next = NULL;  //newNode�� NULL�����͸� ����Ű���Ѵ�. 
				
					if(head == NULL)
					{
						head = newNode;  //head�� �������͸� ����ų ���  head�� newNode�� �ű��. 
					}
					else
						tail->next = newNode; //tail�� newNode�� ����Ű���Ѵ�. 
					tail = newNode; //tail�� newNode�� �ű��. 
					printf("Successfully Insert\n");
					insertcount++;  //Insertion�� �Ͼ �� insertcount 1����  
				}
				break;
			case 2:
				if(head == NULL)
				{
					printf("Queue is Empty\n");
					break;
				}
				else
				{
					printf("Deleted item : %d\n",head->element); //ť�� ���� �� ���� ���� �����ǹǷ� head�� �ִ� ���� ��� 
					del = head; //del�� head�� �ű��. 
					head = head->next; //head�� ���� ���� �ű��. 
					cur = head; //cur�� head�� �ű��. 
					free(del);  //�������� ��带 ����Ű�� �ִ� del�� free��Ŵ���ν� ���� 
					printf("\n");
					insertcount--;  //��带 �ϳ� ���������Ƿ� insertcount 1����  
					break;
				}
			case 3:
				if(head == NULL)
				{
					printf("Queue is Empty\n");
					break;
				}
				else
				{
					printf("Items : ");
					cur=head;  //cur�� head�� �ű��. 
					printf("%d ",cur->element);
					while(cur->next != NULL)
					{
						cur = cur->next;
						printf("%d ",cur->element);     //cur�� �̾��� ��带 ���� �̵��ϸ鼭 ������ element�� ����Ѵ�
					}
					printf("\n");
					break;
				}
			case 0:
				printf("Exit\n");
				break;
			default :
				printf("1,2,3,0 �� �ϳ��� �Է����ּ���.\n");	
		}
	}while(option!=0);
	
	if(head == NULL)
	{
		return 0;
	}
	
	else
	{
		Node * delNode = head;			//Node�� free��Ű�� ���� ��带 ����ų ������ ����
		Node * delNextNode = head->next;  //Node�� free��Ű�� ���� ��带 ����ų ������ ���� 
		
		free(delNode);
		
		while(delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;		//delNode�� delNextNode�� �̵���Ű�鼭 delNode�� free��Ų��. 
			free(delNode);
		}
	}
	
	
	return 0; 
}
