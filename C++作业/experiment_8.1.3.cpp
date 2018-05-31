/*
 * 问题四：如果将该框架中调整为病人和处方的关系，请通过调整主函数输出一个病人所具有的两个处方
 */

#include <iostream>
#include <string>
using namespace std;

class Patient
{  
public:  
	virtual void ShowPrescription() = 0;
};  

class Cold : public Patient
{
private:  
	string m_name;
	string m_symptoms;
	string m_department;
	int m_age;
	string m_gerden;
public:  
	Cold(string name,string symptoms, string department, int age, string gerden)
	{
		m_name = name;
		m_symptoms = symptoms;
		m_department = department;
		m_age = age;
		m_gerden = gerden;
	}  
    virtual void ShowPrescription() 
	{
		cout<<m_name<<"'s age : "<<m_age<<endl;
		cout<<m_name<<"'s gerden: "<<m_gerden<<endl;
		cout<<m_name<<"'s symptoms: "<<m_symptoms<<endl;
		cout<<m_name<<"'s department: "<<m_department<<endl;
		cout<<m_name<<"'s Prescription:"<<endl;
	}  
};

class Prescription : public Patient
{
private:  
	Patient *m_patient;
public:  
	Prescription(Patient *patient): m_patient(patient) {}
	virtual void ShowPrescription() { m_patient->ShowPrescription(); }
};

class PrescriptionA : public Prescription
{
private:
	string Prescription_name;
public:
	PrescriptionA(string d,Patient *patient) : Prescription(patient) 
	{ Prescription_name = d;} 
	void ShowPrescription()	
	{
		Prescription::ShowPrescription();
		AddPrescription();
	}  
private:  
	void AddPrescription() { cout<<Prescription_name<<endl; }
}; 
int main()
{
	Patient *pcold = new Cold("www","cold","xxxxxx",29,"male");
	Patient *ppa = new PrescriptionA("感冒清胶囊",pcold);
 	Patient *ppb = new PrescriptionA("小柴胡片",ppa);
	ppb->ShowPrescription();
	delete ppa;  
	delete ppb;  
	delete pcold;  
	return 0;
}

