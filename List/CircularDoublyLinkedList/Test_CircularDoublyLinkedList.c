#include "CircularDoublyLinkedList.h"

int main(void)
{
    int count = 0;
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* Current = NULL;

    for(int i = 0; i < 5; i++)
    {
        NewNode = CDLL_CreateNode(i);
        CDLL_AppendNode(&List, NewNode);
    }

    count = CDLL_GetNodeCount(List);
    for(int i = 0; i < count; i++)
    {
        Current = CDLL_GetNodeAt(List, i);
        printf("List[%d]: %d\n", i, Current->Data);
    }

    printf("\n Inserting 3000 After [2]...\n\n");

    Current = CDLL_GetNodeAt(List, 2);
    NewNode = CDLL_CreateNode(3000);
    CDLL_InsertAfter(Current, NewNode);

    printf("\nRemoving Node at 2...\n");
    Current = CDLL_GetNodeAt(List, 2);
    CDLL_RemoveNode(&List, Current);
    CDLL_DestroyNode(Current);

    count = CDLL_GetNodeCount(List);
    for(int i = 0; i < count*2; i++)
    {
        if(i == 0) Current = List;
        else Current = Current->NextNode;
        printf("List[%d]: %d\n", i, Current->Data);
    }

    printf("\nDestroying List...\n");

    for(int i = 0; i < count; i++)
    {
        Current = CDLL_GetNodeAt(List, i);
        if(Current != NULL)
        {
            CDLL_RemoveNode(&List, Current);
            CDLL_DestroyNode(Current);
        }
    }

    return 0;
}