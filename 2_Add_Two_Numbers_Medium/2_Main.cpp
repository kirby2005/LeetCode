 struct ListNode
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int carry = 0;
	ListNode* head = new ListNode(0);
	ListNode* currentNode = head;
	ListNode* currentL1 = l1;
	ListNode* currentL2 = l2;

	while (currentL1 && currentL2)
	{
		ListNode* newNode = new ListNode(0);
		currentNode->next = newNode;
		currentNode = newNode;

		int count = currentL1->val + currentL2->val + carry;
		if (count >= 10)
		{
			currentNode->val = count % 10;
			carry = (int)(count / 10);
		}
		else
		{
			currentNode->val = count;
			carry = 0;
		}

		currentL1 = currentL1->next;
		currentL2 = currentL2->next;
	}

	ListNode* rest = currentL1 ? currentL1 : currentL2;
	while (rest)
	{
		ListNode* newNode = new ListNode(0);
		currentNode->next = newNode;
		currentNode = newNode;
		int count = rest->val + carry;
		if (count >= 10)
		{
			currentNode->val = count % 10;
			carry = (int)(count / 10);
		}
		else
		{
			currentNode->val = count;
			carry = 0;
		}

		rest = rest->next;
	}

	if (carry > 0)
	{
		ListNode* last = new ListNode(carry);
		currentNode->next = last;
	}

	currentNode = head->next;
	delete(head);
	head = nullptr;
	return currentNode;
}

int main(int argc, char* argv[])
{
	ListNode* a1 = new ListNode(9);
	ListNode* b1 = new ListNode(9);
	ListNode* b2 = new ListNode(9);
	b1->next = b2;

	auto result = addTwoNumbers(a1, b1);

	return 0;
}