#include "Vector.h"

Vector::Vector(int nDim , int initVal )
{
	//wykreowaæ dynamiczna tablice wspo³rzednych
	createVector(nDim);
	//wkopiowac do kazdej wspo³rzednej initVal
	for (int i = 0; i < getDim(); i++)
	{
		m_pCoord[i] = initVal;
	}
}
Vector::Vector(const Vector& v)
{
	m_pCoord = nullptr;
	mDim = 0; // Wazne aby mozna bylo sprawdzac rozmiar w operatorze podstawienia =
	*this = v;// musimy sami go napisac bo mamy strukture dynamiczna
}
Vector::~Vector()
{
	delete[] m_pCoord; // !!!!! bo zwalniana jest dynamiczna tablica
}

Vector& Vector::operator = (const Vector& v) // v1 = v2 = v3 
{
	if (this->getDim() != v.getDim())
	{
		delete[] m_pCoord; // bedzie rowniez ok jesli m_pCoord jest NULL
		createVector(v.getDim());
	}
	copyVector(v);

	return *this;
}


istream& operator >> (istream& in, Vector& v) //--- input/output
{
	for (int i = 0; i < v.getDim(); i++)
		in >> v.m_pCoord[i];
	return in;
}
ostream& operator << (ostream& out, Vector& v)//--- input/output
{
	out << '[';
	for (int i = 0; i < v.getDim(); i++)
	{
		out << v.m_pCoord[i];
		if (i < v.getDim() - 1)
		out << ',';
	}
	out << ']';
	return out;
}
//--- addition
const Vector operator + (const Vector& v1, const Vector& v2)//v1 + v2
{
	Vector res(v1);
	return res += v2;
}
const Vector operator + (const Vector& v1, double x)//v2 + 4
{
	Vector res(v1);
	return res += x;
}
const Vector operator + (double x, const Vector& v2)//4 + v1
{
	return v2 + x;
}
Vector& Vector::operator += (const Vector& v)//v1 += v2
{
	if (this->getDim() != v.getDim())
	{
		//cerr << "Incompatible vector dimensions!!!\n";
		//return *this;
		throw VectorException(INVAILID_VECTOR_DIM);
	}
	for (int i = 0; i < getDim(); i++)
		this->m_pCoord[i] += v.m_pCoord[i];

	return *this; // powtórzenie ale for nie jest w else
}
Vector& Vector::operator += (double x) //v1 += 4
{
	for (int i = 0; i < getDim(); i++)
	{
		m_pCoord[i] += x;
	}
	return *this;
}
//--- unary minus
const Vector operator - (const Vector& v) //-v
{
	Vector res(v);
	for (int i = 0; i < v.getDim(); i++)
	{
		res.m_pCoord[i] = -res.m_pCoord[i];
	}
	return res;
}

//--- scalar multiplication
double operator * (const Vector& v1, const Vector& v2) // double x = v1 * v2
{
	if (v1.getDim() != v2.getDim())
	{
		//cerr << "Incompatible vector dimension\n";
		//return 0;
		throw VectorException(INVAILID_VECTOR_DIM);
	}
	double res = 0;
	for (int i = 0; i < v1.getDim(); i++)
		res += v1.m_pCoord[i] * v2.m_pCoord[i];

	return res;
}


//--- comparision
bool operator == (const Vector& v1, const Vector& v2)// v1 == v2
{
	if (v1.getDim() != v2.getDim())
		return false;

	for (int i = 0; i < v1.getDim(); i++)
		if (v1.m_pCoord[i] != v2.m_pCoord[i])
			return false;
	return true;
}
bool operator != (const Vector& v1, const Vector& v2)// v1 != v2
{
	return !(v1 == v2);
}
//--- indexation
double Vector::operator[] (int ix) const //double x = v[1];
{
	if (ix < 0 || ix >= this->getDim())
	{
		//cerr << "Index out of range!\n";
		//return 0;
		throw VectorException(INDEX_OUT_OF_RANGE);
	}

	return m_pCoord[ix];
}
double& Vector::operator[] (int ix) //v[1] = 2;
{
	if (ix < 0 || ix >= this->getDim())
	{
		//cerr << "Index out of range!\n";
		//return m_pCoord[0];
		throw VectorException(INDEX_OUT_OF_RANGE);
	}

	return m_pCoord[ix];
}



