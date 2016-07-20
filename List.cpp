#include<iostream>
using namespace std;

//单链表
typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode;

//双链表
typedef struct DLnode{
	int data;
	struct DLnode *next;
}DLnode;


/*
尾插法建立单链表
*/
Lnode * Create(Lnode *head, int *a, int n){    
	Lnode *first, *node;
	first = (Lnode *)malloc(sizeof(Lnode));   //头结点
	head = first;
	first->next = NULL;
	for (int i = 0; i < n; ++i){
		node = (Lnode *)malloc(sizeof(Lnode));
		node->data = *(a + i);
		first->next = node;
		first = first->next;
	}
	first->next = NULL;
	return head;
}

/*
头插法建立单链表
*/
Lnode * HeadCreate(Lnode *head, int *a, int n){			
	Lnode *first, *node;
	first = (Lnode *)malloc(sizeof(Lnode));    //头结点
	head = first;
	first->next = NULL;
	for (int i = 0; i < n; ++i){
		node = (Lnode *)malloc(sizeof(Lnode));
		node->data = *(a + i);
		node->next = first->next;
		first->next = node;
	}

	return head;
}

/*
 在指定位置插入节点val
*/
Lnode * Insert(Lnode * head, int n, int val){	
	Lnode *p = head;
	Lnode *node = (Lnode*)malloc(sizeof(Lnode));
	for (int i = 0; i < n - 1; ++i){
		p = p->next;
	}
	node->data = val;
	node->next = p->next;
	p->next = node;
	return head;
}

/*
 删除 data 为val的某个节点
*/
int Del(Lnode *head, int val){		
	Lnode*p, *q;
	p = head;				      //传入头指针，然后p保存头指针信息，修改p,即等同于修改head头指针
	while (p->next != NULL){     //p指向删除节点的前一个节点
		if (p->next->data == val)
		{
			break;
		}
		p = p->next;
	}

	if (p->next == NULL){
		return 0;
	}
	else{
		q = p->next;
		p->next = q->next;
		free(q);
		return 1;
	}
}

/*
单链表反转
*/
Lnode* Reverse(Lnode *head){
	Lnode *first = head->next, *tmp;
	head->next = NULL;
	while (first != NULL)
	{
		tmp = first->next;
		first->next = head->next;
		head->next = first;
		first = tmp;
	}
	return head;
}


/*
* 构建有环单链表
*/
Lnode *CirLnode(Lnode *head, int num) {
	Lnode *tmp, *tail;
	tmp = tail = head->next;
	for (int i = 1; i < num; ++i) {
		tmp = tmp->next;
	}

	while (tail->next != NULL) {
		tail = tail->next;
	}

	tail->next = tmp;
	return head;
}

/*
* 判断单链表是否有环
*/
int IsCir(Lnode *head) {

	Lnode *first, *last;
	first = head;
	last = head;

	while (last != NULL && last->next != NULL) {
		last = last->next->next;
		first = first->next;
		if (first == last) {
			cout << first->data << endl;                //在环中相遇的点,不一定是环的初始点

			//求环的初始点

			first = head;
			while (first->next!=NULL){   //first和last在环中相遇的时候，使first指针回到head节点，last不动，然后first和last都每次走一步，两者再次相遇的点就是环的初始节点
				first = first->next;
				last = last->next;
				if (first == last){
					cout << "初始环点" << first->data << endl;
					break;
				}
			}
			return 1;
		}

	}
	return 0;
}

/*
约瑟夫环问题
*/
int JoseCircle(Lnode *head,int num){
	Lnode *p = head,*tmp,*q;
	int i = 1;
	q = p->next;
	while (p!=q){
		i++;
		p = q;
		q = q->next;
		if (i == num){
			tmp = q;
			p->next = tmp->next;
			q = p->next;
			free(tmp);
			i = 1;
		}
	}
	return q->data;
}

