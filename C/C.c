#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int item;
  struct list *next;
} list;

list *initialize_list(int item)
{
  list *list = malloc(sizeof(list));
  list->item = item;
  return list;
}

insert_list(list **l, int item)
{
  list *temp;
  temp = initialize_list(item);
  temp->next = *l;
  *l = temp;
}

traverse_list(list *l)
{
  if (l == NULL) return;
  printf("%p, %i\n", l, l->item);
  traverse_list(l->next);
}

list *search_list(list *l, int x)
{
  if (l == NULL || l->next == NULL) return;
  if (l->item == x) return l;
  search_list(l->next, x);
}

main()
{
  list *head = initialize_list(0);
  insert_list(&head, 1);
  insert_list(&head, 2);
  insert_list(&head, 4);
  insert_list(&head, 8);
  traverse_list(head);
  printf("Done traversing!\n");
  list *search;
  search = search_list(head, 4);
  printf("Found %i! Location: %p\n", search->item, search);
}
