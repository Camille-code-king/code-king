#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//目标：从0开始实现cmp算法
//例如:aabccabc
int* creatArrNext(char pattern[]) {
	int len = (int)strlen(pattern);
	int* next = (int*)malloc(sizeof(int) * len);
	next[0] = 0;
	int i = 1;
	int j = 0;
	while (i < len) {
		if (pattern[i] == pattern[j]) {
			next[i] = j + 1;
			i++;
			j++;
		}
		else if (j>0)
		{
			j = next[j - 1];
		}
		else
		{
			next[i] = 0;
			i++;
		}
	}

	return next;
}
int matchString(char* pattern,char* mainString,int* next) {
	int i = 0;
	int j = 0;	//char s1[] = "aabccabc";
	            //char pattern[] = "cab";
	int len = (int)strlen(mainString);
	int max = (int)strlen(pattern);
	while (i <= len) {
		if (j  == max)
			return i-j;
		if (pattern[j] == mainString[i]) {
			i++;
			j++;
		}
		else if (j > 0) {
			j = next[j - 1];
		}
		else {
			i++;
		}
	}
	return -1;
}
int main() {
	char s1[] = "aabccabc";
	char pattern[] = "bccabc";
	int* arr = creatArrNext(s1);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arr[i]);
	}
	int a = matchString(pattern, s1, arr);
	printf("\n");
	printf("%d",a);
	return 0;
}
