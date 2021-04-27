#include "../raylib/include/raylib.h"

typedef struct
{
	Vector2 position;
	float angle;
	int ray_length;
	float ray_angle_from_center[720];
	float distance_between_rays;
	Vector2 rays[7200]; // CHANGE THIS
} Player;

typedef struct
{
	float speed;
	float fov;
	float mouse_sensibility;
	float ray_count;
	char user_name[128];
} Settings;

// player by reference, x and y coordinates, angle, fov, ray_count, speed (150 recommended)
void init_player(Player *player, Settings *settings, float x, float y, float angle);
void init_settings(Settings *settings, const char *user_name, float fov, int ray_count, float speed, float mouse_sensibility);
void player(Player *player, Settings *settings);
void p_controls(Player *player, Settings *settings);
void cast_rays(Vector2 ray_s, Vector2 ray_e, Vector2 wall_s, Vector2 wall_e, Vector2 *collision_point);
void update_rays(Player *player, Settings *settings);