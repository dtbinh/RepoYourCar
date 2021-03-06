#include "Control.h"
#include <iostream>
//#include "Queue.h"
//`pkg-config gtkmm-3.0 --cflags --libs`

using namespace std;
Application* apples;
int THIS_BUF = 1000;












//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
						//main form error checking
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Control::errorCheck(string* course, string* first, string* last, string* mgpa, string* gpa, string* email, string* year, string* major, string* stunum, string* areas, string* program, string* supervisor, WindowApp *theApp){

	bool good = true;
	int mg;
	int cg;
	int yr;
	unsigned invalidF = (*first).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-'");
	unsigned invalidL = (*last).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-'");
	unsigned invalidSup = (*supervisor).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-'");
	string stringToFind1("@carleton.ca");
	unsigned validChars1 = (*email).find(stringToFind1);
	unsigned invalidE = (*major).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ- ");
	unsigned validStu = (*stunum).find_first_not_of("0123456789");
	unsigned validGPA = (*gpa).find_first_not_of("0123456789");
	unsigned validCGPA = (*mgpa).find_first_not_of("0123456789");
	
	if(!theApp->gradApp){
		mg = atoi(mgpa->c_str());	
		cg = atoi(gpa->c_str());
		yr = atoi(year->c_str());

		if(mgpa->length() == 0){
			cout << "MGPA is empty" <<endl;
			WindowApp::popWindow("MGPA is empty", theApp);
			return !good;
		}
                
		else if(gpa->length() == 0){
			cout << "GPA is empty" <<endl;
			WindowApp::popWindow("GPA is empty", theApp);
			return !good;
		}

		else if(year->length() == 0){
			cout << "year is Empty" <<endl;
			WindowApp::popWindow("year is Empty", theApp);
			return !good;
		}
               
		else if(major->length() == 0){
			cout << "Major is Empty" <<endl;
			WindowApp::popWindow("Major is Empty", theApp);
			return !good;
		}
		else if (validGPA != string::npos) {
			cout << "You entered a non-alphabetical character, " << (*gpa)[validGPA];
			cout << ", at position " << validGPA << endl;
			
			WindowApp::popWindow("Please Enter a valid GPA", theApp);
			return !good;
		
  		}
		else if (validCGPA != string::npos) {
			cout << "You entered a non-alphabetical character, " << (*mgpa)[validCGPA];
			cout << ", at position " << validCGPA << endl;
				
			WindowApp::popWindow("Please Enter a valid CGPA", theApp);
			return !good;
			
	   	}
		
			
		else if(mg < 0 || mg > 12){
			WindowApp::popWindow("Enter a GPA between 0 and 12", theApp);
			return !good;
		}
		else if(cg < 0 || cg > 12){
			WindowApp::popWindow("Enter a CGPA between 0 and 12", theApp);
			return !good;
		}
		else if (yr < 1 || yr > 4) {
			cout << "Year standing must be either 1, 2, 3, or 4. Please try again" << endl; 
			WindowApp::popWindow("Year standing must be either 1, 2, 3, or 4.", theApp);
			return !good;
		}
		else if (invalidE != string::npos) {
			cout << "You entered a non-alphabetical character, " << (*major)[invalidE];
			cout << ", at position " << invalidE << endl;
			WindowApp::popWindow("You entered a non-alphabetical character in major", theApp);
			return !good;
   		}
	}
	if(theApp->gradApp){

		//string* areas, string* program, string* supervisor
		if(areas->length() == 0){
			cout << "Study Area is empty" <<endl;
			WindowApp::popWindow("Choose a main study area", theApp);
			return !good;
		
		}
		else if(program->length() == 0){
			cout << "Program is empty" <<endl;
			WindowApp::popWindow("Choose a program", theApp);
			return !good;
			
		}



	}
	

	if(course->length() == 0){
		cout << "Course is empty" <<endl;
		WindowApp::popWindow("Choose a course", theApp);
		return !good;
		
	}
		
	else if(first->length() == 0){
		cout << "First name is empty" <<endl;
		WindowApp::popWindow("First name is empty", theApp);
		return !good;
	}
                
		
	else if(last->length() == 0){
		cout << "Last Name is Empty" <<endl;
		WindowApp::popWindow("Last Name is Empty", theApp);
		return !good;
	}
                
	
                
	else if(email->length() == 0){
		cout << "Email is Empty" <<endl;
		WindowApp::popWindow("Email is Empty", theApp);
		return !good;
	}
                	
	
                
	else if(stunum->length() == 0){
		cout << "Student Number is Empty" <<endl;
		WindowApp::popWindow("Student Number is Empty", theApp);
		return !good;
	}

	
	
	
  
	else if (invalidF != string::npos) {
		cout << "You entered a non-alphabetical character, " << (*first)[invalidF];
		cout << ", at position " << invalidF << endl;
			
		WindowApp::popWindow("You entered a non-alphabetical character in first name", theApp);
		return !good;
		
   	}


	
  
	else if (invalidL != string::npos) {
		cout << "You entered a non-alphabetical character, " << (*last)[invalidL];
		cout << ", at position " << invalidL << endl;
		WindowApp::popWindow("You entered a non-alphabetical character in last name", theApp);
		return !good;
   	}

   	else if (invalidSup != string::npos) {
		cout << "You entered a non-alphabetical character, " << (*supervisor)[invalidSup];
		cout << ", at position " << invalidSup << endl;
		WindowApp::popWindow("You entered a non-alphabetical character in supervisor", theApp);
		return !good;
   	}


	

	else if (validChars1 == string::npos) {
		cout << "Invalid e-mail address. Please enter your Carleton e-mail address (yourname@carleton.ca) to register." << endl;
		WindowApp::popWindow("Invalid e-mail address. Please enter your Carleton e-mail address (yourname@carleton.ca) to register.", theApp);
		return !good;
	}

	
  
	


	
	else if (validStu != string::npos) {
		cout << "You entered a character which is not a number between 0-9: " << (*stunum)[validStu];
		cout << ", at position " << validStu << "Please re-enter your student number." << endl;
		WindowApp::popWindow("Your student number contains invalid characters", theApp);
		return !good;
    }

	else if ((*stunum).length() != 9) {
		cout << "A valid student number has exactly 9 characters. Please re-enter your student number." << endl;
		WindowApp::popWindow("A valid student number has exactly 9 characters.", theApp);
		return !good;
	}
	
	cout << "Its getting to here" << endl;


		

	

	return good;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
					//get info gets content from main text boxes
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int Control::getInfo(GtkWidget *widget, WindowApp *theApp){
	const gchar *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9;
	string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="", string10="", string11="", string12="";
	double c, g;
	int num;
	if(!theApp->gradApp){
		
		s1 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(theApp->combo));
		if(s1==NULL)
			s1="";
		s2 = gtk_entry_get_text(GTK_ENTRY(theApp->fName));
		
		s3 = gtk_entry_get_text(GTK_ENTRY(theApp->lName));
		s4 = gtk_entry_get_text(GTK_ENTRY(theApp->gpa));
		s5 = gtk_entry_get_text(GTK_ENTRY(theApp->cgpa));        
	    s6 = gtk_entry_get_text(GTK_ENTRY(theApp->email));
		s7 = gtk_entry_get_text(GTK_ENTRY(theApp->year));
		s8 = gtk_entry_get_text(GTK_ENTRY(theApp->major));
		s9 = gtk_entry_get_text(GTK_ENTRY(theApp->stuNum));
		string1 = (s1);
		string2 = (s2);
		string3 = (s3);
		string4 = (s4);
		string5 = (s5);
		string6 = (s6);
		string7 = (s7);
		string8 = (s8);
		string9 = (s9);
	}
	else{
		//const gchar *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9;
		//string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
		//
		
		s1 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(theApp->combo));
		if(s1==NULL)
			s1="";

		s2 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(theApp->grad_research_combo));
		if(s2==NULL)
			s2="";
		s3 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(theApp->grad_program_combo));
		if(s3==NULL)
			s3="";
		s4 = gtk_entry_get_text(GTK_ENTRY(theApp->fName));
		
		s5 = gtk_entry_get_text(GTK_ENTRY(theApp->lName));
		//s4 = gtk_entry_get_text(GTK_ENTRY(theApp->gpa));
		//s5 = gtk_entry_get_text(GTK_ENTRY(theApp->cgpa));        
	    s6 = gtk_entry_get_text(GTK_ENTRY(theApp->email));
		//s7 = gtk_entry_get_text(GTK_ENTRY(theApp->year));
		s7 = gtk_entry_get_text(GTK_ENTRY(theApp->grad_sup));
		s8 = gtk_entry_get_text(GTK_ENTRY(theApp->stuNum));
		string1 = (s1);
		string2 = (s4);
		string3 = (s5);
		//string4 = (s4);
		//string5 = (s5);
		string6 = (s6);
		string9 = (s8);
		string10 = (s2);
		string11 = (s3);
		string12 = (s7);
		//1 string* course, 2 string* first, 3 string* last, 4 string* mgpa, 
		//5 string* gpa, 6 string* email, 7 string* year, 8 string* major, 
		//9 string* stunum, 10 string* areas, 11 string* program, 12 string* supervisor, WindowApp *theApp

	}
	
	
        
	
    if (Control::errorCheck(&string1,&string2,&string3,&string4,&string5,&string6,&string7, &string8, &string9, &string10, &string11, &string12, theApp))
	{
		//Create a new student
		c = atof(s4);
		g = atof(s5);
		num = atoi(s7);




		/////////////////////////////////////////////////////
		//-----------Create new submission window -------////
		/////////////////////////////////////////////////////

		theApp->submitWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_position(GTK_WINDOW(theApp->submitWindow), GTK_WIN_POS_CENTER);
	
		gtk_window_set_default_size(GTK_WINDOW(theApp->submitWindow), 250, 100);
		gtk_window_set_title(GTK_WINDOW(theApp->submitWindow), "Submit Page");
	
	

		/////////////////////////////////////////////////////
		//-----------Add frame onto window---------------////
		/////////////////////////////////////////////////////
		theApp->submitFrame = gtk_fixed_new();
	

		gtk_container_add(GTK_CONTAINER(theApp->submitWindow), theApp->submitFrame);

		//submission page
		theApp->submitFinish = gtk_button_new_with_label("Finish");
		theApp->submitRepeat = gtk_button_new_with_label("Make Another");

	
		gtk_widget_set_size_request(theApp->submitFinish, 80, 35);
		gtk_fixed_put(GTK_FIXED(theApp->submitFrame), theApp->submitFinish, 30, 20);

	
		gtk_widget_set_size_request(theApp->submitRepeat, 80, 35);
		gtk_fixed_put(GTK_FIXED(theApp->submitFrame), theApp->submitRepeat, 150, 20);

		gtk_widget_show_all(theApp->submitWindow);

		g_signal_connect (theApp->submitFinish, "clicked", G_CALLBACK (Control::killSubmitWindow), theApp);
		g_signal_connect (theApp->submitRepeat, "clicked", G_CALLBACK (Control::submitToRepeat), theApp);

		Control::submit(&string1,&string2,&string3,c,g,&string6,num, &string8, &string9, &string10, &string11, &string12, theApp);
		
		//submit(string*, string*, string*, int, int, string*, int, string*);
	}
	
	return 0;
}

