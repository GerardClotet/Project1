#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	//Back = new SDL_Rect();

	LOG("Loading scene");
	
	background = App->textures->Load("assets/background2.png");
	//Back->x = 0;
	//Back->y = 0;
	//Back->h = 785;
	//Back->w = 5110;
	
	
	return true;
}

// UnLoad assets
bool ModuleBackground::CleanUp()
{
	
	return true;
}
update_status ModuleBackground::PreUpdate()
{
	
		//App->render->Blit(background, x, -560, Back);
		
		
	
	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	// Move camera forward -----------------------------
	int scroll_speed = 1;

	App->player->position.x += 1;
	App->render->camera.x -= 2;

/*	do
	{
		App->player->position.y -= 1;
		App->render->camera.y += 3;

	} while (Back->w > 511 && Back->w < 711&&Back->h!=785);
	*/	
	
	

	// Draw everything --------------------------------------

	App->render->Blit(background, 0, 0, NULL);
	return UPDATE_CONTINUE;
}