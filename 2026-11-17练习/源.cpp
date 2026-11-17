//非递归反转
ListNode* reverseList(ListNode* head)
{
	ListNode* prev = nullptr, * next;
	while (head)
	{
		next = head->next;
		head-> = prev;
		prev = head;
		head = next;
	}
	return prev;
}

//递归反转
ListNode* reverseList(ListNode* head, ListNode* prev = nullptr) {
	if (!head) {
		return prev;
	}
	ListNode* next = head->next;
	head->next = prev;
	return reverseList(next, head);
}