void Control::killSubmitWindow(GtkWidget *widget, WindowApp *theApp){
	gtk_widget_destroy(theApp->submitWindow);
	submitToMain(widget,theApp);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//submit application once error checking is done

//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Control::submit(string* course, string* first, string* last, int mgpa, int gpa, string* email, int year, string* major, string* stunum, string* area, string* program, string* supervisor, WindowApp *theApp){
	static int applicationNum = 1;

	Student* s ;
	//theApp->studentRepeat = s;
	GradStudent *gs = NULL;
	UndergradStudent *ugs = NULL;
	//Application *a;
	GradApp *ga = NULL;
	UndergradApp *uga = NULL;
	if(theApp->gradApp){
		cout << "pushing grad app" << endl;
		gs = new GradStudent(*first, *last, *email, *stunum, *area, *program, *supervisor);
		//a  = new Application(gs, ugs,applicationNum++, *course, "PENDING");
		ga = new GradApp(gs, applicationNum++, *course, "PENDING");
		ga->setRelatedTAPositions(theApp->cQTa);
		ga->setRelatedWorkEXP(theApp->jQRelated);
		theApp->appQueue.pushBack(ga, uga);
		if(!ga->printApp())
				return false;
	}
	else{
		cout << "pushing ugrad app" << endl;
		ugs = new UndergradStudent(gpa, mgpa, *first, *last, *email, *major, year, *stunum);
		//a  = new Application(gs, ugs, applicationNum++, *course, "PENDING");
		//uga = new UndergradApp(ugs, applicationNum++, *course, "PENDING");
		uga = new UndergradApp(ugs, applicationNum++, *course, "PENDING");
		uga->setRelatedCourses(theApp->cQRelated);
		uga->setRelatedTAPositions(theApp->cQTa);
		uga->setRelatedWorkEXP(theApp->jQRelated);
		theApp->appQueue.pushBack(ga, uga);
		if(!uga->printApp())
				return false;
	}
	//Application *a = new Application(s, applicationNum++, *course, "PENDING");
	
	
	//theApp->studentApp = a;
	//theApp->appQueue.pushBack(a);
	//theApp->appQueue.isEmpty();
	

	//Control::printApp(a);
	//if(!a->printApp(theApp->gradApp))
	//	return false;

	
	return true;
}

