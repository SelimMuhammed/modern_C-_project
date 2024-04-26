#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <limits>

#define OPTIONS_MAX_NUM (char) 3
#define INIT_VALUE      (char) 0
using namespace std;


enum class option
      {
        AddRecord = 1,
        FetchRecord = 2,
        Quit = 3
      };  

string convertToStr(option optionSel)
 {
   switch (optionSel)
   {
   case option::AddRecord:
    return "1: Add Record";
    break;

    case option::FetchRecord:
    return "2: Fetch Record";
    break;

    case option::Quit:
    return "3: Quit";
    break;
   
   }
 }  

class Person
   {
      public:

      string Name ;
      int Age ;

      array<option,OPTIONS_MAX_NUM> options
      {option::AddRecord,option::FetchRecord,option::Quit};

      void showOptions()
      {
        cout<< "Please select an option\n";
        for(option optionCounter : options)
        {
          cout<<convertToStr(optionCounter)<<"\n";   
        }
      }

   }; 


vector<Person>PersonDB{0} ;


void Add_voidRecord(Person* recordPtr)
{
    // Create a new Person object and copy the data from recordPtr
    Person newRecord;
    newRecord.Name = recordPtr->Name;
    newRecord.Age = recordPtr->Age;
    
    // Add the new record to the PersonDB vector
    PersonDB.push_back(newRecord);
}

Person Fetch_personRecord(int user_ID)
{
    Person Record;
    if (user_ID >= INIT_VALUE && user_ID < PersonDB.size()) {
        Record.Name = PersonDB[user_ID].Name;
        Record.Age = PersonDB[user_ID].Age;
    } else {
        // Handle out-of-bounds access (e.g., throw an exception, return a default record, etc.)
        // For simplicity, let's just set the Name and Age to indicate an error
        Record.Name = "Invalid User";
        Record.Age = -1;
    }
    return Record;
}

istream& operator>>(istream & input_stream,option & result)
{
   int int_option;
   input_stream >> int_option; // integer
   // convert integer ----> option enum.
   result = static_cast<option>(int_option);
    return input_stream;
}

int main()
{
  int User_ID;
  option selectOption;
  Person personSelect;

  while(1)
  {
  personSelect.showOptions();
  cout<< "Enter option : ";
  cin>> selectOption;

  if (selectOption < option::AddRecord || selectOption > option::Quit)
  {
    cout<<"Please Enter a valid option :\n";
  }
  else
  {
   switch (selectOption)
    {
    case option::AddRecord:
        // Code for adding a record
        cout<< "Add User. Please enter user name and age: \nName: ";

        cin.ignore(); // Ignore newline character left in the input buffer
        getline(cin, personSelect.Name);

        cout<< "Age: ";
        cin>> personSelect.Age;

        Add_voidRecord(&personSelect);
        cout<< "User record added successfully.\n";
        break;

    case option::FetchRecord:
        // Code for fetching a record
        cout<< "Please enter user ID: \nUser ID: ";
        cin>> User_ID;

        personSelect = Fetch_personRecord(User_ID);

        cout<< "User Name: "<<personSelect.Name<<"\n";
        cout<< "User Age: "<<personSelect.Age<<"\n";
        break;

    case option::Quit:
        // Code for quitting
        cout<< "Thank You\n";
        return 0;
        break;
    }
  }
 }
    return 0;

}

