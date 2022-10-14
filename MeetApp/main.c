#include <stdio.h>
#include "Database.h"


DATABASE_STRUCT_t MeetApp_DB;

USER_PROFILE_STRUCT_t Richard = {
									{
										"ruhegbu@hotmail.com",
										account_standard,
										status_Active
									},
									{
										"Richard",
										"Uhegbu",
										gender_male,
										ethnicity_black,
										35,
										175,
										100,
										"London",
										children_none,
									},
									{
										"Engineering",
										"Software Engineer",
										"London Southbank",
										education_undergrad,
										religion_agnostic,
										intention_notdisclosed,
									},
									{
											profile_no,
											profile_no,
											profile_no,
											profile_no,
									}
								};


void main(void)
{

	MeetApp_DB.Status = Db_Init(&MeetApp_DB);

	(MeetApp_DB.Status == dbstatus_ok) ? (printf("MeetApp Ready\n")) : (printf("MeetApp Not Ready\n"));

	MeetApp_DB.Status = Db_AddProfile(&MeetApp_DB, Richard);

	while (1);
}

