#pragma once
#include <string>
#include <list>
#include <iostream>
#include <conio.h>
#include <iostream>
using namespace std;


/*! @class	Node
    @brief	Contains a record of the student's name, subject and their indices.
*/

class Node
{
public:
	Node()
		:pupil(-1)
		,subject(-1)
		,xPupil(-1)
		,xSubject(-1)	{}
	int pupil;
	int subject;
	int xPupil;
	int xSubject;
};


/*! @class	multiList
*/

class multiList
{
private:
	int pCount;
	int sCount;
	int Count;								/// number of entries
	char** pupils;							/// massive of pupils
	char** subjects;						/// massive of subjects
	int** linkTable;						/// massive of communication between the student and the subject
	Node* nodes;							/// massive of entries
public:
	multiList() : Count(0)
	{}
	~multiList()
	{}


/*! @fn		int PCount()
    @brief	return number of students
	@return	int 
*/
	int PCount()
	{
		return pCount;
	}


/*! @fn		int SCount()
    @brief	return number of subjects    
	@return	int 
*/

	int SCount()
	{
		return sCount;
	}


/*! @fn		char** Pupils()
    @brief	return of pupils'es names massive    
	@return	char**
*/

	char** Pupils()
	{
		return pupils;
	}


/*! @fn		char** Subjects()
    @brief	return of pupils'es subjects massive
	@return	char**
*/

	char** Subjects()
	{
		return subjects;
	}


/*! @fn		int** LinkTable()
    @brief	return link table.    
	@return	int**
*/

	int** LinkTable()
	{
		return linkTable;
	}


/*! @fn		list<char*> getPupilsOnSubject(char* subject)
    @brief	make list of pupils sorted by subject     
	@param	char* subject - pointer to subjects massive
	@return	list<char*> result - pointer to first element
*/

	list<char*> getPupilsOnSubject(char* subject)
	{
		list<char*> result;
		int i;
		int k;
		for (i = 0; i < sCount; ++i)
			if (subjects[i] == subject)	
				break;
		for (k = 0; k < Count; ++k)
			if (nodes[k].subject == i) 
				break;
		Node curNode = nodes[k];
		result.push_back(pupils[curNode.pupil]);
		while (curNode.xPupil !=-1)
		{
			curNode = nodes[curNode.xPupil];
			result.push_back(pupils[curNode.pupil]);
		}
		return result; 
	}


/*! @fn		list<char*> getSubjectsOnPupil(char* pupil)
    @brief	make list of subjects sorted by pupils     
	@param	char* pupil - pointer to pupil massive
	@return	list<char*> result - pointer to first element
*/

	list<char*> getSubjectsOnPupil(char* pupil)
	{
		list<char*> result;
		int i;
		int k;
		for (i = 0; i < pCount; ++i)
			if (pupils[i] == pupil)	
				break;
		for (k = 0; k < Count; ++k)
			if (nodes[k].pupil == i) 
				break;
		Node curNode = nodes[k];
		result.push_back(subjects[curNode.subject]);
		while (curNode.xSubject !=-1)
		{
			curNode = nodes[curNode.xSubject];
			result.push_back(subjects[curNode.subject]);
		}
		return result; 
	}


/*! @fn		void setSubjects(char** arr, int count)
    @brief	set name of subject     
	@param	char** arr - pointer to pointer to massive of subjects
*/

	void setSubjects(char** arr, int count)
	{
		subjects = arr;
		sCount = count;
	}


/*! @fn		void setPupils(char** arr, int count)
    @brief	set name of pupil     
	@param	char** arr - pointer to pointer to massive of pupils
*/

	void setPupils(char** arr, int count)
	{
		pupils = arr;
		pCount = count;
	}


/*! @fn		void setLinks(int **lTable)
    @brief	set link table
	@param	int **lTable - pointer to pointer to massive of link table
*/

	void setLinks(int **lTable)
	{
		linkTable = lTable;		
		nodes = new Node[Count];	
		int k = 0;
		for (int i = 0; i < sCount; ++i)
		{
			for (int j = 0; j < pCount; ++j)
			{
				if (linkTable[i][j])
				{
					nodes[k].pupil = j;
					nodes[k].subject = i;
					++k;
					++Count;			
				}
			}		
		}
		for(int k = 0; k < Count; ++k)
		{
			nodes[k].xPupil = -1;
			nodes[k].xSubject = -1;		
		}
		for(int k = 0; k < Count; ++k)
		{
			for (int i = k + 1; i < Count; ++i) 
			{
				if (nodes[i].subject == nodes[k].subject) 
				{
					nodes[k].xPupil = i;
					break;
				}
			}
			for (int i = k + 1; i < Count; ++i)
			{
				if (nodes[i].pupil == nodes[k].pupil)
				{
					nodes[k].xSubject = i;
					break;
				}
			}
		}		
	}
	};
void main()
{	
	
	multiList ml;						/// new element of class multiList
	const int subjectsCount = 3;
	const int pupilsCount = 6;
	char* subjectsArr[subjectsCount] =	{"Physics", "Inegrals", "Programming"};
	char* pupilsArr[pupilsCount] =		{"Alexey", "Evgenii", "Alexandra", "Katya", "Dmitrii", "Kristina"};	
	bool _lTable[subjectsCount][pupilsCount] =
    {
        {1,0,1,1,0,0},
        {1,0,0,1,0,1},
        {1,1,0,0,1,0}
    };
	int** lTable = new int*[subjectsCount];
	for (int i = 0; i < subjectsCount; ++i)
	{
		lTable[i] = new int[pupilsCount];
		for (int j = 0; j < pupilsCount; ++j)
		{
			lTable[i][j] = _lTable[i][j];
		}
	}
	ml.setSubjects(subjectsArr, subjectsCount);
	ml.setPupils(pupilsArr, pupilsCount);
	ml.setLinks(lTable);
	cout<<"Subjects: "<<endl;
	for (int i = 0; i < subjectsCount; ++i) 
		cout<<i<<". "<<subjectsArr[i]<<endl;
	cout<<endl<<"Pupils: "<<endl;
	for (int i = 0; i < pupilsCount; ++i) 
		cout<<i<<". "<<pupilsArr[i]<<endl;
	cout<<endl<<"Link Table: "<<endl;
	for (int i = 0; i < subjectsCount; ++i)
	{
		for (int j = 0; j < pupilsCount; ++j)
			cout<<ml.LinkTable()[i][j]<<"\t";
		cout<<endl<<endl;
	}	
	list<char*> res = ml.getPupilsOnSubject("Physics");
	cout<<endl<<"Pupils on Physics: "<<"\t";
	for (auto it = res.begin(); it != res.end(); it++)
		cout<<*it<<", ";
	cout<<endl<<endl<<"Subject on Alexey: "<<"\t";
	res = ml.getSubjectsOnPupil("Alexey");
	for (auto it = res.begin(); it != res.end(); it++)
		cout<<*it<<", ";
	cout<<endl<<endl;
	system("PAUSE");
}