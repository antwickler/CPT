#include<stdio.h>
#include<stdlib.h>
#define bool int
struct sNode{
    int  data;
    struct sNode *next;
};
typedef struct sNode stack;
void push(struct sNode** top_ref, int new_data);
int pop(struct sNode** top_ref);
bool isEmpty(struct sNode* top);
void print(struct sNode* top);
void reverse(struct sNode** top_ref);
int main(){
    struct sNode *s = NULL;
    int dec,bit;
    printf("Enter Decimal: ");
    scanf("%d",&dec);
    while(dec>0){
    	bit = dec % 2;
        dec = dec / 2;
    	push(&s,bit);
	}
    printf("Binary is ");
    print(s);
    return 0;
}
void insertAtBottom(struct sNode** top_ref, int item){
    if (isEmpty(*top_ref))
        push(top_ref, item);
    else    {
        int temp = pop(top_ref);
        insertAtBottom(top_ref, item);
        push(top_ref, temp);
    }
}
void reverse(struct sNode** top_ref){
    if (!isEmpty(*top_ref))    {
        int temp = pop(top_ref);
        reverse(top_ref);
        insertAtBottom(top_ref, temp);
    }
}
bool isEmpty(struct sNode* top){
    return (top == NULL)? 1 : 0;
}
void push(struct sNode** top_ref, int new_data){
    struct sNode* new_node = (struct sNode*) malloc(sizeof(struct sNode));
    if (new_node == NULL)    {
        printf("Stack overflow \n");
        exit(0);
    }
    new_node->data  = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}
int pop(struct sNode** top_ref){
    char res;
    struct sNode *top;
    if (*top_ref == NULL){
        printf("Stack overflow \n");
        exit(0);
    }
    else{
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}
void print(struct sNode* top){
    while (top != NULL){
        printf("%d", top->data);
        top =  top->next;
    }
    printf("\n");
}
