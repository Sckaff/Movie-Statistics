//Fernando Sckaff
//COP2000.0M1
//This program will read and give information about movies (in this case Sci-Fi)

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using std::ifstream;
using std::string;

class Movie
{
private:
	//private member variables 
	ifstream inMovie;
	int sumTime,
		movies;
	float sumGross,
		avgTime,
		avgGross;

	//private member functions' prototypes
	void openFile();
	void testFile();
	void readFile();
	void closeFile();
	void calcAvgTime();
	void calcAvgGross();
	void display();

public:
	//public member functions' prototypes
	Movie();
	void driver();
};

/**************************************************************/

//Open the File
void Movie::openFile()
{
	inMovie.open("SciFiMovies.txt");

	testFile();
}

//Test to see if the file was open properly
void Movie::testFile()
{
	if (!inMovie)
	{
		using std::cerr;
		using std::endl;

		cerr << "The file did not open properly" << endl << endl;
		exit(101);
	}
}

//Read the file and extract the important information
void Movie::readFile()
{
	int minutes,
		year;
	float budget;
	string name;

	//Get the year, time, budget, and the name of the movie in each line
	while (inMovie >> year >> minutes >> budget >> name)
	{
		sumTime += minutes;
		sumGross += budget;
		movies++;

		inMovie.ignore(256, '\n'); //Ignore in case the movie name has more than one word
	}
}

//close the input file
void Movie::closeFile()
{
	inMovie.close();
}

//Calculate the average time of all the movies in the file (in minutes)
void Movie::calcAvgTime()
{
	avgTime = static_cast<float>(sumTime) / movies;
}

//Calculate the average budget of all the movies in the file (in millions)
void Movie::calcAvgGross()
{
	avgGross = sumGross / movies;
}

//Display all the required information to the user interface
void Movie::display()
{
	using std::cout;
	using std::endl;
	using std::fixed;
	using std::setprecision;

	cout << fixed << setprecision(1); 

	cout << "Welcome to the Movie reader!" << endl << endl; //Welcoming statement

	cout << "The average movie length for these movies is: " << avgTime << " minutes" << endl;
	cout << "The average gross box office for these movies is: " << avgGross << " millions" << endl;

	cout << endl << "\"Ecto Gamat\" - The Fith Element"; //End statement
}

//Constructor
Movie::Movie()
{
	sumTime = 0,
	movies = 0;
	sumGross = 0,
	avgTime = 0,
	avgGross = 0;
}

//Order of execution
void Movie::driver()
{
	openFile();
	readFile();
	closeFile();
	calcAvgTime();
	calcAvgGross();
	display();
}
/**************************************************************/

int main()
{
	using std::cout;
	using std::endl;

	Movie mov;		//Creating the object
	mov.driver();	//Requesting the order of execution

	cout << endl << endl;
	system("pause");
	return 0;
}