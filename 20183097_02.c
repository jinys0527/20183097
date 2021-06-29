#include <stdio.h>
#include <string.h>

int main()
{
	int array[50]; //최대 길이가 50인 배열 생성 
	int i;
	int position;  //원하는 위치를 받기 위한 변수 선언 
	char input[10];  //계속할지 확인하기 위한 문자열 생성 
	int count=0;   //지우고 싶은 위치의 element가 몇개 지워졌는지 확인하기 위한 변수 선언
	printf("Enter element in array : ");
	
	for(i=0;i<5;i++)
	{
		scanf("%d",&array[i]); //배열에 5개 정수  초기화 
	}
	printf("Stored element in array : ");
	for(i=0;i<5;i++)
	{
		printf("%d ",array[i]);  //배열에 저장된 5개 정수 출력 
	}
	printf("\n");
	
	
	do
	{
		if(strcmp(input,"continue")==0)
		{
			printf("Enter poss. of element to delete : "); 
			scanf("%d",&position);  //지우고 싶은 위치 입력 
			while(1)
			{
				if(position>5-count||position<=0)   //지우고 싶은 위치가 5-지운횟수보다 크거나 0보다 작은 같을 넣었을 때 
				{
					printf("1이상 %d이하의 수를 입력해주세요.\n",5-count); //지울 수 있는 범위를 알려주는 메시지 
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
					array[i]=array[i+1];	//지울 위치 이후 값 앞으로 당기기
				else if(i==4-count)
						break;
				printf("%d ",array[i]);
			}
			count++; //지운 횟수 1더하기
			printf("\n");
			printf("continue / exit?");  // 더 실행할 것인지 여부확인
			scanf("%s",&input);
			for(i=0;i<10;i++)
			{
				input[i] = tolower(input[i]);   //input에 들어간 값을 소문자로 변환해주는 함수 
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
		printf("Enter poss. of element to delete : "); 
		scanf("%d",&position);  //지우고 싶은 위치 입력 
		while(1)
		{
			if(position>5-count||position<=0)   //지우고 싶은 위치가 5-지운횟수보다 크거나 0보다 작은 같을 넣었을 때 
			{
				printf("1이상 %d이하의 수를 입력해주세요.\n",5-count); //지울 수 있는 범위를 알려주는 메시지 
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
				array[i]=array[i+1];	//지울 위치 이후 값 앞으로 당기기
			else if(i==4-count)
				break;
			printf("%d ",array[i]);
		}
		count++; // 지운 횟수 1더하기 
		printf("\n");
		printf("continue / exit?");  // 더 실행할 것인지 여부확인
		scanf("%s",&input);
		for(i=0;i<10;i++)
		{
			input[i] = tolower(input[i]);   //input에 들어간 값을 소문자로 변환해주는 함수 
		}
	}while(count<=5); //지울 수 있는 횟수는 처음에 넣은 5이 하 
	
	
	return 0;
}
