#include "User_Profile.h"


//databse for profiles will be in an array which gets added
//when a profile filters, its filters the database and copies the valid profiles tot he users circular buffer
// when the user applies new filters the proces repeats and the circular buffer pointers reset to original
//when adding new profiles we can overwrite deleted profiles in the database


