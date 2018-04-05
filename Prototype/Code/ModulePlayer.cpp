#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"

#include "ModuleRender.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	graphics = NULL;
	current_animation = NULL;

	position.x = 150;
	position.y = 120;

	// idle-forward-downwards animation 
	forward.PushBack({ 68 ,53 ,32 ,28 });
	forward.PushBack({ 108 ,54 ,32 ,28 });
	forward.PushBack({ 148, 54, 32, 27 });


	forward.speed = 0.1f;

	// move upwards-backwards animation
	mid.PushBack({ 187, 95, 26, 29 });
	mid.PushBack({ 230, 95, 24, 28 });
	mid.PushBack({ 270, 95, 26, 28 });
	mid.loop = false;
	mid.speed = 0.1f;

	// move upwards-backwards animation
	backward.PushBack({ 193, 53, 26, 29 });
	backward.PushBack({ 233, 54, 27, 28 });
	backward.PushBack({ 272, 54, 27, 28 });
	//backward.loop = false;
	backward.speed = 0.1f;



}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("assets/miko.png");

	return true;
}


bool ModulePlayer::CleanUp()
{
	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	//Animation* current_animation = &forward;

	int speed = 1;

	if(App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		if (current_animation != &backward) {
			backward.Reset();
			current_animation = &backward;
		}
		position.x -= speed;
	
		
		
	}

	if(App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		
			current_animation = &forward;
		
		position.x += speed;
	}

	if(App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		
		//if (current_animation == &forward) {
		if (current_animation != &mid ) {
			mid.Reset();
			current_animation = &mid;
		
			
		}

	
		
		
			//aux++;
		//}

		//else if(aux == 2){
			//current_animation = &backward;
	//}
	/*
		if (current_animation != &backward) {
			backward.Reset();
			current_animation = &backward;
		}
		*/
		position.y -= speed;
			
			
		
	}

	

	

	if(App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
	   && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
		current_animation = &forward;

	// Draw everything --------------------------------------

	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}