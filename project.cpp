#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin;

class Game{
	private:
		string input;
		int points;
		int trys;
		string possiblewords[50];
		vector <string> trash;
	public:
		Game(){
			input=" ";
			points=0;
			trys=24;
			int i=0;
			while(fin>>possiblewords[i]){
				i++;
			}
		}
		void setInput(string str)
		{
			input=str;
		}
		int getPoints(){return points;}
		int getTrys(){return trys;}
		void setTrys(){trys-=1;}
		void find()
		{
            for(int i=0;i<24;i++)
                if(input==possiblewords[i])
					{
						points+=1;
						if(input=="aficionado")
							points+=2;
						cout<<"Worked"<<endl<<endl;
						trash.push_back(input);
						return;
					}
            cout<<"Word not on list"<<endl<<endl;
            return;
        }
        bool usedword()
        {
            for(int a=0;a<trash.size();a++)
            {
                if(input==trash[a])
                    {
                        cout<<"you used this word already"<<endl;
                        return 1;
                    }
            }
            return 0;
		}

		void text()
		{
		    cout<<"*****************************************************"<<endl;
		    cout<<"*               *                    *              *"<<endl;
		    cout<<"*         O     *        A           *      D       *"<<endl;
		    cout<<"*               *                    *              *"<<endl;
		    cout<<"*****************************************************"<<endl;
		    cout<<"*               *                    *              *"<<endl;
		    cout<<"*               *        C           *              *"<<endl;
		    cout<<"*               *                    *              *"<<endl;
		    cout<<"*****************************************************"<<endl;
		    cout<<"*               *                    *              *"<<endl;
		    cout<<"*         N     *        I           *      F       *"<<endl;
		    cout<<"*               *                    *              *"<<endl;
		    cout<<"*****************************************************"<<endl;
            cout<<endl;
		}
};

int main()
{

	fin.open("test.txt");
	Game match;
	int x=0,y=0;
	string word;
	bool whatever;
	cout<<"The rules of the game are as follows :"<<endl;
		    cout<<endl;
		    cout<<"1.Each word has at least 5 letters, chosen from the listed letters."<<endl;
		    cout<<endl;
		    cout<<"2.Every word must use the center letter at least once."<<endl;
		    cout<<endl;
		    cout<<"3.A letter may be used more than once in a word"<<endl;
		    cout<<endl;
		    cout<<"4.Not allowed are proper names, hyphenated words, prefixes and suffixes."<<endl;
		    cout<<endl;
		    cout<<"5.There are 24 tries, lower-case letters only."<<endl;
		    cout<<endl;
    match.text();
	cout<<"Enter a word"<<endl;
	cin>>word;
	match.setInput(word);
	match.find();
	cout<<"Total points: "<<match.getPoints()<<endl;
	match.setTrys();
	cout<<"Tries left: "<<match.getTrys()<<endl<<endl;
	match.text();
	while (match.getTrys()>0)
    {
        cout<<"Enter a word"<<endl;
        cin>>word;
        match.setInput(word);
        whatever=match.usedword();
        while(!whatever)
            {
                match.find();
                whatever=1;
            }
        cout<<"Total points: "<<match.getPoints()<<endl;
        match.setTrys();
        cout<<"Tries left: "<<match.getTrys()<<endl<<endl;

        cout<<endl;
        match.text();
    }

    cout<<"You scored : ";
    cout<<match.getPoints()<<endl;
    if(match.getPoints()>=20)
        cout<<"You are a genius"<<endl;
    if(match.getPoints()>=15 && match.getPoints()<20)
        cout<<"You are excellent"<<endl;
    if(match.getPoints()>=10 && match.getPoints()<15)
        cout<<"You are good"<<endl;
    if(match.getPoints()<10)
        cout<<"Better luck next time"<<endl;
}


