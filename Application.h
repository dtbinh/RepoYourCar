#ifndef APPLICATION_H
#define APPLICATION_H

#include "Student.h"
#include "GradStudent.h"
#include "UndergradStudent.h"
#include <string>
#include <iostream>
#include <fstream>

//#include "AppQueue.h"
#define APP_MAX_BUF 1000

#define INCLUDED
using namespace std;
//#include "CourseQueue.h"
//#include "JobQueue.h"

class Application{

	friend   ostream& operator<<(ostream&, Application&);
public:
	//VARIABLES---------------------	
	//------------------------------
	//FUNCTIONS---------------------
	
	
	virtual int      getApplicationNumber(void) = 0;
	string   getCourse(void);
	string   getStatus();

	string   getStuFirst();
	string   getStuLast();
	string   getStuEmail();
	string 	 getType();
	
	string   getStuID();
	
	void	 setRelatedTAPositions(CourseQueue*);
	void	 setRelatedWorkEXP(JobQueue*);
	//bool 	 saveSummary();

	//virtual string getStuName();
	virtual bool printApp(bool);
	virtual bool printModifiedApp(ofstream&);
	Application(int, string="unknown", string="pending", string="grad");
	~Application();
	Application(Application&);//COPY CONSTRUCTOR!
	CourseQueue	*relatedCourses;
	CourseQueue	*relatedTAPositions;
	JobQueue	*relatedWorkEXP;
	//------------------------------

	Application& operator-();//unary '-' changes status of application to "closed"
    Application& operator+();//unary '+' changes status to "assigned"
    bool 		 operator==(Application&);

protected:
	//VARIABLES---------------------

	int     applicationNumber;
	string  course;
	
	
	string  applicationStatus;
	
	string stuFirst;
	string stuLast;
	string stuEmail;
	
	string stuID;
	string stuType;
	
	//------------------------------
};


#endif

