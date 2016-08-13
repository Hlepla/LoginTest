#include <iostream>
#include <fstream>
#include <string>

using namespace std ;

void openfile();
int getfilesize(ifstream& infile);
void readfile(ifstream& infile , int sizeof_file);
int User_Input(string Username[] , string Password[]);
void getsuccess(string);


int main()
{
  openfile();


}


void openfile()
{
  ifstream infile ;
  int size ;

  infile.open("password.txt") ;

  if(infile.fail())
    {

      cout << "An error has occured opening the file... " ;
      return ;

    }

  else
    {
      size = getfilesize(infile) ;
      infile.close();

      infile.open("password.txt") ;
       readfile(infile , size);

    }

}

int getfilesize(ifstream& infile)
{
  int number_of_lines = 0 ;
  string line ;

  while( getline(infile, line))
    {
      ++number_of_lines ;

    }
  
   number_of_lines-- ;
  
  cout << "The number of lines in the file is:" << number_of_lines << endl ;

  return number_of_lines ;

}

void readfile(ifstream& infile, int size)
{
  int i = 0;

  string usrArray[size] , passArray[size] ;


  while(infile.eof() == false)
    {

      infile >> usrArray[i] >> passArray[i] ;

      cout << usrArray[i] << passArray[i] << endl ; // temp line to see if info reads into arrays

      i++ ;
    }

  cout <<"test1" << endl ;

  User_Input(usrArray,passArray) ;

}

int User_Input(string Username[] , string Password[] )
{
  string user , pass ;

  cout << "test2" << endl ;

 failure1:

  cout << "test below..." << endl ;

  cout << "test username:" << Username[0] << endl ;
  cout << "test password:" << Password[0] << endl ;


  cout <<"Please enter your username: " ;
  cin >> user ;

  cout <<"Please enter your password: " ;
  cin >>pass ;

  for(int i ; i < 3 ; i++)
    {

      if(user==Username[i] && pass==Password[i])
        {

          getsuccess(user) ;
          break ;

        }
    }



      cout << "Username and/or password is incorrect, please try again.." << endl ;

      goto failure1 ;


}

void getsuccess(string user)
{

  cout <<"Welcome back, " << user << " " << "Please remember to logout! " <<endl ;

  return ;


}
 
