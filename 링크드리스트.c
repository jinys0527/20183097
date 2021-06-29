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
	Node * newNode = NULL;  //새로운 노드 생성을 위한 포인터 생성 
	int element;     //Node->element에 넣을 값을 보관하기 위한 변수 선언 
	int position;   //삽입할 위치를 입력받기 위한 변수 선언 
	int i;
	int count=0;   //삽입한 횟수를 기록하기 위한 변수 선언 
	char input[10];  //계속 할 것인지에 대한 여부 확인을 위한 문자열 선언  
	printf("Enter 5 elements in list : ");
	for(i=0;i<5;i++)
	{
		scanf("%d",&element);   
		newNode = (Node*)malloc(sizeof(Node)); //newNode에 메모리할당 
		newNode->element = element;  //newNode->element에 element 초기화 
		newNode->next = NULL;  //newNode가 NULL포인터를 가리키게한다. 
		if(head == NULL)
		{
			head = newNode;  //head가 널포인터를 가르킬 경우  head를 newNode로 옮긴다. 
		}
		else
			tail->next = newNode; //tail이 newNode를 가리키게한다. 
		tail = newNode; //tail을 newNode로 옮긴다. 
	}
	printf("\n");
	
	printf("Stored element in list : ");
	cur = head;  //cur를 head로 옮긴다. 
	printf("%d ",cur->element);
	while(cur->next != NULL)
	{
		cur = cur->next;
		printf("%d ",cur->element);  //cur가 이어진 노드를 따라서 이동하면서 노드안의 element를 출력한다. 
	}
	printf("\n");
	
	do
	{
		if(strcmp(input,"continue")==0)
		{
			printf("Enter position for enter element : ");
			scanf("%d",&position); //새로운 element를 넣은 위치 입력 
			count++;  //현재 있는 갯수 다음에 추가할 수 있도록 count를 1증가 
			while(1)
			{	
				if(position>5+count||position<1) //넣을 위치가 1보다 작거나 현재 있는것보다 클경우 
				{
					printf("1이상%d이하의 수를 입력해주세요.\n",5+count); //넣을 수 있는 범위를 알려주는 메시지 
					printf("Enter position for enter element : ");
					scanf("%d",&position);
					continue; 
				}			
				else 
					break;
			}
		
			Node * insertNode = (Node*)malloc(sizeof(Node)); //새로 넣을 insertNode에 메모리 할당 
			printf("Enter new element : ");
			scanf("%d",&element);
			insertNode->element = element;  //insertNode->element에 element를 초기화 
			cur = head;  //cur를 head로 옮긴다. 
			
			for(i=1;i<position-1;i++)
			{
				cur=cur->next;			//원하는 위치 전까지의 노드를 연결한 후 
			}
			insertNode->next = cur->next; //원하는 위치에 노드에  insertNode->next를 연결한다. 
		
			if(cur == head&&position==1)  //cur이 head거나 원하는 위치가 1일 경우 
			{
				insertNode->next = head; //insertNode->next를 head에 연결시키고 
				head = insertNode;  //head를 insertNode로 옮긴다. 
			}
			else if(cur == head)   //cur이 head일경우 
			{
				cur->next = insertNode;   //cur->next를 insertNode에 연결한후 
				cur=cur->next;            //cur를 다음노드로 옮긴다. 
				insertNode->next = cur->next;	//insertNode->next를 다음노드에 연결시킨다. 
			}
			else if(cur!=head)  //cur이 head가 아닐 경우 
				cur->next = insertNode;   //cur->next를 insertNode에 연결한다. 
				
			printf("Stored data in list : ");
			cur = head;  //cur를 head로 옮긴다. 
			printf("%d ",cur->element);
			while(cur->next != NULL)
			{
				cur = cur->next;          //cur가 이어진 노드를 따라서 이동하면서 노드안의 element를 출력한다. 
				printf("%d ",cur->element);
			}
			
			printf("\n");
			printf("continue / exit : ");
			scanf("%s",&input);
			for(i=0;i<10;i++)
			{
				input[i] = tolower(input[i]); //input을 소문자로 변환하는 함수  
			}
			continue;
		}
		else if(strcmp(input,"exit")==0) // input이면 exit일 때 
		{ 			
			break; //반복문 탈출 
		}
		else if((strcmp(input,"continue")!=0||strcmp(input,"exit")!=0)&&count!=0) //count==0일때 input에 가비지때문에 실행되지않도록 조건에 count!=0를 추가 
		{
			do
			{
				printf("continue 또는 exit을 입력해주세요.\n"); //input이 continue나 exit이  아닌경우 다시 입력하라는 메시지 
				printf("continue / exit?");
				scanf("%s",&input);
				for(i=0;i<10;i++)
				{
					input[i] = tolower(input[i]);  //input에 들어간 값을 소문자로 변환해주는 함수 
				}
				if(strcmp(input,"continue")==0||strcmp(input,"exit")==0)
				{
					break;
				}
			}while(1);
			if(strcmp(input,"exit")==0)
			{
				break;
			}
		}
		printf("Enter position for enter element : ");
		scanf("%d",&position); //새로운 element를 넣은 위치 입력 
		count++;  //현재 있는 갯수 다음에 추가할 수 있도록 count를 1증가 
		while(1)
		{
			if(position>5+count||position<1) //넣을 위치가 1보다 작거나 현재 있는것보다 클경우 
			{
				printf("1이상%d이하의 수를 입력해주세요.\n",5+count); //넣을 수 있는 범위를 알려주는 메시지 
				printf("Enter position for enter element : ");
				scanf("%d",&position);
				continue; 
			}			
			else 
				break;
		}
		
		Node * insertNode = (Node*)malloc(sizeof(Node)); //새로 넣을 insertNode에 메모리 할당 
		printf("Enter new element : ");
		scanf("%d",&element);
		insertNode->element = element;  //insertNode->element에 element를 초기화 
		cur = head;  //cur를 head로 옮긴다. 
		
		for(i=1;i<position-1;i++)
		{
			cur=cur->next;			//원하는 위치 전까지의 노드를 연결한 후 
		}
		insertNode->next = cur->next; //원하는 위치에 노드에  insertNode->next를 연결한다. 
		
		if(cur == head&&position==1)  //cur이 head거나 원하는 위치가 1일 경우 
		{
			insertNode->next = head; //insertNode->next를 head에 연결시키고 
			head = insertNode;  //head를 insertNode로 옮긴다. 
		}
		else if(cur == head)   //cur이 head일경우 
		{
			cur->next = insertNode;   //cur->next를 insertNode에 연결한후 
			cur=cur->next;            //cur를 다음노드로 옮긴다. 
			insertNode->next = cur->next;	//insertNode->next를 다음노드에 연결시킨다. 
		}
		else if(cur!=head)  //cur이 head가 아닐 경우 
			cur->next = insertNode;   //cur->next를 insertNode에 연결한다. 
			
		printf("Stored data in list : ");
		cur = head;  //cur를 head로 옮긴다. 
		printf("%d ",cur->element);
		while(cur->next != NULL)
		{
			cur = cur->next;          //cur가 이어진 노드를 따라서 이동하면서 노드안의 element를 출력한다. 
			printf("%d ",cur->element);
		}
		
		printf("\n");
		printf("continue / exit : ");
		scanf("%s",&input);
		for(i=0;i<10;i++)
		{
			input[i] = tolower(input[i]); //input을 소문자로 변환하는 함수  
		}
		
	}while(1);
	
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
