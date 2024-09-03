#include "middle_list_node.h"
#include "linked_list.h"

// case 1: Even number of nodes

/* fast
   slow
   [a]->[b]->[c]->[d]->Null
   
       slow  fast
   [a]->[b]->[c]->[d]->Null
   
            slow      fast
   [a]->[b]->[c]->[d]->Null

CONCLUDE: when a list contains an even number of nodes, after iterations a fast pointer is null,
          and a slow pointer is pointing to the second of the two middle nodes.
*/

// case 1: Odd number of nodes

/* fast
   slow
   [a]->[b]->[c]->[d]->[e]->Null


        slow fast
   [a]->[b]->[c]->[d]->[e]->Null

            slow      fast
   [a]->[b]->[c]->[d]->[e]->Null

CONCLUDE: when a list contains an odd number of nodes, after iterations a fast pointer next is null,
          and a slow pointer is pointing to the middle list node.
*/

LinkedList *middleNode(LinkedList *linkedList)
{
    auto *p_slow = linkedList, *p_fast = linkedList;
    while (p_fast != nullptr && p_fast->next != nullptr) {
        p_slow = p_slow->next;
        p_fast = p_fast->next->next;
    }

    return p_slow;
}
