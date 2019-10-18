#include <iostream>
using namespace std;

class complex
{
	public:
		float real,imag;
		void print();
		void repres(float ,float);
		void add(const complex &,const complex &);
		void sub(const complex &,const complex &);
		void multiply(const complex &,const complex &);
		void divide(const complex &,const complex &);
		complex operator -()const;
		complex operator ++();
		complex operator +(float n)const;
}; 
complex complex::operator -()const
{
	complex c;
	c.real=-real;
	c.imag=-imag;
	return c;
}
complex complex::operator ++()
{
	complex d;
	d.real=++real;
	d.imag=++imag;
	return d;
}
complex complex::operator +(float n)const   
{
	complex c;
	c.real=real+n;
	c.imag=imag+n;
	return c;
}
/*friend
	complex operator +(float n,const complex &c)
	{
	complex d;
	d.real=n+c.real;
	d.imag=n+c.imag;
	return d;
	}
*/

istream& operator >>(istream&get,complex&c)
{
	cout<<"\n";
	cout<<"Enter the real part : ";
	get>>c.real;
	cout<<"\nEnter the imag part : ";
	get>>c.imag;
	return get;
}
ostream& operator <<(ostream &put,const complex &c)
{
	put<<"\n("<<c.real<<","<<c.imag<<"i)";
	return put;
}
void complex::repres(float a,float b)
{
	real=a;
	imag=b;
}

void complex::print()
{
	cout<<real<<"+"<<imag<<"i"<<"\n";
}
void complex::add(const complex &s,const complex &p)
{
	real=s.real+p.real;
	imag=s.imag+p.imag;
}
void complex::sub(const complex &s,const complex &p)
{
	real=s.real-p.real;
	imag=s.imag-p.imag;
}
void complex::multiply(const complex &s,const complex &p)
{
	real=(s.real*p.real)-(s.imag*p.imag);
	imag=(s.real*p.imag)+(s.imag*p.real);
}
void complex::divide(const complex &s,const complex &p)
{
	real=((s.real*p.real)+(s.imag*p.imag))/(p.real*p.real+p.imag*p.imag);
	imag=((s.real*p.imag)-(s.imag*p.real))/(p.real*p.real+p.imag*p.imag);
}

main()
{
	complex s,p,z,a,b,c;
	cin>>a;
	cin>>b;
	cout<<"\na : "<<a;
	cout<<"\nb : "<<b;
	cout<<"\n";
	s.repres(a.real,a.imag);
	cout<<"1st number : ";
	s.print();

	p.repres(b.real,b.imag);
	cout<<"\n2nd number : ";
	p.print();

	a=b.operator -();
	a.print();
	a=b.operator ++();
	a.print();
	a=b.operator +(4.5);
	a.print();
	return 0;
}