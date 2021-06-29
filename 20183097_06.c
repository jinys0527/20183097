#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
	Node * popNode = NULL;  //pop이 일어나면서 나올 노드를 가리킬 popNode포인터 생성  
	int choice;      //사용자가 실행할 종류를 입력받기 위한 변수 선언 
	int pushcount=0;  //push가 일어난 횟수를 기록하기 위한 변수 선언 
	int element;     //Node->element에 넣을 값을 보관하기 위한 변수 선언 
	char select[100];   //push를 계속할 것인지에 대한 여부를 확인하기 위한 문자열 선언 
	int count=0;  //push를 추가로 실행한 횟수를 기록하기 위한 변수 선언 
	do
	{
		printf("1 : push\n");
		printf("2 : pop\n");
		printf("3 : display\n");
		printf("4 : exit\n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1:
				do
				{
					printf("Enter element in stack : ");
					Node * newNode = (Node*)malloc(sizeof(Node));         //newNode에 메모리할당 
					scanf("%d",&element);
					printf("\n");
					newNode->element = element;  //newNode->element에 element 초기화 
					newNode->next = NULL;  //newNode가 NULL포인터를 가리키게한다.
					if(tail == NULL)     //tail이 널일때  
					{
						tail = newNode;     //tail을 newNode로 옮긴다. 
						head = newNode;		//head를 newNode로 옮긴다. 
						head->next = tail;		//스택은 먼저들어간것이 끝으로 가기때문에 head가 tail을 가리키게한다. 
					}
					else
					{
						newNode->next = head;   //newNode->next가 head를 가리키게 한다. 
						head = newNode;        //head를 newNode로 옮긴다. 
					}	
					printf("Pushed an element (Y/N) : ");
					scanf("%s",&select[count]);
					select[count] = tolower(select[count]);    //select의 값을 소문자로 변환하는 함수  
					printf("\n");
					if(select[count]=='y')
					{
						pushcount++;
						continue;
					}
					else if(select[count]=='n')
						break;
					else if(select[count]!='y' || select[count]!='n')
					{
						do
						{
							printf("y / n을 입력해주세요.\n\n");      //select가 y나 n이  아닌경우 다시 입력하라는 메시지 출력
							printf("Pushed an element (Y/N) : ");    
							scanf("%s",&select[count]);
							getchar();
							select[count] = tolower(select[count]);
							printf("\n");
							if(select[count]=='y'||select[count]=='n')
								break;
							count++;
						}while(1);
						if(select[count]=='n')
							break;
					}
					pushcount++;
					count++;
				}while(1);
				break;
			case 2:
				printf("deleted data is : %d\n",head->element);   //스택은 마지막에 들어간 head의 값이 먼저 삭제되므로 head의 값 출력 
				printf("\n");
				pushcount--;   //삭제되면서 push가 일어난 횟수가 감소하므로 pushcount 1감소  
				popNode = head;  //popNode를 head로 옮긴다. 
				head = head->next;  //head를 head->next로 옮긴다. 
				free(popNode);  //삭제될 노드인 popNode를 free시킨다. 
				do
				{
					printf("Pushed an element (Y/N) : ");
					scanf("%s",&select[count]);
					printf("\n");
					select[count] = tolower(select[count]);
					if(select[count]=='y')
					{
						printf("Enter element in stack : ");
						Node * newNode = (Node*)malloc(sizeof(Node));         //newNode에 메모리할당 
						scanf("%d",&element);
						printf("\n");
						newNode->element = element;  //newNode->element에 element 초기화 
						newNode->next = NULL;  //newNode가 NULL포인터를 가리키게한다.
						if(tail == NULL)     //tail이 널일때  
						{
							tail = newNode;     //tail을 newNode로 옮긴다. 
							head = newNode;		//head를 newNode로 옮긴다. 
							head->next = tail;		//스택은 먼저들어간것이 끝으로 가기때문에 head가 tail을 가리키게한다. 
						}
						else
						{
							newNode->next = head;   //newNode->next가 head를 가리키게 한다. 
							head = newNode;        //head를 newNode로 옮긴다. 
						}	
						pushcount++;
						count++;
						break;
					}
					if(select[count]=='n')
						break;
					else if(select[count]!='y' || select[count]!='n')
					{
						do
						{
							printf("y / n을 입력해주세요.\n\n");     //select가 y나 n이  아닌경우 다시 입력하라는 메시지 출력  
							printf("Pushed an element (Y/N) : "); 
							scanf("%s",&select[count]);
							getchar();
							select[count] = tolower(select[count]);
							printf("\n");
							if(select[count]=='y'||select[count]=='n')
								break;
							count++;
						}while(1);
						if(select[count]=='n')
							break;
						else if(select[count]=='y')
						{
							printf("Enter element in stack : ");
							Node * newNode = (Node*)malloc(sizeof(Node));         //newNode에 메모리할당 
							scanf("%d",&element);
							printf("\n");
							newNode->element = element;  //newNode->element에 element 초기화 
							newNode->next = NULL;  //newNode가 NULL포인터를 가리키게한다.
							if(tail == NULL)     //tail이 널일때  
							{
								tail = newNode;     //tail을 newNode로 옮긴다. 
								head = newNode;		//head를 newNode로 옮긴다. 
								head->next = tail;		//스택은 먼저들어간것이 끝으로 가기때문에 head가 tail을 가리키게한다. 
							}
							else
							{
								newNode->next = head;   //newNode->next가 head를 가리키게 한다. 
								head = newNode;        //head를 newNode로 옮긴다. 
							}	
							pushcount++;
							count++;
							break;
						}
					}
				}while(1);
				break;
			case 3:
				cur=head;      //cur을 head로 옮긴다. 
				printf("%d\n",cur->element);
				while(cur != tail)
				{
					cur = cur->next;
					printf("%d\n",cur->element);    //cur를 옮기면서 element값을 출력한다. 
				}
				printf("\n");
				do
				{
					printf("Pushed an element (Y/N) : ");
					scanf("%s",&select[count]);
					printf("\n");
					select[count] = tolower(select[count]);
					if(select[count]=='y')
					{
						printf("Enter element in stack : ");
						Node * newNode = (Node*)malloc(sizeof(Node));         //newNode에 메모리할당 
						scanf("%d",&element);
						printf("\n");
						newNode->element = element;  //newNode->element에 element 초기화 
						newNode->next = NULL;  //newNode가 NULL포인터를 가리키게한다.
						if(tail == NULL)     //tail이 널일때  
						{
							tail = newNode;     //tail을 newNode로 옮긴다. 
							head = newNode;		//head를 newNode로 옮긴다. 
							head->next = tail;		//스택은 먼저들어간것이 끝으로 가기때문에 head가 tail을 가리키게한다. 
						}
						else
						{
							newNode->next = head;   //newNode->next가 head를 가리키게 한다. 
							head = newNode;        //head를 newNode로 옮긴다. 
						}	
						pushcount++;
						count++;
					}
					if(select[count]=='n')
						break;
					else if(select[count]!='y' || select[count]!='n')
					{
						do
						{
							printf("y / n을 입력해주세요.\n\n");       //select가 y나 n이  아닌경우 다시 입력하라는 메시지 출력  
							printf("Pushed an element (Y/N) : ");    
							scanf("%s",&select[count]);
							getchar();
							select[count] = tolower(select[count]);
							printf("\n");
							if(select[count]=='y'||select[count]=='n')   
								break;
							count++;
						}while(1);
						if(select[count]=='n')
							break;
						else if(select[count]=='y')
						{
							printf("Enter element in stack : ");
							Node * newNode = (Node*)malloc(sizeof(Node));         //newNode에 메모리할당 
							scanf("%d",&element);
							printf("\n");
							newNode->element = element;  //newNode->element에 element 초기화 
							newNode->next = NULL;  //newNode가 NULL포인터를 가리키게한다.
							if(tail == NULL)     //tail이 널일때  
							{
								tail = newNode;     //tail을 newNode로 옮긴다. 
								head = newNode;		//head를 newNode로 옮긴다. 
								head->next = tail;		//스택은 먼저들어간것이 끝으로 가기때문에 head가 tail을 가리키게한다. 
							}
							else
							{
								newNode->next = head;   //newNode->next가 head를 가리키게 한다. 
								head = newNode;        //head를 newNode로 옮긴다. 
							}
							pushcount++;
							count++;
							break;
						}	
					}	
				}while(1);
				break;
			case 4:
				printf("Exit");
				break;
			default :
				printf("1,2,3,4 중 하나를 입력해주세요.");	
		}
		if(choice == 4)
			break;
	}while(pushcount<=50);
	
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
