#include "Score.h"

using namespace std;
Score::Score()
{
	i = 0;
}

Score::~Score()
{
}

void Score::ReadFile()
{
	
	scorefile.open("./score.txt");
	while (scorefile>>temp>>score[i]&&i<5)
	{
		cout << temp<<" " << score[i]<< "\n";
		i++;
	}
	scorefile.close();
}
