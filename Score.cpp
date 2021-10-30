#define _CRT_SECURE_NO_WARNINGS
#include "Score.h"

using namespace std;
Score::Score()
{




}

Score::~Score()
{
}

void Score::ReadFile()
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
	
}

void Score::wFile()
{
	ReadFile();
	this->name[5] = Pname;
	this->score[5] = scoreplayer;	
	this->userScore.push_back(make_pair(this->score[5], this->name[5]));	
	sort(userScore.begin(),userScore.end());
	fp=fopen("./score.txt", "w");
	for (int i = 5; i >0; i--)
	{

		strcpy(temp, userScore[i].second.c_str());		
	
		fprintf(fp, "%s %d\n", temp, userScore[i].first);
	}
	for ( int i = 5; i >0;  i--)
	{
		cout <<userScore[i].second<<" "<< userScore[i].first<<endl;	
	}
	for (int i = 0; i < 6; i++)
	{
		userScore.pop_back();
	}
	fclose(this->fp);
}
