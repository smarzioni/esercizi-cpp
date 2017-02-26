//Taken from Joshi's C++ Design Patterns

#ifndef PAYOFF3_H
#define PAYOFF3_H

/*
 The Base Class PayOff is used as a function object via the overloaded operator(double Spot) to return 
 the pay off given the Spot price. As different types of payoffs exist, we will have 
 different derived classes from PayOff.
*/
class PayOff
{
public:
	PayOff() {};

	virtual double operator()(double Spot) const = 0;
	virtual ~PayOff() {} //virtual destructor
	virtual PayOff* clone() const = 0;
private:
};

class PayOffCall : public PayOff //inherit the interface of the class PayOff
{
public:
	PayOffCall(double Strike_);

	virtual double operator()(double Spot) const;
	virtual ~PayOffCall() {}
	virtual PayOff* clone() const;

private:
	double Strike;
};

class PayOffPut : public PayOff
{
public:
	PayOffPut(double Strike);
	virtual double operator()(double Spot) const;
	virtual ~PayOffPut() {}
	virtual PayOff* clone() const;

private:
	double Strike;
};

#endif


//personal Comments.
//The class PayOff is inherited by the two classes PayOffCall and PayOffPut.
//Both the Destructor ~PayOff() and the operator() are declared virtual.
//In this way an object of type PayOffCall will have some extra data (a function pointer),
//that will refer to the right implementation of the virtual function corresponding to,
// e.g., operator().
// Putting  the =0 in line 10 means that such method HAS TO be implemented in the derived classes.
//Such methods are called pure virtual.
// As such, the class PayOff by itself is incompleted and objects of this class can not
//be defined.
// The need to declear a virtual destrucor and override it is that, if we call a 
// delete to a pointer of type PayOff* which actually point to an object of a 
// derived type (like PayOffPut) then, if not overridden, the destructor invoked
// would be the one of the class PayOff. For example it would forget to deallocate the
//	memory of the member Strike. 
