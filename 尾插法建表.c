void ListCreate_Tail(List * pl)
{
	//�Ƚ�����һ���ڵ�
	*pl = (ListNode *)malloc(sizeof(ListNode));
	assert(*pl != NULL);
	(*pl)->data = 1;
	(*pl)->next = NULL;

	//����һ���ָ��pָ���һ���ڵ�
	ListNode * p = *pl;
	for (int i = 2; i <= 10; i++)
	{
		//�½�һ���ڵ㣬������һ���ָ��sָ����
		ListNode * s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		//��s���ӵ�������
		p->next = s;

		//��pָ��sҲ�����������һ���ڵ�׼����һ��ѭ��
		p = s;
	}

}
