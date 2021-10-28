#include "Score.h"

using namespace std;
Score::Score()
{
	i = 0;	
	scorefile.open("./score.txt");
	while (scorefile>>temp>>score[i]&&i<5)
	{
		cout << temp<<" " << score[i]<< "\n";
		name[i] = temp;
		this->userScore.push_back(make_pair(this->score[5],this->name[5]));		
		i++;	
	}		
	scorefile.close();

}

Score::~Score()
{
}

void Score::ReadFile()
{
		scorefile.open("./score.txt");
	//sort(score[5]);
	for (int i = 0; i < 5; i++)
	{
		scorefile <<score[i]  <<" "<<name[i]<<"\n";
	}	
	scorefile.close();


}
