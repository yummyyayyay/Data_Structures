//implementation of both input and output restricted deque
#include <stdio.h>
#define  MAX 5

int RIGHT = -1,LEFT = -1;
int deque[MAX];

void input_deque();
void output_deque();
void insert_left();
void insert_right();
void delete_right();
void delete_left();
void display();

int main(){
    int choice;
    printf("1.Input restricted deque\n2.Output restricted deque\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            input_deque();
            break;
        case 2:
            output_deque();
            break;
    }
    return 0;
}

void input_deque(){
    int choice;
    while(1){
        printf("1.insert_right\n2.delete right\n3.delete left\n4.display\n5.exist\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert_right();
                break;
            case 2:
                delete_right();
                break;
            case 3:
                delete_left();
                break;
            case 4:
                display();
                break;
            case 5:
                 return;
        }
    }
}

void output_deque(){
    int choice;
    while(1){
        printf("1.insert_right\n2.insert left\n3.delete left\n4.display\n5.exist\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert_right();
                break;
            case 2:
                insert_left();
                break;
            case 3:
                delete_left();
                break;
            case 4:
                display();
                break;
            case 5:
                return;
        }
    }
}

void insert_left(){
    if(LEFT == 0 && RIGHT == MAX-1 || LEFT == RIGHT+1) {
        printf("OVERFLOW");
        return;
    }
    if(LEFT == -1){
        LEFT = 0;
        RIGHT = 0;
    }
    else{
        if(LEFT == 0)
            LEFT = MAX-1;
        else
            LEFT = LEFT -1;
    }
}

void insert_right(){
    if(LEFT == 0 && RIGHT == MAX-1 || LEFT == RIGHT+1) {
        printf("OVERFLOW");
        return;
    }
    if(LEFT == -1){
        LEFT = 0;
        RIGHT = 0;
    }
    else{
        if(RIGHT == MAX-1)
            RIGHT = 0;
        else
            RIGHT = RIGHT+1;
    }
}

void delete_right(){
    if(LEFT == -1) {
        printf("UNDERFLOW");
        return;
    }
    if(RIGHT == LEFT){
        LEFT = -1;
        RIGHT = -1;
    }
    else{
        if(RIGHT == 0)
            RIGHT = MAX - 1;
        else
            RIGHT = RIGHT - 1;
    }
}

void delete_left(){
    if(LEFT == -1) {
        printf("UNDERFLOW");
        return;
    }
    if(LEFT == RIGHT){
        LEFT = -1;
        RIGHT = -1;
    }
    else{
        if(LEFT == MAX-1)
            LEFT = 0;
        else
            LEFT = LEFT + 1;
    }
}

//deque using doubly linked list
/*
 * #include <stdio.h>

typedef struct Node{
  struct* Node next;
  struct* Node prev;
  int data;
}Node;

typedef struct Deque{
  Node* front;
  Node* prev;
}Deque;

Deque* initialize_deque(){
  Deque* deque = malloc(sizeof(Deque));
  deque->front = NULL;
  deque->rear = NULL;
  return deque;
}

void insertfront(Deque* deque,int data){
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->next = deque->front;
  temp->prev = NULL;
  if(deque->front != NULL)
    deque->front->prev = temp;
  deque->front = temp;
  if(deque->rear == NULL)
    deque->rear = temp;
}

void inesertback(Deque* deque,int data){
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->next = NULL;
  temp->prev = deque->rear;
  if(deque->rear != NULL)
    deque->rear->next = temp;
  deque->rear = temp;
  if(deque->front == NULL)
    deque->front = temp;
}

void deletefront(Deque* deque){
  if(deque->front == NULL){
    printf("The deque is empty");
    return;
  }
  Node* temp = deque->front;
  if(deque->front == deque->rear){
    deque->front = NULL;
    deque->rear = NULL;
  }
  else{
    deque->front = deque->front->next;
    deque->front->prev = NULL;
  }
  printf("The deleted element is %d",temp->data);
  free(temp);
}

void deleterear(Deque* deque){
  if(deque->rear == NULL){
    printf("The deque is empty");
    return;
  }
  Node* temp = deque->rear;
  if(deque->rear == deque->front){
    deque->front = NULL;
    deque->rear = NULL;
  }
  else{
    deque->rear = temp->prev;
    temp->prev->next = NULL;
  }
  printf("The deleted element is %d\n",temp->data);
  free(temp);
}
 */