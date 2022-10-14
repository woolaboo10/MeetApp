#pragma once

#ifndef _USER_PROFILE_H_
#define _USER_PROFILE_H_

typedef enum USER_PROFILE_YES_NO_ENUM_e
{
	profile_no = 0,
	profile_yes,
	profile_notdisclosed,
}USER_PROFILE_YES_NO_ENUM_e;


typedef enum USER_PROFILE_GENDER_ENUM_e
{
	gender_male = 0,
	gender_female,
	gender_xy,
	gender_yx,
}USER_PROFILE_GENDER_ENUM_e;

typedef enum USER_PROFILE_ETHNICITY_ENUM_e
{
	ethnicity_black = 0,
	ethnicity_white,
	ethnicity_asian,
	ethnicity_eastasian,
	ethnicity_latino,
	ethnicity_other
}USER_PROFILE_ETHNICITY_ENUM_e;

typedef enum USER_PROFILE_EDUCATION_ENUM_e
{
	education_highschool = 0,
	education_undergrad,
	education_postgrad,
	education_notdisclosed,
}USER_PROFILE_EDUCATION_ENUM_e;


typedef enum USER_PROFILE_CHILDREN_ENUM_e
{
	children_none = 0,
	children_have,
	children_notdisclosed,
}USER_PROFILE_CHILDREN_ENUM_e;


typedef enum USER_PROFILE_RELIGION_ENUM_e
{
	religion_notdisclosed = 0,
	religion_agnostic,
	religion_buddhist,
	religion_christian,
	religion_hindu,
	religion_jewish,
	religion_muslim,
	religion_sikh,
	religion_spiritual,
	religion_other,
	religion_catholic
}USER_PROFILE_RELIGION_ENUM_e;

typedef enum USER_PROFILE_INTENTION_ENUM_e
{
	intention_notdisclosed = 0,
	intention_lifepartner,
	intention_relationship,
	intention_dating,
}USER_PROFILE_INTENTION_ENUM_e;

typedef enum USER_PROFILE_ADMIN_STATUS_ENUM_e
{
	status_deleted = 0,
	status_hidden,
	status_Active,
}USER_PROFILE_ADMIN_STATUS_ENUM_e;

typedef enum USER_PROFILE_ADMIN_ACCOUNT_ENUM_e
{
	account_standard = 0,
	status_premium,
	status_platinum,
}USER_PROFILE_ADMIN_ACCOUNT_ENUM_e;



typedef struct USER_PROFILE_DETAILS_STRUCT_t
{
	char Name[15];
	char Surname[15];
	USER_PROFILE_GENDER_ENUM_e Gender;
	USER_PROFILE_ETHNICITY_ENUM_e Ethnicity;
	unsigned char Age;
	unsigned int Height;
	unsigned int Weight;
	char Location[15];
	USER_PROFILE_CHILDREN_ENUM_e Children;

}USER_PROFILE_DETAILS_STRUCT_t;

typedef struct USER_PROFILE_BACKGROUND_STRUCT_t
{
	char Work_Sector[30];
	char Job_Title[30];
	char School[20];
	USER_PROFILE_EDUCATION_ENUM_e Education_level;
	USER_PROFILE_RELIGION_ENUM_e Religion;
	USER_PROFILE_INTENTION_ENUM_e Intention;
}USER_PROFILE_BACKGROUND_STRUCT_t;

typedef struct USER_PROFILE_BELEIFS_STRUCT_t
{
	USER_PROFILE_YES_NO_ENUM_e Drinking;
	USER_PROFILE_YES_NO_ENUM_e Smoking;
	USER_PROFILE_YES_NO_ENUM_e Marijuana;
	USER_PROFILE_YES_NO_ENUM_e Drugs;
}USER_PROFILE_BELEIFS_STRUCT_t;

typedef struct USER_PROFILE_ADMIN_STRUCT_t
{
	char Email[30];
	USER_PROFILE_ADMIN_ACCOUNT_ENUM_e Account_Type;
	USER_PROFILE_ADMIN_STATUS_ENUM_e  Account_Status;
}USER_PROFILE_ADMIN_STRUCT_t;


typedef struct USER_PROFILE_STRUCT_t
{
	USER_PROFILE_ADMIN_STRUCT_t         Admin_Info;
	USER_PROFILE_DETAILS_STRUCT_t		Personal_Details;
	USER_PROFILE_BACKGROUND_STRUCT_t	Life_Details;
	USER_PROFILE_BELEIFS_STRUCT_t		Beliefs;
}USER_PROFILE_STRUCT_t;





















#endif