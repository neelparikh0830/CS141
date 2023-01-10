/*
 * This program read the movies from file and puts out the number of how many movies are in file.
 * After that it sorts the movies by ID and by there title and then output it.
 * After that it counts how many reviews are there for each movies and then add 
 * all the ratings from reviews and then outputs the # of reviews and avg. of rating.
 * Author : Neel Parikh UIC Fall 2020
 */



#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Movie
{
    int ID;
    int Year;
    string Title;
};

struct Review
{
    int rID;
    int mID;
    int Rating;
};

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
         array[j].ID = array[j - 1].ID;
         array[j - 1].ID = temp0;
          
         temp1 = array[j].Year;
         array[j].Year = array[j - 1].Year;
         array[j - 1].Year = temp1;
          
         temp = array[j].Title;
         array[j].Title = array[j - 1].Title;
         array[j - 1].Title = temp;
         //swap(array[j], array[j-1]);
         --j;
      }
   }
}

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
         array[j].ID = array[j - 1].ID;
         array[j - 1].ID = temp0;
          
         temp1 = array[j].Year;
         array[j].Year = array[j - 1].Year;
         array[j - 1].Year = temp1;
          
         temp = array[j].Title;
         array[j].Title = array[j - 1].Title;
         array[j - 1].Title = temp;
         //swap(array[j], array[j-1]);
         --j;
      }
   }
}

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
            if (array[i].ID == arriy[j].mID)
            {
                A[i] += arriy[j].Rating;
                B[i]++;
            }
        }
    }
}



void moviesoutput(Movie array[], int size, double A[], int B[])
{
    for (int z = 0; z < size; z++)
   {
        if (B[z] == 0)
      {
          cout << array[z].ID << " " << array[z].Year << " '" << array[z].Title << "' " <<
          B[z] << " reviews " << B[z] << " avg rating" << endl;
      }
      else
      {
          cout << array[z].ID << " " << array[z].Year << " '" << array[z].Title << "' " <<
          B[z] << " reviews " << A[z]/B[z] << " avg rating" << endl;
      }
   }
}

int main()
{
    string filename0, filename1;
    int N,O;
    
    cout << "Movies filename> ";
    cin >> filename0;
    
    cout << "Reviews filename> ";
    cin >> filename1;
    
    ifstream inmoviefile(filename0);
    ifstream inreviewfile(filename1);
    
    if (!inmoviefile.good())
    {
        cout << "**Error: unable to open input file '" << filename0 << "'." << endl;
        return 0;
    }
    
    if(!inreviewfile.good())
    {
        cout << "**Error: unable to open input file '" << filename1 << "'." << endl;
        return 0;
    }
    
    string notUseFull1, notUseFull2;
    
    getline(inmoviefile, notUseFull1);
    inmoviefile >> notUseFull2;
    inmoviefile >> N;
    cout << "**Number_Movies: " << N << endl;
    
    string notUseFull3, notUseFull4;
    
    getline(inreviewfile, notUseFull3);
    inreviewfile >> notUseFull4;
    inreviewfile >> O;
    cout << "**Number_Reviews: " << O << endl;
    
    Movie* movies;
    movies = new Movie[N];
    
    Review* reviews;
    reviews = new Review[O];
    
    
    /* 39 - 60 */
    
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
    
    double* A;
    A = new double [N];
    
    int* B;
    B = new int [N];
    
    /* 39 - 60 */
    
    cout << "**MOVIES BY ID**" << endl;
    
    
    sortMoviesIDArray(movies, N);
    
    reviewcount(movies, N, reviews, O, A, B);
    
    moviesoutput(movies, N, A, B);
    
    cout << "**MOVIES BY TITLE**" << endl;
    
    sortMoviesTITArray(movies, N);
    
    reviewcount(movies, N, reviews, O, A, B);
        
    moviesoutput(movies, N, A, B);
    
    cout << "**Done**" << endl;
    
    delete [] movies;
    
    delete [] A;
    
    delete [] B;
    
    delete [] reviews;
    
    return 0;
}