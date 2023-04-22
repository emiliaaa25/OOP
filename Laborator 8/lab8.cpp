#include<fstream>
#include<string>
#include<map>
#include<queue>
#include<utility>

using namespace std;

class Compare {
public:
	bool operator() (pair<string, int> p1, pair<string, int> p2){
		if (p1.second < p2.second)
			return true;
		if (p1.second > p2.second)
			return false;
		if (p1.first < p2.first)
			return false;
		return true;
	}

};

int main()
{
	string phrase;
	string s1;
	map <string, int> mapa;
	ifstream file("sir.txt");
	if (!file)
		printf("eroare la deschiderea fisierului");
	getline(file, phrase);
	printf("Sirul de caractere citit este: %s\n", phrase.c_str());

	for (int i = 0;i < phrase.size();i++)
			if (phrase[i] != ' ')
			{
				if (phrase[i] != '.')
				{
					if (phrase[i] >= 'A' && phrase[i] <= 'Z')
						phrase[i] = phrase[i] + 32;
					s1 = s1 + phrase[i];
				}
			}
			else
			{
				if (mapa.find(s1) != mapa.cend())
					mapa[s1]++;
				else
					mapa[s1] = 1;
				s1.erase();
			}
	if (s1[0] != NULL)
	{
		if (mapa.find(s1) != mapa.cend())
			mapa[s1]++;
		else
			mapa[s1] = 1;
		s1.erase();
	}

	map<string, int>::iterator it;
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> Coada;
	for (it = mapa.begin(); it != mapa.end(); it++)
		Coada.push(pair<string, int>(it->first, it->second));
	while (Coada.empty()==false)
	{
		printf("%s => %d\n", Coada.top().first.data(),Coada.top().second);
		Coada.pop();
	}
	return 0;
}