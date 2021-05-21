#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int arr[100],count=0;
void insert(int e){
    int i,j;
    arr[count]=e;
    count++;
    i=count;
    j=floor(i/2);
    while(j>0){
        if(e>arr[j-1]){
            arr[i-1]=arr[j-1];
            arr[j-1]=e;
            i=j;
            j=floor(i/2);
        }
        else{
            break;
        }
    }
    printf("%d insertion success...\n",e);
}
void delete_(){
    int l,r,i,e,d;
    if(count==0){
        printf("Heap empty ...\n");
    }
    else{
        d=arr[0];
        i=1;
        count--;
        arr[0]=arr[count];
        e=arr[0];
        while(i*2<=count){
            l=2*i;
            r=2*i+1;
            if(r>count || arr[l-1]>arr[r-1]){
                if(arr[l-1]>e){
                    arr[i-1]=arr[l-1];
                    arr[l-1]=e;
                    i=l;
                }
                else{
                    break;
                }
            }
            else{
                if(arr[r-1]>e){
                    arr[i-1]=arr[r-1];
                    arr[r-1]=e;
                    i=r;
                }
                else{
                    break;
                }
            }
        }
        printf("Deleted %d from heap...\n",d);
    }
}
void display(){
    if(count==0){
        printf("Heap empty...\n");
        return;
    }
    for(int i=0;i<count;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void max_(){
    if(count==0){
        printf("Heap empty...\n");
        return;
    }
    printf("%d extracted from heap...\n",arr[0]);
}
int main()
{
    int f=1,c,e;
    while(f==1){
        printf("-----MENU-----\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Extract Maximum element\n5.Exit\nEnter your choice : ");
        scanf("%d",&c);
        switch(c){
        case 1:
            printf("Enter the element : ");
            scanf("%d",&e);
            insert(e);
            break;
        case 2:
            delete_();
            break;
        case 3:
            display();
            break;
        case 4:
            max_();
            break;
        case 5:
            f=0;
            break;
        default:
            printf("Invalid choice...\n");
        }
    }
    return 0;
}
