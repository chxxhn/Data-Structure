#include "DoublyLinkedList.h"

int main(void)
{
    int count = 0;
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* Current = NULL;

    for(int i = 0; i < 5; i++)
    {
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }

    count = DLL_GetNodeCount(List);
    for(int i = 0; i < count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d]: %d\n", i, Current->Data);
    }

    printf("\n Inserting 3000 After [2]...\n\n");

    Current = DLL_GetNodeAt(List, 2);
    NewNode = DLL_CreateNode(3000);
    DLL_InsertAfter(Current, NewNode);

    count = DLL_GetNodeCount(List);
    for(int i = 0; i < count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d]: %d\n", i, Current->Data);
    }

    printf("\nDestroying List...\n");

    for(int i = 0; i < count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        if(Current != NULL)
        {
            DLL_RemoveNode(&List, Current);
            DLL_DestroyNode(Current);
        }
    }

    return 0;
}