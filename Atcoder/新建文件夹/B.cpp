#include<cstdio>

int main(){
    char str[55];
    int a[35] = {0};
    scanf("%s",str);
    for(int i = 0;str[i] != '\0';i++)
        a[str[i]-'a']++;

    for(int i = 0;i < 26;i++)
        if(a[i] > 1)
            return 0 * printf("no\n");
    printf("yes\n");
    return 0;
}