/*
 查找单链表中的倒数第K个结点（k > 0）
*/
int  FindLast(Lnode * head, int k){  
	Lnode *p, *q;
	q = head;
	p = q->next;
	for (int i = 0; i < k; ++i){	//使用两个指针，前面的指针走到正K，后面的指向第一个，两者相差为k-1,然后同时走，直到前面走到最后，后指针的位置即为所求
		q = q->next;
	}
	if (q == NULL){				//k大于链表个数
		return -1;
	}
	while (q->next != NULL){
		p = p->next;
		q = q->next;	
	}
	/*
		while(p){
		p=p->next;
		i++;
		if(i>k) q=q->next;		//p先走，只有存在p走过了K个节点，q才开始走，当p走到终点，q指向倒数K个节点
		}	
		if(q==head) return 0;		   //q要么指向头结点，要么指向倒数第K个
		else cout<<q->data<<endl;	
	*/
	return p->data;

}

/*
* 删除相同节点
*/
Lnode *DelSame(Lnode *head) {
	Lnode *p, *q, *tmp;
	p = head->next;
	while (p != NULL) {
		q = p;
		while (q->next != NULL) {

			if (q->next->data == p->data) {
				tmp = q->next;
				q->next = tmp->next;
				free(tmp);
			}
			else{
				q = q->next;
			}

		}
		p = p->next;
	}
	return head;
}

/*
	查找单链表的中间节点
*/
int FindMid(Lnode *head){		
	Lnode *p, *q;
	p = q = head->next;
	while (q->next != NULL){
		if (q->next->next != NULL){
			p = p->next;
			q = q->next->next;
		}
		else{
			break;
		}
	}
	return p->data;
}

/*
	统计节点的个数
*/
int CalcNum(Lnode *head){
	int n = 0;
	Lnode *tmp = head;
	if (head->next == NULL){
		return n;
	}
	else{
		while (tmp->next != NULL){
			n++;
			tmp = tmp->next;
		}
		return n;
	}
}

/*
* 合并两个有序链表
*/
Lnode *MergeLnode(Lnode *h1, Lnode *h2) {
	Lnode *p1, *p2, *p3, *q;
	p1 = h1->next, p2 = h2->next;
	q = p3 = h1;
	q->next = NULL;

	while (p1 != NULL && p2 != NULL) {
		if (p1->data <= p2->data) {
			q->next = p1;
			p1 = p1->next;
		}
		else {
			q->next = p2;
			p2 = p2->next;
		}
		q = q->next;
	}

	if (p1 != NULL) q->next = p1;
	if (p2 != NULL) q->next = p2;

	return p3;
}

/*
* 求A,B链表的差集A-B
*/
Lnode *Diff(Lnode *h1, Lnode *h2) {

	Lnode *p = h1, *q = h2;
	Lnode *tmp;
	while (p->next != NULL && q->next != NULL) {
		if (p->next->data < q->next->data) {
			p = p->next;
		}
		else if (p->next->data > q->next->data) {
			q = q->next;
		}
		else {
			tmp = p->next;
			p->next = tmp->next;
			free(tmp);
		}

	}

	return h1;
}

/*
	求A,B链表的交集
*/
void Common(Lnode *h1, Lnode *h2){
	Lnode *p = h1, *q = h2;
	while (p->next != NULL && q->next != NULL) {
		if (p->next->data < q->next->data) {
			p = p->next;
		}
		else if (p->next->data > q->next->data) {
			q = q->next;
		}
		else {
			cout << p->next->data << "	";
			p = p->next;
			q = q->next;
		}

	}
	cout << endl;
}

/*
删除单链表中的最小值节点
*/
Lnode *DelMin(Lnode *head){

	Lnode *q = head->next, *min = q,*tmp=head;
	while (q != NULL && q->next!=NULL){
		if (q->next->data < min->data){
			tmp = q;
			min = q->next;
		}
		q = q->next;
	}
	tmp->next = min->next;
	free(min);
	return head;
}

