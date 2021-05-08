
typedef struct item *pitem;
struct item {
	int pr,cnt;
	int val;

	pitem l,r;
	item(int val): pr(rnd(int(2e6))),cnt(1),val(val),l(0),r(0){}
};
void push(pitem it){
	if(it){
	}
}
int cnt(pitem it){return it?it->cnt:0;}

void refresh(pitem it){
	if(it){
		it->cnt=cnt(it->l)+cnt(it->r)+1;
	}
}
void merge(pitem& t, pitem l, pitem r){
	push(l);push(r);
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	refresh(t);
}
void split(pitem t, pitem& l, pitem& r, int sz){
	if(!t){l=r=0;return;}
	push(t);
	if(sz<=cnt(t->l))split(t->l,l,t->l,sz),r=t;
	else split(t->r,t->r,r,sz-1-cnt(t->l)),l=t;
	refresh(t);
}
void output(pitem t){
	if(!t)return;
	push(t);
	output(t->l);cout<<t->val<<" ";output(t->r);
}


};
