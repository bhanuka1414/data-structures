# include <stdio.h>
# include <stdlib.h>

struct node // declare a structure called “node”
{
    int data;
    node* next;
    node* pre;
};
struct node* head;
struct node* tail;

void initList() // function to initialize the list
{
    head = NULL;
    tail = NULL;
}

node* newNode(int x) //create a new node
{
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    temp->pre=NULL;
    return temp;
}

void insertFront(node* temp) // function to insert at the front
{
    if(head==NULL) // case1: list is empty
    {
        head = tail = temp;
    }
    else // case2 :list is not empty
    {

        temp->next = head;
        temp->pre=NULL;
        head->pre=temp;
        head = temp;

    }
}

void insertRear(node* temp) // function to insert at the rear
{
    if(head==NULL) //case1 : list is empty
    {
        head = tail = temp;
    }
    else //case2 :list is not empty
    {
        tail->next = temp;
        temp->pre=tail;
        temp->next=NULL;
        tail = temp;
    }
}


void insertNext(int d,node* temp1) // function to insert next to a given node
{
    node* temp2;
    int found=0;
    if(head==NULL) //case1 : list is empty
    {
        head=tail=temp1;
        printf("\n list is empty, your node successfully inserted to the front\n");
    }
    else //case2 : list is not empty
    {
        temp2=head;
        while(temp2!=NULL && (!found)) //searching the list
        {
            if(temp2->data==d)
            {
                found=1; //searching node is found
                break;
            }
            else
            {
                temp2=temp2->next;
                //move to the next node
            }
        } //end while
        if(found) //got the searching node
        {
            if(temp2==tail) // searching value is found at the last node
            {
                temp2->next=temp1;
                temp1->pre=temp2;
                temp1->next=NULL;
                tail=temp1;
            }
            else
            {
                temp1->next=temp2->next;
                temp1->pre=temp2;
                temp2->next=temp1;
                temp1->next->pre=temp1;
            }
        }
        else
        {
            tail->next=temp1;
            temp1->pre=tail;
            temp1->next=NULL;
            tail=temp1;
            printf("\nYour searching value is not there,your node successfuly inserted to rear\n");
        }
    } //end else
}
void deleteNode(int d) // function to delete node
{
    node* temp1;
    node* temp2;
    int found=0;
    temp1=head;
   	temp2=head;
    while((!found) && (temp1!=NULL)) //searching the node
    {
        if(temp1->data==d)
        {
            found=1; //searching value is found
            break;
        }
        else
        {
            temp2=temp1;
            temp1=temp1->next; //move to next node
        }
    } //end while
    if(found) //got the searching value
    {
        if(temp2==temp1) //searching value is at the first node
        {
        	temp2->next->pre=NULL;
            head=temp2->next; //first node is deleted
            
        }
        else if(temp1==tail)
//searching value is at the last node
        {
            temp2->next=temp1->next;
            tail=temp2;
        }
        else
        {
            temp2->next=temp1->next;
            temp1->next->pre=temp2;
        }
        free(temp1); //to release memory allocated for temp1, call free function (pre defined function in C)
        printf("\nSuccessfuly deleted(%d)......\n",d);
    }
    else
    {
        printf("\nThe node(%d) does not exist\n",d);
    }
}
void search(int d) // function to search
{
    node* temp;
    int found=0;
    temp=head;
    while(temp!=NULL && (!found)) //searching the node
    {
        if(temp->data==d)
        {
            found=1; //searching node is found
            break;
        }
        else
        {
            temp=temp->next; //move to next node
        }
    } //end while
    if(found) //got the searching node
    {

        printf("\nSearch is successful. Your node(%d) exists",d);
    }

    else
    {
        printf("\nSearch is completed.Your node does not exist");
        
    }
}

void printList_for()
{
    node* temp;
    temp =head;
    if(temp==NULL)
    {
        printf("List is empty");
    }
    else
    {
    	printf("\nForward Printing:");
        while(temp != NULL)
        {
            printf(" %d",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void printList_back()
{
    node* temp;
    temp =tail;
    if(temp==NULL)
    {
        printf("List is empty");
    }
    else
    {
    	printf("\nBackward Printing:");
        while(temp != NULL)
        {
            printf(" %d",temp->data);
            temp = temp->pre;
        }
        printf("\n");
    }
}

int main()
{
printf("************************************************************************\n");
printf("\t\tWijesinghe B P\n");
printf("\t\tHDCBIS-KA-171F-28\n");
printf("************************************************************************");
printf("\n\n");
    initList(); //to initialize l, call initList function
    insertFront(newNode(10)); //to insert a node to front, call insertFront function
    insertFront(newNode(15));
    insertFront(newNode(20));
    insertRear(newNode(25)); //to insert a node to rear, call insertRear function
    insertRear(newNode(30));
    insertRear(newNode(35));
    insertNext(30,newNode(50)); //to insert a node after a given node, call insertNext function
    printList_for();
    printList_back();
  	search(30); //to search a node, call search function
  	deleteNode(15); //to delete a node, call deleteNode function
  	printf("\nAfter Deletion");
    printList_for(); //to print the list
    printList_back();
    printf("\n\n");
    printf("************************************************************************\n");
    printf("************************************************************************\n");
    return 0;
}
