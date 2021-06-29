#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

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
	Node * newNode = NULL;  //���ο� ��� ������ ���� ������ ���� 
	Node * beforeNode = NULL;  //���� ��� ���� ��带 ����ų ������ ���� 
	Node * deleteNode = NULL;  //���� ��� ������ ���� ������ ����  
	int element;     //Node->element�� ���� ���� �����ϱ� ���� ���� ���� 
	int position;   //������ ��ġ�� �Է¹ޱ� ���� ���� ���� 
	int i;
	int count=0;    //���� Ƚ���� ����ϱ� ���� ���� ���� 
	char input[10];  //��� �� �������� ���� ���� Ȯ���� ���� ���ڿ� ����  
	printf("Enter 5 elements in list : ");
	for(i=0;i<5;i++)
	{
		scanf("%d",&element);   
		newNode = (Node*)malloc(sizeof(Node)); //newNode�� �޸��Ҵ� 
		newNode->element = element;  //newNode->element�� element �ʱ�ȭ 
		newNode->next = NULL;  //newNode�� NULL�����͸� ����Ű���Ѵ�. 
		if(head == NULL)
		{
			head = newNode;  //head�� �������͸� ����ų ���  head�� newNode�� �ű��. 
		}
		else
			tail->next = newNode; //tail�� newNode�� ����Ű���Ѵ�. 
		tail = newNode; //tail�� newNode�� �ű��. 
	}
	printf("\n");
	
	printf("Stored element in list : ");
	cur = head;  //cur�� head�� �ű��. 
	printf("%d ",cur->element);
	while(cur->next != NULL)
	{
		cur = cur->next;
		printf("%d ",cur->element);  //cur�� �̾��� ��带 ���� �̵��ϸ鼭 ������ element�� ����Ѵ�. 
	}
	printf("\n");
	
	do
	{
		if(strcmp(input,"continue")==0)
		{
			printf("Enter poss. of element to delete : ");
			scanf("%d",&position);  //���� ����� ��ġ �Է�   
			
			while(1)
			{
				if(position>5-count||position<1)   //����� ���� ��ġ�� 5-����Ƚ������ ũ�ų� 1���� ���� ���� �־��� �� 
				{
					printf("1�̻� %d������ ���� �Է����ּ���.\n",5-count); //���� �� �ִ� ������ �˷��ִ� �޽��� 
					printf("Enter poss. of element to delete : ");
					scanf("%d",&position);
					continue; 
				}	
				else 
					break;
			}	
			count++; //���� ��ġ�� �־����� count�� 1����  
					
			cur = head;  //cur�� head�� �ű��. 
			for(i=1;i<position-1;i++)
			{
				cur=cur->next;  //���� ��ġ�� ��� ������ cur�� �̵���Ų��. 
			}
			beforeNode = cur;   //beforeNode�� ���� ��� ������ �ű��. 
			if(cur == head&&position==1)  //cur�� head�̸鼭 ���� ��ġ�� 1�ϰ�� 
			{
				deleteNode = head;      //head�� �������ߵǹǷ� deleteNode�� head�� �ű��. 
				head = head->next;     //head�� �������� �ű�� 
				beforeNode = head;     //beforeNode�� head�� �ű��. 
			}
			cur = cur->next;  //cur�� ���� ���� �ű��.  
			beforeNode->next = cur->next; //beforeNode->next�� ���� ��� ������ ����Ű���Ѵ�. 
			if(position==1)
				free(deleteNode);  //deleteNode�� free��Ų��.
			else if(deleteNode != NULL && position!=1) 
			{
				deleteNode = cur;  //deleteNode�� �����带 ����Ű���Ѵ�. 
				free(deleteNode); //deleteNode�� free��Ų��.
			}
			printf("Stored data in list : ");
			cur = head;  //cur�� head�� �ű��. 
			printf("%d ",cur->element);
			while(cur->next != NULL)
			{
				cur = cur->next;          //cur�� �̾��� ��带 ���� �̵��ϸ鼭 ������ element�� ����Ѵ�. 
				printf("%d ",cur->element);
			}
			printf("\n");
			printf("continue / exit : ");
			scanf("%s",&input);
			for(i=0;i<10;i++)
			{
				input[i] = tolower(input[i]); //input�� �ҹ��ڷ� ��ȯ�ϴ� �Լ�  
			}
			continue;
		}
		else if(strcmp(input,"exit")==0) // input�̸� exit�� �� 
		{ 			
			break; //�ݺ��� Ż�� 
		}
		else if((strcmp(input,"continue")!=0||strcmp(input,"exit")!=0)&&count!=0) //count==0�϶� input�� ������������ ��������ʵ��� ���ǿ� count!=0�� �߰� 
		{
			do
			{
				printf("continue �Ǵ� exit�� �Է����ּ���.\n"); //input�� continue�� exit��  �ƴѰ�� �ٽ� �Է��϶�� �޽��� 
				printf("continue / exit?");
				scanf("%s",&input);
				for(i=0;i<10;i++)
				{
					input[i] = tolower(input[i]);  //input�� �� ���� �ҹ��ڷ� ��ȯ���ִ� �Լ� 
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
		printf("Enter poss. of element to delete : ");
		scanf("%d",&position);  //���� ����� ��ġ �Է�
		while(1)
		{
			if(position>5-count||position<1)   //����� ���� ��ġ�� 5-����Ƚ������ ũ�ų� 1���� ���� ���� �־��� �� 
			{
				printf("1�̻� %d������ ���� �Է����ּ���.\n",5-count); //���� �� �ִ� ������ �˷��ִ� �޽��� 
				printf("Enter poss. of element to delete : ");
				scanf("%d",&position);
				continue; 
			}	
			else 
				break;
		}	
		count++; //���� ��ġ�� �־����� count�� 1����  
		cur = head;  //cur�� head�� �ű��. 
		for(i=1;i<position-1;i++)
		{
			cur=cur->next;  //���� ��ġ�� ��� ������ cur�� �̵���Ų��. 
		}
		beforeNode = cur;   //beforeNode�� ���� ��� ������ �ű��. 
		if(cur == head&&position==1)  //cur�� head�̸鼭 ���� ��ġ�� 1�ϰ�� 
		{
			deleteNode = head;      //head�� �������ߵǹǷ� deleteNode�� head�� �ű��. 
			head = head->next;     //head�� �������� �ű�� 
			beforeNode = head;     //beforeNode�� head�� �ű��. 
		}
		cur = cur->next;  //cur�� ���� ���� �ű��.
		beforeNode->next = cur->next; //beforeNode->next�� ���� ��� ������ ����Ű���Ѵ�.  
		if(position==1)
			free(deleteNode);   //deleteNode�� free��Ų��.
		else if(deleteNode != NULL && position!=1) 
		{
			deleteNode = cur;   //deleteNode�� �����带 ����Ű���Ѵ�. 
			free(deleteNode); //deleteNode�� free��Ų��.
		}
		printf("Stored data in list : ");
		cur = head;  //cur�� head�� �ű��. 
		printf("%d ",cur->element);
		while(cur->next != NULL)
		{
			cur = cur->next;          //cur�� �̾��� ��带 ���� �̵��ϸ鼭 ������ element�� ����Ѵ�. 
			printf("%d ",cur->element);
		}
		printf("\n");
		printf("continue / exit : ");
		scanf("%s",&input);
		for(i=0;i<10;i++)
		{
			input[i] = tolower(input[i]); //input�� �ҹ��ڷ� ��ȯ�ϴ� �Լ�  
		}
	}while(1);
	
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