void Control::cancel(){
	exit(1);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
				//load the applications from a file
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Control::loadApplications(WindowApp *theApp){
	char text[80];

	ifstream inFile("Applications.txt", ios::in);

	//Variables used to build an application
	int     a, cgpa, mgpa, y;
	string  c, s, f, l, e, m, i, program, area, supervisor;
	bool aGrad;
	//CourseQueue *aCourseQueue = new CourseQueue();
	//CourseQueue *bCourseQueue = new CourseQueue();
	//JobQueue *jQueue = new JobQueue();	

	//Varibles used to build a course
	int cYear;
	string cSuper, cTitle, cTerm;	

	//Variables used to build a job
	string jTitle, jDuration, jStart, jEnd, jTasks;
	string anArray[100];
	
  	if (!inFile) {
    		cout<<"Could not open file"<<endl;
    		return;
  	}

	while (!inFile.eof()) {
		CourseQueue* relatedC = new CourseQueue();
		CourseQueue* relatedT = new CourseQueue();
		JobQueue*    relatedJ = new JobQueue();
		
		inFile.getline(text, THIS_BUF); // application type
		
		if (strlen(text) == 0){
			break;
		}		

		//if(strcmp(text, "ENDOFFILEMARKER") == 0){
	//		break;
	//	}

		if(strcmp(text, "underGrad") == 0)
		{	
			cout << "UNDERGRADUATE APP" << endl;
			aGrad = false;
			inFile.getline(text, THIS_BUF); // application number 
			 
			a = atoi(text);
			inFile.getline(text, THIS_BUF); // application course
			 
			c = text;
			inFile.getline(text, THIS_BUF); // application status
			 
			s = text;
			inFile.getline(text, THIS_BUF); // cGPA
			 
			cgpa = atoi(text);
			inFile.getline(text, THIS_BUF); // mGPA
			 
			mgpa = atoi(text);
			inFile.getline(text, THIS_BUF); // First Name
			 
			f = text;
			inFile.getline(text, THIS_BUF); // Last Name
			 
			l = text;
			inFile.getline(text, THIS_BUF); // Email
			 
			e = text;
			inFile.getline(text, THIS_BUF); // Major
			 
			m = text;
			inFile.getline(text, THIS_BUF); // Year Standing
			
			y = atoi(text);
			inFile.getline(text, THIS_BUF); // Student Number
			
			i = text;
				
		}
		else{
			aGrad = true;
			inFile.getline(text, THIS_BUF); // application number 
		
			a = atoi(text);
			inFile.getline(text, THIS_BUF); // application course
			
			c = text;
			inFile.getline(text, THIS_BUF); // application status
			
			s = text;
			inFile.getline(text, THIS_BUF); // program
			
			program = text;
			
			inFile.getline(text, THIS_BUF); // area
			
			area = text;
			inFile.getline(text, THIS_BUF); // First Name
			
			f = text;
			inFile.getline(text, THIS_BUF); // Last Name
			
			l = text;
			inFile.getline(text, THIS_BUF); // Email
			
			e = text;
			inFile.getline(text, THIS_BUF); // supervisor
			
			supervisor = text;
			inFile.getline(text, THIS_BUF); // Student Number
			
			i = text;
		}	
		
		//read an entire application
		
		
		

		//read the related courses
		
		
		if (!aGrad){
		
		while (1){ //untill you get to the TA positions
			inFile.getline(text, THIS_BUF);
			
			if(strcmp(text, "RELATEDTAPOSITIONS") == 0)
			{	
				
				break;
				
			}
			cTitle = text;

			
			inFile.getline(text, THIS_BUF);
			
			cSuper = text;
			inFile.getline(text, THIS_BUF);
					
			cYear = atoi(text);
			inFile.getline(text, THIS_BUF);
			
			cTerm = text;
			
			//make a course with the information and "N/A" supervisor
			Course *cor = new Course(cTitle, cYear, cTerm, "N/A", cSuper);
			
			relatedC->pushBack(cor);	
			
				
		}
		
		}
		else{
			inFile.getline(text, THIS_BUF); //be sure to read the header
		}			

		//read the related TA positions
		
		
		while (1){

			inFile.getline(text, THIS_BUF);			
				
					
			if(strcmp(text, "WORKEXP") ==0)
			{
				
				break;
				
			}
			
			cTitle = text;
			
			inFile.getline(text, THIS_BUF);
			
			cSuper = text;
			inFile.getline(text, THIS_BUF);
			
			cYear = atoi(text);
			inFile.getline(text, THIS_BUF);
			
			cTerm = text;
			//make a course with the information and "N/A" grade
			Course *bcor = new Course(cTitle, cYear, cTerm, cSuper, "N/A");
			relatedT->pushBack(bcor);	
			
		}
		//read the related Work EXP
		
		while (1){
			inFile.getline(text, THIS_BUF);
					
			if(strcmp(text, "ENDAPP") ==0)
			{
				
				break;
				
			}
			
			jTitle = text;
			inFile.getline(text, THIS_BUF);
			jTasks = text;
			
			inFile.getline(text, THIS_BUF);
			jDuration = text;
			
			inFile.getline(text, THIS_BUF);
			jStart = text;
			
			inFile.getline(text, THIS_BUF);
			jEnd = text;
			

			Job *aJob = new Job(jTitle, jTasks, jDuration, jStart, jEnd);
			relatedJ->pushBack(aJob);
			
		}

		//NOW initialise an application
		
		GradApp *ga = NULL;
		UndergradApp *uga = NULL;
		if(aGrad){
			GradStudent *stu = new GradStudent(f, l, e, i, area, program, supervisor);
			ga = new GradApp(stu, a,c,s);
			ga->setRelatedTAPositions(relatedT);
			ga->setRelatedWorkEXP(relatedJ);
			theApp->appQueue.pushBack(ga, uga);
		}
		else{
			
			UndergradStudent *stu = new UndergradStudent(cgpa, mgpa, f, l, e, m, y, i);
			uga = new UndergradApp(stu,a,c,s);
			uga->setRelatedCourses(relatedC);
			uga->setRelatedTAPositions(relatedT);
			uga->setRelatedWorkEXP(relatedJ);
			theApp->appQueue.pushBack(ga, uga);
		}
		
			
  	}
 
}













void Control::moveOn(GtkWidget *widget, WindowApp *theApp){
	theApp->moveOn = true;
	quickCheck(widget,theApp); //checks if the app can move on to next page

}
void Control::moveOn2(GtkWidget *widget, WindowApp *theApp){
	theApp->moveOn = true;
	quickCheck2(widget,theApp);

}
void Control::moveOn3(GtkWidget *widget, WindowApp *theApp){
	theApp->moveOn = true;
	quickCheck3(widget,theApp);

}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//quick check: check if the extra info boxes are empty and other error checking
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Control::quickCheck(GtkWidget *widget, WindowApp *theApp){
	

	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
	
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_relatedCourse1));
	
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_year1));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_term1));
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_finalGrade));        
      
	string1 = (s1);
	string2 = (s2);
	
	string3 = (s3);
	string4 = (s4);
	if(string1 != "" && string2 != "" && string3 != "" && string4 != ""){
		
		theApp->checkGood = true;
		gtk_widget_set_sensitive(theApp->ei_continue, TRUE);
		gtk_widget_set_sensitive(theApp->ei_repeat, TRUE);
		
		if(theApp->moveOn){
			int yr = atoi(string2.c_str());
			unsigned validRC1 = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  			unsigned validterm1 = (string3).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned grade = (string4).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			
			if (validRC1 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string1)[validRC1];
				cout << ", at position " << validRC1 << endl;
				WindowApp::popWindow("You entered a non-alphabetical character in Related Courses", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}
			
  
			else if (validterm1 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string3)[validterm1];
				cout << ", at position " << validterm1 << endl;
				WindowApp::popWindow("You entered a non-alphabetical character in term", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			
			else if (grade != string::npos) {
				cout << "Please Enter a Letter Grade" << endl;
				WindowApp::popWindow("Please Enter a Letter Grade", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}


			else if (yr < 1990 || yr > 2013) {
				cout << "Year must be between 1990 and 2013" << endl; 
				WindowApp::popWindow("Year must be between 1990 and 2013", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
			}
			
			if(theApp->checkGood){
				Course* cor = new Course(string1, yr, string3, "N/A", string4);
				//theApp->cQRelated = new CourseQueue();
				theApp->cQRelated->pushBack(cor);
				theApp->moveOn = false;
				WindowApp::relatedCourses2(widget, theApp);
			}
		}
		
		
	}
}

void Control::quickCheck2(GtkWidget *widget, WindowApp *theApp){
	

	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
	
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_relatedCourse2));
	
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_year2));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_term2));
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_supervisor));        
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);
	if(string1 != "" && string2 != "" && string3 != "" && string4 != ""){
		theApp->checkGood = true;
		gtk_widget_set_sensitive(theApp->ei_continue2, TRUE);
		gtk_widget_set_sensitive(theApp->ei_repeat2, TRUE);
		if(theApp->moveOn){
			int yr = atoi(string2.c_str());


			unsigned validRC2 = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned validterm2 = (string3).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned supervisor = (string4).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  
			if (validRC2 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string1)[validRC2];
				cout << ", at position " << validRC2 << endl;
				WindowApp::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}
			
  
			else if (validterm2 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string3)[validterm2];
				cout << ", at position " << validterm2 << endl;
				WindowApp::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			
			else if (supervisor != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string4)[supervisor];
				cout << ", at position " << supervisor << endl;
				WindowApp::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
				
		   	}


			else if (yr < 1990 || yr > 2013) {
				cout << "Year must be between 1990 and 2013" << endl; 
				WindowApp::popWindow("Year must be between 1990 and 2013", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
				
			}

			if(theApp->checkGood){
				Course* cor = new Course(string1, yr, string3, string4, "N/A");
			
				//theApp->cQTa = new CourseQueue();
				theApp->cQTa->pushBack(cor);

				theApp->moveOn = false;
				WindowApp::workExperience(widget, theApp);
			}
		}
		
		
	}
}

