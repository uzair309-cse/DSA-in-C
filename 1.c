#include <stdio.h>
#include <stdlib.h>

void display(int arr[],int size){

    printf("Array elements are: ");

    for(int i=0;i<size;i++){

        printf("%d",arr[i]);
    }
    printf("\n");
}

void insert(int arr[],int *size){

    int element,position;

    printf("Enter the element:");
    scanf("%d",&element);

    printf("Enter position(0 to %d):",*size);
    scanf("%d",&position);

    for(int i=*size;i>position;i--){

        arr[i]=arr[i-1];
    }

    arr[position]=element;
    (*size)++;
}

void delete(int arr[],int *size){

    int position;

    printf("Enter the position(0 to %d):",*size-1);
    scanf("%d",&position);
    for(int i=position;i< *size-1;i++){
        arr[i]=arr[i+1];
    }
    (*size)--;
}

void search(int arr[],int size){

    int element;
    printf("Enter the element:");
    scanf("%d",&element);

    for (int i=0;i<size;i++){

        if(arr[i]==element){
            printf("Element found at index %d",i);
        }
    }
    printf("Not found");
}

void update(int arr[],int size){

    int new,position;

    printf("Enter the positiin(0 to %d):",size-1);
    scanf("%d",&position);

    printf("Enter new value:");
    scanf("%d",&new);

    arr[position]=new;
}

void sort(int arr[],int size){

    for (int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void address(int *arr[],int size){

    int *address=0;
    int index;
    printf("Enter the index(0 to %d)",size-1);
    scanf("%d",&index);

    address = &arr[0] + (index*sizeof(arr[0]));
    printf("Address:");
    printf("%u",address);
}

int main(){

    int arr[10];
    int size = 0;
    int choice;

    printf("Enter the 5 elements(max 10):");
    for(int i=0;i<5;i++){
        printf("Enter the element %d:",i+1);
        scanf("%d",&arr[i]);
        size++;
    }

    while(1){

        printf("\n operations\n");

        printf("1.Display\n 2.Insert\n 3.Delete\n 4. Search\n 5. Update\n 6.Sort\n 7. Address\n");
        printf("Enter the choice:");
        scanf("%d",&choice);

        switch(choice){

            case 1: display(arr,size);break;
            case 2: insert(arr,&size);break;
            case 3: delete(arr,&size);break;
            case 4: search(arr,size);break;
            case 5: update(arr,size);break;
            case 6: sort(arr,size);break;
            case 7: address(arr,size);break;
            default: printf("invalid choice!");
        }
    }
return 0;

}