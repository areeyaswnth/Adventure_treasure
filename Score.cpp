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
	for (int i = 0; i < 5; i++)
	{
		cout << score[i] <<" "<< name[i] << "\n";
	}
}

Score::~Score()
{
}

void Score::ReadFile()
{
	


}
