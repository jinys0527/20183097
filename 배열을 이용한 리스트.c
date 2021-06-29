#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main()
{
	int array[50];   //최대 길이가 50인 배열 생성 
	int i,temp1,temp2;
	int position;    //원하는 위치를 받기 위한 변수 선언 
	int newelement;  //새로 삽입할 element 
	char input[10];  //계속할지 확인하기 위한 문자열 생성 
	int count = 0; //새로운 element가 몇개 추가되었는지 확인하기 위한 변수 선언 
	printf("Enter 5 elements in array : ");
	
	for(i=0;i<5;i++)
	{
		scanf("%d",&array[i]);    //배열에 5개 정수  초기화 
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
			printf("Enter position for enter element : ");
			scanf("%d",&position);  //새로운 element를 넣은 위치 입력 
			while(1)
			{
				if(position>50) // 배열의 최대길이가 50이므로 position은 50보다 작아야한다. 
				{
					printf("50이하의 수를 입력해주세요. ");
					scanf("%d",&position);
					continue;
				}
				else 
					break;
			}
			printf("Enter new element : ");
			scanf("%d",&newelement);
			count++;   //새로운 element가 추가 되었으니 count를 1씩 증가 
			printf("Stored data in array : ");
			for(i=0;i<5+count;i++)
			{
				if(i==position-1) 
				{
					temp1 = array[i]; //원하는 위치 값 ->  temp1
					array[i]=newelement; //원하는 위치 <- 새로운 값 
				}
				else if(i>position-1) 
				{
					temp2 = array[i];  //원하는 위치 이후의 값 -> temp2 
					array[i]=temp1; //이후 값 대체 
					temp1 = temp2; //다시 원래꺼 -> temp1 
				}
				printf("%d ",array[i]);
			}
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
		printf("Enter position for enter element : ");
		scanf("%d",&position);  //새로운 element를 넣은 위치 입력 
		while(1)
		{
			if(position>50) // 배열의 최대길이가 50이므로 position은 50보다 작아야한다. 
			{
				printf("50이하의 수를 입력해주세요. ");
				scanf("%d",&position);			
				continue;
			}
			else
				break;
		}
		printf("Enter new element : ");
		scanf("%d",&newelement);
		count++;   //새로운 element가 추가 되었으니 count를 1씩 증가 
		printf("Stored data in array : ");
		for(i=0;i<5+count;i++)
		{
			if(i==position-1) 
			{
				temp1 = array[i]; //원하는 위치 값 ->  temp1
				array[i]=newelement; //원하는 위치 <- 새로운 값 
			}
			else if(i>position-1) 
			{
				temp2 = array[i];  //원하는 위치 이후의 값 -> temp2 
				array[i]=temp1; //이후 값 대체 
				temp1 = temp2; //다시 원래꺼 -> temp1 
			}
			printf("%d ",array[i]);
		}
		printf("\n");
		printf("continue / exit?");  // 더 실행할 것인지 여부확인
		scanf("%s",&input);
		for(i=0;i<10;i++)
		{
			input[i] = tolower(input[i]);   //input에 들어간 값을 소문자로 변환해주는 함수 
		}
	}while(count<=45);  //처음에 5개를 넣었으므로 최대 들어갈수있는것은 45개이므로 count는 45이하일때만 실행 
	
	
	
	return 0; 
}
