typedef struct node
{
	int data;
	struct node *next;
}
node;

node* initialize(node* list, int n);
node* reverse(node *list);
node* shuffle(node* list);
void print(node* list);