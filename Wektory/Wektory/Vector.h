#pragma once
#include <iostream>
using namespace std;

#define INVAILID_DIMENSION  0x01
#define INVAILID_VECTOR_DIM 0x02
#define INDEX_OUT_OF_RANGE  0x04
#define OTHER_ERROR		    0x70

class VectorException
{
public:
	VectorException(int errCode = OTHER_ERROR);
	const char* getReason(); // zwraca opis b³edu


private:
	int mErrCode;
};

inline VectorException::VectorException(int errCode)
{
	mErrCode = errCode;
}
inline const char* VectorException::getReason() // zwraca opis b³edu
{
	switch (mErrCode)
	{
	case INVAILID_DIMENSION: return "Invalid vector dimension!!";
	case INVAILID_VECTOR_DIM: return "Invalid vector dimensions!!";
	case INDEX_OUT_OF_RANGE: return "Index out of range";
	default: return "Other error!!";
	}
}



// ============================================================
class Vector
{
public:
	explicit Vector(int nDim=2, int initVal = 0);// zabraonina niejawna konwersja
	Vector(const Vector& v);
	virtual ~Vector();

	int getDim() const;

public: //operatory

//--- assigment
	Vector& operator = (const Vector& v);

//--- addition
	//v1 + v2
	friend const Vector operator + (const Vector& v1, const Vector& v2);
	//v2 + 4
	friend const Vector operator + (const Vector& v1, double x);
	//4 + v1
	friend const Vector operator + (double x, const Vector& v2);
	//v1 += v2
	Vector& operator += (const Vector& v);
	//v1 += 4
	Vector& operator += (double x);

//--- substracion
	//v1 - v2
	friend const Vector operator - (const Vector& v1, const Vector & v2);
	//v1 - 3
	friend const Vector operator - (const Vector& v1, double x);
	//v1 -= v2
	Vector& operator -= (const Vector& v);
	//v1 -= 3
	Vector& operator -= (double x);

//--- unary minus
	//-v
	friend const Vector operator - (const Vector& v);

//--- scalar multiplication
	// double x = v1 * v2
	friend double operator * (const Vector& v1, const Vector& v2);

//--- multiplication
	//v * 4
	friend double operator * (const Vector& v1, double x);
	//4 * v
	friend double operator * (double x, const Vector& v1);
	//v *= 4
	Vector& operator *= (double x);

//--- comparision
	// v1 == v2
	friend bool operator == (const Vector& v1, const Vector& v2);
	// v1 != v2
	friend bool operator != (const Vector& v1, const Vector& v2);

//--- indexation
	//double x = v[1];
	double operator[] (int ix) const;
	//v[1] = 2;
	double& operator[] (int ix);

//--- input/output
	friend istream& operator >> (istream& in, Vector& v);
	friend ostream& operator << (ostream& out, Vector& v);

//--- conversion Vector to double
	operator double* (); // conversion Vector ->> double  double* p = (double)v; i teraz p to tablica wspolrzednych wektora


private:
	void createVector(int nDim);
	void copyVector(const Vector& v);

private:
	int		mDim;	   // vector dimension(rozmiar)
	double* m_pCoord; // vector coordinates

};

//-- inline functions
inline int Vector::getDim() const
{
	return mDim;
}

inline Vector::operator double* ()
{
	return m_pCoord;
}

inline void Vector::createVector(int nDim)
{
	if (nDim < 2)
	{
		//cerr << "Invalid vector dimension!!\n";
		//nDim = 2;
		throw VectorException(INVAILID_DIMENSION);
	}
	mDim = nDim;
	m_pCoord = new double[mDim];
	//m_pCoord = new( nothrow ) double[mDim];
	//wtedy moge sprawdzic czy m_pCoord == NULL(nullptr) i obsluzyc sytuacje wyjatkowa
}

inline void Vector::copyVector(const Vector& v)
{
	memcpy(this->m_pCoord, v.m_pCoord, getDim() * sizeof(double)); // bardzo szybkie
}





