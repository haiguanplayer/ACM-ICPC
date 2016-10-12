/*
POJ 3295
Tautology
题目大意：给你这些字母：K, A, N, C, E, p, q, r, s, t
它们分别代表&&与    ||或   !非   (!x)||y    ==
（tautology  恒真命题）
让你判断一个命题是否恒为真命题
思路：构造法，和不懂，附别人的代码
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int state[5];
char s[205];
int l=0;
int ind()
{
	char ch=s[l++];
	//printf("%d\n",l);
	printf("");

	switch(ch)
	{
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
		return state[ch-'p'];
		break;
	case 'K':
		return ind()&ind();
		break;
	case 'A':
		return ind()|ind();
		break;
	case 'N':
		return !ind();
		break;
	case 'C':
		return !ind()|ind();
		break;
	case 'E':
		return ind()==ind();
		break;
	}
}

int main()
{
    scanf("%s", s);
    while(s[0]!='0')
    {
        int len=strlen(s);
        int mark=1;
        for(state[0]=0; state[0]<=1 && mark; state[0]++)
        {
            for(state[1]=0; state[1]<=1 && mark; state[1]++)
            {
                for(state[2]=0; state[2]<=1 && mark; state[2]++)
                {
                    for(state[3]=0; state[3]<=1 && mark; state[3]++)
                    {
                        for(state[4]=0; state[4]<=1 && mark; state[4]++)
                        {
                            l=0;
                            if(ind()==0)
                               mark=0;
                        }
                    }
                 }
            }
        }
        if(mark==1)
            printf("tautology\n");
        else
            printf("not\n");
        scanf("%s", s);
    }
    return 0;
}
