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
	Node * popNode = NULL;  //pop�� �Ͼ�鼭 ���� ��带 ����ų popNode������ ����  
	int choice;      //����ڰ� ������ ������ �Է¹ޱ� ���� ���� ���� 
	int pushcount=0;  //push�� �Ͼ Ƚ���� ����ϱ� ���� ���� ���� 
	int element;     //Node->element�� ���� ���� �����ϱ� ���� ���� ���� 
	char select[100];   //push�� ����� �������� ���� ���θ� Ȯ���ϱ� ���� ���ڿ� ���� 
	int count=0;  //push�� �߰��� ������ Ƚ���� ����ϱ� ���� ���� ���� 
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
					Node * newNode = (Node*)malloc(sizeof(Node));         //newNode�� �޸��Ҵ� 
					scanf("%d",&element);
					printf("\n");
					newNode->element = element;  //newNode->element�� element �ʱ�ȭ 
					newNode->next = NULL;  //newNode�� NULL�����͸� ����Ű���Ѵ�.
					if(tail == NULL)     //tail�� ���϶�  
					{
						tail = newNode;     //tail�� newNode�� �ű��. 
						head = newNode;		//head�� newNode�� �ű��. 
						head->next = tail;		//������ ���������� ������ ���⶧���� head�� tail�� ����Ű���Ѵ�. 
					}
					else
					{
						newNode->next = head;   //newNode->next�� head�� ����Ű�� �Ѵ�. 
						head = newNode;        //head�� newNode�� �ű��. 
					}	
					printf("Pushed an element (Y/N) : ");
					scanf("%s",&select[count]);
					select[count] = tolower(select[count]);    //select�� ���� �ҹ��ڷ� ��ȯ�ϴ� �Լ�  
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
							printf("y / n�� �Է����ּ���.\n\n");      //select�� y�� n��  �ƴѰ�� �ٽ� �Է��϶�� �޽��� ���
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
				printf("deleted data is : %d\n",head->element);   //������ �������� �� head�� ���� ���� �����ǹǷ� head�� �� ��� 
				printf("\n");
				pushcount--;   //�����Ǹ鼭 push�� �Ͼ Ƚ���� �����ϹǷ� pushcount 1����  
				popNode = head;  //popNode�� head�� �ű��. 
				head = head->next;  //head�� head->next�� �ű��. 
				free(popNode);  //������ ����� popNode�� free��Ų��. 
				do
				{
					printf("Pushed an element (Y/N) : ");
					scanf("%s",&select[count]);
					printf("\n");
					select[count] = tolower(select[count]);
					if(select[count]=='y')
					{
						printf("Enter element in stack : ");
						Node * newNode = (Node*)malloc(sizeof(Node));         //newNode�� �޸��Ҵ� 
						scanf("%d",&element);
						printf("\n");
						newNode->element = element;  //newNode->element�� element �ʱ�ȭ 
						newNode->next = NULL;  //newNode�� NULL�����͸� ����Ű���Ѵ�.
						if(tail == NULL)     //tail�� ���϶�  
						{
							tail = newNode;     //tail�� newNode�� �ű��. 
							head = newNode;		//head�� newNode�� �ű��. 
							head->next = tail;		//������ ���������� ������ ���⶧���� head�� tail�� ����Ű���Ѵ�. 
						}
						else
						{
							newNode->next = head;   //newNode->next�� head�� ����Ű�� �Ѵ�. 
							head = newNode;        //head�� newNode�� �ű��. 
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
							printf("y / n�� �Է����ּ���.\n\n");     //select�� y�� n��  �ƴѰ�� �ٽ� �Է��϶�� �޽��� ���  
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
							Node * newNode = (Node*)malloc(sizeof(Node));         //newNode�� �޸��Ҵ� 
							scanf("%d",&element);
							printf("\n");
							newNode->element = element;  //newNode->element�� element �ʱ�ȭ 
							newNode->next = NULL;  //newNode�� NULL�����͸� ����Ű���Ѵ�.
							if(tail == NULL)     //tail�� ���϶�  
							{
								tail = newNode;     //tail�� newNode�� �ű��. 
								head = newNode;		//head�� newNode�� �ű��. 
								head->next = tail;		//������ ���������� ������ ���⶧���� head�� tail�� ����Ű���Ѵ�. 
							}
							else
							{
								newNode->next = head;   //newNode->next�� head�� ����Ű�� �Ѵ�. 
								head = newNode;        //head�� newNode�� �ű��. 
							}	
							pushcount++;
							count++;
							break;
						}
					}
				}while(1);
				break;
			case 3:
				cur=head;      //cur�� head�� �ű��. 
				printf("%d\n",cur->element);
				while(cur != tail)
				{
					cur = cur->next;
					printf("%d\n",cur->element);    //cur�� �ű�鼭 element���� ����Ѵ�. 
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
						Node * newNode = (Node*)malloc(sizeof(Node));         //newNode�� �޸��Ҵ� 
						scanf("%d",&element);
						printf("\n");
						newNode->element = element;  //newNode->element�� element �ʱ�ȭ 
						newNode->next = NULL;  //newNode�� NULL�����͸� ����Ű���Ѵ�.
						if(tail == NULL)     //tail�� ���϶�  
						{
							tail = newNode;     //tail�� newNode�� �ű��. 
							head = newNode;		//head�� newNode�� �ű��. 
							head->next = tail;		//������ ���������� ������ ���⶧���� head�� tail�� ����Ű���Ѵ�. 
						}
						else
						{
							newNode->next = head;   //newNode->next�� head�� ����Ű�� �Ѵ�. 
							head = newNode;        //head�� newNode�� �ű��. 
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
							printf("y / n�� �Է����ּ���.\n\n");       //select�� y�� n��  �ƴѰ�� �ٽ� �Է��϶�� �޽��� ���  
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
							Node * newNode = (Node*)malloc(sizeof(Node));         //newNode�� �޸��Ҵ� 
							scanf("%d",&element);
							printf("\n");
							newNode->element = element;  //newNode->element�� element �ʱ�ȭ 
							newNode->next = NULL;  //newNode�� NULL�����͸� ����Ű���Ѵ�.
							if(tail == NULL)     //tail�� ���϶�  
							{
								tail = newNode;     //tail�� newNode�� �ű��. 
								head = newNode;		//head�� newNode�� �ű��. 
								head->next = tail;		//������ ���������� ������ ���⶧���� head�� tail�� ����Ű���Ѵ�. 
							}
							else
							{
								newNode->next = head;   //newNode->next�� head�� ����Ű�� �Ѵ�. 
								head = newNode;        //head�� newNode�� �ű��. 
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
				printf("1,2,3,4 �� �ϳ��� �Է����ּ���.");	
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
