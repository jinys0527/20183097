#include <stdio.h>
#include <string.h>

int main()
{
	int array[50]; //�ִ� ���̰� 50�� �迭 ���� 
	int i;
	int position;  //���ϴ� ��ġ�� �ޱ� ���� ���� ���� 
	char input[10];  //������� Ȯ���ϱ� ���� ���ڿ� ���� 
	int count=0;   //����� ���� ��ġ�� element�� � ���������� Ȯ���ϱ� ���� ���� ����
	printf("Enter element in array : ");
	
	for(i=0;i<5;i++)
	{
		scanf("%d",&array[i]); //�迭�� 5�� ����  �ʱ�ȭ 
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
			printf("Enter poss. of element to delete : "); 
			scanf("%d",&position);  //����� ���� ��ġ �Է� 
			while(1)
			{
				if(position>5-count||position<=0)   //����� ���� ��ġ�� 5-����Ƚ������ ũ�ų� 0���� ���� ���� �־��� �� 
				{
					printf("1�̻� %d������ ���� �Է����ּ���.\n",5-count); //���� �� �ִ� ������ �˷��ִ� �޽��� 
					printf("Enter poss. of element to delete : ");
					scanf("%d",&position);
					continue; 
				}	
				else 
					break;
			}
			printf("After deletion elements in array : ");
			for(i=0;i<5-count;i++)   
			{
				if(i>=position-1&&i!=4-count)  
					array[i]=array[i+1];	//���� ��ġ ���� �� ������ ����
				else if(i==4-count)
						break;
				printf("%d ",array[i]);
			}
			count++; //���� Ƚ�� 1���ϱ�
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
		printf("Enter poss. of element to delete : "); 
		scanf("%d",&position);  //����� ���� ��ġ �Է� 
		while(1)
		{
			if(position>5-count||position<=0)   //����� ���� ��ġ�� 5-����Ƚ������ ũ�ų� 0���� ���� ���� �־��� �� 
			{
				printf("1�̻� %d������ ���� �Է����ּ���.\n",5-count); //���� �� �ִ� ������ �˷��ִ� �޽��� 
				printf("Enter poss. of element to delete : ");
				scanf("%d",&position);
				continue; 
			}	
			else 
				break;
		}
		printf("After deletion elements in array : ");
		for(i=0;i<5-count;i++)   
		{
			if(i>=position-1&&i!=4-count)  
				array[i]=array[i+1];	//���� ��ġ ���� �� ������ ����
			else if(i==4-count)
				break;
			printf("%d ",array[i]);
		}
		count++; // ���� Ƚ�� 1���ϱ� 
		printf("\n");
		printf("continue / exit?");  // �� ������ ������ ����Ȯ��
		scanf("%s",&input);
		for(i=0;i<10;i++)
		{
			input[i] = tolower(input[i]);   //input�� �� ���� �ҹ��ڷ� ��ȯ���ִ� �Լ� 
		}
	}while(count<=5); //���� �� �ִ� Ƚ���� ó���� ���� 5�� �� 
	
	
	return 0;
}
