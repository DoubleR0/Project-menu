#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
char text[100], text2[100], text3[100], text4[100], text5[100];
char arr[100][100];
int i=0, j=0;
char *point;
int num, item, number, len;
int arrnum[100];
float cost[100], total;
	
void loadmenu();
void order();
void addmenu();
void delmenu();
void savemenu();
void delmenu(){
	strrev(text);
	point = strchr(text, ' ')-text+1;
	strncpy(text3, text, point);
	number = atoi(text3);
	strcpy(arr[number-1], "\n");
	cost[number-1] = 0;
	printf("Delmenu Confirm");
}
void addmenu(){
	point = strchr(text, ' ')-text+2;
	strncpy(text3, text, point);
	strrev(text3);
	strncpy(text4, text3, 1);
	number = atoi(text4);
	strncpy(text3, text, point);
	strrev(text);
	strncpy(text4, text, strlen(text)-strlen(text3)+1);
	strrev(text);
	strrev(text4);
	strcat(text4, "\n");
	strcpy(arr[number-1], text4);
	strrev(text);
	point = strchr(text, ',')-text;
	strncpy(text5, text, point);
	strrev(text5);
	cost[number-1] = atof(text5);
	printf("Addmenu Confirm");
}
void order(){
	FILE *fp3 = fopen("orders.txt", "w+");
	while(i==0){
		scanf("%s", text);
		if(strcmp(text, "total")==0){
			j=0;
			while(j>=0){
				if(strcmp(arr[j], "")==0){
					break;
				}
				else{
				printf("%s amount %d total %.2f Bath\n", arr[j], arrnum[j], arrnum[j]*cost[j]);
				fprintf(fp3, "%s amount %d total %.2f Bath\n", arr[j], arrnum[j], arrnum[j]*cost[j]);
				total += arrnum[j]*cost[j];
				}
				j++;
			}
			printf("\nTotal price: %.2f Bath\n", total);
			fprintf(fp3, "\nTotal price: %.2f Bath\n", total);
			fclose(fp3);
			break;
		}
		scanf("%d %d", &num, &item);
		if(strcmp(text, "Add")==0){
			arrnum[num-1] += item;
		}
		if(strcmp(text, "Delete")==0){
			if(arrnum[num-1]==0){
				continue;
			}
			else{
				arrnum[num-1] -= item;
			}
		}
		else{
			continue;
		}
	}
}
void savemenu(){
	FILE *fp2 = fopen("menu2.txt", "w+");
		j=0;
		while(j>=0){
			if(strcmp(arr[j], "")==0){
				break;
			}
			else{
				fputs(arr[j], fp2);
			}
			j++;
		}
		fclose(fp2);
}
void loadmenu(){
	FILE *fp = fopen("menus.txt", "r+");
		while(j>=0){
			fgets(arr[j], 100, fp);
			if(strcmp(arr[j], "")==0){
				break;
			}
			else{
				char text[100];
				strcpy(text2, arr[j]);
				strrev(text2);
				point = strchr(text2, ',')-text2-1;
				strncpy(text, text2, point);
				strrev(text);
				cost[j] = atof(text);
			}
			j++;
		}
}
int main(){
	while(i==0){
		scanf("%s", text);
		if(strncmp(text, "loadmenu", 8)==0){
			loadmenu();
			printf("Loadmenu Confirm\n");
			break;
		}
		else{
			continue;
		}
	}
	while(i==0){
		j=0;
		gets(text);
		if(strcmp(text, "showmenu")==0){
			while(i==0){
				if(strcmp(arr[j], "")==0){
					break;
				}
				else{
					printf("%s", arr[j]);
				}
				j++;
			}
		}
		if(strncmp(text, "addmenu", 7)==0){
			addmenu();
		}
		if(strncmp(text, "delmenu", 7)==0){
			delmenu();
		}
		if(strcmp(text, "save")==0){
			savemenu();
		}
		if(strcmp(text, "order")==0){
			break;
		}
		else{
			continue;
		}
	}
	order();
    return 0;
}
