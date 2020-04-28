void ListCreate_Tail(List * pl)
{
	//先建立第一个节点
	*pl = (ListNode *)malloc(sizeof(ListNode));
	assert(*pl != NULL);
	(*pl)->data = 1;
	(*pl)->next = NULL;

	//创建一个活动指针p指向第一个节点
	ListNode * p = *pl;
	for (int i = 2; i <= 10; i++)
	{
		//新建一个节点，并创建一个活动指针s指向它
		ListNode * s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		//将s链接到链表上
		p->next = s;

		//将p指向s也就是链表最后一个节点准备下一次循环
		p = s;
	}

}
