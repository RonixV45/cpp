#include "Pupil.h"

int Pupil::mBaseID = 1000;

Pupil::Pupil(string name, int age, string className) : Person(name,age)
{
	setClassName(className);
	clearNotes();
	mID = to_string(mBaseID++);
}
Pupil::Pupil(const Pupil& pu)
{
	*this = pu;
}
void Pupil::clearNotes()
{
	for (int i = POLSKI; i <= NIEMIECKI; i++)
		mNotes[i] = 0;

	//znacznie lepiej uzyc memset
}
void Pupil::setNote(Subjects sub, double note)
{
	if (sub >= POLSKI && sub <= NIEMIECKI)
		mNotes[sub] = note;
}
double Pupil::calcAve()
{
	double sum = 0;
	int noteNo = 0;
	for(int i=POLSKI; i<NIEMIECKI;i++)
		if (mNotes[i] > 1)
		{
			noteNo++; sum += mNotes[i];
		}
	return mAve = (noteNo != 0) ? sum / noteNo : 0;
}
void Pupil::printPupil()
{
	cout << getName() << " (" << getAge() << ") srednia = " << getAve();
	cout << endl << "\t\t";
	printOutFit();

}



