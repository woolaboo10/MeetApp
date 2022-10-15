#include "pch.h"
#include "CppUnitTest.h"
#include "Database.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

DATABASE_STRUCT_t Test_MeetApp_DB;

namespace MeetAppTest
{
	TEST_CLASS(MeetAppTest)
	{
	public:
		
		TEST_METHOD(DatabaseErrorInit)
		{
			Test_MeetApp_DB.Status = Db_Init(0);

			Assert::AreEqual((int)Test_MeetApp_DB.DB_Initialised, 0);
			Assert::AreEqual((int)Test_MeetApp_DB.Status, (int)dbstatus_error);
		}


		TEST_METHOD(DatabaseInit)
		{
			unsigned int loop = 0;

			Test_MeetApp_DB.Status = Db_Init(&Test_MeetApp_DB);

			Assert::AreEqual((int)Test_MeetApp_DB.DB_Initialised, 1);
			Assert::AreEqual((int)Test_MeetApp_DB.No_Profiles, 0);
			Assert::AreEqual((int)Test_MeetApp_DB.Status, (int)dbstatus_ok);

			for (loop = 0; loop < MAX_NO_PROFILES; loop++)
			{
				Assert::AreEqual((const char*)Test_MeetApp_DB.Profile_Database->Admin_Info.Email, "");
				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Admin_Info.Account_Type, (int)account_standard);
				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Admin_Info.Account_Status, (int)status_deleted);

				Assert::AreEqual((const char*)Test_MeetApp_DB.Profile_Database[loop].Personal_Details.Name, "");
				Assert::AreEqual((const char*)Test_MeetApp_DB.Profile_Database[loop].Personal_Details.Surname, "");
				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Personal_Details.Gender, (int)gender_male);
				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Personal_Details.Ethnicity, (int)ethnicity_black);
				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Personal_Details.Age, 0);
				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Personal_Details.Height, 0);
				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Personal_Details.Weight, 0);
				Assert::AreEqual((const char*)Test_MeetApp_DB.Profile_Database[loop].Personal_Details.Location, "");
				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Personal_Details.Children, (int)children_none);				

				Assert::AreEqual((const char*)Test_MeetApp_DB.Profile_Database[loop].Life_Details.Work_Sector, "");
				Assert::AreEqual((const char*)Test_MeetApp_DB.Profile_Database[loop].Life_Details.Job_Title, "");
				Assert::AreEqual((const char*)Test_MeetApp_DB.Profile_Database[loop].Life_Details.School, "");
				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Life_Details.Education_level, (int)education_highschool);
				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Life_Details.Religion, (int)religion_notdisclosed);
				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Life_Details.Intention, (int)intention_notdisclosed);				

				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Beliefs.Drinking, (int)profile_no);
				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Beliefs.Smoking,(int)profile_no);
				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Beliefs.Marijuana,(int)profile_no);
				Assert::AreEqual((int)Test_MeetApp_DB.Profile_Database[loop].Beliefs.Drugs, (int)profile_no);
			}
		}




	};
}
