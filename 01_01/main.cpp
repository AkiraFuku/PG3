
#include <stdio.h>
#include <list>
using namespace std;



void Draw(list<const char*> stations) {
	int num = 1;
	for (const char* station : stations) {

		
		printf("|%02d|Station: %s|\n",num, station);
		num++;
	}
}
/// <summary>
/// 指定した位置に駅名をリストに挿入します。
/// </summary>
/// <param name="stations">駅名（const char*）のリストへの参照。挿入先となります。</param>
/// <param name="stationName">挿入する駅名（const char*）。</param>
/// <param name="pos">挿入位置を示すインデックス（0始まり）。</param>
void Input(list<const char*>& stations,const char* stationName,int pos) {

	auto it = stations.begin();
    for (int i = 0; i < pos - 1 && it != stations.end(); i++) {
        it++;
    }
    stations.insert(it, stationName);

	
}

int main() {
	list<const char*> stations{ "Tokyo", "Kanda", "Akihabara","Okachimchi","Ueno","Uguisudani","Nippori","Tabata","Komagome","Sugamo","Otuka","Ikebukuro","Mejiro","Takadanobaba,","Shin-Okubo","shinjuku","Yoyogi","Harajuku","Shibuya","Ebisu","Meguro","Gotanda","Osaki","Shinagawa","Tamachi","Hamamatucho","Shimbashi","Yurakucho"};
	
	printf("1970\n");
	Draw(stations);
	Input(stations,"Nisi-Nippori", 8);
	printf("2019\n");
	Draw(stations);
	Input(stations, "Takanawa Gateway", 26);
	printf("2022\n");
	Draw(stations);

	return 0;
}