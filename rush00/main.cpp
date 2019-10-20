#include "Screen.class.hpp"
#include "AScreenElement.class.hpp"
#include <unistd.h>
#include <cstdlib>
#include "Player.hpp"
#include "Enemy.hpp"
#include "EnemyFleet.hpp"
#include "SpaceDebris.class.hpp"
#include "SpaceDebrisContainer.class.hpp"
#include "PlayerInput.class.hpp"
#include <time.h>
#include <iostream>
#include <chrono>

#define FPS 30
#define LOOP_TIME (1000 / FPS)

void	gameLoop(Screen &ms)
{
	PlayerInput					pi;
	SpaceDebrisContainer		spd_cont = SpaceDebrisContainer(&ms);
	BulletContainer				bullets = BulletContainer(&ms);
    EnemyFleet					fleet = EnemyFleet(&ms, &bullets);
    Player						player = Player(&ms, &bullets, &fleet);
    std::chrono::milliseconds	time_start;

	spd_cont.create(25);
	ms.display();
	while (true)
	{
        time_start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		pi.read(ms);
		if (pi.quit())
			break ;
		player.move(pi.getHorizontalDirection() * 2, pi.getVerticalDirection() * -1);
		player.getWeapon()->shot();
		spd_cont.update();
		if (player.update() == false)
			break;
        bullets.update();  // update all bullets
        fleet.update();  // update all enemy
		ms.display();
        std::chrono::milliseconds time_loop = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()) - time_start;
		if (time_loop.count() < LOOP_TIME)
			usleep((LOOP_TIME - time_loop.count()) * 1000);
	}
}


int main()
{
	srand(time(NULL));
    Screen					ms;
	if (!ms.init())
	{
		ms.deinit();
        std::cout << "Error setting terminal settings." << std::endl;
		return (1);
	}
	if (!ms.check_size())
	{
		ms.deinit();
        std::cout << "The screen is too small, please GET ME A BIGGER SCREEN FOR **** sake!" << std::endl;
		return (2);
    }
	gameLoop(ms);
    ms.deinit();
	std::cout << "Final score : " << ms.getScore() << std::endl;
    return 0;
}
