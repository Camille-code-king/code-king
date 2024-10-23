//#include<stdio.h>
//#include<string.h>
//bool isValid(char* s) {
//	int n = strlen(s);
//	int top=0;
//	char p[1000];
//	int count = 0;
//	if (n % 2 == 1)
//		return false;
//	for (int i = 0; i < n; i++)
//	{  
//		if (top == 0) {
//			p[0] = s[i];
//			top++;
//		}
//		else {
//			if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
//				p[top] = s[i];
//				top++;
//			}
//			else {
//				if ((p[top - 1] == '{' && s[i] == '}') || (p[top - 1] == '[' && s[i] == ']') || (p[top - 1] == '(' && s[i] == ')')) {
//					top--;
//				}
//				else {
//					return false;
//				}
//			}
//		}
//		if (p[top - 1] == '{' || p[top - 1] == '[' || p[top - 1] == '(')
//			return false;
//	}
//	for (int i = 0; i < top; i++)
//	{
//		if (p[i] == '{' || p[i] == '[' || p[i] == '(') {
//			count++;
//		}
//	}
//	if (count == top&&top!=0) {
//		return false;
//	}
//	return true;
//}