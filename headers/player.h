#ifndef PLAYER_H
#define PLAYER_H
#include "../lib/raylib/include/raylib.h"
#include "fighting.h"
#define RAY_MAX_COUNT 1000

typedef struct
{
	Vector2 position;
	Vector2 look_direction;
	float angle;
	int damage;
	int max_bullets;
	int bullets;
} Gun;

typedef struct
{
	Vector2 position;
	float angle;
	float ray_angle_from_start[RAY_MAX_COUNT];
	float distance_between_rays;
	Vector2 colliding_rays[RAY_MAX_COUNT];
	Vector2 directional_rays[RAY_MAX_COUNT];
	Vector2 rays[RAY_MAX_COUNT];
	Gun *gun;
} Player;

typedef struct
{
	float speed;
	float fov;
	float mouse_sensibility;
	int ray_count;
	int vsync;
	int directional_rays_enabled;
	int fisheye_correction;
	int show_rays;
	int ray_length;
	char user_name[128];
	float distance[RAY_MAX_COUNT];
} Settings;

// player by reference, x and y coordinates, angle, fov, ray_count, speed (150 recommended)
void init_player(Player *player, Settings *settings, float x, float y, float angle);
void load_settings(Settings *settings, const char *user_name, float fov, int ray_count, float speed, float mouse_sensibility, char *settings_file_name);
void load_default_settings(Settings *settings, const char *user_name, float fov, int ray_count, float speed, float mouse_sensibility);
void player(Player *player, Settings *settings);
void p_controls(Player *player, Settings *settings);
void p_collide(Player *player, Settings *settings, Vector2 speed);
void p_draw_on_map(Player *player, Settings *settings);
void init_gun(Gun *gun, int damage, int max_bullets);
#endif