/*
 * This program read the movies from file and puts out the number of how many movies are in file.
 * After that it sorts the movies by ID and by there title and then output it.
 * After that it counts how many reviews are there for each movies and then add 
 * all the ratings from reviews and then outputs the # of reviews and avg. of rating.
 * Also in the final part of the code the user is allowed to take a look at what they want to see
 * and enter the command to see that.
 * Author : Neel Parikh UIC Fall 2020
 */



#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// This is first struct where movies id, year and title are stored from movie file.

struct Movie
{
    int ID;
    int Year;
    string Title;
};

// The second struct is the struct where reviews are stored in form of review id, movie id and rating from review file.

struct Review
{
    int rID;
    int mID;
    int Rating;
};

//Next function is for the sorting of the movie by a movie id.

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
         array[j].ID = array[j - 1].ID; // line 55 to 57  swaps the movie ID for the sorting function.
         array[j - 1].ID = temp0;
          
         temp1 = array[j].Year;
         array[j].Year = array[j - 1].Year; // line 59 to 61  swaps the movie year.
         array[j - 1].Year = temp1;
          
         temp = array[j].Title;
         array[j].Title = array[j - 1].Title; // line 63 to 65 swaps the movie title.
         array[j - 1].Title = temp;
         //swaps array[j] with array[j-1]
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
         array[j].ID = array[j - 1].ID; // line 89 to 91  swaps the movie ID for the sorting function.
         array[j - 1].ID = temp0;
          
         temp1 = array[j].Year;
         array[j].Year = array[j - 1].Year; // line 93 to 95  swaps the movie year.
         array[j - 1].Year = temp1;
          
         temp = array[j].Title;
         array[j].Title = array[j - 1].Title; // line 97 to 99  swaps the movie title.
         array[j - 1].Title = temp;
         //swaps array[j] and array[j-1]
         --j;
      }
   }
}

// Next void function counts the number of reviews and aslo rating and add them up.

void reviewcount(Movie array[], int size0, Review arriy[], int size1, double A[], int B[])
{
    int i;
    int j;
    for (i=0; i<size0; i++)
    {
        A[i]=0;
        B[i]=0;
        for (j=0; j<size1; j++)
        {
            if (array[i].ID == arriy[j].mID) // checks if movie id matches from both struct
            {
                A[i] += arriy[j].Rating; // if it matches then it add ups the rating increase the count for review.
                B[i]++;
            }
        }
    }
}

// this function find max reviews in the file and sents it the main function.

double maxArray(double* A, int* B, double* C, int count)
{
   for (int r=0; r<count; r++)
    {
        if (B[r] == 0) // if b[r] is zero because divide by zero is und.
        {
            C[r] = 0;
        }
       
       else
       {
            C[r] = A[r]/B[r];
        }
    }
    
   double temp = C[0];
   for (int j=1; j<count; j++)
   {
      if (C[j] > temp)
      {
         temp = C[j];
      }
   }
   return temp;
}

// compares the double value in the function and returns the index of that place.

int findInArray(double variable, double C[], int size)
{
    for (int i=0; i<size; i++)
    {
        if (variable == C[i])
        {
            return i;
        }
    }
    
    return 0;
}

// boolean function which checks if there is a digit in the user input.

bool commandint(string check)
{
    int length = check.length();
    for (int i=0; i<length; i++)
    {
        if(isdigit(check[i]) == false)
        {
            return false;
        }
    }
    return true;
}

void findtitle(Movie array[], int N, string neel, double* A, int* B)
{
    int cnt=0;

                    for (int i=0; i<N; i++)
                    {

                        string find = array[i].Title;
                        size_t pos = find.find(neel);
                        if (pos == string::npos)
                        {
                            cnt++;
                            if (cnt == N)
                            {
                                cout << "Movie not found..." << endl;
                            }
                        }
                        else
                        {
                            if (B[i] == 0)
                            {
                                cout << array[i].ID << " " << array[i].Year << " '" << find << "' " <<
                                B[i] << " reviews " << B[i] << " avg rating" << endl;
                            }
                            else 
                            {
                                cout << array[i].ID << " " << array[i].Year << " '" << find << "' " <<
                                B[i] << " reviews " << A[i]/B[i] << " avg rating" << endl;
                            }
                        }
                    }
}



int findByID(int find, Movie array[], int N)
{
    for (int i=0; i<N; i++)
    {
        if (find == array[i].ID)
        {
            return i;
        }
    }
    
    return -1;
}

// This function outputs the sorted order one by one.

void moviesoutput(Movie array[], int size, double A[], int B[])
{
    for (int z = 0; z < size; z++)
   {
        if (B[z] == 0) // if the integer is zero in B array then it couts this statement.
      {
          cout << array[z].ID << " " << array[z].Year << " '" << array[z].Title << "' " <<
          B[z] << " reviews " << B[z] << " avg rating" << endl;
      }
      else // else couts this statement.
      {
          cout << array[z].ID << " " << array[z].Year << " '" << array[z].Title << "' " <<
          B[z] << " reviews " << A[z]/B[z] << " avg rating" << endl;
      }
   }
}

