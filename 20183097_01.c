#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main()
{
	int array[50];   //�ִ� ���̰� 50�� �迭 ���� 
	int i,temp1,temp2;
	int position;    //���ϴ� ��ġ�� �ޱ� ���� ���� ���� 
	int newelement;  //���� ������ element 
	char input[10];  //������� Ȯ���ϱ� ���� ���ڿ� ���� 
	int count = 0; //���ο� element�� � �߰��Ǿ����� Ȯ���ϱ� ���� ���� ���� 
	printf("Enter 5 elements in array : ");
	
	for(i=0;i<5;i++)
	{
		scanf("%d",&array[i]);    //�迭�� 5�� ����  �ʱ�ȭ 
	}
	printf("Stored element in array : ");
	
	for(i=0;i<5;i++)
	{
		printf("%d ",array[i]);  //�迭�� ����� 5�� ���� ��� 
	}
	printf("\n");
	
	
	do
	{
		if(strcmp(input,"continue")==0)
		{
			printf("Enter position for enter element : ");
			scanf("%d",&position);  //���ο� element�� ���� ��ġ �Է� 
			while(1)
			{
				if(position>50) // �迭�� �ִ���̰� 50�̹Ƿ� position�� 50���� �۾ƾ��Ѵ�. 
				{
					printf("50������ ���� �Է����ּ���. ");
					scanf("%d",&position);
					continue;
				}
				else 
					break;
			}
			printf("Enter new element : ");
			scanf("%d",&newelement);
			count++;   //���ο� element�� �߰� �Ǿ����� count�� 1�� ���� 
			printf("Stored data in array : ");
			for(i=0;i<5+count;i++)
			{
				if(i==position-1) 
				{
					temp1 = array[i]; //���ϴ� ��ġ �� ->  temp1
					array[i]=newelement; //���ϴ� ��ġ <- ���ο� �� 
				}
				else if(i>position-1) 
				{
					temp2 = array[i];  //���ϴ� ��ġ ������ �� -> temp2 
					array[i]=temp1; //���� �� ��ü 
					temp1 = temp2; //�ٽ� ������ -> temp1 
				}
				printf("%d ",array[i]);
			}
			printf("\n");
			printf("continue / exit?");  // �� ������ ������ ����Ȯ��
			scanf("%s",&input);
			for(i=0;i<10;i++)
			{
				input[i] = tolower(input[i]);   //input�� �� ���� �ҹ��ڷ� ��ȯ���ִ� �Լ� 
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
		printf("Enter position for enter element : ");
		scanf("%d",&position);  //���ο� element�� ���� ��ġ �Է� 
		while(1)
		{
			if(position>50) // �迭�� �ִ���̰� 50�̹Ƿ� position�� 50���� �۾ƾ��Ѵ�. 
			{
				printf("50������ ���� �Է����ּ���. ");
				scanf("%d",&position);			
				continue;
			}
			else
				break;
		}
		printf("Enter new element : ");
		scanf("%d",&newelement);
		count++;   //���ο� element�� �߰� �Ǿ����� count�� 1�� ���� 
		printf("Stored data in array : ");
		for(i=0;i<5+count;i++)
		{
			if(i==position-1) 
			{
				temp1 = array[i]; //���ϴ� ��ġ �� ->  temp1
				array[i]=newelement; //���ϴ� ��ġ <- ���ο� �� 
			}
			else if(i>position-1) 
			{
				temp2 = array[i];  //���ϴ� ��ġ ������ �� -> temp2 
				array[i]=temp1; //���� �� ��ü 
				temp1 = temp2; //�ٽ� ������ -> temp1 
			}
			printf("%d ",array[i]);
		}
		printf("\n");
		printf("continue / exit?");  // �� ������ ������ ����Ȯ��
		scanf("%s",&input);
		for(i=0;i<10;i++)
		{
			input[i] = tolower(input[i]);   //input�� �� ���� �ҹ��ڷ� ��ȯ���ִ� �Լ� 
		}
	}while(count<=45);  //ó���� 5���� �־����Ƿ� �ִ� �����ִ°��� 45���̹Ƿ� count�� 45�����϶��� ���� 
	
	
	
	return 0; 
}
