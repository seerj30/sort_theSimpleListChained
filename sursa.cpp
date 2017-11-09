#include<iostream>
#include<fstream>
using namespace std;

struct nod
{
	int inf;
	nod *urm;
}*u,*a,*ul;

void creare(nod *&p)
{
	ifstream f("in.txt");
	int x;
	nod *q;
	while(f>>x)
	{
		if(p==NULL)
		{
			p=new nod;
			p->inf=x;
			p->urm=NULL;
			u=p;
		}
		else
		{
			q=new nod;
			q->inf=x;
			u->urm=q;
			u=q;
		}
	}
	u->urm=NULL;
}

void afisare(nod *p)
{
	nod *q;
	for(q=p;q;q=q->urm)
		cout<<q->inf<<" ";
	cout<<endl;
}

void insertie(int minv,nod *&ul)
{
	nod *q=new nod;
	q->inf=minv;
	if(a==NULL)
	{
		a=q;
		a->urm=NULL;
		ul=a;
	}
	else
	{
		ul->urm=q;
		ul=q;
		ul->urm=NULL;
	}
}

void stergere(nod *&p)
{
	nod *r,*t;
	int minv;
	for(;p;)
	{
		minv=p->inf;
		for(r=p;r;r=r->urm)
			if(r->inf<minv)
				minv=r->inf;
		for(r=p;r->urm;r=r->urm)
		{
			if(p->inf==minv)
			{
				t=p;
				if(p->urm)
					p=p->urm;
				else
					p=NULL;
				delete t;
				insertie(minv,ul);
			}
			else
			if(r->urm!=u && r->urm->inf==minv)
			{
				t=r->urm;
				if(t->urm==NULL)
					r->urm=NULL;
				else
					r->urm=t->urm;
				delete t;
				insertie(minv,ul);
			}
			else
			if(r->urm==u && r->urm->inf==minv)
			{
				t=r->urm;
				u=r;
				u->urm=NULL;
				delete t;
				insertie(minv,ul);
			}
		}
	}
	ul->urm=NULL;
}

int main()
{
	nod *p;
	p=a=NULL;
	creare(p);
	afisare(p);
	stergere(p);
	afisare(a);
	return 0;
}
