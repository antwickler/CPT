#include <stdio.h>
int main(){
	int i,x,y;
	printf("Ans: ");
	scanf("%d", &x);
	system("cls");
	for(i = 0; i < 10; i++){
		printf("T%02d: ", i+1);
		scanf("%d", &y); fflush(stdin);

    if(i == 9){
			printf("=Game over\n");
			break;
		}
    if(y < (x - 3))
			printf("=Too samll\n");
		else if(y > (x + 3))
			printf("=Too large\n");
		else if(y < (x) || y > (x))
			printf("=Very close\n");
		else if(y == x){
			printf("=Victory\n");
			break;
		}
	}
	return 0;
}
