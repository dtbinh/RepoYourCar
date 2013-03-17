#include "Job.h"
#include "Course.h"
#include "Student.h"
#include "UndergradStudent.h"
#include "GradStudent.h"
#include "CourseQueue.h"
#include "JobQueue.h"
#include "GradApp.h"
#include "UndergradApp.h"
#include "Application.h"
#include "AppQueue.h"

#include <string>
#include <iostream>
using namespace std;
int main(){
	//=========================================TEMPLATES FOR OBJECT PARAMETERS===============================================
	//GradStudent(string first, string last, string email, string studentnum, string research, string program, string supervisor)
	//GradApp(GradStudent *gs, int appNum, string course, string status)

	//UndergradStudent(int cgpa, int gpa, string fisrt, string last, string email, string major, int year, string studentnum)
	//UndergradApp(UndergradStudent *ugs, int appNum, string course, string appstatus)
	//=======================================================================================================================

	/////////////////////STUDENTS/////////////////////////
	GradStudent bill("Bill", "OReily", "baba@carleton.ca", "100928374", "Physics", "super-Jim");
	GradStudent monkeys("Arctic", "Monkeys", "telecaster@carleton.ca", "100934782", "CompSci", "visor");
	GradStudent fun("Fun", "-", "some@carleton.ca", "100828392", "Baking", "lolapalooza");
	GradStudent nana("Naena", "Lapsodpesia", "nights@carleton.ca", "100829372", "Music", "coolguy");
	UndergradStudent george(10, 11, "George", "Lamp", "lamp@carleton.ca", "InteriorLighting", 2, "100998877" );
	UndergradStudent syd(11, 7, "Syd", "Barrett", "shineon@carleton.ca", "Music", 2, "100829372" );
	UndergradStudent valerie(12, 9, "Valerie", "Dee", "goldontheceiling@carleton.ca", "Business", 2, "100346789" );
	UndergradStudent smith(1, 8, "Agent", "Smith", "anderson@carleton.ca", "Anderson", 2, "100101101" );
	////////////////////APPLICATIONS//////////////////////
	GradApp billApp(&bill, 10231, "COMP2401", "pending");
	GradApp monkeyApp(&monkeys, 10232, "COMP2406", "pending");
	GradApp funApp(&fun, 10233, "COMP2406", "pending");
	GradApp nanaApp(&nana, 10234, "COMP3803", "pending");
	UndergradApp georgeApp(&george, 20394, "COMP2404", "pending");
	UndergradApp sydApp(&syd, 20396, "COMP4000", "pending");
	UndergradApp valApp(&valerie, 20397, "COMP3001", "pending");
	UndergradApp smithApp(&smith, 20395, "COMP2404", "pending");

	//////////////////////THE QUEUE///////////////////////
	AppQueue queue;

	//////////////////////POPULATE////////////////////////
	queue.pushBack(&billApp, NULL);
	queue.pushBack(&monkeyApp, NULL);
	queue.pushBack(&funApp, NULL);
	queue.pushBack(&nanaApp, NULL);
	queue.pushBack(NULL, &georgeApp);
	queue.pushBack(NULL, &sydApp);
	queue.pushBack(NULL, &valApp);
	queue.pushBack(NULL, &smithApp);





	return 0;
}