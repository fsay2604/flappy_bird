/************************************************************************/
/*  Francois Charles Hebert												*/
/*  25 novembre 2020													*/
/*  Lab 8: Recréation du jeu Flappy Bird.								*/
/************************************************************************/

#include "game.h"
#include "DEFINITIONS.hpp"
using namespace std;

int main()
{
	game flappy(SCREEN_WIDTH, SCREEN_HEIGHT, "FLAPPY BURDS");
	return 0;
}



/// Pragma once dans les .h
/// pas de using namespace dans un .h, on ajoute le namespace dans les .h
/// on utilise using namespace dans le cpp.
/// on met seulement les include utilis/ dans le .h dans le .h, et les include utilise dans le cpp dans le cpp. Si le include est utiliser dans le .h et le .cpp, le mettre dans le .h a cause du pragma once.
/// 


