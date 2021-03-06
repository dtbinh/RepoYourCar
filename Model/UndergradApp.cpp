#include "UndergradApp.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

UndergradApp::UndergradApp(UndergradStudent *ugs, int appNum, string cor, string stat): Application(0,"","","undergrad"){
	applicationNumber = appNum;
    course 		  = cor;
    applicationStatus = stat;
	
 	stuFirst = ugs->getFirst();
	stuLast = ugs->getLast();
	stuEmail = ugs->getEmail();
	stuID = ugs->getStudentNumber();
	stuCGPA = ugs->getCGPA();
	stuMGPA = ugs->getMajorGPA();
	stuMajor = ugs->getMajor();
	stuYearStanding = ugs->getYearStanding();

}

Application* UndergradApp::getCopy(){
	return (new UndergradApp(*this));//return a copy of this class
}

string UndergradApp::compareValue(){
	stringstream ss;
	string s;
	s = "" + getStuMGPA();
	ss << getStuMGPA();//add the int to the string
	cout << "---THE COMPARE VALUE OF " << getStuFirst() << " IS: " << s <<endl;
	return s;
}


UndergradApp::~UndergradApp(){}
/*
UndergradApp::UndergradApp(UndergradApp& ua){
	//////////////////////COPY CTOR//////////////////////
	applicationNumber = ua.getApplicationNumber();
    course 	= ua.getCourse();
    applicationStatus = ua.getAppStatus();
	
 	stuFirst = ua.getStuFirst();
	stuLast = ua.getStuLast();
	stuEmail = ua.getStuEmail();
	stuID = ua.getStuID();
	stuCGPA = ua.getStuCGPA();
	stuMGPA = ua.getStuMGPA();
	stuMajor = ua.getStuMajor();
	stuYearStanding = ua.getStuYrStanding();
}
*/
//==============================GETTERS==========================================

int      UndergradApp::getStuCGPA(){ return stuCGPA; }
int      UndergradApp::getStuMGPA(){ return stuMGPA; }
string   UndergradApp::getStuMajor(){ return stuMajor; }
int      UndergradApp::getStuYrStanding(){ return stuYearStanding; }
string   UndergradApp::getStuFirst(){ return stuFirst; }
string   UndergradApp::getStuLast(){ return stuLast; }
string   UndergradApp::getStuEmail(){ return stuEmail; }
string   UndergradApp::getCourse(){ return course; }
string   UndergradApp::getStuID(){ return stuID; }
int      UndergradApp::getApplicationNumber(){ return applicationNumber; }
string   UndergradApp::getAppStatus(){ return applicationStatus; }

string 	 UndergradApp::getSummaryString(){
	string s1, s2, s3, s4, s5, s6, s7, s8, summary;
	std::stringstream ss1; 
	std::stringstream ss2; 
	std::stringstream ss3;
	s1 = getStuFirst();
	s2 = getStuLast();
				 
	ss1 << getStuYrStanding();
	s3 = ss1.str();
	s4 = getStuMajor();
	ss2 << getStuCGPA();
	s5 = ss2.str();
	s6 = getStuEmail();
	s7 = getStuID();
	ss3 << getStuMGPA();
	s8 = ss3.str();
	summary = "Course: " + course + " Undergrad: " + s1 + " " + s2 + " in Year: " + s3 + "  |  Major: " + s4 + "  |  CGPA: " + s5  + "  |  GPA:  " + s8 + "  |  Email: " + s6 + "  |  ID: " + s7;
	return summary;
}


//bool compare(GradApp* app){

//}

//bool compare(UndergradApp* app){

//}


