struct Comp {
	bool operator() (ListNode* l1, ListNode* l2) {
		return l1->val > l2->val;
	}
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.empty()) return nullptr;
	priority_queue<ListNode*, vector<ListNode*>, Comp> q;
	for (ListNode* list : lists) {
		if (list) {
			q.push(list);
		}
	}
	ListNode* dummy = new ListNode(0), * cur = dummy;
	while (!q.empty()) {
		cur->next = q.top();
		q.pop();
		cur = cur->next;
		if (cur->next) {
			q.push(cur->next);
		}
	}
	return dummy->next;
}