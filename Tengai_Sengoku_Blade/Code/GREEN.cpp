#include "Application.h"
#include "GREEN.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"



GREEN::GREEN(int x, int y, int type) : Enemy(x, y, type)
{


	backward.PushBack({ 24,  37, 32, 31 });
	backward.PushBack({ 80, 37, 32, 32 });
	backward.PushBack({ 137, 37, 32, 31 });
	backward.PushBack({ 189,37,32,31 });
	backward.PushBack({ 236,36,32,32 });



	path.PushBack({ -0.5f, 0 }, 250, &backward);
	path.PushBack({ -0.5f, 0.5f }, 200, &backward);




	backward.speed = 0.1f;

	animation = &backward;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos = { x,y };


}


void GREEN::Move()
{
	
	
	iPoint path_pos = path.GetCurrentPosition();
	position.x = float(original_pos.x + path_pos.x);
	position.y = float(original_pos.y + path_pos.y);
}