bool UndergradApp::saveSummary(){
	
	int i;
	int rlCS = relatedCourses->size();
	
	
	
	//int rlTAS = relatedTAPositions->size();
	//int rlWS = relatedWorkEXP->size();
	//there.


	//Course tempCourse;
	string fileName = applicationNumber + ".txt";

    ofstream outFile("fileName", ios::out|ios::app);

    if (!outFile) {
            cout<<"Could not open file"<<endl;
            return false;
    }

	outFile << "UnderGraduate Application:" << endl;
	outFile << "Application Number: " << applicationNumber << endl;
	outFile << "Course: " << course << endl;
	outFile << "Application Status: " << applicationStatus << endl;
	outFile << "Student CGPA: " << stuCGPA << endl;
	outFile << "Student GPA: " << stuMGPA << endl;
	outFile << "First Name: " << stuFirst << endl;
	outFile << "Last Name: " << stuLast << endl;
	outFile << "Email: " << stuEmail << endl;
	outFile << "Major: " << stuMajor << endl;
	outFile << "Current year Standing: " << stuYearStanding << endl;
	outFile << "Student ID: " << stuID << endl;
	

	//Save the Application data:	
	

	int aSize;

	Queue<Course> tempQ(*relatedCourses);
	//Save the related courses for undergraduates:

	outFile << "Related Courses: " << endl <<endl;
	cout << "SIZE OF tempQ: " << aSize << endl; 
	int cSize = relatedCourses->size();
	for(i=0; i < cSize; i++){
		outFile << "Related Course " << i << ":" << endl;
		outFile << "Title: " << tempQ.front()->getTitle() << endl;
		outFile << "Final Grad: " << tempQ.front()->getFinal() << endl;
		outFile << "Year: " << tempQ.front()->getYear() << endl;
		outFile << "Term: " << tempQ.front()->getTerm() << endl;
		tempQ.popFront();
	}
	
	

	//Save the related TA positions:
	outFile << "Related TA Positions:" << endl <<endl; // header	

	Queue<Course> otherTemp(*relatedTAPositions);
	aSize = otherTemp.size();
	for(i=0; i < aSize; i++){
		outFile << "Related TA Position " << i << ":" <<endl;
		outFile << "Title: " << otherTemp.front()->getTitle() << endl;
		outFile << "Supervisor: " << otherTemp.front()->getSupervisor() << endl;
		outFile << "Year: " << otherTemp.front()->getYear() << endl;
		outFile << "Term: " << otherTemp.front()->getTerm() << endl;
		otherTemp.popFront();
	}

	//Save related work EXP
	outFile << "Related Work Experience" << endl <<endl; //header

	Queue<Job> tempJQueue(*relatedWorkEXP);
	aSize = tempJQueue.size();
	for(i=0; i < aSize; i++){
		outFile << "Related Job " << i << ":" <<endl;
		outFile << "Title: " << tempJQueue.front()->getJobTitle() << endl;
		outFile << "Tasks: " << tempJQueue.front()->getTasks() << endl;
		outFile << "Duration : " << tempJQueue.front()->getDuration() << endl;
		outFile << "Start Date: " << tempJQueue.front()->getStartDate() << endl;
		outFile << "End Date: " << tempJQueue.front()->getEndDate() << endl;
		tempJQueue.popFront();
	}
	

}


bool UndergradApp::printApp(bool append,bool rCourses, bool rTA, bool rWorkExp){
	//Application::printApp();

	

	ofstream outFile("Applications.txt", ios::out|ios::app);

    if (!outFile) {
            //ios::out<<"Could not open file"<<endl;
            return false;
    }
    outFile << "underGrad" << endl;
	outFile << applicationNumber << endl;
	outFile << course << endl;
	outFile << applicationStatus << endl;
	outFile << stuCGPA << endl;
	outFile << stuMGPA << endl;
	outFile << stuFirst << endl;
	outFile << stuLast << endl;
	outFile << stuEmail << endl;
	outFile << stuMajor << endl;
	outFile << stuYearStanding << endl;
	outFile << stuID << endl;

	int aSize;
	int i;
	if(rCourses){
		//Save the related courses for undergraduates:
		cout << "SAVING RELATED COURSES: " << endl;
		Queue<Course> tempQ(*relatedCourses);
		aSize = tempQ.size();
		cout << "SIZE OF tempQ: " << aSize << endl; 
		for(i=0; i < aSize; i++){
			cout << "Inside for loop! i is: " << i <<  endl;
			cout << "And tempQ.size is: " << tempQ.size() << endl;
			outFile << tempQ.front()->getTitle() << endl;
			outFile << tempQ.front()->getFinal() << endl;
			outFile << tempQ.front()->getYear() << endl;
			outFile << tempQ.front()->getTerm() << endl;
			tempQ.popFront();
		}
	}else if(!rCourses){

	}
	if(rTA){
		//Save the related TA positions:
		outFile << "RELATEDTAPOSITIONS" << endl; // header	

		Queue<Course> otherTemp(*relatedTAPositions);
		aSize = otherTemp.size();
		for(i=0; i < aSize; i++){
			outFile << otherTemp.front()->getTitle() << endl;
			outFile << otherTemp.front()->getSupervisor() << endl;
			outFile << otherTemp.front()->getYear() << endl;
			outFile << otherTemp.front()->getTerm() << endl;
			otherTemp.popFront();
		}
	}else if(!rTA){
		outFile << "RELATEDTAPOSITIONS" << endl; // header	
		//outFile << "NONE" << endl; // header	
	}
	if(rWorkExp){
		//Save related work EXP
		outFile << "WORKEXP" << endl; //header

		Queue<Job> tempJQueue(*relatedWorkEXP);
		aSize = tempJQueue.size();
		for(i=0; i < aSize; i++){
			outFile << tempJQueue.front()->getJobTitle() << endl;
			outFile << tempJQueue.front()->getTasks() << endl;
			outFile << tempJQueue.front()->getDuration() << endl;
			outFile << tempJQueue.front()->getStartDate() << endl;
			outFile << tempJQueue.front()->getEndDate() << endl;
			tempJQueue.popFront();
		}
	}else if(!rWorkExp){
		outFile << "WORKEXP" << endl; //header
		//outFile << "NONE" << endl; //header
	}
	outFile << "ENDAPP" << endl;
}