int main()
{
    string filename0, filename1; // This string variable are for filename entred by username..
    int N,O; // These is the variable where number of movies nad reviews will be stored.
    
    // Next two line, one of them cout the statement for user to put the filname and another one bring that filename in program. 
    cout << "Movies filename> ";
    cin >> filename0;
    
    ifstream inmoviefile(filename0); // open the file if it's given.
    
    if (!inmoviefile.good()) // if not then this statement output's the error massage.
    {
        cout << "**Error: unable to open input file '" << filename0 << "'." << endl;
        return 0;
    }
    
    // Next two line, one of them cout the statement for user to put the filname and another one bring that filename in program. 
    cout << "Reviews filename> ";
    cin >> filename1;
    
    ifstream inreviewfile(filename1); // open the file if it's given.
    
    if(!inreviewfile.good()) // if not then this statement output's the error massage.
    {
        cout << "**Error: unable to open input file '" << filename1 << "'." << endl;
        return 0;
    }
    
    string notUseFull1, notUseFull2; // This string variable are for dumping out string and getting int.
    
    // Next 3 to 4 lines takes the unusefull string with them and helps to cout the number of movies int variable.
    
    getline(inmoviefile, notUseFull1);
    inmoviefile >> notUseFull2;
    inmoviefile >> N;
    cout << "**Number_Movies: " << N << endl;
    
    string notUseFull3, notUseFull4; // This string variable are for dumping out string and getting int.
    
    // Next 3 to 4 lines takes the unusefull string with them and helps to cout the number of reviews int variable.
    
    getline(inreviewfile, notUseFull3);
    inreviewfile >> notUseFull4;
    inreviewfile >> O;
    cout << "**Number_Reviews: " << O << endl;
    
    // Create new array of struct with how many number of movies where there.
    Movie* movies;
    movies = new Movie[N];
    
    // Create new array of struct with how many number of reviews where there.
    Review* reviews;
    reviews = new Review[O];
    
    // lines 263 to 290 reads the text file and then store it as an array in the movie struct.
    
    int id;
    int year;
    string a, title;
    int strlen;
    int i=0;
    
    while (!inmoviefile.eof())
    {
        inmoviefile >> id;
        inmoviefile >> year;
        getline(inmoviefile, a);
        strlen = a.length();
        title = a.substr(1,strlen-1);
        
        
        if (!inmoviefile.fail())
        {
            movies[i].ID = id;
            movies[i].Year = year;
            movies[i].Title = title;
            i++;
        }
        
    }
    
    // lines 263 to 290 reads the text file and then store it as an array in the movie struct.
    
    // lines 292 to 316 reads the text file and then store it as an array in the review struct.
    
    int rid;
    int mid;
    int rating;
    int j=0;
    
    while (!inreviewfile.eof())
    {
        inreviewfile >> rid;
        inreviewfile >> mid;
        inreviewfile >> rating;
        
        
        if (!inreviewfile.fail())
        {
            reviews[j].rID = rid;
            reviews[j].mID = mid;
            reviews[j].Rating = rating;
            j++;
        }
        
    }
    
    // lines 292 to 316 reads the text file and then store it as an array in the review struct.
    
    // Create new array double with how many number of movies where there to store sum of ratings.
    double* A;
    A = new double [N];
    
    // Create new array int with how many number of movies where there to store number of reviews.
    int* B;
    B = new int [N];
    
    // Create new array double with how many number of movies where there to store average of ratings.
    double* C;
    C = new double [N];
    
    cout << endl;
    string command;
    string command1;
    string command2;
    int p=1;
    while (p>0) // loop which checks if user input q and if its q than break the loop.
    {
        cout << "Enter command (f id, f title, l, mp, q): ";
        cin >> command;

        if (command == "q") // this statement will run user input q.
        {
           p = -2;
           cout << "**Done**" << endl;

        }

        else if (command == "mp") // this statement print's out most popular movie.
        {
            // review count to bring number of reviews and avg. rating into loop.
            reviewcount(movies, N, reviews, O, A, B);
            
            //max Array returns the highest review in the file.

            double mstreview = maxArray(A, B, C, N);
            
            //findInArray function returns the location for the highest review in the file after that cout the mp.

            int f = findInArray(mstreview, C, N);

            cout << movies[f].ID << " " << movies[f].Year << " '" << movies[f].Title << "' " <<
            B[f] << " reviews " << C[f] << " avg rating" << endl;

        }

        else if (command == "f") // this function find the movie id ot title given by user.
        {
            getline(cin, command1);

            command2 = command1.substr(1);
            
            reviewcount(movies, N, reviews, O, A, B);

            if (commandint(command2))
            {
                
                
                int find = stoi(command2);

                int k = findByID(find, movies, N);

                if (k<0)
                {
                    cout << "Movie not found..." << endl;
                }
                else if (B[k] == 0)
                {
                    cout << movies[k].ID << " " << movies[k].Year << " '" << movies[k].Title << "' " <<
                    B[k] << " reviews " << B[k] << " avg rating" << endl;
                }
                else 
                {
                    cout << movies[k].ID << " " << movies[k].Year << " '" << movies[k].Title << "' " <<
                    B[k] << " reviews " << A[k]/B[k] << " avg rating" << endl;
                }

            }

            else
            {
                /* New */
                sortMoviesTITArray(movies, N);
                
                reviewcount(movies, N, reviews, O, A, B);
                
                findtitle(movies, N, command2, A, B);
            }
            
        }

        else // this else cout all movies in the file
        {
            cout << "**MOVIES BY ID**" << endl;

            sortMoviesIDArray(movies, N);

            reviewcount(movies, N, reviews, O, A, B);

            moviesoutput(movies, N, A, B);

            cout << "**MOVIES BY TITLE**" << endl;

            sortMoviesTITArray(movies, N);

            reviewcount(movies, N, reviews, O, A, B);

            moviesoutput(movies, N, A, B);
            

        }
        
        cout << endl;
    }
    p++;
    
    // from line 451 to 460 it deletes the array which we took from computer.
    delete [] movies;
    
    delete [] A;
    
    delete [] B;
    
    delete [] C;
    
    delete [] reviews;
    
    return 0;
    
     
}