void Control::quickCheck3(GtkWidget *widget, WindowApp *theApp){
	

	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="";
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_relevantWork));
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_responsabilities));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_duration)); 
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_startDate));
	s5 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_endDate));
	       
	  
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);
	string5 = (s5);
	if(string1 != "" && string2 != "" && string3 != "" && string4 != ""&& string5 != ""){
		gtk_widget_set_sensitive(theApp->ei_finish, TRUE);
		gtk_widget_set_sensitive(theApp->ei_repeat3, TRUE);
		theApp->checkGood = true;
		if(theApp->moveOn){
			


			unsigned validRW = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned validresp = (string2).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned validdur = (string3).find_first_not_of("0123456789");
			unsigned startDate = (string4).find_first_not_of("0123456789/");
			unsigned endDate = (string5).find_first_not_of("0123456789/");
			//string startYear = "00";
  
			if (validRW != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string1)[validRW];
				cout << ", at position " << validRW << endl;
				WindowApp::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}
			
  
			else if (validresp != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string2)[validresp];
				cout << ", at position " << validresp << endl;
				WindowApp::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}
			
			else if (validdur != string::npos) {
				cout << "Enter # of months" << (string3)[validdur];
				//cout << ", at position " << validdur << endl;
				WindowApp::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			
			else if (startDate != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string4)[startDate];
				cout << ", at position " << startDate << endl;
				WindowApp::popWindow("Wrong Format for Start Date", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			
			else if (endDate != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string5)[endDate];
				cout << ", at position " << endDate << endl;
				WindowApp::popWindow("Wrong Format for End Date", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			if(theApp->checkGood){
				Job* job = new Job(s1, s2, s3, s4, s5);
				//theApp->jQRelated = new JobQueue();
				theApp->jQRelated->pushBack(job);

				theApp->moveOn = false;
				finishExtra(widget, theApp);
			}
		}
		
	}
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//when the user wants to continue to next set of extra info and finish
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Control::finishExtra(GtkWidget *widget, WindowApp *theApp){
		
	
	/////////////////////////////////////////////////////
	//-----------Remove Old Labels and text entires--////
	/////////////////////////////////////////////////////
	gtk_widget_destroy(theApp->ei_lblRelevantWork);
	gtk_widget_destroy(theApp->ei_lblDuration);
	gtk_widget_destroy(theApp->ei_lblStartDate);
	gtk_widget_destroy(theApp->ei_lblEndDate);
	gtk_widget_destroy(theApp->ei_lblResponsabilities);
	
	gtk_widget_destroy(theApp->ei_finish);
	gtk_widget_destroy(theApp->ei_repeat3);
	gtk_widget_destroy(theApp->ei_relevantWork);
	gtk_widget_destroy(theApp->ei_responsabilities);
	gtk_widget_destroy(theApp->ei_duration);
	gtk_widget_destroy(theApp->ei_startDate);
	gtk_widget_destroy(theApp->ei_endDate);

	gtk_window_resize(GTK_WINDOW(theApp->window), 400,600);
	gtk_widget_set_sensitive(theApp->submit, TRUE);
	theApp->extra =false;

}








//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//add another: user chooses to add another set of extra info
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Control::addAnother(GtkWidget *widget, WindowApp *theApp){
	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="";
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_relatedCourse1));
	
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_year1));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_term1));
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_finalGrade)); 
	       
	  
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);

	if(string1 != "" && string2 != "" && string3 != "" && string4 != ""){
		cout << "Checking this right hre2" << endl;
		theApp->checkGood = true;
		gtk_widget_set_sensitive(theApp->ei_continue, TRUE);
		gtk_widget_set_sensitive(theApp->ei_repeat, TRUE);
		
		
			cout << "Checking this right hre3" << endl;
			int yr = atoi(string2.c_str());
			unsigned validRC1 = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  			unsigned validterm1 = (string3).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned grade = (string4).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			cout << "Checking this right hre" << endl;
			if (validRC1 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string1)[validRC1];
				cout << ", at position " << validRC1 << endl;
				WindowApp::popWindow("You entered a non-alphabetical character in Related Courses", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}
			
  
			else if (validterm1 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string3)[validterm1];
				cout << ", at position " << validterm1 << endl;
				WindowApp::popWindow("You entered a non-alphabetical character in term", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			
			else if (grade != string::npos) {
				cout << "Please Enter a Letter Grade" << endl;
				WindowApp::popWindow("Please Enter a Letter Grade", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}


			else if (yr < 1990 || yr > 2013) {
				cout << "Year must be between 1990 and 2013" << endl; 
				WindowApp::popWindow("Year must be between 1990 and 2013", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
			}
			
			if(theApp->checkGood){
			int yr = atoi(string2.c_str());
			Course* cor = new Course(string1, yr, string3, "N/A", string4);
			theApp->cQRelated->pushBack(cor);
			

			gtk_entry_set_text(GTK_ENTRY(theApp->ei_relatedCourse1), "");
			gtk_entry_set_text(GTK_ENTRY(theApp->ei_year1), "");
			gtk_entry_set_text(GTK_ENTRY(theApp->ei_term1), "");
			gtk_entry_set_text(GTK_ENTRY(theApp->ei_finalGrade), "");

			gtk_widget_set_sensitive(theApp->ei_continue, FALSE);

			gtk_widget_set_sensitive(theApp->ei_repeat, FALSE);

			gtk_widget_set_sensitive(theApp->ei_repeat, FALSE);
		}
		
		
		
	}










	


}

void Control::addAnother2(GtkWidget *widget, WindowApp *theApp){
	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="";
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_relatedCourse2));
	
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_year2));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_term2));
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_supervisor));  
	       
	
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);

	if(string1 != "" && string2 != "" && string3 != "" && string4 != ""){
		theApp->checkGood = true;
		gtk_widget_set_sensitive(theApp->ei_continue2, TRUE);
		gtk_widget_set_sensitive(theApp->ei_repeat2, TRUE);
		
			int yr = atoi(string2.c_str());


			unsigned validRC2 = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned validterm2 = (string3).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned supervisor = (string4).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  
			if (validRC2 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string1)[validRC2];
				cout << ", at position " << validRC2 << endl;
				WindowApp::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}
			
  
			else if (validterm2 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string3)[validterm2];
				cout << ", at position " << validterm2 << endl;
				WindowApp::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			
			else if (supervisor != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string4)[supervisor];
				cout << ", at position " << supervisor << endl;
				WindowApp::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
				
		   	}


			else if (yr < 1990 || yr > 2013) {
				cout << "Year must be between 1990 and 2013" << endl; 
				WindowApp::popWindow("Year must be between 1990 and 2013", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
				
			}

			if(theApp->checkGood){
			int yr = atoi(string2.c_str());
			Course* cor = new Course(string1, yr, string3, "N/A", string4);
			theApp->cQTa->pushBack(cor);

			gtk_entry_set_text(GTK_ENTRY(theApp->ei_relatedCourse2), "");
			gtk_entry_set_text(GTK_ENTRY(theApp->ei_year2), "");
			gtk_entry_set_text(GTK_ENTRY(theApp->ei_term2), "");
			gtk_entry_set_text(GTK_ENTRY(theApp->ei_supervisor), "");
			gtk_widget_set_sensitive(theApp->ei_continue2, FALSE);
			gtk_widget_set_sensitive(theApp->ei_repeat2, FALSE);
		}
		
		
		
		
	}









	
	
}

