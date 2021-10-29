#define _CRT_SECURE_NO_WARNINGS
#include "Score.h"

using namespace std;
Score::Score()
{


	fp = fopen("./score.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		fscanf(fp, "%s", &temp);
		name[i] = temp;
		fscanf(fp, "%d", &score[i]);
//		cout << name[i] << " " << score[i] << endl;
		this->userScore.push_back(make_pair(score[i], name[i]));
	}
	fclose(fp);
	sort(userScore.begin(),userScore.end());
	for (size_t i = 0; i < 5; i++)
	{
	//	cout <<userScore[i].second<<" "<< userScore[i].first<<endl;
	}	
}

Score::~Score()
{
}

void Score::ReadFile()
{

}

void Score::wFile()
{
}
