#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int element;              //Node 구조체 생성 
	struct Node *next;
}Node;

int main()
{
	Node * head = NULL;	  //head 포인터 생성 
	Node * tail = NULL;   //tail 포인터 생성
	Node * cur = NULL;    //현재 위치를 가리킬 cur 포인터 생성  
	Node * del = NULL;    //Deletion이 실행될때 삭제될 노드를 가리킬 del포인터 생성 
	int option;       //사용자가 어떤 실행을 할지 입력받기 위한 변수 선언 
	int element;     //Node->element에 넣을 값을 보관하기 위한 변수 선언 
	int insertcount=0;  //Insertion으로 추가된 노드의 수를 기록하기 위한 변수 선언 
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
					Node * newNode = (Node*)malloc(sizeof(Node));   //newNode에 메모리할당 
					scanf("%d",&element);
					newNode->element = element;  //newNode->element에 element 초기화 
					newNode->next = NULL;  //newNode가 NULL포인터를 가리키게한다. 
				
					if(head == NULL)
					{
						head = newNode;  //head가 널포인터를 가르킬 경우  head를 newNode로 옮긴다. 
					}
					else
						tail->next = newNode; //tail이 newNode를 가리키게한다. 
					tail = newNode; //tail을 newNode로 옮긴다. 
					printf("Successfully Insert\n");
					insertcount++;  //Insertion이 일어난 후 insertcount 1증가  
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
					printf("Deleted item : %d\n",head->element); //큐는 먼저 들어간 것이 먼저 삭제되므로 head에 있는 원소 출력 
					del = head; //del을 head로 옮긴다. 
					head = head->next; //head를 다음 노드로 옮긴다. 
					cur = head; //cur를 head로 옮긴다. 
					free(del);  //지워야할 노드를 가리키고 있는 del을 free시킴으로써 삭제 
					printf("\n");
					insertcount--;  //노드를 하나 삭제했으므로 insertcount 1감소  
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
					cur=head;  //cur를 head로 옮긴다. 
					printf("%d ",cur->element);
					while(cur->next != NULL)
					{
						cur = cur->next;
						printf("%d ",cur->element);     //cur가 이어진 노드를 따라서 이동하면서 노드안의 element를 출력한다
					}
					printf("\n");
					break;
				}
			case 0:
				printf("Exit\n");
				break;
			default :
				printf("1,2,3,0 중 하나를 입력해주세요.\n");	
		}
	}while(option!=0);
	
	if(head == NULL)
	{
		return 0;
	}
	
	else
	{
		Node * delNode = head;			//Node들 free시키기 위한 노드를 가리킬 포인터 생성
		Node * delNextNode = head->next;  //Node들 free시키기 위한 노드를 가리킬 포인터 생성 
		
		free(delNode);
		
		while(delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;		//delNode와 delNextNode를 이동시키면서 delNode를 free시킨다. 
			free(delNode);
		}
	}
	
	
	return 0; 
}