/*
将A链表拆分成A,B，其中A是data为奇数的点，B是data为偶数的点，顺序不变
*/
Lnode * SplitLink(Lnode *h1, Lnode *h2){
	Lnode *p = h1,*t ;
	Lnode *q = (Lnode *)malloc(sizeof(Lnode));
    h2 = q;
	q->next = NULL;

	while (p->next != NULL){
		if (p->next->data % 2 == 0){      //如果是偶数，就取出   放到B中，否则就继续前进，然后A就剩余奇数
			t = p->next;
			p->next = t->next;
			t->next = NULL;
			q->next = t;
			q = q->next;
		}
		else{
			p = p->next;
		}
	}
	return h2;
}
/*
按照val值将单链表分成左右部分，左边比它小，右边比它大
*/
Lnode * Partation(Lnode *head,int val){
	Lnode *p = head;

	Lnode *small, *equal, *big;				//将单链表拆成三个链表， 分别定义三个头指针，
	small = equal = big = NULL;

	Lnode * smallA, *equalA, *bigA ;        //三个链表的尾指针
	smallA = equalA = bigA = NULL;

	while (p->next!=NULL){
		if (p->next->data < val){
			if (small == NULL){					//初始时，头尾指针均指向第一个进入大，等，小的节点
				smallA = small = p->next;
			}
			else{
				smallA->next = p->next;		   //不是第一个节点的时候，采用尾插法将节点插入链表
				smallA = smallA->next;
			}
			
		}
		else if (p->next->data == val){
			if (equal == NULL){
				equalA = equal = p->next;
			}
			else{
				equalA->next = p->next;
				equalA = equalA->next;
			}	
		}
		else {
			if (big == NULL){
				bigA = big = p->next;
			}
			else{
				bigA->next = p->next;
				bigA = bigA->next;
			
			}
		}
		p = p->next;
	}
	
	if (small!=NULL && equalA != NULL) {      //当小链表不为空，且等链表不为空，链接两个链表，等链表后置为空
		equalA->next = NULL;
		smallA->next = equal;
	}
	if (equalA!=NULL && bigA != NULL) {		//	同理链接等链表和大链表
		bigA->next = NULL;
		equalA->next = big;
	}

	head->next = small != NULL ? small : equal != NULL ? equal : big;
	return head;
}

/*
正序打印单链表
*/
void show(Lnode * head){
	while (head->next != NULL){
		cout << head->next->data << "  ";
		head = head->next;
	}
	cout << endl;
}

/*
逆序打印单链表
*/
void ShowTail(Lnode *head) {          //print from tail,颠倒顺序的问题,采用栈,并且去掉头结点
	Lnode *p = head;
	if (p == NULL) {
		return;
	}
	ShowTail(p->next);
	cout << p->data << " ";
}

void tt(int *p){
	int a = 3;
	int *q = p;
	q = &a;

}

void test(Lnode *head){					//一个单链表，first指针在前，last指针在后，first置空后，last便访问不到first后的节点
	                                    //last置空后，并不妨碍first访问后面的节点
	Lnode *p = head->next;
    Lnode *q = p;

	p = p->next->next;

	p->next = NULL;

	q = q->next;

	cout << p->data << endl;
}

void main(){

	int a[] = {2,1,3,5,4};
	int b[] = { 3,4, 5, 6, 7, 8 };
	int lenA = sizeof(a) / sizeof(a[0]);
	int lenB = sizeof(b) / sizeof(b[0]);

	Lnode *head = NULL, *tail = NULL , *h2=NULL;         //头指针
	head = Create(head, a, lenA);					     //指针作为函数参数时，传递的也是指针的地址拷贝，所以指正不会改变，传入堆指针时，指针的值才会变化
	show(head);

	tail = HeadCreate(tail, b, lenB);
	Reverse(tail);
	show(tail);

	/*
	cout << "节点个数为: " << CalcNum(head) << endl;

	*tail = Reverse(tail);
	show(tail);

	if (Del(head, 4) > 0){
		cout << "找到并删除" << endl;
		show(head);
	}

	Insert(head, 3, 6);
	show(head);
	cout << "节点个数为: " << CalcNum(head) << endl;
   

	cout << FindMid(head) << endl;

	head = DelMin(head);
	show(head);


	h2=SplitLink(head, h2);
	show(head);
	show(h2);

	

	int *p = (int *)malloc(sizeof(int));
	tt(p);
	if (p == NULL){
		cout << "null" << endl;
	}
	else{
		cout << " not null" << endl;
	}
*/	

	//head = CirLnode(head, 1);
	/*if (IsCir(head)){
		cout << "has a circle " << endl;
	}
	else{
		cout << "no circle " << endl;
	}*/
	//cout << "Last out " << JoseCircle(head, 3) << endl;
	//Common(head, tail);


	head = Partation(head, 2);
	show(head);


	free(head);
	free(tail);
	system("pause");
}