#include "Movie.h"

using namespace std;

void test();

int main()
{
    cout << "Start testing\n" << endl;
    test();
    cout<<"\nFinish testing"<<endl;
    return 0;

}

void test()
{
    Movie myMovie;
    myMovie.addActor("Usagi", "Tsukino", 1984);
    myMovie.printMovieInfo();
}
