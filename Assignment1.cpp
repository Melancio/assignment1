//A simple ditionary by: Melance Gaudreault

#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstring>
#include <iomanip>

#define ROW 300
#define COL 20


using namespace std;

int main() {


char tmpDic[ROW][COL]; //All the words get dumped into this array first
char dic[ROW][COL]; //Dictionary without duplicates of words
char pos[ROW];
int numWords = 0;
int count[ROW];
int newWord= 0;
int wordCount = 0;
char ch;
int row = 0;
int col = 0;

char ans;
bool done = false;

while( cin.good() && ! done ) //dumping txt into tmpDic
{
 char ch = cin.get();
 if ( isalpha(ch) )
    {
    	tmpDic[row][col] = tolower(ch);
    	col++;
    	newWord = 1;
    }
 else
       if (newWord == 1)
          {
			row++;
			if (row > ROW)
			{
                cout << "Too many words in the Dictionary, word count > ";
                cout << ROW;
                cout.put('\n');
                cout << "Do you want to display the dictionary anyways? Y/N";
                cin >> ans;
                if ( ans == 'Y' || ans == 'y') done = true;
                    else return 0;

			}
            newWord = 0;
           	col = 0;
          }

}

for ( int i = 0 ; i < row; i++)
	{
        int found = 0;
		for (int k = 0 ; k < i; k++ ) //compares word in tmpDic to the words in Dictionary
		{
            if ( strcmp( tmpDic[i], dic[k]) == 0 )
            {
                count[k]++;
                //i++;
                found = 1;
            }
		}

            if ( found == 0)
            {
                for ( int j = 0; j < COL; j++) //Place word at end of list
                {
                    dic[numWords][j] = tmpDic[i][j];

                }
                numWords++;
            }

	}
cout << "Word" << setw(30) << "Frequency";
cout.put('\n');
cout << "--------------------------------";
cout.put('\n');
for (int i = 0; i < numWords; i++) //Print outs dictionary NOTE: NEED PROPER FORMATING
    {

        cout << dic[i];
        cout << setw(28);
        cout << count[i] + 1;
        cout.put('\n');
    }


return 0;
}
