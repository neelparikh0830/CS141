/*
 * This program read the movies from file and puts out the number of how many movies are in file.
 * After that it sorts the movies by ID and by there title and then output it.
 * Author : Neel Parikh UIC Fall 2020
 */


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Neel please explain the code before you submit.
// This defines the struct and stores the value in the struct of the movie.
struct Movie 
{
    int ID;
    int Year;
    string Title;
};

// This is the sorting function which shorts the movies by their ID.
void sortMoviesIDArray(Movie array[], int size) 
{
   int i;
   int j;
   int temp0;
   int temp1;
   string temp;
   
   
   for (i = 1; i < size; i++) {
      j = i;
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && array[j].ID < array[j - 1].ID) {
         
         // Swap numbers[j] and numbers[j - 1]
         temp0 = array[j].ID;
         array[j].ID = array[j - 1].ID; // line 38 to 40  swaps the the movie ID.
         array[j - 1].ID = temp0;
          
         temp1 = array[j].Year;
         array[j].Year = array[j - 1].Year; // line 42 to 44  swaps the the movie year.
         array[j - 1].Year = temp1;
          
         temp = array[j].Title;
         array[j].Title = array[j - 1].Title; // line 46 to 48  swaps the the movie title.
         array[j - 1].Title = temp;
         //swap array[j] and array[j-1];
         --j;
      }
   }
}
// This is the sorting function which shorts the movies by their Title.

void sortMoviesTITArray(Movie array[], int size)
{
   int i;
   int j;
   int temp0;
   int temp1;
   string temp;
   
   for (i = 1; i < size; i++) {
      j = i;
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && array[j].Title < array[j - 1].Title) {
         
         // Swap numbers[j] and numbers[j - 1]
         temp0 = array[j].ID;
         array[j].ID = array[j - 1].ID; // line 71 to 73  swaps the the movie ID.
         array[j - 1].ID = temp0;
          
         temp1 = array[j].Year;
         array[j].Year = array[j - 1].Year; // line 75 to 77  swaps the the movie year.
         array[j - 1].Year = temp1;
          
         temp = array[j].Title;
         array[j].Title = array[j - 1].Title; // line 79 to 81  swaps the the movie title.
         array[j - 1].Title = temp;
         //swa (array[j and, array[j-1;
         --j;
      }
   }
}

// This function outputs the sorted order one by one.

void moviesoutput(Movie array[], int size)
{
    for (int z = 0; z < size; z++)
   {
      cout << array[z].ID << " " << array[z].Year << " '" << array[z].Title << "'" << endl;
   }
}

int main()
{
    string filename, notUseFull1, notUseFull2; // There are three string variable one for filname another two dumping out string and getting int.;
    int N; // These is the variable where number of movies will be stored.
   
    // Next two line, one of them cout the statement for user to put the filname and another one bring that filename in program. 
    cout << "Movies filename> ";
    cin >> filename;
    
    ifstream inmoviefile(filename); // open the file if it's given.;
    
    if (!inmoviefile.good()) // if not then this statement output's the error massage.)
    {
        cout << "**Error: unable to open input file '" << filename << "'." << endl;
        return 0;
    
    }
   // Next 3 to 4 lines takes the unusefull string with them and helps to cout the number of movies int variable. 
    getline(inmoviefile, notUseFull1);
    inmoviefile >> notUseFull2;
    inmoviefile >> N;
    cout << "**Number_Movies: " << N << endl;
   
    // Create new array of struct with how many number of movies where there. 
    Movie* movies;
    movies = new Movie[N];
    
    /*127 -156 */
    
    // lines 127 to 156 reads the text file and then store it as an array in the struct.
    
    int id;
    int year;
    string a, title;
    int strlen;
    int i=0;
    
    while (!inmoviefile.eof())
    {
        inmoviefile >> id; // it gets the id of the movie from the text file.;
        inmoviefile >> year; // it gets the year of the movie from the text file.;
        getline(inmoviefile, a); // it gets the tile of the movie from the text file.;
        strlen = a.length(); // it counts the length of the string.;
        title = a.substr(1,strlen-1); // This string avoids the frist empty space and gives us next entire sting.;
        
        
        if (!inmoviefile.fail()) // these loop puts value in the movie strcut if it doesn't fail)
        {
            movies[i].ID = id;
            movies[i].Year = year;
            movies[i].Title = title;
            i++;
        }
        
    }
    
   /* 1279 -1560 */
   
    // This line output's the first and last movies of the text file. 
    cout << "**First movie: " << movies[0].ID << " " << movies[0].Year << " '" << movies[0].Title << "'" << endl;
    cout << "**Last movie: " << movies[N-1].ID << " " << movies[N-1].Year << " '" << movies[N-1].Title << "'" << endl
    ;
    cout << "**MOVIES BY ID**" << endl;
   
    // next statement calls the sort function which sorts the movies by ID. 
    sortMoviesIDArray(movies, N);
   
    // it calls the output function which cout's movies one by one from an array. 
    moviesoutput(movies, N);
    
    cout << "**MOVIES BY TITLE**" << endl;
   
    // next statement calls the sort function which sorts the movies by Title. 
    sortMoviesTITArray(movies, N);
   
    // it calls the output function which cout's movies one by one from an array. 
    moviesoutput(movies, N);
    
    cout << "**Done**" << endl;
    
    delete [] movies; // These deletes the movies array which we took it from the computer
    
    return 0;
}