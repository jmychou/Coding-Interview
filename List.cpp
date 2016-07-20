#include<iostream>
using namespace std;

//������
typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode;

//˫����
typedef struct DLnode{
	int data;
	struct DLnode *next;
}DLnode;


/*
β�巨����������
*/
Lnode * Create(Lnode *head, int *a, int n){    
	Lnode *first, *node;
	first = (Lnode *)malloc(sizeof(Lnode));   //ͷ���
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
ͷ�巨����������
*/
Lnode * HeadCreate(Lnode *head, int *a, int n){			
	Lnode *first, *node;
	first = (Lnode *)malloc(sizeof(Lnode));    //ͷ���
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
 ��ָ��λ�ò���ڵ�val
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
 ɾ�� data Ϊval��ĳ���ڵ�
*/
int Del(Lnode *head, int val){		
	Lnode*p, *q;
	p = head;				      //����ͷָ�룬Ȼ��p����ͷָ����Ϣ���޸�p,����ͬ���޸�headͷָ��
	while (p->next != NULL){     //pָ��ɾ���ڵ��ǰһ���ڵ�
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
������ת
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
* �����л�������
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
* �жϵ������Ƿ��л�
*/
int IsCir(Lnode *head) {

	Lnode *first, *last;
	first = head;
	last = head;

	while (last != NULL && last->next != NULL) {
		last = last->next->next;
		first = first->next;
		if (first == last) {
			cout << first->data << endl;                //�ڻ��������ĵ�,��һ���ǻ��ĳ�ʼ��

			//�󻷵ĳ�ʼ��

			first = head;
			while (first->next!=NULL){   //first��last�ڻ���������ʱ��ʹfirstָ��ص�head�ڵ㣬last������Ȼ��first��last��ÿ����һ���������ٴ������ĵ���ǻ��ĳ�ʼ�ڵ�
				first = first->next;
				last = last->next;
				if (first == last){
					cout << "��ʼ����" << first->data << endl;
					break;
				}
			}
			return 1;
		}

	}
	return 0;
}

/*
Լɪ������
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
 ���ҵ������еĵ�����K����㣨k > 0��
*/
int  FindLast(Lnode * head, int k){  
	Lnode *p, *q;
	q = head;
	p = q->next;
	for (int i = 0; i < k; ++i){	//ʹ������ָ�룬ǰ���ָ���ߵ���K�������ָ���һ�����������Ϊk-1,Ȼ��ͬʱ�ߣ�ֱ��ǰ���ߵ���󣬺�ָ���λ�ü�Ϊ����
		q = q->next;
	}
	if (q == NULL){				//k�����������
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
		if(i>k) q=q->next;		//p���ߣ�ֻ�д���p�߹���K���ڵ㣬q�ſ�ʼ�ߣ���p�ߵ��յ㣬qָ����K���ڵ�
		}	
		if(q==head) return 0;		   //qҪôָ��ͷ��㣬Ҫôָ������K��
		else cout<<q->data<<endl;	
	*/
	return p->data;

}

/*
* ɾ����ͬ�ڵ�
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
	���ҵ�������м�ڵ�
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
	ͳ�ƽڵ�ĸ���
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
* �ϲ�������������
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
* ��A,B����ĲA-B
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
	��A,B����Ľ���
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
ɾ���������е���Сֵ�ڵ�
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
��A�����ֳ�A,B������A��dataΪ�����ĵ㣬B��dataΪż���ĵ㣬˳�򲻱�
*/
Lnode * SplitLink(Lnode *h1, Lnode *h2){
	Lnode *p = h1,*t ;
	Lnode *q = (Lnode *)malloc(sizeof(Lnode));
    h2 = q;
	q->next = NULL;

	while (p->next != NULL){
		if (p->next->data % 2 == 0){      //�����ż������ȡ��   �ŵ�B�У�����ͼ���ǰ����Ȼ��A��ʣ������
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
����valֵ��������ֳ����Ҳ��֣���߱���С���ұ߱�����
*/
Lnode * Partation(Lnode *head,int val){
	Lnode *p = head;

	Lnode *small, *equal, *big;				//������������������ �ֱ�������ͷָ�룬
	small = equal = big = NULL;

	Lnode * smallA, *equalA, *bigA ;        //���������βָ��
	smallA = equalA = bigA = NULL;

	while (p->next!=NULL){
		if (p->next->data < val){
			if (small == NULL){					//��ʼʱ��ͷβָ���ָ���һ������󣬵ȣ�С�Ľڵ�
				smallA = small = p->next;
			}
			else{
				smallA->next = p->next;		   //���ǵ�һ���ڵ��ʱ�򣬲���β�巨���ڵ��������
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
	
	if (small!=NULL && equalA != NULL) {      //��С����Ϊ�գ��ҵ�����Ϊ�գ����������������������Ϊ��
		equalA->next = NULL;
		smallA->next = equal;
	}
	if (equalA!=NULL && bigA != NULL) {		//	ͬ�����ӵ�����ʹ�����
		bigA->next = NULL;
		equalA->next = big;
	}

	head->next = small != NULL ? small : equal != NULL ? equal : big;
	return head;
}

/*
�����ӡ������
*/
void show(Lnode * head){
	while (head->next != NULL){
		cout << head->next->data << "  ";
		head = head->next;
	}
	cout << endl;
}

/*
�����ӡ������
*/
void ShowTail(Lnode *head) {          //print from tail,�ߵ�˳�������,����ջ,����ȥ��ͷ���
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

void test(Lnode *head){					//һ��������firstָ����ǰ��lastָ���ں�first�ÿպ�last����ʲ���first��Ľڵ�
	                                    //last�ÿպ󣬲�������first���ʺ���Ľڵ�
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

	Lnode *head = NULL, *tail = NULL , *h2=NULL;         //ͷָ��
	head = Create(head, a, lenA);					     //ָ����Ϊ��������ʱ�����ݵ�Ҳ��ָ��ĵ�ַ����������ָ������ı䣬�����ָ��ʱ��ָ���ֵ�Ż�仯
	show(head);

	tail = HeadCreate(tail, b, lenB);
	Reverse(tail);
	show(tail);

	/*
	cout << "�ڵ����Ϊ: " << CalcNum(head) << endl;

	*tail = Reverse(tail);
	show(tail);

	if (Del(head, 4) > 0){
		cout << "�ҵ���ɾ��" << endl;
		show(head);
	}

	Insert(head, 3, 6);
	show(head);
	cout << "�ڵ����Ϊ: " << CalcNum(head) << endl;
   

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