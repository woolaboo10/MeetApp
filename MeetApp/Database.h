#pragma once
#pragma once

#ifndef _DATABASE_H_
#define _DATABASE_H_

#include "User_Profile.h"


#define MAX_NO_PROFILES	1000

typedef enum DATABASE_STATUS_e
{
	dbstatus_ok = 0,
	dbstatus_error,
	dbstatus_invalid,
}DATABASE_STATUS_e;

typedef struct DATABASE_STRUCT_t
{
	DATABASE_STATUS_e Status;
	unsigned char DB_Initialised;
	unsigned int No_Profiles;
	USER_PROFILE_STRUCT_t Profile_Database[MAX_NO_PROFILES];

}DATABASE_STRUCT_t;





/*****************************************************************/
//
//	Function:		Db_Init
//	Inputs:			Pointer to a DATABASE_STRUCT_t structure
//	Returns:		status upon completion of function call
//	Description:	Called on startup to initialise all profiles 
//					in database to default, then set the intialised 
//					flag
//
/*****************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
	DATABASE_STATUS_e Db_Init(DATABASE_STRUCT_t* Database);
#ifdef __cplusplus
}
#endif


/*****************************************************************/
//
//	Function:		Db_AddProfile
//	Inputs:			1) Pointer to a DATABASE_STRUCT_t structure
//					2) profile to be added to the database
//	Returns:		status upon completion of function call
//	Description:	Function to add a profile to database
//
/*****************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
	DATABASE_STATUS_e Db_AddProfile(DATABASE_STRUCT_t* Database, USER_PROFILE_STRUCT_t Profile);
#ifdef __cplusplus
}
#endif




/*****************************************************************/
//
//	Function:		Db_RemoveProfile
//	Inputs:			1) Pointer to a DATABASE_STRUCT_t structure
//					2) profile to be removed from the database
//	Returns:		status upon completion of function call
//	Description:	Function to remove profile from database
//
/*****************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
	DATABASE_STATUS_e Db_RemoveProfile(DATABASE_STRUCT_t* Database, USER_PROFILE_STRUCT_t Profile);
#ifdef __cplusplus
}
#endif










#endif