void UndergradApp::setRelatedCourses(Queue<Course> *queue){
	relatedCourses = queue;
	
}


bool UndergradApp::printModifiedApp(ofstream& outFile){
	

    if (!outFile) {
            //ios::out<<"Could not open file"<<endl;
            return false;
    }
    outFile << "underGrad" << endl;
	outFile << applicationNumber << endl;
	outFile << course << endl;
	outFile << applicationStatus << endl;
	outFile << stuCGPA << endl;
	outFile << stuMGPA << endl;
	outFile << stuFirst << endl;
	outFile << stuLast << endl;
	outFile << stuEmail << endl;
	outFile << stuMajor << endl;
	outFile << stuYearStanding << endl;
	outFile << stuID << endl;

	int aSize;
	int i;
	if(relatedCourses !=NULL){
		//Save the related courses for undergraduates:
		cout << "SAVING RELATED COURSES: " << endl;
		Queue<Course> tempQ(*relatedCourses);
		aSize = tempQ.size();
		cout << "SIZE OF tempQ: " << aSize << endl; 
		for(i=0; i < aSize; i++){
			cout << "Inside for loop! i is: " << i <<  endl;
			cout << "And tempQ.size is: " << tempQ.size() << endl;
			outFile << tempQ.front()->getTitle() << endl;
			outFile << tempQ.front()->getFinal() << endl;
			outFile << tempQ.front()->getYear() << endl;
			outFile << tempQ.front()->getTerm() << endl;
			tempQ.popFront();
		}
	}else if(relatedCourses ==NULL){

	}
	if(relatedTAPositions != NULL){
		//Save the related TA positions:
		outFile << "RELATEDTAPOSITIONS" << endl; // header	

		Queue<Course> otherTemp(*relatedTAPositions);
		aSize = otherTemp.size();
		for(i=0; i < aSize; i++){
			outFile << otherTemp.front()->getTitle() << endl;
			outFile << otherTemp.front()->getSupervisor() << endl;
			outFile << otherTemp.front()->getYear() << endl;
			outFile << otherTemp.front()->getTerm() << endl;
			otherTemp.popFront();
		}
	}
	else if(relatedTAPositions == NULL){
		outFile << "RELATEDTAPOSITIONS" << endl; // header	
	}
	if(relatedWorkEXP !=NULL){
		//Save related work EXP
		outFile << "WORKEXP" << endl; //header

		Queue<Job> tempJQueue(*relatedWorkEXP);
		aSize = tempJQueue.size();
		for(i=0; i < aSize; i++){
			outFile << tempJQueue.front()->getJobTitle() << endl;
			outFile << tempJQueue.front()->getTasks() << endl;
			outFile << tempJQueue.front()->getDuration() << endl;
			outFile << tempJQueue.front()->getStartDate() << endl;
			outFile << tempJQueue.front()->getEndDate() << endl;
			tempJQueue.popFront();
		}
	}
	else if(relatedWorkEXP ==NULL){

	}
	outFile << "ENDAPP" << endl;
}
bool UndergradApp::printApp(bool okay){

}