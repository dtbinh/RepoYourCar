#ifndef WINDOWAPP_H
#define WINDOWAPP_H
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>
#include "../Model/Student.h"
#include "../Model/Application.h"
#include "../Model/Course.h"

#include "../Model/Queue.h"
#include "AdminManager.h"
#include "MainMenu.h"
#include "GradAppPage.h"
#include "UnderGradAppPage.h"
#include "StudentPage.h"
#include "AppManager.h"
#include "../Model/GradAppData.h"
#include "../Model/UGradAppData.h"
class UnderGradApp;

#include "../Model/Student.h"
#include "../Model/GradStudent.h"
#include "../Model/UndergradStudent.h"
#include "../Model/GradApp.h"
#include "../Model/UndergradApp.h"
//
//#include <String.h>

using namespace std;
class Control;
class MainMenu;
class GradAppPage;
class UnderGradAppPage;
class GradSubmitWindow;
class UGradSubmitWindow;
class AppManager;
class StudentPage;
class WindowApp;
class WindowApp{
	public:
		friend class Control;
		friend class AppManager;
		friend class GradAppPage;
		friend class UnderGradAppPage;
		friend class RelatedCoursesTwoForm;
		friend class RelatedCoursesOneForm;
		friend class WorkExperienceForm;
		friend class AdminWindow;
		friend class AdminPage;
		friend class StudentPage;
		friend class GradErrorCheck;
		friend class UGradErrorCheck;
		friend class GradSubmitWindow;
		friend class UGradSubmitWindow;
		friend class GradForm;
		friend class UnderGradForm;

		//Control Control;
	/*	GtkWidget *label, *info_label, *window, *frame, *apply, *login, *appFrame, *fName, *lblfName, *lName, *lbllName, *major, *lblMajor, *gpa, *lblGpa, *cgpa, *lblCgpa, *stuNum,*lblstuNum, *email, *lblEmail, *year, *lblYear, *submit, *cancel, *combo,  *ei_relatedCourse1, *ei_relatedCourse2, *ei_term1, *ei_term2, *ei_year1, *ei_year2, *ei_finalGrade, *ei_supervisor, *ei_relevantWork, *ei_responsabilities, *ei_duration, *ei_startDate, *ei_endDate, *ei_continue, *ei_continue2, *ei_repeat, *ei_repeat2, *ei_repeat3, *ei_finish, *ei_lblRelatedCourse, *ei_lblTerm, *ei_lblYear, *ei_lblFinalGrade, *ei_lblSupervisor, *ei_lblRelevantWork, *ei_lblDuration, *ei_lblStartDate, *ei_lblEndDate, *ei_lblResponsabilities
			,*lblpickCourse, *lblpickArea, *lblpickProgram;

		GtkWidget *submitWindow, *submitFrame, *submitRepeat, *error_window, *error_frame, *error_dismiss, *error_message;
		
		GtkWidget *student_window, *student_frame, *submitFinish, *student_edit, *student_cancel, *student_apply, *btnStudent,*admin_window,*admin_combo, *admin_frame, *admin_cancel , *admin_viewSummary, *admin_login, *summary_combo;
		
		GtkWidget *grad_research, *grad_research_combo, *grad_sup, *grad_program_combo, *grad_apply, *lbl_grad_sup;

		GtkWidget *summary_choice_window, *summary_choice_frame, *btnOneCourse, *btnAllCourses, *summaryMessage;
		*/
		Application *studentApp;
		Course *studentCourse;
		Queue<Course> *cQRelated, *cQTa;
		Queue<Job> *jQRelated;

		Queue<Application> appQueue, *cycle;
		int blockID, blockID2, blockID3;

		Application *originalApp;
		static WindowApp *instance;

		bool moveOn;
		bool checkGood;
		bool extra;
		int page;
		bool gradApp;
		bool allCourses;
		bool editGMode;
		bool editUMode;
		bool canEdit;
		bool canCycle;
		static int applicationNum; 		
		/*WindowApp();
		~WindowApp();*/
		void setfName(string);
		void setlName(string);
		void setMajor(string);
		void setGpa(string);
		void setEmail(string);
		void setYear(string);
		void setCgpa(string);
		void setStuNum(string);

		string getfName();
		string getlName();
		string getMajor();
		string getGpa();
		string getEmail();
		string getYear();
		string getStuNum();
		string getCgpa();
		int cycler;
		int cyclerSize;
		bool cyclerTypes[100];

		int currAppNumber;
	private:
		string strfName, strlName, strMajor, strGpa, strCgpa, strEmail, strYear, strStuNum;
		MainMenu *main;
		//GradAppPage *gradPage;
		//UnderGradAppPage *underPage;
		StudentPage *stuPage;
		AppManager *appMan;
		GradAppPage *gradAppPage;
		//GradForm *gradForm;
		GradSubmitWindow *gSubmitWindow;
		UGradSubmitWindow *uSubmitWindow;
		UnderGradAppPage *uGradAppPage;
		Application *editApp;
		GradApp *editGApp;
		UndergradApp *editUApp;

		GtkWidget *killThisWindow;
		//UnderGradForm *uGradForm;
		
	protected:
		static void adminPage(GtkWidget*, WindowApp*);
		static void viewSummary(GtkWidget*, WindowApp*);
		static void viewSummaryChoice(GtkWidget*, WindowApp*);
		static void mainMenu(GtkWidget*, WindowApp*);
		static void popWindow(string, WindowApp*);
		static void closePopWindow(GtkWidget*, WindowApp*);
		static void closeAdminPage(GtkWidget*, WindowApp*);
		static void closeStudentPage(GtkWidget*, WindowApp*);
		static void closeSummaryChoice(GtkWidget*, WindowApp*);
		static void studentPage(GtkWidget*, WindowApp*);
		static int makeApplication(GtkWidget*, WindowApp*);	
		static int makeGradApplication(GtkWidget*, WindowApp*);	
		static void updateCombo(GtkWidget*, WindowApp*);

		static void workExperience(GtkWidget *, WindowApp *);
		static void relatedCourses1(GtkWidget *, WindowApp *);
		static void relatedCourses2(GtkWidget *, WindowApp *);
		
		static void finishExtra(GtkWidget*,WindowApp*);
		static void submitToMain(GtkWidget*,WindowApp*);
				
		static void submitGradApp(WindowApp*);
		static void submitUGradApp(WindowApp*);
		static void editStudent(GtkWidget*,WindowApp*);

};

#endif
