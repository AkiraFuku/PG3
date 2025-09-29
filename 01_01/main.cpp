
#include <stdio.h>
#include <list>
using namespace std;



void Draw(list<const char*> stations) {
	for (const char* station : stations) {
		printf("|Station: %s|\n", station);
	}
}
int main() {
	list<const char*> stations2022{ "Tokyo", "Kanda", "Akihabara","Okachimchi","Ueno","Uguisudani","Nippori","Nisi-Nippori","Tabata","Komagome","Sugamo","Otuka","Ikebukuro","Mejiro","Takadanobaba,","Shin-Okubo","shinjuku","Yoyogi","Harajuku","Shibuya","Ebisu","Meguro","Gotanda","Osaki","Shinagawa","Tamachi","Hamamatucho","Shinbashi",};
	list<const char*> stations2019{ "Station D", "Station E", "Station F" };
	list<const char*> stations1970{ "Station G", "Station H", "Station I" };

	Draw(stations2022);
	Draw(stations2019);
	Draw(stations1970);

	return 0;
}