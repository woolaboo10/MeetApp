#include "Database.h"
#include <string.h>



/*****************************************************************/
//
//	Function:		Db_Init
//	Inputs:			Pointer to a DATABASE_STRUCT_t structure
//	Returns:		None
//	Description:	Called on startup to initialise all profiles 
//					in database to default, then set the intialised 
//					flag
//
/*****************************************************************/
DATABASE_STATUS_e Db_Init(DATABASE_STRUCT_t *Database)
{
	unsigned int loop = 0;

	//check for null pointer passed in
	if (Database == 0) 
	{
		return dbstatus_error;
	}


	//loop through setting defaults to each profile
	for (loop = 0; loop < MAX_NO_PROFILES; loop++)
	{
		memset(&Database->Profile_Database[loop], 0, sizeof(USER_PROFILE_STRUCT_t));
		Database->Profile_Database[loop].Admin_Info.Account_Status = status_deleted;
	}

	//set database as intialised
	Database->DB_Initialised = 1;

	return dbstatus_ok;
}



/*****************************************************************/
//
//	Function:		Db_AddProfile
//	Inputs:			1) Pointer to a DATABASE_STRUCT_t structure
//					2) profile to be added to the database
//	Returns:		status upon completion of function call
//	Description:	Function to add a profile to database
//
/*****************************************************************/
DATABASE_STATUS_e Db_AddProfile(DATABASE_STRUCT_t *Database, USER_PROFILE_STRUCT_t Profile)
{
	unsigned int loop = 0;
	unsigned char Empty_Slot_Found = 0;

	//check for null pointer passed in
	if (Database == 0)
	{
		return dbstatus_error;
	}

	//loop through checking for the first empty entry thus breaking loop
	for (loop = 0; loop < MAX_NO_PROFILES; loop++)
	{
		if (Database->Profile_Database[loop].Admin_Info.Account_Status == status_deleted)
		{
			Empty_Slot_Found = 1;
			break;
		}
	}


	if (Empty_Slot_Found)
	{
		//copy contents of profile to empty profile location
		memcpy(&Database->Profile_Database[loop], &Profile, sizeof(USER_PROFILE_STRUCT_t));
		return dbstatus_ok;
	}

	return dbstatus_invalid;
}



/*****************************************************************/
//
//	Function:		Db_RemoveProfile
//	Inputs:			1) Pointer to a DATABASE_STRUCT_t structure
//					2) profile to be removed from the database
//	Returns:		status upon completion of function call
//	Description:	Function to remove profile from database
//
/*****************************************************************/
DATABASE_STATUS_e Db_RemoveProfile(DATABASE_STRUCT_t *Database, USER_PROFILE_STRUCT_t Profile)
{
	unsigned int loop = 0;
	unsigned char Profile_found = 0;

	//check for null pointer passed in
	if (Database == 0)
	{
		return dbstatus_error;
	}

	//loop through to match the name and surname of profile to delete
	for (loop = 0; loop < MAX_NO_PROFILES; loop++)
	{
		if( (strcmp(Database->Profile_Database[loop].Personal_Details.Name, Profile.Personal_Details.Name) == 0)
			&& (strcmp(Database->Profile_Database[loop].Personal_Details.Surname, Profile.Personal_Details.Surname) == 0))
		{
			Profile_found = 1;
			break;
		}
	}

	//set the profile to default
	if (Profile_found)
	{
		memset(&Database->Profile_Database[loop], 0, sizeof(USER_PROFILE_STRUCT_t));
		Database->Profile_Database[loop].Admin_Info.Account_Status = status_deleted;

		return dbstatus_ok;
	}

	return dbstatus_invalid;
}