void Control::addAnother3(GtkWidget *widget, WindowApp *theApp){
	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="";
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_relevantWork));
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_responsabilities));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_duration)); 
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_startDate));
	s5 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_endDate));
	       
	  
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);
	string5 = (s5);

	if(string1 != "" && string2 != "" && string3 != "" && string4 != ""&& string5 != ""){
		gtk_widget_set_sensitive(theApp->ei_finish, TRUE);
		gtk_widget_set_sensitive(theApp->ei_repeat3, TRUE);
		theApp->checkGood = true;
		
			


			unsigned validRW = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned validresp = (string2).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned validdur = (string3).find_first_not_of("0123456789");
			unsigned startDate = (string4).find_first_not_of("0123456789/");
			unsigned endDate = (string5).find_first_not_of("0123456789/");
			//string startYear = "00";
  
			if (validRW != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string1)[validRW];
				cout << ", at position " << validRW << endl;
				WindowApp::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}
			
  
			else if (validresp != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string2)[validresp];
				cout << ", at position " << validresp << endl;
				WindowApp::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}
			
			else if (validdur != string::npos) {
				cout << "Enter # of months" << (string3)[validdur];
				//cout << ", at position " << validdur << endl;
				WindowApp::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			
			else if (startDate != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string4)[startDate];
				cout << ", at position " << startDate << endl;
				WindowApp::popWindow("Wrong Format for Start Date", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			
			else if (endDate != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string5)[endDate];
				cout << ", at position " << endDate << endl;
				WindowApp::popWindow("Wrong Format for End Date", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			if(theApp->checkGood){
				Job* job = new Job(s1, s2, s3, s4, s5);
				theApp->jQRelated->pushBack(job);
				
				gtk_entry_set_text(GTK_ENTRY(theApp->ei_relevantWork), "");
				gtk_entry_set_text(GTK_ENTRY(theApp->ei_responsabilities), "");
				gtk_entry_set_text(GTK_ENTRY(theApp->ei_duration), "");
				gtk_entry_set_text(GTK_ENTRY(theApp->ei_startDate), "");
				gtk_entry_set_text(GTK_ENTRY(theApp->ei_endDate), "");

				gtk_widget_set_sensitive(theApp->ei_finish, FALSE);
				gtk_widget_set_sensitive(theApp->ei_repeat3, FALSE);
			}
		
		
	}



	
	
}






















//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
		//submission page : return to main menu
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Control::submitToMain(GtkWidget *widget,WindowApp *theApp){
	/*
	gtk_window_resize(GTK_WINDOW(theApp->window), 400,200);
	gtk_widget_destroy(theApp->fName);
	gtk_widget_destroy(theApp->lName);
	gtk_widget_destroy(theApp->major);
	gtk_widget_destroy(theApp->gpa);
	gtk_widget_destroy(theApp->cgpa);
	gtk_widget_destroy(theApp->email);
	gtk_widget_destroy(theApp->year);
	gtk_widget_destroy(theApp->stuNum);
	gtk_widget_destroy(theApp->lblfName);
	gtk_widget_destroy(theApp->lbllName);
	gtk_widget_destroy(theApp->lblMajor);
	gtk_widget_destroy(theApp->lblGpa);
	gtk_widget_destroy(theApp->lblCgpa);
	gtk_widget_destroy(theApp->lblEmail);
	gtk_widget_destroy(theApp->lblYear);
	gtk_widget_destroy(theApp->lblstuNum);
	gtk_widget_destroy(theApp->submit);
	gtk_widget_destroy(theApp->cancel);
	
	gtk_widget_destroy(theApp->combo);

	if(theApp->extra){
		if(theApp->page == 1){
			gtk_widget_destroy(theApp->ei_relatedCourse1);
			gtk_widget_destroy(theApp->ei_term1);
			gtk_widget_destroy(theApp->ei_year1);
			gtk_widget_destroy(theApp->ei_finalGrade);

			gtk_widget_destroy(theApp->ei_lblFinalGrade);
			gtk_widget_destroy(theApp->ei_lblRelatedCourse);
			
			gtk_widget_destroy(theApp->ei_lblTerm);
			gtk_widget_destroy(theApp->ei_lblYear);
			gtk_widget_destroy(theApp->ei_continue);
			gtk_widget_destroy(theApp->ei_repeat);
			gtk_widget_destroy(theApp->submitWindow);
		}
		else if(theApp->page == 2){
			gtk_widget_destroy(theApp->ei_relatedCourse2);
			gtk_widget_destroy(theApp->ei_term2);
			gtk_widget_destroy(theApp->ei_year2);
			gtk_widget_destroy(theApp->ei_supervisor);	
	
			gtk_widget_destroy(theApp->ei_lblRelatedCourse);
			gtk_widget_destroy(theApp->ei_lblSupervisor);
			gtk_widget_destroy(theApp->ei_lblTerm);
			gtk_widget_destroy(theApp->ei_lblYear);
			gtk_widget_destroy(theApp->ei_continue2);
			gtk_widget_destroy(theApp->ei_repeat2);
			gtk_widget_destroy(theApp->submitWindow);
		}
		else if(theApp->page == 3){
			gtk_widget_destroy(theApp->ei_lblRelevantWork);
			gtk_widget_destroy(theApp->ei_lblDuration);
			gtk_widget_destroy(theApp->ei_lblStartDate);
			gtk_widget_destroy(theApp->ei_lblEndDate);
			gtk_widget_destroy(theApp->ei_lblResponsabilities);
	
			gtk_widget_destroy(theApp->ei_finish);
			gtk_widget_destroy(theApp->ei_repeat3);
			gtk_widget_destroy(theApp->ei_relevantWork);
			gtk_widget_destroy(theApp->ei_responsabilities);
			gtk_widget_destroy(theApp->ei_duration);
			gtk_widget_destroy(theApp->ei_startDate);
			gtk_widget_destroy(theApp->ei_endDate);
			gtk_widget_destroy(theApp->submitWindow);

		}
		
	}
	*/
	gtk_widget_destroy(theApp->appFrame);
	WindowApp::mainMenu(widget,theApp);
	


}
		



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
		//submission page create another application
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Control::submitToRepeat(GtkWidget *widget,WindowApp *theApp){
	gtk_widget_set_sensitive(theApp->combo, TRUE);
	gtk_widget_hide(theApp->submitWindow);

}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//Create the Main Menu
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void Control::mainMenu(GtkWidget *widget, WindowApp *theApp){
	/////////////////////////////////////////////////////
	//-----------Create the window ------------------////
	/////////////////////////////////////////////////////
	

	gtk_window_resize(GTK_WINDOW(theApp->window), 400,200);

	


	/////////////////////////////////////////////////////
	//-----------Add frame onto window---------------////
	/////////////////////////////////////////////////////
	theApp->appFrame = gtk_fixed_new();
	theApp->admin_frame = gtk_fixed_new();

	gtk_container_add(GTK_CONTAINER(theApp->window), theApp->appFrame);


	/////////////////////////////////////////////////////
	//Make the application button and add to frame---////
	/////////////////////////////////////////////////////

	theApp->btnStudent = gtk_button_new_with_label("Student");
	gtk_widget_set_size_request(theApp->btnStudent, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->btnStudent, 50, 20);	

	theApp->apply = gtk_button_new_with_label("Apply");
	gtk_widget_set_size_request(theApp->apply, 80, 35);


	/////////////////////////////////////////////////////
	//------Make the login button and add to frame---////
	/////////////////////////////////////////////////////
	theApp->login = gtk_button_new_with_label("Admin");
	gtk_widget_set_size_request(theApp->login, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->login, 50, 80);


	
	
	/////////////////////////////////////////////////////
	//------Make the Prompt Label and add to frame---////
	/////////////////////////////////////////////////////
	theApp->label = gtk_label_new("Choose a Menu Option");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->label, 150, 58); 



	/////////////////////////////////////////////////////
	//----------Show all the widgets on the window---////
	/////////////////////////////////////////////////////
	theApp->moveOn = false;
	theApp->extra = false;
	gtk_widget_show_all(theApp->window);



	/////////////////////////////////////////////////////
	//Connect signals with each button as well as close////
	/////////////////////////////////////////////////////
	g_signal_connect(theApp->window, "destroy", G_CALLBACK (Control::cancel), theApp);

	g_signal_connect(theApp->btnStudent, "clicked", G_CALLBACK(WindowApp::studentPage), theApp);

	
	g_signal_connect(theApp->login, "clicked", G_CALLBACK(WindowApp::adminPage), theApp);

}
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
		//create the main window
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Control::createWindow(int argc, char** argv)
{
	cout << "In Control CreateWindow" <<endl;
	WindowApp *theApp = new WindowApp();
	theApp->cQRelated = new CourseQueue();
	theApp->cQTa = new CourseQueue();
	theApp->jQRelated = new JobQueue();
	
	// initialize GTK+
	gtk_init(&argc, &argv);
	theApp->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	loadApplications(theApp);
	cout << "app loaded" << endl;
	gtk_window_set_position(GTK_WINDOW(theApp->window), GTK_WIN_POS_CENTER);
	
	gtk_window_set_default_size(GTK_WINDOW(theApp->window), 400, 200);
	//gtk_window_resize(GTK_WINDOW(theApp->window), 600,300);
	gtk_window_set_title(GTK_WINDOW(theApp->window), "Main Menu");
	cout << "Calling WindowApp mani menu" <<endl;
	WindowApp::mainMenu(theApp->window, theApp);
	

	gtk_main();
	return 0;
}
